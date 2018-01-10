/**
  * \file QryBrlyRlyList.cpp
  * job handler for job QryBrlyRlyList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyRlyList.h"

#include "QryBrlyRlyList_blks.cpp"

/******************************************************************************
 class QryBrlyRlyList
 ******************************************************************************/

QryBrlyRlyList::QryBrlyRlyList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYRLYLIST, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecBrlyVCall::CALLBRLYRLYMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyRlyList::~QryBrlyRlyList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyRlyList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYRLYUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYRLYUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryBrlyRlyList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	ubigint preRefCon = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);
	int preSta = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYRLYLIST_STA, jref);
	int preSto = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYRLYLIST_STO, jref);
	ubigint preCon = xchg->getRefPreset(VecBrlyVPreset::PREBRLYRLYLIST_CON, jref);
	uint preDir = xchg->getIxPreset(VecBrlyVPreset::PREBRLYRLYLIST_DIR, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqrlylist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecBrlyVPreset::PREBRLYREFCON) {
		sqlstr = "SELECT COUNT(TblBrlyMRelay.ref)";
		sqlstr += " FROM TblBrlyMRelay";
		sqlstr += " WHERE TblBrlyMRelay.refBrlyMConnection = " + to_string(preRefCon) + "";
		rerun_filtSQL(sqlstr, preSta, preSto, preCon, preDir, false);
		dbsbrly->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblBrlyMRelay.ref)";
		sqlstr += " FROM TblBrlyMRelay";
		rerun_filtSQL(sqlstr, preSta, preSto, preCon, preDir, true);
		dbsbrly->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cntsum) {
		if (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	for (unsigned int i=0;i<cnts.size();i++) {
		if (statshr.nload < stgiac.nload) {
			if ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {
				if (statshr.ntot >= stgiac.jnumFirstload) {
					ofss[i] = 0;
				} else {
					ofss[i] = stgiac.jnumFirstload-statshr.ntot-1;
				};

				if ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;
				else lims[i] = cnts[i]-ofss[i];
			};
		};

		statshr.ntot += cnts[i];
		statshr.nload += lims[i];
	};

	if (preIxPre == VecBrlyVPreset::PREBRLYREFCON) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblBrlyMRelay";
		sqlstr += " WHERE TblBrlyMRelay.refBrlyMConnection = " + to_string(preRefCon) + "";
		rerun_filtSQL(sqlstr, preSta, preSto, preCon, preDir, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsbrly->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblBrlyMRelay";
		rerun_filtSQL(sqlstr, preSta, preSto, preCon, preDir, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsbrly->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblBrlyQRlyList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyRlyList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblBrlyQRlyList(jref, jnum, ref, x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMRelay.ref, TblBrlyMRelay.x1Start, TblBrlyMRelay.x1Stop, TblBrlyMRelay.refBrlyMConnection, TblBrlyMRelay.ixVDir, TblBrlyMRelay.Connected";
};

void QryBrlyRlyList::rerun_filtSQL(
			string& sqlstr
			, const int preSta
			, const int preSto
			, const ubigint preCon
			, const uint preDir
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSta != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMRelay.x1Start = " + to_string(preSta) + "";
	};

	if (preSto != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMRelay.x1Stop = " + to_string(preSto) + "";
	};

	if (preCon != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMRelay.refBrlyMConnection = " + to_string(preCon) + "";
	};

	if (preDir != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMRelay.ixVDir = " + to_string(preDir) + "";
	};
};

void QryBrlyRlyList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyRlyList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblBrlyMRelay.x1Start ASC";
	else if (preIxOrd == VecVOrd::STO) sqlstr += " ORDER BY TblBrlyMRelay.x1Stop ASC";
	else if (preIxOrd == VecVOrd::CON) sqlstr += " ORDER BY TblBrlyMRelay.refBrlyMConnection ASC";
	else if (preIxOrd == VecVOrd::DIR) sqlstr += " ORDER BY TblBrlyMRelay.ixVDir ASC";
};

void QryBrlyRlyList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQRlyList* rec = NULL;

	dbsbrly->tblbrlyqrlylist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefBrlyMConnection = StubBrly::getStubConStd(dbsbrly, rec->refBrlyMConnection, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVDir = VecBrlyVMRelayDir::getSref(rec->ixVDir);
			rec->titIxVDir = VecBrlyVMRelayDir::getTitle(rec->ixVDir, ixBrlyVLocale);
			if (rec->Connected) rec->yesnoConnected = VecBrlyVTag::getTitle(VecBrlyVTag::YES, ixBrlyVLocale); else rec->yesnoConnected = VecBrlyVTag::getTitle(VecBrlyVTag::NO, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyRlyList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyRlyList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQRlyList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyRlyList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQRlyList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQRlyList* QryBrlyRlyList::getRecByJnum(
			const uint jnum
		) {
	BrlyQRlyList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyRlyList::handleRequest(
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

bool QryBrlyRlyList::handleRerun(
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

bool QryBrlyRlyList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQRlyList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1Start";
	cout << "\tftmX1Start";
	cout << "\tx1Stop";
	cout << "\tftmX1Stop";
	cout << "\trefBrlyMConnection";
	cout << "\tstubRefBrlyMConnection";
	cout << "\tixVDir";
	cout << "\tsrefIxVDir";
	cout << "\ttitIxVDir";
	cout << "\tConnected";
	cout << "\tyesnoConnected";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1Start;
		cout << "\t" << rec->ftmX1Start;
		cout << "\t" << rec->x1Stop;
		cout << "\t" << rec->ftmX1Stop;
		cout << "\t" << rec->refBrlyMConnection;
		cout << "\t" << rec->stubRefBrlyMConnection;
		cout << "\t" << rec->ixVDir;
		cout << "\t" << rec->srefIxVDir;
		cout << "\t" << rec->titIxVDir;
		cout << "\t" << rec->Connected;
		cout << "\t" << rec->yesnoConnected;
		cout << endl;
	};
	return retval;
};

void QryBrlyRlyList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYRLYMOD) {
		call->abort = handleCallBrlyRlyMod(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYRLYUPD_REFEQ) {
		call->abort = handleCallBrlyRlyUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyRlyList::handleCallBrlyStubChg(
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

bool QryBrlyRlyList::handleCallBrlyRlyMod(
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

bool QryBrlyRlyList::handleCallBrlyRlyUpd_refEq(
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

