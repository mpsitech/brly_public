/**
  * \file QryBrlyUsrMNUsergroup.cpp
  * job handler for job QryBrlyUsrMNUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyUsrMNUsergroup.h"

#include "QryBrlyUsrMNUsergroup_blks.cpp"

/******************************************************************************
 class QryBrlyUsrMNUsergroup
 ******************************************************************************/

QryBrlyUsrMNUsergroup::QryBrlyUsrMNUsergroup(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYUSRMNUSERGROUP, jrefSup, ixBrlyVLocale) {

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

QryBrlyUsrMNUsergroup::~QryBrlyUsrMNUsergroup() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyUsrMNUsergroup::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyUsrMNUsergroup::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFUSR, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYUSRRUSGMOD_USREQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqusrmnusergroup->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyRMUserMUsergroup.ref)";
	sqlstr += " FROM TblBrlyRMUserMUsergroup, TblBrlyMUsergroup";
	sqlstr += " WHERE TblBrlyRMUserMUsergroup.refBrlyMUsergroup = TblBrlyMUsergroup.ref";
	sqlstr += " AND TblBrlyRMUserMUsergroup.refBrlyMUser = " + to_string(preRefUsr) + "";
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQUsrMNUsergroup(jref, jnum, mref, ref, ixBrlyVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMUsergroup.ref, TblBrlyRMUserMUsergroup.ref, TblBrlyRMUserMUsergroup.ixBrlyVUserlevel";
	sqlstr += " FROM TblBrlyRMUserMUsergroup, TblBrlyMUsergroup";
	sqlstr += " WHERE TblBrlyRMUserMUsergroup.refBrlyMUsergroup = TblBrlyMUsergroup.ref";
	sqlstr += " AND TblBrlyRMUserMUsergroup.refBrlyMUser = " + to_string(preRefUsr) + "";
	sqlstr += " ORDER BY TblBrlyMUsergroup.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQUsrMNUsergroup SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYUSRRUSGMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsr, Clstn::VecVJactype::LOCK);
};

void QryBrlyUsrMNUsergroup::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQUsrMNUsergroup* rec = NULL;

	dbsbrly->tblbrlyqusrmnusergroup->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubBrly::getStubUsgStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxBrlyVUserlevel = VecBrlyVUserlevel::getSref(rec->ixBrlyVUserlevel);
			rec->titIxBrlyVUserlevel = VecBrlyVUserlevel::getTitle(rec->ixBrlyVUserlevel, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyUsrMNUsergroup", "fetch");
	};

	refreshJnum();
};

uint QryBrlyUsrMNUsergroup::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQUsrMNUsergroup* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyUsrMNUsergroup::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQUsrMNUsergroup* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQUsrMNUsergroup* QryBrlyUsrMNUsergroup::getRecByJnum(
			const uint jnum
		) {
	BrlyQUsrMNUsergroup* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyUsrMNUsergroup::handleRequest(
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

bool QryBrlyUsrMNUsergroup::handleRerun(
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

bool QryBrlyUsrMNUsergroup::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQUsrMNUsergroup* rec = NULL;

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

void QryBrlyUsrMNUsergroup::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSRRUSGMOD_USREQ) {
		call->abort = handleCallBrlyUsrRusgMod_usrEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyUsrMNUsergroup::handleCallBrlyStubChg(
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

bool QryBrlyUsrMNUsergroup::handleCallBrlyUsrRusgMod_usrEq(
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

