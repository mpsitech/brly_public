/**
  * \file QryBrlyFltEqpMNConnection.cpp
  * job handler for job QryBrlyFltEqpMNConnection (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyFltEqpMNConnection.h"

#include "QryBrlyFltEqpMNConnection_blks.cpp"

/******************************************************************************
 class QryBrlyFltEqpMNConnection
 ******************************************************************************/

QryBrlyFltEqpMNConnection::QryBrlyFltEqpMNConnection(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYFLTEQPMNCONNECTION, jrefSup, ixBrlyVLocale) {

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

QryBrlyFltEqpMNConnection::~QryBrlyFltEqpMNConnection() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyFltEqpMNConnection::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyFltEqpMNConnection::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefEqp = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFEQP, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYCONREQPMOD_EQPEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqflteqpmnconnection->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyLRMConnectionMEquipment.ref)";
	sqlstr += " FROM TblBrlyLRMConnectionMEquipment, TblBrlyMConnection";
	sqlstr += " WHERE TblBrlyLRMConnectionMEquipment.conRefBrlyMConnection = TblBrlyMConnection.ref";
	sqlstr += " AND TblBrlyLRMConnectionMEquipment.refBrlyMEquipment = " + to_string(preRefEqp) + "";
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQFltEqpMNConnection(jref, jnum, mref, ref, conIxBrlyVLat)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMConnection.ref, TblBrlyLRMConnectionMEquipment.ref, TblBrlyLRMConnectionMEquipment.conIxBrlyVLat";
	sqlstr += " FROM TblBrlyLRMConnectionMEquipment, TblBrlyMConnection";
	sqlstr += " WHERE TblBrlyLRMConnectionMEquipment.conRefBrlyMConnection = TblBrlyMConnection.ref";
	sqlstr += " AND TblBrlyLRMConnectionMEquipment.refBrlyMEquipment = " + to_string(preRefEqp) + "";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQFltEqpMNConnection SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYCONREQPMOD_EQPEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefEqp, Clstn::VecVJactype::LOCK);
};

void QryBrlyFltEqpMNConnection::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQFltEqpMNConnection* rec = NULL;

	dbsbrly->tblbrlyqflteqpmnconnection->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubBrly::getStubConStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefConIxBrlyVLat = VecBrlyVLat::getSref(rec->conIxBrlyVLat);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyFltEqpMNConnection", "fetch");
	};

	refreshJnum();
};

uint QryBrlyFltEqpMNConnection::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQFltEqpMNConnection* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyFltEqpMNConnection::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQFltEqpMNConnection* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQFltEqpMNConnection* QryBrlyFltEqpMNConnection::getRecByJnum(
			const uint jnum
		) {
	BrlyQFltEqpMNConnection* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyFltEqpMNConnection::handleRequest(
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

bool QryBrlyFltEqpMNConnection::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;

	cout << "\tjnumFirstload (" << stgiac.jnumFirstload << "): ";
	cin >> input;
	stgiac.jnumFirstload = atol(input.c_str());
	cout << "\tnload (" << stgiac.nload << "): ";
	cin >> input;
	stgiac.nload = atol(input.c_str());

	rerun(dbsbrly);
	return retval;
};

bool QryBrlyFltEqpMNConnection::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQFltEqpMNConnection* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tconIxBrlyVLat";
	cout << "\tsrefConIxBrlyVLat";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->conIxBrlyVLat;
		cout << "\t" << rec->srefConIxBrlyVLat;
		cout << endl;
	};
	return retval;
};

void QryBrlyFltEqpMNConnection::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCONREQPMOD_EQPEQ) {
		call->abort = handleCallBrlyConReqpMod_eqpEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyFltEqpMNConnection::handleCallBrlyStubChg(
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

bool QryBrlyFltEqpMNConnection::handleCallBrlyConReqpMod_eqpEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixBrlyVQrystate != VecBrlyVQrystate::OOD) {
		ixBrlyVQrystate = VecBrlyVQrystate::OOD;
		xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);
	};

	return retval;
};

