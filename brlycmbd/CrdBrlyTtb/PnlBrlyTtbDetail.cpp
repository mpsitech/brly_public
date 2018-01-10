/**
  * \file PnlBrlyTtbDetail.cpp
  * job handler for job PnlBrlyTtbDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyTtbDetail.h"

#include "PnlBrlyTtbDetail_blks.cpp"
#include "PnlBrlyTtbDetail_evals.cpp"

/******************************************************************************
 class PnlBrlyTtbDetail
 ******************************************************************************/

PnlBrlyTtbDetail::PnlBrlyTtbDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYTTBDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFPupAli.tag = "FeedFPupAli";
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKALLIANCE, ixBrlyVLocale, feedFPupAli);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYTTB_FILEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecBrlyVCall::CALLBRLYKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVKeylist::KLSTBRLYKALLIANCE, Clstn::VecVJactype::LOCK);

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFTTB, jref);
};

PnlBrlyTtbDetail::~PnlBrlyTtbDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyTtbDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupAli, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyTtbDetail::refreshPupAli(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupAli = 0;

	for (unsigned int i=0;i<feedFPupAli.size();i++) {
		if (feedFPupAli.getSrefByNum(i+1) == contiac.TxfAli) {
			contiac.numFPupAli = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfAliValid = (contiac.numFPupAli != 0);
	statshr.PupAliActive = evalPupAliActive(dbsbrly);
	statshr.ButAliEditAvail = evalButAliEditAvail(dbsbrly);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyTtbDetail::refreshTxfAli(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfAli = feedFPupAli.getSrefByNum(contiac.numFPupAli);

	// statshr
	statshr.TxfAliValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyTtbDetail::refreshAli(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	// feedFPupAli
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKALLIANCE, ixBrlyVLocale, feedFPupAli);

	insert(moditems, DpchEngData::FEEDFPUPALI);

	refreshPupAli(dbsbrly, moditems);
};

void PnlBrlyTtbDetail::refreshRecTtb(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMTimetable* _recTtb = NULL;

	if (dbsbrly->tblbrlymtimetable->loadRecByRef(recTtb.ref, &_recTtb)) {
		recTtb = *_recTtb;
		delete _recTtb;
	} else recTtb = BrlyMTimetable();

	dirty = false;

	contiac.TxfTit = recTtb.Title;
	continf.TxtFil = StubBrly::getStubFilStd(dbsbrly, recTtb.refBrlyMFile, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfAli = recTtb.srefBrlyKAlliance;
	contiac.TxfSta = Ftm::date(recTtb.startd);
	contiac.TxfSto = Ftm::date(recTtb.stopd);

	statshr.TxfTitActive = evalTxfTitActive(dbsbrly);
	statshr.TxtFilActive = evalTxtFilActive(dbsbrly);
	statshr.ButFilViewAvail = evalButFilViewAvail(dbsbrly);
	statshr.ButFilViewActive = evalButFilViewActive(dbsbrly);
	statshr.TxfStaActive = evalTxfStaActive(dbsbrly);
	statshr.TxfStoActive = evalTxfStoActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupAli(dbsbrly, moditems);

};

void PnlBrlyTtbDetail::refresh(
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

void PnlBrlyTtbDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFTTB) {
		recTtb.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFTTB, jref);
		refreshRecTtb(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyTtbDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILVIEWCLICK) {
					handleDpchAppDoButFilViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTALIEDITCLICK) {
					handleDpchAppDoButAliEditClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyTtbDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyTtbDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFSTA, ContIac::TXFSTO})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
	};

	if (has(diffitems, ContIac::TXFALI)) {
		contiac.TxfAli = _contiac->TxfAli;
		refreshPupAli(dbsbrly, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPALI)) {
		contiac.numFPupAli = _contiac->numFPupAli;
		refreshTxfAli(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyTtbDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlyTtbDetail::handleDpchAppDoButFilViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButFilViewAvail && statshr.ButFilViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFIL, jref)) {
			sref = "CrdBrlyFil";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recTtb.refBrlyMFile, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyTtbDetail::handleDpchAppDoButAliEditClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButAliEditClick --- INSERT
};

void PnlBrlyTtbDetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYTTB_FILEQ) {
		call->abort = handleCallBrlyTtb_filEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYTTBUPD_REFEQ) {
		call->abort = handleCallBrlyTtbUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallBrlyKlsAkeyMod_klsEq(dbsbrly, call->jref, call->argInv.ix);
	};
};

bool PnlBrlyTtbDetail::handleCallBrlyTtb_filEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyTtb_filEq --- BEGIN
	boolvalRet = (recTtb.refBrlyMFile == refInv);
	// IP handleCallBrlyTtb_filEq --- END
	return retval;
};

bool PnlBrlyTtbDetail::handleCallBrlyTtbUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyTtbUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyTtbDetail::handleCallBrlyKlsAkeyMod_klsEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecBrlyVKeylist::KLSTBRLYKALLIANCE) {
		refreshAli(dbsbrly, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

