/**
  * \file QryBrlyConMapLocation.cpp
  * job handler for job QryBrlyConMapLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyConMapLocation.h"

#include "QryBrlyConMapLocation_blks.cpp"

/******************************************************************************
 class QryBrlyConMapLocation
 ******************************************************************************/

QryBrlyConMapLocation::QryBrlyConMapLocation(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYCONMAPLOCATION, jrefSup, ixBrlyVLocale) {

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

QryBrlyConMapLocation::~QryBrlyConMapLocation() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyConMapLocation::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyConMapLocation::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	ubigint preRefCon = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqconmaplocation->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblBrlyQConMapLocation(qwr, jref, jnum, ref, legphi, legtheta, mref, mrefBrlyMEquipment)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblBrlyRMLegMLocation.ref, TblBrlyRMLegMLocation.legphi, TblBrlyRMLegMLocation.legtheta, TblBrlyMLocation.ref, TblBrlyMLocation.refBrlyMEquipment";
	sqlstr += " FROM TblBrlyRMLegMLocation, TblBrlyMConnection, TblBrlyMLocation";
	sqlstr += " WHERE TblBrlyMConnection.ref = " + to_string(preRefCon) + "";
	sqlstr += " AND TblBrlyRMLegMLocation.refBrlyMLeg = TblBrlyMConnection.corRefBrlyMLeg";
	sqlstr += " AND TblBrlyMLocation.ref = TblBrlyRMLegMLocation.refBrlyMLocation";
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQConMapLocation SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyConMapLocation::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQConMapLocation* rec = NULL;

	dbsbrly->tblbrlyqconmaplocation->loadRstByJref(jref, false, rst);

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = i+1;
			rec->stubMref = StubBrly::getStubLocStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyConMapLocation", "fetch");
	};

	refreshJnum();
};

uint QryBrlyConMapLocation::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQConMapLocation* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyConMapLocation::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQConMapLocation* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQConMapLocation* QryBrlyConMapLocation::getRecByJnum(
			const uint jnum
		) {
	BrlyQConMapLocation* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyConMapLocation::handleRequest(
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

bool QryBrlyConMapLocation::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	rerun(dbsbrly);
	return retval;
};

bool QryBrlyConMapLocation::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQConMapLocation* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tlegphi";
	cout << "\tlegtheta";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tmrefBrlyMEquipment";
	cout << "\tx";
	cout << "\ty";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->qwr;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->legphi;
		cout << "\t" << rec->legtheta;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->mrefBrlyMEquipment;
		cout << "\t" << rec->x;
		cout << "\t" << rec->y;
		cout << endl;
	};
	return retval;
};

void QryBrlyConMapLocation::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	};
};

bool QryBrlyConMapLocation::handleCallBrlyStubChg(
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

