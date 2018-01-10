/**
  * \file QryBrlyRegADstswitch.cpp
  * job handler for job QryBrlyRegADstswitch (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyRegADstswitch.h"

#include "QryBrlyRegADstswitch_blks.cpp"

/******************************************************************************
 class QryBrlyRegADstswitch
 ******************************************************************************/

QryBrlyRegADstswitch::QryBrlyRegADstswitch(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYREGADSTSWITCH, jrefSup, ixBrlyVLocale) {

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

QryBrlyRegADstswitch::~QryBrlyRegADstswitch() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyRegADstswitch::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyRegADstswitch::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefReg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFREG, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYREGADSSMOD_REGEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqregadstswitch->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyAMRegionDstswitch.ref)";
	sqlstr += " FROM TblBrlyAMRegionDstswitch";
	sqlstr += " WHERE TblBrlyAMRegionDstswitch.refBrlyMRegion = " + to_string(preRefReg) + "";
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQRegADstswitch(jref, jnum, ref, startd, startt)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyAMRegionDstswitch.ref, TblBrlyAMRegionDstswitch.startd, TblBrlyAMRegionDstswitch.startt";
	sqlstr += " FROM TblBrlyAMRegionDstswitch";
	sqlstr += " WHERE TblBrlyAMRegionDstswitch.refBrlyMRegion = " + to_string(preRefReg) + "";
	sqlstr += " ORDER BY startd ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQRegADstswitch SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYREGADSSMOD_REGEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefReg, Clstn::VecVJactype::LOCK);
};

void QryBrlyRegADstswitch::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQRegADstswitch* rec = NULL;

	dbsbrly->tblbrlyqregadstswitch->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->ftmStartd = Ftm::date(rec->startd);
			rec->ftmStartt = Ftm::time(rec->startt);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyRegADstswitch", "fetch");
	};

	refreshJnum();
};

uint QryBrlyRegADstswitch::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQRegADstswitch* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyRegADstswitch::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQRegADstswitch* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQRegADstswitch* QryBrlyRegADstswitch::getRecByJnum(
			const uint jnum
		) {
	BrlyQRegADstswitch* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyRegADstswitch::handleRequest(
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

bool QryBrlyRegADstswitch::handleRerun(
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

bool QryBrlyRegADstswitch::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQRegADstswitch* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstartd";
	cout << "\tftmStartd";
	cout << "\tstartt";
	cout << "\tftmStartt";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->startd;
		cout << "\t" << rec->ftmStartd;
		cout << "\t" << rec->startt;
		cout << "\t" << rec->ftmStartt;
		cout << endl;
	};
	return retval;
};

void QryBrlyRegADstswitch::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREGADSSMOD_REGEQ) {
		call->abort = handleCallBrlyRegAdssMod_regEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyRegADstswitch::handleCallBrlyStubChg(
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

bool QryBrlyRegADstswitch::handleCallBrlyRegAdssMod_regEq(
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

