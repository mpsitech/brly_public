/**
  * \file PnlBrlyLegDetail.cpp
  * job handler for job PnlBrlyLegDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyLegDetail.h"

#include "PnlBrlyLegDetail_blks.cpp"
#include "PnlBrlyLegDetail_evals.cpp"

/******************************************************************************
 class PnlBrlyLegDetail
 ******************************************************************************/

PnlBrlyLegDetail::PnlBrlyLegDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYLEGDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupTyp.tag = "FeedFPupTyp";
	VecBrlyVMLegBasetype::fillFeed(ixBrlyVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYLEG_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYLEG_INSBS, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYLEG_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFLEG, jref);
};

PnlBrlyLegDetail::~PnlBrlyLegDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyLegDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyLegDetail::refreshLstClu(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCluActive = evalLstCluActive(dbsbrly);
	statshr.ButCluViewActive = evalButCluViewActive(dbsbrly);
	statshr.ButCluClusterAvail = evalButCluClusterAvail(dbsbrly);
	statshr.ButCluUnclusterAvail = evalButCluUnclusterAvail(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyLegDetail::refreshClu(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	vector<ubigint> refs;

	bool first;

	// contiac
	contiac.numFLstClu = 0;

	// feedFLstClu, continf
	feedFLstClu.clear();
	continf.TxtClu = "";

	if (recLeg.refBrlyCLeg != 0) dbsbrly->tblbrlymleg->loadRefsByClu(recLeg.refBrlyCLeg, false, refs);

	first = true;
	for (unsigned int i=0;i<refs.size();i++) {
		if (refs[i] != recLeg.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubBrly::getStubLegStd(dbsbrly, refs[i], ixBrlyVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubBrly::getStubLegStd(dbsbrly, refs[i], ixBrlyVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbsbrly, moditems);
};

void PnlBrlyLegDetail::refreshRecLeg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMLeg* _recLeg = NULL;

	if (dbsbrly->tblbrlymleg->loadRecByRef(recLeg.ref, &_recLeg)) {
		recLeg = *_recLeg;
		ixWSubsetLeg = dbsbrly->getIxWSubsetByBrlyMLeg(_recLeg);
		delete _recLeg;
	} else {
		recLeg = BrlyMLeg();
		ixWSubsetLeg = 0;
	};

	dirty = false;

	xchg->removeClstns(VecBrlyVCall::CALLBRLYLEGMOD_CLUEQ, jref);
	if (recLeg.refBrlyCLeg != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYLEGMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, recLeg.refBrlyCLeg, Clstn::VecVJactype::LOCK);

	continf.TxtBlo = StubBrly::getStubLocStd(dbsbrly, recLeg.bgnRefBrlyMLocation, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	continf.TxtElo = StubBrly::getStubLocStd(dbsbrly, recLeg.endRefBrlyMLocation, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recLeg.ixVBasetype);
	contiac.TxfAlt = to_string(recLeg.alt);
	contiac.TxfDph = to_string(recLeg.deltaphi);
	contiac.TxfAph = to_string(recLeg.alpha);
	contiac.TxfXal = to_string(recLeg.xAlt);
	contiac.TxfXp0 = to_string(recLeg.xPhi0);
	contiac.TxfXp1 = to_string(recLeg.xPhi1);
	contiac.TxfXap = to_string(recLeg.xAlpha);
	contiac.ChkCdn = recLeg.Calcdone;

	statshr.TxtBloActive = evalTxtBloActive(dbsbrly);
	statshr.TxtEloActive = evalTxtEloActive(dbsbrly);
	statshr.PupTypActive = evalPupTypActive(dbsbrly);
	statshr.TxfAltActive = evalTxfAltActive(dbsbrly);
	statshr.TxfDphActive = evalTxfDphActive(dbsbrly);
	statshr.TxfAphActive = evalTxfAphActive(dbsbrly);
	statshr.TxfXalActive = evalTxfXalActive(dbsbrly);
	statshr.TxfXp0Active = evalTxfXp0Active(dbsbrly);
	statshr.TxfXp1Active = evalTxfXp1Active(dbsbrly);
	statshr.TxfXapActive = evalTxfXapActive(dbsbrly);
	statshr.ChkCdnActive = evalChkCdnActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbsbrly, moditems);

};

void PnlBrlyLegDetail::refresh(
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

void PnlBrlyLegDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFLEG) {
		recLeg.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLEG, jref);
		refreshRecLeg(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyLegDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUVIEWCLICK) {
					handleDpchAppDoButCluViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUCLUSTERCLICK) {
					handleDpchAppDoButCluClusterClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUUNCLUSTERCLICK) {
					handleDpchAppDoButCluUnclusterClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyLegDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyLegDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::TXFALT, ContIac::TXFDPH, ContIac::TXFAPH, ContIac::TXFXAL, ContIac::TXFXP0, ContIac::TXFXP1, ContIac::TXFXAP, ContIac::CHKCDN})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFALT)) contiac.TxfAlt = _contiac->TxfAlt;
		if (has(diffitems, ContIac::TXFDPH)) contiac.TxfDph = _contiac->TxfDph;
		if (has(diffitems, ContIac::TXFAPH)) contiac.TxfAph = _contiac->TxfAph;
		if (has(diffitems, ContIac::TXFXAL)) contiac.TxfXal = _contiac->TxfXal;
		if (has(diffitems, ContIac::TXFXP0)) contiac.TxfXp0 = _contiac->TxfXp0;
		if (has(diffitems, ContIac::TXFXP1)) contiac.TxfXp1 = _contiac->TxfXp1;
		if (has(diffitems, ContIac::TXFXAP)) contiac.TxfXap = _contiac->TxfXap;
		if (has(diffitems, ContIac::CHKCDN)) contiac.ChkCdn = _contiac->ChkCdn;
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyLegDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlyLegDetail::handleDpchAppDoButCluViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlBrlyLegDetail::handleDpchAppDoButCluClusterClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlBrlyLegDetail::handleDpchAppDoButCluUnclusterClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlBrlyLegDetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYLEG_CLUEQ) {
		call->abort = handleCallBrlyLeg_cluEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEG_INSBS) {
		call->abort = handleCallBrlyLeg_inSbs(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEG_TYPEQ) {
		call->abort = handleCallBrlyLeg_typEq(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEGUPD_REFEQ) {
		call->abort = handleCallBrlyLegUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEGMOD_CLUEQ) {
		call->abort = handleCallBrlyLegMod_cluEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool PnlBrlyLegDetail::handleCallBrlyLeg_cluEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyLeg_cluEq --- BEGIN
	boolvalRet = (recLeg.refBrlyCLeg == refInv);
	// IP handleCallBrlyLeg_cluEq --- END
	return retval;
};

bool PnlBrlyLegDetail::handleCallBrlyLeg_inSbs(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyLeg_inSbs --- BEGIN
	boolvalRet = ((ixWSubsetLeg & ixInv) != 0);
	// IP handleCallBrlyLeg_inSbs --- END
	return retval;
};

bool PnlBrlyLegDetail::handleCallBrlyLeg_typEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyLeg_typEq --- BEGIN
	boolvalRet = (recLeg.ixVBasetype == ixInv);
	// IP handleCallBrlyLeg_typEq --- END
	return retval;
};

bool PnlBrlyLegDetail::handleCallBrlyLegUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyLegUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyLegDetail::handleCallBrlyLegMod_cluEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbsbrly, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

