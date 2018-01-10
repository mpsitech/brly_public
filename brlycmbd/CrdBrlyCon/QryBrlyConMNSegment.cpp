/**
  * \file QryBrlyConMNSegment.cpp
  * job handler for job QryBrlyConMNSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyConMNSegment.h"

#include "QryBrlyConMNSegment_blks.cpp"

/******************************************************************************
 class QryBrlyConMNSegment
 ******************************************************************************/

QryBrlyConMNSegment::QryBrlyConMNSegment(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYCONMNSEGMENT, jrefSup, ixBrlyVLocale) {

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

QryBrlyConMNSegment::~QryBrlyConMNSegment() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyConMNSegment::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyConMNSegment::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCon = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);
	int preTime = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYTIME, jref);
	double prePhi = xchg->getDblvalPreset(VecBrlyVPreset::PREBRLYPHI, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYCONRSEGMOD_CONEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqconmnsegment->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyRMConnectionMSegment.ref)";
	sqlstr += " FROM TblBrlyRMConnectionMSegment, TblBrlyMSegment";
	sqlstr += " WHERE TblBrlyRMConnectionMSegment.refBrlyMSegment = TblBrlyMSegment.ref";
	sqlstr += " AND TblBrlyRMConnectionMSegment.refBrlyMConnection = " + to_string(preRefCon) + "";
	rerun_filtSQL(sqlstr, preTime, prePhi, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQConMNSegment(jref, jnum, mref, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMSegment.ref, TblBrlyRMConnectionMSegment.ref, TblBrlyRMConnectionMSegment.x1Start, TblBrlyRMConnectionMSegment.x1Stop, TblBrlyRMConnectionMSegment.x2Legphi0, TblBrlyRMConnectionMSegment.x2Legphi1";
	sqlstr += " FROM TblBrlyRMConnectionMSegment, TblBrlyMSegment";
	sqlstr += " WHERE TblBrlyRMConnectionMSegment.refBrlyMSegment = TblBrlyMSegment.ref";
	sqlstr += " AND TblBrlyRMConnectionMSegment.refBrlyMConnection = " + to_string(preRefCon) + "";
	rerun_filtSQL(sqlstr, preTime, prePhi, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQConMNSegment SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYCONRSEGMOD_CONEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefCon, Clstn::VecVJactype::LOCK);
};

void QryBrlyConMNSegment::rerun_filtSQL(
			string& sqlstr
			, const int preTime
			, const double prePhi
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTime != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyRMConnectionMSegment.x1Start <= " + to_string(preTime) + "";
	};

	if (preTime != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyRMConnectionMSegment.x1Stop >= " + to_string(preTime) + "";
	};

	if (prePhi != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyRMConnectionMSegment.x2Legphi0 <= " + to_string(prePhi) + "";
	};

	if (prePhi != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyRMConnectionMSegment.x2Legphi1 >= " + to_string(prePhi) + "";
	};
};

void QryBrlyConMNSegment::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyConMNSegment::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQConMNSegment* rec = NULL;

	dbsbrly->tblbrlyqconmnsegment->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubBrly::getStubSegStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyConMNSegment", "fetch");
	};

	refreshJnum();
};

uint QryBrlyConMNSegment::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQConMNSegment* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyConMNSegment::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQConMNSegment* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQConMNSegment* QryBrlyConMNSegment::getRecByJnum(
			const uint jnum
		) {
	BrlyQConMNSegment* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyConMNSegment::handleRequest(
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

bool QryBrlyConMNSegment::handleRerun(
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

bool QryBrlyConMNSegment::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQConMNSegment* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tx1Start";
	cout << "\tftmX1Start";
	cout << "\tx1Stop";
	cout << "\tftmX1Stop";
	cout << "\tx2Legphi0";
	cout << "\tx2Legphi1";
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
		cout << "\t" << rec->x1Start;
		cout << "\t" << rec->ftmX1Start;
		cout << "\t" << rec->x1Stop;
		cout << "\t" << rec->ftmX1Stop;
		cout << "\t" << rec->x2Legphi0;
		cout << "\t" << rec->x2Legphi1;
		cout << endl;
	};
	return retval;
};

void QryBrlyConMNSegment::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCONRSEGMOD_CONEQ) {
		call->abort = handleCallBrlyConRsegMod_conEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyConMNSegment::handleCallBrlyStubChg(
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

bool QryBrlyConMNSegment::handleCallBrlyConRsegMod_conEq(
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

