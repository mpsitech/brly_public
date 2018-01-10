/**
  * \file QryBrlyLocMapLeg.cpp
  * job handler for job QryBrlyLocMapLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyLocMapLeg.h"

#include "QryBrlyLocMapLeg_blks.cpp"

/******************************************************************************
 class QryBrlyLocMapLeg
 ******************************************************************************/

QryBrlyLocMapLeg::QryBrlyLocMapLeg(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYLOCMAPLEG, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyLocMapLeg::~QryBrlyLocMapLeg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyLocMapLeg::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyLocMapLeg::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	ubigint preRefLoc = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLOC, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqlocmapleg->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblBrlyQLocMapLeg(qwr, jref, jnum, ref, x1VisLegphi0, x1VisLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblBrlyRMLegMLocation.ref, TblBrlyRMLegMLocation.x1VisLegphi0, TblBrlyRMLegMLocation.x1VisLegphi1, TblBrlyMLeg.ref, TblBrlyMLeg.bgnRefBrlyMLocation, TblBrlyMLeg.endRefBrlyMLocation";
	sqlstr += " FROM TblBrlyRMLegMLocation, TblBrlyMLeg";
	sqlstr += " WHERE TblBrlyMLeg.ixVBasetype = " + to_string(VecBrlyVMLegBasetype::RTE);
	sqlstr += " AND TblBrlyMLeg.ref = TblBrlyRMLegMLocation.refBrlyMLeg";
	sqlstr += " AND TblBrlyRMLegMLocation.refBrlyMLocation = " + to_string(preRefLoc) + "";
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQLocMapLeg SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyLocMapLeg::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQLocMapLeg* rec = NULL;

	dbsbrly->tblbrlyqlocmapleg->loadRstByJref(jref, false, rst);

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = i+1;
			rec->stubMref = StubBrly::getStubLegStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyLocMapLeg", "fetch");
	};

	refreshJnum();
};

uint QryBrlyLocMapLeg::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQLocMapLeg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyLocMapLeg::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQLocMapLeg* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQLocMapLeg* QryBrlyLocMapLeg::getRecByJnum(
			const uint jnum
		) {
	BrlyQLocMapLeg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyLocMapLeg::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\trerun" << endl;
			cout << "\tshow" << endl;
		} else if (req->cmd == "rerun") {
			req->retain = handleRerun(dbsbrly);

		} else if (req->cmd == "show") {
			req->retain = handleShow(dbsbrly);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
	};
};

bool QryBrlyLocMapLeg::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	rerun(dbsbrly);
	return retval;
};

bool QryBrlyLocMapLeg::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQLocMapLeg* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1VisLegphi0";
	cout << "\tx1VisLegphi1";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tmbgnRefBrlyMLocation";
	cout << "\tmendRefBrlyMLocation";
	cout << "\tdx";
	cout << "\tdy";
	cout << "\tx0";
	cout << "\ty0";
	cout << "\tlam1";
	cout << "\tlam2";
	cout << "\tlam3";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->qwr;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1VisLegphi0;
		cout << "\t" << rec->x1VisLegphi1;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->mbgnRefBrlyMLocation;
		cout << "\t" << rec->mendRefBrlyMLocation;
		cout << "\t" << rec->dx;
		cout << "\t" << rec->dy;
		cout << "\t" << rec->x0;
		cout << "\t" << rec->y0;
		cout << "\t" << rec->lam1;
		cout << "\t" << rec->lam2;
		cout << "\t" << rec->lam3;
		cout << endl;
	};
	return retval;
};

void QryBrlyLocMapLeg::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	};
};

bool QryBrlyLocMapLeg::handleCallBrlyStubChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (ixBrlyVQrystate == VecBrlyVQrystate::UTD) {
		ixBrlyVQrystate = VecBrlyVQrystate::SLM;
		xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);
	};

	return retval;
};

