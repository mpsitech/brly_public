// IP file --- KEEP
/**
  * \file QryBrlyConMapRelay.cpp
  * job handler for job QryBrlyConMapRelay (implementation)
  * \author Alexander Wirthmueller
  * \date created: 5 Nov 2016
  * \date modified: 5 Nov 2016
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyConMapRelay.h"

#include "QryBrlyConMapRelay_blks.cpp"

/******************************************************************************
 class QryBrlyConMapRelay
 ******************************************************************************/

QryBrlyConMapRelay::QryBrlyConMapRelay(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYCONMAPRELAY, jrefSup, ixBrlyVLocale) {

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

QryBrlyConMapRelay::~QryBrlyConMapRelay() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyConMapRelay::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyConMapRelay::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	ubigint preRefCon = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqconmaprelay->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblBrlyQConMapRelay(qwr, jref, jnum, ref, x1Start, x1Stop, ixVDir, Connected, Nhop)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblBrlyMRelay.ref, TblBrlyMRelay.x1Start, TblBrlyMRelay.x1Stop, TblBrlyMRelay.ixVDir, TblBrlyMRelay.Connected, TblBrlyMRelay.Nhop";
	sqlstr += " FROM TblBrlyMRelay";
	sqlstr += " WHERE TblBrlyMRelay.refBrlyMConnection = " + to_string(preRefCon) + "";
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQConMapRelay SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

///
	// preliminary jnum workaround /// NOTE: probably this is not thread-safe if qref is not contigouus
	ubigint qref0;

	dbsbrly->loadRefBySQL("SELECT qref FROM TblBrlyQConMapRelay WHERE jref = " + to_string(jref) + " ORDER BY qref ASC LIMIT 0,1", qref0);
	dbsbrly->executeQuery("UPDATE TblBrlyQConMapRelay SET jnum = qref-" + to_string(qref0-1) + " WHERE jref = " + to_string(jref));
///

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyConMapRelay::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQConMapRelay* rec = NULL;

	dbsbrly->tblbrlyqconmaprelay->loadRstByJref(jref, false, rst);

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = i+1;
			rec->srefIxVDir = VecBrlyVMRelayDir::getSref(rec->ixVDir);
			if (rec->Connected) rec->yesnoConnected = VecBrlyVTag::getTitle(VecBrlyVTag::YES, ixBrlyVLocale); else rec->yesnoConnected = VecBrlyVTag::getTitle(VecBrlyVTag::NO, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyConMapRelay", "fetch");
	};

	refreshJnum();
};

uint QryBrlyConMapRelay::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQConMapRelay* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyConMapRelay::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQConMapRelay* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQConMapRelay* QryBrlyConMapRelay::getRecByJnum(
			const uint jnum
		) {
	BrlyQConMapRelay* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyConMapRelay::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {
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

bool QryBrlyConMapRelay::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	rerun(dbsbrly);
	return retval;
};

bool QryBrlyConMapRelay::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQConMapRelay* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1Start";
	cout << "\tx1Stop";
	cout << "\tixVDir";
	cout << "\tsrefIxVDir";
	cout << "\tConnected";
	cout << "\tyesnoConnected";
	cout << "\tNhop";
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
		cout << "\t" << rec->ixVDir;
		cout << "\t" << rec->srefIxVDir;
		cout << "\t" << rec->Connected;
		cout << "\t" << rec->yesnoConnected;
		cout << "\t" << rec->Nhop;
		cout << endl;
	};
	return retval;
};

void QryBrlyConMapRelay::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	};
};

bool QryBrlyConMapRelay::handleCallBrlyStubChg(
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
