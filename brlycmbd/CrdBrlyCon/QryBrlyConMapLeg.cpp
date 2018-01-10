/**
  * \file QryBrlyConMapLeg.cpp
  * job handler for job QryBrlyConMapLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyConMapLeg.h"

#include "QryBrlyConMapLeg_blks.cpp"

/******************************************************************************
 class QryBrlyConMapLeg
 ******************************************************************************/

QryBrlyConMapLeg::QryBrlyConMapLeg(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYCONMAPLEG, jrefSup, ixBrlyVLocale) {

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

QryBrlyConMapLeg::~QryBrlyConMapLeg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyConMapLeg::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyConMapLeg::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	ubigint preRefCon = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqconmapleg->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblBrlyQConMapLeg(qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, mdeltaphi)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblBrlyRMLegMLeg.ref, TblBrlyRMLegMLeg.VisOrgLegphi0, TblBrlyRMLegMLeg.VisOrgLegphi1, TblBrlyMLeg.ref, TblBrlyMLeg.bgnRefBrlyMLocation, TblBrlyMLeg.endRefBrlyMLocation, TblBrlyMLeg.deltaphi";
	sqlstr += " FROM TblBrlyRMLegMLeg, TblBrlyMConnection, TblBrlyMLeg";
	sqlstr += " WHERE TblBrlyMConnection.ref = " + to_string(preRefCon) + "";
	sqlstr += " AND TblBrlyRMLegMLeg.dstRefBrlyMLeg = TblBrlyMConnection.corRefBrlyMLeg";
	sqlstr += " AND TblBrlyMLeg.ref = TblBrlyRMLegMLeg.orgRefBrlyMLeg";
	sqlstr += " AND TblBrlyMLeg.ixVBasetype = " + to_string(VecBrlyVMLegBasetype::RTE);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQConMapLeg SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyConMapLeg::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQConMapLeg* rec = NULL;

	dbsbrly->tblbrlyqconmapleg->loadRstByJref(jref, false, rst);

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
		stmgr->unlockAccess("QryBrlyConMapLeg", "fetch");
	};

	refreshJnum();
};

uint QryBrlyConMapLeg::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQConMapLeg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyConMapLeg::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQConMapLeg* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQConMapLeg* QryBrlyConMapLeg::getRecByJnum(
			const uint jnum
		) {
	BrlyQConMapLeg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyConMapLeg::handleRequest(
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

bool QryBrlyConMapLeg::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	rerun(dbsbrly);
	return retval;
};

bool QryBrlyConMapLeg::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQConMapLeg* rec = NULL;

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
	cout << "\tmdeltaphi";
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
		cout << "\t" << rec->mdeltaphi;
		cout << "\t" << rec->dx;
		cout << "\t" << rec->dy;
		cout << "\t" << rec->x0;
		cout << "\t" << rec->y0;
		cout << endl;
	};
	return retval;
};

void QryBrlyConMapLeg::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	};
};

bool QryBrlyConMapLeg::handleCallBrlyStubChg(
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

