/**
  * \file PnlBrlyLocRec.cpp
  * job handler for job PnlBrlyLocRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyLocRec.h"

#include "PnlBrlyLocRec_blks.cpp"
#include "PnlBrlyLocRec_evals.cpp"

/******************************************************************************
 class PnlBrlyLocRec
 ******************************************************************************/

PnlBrlyLocRec::PnlBrlyLocRec(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYLOCREC, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	pnldetail = NULL;
	pnlmap = NULL;
	pnlbgn1nleg = NULL;
	pnlend1nleg = NULL;
	pnleqp1nnode = NULL;
	pnlmnsegment = NULL;
	pnlproxorgmnlocation = NULL;
	pnlvisorgmnlocation = NULL;
	pnlmnleg = NULL;
	pnlmnflight = NULL;
	pnleqpmnconnection = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFLOC, jref);
};

PnlBrlyLocRec::~PnlBrlyLocRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyLocRec::getNewDpchEng(
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

void PnlBrlyLocRec::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubBrly::getStubLocStd(dbsbrly, recLoc.ref, ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recLoc.ref == 0) statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;

	statshr.pnlbgn1nlegAvail = evalPnlbgn1nlegAvail(dbsbrly);
	statshr.pnlend1nlegAvail = evalPnlend1nlegAvail(dbsbrly);
	statshr.pnleqp1nnodeAvail = evalPnleqp1nnodeAvail(dbsbrly);
	statshr.pnleqpmnconnectionAvail = evalPnleqpmnconnectionAvail(dbsbrly);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbsbrly);

	if (statshr.ixBrlyVExpstate == VecBrlyVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlmap) {delete pnlmap; pnlmap = NULL;};
		if (pnlbgn1nleg) {delete pnlbgn1nleg; pnlbgn1nleg = NULL;};
		if (pnlend1nleg) {delete pnlend1nleg; pnlend1nleg = NULL;};
		if (pnleqp1nnode) {delete pnleqp1nnode; pnleqp1nnode = NULL;};
		if (pnlmnsegment) {delete pnlmnsegment; pnlmnsegment = NULL;};
		if (pnlproxorgmnlocation) {delete pnlproxorgmnlocation; pnlproxorgmnlocation = NULL;};
		if (pnlvisorgmnlocation) {delete pnlvisorgmnlocation; pnlvisorgmnlocation = NULL;};
		if (pnlmnleg) {delete pnlmnleg; pnlmnleg = NULL;};
		if (pnlmnflight) {delete pnlmnflight; pnlmnflight = NULL;};
		if (pnleqpmnconnection) {delete pnleqpmnconnection; pnleqpmnconnection = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlBrlyLocDetail(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmap) pnlmap = new PnlBrlyLocMap(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlbgn1nleg) pnlbgn1nleg = new PnlBrlyLocBgn1NLeg(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlend1nleg) pnlend1nleg = new PnlBrlyLocEnd1NLeg(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnleqp1nnode) pnleqp1nnode = new PnlBrlyLocEqp1NNode(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmnsegment) pnlmnsegment = new PnlBrlyLocMNSegment(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlproxorgmnlocation) pnlproxorgmnlocation = new PnlBrlyLocProxOrgMNLocation(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlvisorgmnlocation) pnlvisorgmnlocation = new PnlBrlyLocVisOrgMNLocation(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmnleg) pnlmnleg = new PnlBrlyLocMNLeg(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmnflight) pnlmnflight = new PnlBrlyLocMNFlight(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnleqpmnconnection) pnleqpmnconnection = new PnlBrlyLocEqpMNConnection(xchg, dbsbrly, jref, ixBrlyVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefMap = ((pnlmap) ? pnlmap->jref : 0);
	statshr.jrefBgn1NLeg = ((pnlbgn1nleg) ? pnlbgn1nleg->jref : 0);
	statshr.jrefEnd1NLeg = ((pnlend1nleg) ? pnlend1nleg->jref : 0);
	statshr.jrefEqp1NNode = ((pnleqp1nnode) ? pnleqp1nnode->jref : 0);
	statshr.jrefMNSegment = ((pnlmnsegment) ? pnlmnsegment->jref : 0);
	statshr.jrefProxOrgMNLocation = ((pnlproxorgmnlocation) ? pnlproxorgmnlocation->jref : 0);
	statshr.jrefVisOrgMNLocation = ((pnlvisorgmnlocation) ? pnlvisorgmnlocation->jref : 0);
	statshr.jrefMNLeg = ((pnlmnleg) ? pnlmnleg->jref : 0);
	statshr.jrefMNFlight = ((pnlmnflight) ? pnlmnflight->jref : 0);
	statshr.jrefEqpMNConnection = ((pnleqpmnconnection) ? pnleqpmnconnection->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlBrlyLocRec::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFLOC) {
		BrlyMLocation* _recLoc = NULL;
		BrlyMEquipment* _recEqp = NULL;

		if (dbsbrly->tblbrlymlocation->loadRecByRef(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLOC, jref), &_recLoc)) {
			recLoc = *_recLoc;
			ixWSubsetLoc = dbsbrly->getIxWSubsetByBrlyMLocation(_recLoc);
			delete _recLoc;
		} else {
			recLoc = BrlyMLocation();
			ixWSubsetLoc = 0;
		};

		if (dbsbrly->tblbrlymequipment->loadRecByRef(recLoc.refBrlyMEquipment, &_recEqp)) {
			recEqp = *_recEqp;
			ixWSubsetEqp = dbsbrly->getIxWSubsetByBrlyMEquipment(_recEqp);
			delete _recEqp;
		} else {
			recEqp = BrlyMEquipment();
			ixWSubsetEqp = 0;
		};

		if (recLoc.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmap) pnlmap->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlbgn1nleg) pnlbgn1nleg->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlend1nleg) pnlend1nleg->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnleqp1nnode) pnleqp1nnode->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmnsegment) pnlmnsegment->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlproxorgmnlocation) pnlproxorgmnlocation->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlvisorgmnlocation) pnlvisorgmnlocation->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmnleg) pnlmnleg->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmnflight) pnlmnflight->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnleqpmnconnection) pnleqpmnconnection->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
		};

		refresh(dbsbrly, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyLocRec::minimize(
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

void PnlBrlyLocRec::regularize(
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

void PnlBrlyLocRec::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCRECDO) {
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

void PnlBrlyLocRec::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyLocRec::handleDpchAppDoButMinimizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	minimize(dbsbrly, true, dpcheng);
};

void PnlBrlyLocRec::handleDpchAppDoButRegularizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	regularize(dbsbrly, true, dpcheng);
};

void PnlBrlyLocRec::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYEQPUPD_REFEQ) {
		call->abort = handleCallBrlyEqpUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOCUPD_REFEQ) {
		call->abort = handleCallBrlyLocUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool PnlBrlyLocRec::handleCallBrlyEqpUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyEqpUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyLocRec::handleCallBrlyLocUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyLocUpd_refEq --- INSERT
	return retval;
};

