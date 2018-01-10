/**
  * \file QryBrlyConConMNEquipment.cpp
  * job handler for job QryBrlyConConMNEquipment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyConConMNEquipment.h"

#include "QryBrlyConConMNEquipment_blks.cpp"

/******************************************************************************
 class QryBrlyConConMNEquipment
 ******************************************************************************/

QryBrlyConConMNEquipment::QryBrlyConConMNEquipment(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYCONCONMNEQUIPMENT, jrefSup, ixBrlyVLocale) {

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

QryBrlyConConMNEquipment::~QryBrlyConConMNEquipment() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyConConMNEquipment::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyConConMNEquipment::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> refsList;
	vector<ubigint> refsPool;

	ListBrlyORMConnectionMEquipment conOeqps;
	BrlyORMConnectionMEquipment* conOeqp;

	ubigint preRefCon = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);
	int preOprX1 = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYCONCONMNEQUIPMENT_OPR_X1, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYCONREQPMOD_CONEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqconconmnequipment->removeRstByJref(jref);

	sqlstr = "SELECT ref FROM TblBrlyLRMConnectionMEquipment";
	sqlstr += " WHERE conIxBrlyVLat = " + to_string(VecBrlyVLat::INI);
	sqlstr += " AND TblBrlyLRMConnectionMEquipment.conRefBrlyMConnection = " + to_string(preRefCon) + "";
	sqlstr += " ORDER BY conNum ASC";
	dbsbrly->loadRefsBySQL(sqlstr, false, refsList);

	sqlstr = "SELECT ref FROM TblBrlyLRMConnectionMEquipment";
	sqlstr += " WHERE conIxBrlyVLat = " + to_string(VecBrlyVLat::DLO);
	sqlstr += " AND TblBrlyLRMConnectionMEquipment.conRefBrlyMConnection = " + to_string(preRefCon) + "";
	dbsbrly->loadRefsBySQL(sqlstr, false, refsPool);

	sqlstr = "SELECT * FROM TblBrlyORMConnectionMEquipment";
	sqlstr += " WHERE refBrlyMConnection = " + to_string(preRefCon) + "";
	sqlstr += " AND x1Start <= " + to_string(preOprX1) + "";
	dbsbrly->tblbrlyormconnectionmequipment->loadRstBySQL(sqlstr, false, conOeqps);

	for (unsigned int i=0;i<conOeqps.nodes.size();i++) {
		conOeqp = conOeqps.nodes[i];
		Oolop::apply(conOeqp->ixBrlyVOolop, refsList, refsPool, conOeqp->pr1RefLR, conOeqp->pr2RefLR);
	};

	statshr.ntot = refsList.size();
	statshr.nload = 0;

	for (unsigned int i=0;i<refsList.size();i++) dbsbrly->tblbrlyqselect->insertNewRec(NULL, jref, i+1, 0, refsList[i]);
	sqlstr = "INSERT INTO TblBrlyQConConMNEquipment(jref, jnum, mref, ref, conIxBrlyVLat, conNum)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMEquipment.ref, TblBrlyLRMConnectionMEquipment.ref, TblBrlyLRMConnectionMEquipment.conIxBrlyVLat, TblBrlyLRMConnectionMEquipment.conNum";
	sqlstr += " FROM TblBrlyLRMConnectionMEquipment, TblBrlyMEquipment, TblBrlyQSelect";
	sqlstr += " WHERE TblBrlyLRMConnectionMEquipment.refBrlyMEquipment = TblBrlyMEquipment.ref";
	sqlstr += " AND TblBrlyQSelect.jref = " + to_string(jref);
	sqlstr += " AND TblBrlyLRMConnectionMEquipment.ref = TblBrlyQSelect.ref";
	sqlstr += " ORDER BY TblBrlyQSelect.jnum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQConConMNEquipment SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYCONREQPMOD_CONEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefCon, Clstn::VecVJactype::LOCK);
};

void QryBrlyConConMNEquipment::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQConConMNEquipment* rec = NULL;

	dbsbrly->tblbrlyqconconmnequipment->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubBrly::getStubEqpStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefConIxBrlyVLat = VecBrlyVLat::getSref(rec->conIxBrlyVLat);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyConConMNEquipment", "fetch");
	};

	refreshJnum();
};

uint QryBrlyConConMNEquipment::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQConConMNEquipment* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyConConMNEquipment::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQConConMNEquipment* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQConConMNEquipment* QryBrlyConConMNEquipment::getRecByJnum(
			const uint jnum
		) {
	BrlyQConConMNEquipment* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyConConMNEquipment::handleRequest(
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

bool QryBrlyConConMNEquipment::handleRerun(
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

bool QryBrlyConConMNEquipment::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQConConMNEquipment* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tconIxBrlyVLat";
	cout << "\tsrefConIxBrlyVLat";
	cout << "\tconNum";
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
		cout << "\t" << rec->conIxBrlyVLat;
		cout << "\t" << rec->srefConIxBrlyVLat;
		cout << "\t" << rec->conNum;
		cout << endl;
	};
	return retval;
};

void QryBrlyConConMNEquipment::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCONREQPMOD_CONEQ) {
		call->abort = handleCallBrlyConReqpMod_conEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyConConMNEquipment::handleCallBrlyStubChg(
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

bool QryBrlyConConMNEquipment::handleCallBrlyConReqpMod_conEq(
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

