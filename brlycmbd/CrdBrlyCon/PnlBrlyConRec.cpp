/**
  * \file PnlBrlyConRec.cpp
  * job handler for job PnlBrlyConRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyConRec.h"

#include "PnlBrlyConRec_blks.cpp"
#include "PnlBrlyConRec_evals.cpp"

/******************************************************************************
 class PnlBrlyConRec
 ******************************************************************************/

PnlBrlyConRec::PnlBrlyConRec(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYCONREC, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	pnlpre = NULL;
	pnldetail = NULL;
	pnlmap = NULL;
	pnl1nrelay = NULL;
	pnlref1nsegment = NULL;
	pnlmnsegment = NULL;
	pnlmnflight = NULL;
	pnlconmnequipment = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFCON, jref);
};

PnlBrlyConRec::~PnlBrlyConRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyConRec::getNewDpchEng(
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

void PnlBrlyConRec::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubBrly::getStubConStd(dbsbrly, recCon.ref, ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recCon.ref == 0) statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsbrly);

	if (statshr.ixBrlyVExpstate == VecBrlyVExpstate::MIND) {
		if (pnlpre) {delete pnlpre; pnlpre = NULL;};
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlmap) {delete pnlmap; pnlmap = NULL;};
		if (pnl1nrelay) {delete pnl1nrelay; pnl1nrelay = NULL;};
		if (pnlref1nsegment) {delete pnlref1nsegment; pnlref1nsegment = NULL;};
		if (pnlmnsegment) {delete pnlmnsegment; pnlmnsegment = NULL;};
		if (pnlmnflight) {delete pnlmnflight; pnlmnflight = NULL;};
		if (pnlconmnequipment) {delete pnlconmnequipment; pnlconmnequipment = NULL;};
	} else {
		if (!pnlpre) pnlpre = new PnlBrlyConPre(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnldetail) pnldetail = new PnlBrlyConDetail(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmap) pnlmap = new PnlBrlyConMap(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnl1nrelay) pnl1nrelay = new PnlBrlyCon1NRelay(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlref1nsegment) pnlref1nsegment = new PnlBrlyConRef1NSegment(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmnsegment) pnlmnsegment = new PnlBrlyConMNSegment(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmnflight) pnlmnflight = new PnlBrlyConMNFlight(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlconmnequipment) pnlconmnequipment = new PnlBrlyConConMNEquipment(xchg, dbsbrly, jref, ixBrlyVLocale);
	};

	statshr.jrefPre = ((pnlpre) ? pnlpre->jref : 0);
	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefMap = ((pnlmap) ? pnlmap->jref : 0);
	statshr.jref1NRelay = ((pnl1nrelay) ? pnl1nrelay->jref : 0);
	statshr.jrefRef1NSegment = ((pnlref1nsegment) ? pnlref1nsegment->jref : 0);
	statshr.jrefMNSegment = ((pnlmnsegment) ? pnlmnsegment->jref : 0);
	statshr.jrefMNFlight = ((pnlmnflight) ? pnlmnflight->jref : 0);
	statshr.jrefConMNEquipment = ((pnlconmnequipment) ? pnlconmnequipment->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlBrlyConRec::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFCON) {
		BrlyMConnection* _recCon = NULL;

		if (dbsbrly->tblbrlymconnection->loadRecByRef(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref), &_recCon)) {
			recCon = *_recCon;
			delete _recCon;
		} else recCon = BrlyMConnection();

		if (recCon.ref != 0) {
			if (pnlpre) pnlpre->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnldetail) pnldetail->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmap) pnlmap->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnl1nrelay) pnl1nrelay->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlref1nsegment) pnlref1nsegment->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmnsegment) pnlmnsegment->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmnflight) pnlmnflight->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlconmnequipment) pnlconmnequipment->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
		};

		refresh(dbsbrly, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyConRec::minimize(
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

void PnlBrlyConRec::regularize(
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

void PnlBrlyConRec::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONRECDO) {
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

void PnlBrlyConRec::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyConRec::handleDpchAppDoButMinimizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	minimize(dbsbrly, true, dpcheng);
};

void PnlBrlyConRec::handleDpchAppDoButRegularizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	regularize(dbsbrly, true, dpcheng);
};

void PnlBrlyConRec::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYCONUPD_REFEQ) {
		call->abort = handleCallBrlyConUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool PnlBrlyConRec::handleCallBrlyConUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyConUpd_refEq --- INSERT
	return retval;
};

