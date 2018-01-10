/**
  * \file QryBrlyConList.cpp
  * job handler for job QryBrlyConList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyConList.h"

#include "QryBrlyConList_blks.cpp"

/******************************************************************************
 class QryBrlyConList
 ******************************************************************************/

QryBrlyConList::QryBrlyConList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYCONLIST, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecBrlyVCall::CALLBRLYCONMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyConList::~QryBrlyConList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyConList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYCONUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYCONUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryBrlyConList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	ubigint preFlt = xchg->getRefPreset(VecBrlyVPreset::PREBRLYCONLIST_FLT, jref);
	ubigint preCor = xchg->getRefPreset(VecBrlyVPreset::PREBRLYCONLIST_COR, jref);
	int preSta = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYCONLIST_STA, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqconlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMConnection.ref)";
	sqlstr += " FROM TblBrlyMConnection";
	rerun_filtSQL(sqlstr, preFlt, preCor, preSta, true);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQConList(jref, jnum, ref, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMConnection.ref, TblBrlyMConnection.refBrlyMFlight, TblBrlyMConnection.corRefBrlyMLeg, TblBrlyMConnection.start, TblBrlyMConnection.stop, TblBrlyMConnection.ixVModel";
	sqlstr += " FROM TblBrlyMConnection";
	rerun_filtSQL(sqlstr, preFlt, preCor, preSta, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQConList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyConList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preFlt
			, const ubigint preCor
			, const int preSta
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preFlt != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMConnection.refBrlyMFlight = " + to_string(preFlt) + "";
	};

	if (preCor != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMConnection.corRefBrlyMLeg = " + to_string(preCor) + "";
	};

	if (preSta != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMConnection.start = " + to_string(preSta) + "";
	};
};

void QryBrlyConList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyConList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::FLT) sqlstr += " ORDER BY TblBrlyMConnection.refBrlyMFlight ASC";
	else if (preIxOrd == VecVOrd::COR) sqlstr += " ORDER BY TblBrlyMConnection.corRefBrlyMLeg ASC";
	else if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblBrlyMConnection.start ASC";
};

void QryBrlyConList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQConList* rec = NULL;

	dbsbrly->tblbrlyqconlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefBrlyMFlight = StubBrly::getStubFltStd(dbsbrly, rec->refBrlyMFlight, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubCorRefBrlyMLeg = StubBrly::getStubLegStd(dbsbrly, rec->corRefBrlyMLeg, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVModel = VecBrlyVMConnectionModel::getSref(rec->ixVModel);
			rec->titIxVModel = VecBrlyVMConnectionModel::getTitle(rec->ixVModel, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyConList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyConList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQConList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyConList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQConList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQConList* QryBrlyConList::getRecByJnum(
			const uint jnum
		) {
	BrlyQConList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyConList::handleRequest(
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

bool QryBrlyConList::handleRerun(
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

bool QryBrlyConList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQConList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefBrlyMFlight";
	cout << "\tstubRefBrlyMFlight";
	cout << "\tcorRefBrlyMLeg";
	cout << "\tstubCorRefBrlyMLeg";
	cout << "\tstart";
	cout << "\tftmStart";
	cout << "\tstop";
	cout << "\tftmStop";
	cout << "\tixVModel";
	cout << "\tsrefIxVModel";
	cout << "\ttitIxVModel";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refBrlyMFlight;
		cout << "\t" << rec->stubRefBrlyMFlight;
		cout << "\t" << rec->corRefBrlyMLeg;
		cout << "\t" << rec->stubCorRefBrlyMLeg;
		cout << "\t" << rec->start;
		cout << "\t" << rec->ftmStart;
		cout << "\t" << rec->stop;
		cout << "\t" << rec->ftmStop;
		cout << "\t" << rec->ixVModel;
		cout << "\t" << rec->srefIxVModel;
		cout << "\t" << rec->titIxVModel;
		cout << endl;
	};
	return retval;
};

void QryBrlyConList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCONMOD) {
		call->abort = handleCallBrlyConMod(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCONUPD_REFEQ) {
		call->abort = handleCallBrlyConUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyConList::handleCallBrlyStubChg(
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

bool QryBrlyConList::handleCallBrlyConMod(
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

bool QryBrlyConList::handleCallBrlyConUpd_refEq(
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

