/**
  * \file QryBrlyUsgMNUser.cpp
  * job handler for job QryBrlyUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyUsgMNUser.h"

#include "QryBrlyUsgMNUser_blks.cpp"

/******************************************************************************
 class QryBrlyUsgMNUser
 ******************************************************************************/

QryBrlyUsgMNUser::QryBrlyUsgMNUser(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYUSGMNUSER, jrefSup, ixBrlyVLocale) {

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

QryBrlyUsgMNUser::~QryBrlyUsgMNUser() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyUsgMNUser::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyUsgMNUser::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFUSG, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYUSRRUSGMOD_USGEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqusgmnuser->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyRMUserMUsergroup.ref)";
	sqlstr += " FROM TblBrlyMUser, TblBrlyRMUserMUsergroup";
	sqlstr += " WHERE TblBrlyRMUserMUsergroup.refBrlyMUser = TblBrlyMUser.ref";
	sqlstr += " AND TblBrlyRMUserMUsergroup.refBrlyMUsergroup = " + to_string(preRefUsg) + "";
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQUsgMNUser(jref, jnum, mref, ref, ixBrlyVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMUser.ref, TblBrlyRMUserMUsergroup.ref, TblBrlyRMUserMUsergroup.ixBrlyVUserlevel";
	sqlstr += " FROM TblBrlyMUser, TblBrlyRMUserMUsergroup";
	sqlstr += " WHERE TblBrlyRMUserMUsergroup.refBrlyMUser = TblBrlyMUser.ref";
	sqlstr += " AND TblBrlyRMUserMUsergroup.refBrlyMUsergroup = " + to_string(preRefUsg) + "";
	sqlstr += " ORDER BY TblBrlyMUser.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQUsgMNUser SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYUSRRUSGMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsg, Clstn::VecVJactype::LOCK);
};

void QryBrlyUsgMNUser::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQUsgMNUser* rec = NULL;

	dbsbrly->tblbrlyqusgmnuser->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubBrly::getStubUsrStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxBrlyVUserlevel = VecBrlyVUserlevel::getSref(rec->ixBrlyVUserlevel);
			rec->titIxBrlyVUserlevel = VecBrlyVUserlevel::getTitle(rec->ixBrlyVUserlevel, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyUsgMNUser", "fetch");
	};

	refreshJnum();
};

uint QryBrlyUsgMNUser::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQUsgMNUser* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyUsgMNUser::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQUsgMNUser* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQUsgMNUser* QryBrlyUsgMNUser::getRecByJnum(
			const uint jnum
		) {
	BrlyQUsgMNUser* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyUsgMNUser::handleRequest(
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

bool QryBrlyUsgMNUser::handleRerun(
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

bool QryBrlyUsgMNUser::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQUsgMNUser* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tixBrlyVUserlevel";
	cout << "\tsrefIxBrlyVUserlevel";
	cout << "\ttitIxBrlyVUserlevel";
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
		cout << "\t" << rec->ixBrlyVUserlevel;
		cout << "\t" << rec->srefIxBrlyVUserlevel;
		cout << "\t" << rec->titIxBrlyVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryBrlyUsgMNUser::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSRRUSGMOD_USGEQ) {
		call->abort = handleCallBrlyUsrRusgMod_usgEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyUsgMNUser::handleCallBrlyStubChg(
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

bool QryBrlyUsgMNUser::handleCallBrlyUsrRusgMod_usgEq(
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

