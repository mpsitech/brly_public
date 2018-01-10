/**
  * \file QryBrlyPtyList.cpp
  * job handler for job QryBrlyPtyList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyPtyList.h"

#include "QryBrlyPtyList_blks.cpp"

/******************************************************************************
 class QryBrlyPtyList
 ******************************************************************************/

QryBrlyPtyList::QryBrlyPtyList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYPTYLIST, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecBrlyVCall::CALLBRLYPTYMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyPtyList::~QryBrlyPtyList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyPtyList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYPTYUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYPTYUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryBrlyPtyList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecBrlyVPreset::PREBRLYPTYLIST_SRF, jref);
	string preTit = xchg->getTxtvalPreset(VecBrlyVPreset::PREBRLYPTYLIST_TIT, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqptylist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMPlntype.ref)";
	sqlstr += " FROM TblBrlyMPlntype";
	rerun_filtSQL(sqlstr, preSrf, preTit, true);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQPtyList(jref, jnum, ref, sref, Title, srefBrlyKEqptype, Capacity)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMPlntype.ref, TblBrlyMPlntype.sref, TblBrlyMPlntype.Title, TblBrlyMPlntype.srefBrlyKEqptype, TblBrlyMPlntype.Capacity";
	sqlstr += " FROM TblBrlyMPlntype";
	rerun_filtSQL(sqlstr, preSrf, preTit, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQPtyList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyPtyList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const string& preTit
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMPlntype.sref = '" + preSrf + "'";
	};

	if (preTit.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMPlntype.Title LIKE '" + preTit + "'";
	};
};

void QryBrlyPtyList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyPtyList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblBrlyMPlntype.sref ASC";
	else if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblBrlyMPlntype.Title ASC";
};

void QryBrlyPtyList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQPtyList* rec = NULL;

	dbsbrly->tblbrlyqptylist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titSrefBrlyKEqptype = dbsbrly->getKlstTitleBySref(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, rec->srefBrlyKEqptype, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyPtyList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyPtyList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQPtyList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyPtyList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQPtyList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQPtyList* QryBrlyPtyList::getRecByJnum(
			const uint jnum
		) {
	BrlyQPtyList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyPtyList::handleRequest(
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

bool QryBrlyPtyList::handleRerun(
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

bool QryBrlyPtyList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQPtyList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\tsrefBrlyKEqptype";
	cout << "\ttitSrefBrlyKEqptype";
	cout << "\tCapacity";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->srefBrlyKEqptype;
		cout << "\t" << rec->titSrefBrlyKEqptype;
		cout << "\t" << rec->Capacity;
		cout << endl;
	};
	return retval;
};

void QryBrlyPtyList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYPTYMOD) {
		call->abort = handleCallBrlyPtyMod(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYPTYUPD_REFEQ) {
		call->abort = handleCallBrlyPtyUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyPtyList::handleCallBrlyStubChg(
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

bool QryBrlyPtyList::handleCallBrlyPtyMod(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixBrlyVQrystate == VecBrlyVQrystate::UTD) || (ixBrlyVQrystate == VecBrlyVQrystate::SLM)) {
		ixBrlyVQrystate = VecBrlyVQrystate::MNR;
		xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);
	};

	return retval;
};

bool QryBrlyPtyList::handleCallBrlyPtyUpd_refEq(
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

