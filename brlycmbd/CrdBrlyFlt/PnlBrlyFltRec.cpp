/**
  * \file PnlBrlyFltRec.cpp
  * job handler for job PnlBrlyFltRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyFltRec.h"

#include "PnlBrlyFltRec_blks.cpp"
#include "PnlBrlyFltRec_evals.cpp"

/******************************************************************************
 class PnlBrlyFltRec
 ******************************************************************************/

PnlBrlyFltRec::PnlBrlyFltRec(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYFLTREC, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	pnlpre = NULL;
	pnldetail = NULL;
	pnlfafawaypoint = NULL;
	pnl1nconnection = NULL;
	pnlref1nsegment = NULL;
	pnleqp1nnode = NULL;
	pnlmnlocation = NULL;
	pnlmnconnection = NULL;
	pnlorgmnflight = NULL;
	pnleqpmnconnection = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFFLT, jref);
};

PnlBrlyFltRec::~PnlBrlyFltRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyFltRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyFltRec::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubBrly::getStubFltStd(dbsbrly, recFlt.ref, ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recFlt.ref == 0) statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;

	statshr.pnlfafawaypointAvail = evalPnlfafawaypointAvail(dbsbrly);
	statshr.pnleqp1nnodeAvail = evalPnleqp1nnodeAvail(dbsbrly);
	statshr.pnleqpmnconnectionAvail = evalPnleqpmnconnectionAvail(dbsbrly);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbsbrly);

	if (statshr.ixBrlyVExpstate == VecBrlyVExpstate::MIND) {
		if (pnlpre) {delete pnlpre; pnlpre = NULL;};
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlfafawaypoint) {delete pnlfafawaypoint; pnlfafawaypoint = NULL;};
		if (pnl1nconnection) {delete pnl1nconnection; pnl1nconnection = NULL;};
		if (pnlref1nsegment) {delete pnlref1nsegment; pnlref1nsegment = NULL;};
		if (pnleqp1nnode) {delete pnleqp1nnode; pnleqp1nnode = NULL;};
		if (pnlmnlocation) {delete pnlmnlocation; pnlmnlocation = NULL;};
		if (pnlmnconnection) {delete pnlmnconnection; pnlmnconnection = NULL;};
		if (pnlorgmnflight) {delete pnlorgmnflight; pnlorgmnflight = NULL;};
		if (pnleqpmnconnection) {delete pnleqpmnconnection; pnleqpmnconnection = NULL;};
	} else {
		if (!pnlpre) pnlpre = new PnlBrlyFltPre(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnldetail) pnldetail = new PnlBrlyFltDetail(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlfafawaypoint) pnlfafawaypoint = new PnlBrlyFltFafAWaypoint(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnl1nconnection) pnl1nconnection = new PnlBrlyFlt1NConnection(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlref1nsegment) pnlref1nsegment = new PnlBrlyFltRef1NSegment(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnleqp1nnode) pnleqp1nnode = new PnlBrlyFltEqp1NNode(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmnlocation) pnlmnlocation = new PnlBrlyFltMNLocation(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmnconnection) pnlmnconnection = new PnlBrlyFltMNConnection(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlorgmnflight) pnlorgmnflight = new PnlBrlyFltOrgMNFlight(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnleqpmnconnection) pnleqpmnconnection = new PnlBrlyFltEqpMNConnection(xchg, dbsbrly, jref, ixBrlyVLocale);
	};

	statshr.jrefPre = ((pnlpre) ? pnlpre->jref : 0);
	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefFafAWaypoint = ((pnlfafawaypoint) ? pnlfafawaypoint->jref : 0);
	statshr.jref1NConnection = ((pnl1nconnection) ? pnl1nconnection->jref : 0);
	statshr.jrefRef1NSegment = ((pnlref1nsegment) ? pnlref1nsegment->jref : 0);
	statshr.jrefEqp1NNode = ((pnleqp1nnode) ? pnleqp1nnode->jref : 0);
	statshr.jrefMNLocation = ((pnlmnlocation) ? pnlmnlocation->jref : 0);
	statshr.jrefMNConnection = ((pnlmnconnection) ? pnlmnconnection->jref : 0);
	statshr.jrefOrgMNFlight = ((pnlorgmnflight) ? pnlorgmnflight->jref : 0);
	statshr.jrefEqpMNConnection = ((pnleqpmnconnection) ? pnleqpmnconnection->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlBrlyFltRec::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFFLT) {
		BrlyMFlight* _recFlt = NULL;
		BrlyMFaflight* _recFaf = NULL;
		BrlyMEquipment* _recEqp = NULL;

		if (dbsbrly->tblbrlymflight->loadRecByRef(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFFLT, jref), &_recFlt)) {
			recFlt = *_recFlt;
			delete _recFlt;
		} else recFlt = BrlyMFlight();

		if (dbsbrly->tblbrlymfaflight->loadRecByRef(recFlt.refBrlyMFaflight, &_recFaf)) {
			recFaf = *_recFaf;
			delete _recFaf;
		} else recFaf = BrlyMFaflight();

		if (dbsbrly->tblbrlymequipment->loadRecByRef(recFlt.refBrlyMEquipment, &_recEqp)) {
			recEqp = *_recEqp;
			ixWSubsetEqp = dbsbrly->getIxWSubsetByBrlyMEquipment(_recEqp);
			delete _recEqp;
		} else {
			recEqp = BrlyMEquipment();
			ixWSubsetEqp = 0;
		};

		if (recFlt.ref != 0) {
			if (pnlpre) pnlpre->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnldetail) pnldetail->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlfafawaypoint) pnlfafawaypoint->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnl1nconnection) pnl1nconnection->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlref1nsegment) pnlref1nsegment->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnleqp1nnode) pnleqp1nnode->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmnlocation) pnlmnlocation->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmnconnection) pnlmnconnection->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlorgmnflight) pnlorgmnflight->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnleqpmnconnection) pnleqpmnconnection->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
		};

		refresh(dbsbrly, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyFltRec::minimize(
			DbsBrly* dbsbrly
			, const bool notif
			, DpchEngBrly** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixBrlyVExpstate != VecBrlyVExpstate::MIND) {
		statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsbrly, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlBrlyFltRec::regularize(
			DbsBrly* dbsbrly
			, const bool notif
			, DpchEngBrly** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixBrlyVExpstate != VecBrlyVExpstate::REGD) {
		statshr.ixBrlyVExpstate = VecBrlyVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsbrly, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlBrlyFltRec::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYINIT) {
			handleDpchAppBrlyInit(dbsbrly, (DpchAppBrlyInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyFltRec::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyFltRec::handleDpchAppDoButMinimizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	minimize(dbsbrly, true, dpcheng);
};

void PnlBrlyFltRec::handleDpchAppDoButRegularizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	regularize(dbsbrly, true, dpcheng);
};

void PnlBrlyFltRec::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYEQPUPD_REFEQ) {
		call->abort = handleCallBrlyEqpUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFAFUPD_REFEQ) {
		call->abort = handleCallBrlyFafUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFLTUPD_REFEQ) {
		call->abort = handleCallBrlyFltUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool PnlBrlyFltRec::handleCallBrlyEqpUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyEqpUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyFltRec::handleCallBrlyFafUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyFafUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyFltRec::handleCallBrlyFltUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyFltUpd_refEq --- INSERT
	return retval;
};

