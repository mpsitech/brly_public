/**
  * \file PnlBrlyPtyDetail.cpp
  * job handler for job PnlBrlyPtyDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyPtyDetail.h"

#include "PnlBrlyPtyDetail_blks.cpp"
#include "PnlBrlyPtyDetail_evals.cpp"

/******************************************************************************
 class PnlBrlyPtyDetail
 ******************************************************************************/

PnlBrlyPtyDetail::PnlBrlyPtyDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYPTYDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFPupEty.tag = "FeedFPupEty";
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, ixBrlyVLocale, feedFPupEty);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecBrlyVCall::CALLBRLYKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVKeylist::KLSTBRLYKEQPTYPE, Clstn::VecVJactype::LOCK);

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFPTY, jref);
};

PnlBrlyPtyDetail::~PnlBrlyPtyDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyPtyDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupEty, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyPtyDetail::refreshPupEty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupEty = 0;

	for (unsigned int i=0;i<feedFPupEty.size();i++) {
		if (feedFPupEty.getSrefByNum(i+1) == contiac.TxfEty) {
			contiac.numFPupEty = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfEtyValid = (contiac.numFPupEty != 0);
	statshr.PupEtyActive = evalPupEtyActive(dbsbrly);
	statshr.ButEtyEditAvail = evalButEtyEditAvail(dbsbrly);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyPtyDetail::refreshTxfEty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfEty = feedFPupEty.getSrefByNum(contiac.numFPupEty);

	// statshr
	statshr.TxfEtyValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyPtyDetail::refreshEty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	// feedFPupEty
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, ixBrlyVLocale, feedFPupEty);

	insert(moditems, DpchEngData::FEEDFPUPETY);

	refreshPupEty(dbsbrly, moditems);
};

void PnlBrlyPtyDetail::refreshRecPty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMPlntype* _recPty = NULL;

	if (dbsbrly->tblbrlymplntype->loadRecByRef(recPty.ref, &_recPty)) {
		recPty = *_recPty;
		delete _recPty;
	} else recPty = BrlyMPlntype();

	dirty = false;

	continf.TxtSrf = recPty.sref;
	contiac.TxfTit = recPty.Title;
	contiac.TxfEty = recPty.srefBrlyKEqptype;
	contiac.TxfCap = to_string(recPty.Capacity);

	statshr.TxtSrfActive = evalTxtSrfActive(dbsbrly);
	statshr.TxfTitActive = evalTxfTitActive(dbsbrly);
	statshr.TxfCapActive = evalTxfCapActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupEty(dbsbrly, moditems);

};

void PnlBrlyPtyDetail::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbsbrly);
	statshr.ButSaveActive = evalButSaveActive(dbsbrly);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyPtyDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFPTY) {
		recPty.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFPTY, jref);
		refreshRecPty(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyPtyDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTYDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTYDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTETYEDITCLICK) {
					handleDpchAppDoButEtyEditClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyPtyDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyPtyDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFCAP})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFCAP)) contiac.TxfCap = _contiac->TxfCap;
	};

	if (has(diffitems, ContIac::TXFETY)) {
		contiac.TxfEty = _contiac->TxfEty;
		refreshPupEty(dbsbrly, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPETY)) {
		contiac.numFPupEty = _contiac->numFPupEty;
		refreshTxfEty(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyPtyDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlyPtyDetail::handleDpchAppDoButEtyEditClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButEtyEditClick --- INSERT
};

void PnlBrlyPtyDetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYPTYUPD_REFEQ) {
		call->abort = handleCallBrlyPtyUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallBrlyKlsAkeyMod_klsEq(dbsbrly, call->jref, call->argInv.ix);
	};
};

bool PnlBrlyPtyDetail::handleCallBrlyPtyUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyPtyUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyPtyDetail::handleCallBrlyKlsAkeyMod_klsEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecBrlyVKeylist::KLSTBRLYKEQPTYPE) {
		refreshEty(dbsbrly, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

