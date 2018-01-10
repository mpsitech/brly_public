/**
  * \file QryBrlyLocMNLeg.cpp
  * job handler for job QryBrlyLocMNLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyLocMNLeg.h"

#include "QryBrlyLocMNLeg_blks.cpp"

/******************************************************************************
 class QryBrlyLocMNLeg
 ******************************************************************************/

QryBrlyLocMNLeg::QryBrlyLocMNLeg(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYLOCMNLEG, jrefSup, ixBrlyVLocale) {

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

QryBrlyLocMNLeg::~QryBrlyLocMNLeg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyLocMNLeg::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyLocMNLeg::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefLoc = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLOC, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYLEGRLOCMOD_LOCEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqlocmnleg->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyRMLegMLocation.ref)";
	sqlstr += " FROM TblBrlyRMLegMLocation, TblBrlyMLeg";
	sqlstr += " WHERE TblBrlyRMLegMLocation.refBrlyMLeg = TblBrlyMLeg.ref";
	sqlstr += " AND TblBrlyRMLegMLocation.refBrlyMLocation = " + to_string(preRefLoc) + "";
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQLocMNLeg(jref, jnum, mref, ref, x1VisLegphi0, x1VisLegphi1, legphi, legtheta, xVisLegphi0, xVisLegphi1)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMLeg.ref, TblBrlyRMLegMLocation.ref, TblBrlyRMLegMLocation.x1VisLegphi0, TblBrlyRMLegMLocation.x1VisLegphi1, TblBrlyRMLegMLocation.legphi, TblBrlyRMLegMLocation.legtheta, TblBrlyRMLegMLocation.xVisLegphi0, TblBrlyRMLegMLocation.xVisLegphi1";
	sqlstr += " FROM TblBrlyRMLegMLocation, TblBrlyMLeg";
	sqlstr += " WHERE TblBrlyRMLegMLocation.refBrlyMLeg = TblBrlyMLeg.ref";
	sqlstr += " AND TblBrlyRMLegMLocation.refBrlyMLocation = " + to_string(preRefLoc) + "";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQLocMNLeg SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYLEGRLOCMOD_LOCEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefLoc, Clstn::VecVJactype::LOCK);
};

void QryBrlyLocMNLeg::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQLocMNLeg* rec = NULL;

	dbsbrly->tblbrlyqlocmnleg->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubBrly::getStubLegStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyLocMNLeg", "fetch");
	};

	refreshJnum();
};

uint QryBrlyLocMNLeg::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQLocMNLeg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyLocMNLeg::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQLocMNLeg* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQLocMNLeg* QryBrlyLocMNLeg::getRecByJnum(
			const uint jnum
		) {
	BrlyQLocMNLeg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyLocMNLeg::handleRequest(
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

bool QryBrlyLocMNLeg::handleRerun(
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

bool QryBrlyLocMNLeg::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQLocMNLeg* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tx1VisLegphi0";
	cout << "\tx1VisLegphi1";
	cout << "\tlegphi";
	cout << "\tlegtheta";
	cout << "\txVisLegphi0";
	cout << "\txVisLegphi1";
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
		cout << "\t" << rec->x1VisLegphi0;
		cout << "\t" << rec->x1VisLegphi1;
		cout << "\t" << rec->legphi;
		cout << "\t" << rec->legtheta;
		cout << "\t" << rec->xVisLegphi0;
		cout << "\t" << rec->xVisLegphi1;
		cout << endl;
	};
	return retval;
};

void QryBrlyLocMNLeg::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEGRLOCMOD_LOCEQ) {
		call->abort = handleCallBrlyLegRlocMod_locEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyLocMNLeg::handleCallBrlyStubChg(
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

bool QryBrlyLocMNLeg::handleCallBrlyLegRlocMod_locEq(
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

