/**
  * \file QryBrlyUsrAAccess.cpp
  * job handler for job QryBrlyUsrAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyUsrAAccess.h"

#include "QryBrlyUsrAAccess_blks.cpp"

/******************************************************************************
 class QryBrlyUsrAAccess
 ******************************************************************************/

QryBrlyUsrAAccess::QryBrlyUsrAAccess(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYUSRAACCESS, jrefSup, ixBrlyVLocale) {

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

QryBrlyUsrAAccess::~QryBrlyUsrAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyUsrAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyUsrAAccess::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFUSR, jref);
	uint preX1 = xchg->getIxPreset(VecBrlyVPreset::PREBRLYUSRAACCESS_X1, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYUSRAACCMOD_USREQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqusraaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyAMUserAccess.ref)";
	sqlstr += " FROM TblBrlyAMUserAccess";
	sqlstr += " WHERE TblBrlyAMUserAccess.refBrlyMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQUsrAAccess(jref, jnum, ref, x1IxBrlyVCard, ixBrlyWUiaccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyAMUserAccess.ref, TblBrlyAMUserAccess.x1IxBrlyVCard, TblBrlyAMUserAccess.ixBrlyWUiaccess";
	sqlstr += " FROM TblBrlyAMUserAccess";
	sqlstr += " WHERE TblBrlyAMUserAccess.refBrlyMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQUsrAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYUSRAACCMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsr, Clstn::VecVJactype::LOCK);
};

void QryBrlyUsrAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyAMUserAccess.x1IxBrlyVCard = " + to_string(preX1) + "";
	};
};

void QryBrlyUsrAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyUsrAAccess::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQUsrAAccess* rec = NULL;

	dbsbrly->tblbrlyqusraaccess->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxBrlyVCard = VecBrlyVCard::getSref(rec->x1IxBrlyVCard);
			rec->titX1IxBrlyVCard = VecBrlyVCard::getTitle(rec->x1IxBrlyVCard, ixBrlyVLocale);
			rec->srefsIxBrlyWUiaccess = VecBrlyWUiaccess::getSrefs(rec->ixBrlyWUiaccess);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyUsrAAccess", "fetch");
	};

	refreshJnum();
};

uint QryBrlyUsrAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQUsrAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyUsrAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQUsrAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQUsrAAccess* QryBrlyUsrAAccess::getRecByJnum(
			const uint jnum
		) {
	BrlyQUsrAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyUsrAAccess::handleRequest(
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

bool QryBrlyUsrAAccess::handleRerun(
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

bool QryBrlyUsrAAccess::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQUsrAAccess* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxBrlyVCard";
	cout << "\tsrefX1IxBrlyVCard";
	cout << "\ttitX1IxBrlyVCard";
	cout << "\tixBrlyWUiaccess";
	cout << "\tsrefsIxBrlyWUiaccess";
	cout << "\ttitsIxBrlyWUiaccess";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxBrlyVCard;
		cout << "\t" << rec->srefX1IxBrlyVCard;
		cout << "\t" << rec->titX1IxBrlyVCard;
		cout << "\t" << rec->ixBrlyWUiaccess;
		cout << "\t" << rec->srefsIxBrlyWUiaccess;
		cout << "\t" << rec->titsIxBrlyWUiaccess;
		cout << endl;
	};
	return retval;
};

void QryBrlyUsrAAccess::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSRAACCMOD_USREQ) {
		call->abort = handleCallBrlyUsrAaccMod_usrEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyUsrAAccess::handleCallBrlyStubChg(
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

bool QryBrlyUsrAAccess::handleCallBrlyUsrAaccMod_usrEq(
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

