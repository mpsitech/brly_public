/**
  * \file QryBrlyPrsADetail.cpp
  * job handler for job QryBrlyPrsADetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyPrsADetail.h"

#include "QryBrlyPrsADetail_blks.cpp"

/******************************************************************************
 class QryBrlyPrsADetail
 ******************************************************************************/

QryBrlyPrsADetail::QryBrlyPrsADetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYPRSADETAIL, jrefSup, ixBrlyVLocale) {

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

QryBrlyPrsADetail::~QryBrlyPrsADetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyPrsADetail::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyPrsADetail::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefPrs = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFPRS, jref);
	string preX1 = xchg->getSrefPreset(VecBrlyVPreset::PREBRLYPRSADETAIL_X1, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYPRSADETMOD_PRSEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqprsadetail->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyAMPersonDetail.ref)";
	sqlstr += " FROM TblBrlyAMPersonDetail";
	sqlstr += " WHERE TblBrlyAMPersonDetail.refBrlyMPerson = " + to_string(preRefPrs) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQPrsADetail(jref, jnum, ref, x1SrefKType, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyAMPersonDetail.ref, TblBrlyAMPersonDetail.x1SrefKType, TblBrlyAMPersonDetail.Val";
	sqlstr += " FROM TblBrlyAMPersonDetail";
	sqlstr += " WHERE TblBrlyAMPersonDetail.refBrlyMPerson = " + to_string(preRefPrs) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQPrsADetail SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYPRSADETMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefPrs, Clstn::VecVJactype::LOCK);
};

void QryBrlyPrsADetail::rerun_filtSQL(
			string& sqlstr
			, const string& preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyAMPersonDetail.x1SrefKType = '" + preX1 + "'";
	};
};

void QryBrlyPrsADetail::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyPrsADetail::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQPrsADetail* rec = NULL;

	dbsbrly->tblbrlyqprsadetail->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX1SrefKType = dbsbrly->getKlstTitleBySref(VecBrlyVKeylist::KLSTBRLYKAMPERSONDETAILTYPE, rec->x1SrefKType, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyPrsADetail", "fetch");
	};

	refreshJnum();
};

uint QryBrlyPrsADetail::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQPrsADetail* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyPrsADetail::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQPrsADetail* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQPrsADetail* QryBrlyPrsADetail::getRecByJnum(
			const uint jnum
		) {
	BrlyQPrsADetail* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyPrsADetail::handleRequest(
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

bool QryBrlyPrsADetail::handleRerun(
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

bool QryBrlyPrsADetail::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQPrsADetail* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1SrefKType";
	cout << "\ttitX1SrefKType";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1SrefKType;
		cout << "\t" << rec->titX1SrefKType;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryBrlyPrsADetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYPRSADETMOD_PRSEQ) {
		call->abort = handleCallBrlyPrsAdetMod_prsEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyPrsADetail::handleCallBrlyStubChg(
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

bool QryBrlyPrsADetail::handleCallBrlyPrsAdetMod_prsEq(
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

