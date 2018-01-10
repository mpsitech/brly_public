/**
  * \file QryBrlyLegOrgMNLeg.cpp
  * job handler for job QryBrlyLegOrgMNLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyLegOrgMNLeg.h"

#include "QryBrlyLegOrgMNLeg_blks.cpp"

/******************************************************************************
 class QryBrlyLegOrgMNLeg
 ******************************************************************************/

QryBrlyLegOrgMNLeg::QryBrlyLegOrgMNLeg(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYLEGORGMNLEG, jrefSup, ixBrlyVLocale) {

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

QryBrlyLegOrgMNLeg::~QryBrlyLegOrgMNLeg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyLegOrgMNLeg::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyLegOrgMNLeg::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefLeg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLEG, jref);
	double prePhi = xchg->getDblvalPreset(VecBrlyVPreset::PREBRLYPHI, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYLEGRLEGMOD_OLGEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqlegorgmnleg->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyRMLegMLeg.ref)";
	sqlstr += " FROM TblBrlyRMLegMLeg, TblBrlyMLeg";
	sqlstr += " WHERE TblBrlyRMLegMLeg.dstRefBrlyMLeg = TblBrlyMLeg.ref";
	sqlstr += " AND TblBrlyRMLegMLeg.orgRefBrlyMLeg = " + to_string(preRefLeg) + "";
	rerun_filtSQL(sqlstr, prePhi, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQLegOrgMNLeg(jref, jnum, mref, ref, x1VisDstLegphi0, x1VisDstLegphi1, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMLeg.ref, TblBrlyRMLegMLeg.ref, TblBrlyRMLegMLeg.x1VisDstLegphi0, TblBrlyRMLegMLeg.x1VisDstLegphi1, TblBrlyRMLegMLeg.VisOrgLegphi0, TblBrlyRMLegMLeg.VisOrgLegphi1, TblBrlyRMLegMLeg.xVisDstLegphi0, TblBrlyRMLegMLeg.xVisDstLegphi1, TblBrlyRMLegMLeg.xVisOrgLegphi0, TblBrlyRMLegMLeg.xVisOrgLegphi1";
	sqlstr += " FROM TblBrlyRMLegMLeg, TblBrlyMLeg";
	sqlstr += " WHERE TblBrlyRMLegMLeg.dstRefBrlyMLeg = TblBrlyMLeg.ref";
	sqlstr += " AND TblBrlyRMLegMLeg.orgRefBrlyMLeg = " + to_string(preRefLeg) + "";
	rerun_filtSQL(sqlstr, prePhi, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQLegOrgMNLeg SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYLEGRLEGMOD_OLGEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefLeg, Clstn::VecVJactype::LOCK);
};

void QryBrlyLegOrgMNLeg::rerun_filtSQL(
			string& sqlstr
			, const double prePhi
			, const bool addwhere
		) {
	bool first = addwhere;

	if (prePhi != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyRMLegMLeg.x1VisDstLegphi0 <= " + to_string(prePhi) + "";
	};

	if (prePhi != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyRMLegMLeg.x1VisDstLegphi1 >= " + to_string(prePhi) + "";
	};
};

void QryBrlyLegOrgMNLeg::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyLegOrgMNLeg::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQLegOrgMNLeg* rec = NULL;

	dbsbrly->tblbrlyqlegorgmnleg->loadRstByJref(jref, false, rst);
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
		stmgr->unlockAccess("QryBrlyLegOrgMNLeg", "fetch");
	};

	refreshJnum();
};

uint QryBrlyLegOrgMNLeg::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQLegOrgMNLeg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyLegOrgMNLeg::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQLegOrgMNLeg* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQLegOrgMNLeg* QryBrlyLegOrgMNLeg::getRecByJnum(
			const uint jnum
		) {
	BrlyQLegOrgMNLeg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyLegOrgMNLeg::handleRequest(
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

bool QryBrlyLegOrgMNLeg::handleRerun(
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

bool QryBrlyLegOrgMNLeg::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQLegOrgMNLeg* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tx1VisDstLegphi0";
	cout << "\tx1VisDstLegphi1";
	cout << "\tVisOrgLegphi0";
	cout << "\tVisOrgLegphi1";
	cout << "\txVisDstLegphi0";
	cout << "\txVisDstLegphi1";
	cout << "\txVisOrgLegphi0";
	cout << "\txVisOrgLegphi1";
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
		cout << "\t" << rec->x1VisDstLegphi0;
		cout << "\t" << rec->x1VisDstLegphi1;
		cout << "\t" << rec->VisOrgLegphi0;
		cout << "\t" << rec->VisOrgLegphi1;
		cout << "\t" << rec->xVisDstLegphi0;
		cout << "\t" << rec->xVisDstLegphi1;
		cout << "\t" << rec->xVisOrgLegphi0;
		cout << "\t" << rec->xVisOrgLegphi1;
		cout << endl;
	};
	return retval;
};

void QryBrlyLegOrgMNLeg::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEGRLEGMOD_OLGEQ) {
		call->abort = handleCallBrlyLegRlegMod_olgEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyLegOrgMNLeg::handleCallBrlyStubChg(
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

bool QryBrlyLegOrgMNLeg::handleCallBrlyLegRlegMod_olgEq(
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

