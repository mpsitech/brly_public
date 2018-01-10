/**
  * \file QryBrlyLegMapLeg.cpp
  * job handler for job QryBrlyLegMapLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyLegMapLeg.h"

#include "QryBrlyLegMapLeg_blks.cpp"

/******************************************************************************
 class QryBrlyLegMapLeg
 ******************************************************************************/

QryBrlyLegMapLeg::QryBrlyLegMapLeg(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYLEGMAPLEG, jrefSup, ixBrlyVLocale) {

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

QryBrlyLegMapLeg::~QryBrlyLegMapLeg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyLegMapLeg::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyLegMapLeg::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	ubigint preRefLeg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLEG, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqlegmapleg->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblBrlyQLegMapLeg(qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblBrlyRMLegMLeg.ref, TblBrlyRMLegMLeg.VisOrgLegphi0, TblBrlyRMLegMLeg.VisOrgLegphi1, TblBrlyMLeg.ref, TblBrlyMLeg.bgnRefBrlyMLocation, TblBrlyMLeg.endRefBrlyMLocation";
	sqlstr += " FROM TblBrlyMLeg, TblBrlyRMLegMLeg";
	sqlstr += " WHERE TblBrlyMLeg.ixVBasetype = " + to_string(VecBrlyVMLegBasetype::RTE);
	sqlstr += " AND TblBrlyMLeg.ref = TblBrlyRMLegMLeg.orgRefBrlyMLeg";
	sqlstr += " AND TblBrlyRMLegMLeg.dstRefBrlyMLeg = " + to_string(preRefLeg) + "";
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQLegMapLeg SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyLegMapLeg::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQLegMapLeg* rec = NULL;

	dbsbrly->tblbrlyqlegmapleg->loadRstByJref(jref, false, rst);

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
		stmgr->unlockAccess("QryBrlyLegMapLeg", "fetch");
	};

	refreshJnum();
};

uint QryBrlyLegMapLeg::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQLegMapLeg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyLegMapLeg::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQLegMapLeg* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQLegMapLeg* QryBrlyLegMapLeg::getRecByJnum(
			const uint jnum
		) {
	BrlyQLegMapLeg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyLegMapLeg::handleRequest(
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

bool QryBrlyLegMapLeg::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	rerun(dbsbrly);
	return retval;
};

bool QryBrlyLegMapLeg::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQLegMapLeg* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tVisOrgLegphi0";
	cout << "\tVisOrgLegphi1";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tmbgnRefBrlyMLocation";
	cout << "\tmendRefBrlyMLocation";
	cout << "\tdx";
	cout << "\tdy";
	cout << "\tx0";
	cout << "\ty0";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->qwr;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->VisOrgLegphi0;
		cout << "\t" << rec->VisOrgLegphi1;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->mbgnRefBrlyMLocation;
		cout << "\t" << rec->mendRefBrlyMLocation;
		cout << "\t" << rec->dx;
		cout << "\t" << rec->dy;
		cout << "\t" << rec->x0;
		cout << "\t" << rec->y0;
		cout << endl;
	};
	return retval;
};

void QryBrlyLegMapLeg::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	};
};

bool QryBrlyLegMapLeg::handleCallBrlyStubChg(
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

