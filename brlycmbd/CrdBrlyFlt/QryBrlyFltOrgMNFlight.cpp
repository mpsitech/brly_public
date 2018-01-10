/**
  * \file QryBrlyFltOrgMNFlight.cpp
  * job handler for job QryBrlyFltOrgMNFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyFltOrgMNFlight.h"

#include "QryBrlyFltOrgMNFlight_blks.cpp"

/******************************************************************************
 class QryBrlyFltOrgMNFlight
 ******************************************************************************/

QryBrlyFltOrgMNFlight::QryBrlyFltOrgMNFlight(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYFLTORGMNFLIGHT, jrefSup, ixBrlyVLocale) {

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

QryBrlyFltOrgMNFlight::~QryBrlyFltOrgMNFlight() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyFltOrgMNFlight::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyFltOrgMNFlight::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefFlt = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFFLT, jref);
	int preTime = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYTIME, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYFLTRFLTMOD_OFLEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqfltorgmnflight->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyRMFlightMFlight.ref)";
	sqlstr += " FROM TblBrlyRMFlightMFlight, TblBrlyMFlight";
	sqlstr += " WHERE TblBrlyRMFlightMFlight.dstRefBrlyMFlight = TblBrlyMFlight.ref";
	sqlstr += " AND TblBrlyRMFlightMFlight.orgRefBrlyMFlight = " + to_string(preRefFlt) + "";
	rerun_filtSQL(sqlstr, preTime, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQFltOrgMNFlight(jref, jnum, mref, ref, x1VisStart, x1VisStop, xVisStart, xVisStop)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMFlight.ref, TblBrlyRMFlightMFlight.ref, TblBrlyRMFlightMFlight.x1VisStart, TblBrlyRMFlightMFlight.x1VisStop, TblBrlyRMFlightMFlight.xVisStart, TblBrlyRMFlightMFlight.xVisStop";
	sqlstr += " FROM TblBrlyRMFlightMFlight, TblBrlyMFlight";
	sqlstr += " WHERE TblBrlyRMFlightMFlight.dstRefBrlyMFlight = TblBrlyMFlight.ref";
	sqlstr += " AND TblBrlyRMFlightMFlight.orgRefBrlyMFlight = " + to_string(preRefFlt) + "";
	rerun_filtSQL(sqlstr, preTime, false);
	sqlstr += " ORDER BY TblBrlyMFlight.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQFltOrgMNFlight SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYFLTRFLTMOD_OFLEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefFlt, Clstn::VecVJactype::LOCK);
};

void QryBrlyFltOrgMNFlight::rerun_filtSQL(
			string& sqlstr
			, const int preTime
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTime != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyRMFlightMFlight.x1VisStart <= " + to_string(preTime) + "";
	};

	if (preTime != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyRMFlightMFlight.x1VisStop >= " + to_string(preTime) + "";
	};
};

void QryBrlyFltOrgMNFlight::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyFltOrgMNFlight::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQFltOrgMNFlight* rec = NULL;

	dbsbrly->tblbrlyqfltorgmnflight->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubBrly::getStubFltStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyFltOrgMNFlight", "fetch");
	};

	refreshJnum();
};

uint QryBrlyFltOrgMNFlight::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQFltOrgMNFlight* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyFltOrgMNFlight::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQFltOrgMNFlight* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQFltOrgMNFlight* QryBrlyFltOrgMNFlight::getRecByJnum(
			const uint jnum
		) {
	BrlyQFltOrgMNFlight* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyFltOrgMNFlight::handleRequest(
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

bool QryBrlyFltOrgMNFlight::handleRerun(
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

bool QryBrlyFltOrgMNFlight::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQFltOrgMNFlight* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tx1VisStart";
	cout << "\tftmX1VisStart";
	cout << "\tx1VisStop";
	cout << "\tftmX1VisStop";
	cout << "\txVisStart";
	cout << "\tftmXVisStart";
	cout << "\txVisStop";
	cout << "\tftmXVisStop";
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
		cout << "\t" << rec->x1VisStart;
		cout << "\t" << rec->ftmX1VisStart;
		cout << "\t" << rec->x1VisStop;
		cout << "\t" << rec->ftmX1VisStop;
		cout << "\t" << rec->xVisStart;
		cout << "\t" << rec->ftmXVisStart;
		cout << "\t" << rec->xVisStop;
		cout << "\t" << rec->ftmXVisStop;
		cout << endl;
	};
	return retval;
};

void QryBrlyFltOrgMNFlight::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFLTRFLTMOD_OFLEQ) {
		call->abort = handleCallBrlyFltRfltMod_oflEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyFltOrgMNFlight::handleCallBrlyStubChg(
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

bool QryBrlyFltOrgMNFlight::handleCallBrlyFltRfltMod_oflEq(
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

