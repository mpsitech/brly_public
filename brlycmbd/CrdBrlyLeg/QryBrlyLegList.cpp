/**
  * \file QryBrlyLegList.cpp
  * job handler for job QryBrlyLegList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyLegList.h"

#include "QryBrlyLegList_blks.cpp"

/******************************************************************************
 class QryBrlyLegList
 ******************************************************************************/

QryBrlyLegList::QryBrlyLegList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYLEGLIST, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecBrlyVCall::CALLBRLYLEGMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyLegList::~QryBrlyLegList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyLegList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYLEGUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYLEGUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryBrlyLegList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	ubigint preBlo = xchg->getRefPreset(VecBrlyVPreset::PREBRLYLEGLIST_BLO, jref);
	ubigint preElo = xchg->getRefPreset(VecBrlyVPreset::PREBRLYLEGLIST_ELO, jref);
	uint preTyp = xchg->getIxPreset(VecBrlyVPreset::PREBRLYLEGLIST_TYP, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqleglist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMLeg.ref)";
	sqlstr += " FROM TblBrlyMLeg";
	rerun_filtSQL(sqlstr, preBlo, preElo, preTyp, true);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQLegList(jref, jnum, ref, bgnRefBrlyMLocation, endRefBrlyMLocation, ixVBasetype, alt)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMLeg.ref, TblBrlyMLeg.bgnRefBrlyMLocation, TblBrlyMLeg.endRefBrlyMLocation, TblBrlyMLeg.ixVBasetype, TblBrlyMLeg.alt";
	sqlstr += " FROM TblBrlyMLeg";
	rerun_filtSQL(sqlstr, preBlo, preElo, preTyp, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQLegList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyLegList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preBlo
			, const ubigint preElo
			, const uint preTyp
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preBlo != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMLeg.bgnRefBrlyMLocation = " + to_string(preBlo) + "";
	};

	if (preElo != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMLeg.endRefBrlyMLocation = " + to_string(preElo) + "";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMLeg.ixVBasetype = " + to_string(preTyp) + "";
	};
};

void QryBrlyLegList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyLegList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::BLO) sqlstr += " ORDER BY TblBrlyMLeg.bgnRefBrlyMLocation ASC";
	else if (preIxOrd == VecVOrd::ELO) sqlstr += " ORDER BY TblBrlyMLeg.endRefBrlyMLocation ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblBrlyMLeg.ixVBasetype ASC";
};

void QryBrlyLegList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQLegList* rec = NULL;

	dbsbrly->tblbrlyqleglist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubBgnRefBrlyMLocation = StubBrly::getStubLocStd(dbsbrly, rec->bgnRefBrlyMLocation, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubEndRefBrlyMLocation = StubBrly::getStubLocStd(dbsbrly, rec->endRefBrlyMLocation, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVBasetype = VecBrlyVMLegBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecBrlyVMLegBasetype::getTitle(rec->ixVBasetype, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyLegList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyLegList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQLegList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyLegList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQLegList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQLegList* QryBrlyLegList::getRecByJnum(
			const uint jnum
		) {
	BrlyQLegList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyLegList::handleRequest(
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

bool QryBrlyLegList::handleRerun(
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

bool QryBrlyLegList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQLegList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tbgnRefBrlyMLocation";
	cout << "\tstubBgnRefBrlyMLocation";
	cout << "\tendRefBrlyMLocation";
	cout << "\tstubEndRefBrlyMLocation";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\talt";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->bgnRefBrlyMLocation;
		cout << "\t" << rec->stubBgnRefBrlyMLocation;
		cout << "\t" << rec->endRefBrlyMLocation;
		cout << "\t" << rec->stubEndRefBrlyMLocation;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->alt;
		cout << endl;
	};
	return retval;
};

void QryBrlyLegList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEGMOD) {
		call->abort = handleCallBrlyLegMod(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEGUPD_REFEQ) {
		call->abort = handleCallBrlyLegUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyLegList::handleCallBrlyStubChg(
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

bool QryBrlyLegList::handleCallBrlyLegMod(
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

bool QryBrlyLegList::handleCallBrlyLegUpd_refEq(
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

