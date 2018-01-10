/**
  * \file QryBrlyFltFafAWaypoint.cpp
  * job handler for job QryBrlyFltFafAWaypoint (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyFltFafAWaypoint.h"

#include "QryBrlyFltFafAWaypoint_blks.cpp"

/******************************************************************************
 class QryBrlyFltFafAWaypoint
 ******************************************************************************/

QryBrlyFltFafAWaypoint::QryBrlyFltFafAWaypoint(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYFLTFAFAWAYPOINT, jrefSup, ixBrlyVLocale) {

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

QryBrlyFltFafAWaypoint::~QryBrlyFltFafAWaypoint() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyFltFafAWaypoint::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyFltFafAWaypoint::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefFaf = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFFAF, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYFAFAWPTMOD_FAFEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqfltfafawaypoint->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyAMFaflightWaypoint.ref)";
	sqlstr += " FROM TblBrlyAMFaflightWaypoint";
	sqlstr += " WHERE TblBrlyAMFaflightWaypoint.fafRefBrlyMFaflight = " + to_string(preRefFaf) + "";
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQFltFafAWaypoint(jref, jnum, ref, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyAMFaflightWaypoint.ref, TblBrlyAMFaflightWaypoint.fafNum, TblBrlyAMFaflightWaypoint.timestamp, TblBrlyAMFaflightWaypoint.latitude, TblBrlyAMFaflightWaypoint.longitude, TblBrlyAMFaflightWaypoint.groundspeed, TblBrlyAMFaflightWaypoint.altitude, TblBrlyAMFaflightWaypoint.altitudeStatus, TblBrlyAMFaflightWaypoint.updateType, TblBrlyAMFaflightWaypoint.altitudeChange";
	sqlstr += " FROM TblBrlyAMFaflightWaypoint";
	sqlstr += " WHERE TblBrlyAMFaflightWaypoint.fafRefBrlyMFaflight = " + to_string(preRefFaf) + "";
	sqlstr += " ORDER BY fafNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQFltFafAWaypoint SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYFAFAWPTMOD_FAFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefFaf, Clstn::VecVJactype::LOCK);
};

void QryBrlyFltFafAWaypoint::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQFltFafAWaypoint* rec = NULL;

	dbsbrly->tblbrlyqfltfafawaypoint->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyFltFafAWaypoint", "fetch");
	};

	refreshJnum();
};

uint QryBrlyFltFafAWaypoint::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQFltFafAWaypoint* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyFltFafAWaypoint::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQFltFafAWaypoint* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQFltFafAWaypoint* QryBrlyFltFafAWaypoint::getRecByJnum(
			const uint jnum
		) {
	BrlyQFltFafAWaypoint* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyFltFafAWaypoint::handleRequest(
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

bool QryBrlyFltFafAWaypoint::handleRerun(
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

bool QryBrlyFltFafAWaypoint::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQFltFafAWaypoint* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tfafNum";
	cout << "\ttimestamp";
	cout << "\tftmTimestamp";
	cout << "\tlatitude";
	cout << "\tlongitude";
	cout << "\tgroundspeed";
	cout << "\taltitude";
	cout << "\taltitudeStatus";
	cout << "\tupdateType";
	cout << "\taltitudeChange";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->fafNum;
		cout << "\t" << rec->timestamp;
		cout << "\t" << rec->ftmTimestamp;
		cout << "\t" << rec->latitude;
		cout << "\t" << rec->longitude;
		cout << "\t" << rec->groundspeed;
		cout << "\t" << rec->altitude;
		cout << "\t" << rec->altitudeStatus;
		cout << "\t" << rec->updateType;
		cout << "\t" << rec->altitudeChange;
		cout << endl;
	};
	return retval;
};

void QryBrlyFltFafAWaypoint::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFAFAWPTMOD_FAFEQ) {
		call->abort = handleCallBrlyFafAwptMod_fafEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool QryBrlyFltFafAWaypoint::handleCallBrlyStubChg(
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

bool QryBrlyFltFafAWaypoint::handleCallBrlyFafAwptMod_fafEq(
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

