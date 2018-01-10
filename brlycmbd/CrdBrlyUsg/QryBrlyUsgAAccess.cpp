/**
  * \file QryBrlyUsgAAccess.cpp
  * job handler for job QryBrlyUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyUsgAAccess.h"

#include "QryBrlyUsgAAccess_blks.cpp"

/******************************************************************************
 class QryBrlyUsgAAccess
 ******************************************************************************/

QryBrlyUsgAAccess::QryBrlyUsgAAccess(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYUSGAACCESS, jrefSup, ixBrlyVLocale) {

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

QryBrlyUsgAAccess::~QryBrlyUsgAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyUsgAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyUsgAAccess::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFUSG, jref);
	uint preX1 = xchg->getIxPreset(VecBrlyVPreset::PREBRLYUSGAACCESS_X1, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYUSGAACCMOD_USGEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqusgaaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyAMUsergroupAccess.ref)";
	sqlstr += " FROM TblBrlyAMUsergroupAccess";
	sqlstr += " WHERE TblBrlyAMUsergroupAccess.refBrlyMUsergroup = " + to_string(preRefUsg) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQUsgAAccess(jref, jnum, ref, x1IxBrlyVCard, ixBrlyWUiaccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyAMUsergroupAccess.ref, TblBrlyAMUsergroupAccess.x1IxBrlyVCard, TblBrlyAMUsergroupAccess.ixBrlyWUiaccess";
	sqlstr += " FROM TblBrlyAMUsergroupAccess";
	sqlstr += " WHERE TblBrlyAMUsergroupAccess.refBrlyMUsergroup = " + to_string(preRefUsg) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQUsgAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYUSGAACCMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsg, Clstn::VecVJactype::LOCK);
};

void QryBrlyUsgAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyAMUsergroupAccess.x1IxBrlyVCard = " + to_string(preX1) + "";
	};
};

void QryBrlyUsgAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyUsgAAccess::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQUsgAAccess* rec = NULL;

	dbsbrly->tblbrlyqusgaaccess->loadRstByJref(jref, false, rst);
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
		stmgr->unlockAccess("QryBrlyUsgAAccess", "fetch");
	};

	refreshJnum();
};

uint QryBrlyUsgAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQUsgAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyUsgAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQUsgAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQUsgAAccess* QryBrlyUsgAAccess::getRecByJnum(
			const uint jnum
		) {
	BrlyQUsgAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyUsgAAccess::handleRequest(
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

bool QryBrlyUsgAAccess::handleRerun(
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

bool QryBrlyUsgAAccess::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQUsgAAccess* rec = NULL;

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

void QryBrlyUsgAAccess::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSGAACCMOD_USGEQ) {
		call->abort = handleCallBrlyUsgAaccMod_usgEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyUsgAAccess::handleCallBrlyStubChg(
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

bool QryBrlyUsgAAccess::handleCallBrlyUsgAaccMod_usgEq(
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

