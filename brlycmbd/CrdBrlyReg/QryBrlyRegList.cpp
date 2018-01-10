/**
  * \file QryBrlyRegList.cpp
  * job handler for job QryBrlyRegList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyRegList.h"

#include "QryBrlyRegList_blks.cpp"

/******************************************************************************
 class QryBrlyRegList
 ******************************************************************************/

QryBrlyRegList::QryBrlyRegList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYREGLIST, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecBrlyVCall::CALLBRLYREGMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyRegList::~QryBrlyRegList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyRegList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryBrlyRegList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecBrlyVPreset::PREBRLYREGLIST_SRF, jref);
	string preTit = xchg->getTxtvalPreset(VecBrlyVPreset::PREBRLYREGLIST_TIT, jref);
	ubigint preSup = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREGLIST_SUP, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqreglist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMRegion.ref)";
	sqlstr += " FROM TblBrlyMRegion";
	rerun_filtSQL(sqlstr, preSrf, preTit, preSup, true);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQRegList(jref, jnum, ref, sref, Title, supRefBrlyMRegion, ixVDst, toffset)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMRegion.ref, TblBrlyMRegion.sref, TblBrlyMRegion.Title, TblBrlyMRegion.supRefBrlyMRegion, TblBrlyMRegion.ixVDst, TblBrlyMRegion.toffset";
	sqlstr += " FROM TblBrlyMRegion";
	rerun_filtSQL(sqlstr, preSrf, preTit, preSup, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQRegList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyRegList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const string& preTit
			, const ubigint preSup
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMRegion.sref = '" + preSrf + "'";
	};

	if (preTit.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMRegion.Title LIKE '" + preTit + "'";
	};

	if (preSup != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMRegion.supRefBrlyMRegion = " + to_string(preSup) + "";
	};
};

void QryBrlyRegList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyRegList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblBrlyMRegion.sref ASC";
	else if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblBrlyMRegion.Title ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblBrlyMRegion.supRefBrlyMRegion ASC";
};

void QryBrlyRegList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQRegList* rec = NULL;

	BrlyJMRegionTitle* regJtit = NULL;
	ListBrlyJMRegion regJs;
	BrlyJMRegion* regJ = NULL;

	uint preIxLcl = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXLCL, jref);
	int preSysdate = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYSYSDATE, jref);

	dbsbrly->tblbrlyqreglist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			if (dbsbrly->tblbrlyjmregiontitle->loadRecByRegLcl(rec->ref, preIxLcl, &regJtit)) {
				rec->Title = regJtit->Title;
				delete regJtit;
			};
			dbsbrly->tblbrlyjmregion->loadRstByReg(rec->ref, false, regJs);
			for (unsigned int j=0;j<regJs.nodes.size();j++) {
				regJ = regJs.nodes[j];
				if ((preSysdate >= regJ->x1Startd) && (preSysdate <= regJ->x1Stopd)) {
					rec->ixVDst = regJ->ixVDst;
					rec->toffset = regJ->toffset;
					break;
				};
			};
			rec->jnum = statshr.jnumFirstload + i;
			rec->stubSupRefBrlyMRegion = StubBrly::getStubRegHsref(dbsbrly, rec->supRefBrlyMRegion, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVDst = VecBrlyVMRegionDst::getSref(rec->ixVDst);
			rec->titIxVDst = VecBrlyVMRegionDst::getTitle(rec->ixVDst, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyRegList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyRegList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQRegList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyRegList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQRegList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQRegList* QryBrlyRegList::getRecByJnum(
			const uint jnum
		) {
	BrlyQRegList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyRegList::handleRequest(
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

bool QryBrlyRegList::handleRerun(
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

bool QryBrlyRegList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQRegList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\tsupRefBrlyMRegion";
	cout << "\tstubSupRefBrlyMRegion";
	cout << "\tixVDst";
	cout << "\tsrefIxVDst";
	cout << "\ttitIxVDst";
	cout << "\ttoffset";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->supRefBrlyMRegion;
		cout << "\t" << rec->stubSupRefBrlyMRegion;
		cout << "\t" << rec->ixVDst;
		cout << "\t" << rec->srefIxVDst;
		cout << "\t" << rec->titIxVDst;
		cout << "\t" << rec->toffset;
		cout << endl;
	};
	return retval;
};

void QryBrlyRegList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREGMOD) {
		call->abort = handleCallBrlyRegMod(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREGUPD_REFEQ) {
		call->abort = handleCallBrlyRegUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyRegList::handleCallBrlyStubChg(
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

bool QryBrlyRegList::handleCallBrlyRegMod(
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

bool QryBrlyRegList::handleCallBrlyRegUpd_refEq(
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

