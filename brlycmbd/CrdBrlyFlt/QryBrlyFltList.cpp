/**
  * \file QryBrlyFltList.cpp
  * job handler for job QryBrlyFltList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyFltList.h"

#include "QryBrlyFltList_blks.cpp"

/******************************************************************************
 class QryBrlyFltList
 ******************************************************************************/

QryBrlyFltList::QryBrlyFltList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYFLTLIST, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecBrlyVCall::CALLBRLYFLTMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyFltList::~QryBrlyFltList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyFltList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYFLTUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYFLTUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryBrlyFltList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecBrlyVPreset::PREBRLYFLTLIST_SRF, jref);
	ubigint preEqp = xchg->getRefPreset(VecBrlyVPreset::PREBRLYFLTLIST_EQP, jref);
	ubigint preLeg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYFLTLIST_LEG, jref);
	int preSta = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYFLTLIST_STA, jref);
	int preSto = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYFLTLIST_STO, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqfltlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMFlight.ref)";
	sqlstr += " FROM TblBrlyMFlight";
	rerun_filtSQL(sqlstr, preSrf, preEqp, preLeg, preSta, preSto, true);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQFltList(jref, jnum, ref, sref, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, start, stop)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMFlight.ref, TblBrlyMFlight.sref, TblBrlyMFlight.refBrlyMEquipment, TblBrlyMFlight.refBrlyMFaflight, TblBrlyMFlight.refBrlyMLeg, TblBrlyMFlight.start, TblBrlyMFlight.stop";
	sqlstr += " FROM TblBrlyMFlight";
	rerun_filtSQL(sqlstr, preSrf, preEqp, preLeg, preSta, preSto, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQFltList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyFltList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preEqp
			, const ubigint preLeg
			, const int preSta
			, const int preSto
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMFlight.sref = '" + preSrf + "'";
	};

	if (preEqp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMFlight.refBrlyMEquipment = " + to_string(preEqp) + "";
	};

	if (preLeg != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMFlight.refBrlyMLeg = " + to_string(preLeg) + "";
	};

	if (preSta != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMFlight.start = " + to_string(preSta) + "";
	};

	if (preSto != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMFlight.stop = " + to_string(preSto) + "";
	};
};

void QryBrlyFltList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyFltList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblBrlyMFlight.sref ASC";
	else if (preIxOrd == VecVOrd::EQP) sqlstr += " ORDER BY TblBrlyMFlight.refBrlyMEquipment ASC";
	else if (preIxOrd == VecVOrd::LEG) sqlstr += " ORDER BY TblBrlyMFlight.refBrlyMLeg ASC";
	else if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblBrlyMFlight.start ASC";
	else if (preIxOrd == VecVOrd::STO) sqlstr += " ORDER BY TblBrlyMFlight.stop ASC";
};

void QryBrlyFltList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQFltList* rec = NULL;

	dbsbrly->tblbrlyqfltlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefBrlyMEquipment = StubBrly::getStubFltStd(dbsbrly, rec->refBrlyMEquipment, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefBrlyMLeg = StubBrly::getStubLegStd(dbsbrly, rec->refBrlyMLeg, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyFltList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyFltList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQFltList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyFltList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQFltList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQFltList* QryBrlyFltList::getRecByJnum(
			const uint jnum
		) {
	BrlyQFltList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyFltList::handleRequest(
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

bool QryBrlyFltList::handleRerun(
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

bool QryBrlyFltList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQFltList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\trefBrlyMEquipment";
	cout << "\tstubRefBrlyMEquipment";
	cout << "\trefBrlyMFaflight";
	cout << "\trefBrlyMLeg";
	cout << "\tstubRefBrlyMLeg";
	cout << "\tstart";
	cout << "\tftmStart";
	cout << "\tstop";
	cout << "\tftmStop";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refBrlyMEquipment;
		cout << "\t" << rec->stubRefBrlyMEquipment;
		cout << "\t" << rec->refBrlyMFaflight;
		cout << "\t" << rec->refBrlyMLeg;
		cout << "\t" << rec->stubRefBrlyMLeg;
		cout << "\t" << rec->start;
		cout << "\t" << rec->ftmStart;
		cout << "\t" << rec->stop;
		cout << "\t" << rec->ftmStop;
		cout << endl;
	};
	return retval;
};

void QryBrlyFltList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFLTMOD) {
		call->abort = handleCallBrlyFltMod(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFLTUPD_REFEQ) {
		call->abort = handleCallBrlyFltUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyFltList::handleCallBrlyStubChg(
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

bool QryBrlyFltList::handleCallBrlyFltMod(
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

bool QryBrlyFltList::handleCallBrlyFltUpd_refEq(
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

