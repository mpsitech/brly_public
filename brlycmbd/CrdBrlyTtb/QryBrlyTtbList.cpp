/**
  * \file QryBrlyTtbList.cpp
  * job handler for job QryBrlyTtbList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyTtbList.h"

#include "QryBrlyTtbList_blks.cpp"

/******************************************************************************
 class QryBrlyTtbList
 ******************************************************************************/

QryBrlyTtbList::QryBrlyTtbList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYTTBLIST, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecBrlyVCall::CALLBRLYTTBMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyTtbList::~QryBrlyTtbList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyTtbList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYTTBUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYTTBUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryBrlyTtbList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	string preTit = xchg->getTxtvalPreset(VecBrlyVPreset::PREBRLYTTBLIST_TIT, jref);
	ubigint preFil = xchg->getRefPreset(VecBrlyVPreset::PREBRLYTTBLIST_FIL, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqttblist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMTimetable.ref)";
	sqlstr += " FROM TblBrlyMTimetable";
	rerun_filtSQL(sqlstr, preTit, preFil, true);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQTtbList(jref, jnum, ref, Title, refBrlyMFile, srefBrlyKAlliance, startd, stopd)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMTimetable.ref, TblBrlyMTimetable.Title, TblBrlyMTimetable.refBrlyMFile, TblBrlyMTimetable.srefBrlyKAlliance, TblBrlyMTimetable.startd, TblBrlyMTimetable.stopd";
	sqlstr += " FROM TblBrlyMTimetable";
	rerun_filtSQL(sqlstr, preTit, preFil, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQTtbList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyTtbList::rerun_filtSQL(
			string& sqlstr
			, const string& preTit
			, const ubigint preFil
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTit.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMTimetable.Title LIKE '" + preTit + "'";
	};

	if (preFil != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMTimetable.refBrlyMFile = " + to_string(preFil) + "";
	};
};

void QryBrlyTtbList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyTtbList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblBrlyMTimetable.Title ASC";
	else if (preIxOrd == VecVOrd::FIL) sqlstr += " ORDER BY TblBrlyMTimetable.refBrlyMFile ASC";
};

void QryBrlyTtbList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQTtbList* rec = NULL;

	dbsbrly->tblbrlyqttblist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefBrlyMFile = StubBrly::getStubFilStd(dbsbrly, rec->refBrlyMFile, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titSrefBrlyKAlliance = dbsbrly->getKlstTitleBySref(VecBrlyVKeylist::KLSTBRLYKALLIANCE, rec->srefBrlyKAlliance, ixBrlyVLocale);
			rec->ftmStartd = Ftm::date(rec->startd);
			rec->ftmStopd = Ftm::date(rec->stopd);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyTtbList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyTtbList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQTtbList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyTtbList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQTtbList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQTtbList* QryBrlyTtbList::getRecByJnum(
			const uint jnum
		) {
	BrlyQTtbList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyTtbList::handleRequest(
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

bool QryBrlyTtbList::handleRerun(
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

bool QryBrlyTtbList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQTtbList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\trefBrlyMFile";
	cout << "\tstubRefBrlyMFile";
	cout << "\tsrefBrlyKAlliance";
	cout << "\ttitSrefBrlyKAlliance";
	cout << "\tstartd";
	cout << "\tftmStartd";
	cout << "\tstopd";
	cout << "\tftmStopd";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->refBrlyMFile;
		cout << "\t" << rec->stubRefBrlyMFile;
		cout << "\t" << rec->srefBrlyKAlliance;
		cout << "\t" << rec->titSrefBrlyKAlliance;
		cout << "\t" << rec->startd;
		cout << "\t" << rec->ftmStartd;
		cout << "\t" << rec->stopd;
		cout << "\t" << rec->ftmStopd;
		cout << endl;
	};
	return retval;
};

void QryBrlyTtbList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYTTBMOD) {
		call->abort = handleCallBrlyTtbMod(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYTTBUPD_REFEQ) {
		call->abort = handleCallBrlyTtbUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyTtbList::handleCallBrlyStubChg(
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

bool QryBrlyTtbList::handleCallBrlyTtbMod(
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

bool QryBrlyTtbList::handleCallBrlyTtbUpd_refEq(
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

