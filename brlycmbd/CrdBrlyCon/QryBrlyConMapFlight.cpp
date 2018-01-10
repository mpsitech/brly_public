/**
  * \file QryBrlyConMapFlight.cpp
  * job handler for job QryBrlyConMapFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyConMapFlight.h"

#include "QryBrlyConMapFlight_blks.cpp"

/******************************************************************************
 class QryBrlyConMapFlight
 ******************************************************************************/

QryBrlyConMapFlight::QryBrlyConMapFlight(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYCONMAPFLIGHT, jrefSup, ixBrlyVLocale) {

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

QryBrlyConMapFlight::~QryBrlyConMapFlight() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyConMapFlight::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyConMapFlight::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	ubigint preRefCon = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqconmapflight->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblBrlyQConMapFlight(qwr, jref, jnum, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, mref, mrefBrlyMEquipment, mrefBrlyMLeg, mstart, mstop)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblBrlyRMConnectionMFlight.ref, TblBrlyRMConnectionMFlight.x1Start, TblBrlyRMConnectionMFlight.x1Stop, TblBrlyRMConnectionMFlight.x2Legphi0, TblBrlyRMConnectionMFlight.x2Legphi1, TblBrlyMFlight.ref, TblBrlyMFlight.refBrlyMEquipment, TblBrlyMFlight.refBrlyMLeg, TblBrlyMFlight.start, TblBrlyMFlight.stop";
	sqlstr += " FROM TblBrlyRMConnectionMFlight, TblBrlyMFlight";
	sqlstr += " WHERE TblBrlyRMConnectionMFlight.refBrlyMConnection = " + to_string(preRefCon) + "";
	sqlstr += " AND TblBrlyMFlight.ref = TblBrlyRMConnectionMFlight.refBrlyMFlight";
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQConMapFlight SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyConMapFlight::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQConMapFlight* rec = NULL;

	dbsbrly->tblbrlyqconmapflight->loadRstByJref(jref, false, rst);

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = i+1;
			rec->stubMref = StubBrly::getStubFltStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyConMapFlight", "fetch");
	};

	refreshJnum();
};

uint QryBrlyConMapFlight::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQConMapFlight* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyConMapFlight::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQConMapFlight* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQConMapFlight* QryBrlyConMapFlight::getRecByJnum(
			const uint jnum
		) {
	BrlyQConMapFlight* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyConMapFlight::handleRequest(
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

bool QryBrlyConMapFlight::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	rerun(dbsbrly);
	return retval;
};

bool QryBrlyConMapFlight::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQConMapFlight* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1Start";
	cout << "\tx1Stop";
	cout << "\tx2Legphi0";
	cout << "\tx2Legphi1";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tmrefBrlyMEquipment";
	cout << "\tmrefBrlyMLeg";
	cout << "\tmstart";
	cout << "\tmstop";
	cout << "\tx0";
	cout << "\ty0";
	cout << "\tt0";
	cout << "\tdx";
	cout << "\tdy";
	cout << "\tdt";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->qwr;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1Start;
		cout << "\t" << rec->x1Stop;
		cout << "\t" << rec->x2Legphi0;
		cout << "\t" << rec->x2Legphi1;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->mrefBrlyMEquipment;
		cout << "\t" << rec->mrefBrlyMLeg;
		cout << "\t" << rec->mstart;
		cout << "\t" << rec->mstop;
		cout << "\t" << rec->x0;
		cout << "\t" << rec->y0;
		cout << "\t" << rec->t0;
		cout << "\t" << rec->dx;
		cout << "\t" << rec->dy;
		cout << "\t" << rec->dt;
		cout << endl;
	};
	return retval;
};

void QryBrlyConMapFlight::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	};
};

bool QryBrlyConMapFlight::handleCallBrlyStubChg(
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

