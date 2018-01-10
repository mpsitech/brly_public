/**
  * \file QryBrlyLocMapVisLocation.cpp
  * job handler for job QryBrlyLocMapVisLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyLocMapVisLocation.h"

#include "QryBrlyLocMapVisLocation_blks.cpp"

/******************************************************************************
 class QryBrlyLocMapVisLocation
 ******************************************************************************/

QryBrlyLocMapVisLocation::QryBrlyLocMapVisLocation(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYLOCMAPVISLOCATION, jrefSup, ixBrlyVLocale) {

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

QryBrlyLocMapVisLocation::~QryBrlyLocMapVisLocation() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyLocMapVisLocation::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyLocMapVisLocation::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	ubigint preRefLoc = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLOC, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqlocmapvislocation->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblBrlyQLocMapVisLocation(qwr, jref, jnum, ref, mref, mtheta, mphi)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblBrlyVisRMLocationMLocation.ref, TblBrlyMLocation.ref, TblBrlyMLocation.theta, TblBrlyMLocation.phi";
	sqlstr += " FROM TblBrlyVisRMLocationMLocation, TblBrlyMLocation";
	sqlstr += " WHERE TblBrlyVisRMLocationMLocation.dstRefBrlyMLocation = " + to_string(preRefLoc) + "";
	sqlstr += " AND TblBrlyMLocation.ref = TblBrlyVisRMLocationMLocation.orgRefBrlyMLocation";
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQLocMapVisLocation SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyLocMapVisLocation::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQLocMapVisLocation* rec = NULL;

	dbsbrly->tblbrlyqlocmapvislocation->loadRstByJref(jref, false, rst);

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = i+1;
			rec->stubMref = StubBrly::getStubLocStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyLocMapVisLocation", "fetch");
	};

	refreshJnum();
};

uint QryBrlyLocMapVisLocation::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQLocMapVisLocation* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyLocMapVisLocation::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQLocMapVisLocation* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQLocMapVisLocation* QryBrlyLocMapVisLocation::getRecByJnum(
			const uint jnum
		) {
	BrlyQLocMapVisLocation* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyLocMapVisLocation::handleRequest(
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

bool QryBrlyLocMapVisLocation::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	rerun(dbsbrly);
	return retval;
};

bool QryBrlyLocMapVisLocation::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQLocMapVisLocation* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tmtheta";
	cout << "\tmphi";
	cout << "\tx";
	cout << "\ty";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->qwr;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->mtheta;
		cout << "\t" << rec->mphi;
		cout << "\t" << rec->x;
		cout << "\t" << rec->y;
		cout << endl;
	};
	return retval;
};

void QryBrlyLocMapVisLocation::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	};
};

bool QryBrlyLocMapVisLocation::handleCallBrlyStubChg(
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

