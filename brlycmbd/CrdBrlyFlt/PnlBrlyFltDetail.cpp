/**
  * \file PnlBrlyFltDetail.cpp
  * job handler for job PnlBrlyFltDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyFltDetail.h"

#include "PnlBrlyFltDetail_blks.cpp"
#include "PnlBrlyFltDetail_evals.cpp"

/******************************************************************************
 class PnlBrlyFltDetail
 ******************************************************************************/

PnlBrlyFltDetail::PnlBrlyFltDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYFLTDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFPupEqpEty.tag = "FeedFPupEqpEty";
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, ixBrlyVLocale, feedFPupEqpEty);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYEQP_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYEQP_INSBS, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYEQP_OPREQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYEQP_PTYEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYFLT_EQPEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYFLT_FAFEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYFLT_TTBEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecBrlyVCall::CALLBRLYKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVKeylist::KLSTBRLYKEQPTYPE, Clstn::VecVJactype::LOCK);

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFFLT, jref);
};

PnlBrlyFltDetail::~PnlBrlyFltDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyFltDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupEqpEty, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyFltDetail::refreshPupEqpEty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupEqpEty = 0;

	for (unsigned int i=0;i<feedFPupEqpEty.size();i++) {
		if (feedFPupEqpEty.getSrefByNum(i+1) == contiac.TxfEqpEty) {
			contiac.numFPupEqpEty = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfEqpEtyValid = (contiac.numFPupEqpEty != 0);
	statshr.PupEqpEtyAvail = evalPupEqpEtyAvail(dbsbrly);
	statshr.PupEqpEtyActive = evalPupEqpEtyActive(dbsbrly);
	statshr.ButEqpEtyEditAvail = evalButEqpEtyEditAvail(dbsbrly);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyFltDetail::refreshTxfEqpEty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfEqpEty = feedFPupEqpEty.getSrefByNum(contiac.numFPupEqpEty);

	// statshr
	statshr.TxfEqpEtyValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyFltDetail::refreshEqpEty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	// feedFPupEqpEty
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, ixBrlyVLocale, feedFPupEqpEty);

	insert(moditems, DpchEngData::FEEDFPUPEQPETY);

	refreshPupEqpEty(dbsbrly, moditems);
};

void PnlBrlyFltDetail::refreshRecFlt(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMFlight* _recFlt = NULL;

	if (dbsbrly->tblbrlymflight->loadRecByRef(recFlt.ref, &_recFlt)) {
		recFlt = *_recFlt;
		delete _recFlt;
	} else recFlt = BrlyMFlight();

	dirty = false;

	recFaf.ref = recFlt.refBrlyMFaflight;

	recEqp.ref = recFlt.refBrlyMEquipment;

	continf.TxtSrf = recFlt.sref;
	continf.TxtTtb = StubBrly::getStubTtbStd(dbsbrly, recFlt.refBrlyMTimetable, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	continf.TxtLeg = StubBrly::getStubLegStd(dbsbrly, recFlt.refBrlyMLeg, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfSta = Ftm::stamp(recFlt.start);
	contiac.TxfSto = Ftm::stamp(recFlt.stop);
	contiac.TxfXsa = Ftm::stamp(recFlt.xStart);
	contiac.TxfXso = Ftm::stamp(recFlt.xStop);
	contiac.ChkCdn = recFlt.Calcdone;
	contiac.ChkSdn = recFlt.Segdone;

	statshr.TxtSrfActive = evalTxtSrfActive(dbsbrly);
	statshr.TxtTtbActive = evalTxtTtbActive(dbsbrly);
	statshr.ButTtbViewAvail = evalButTtbViewAvail(dbsbrly);
	statshr.ButTtbViewActive = evalButTtbViewActive(dbsbrly);
	statshr.TxtLegActive = evalTxtLegActive(dbsbrly);
	statshr.TxfStaActive = evalTxfStaActive(dbsbrly);
	statshr.TxfStoActive = evalTxfStoActive(dbsbrly);
	statshr.TxfXsaActive = evalTxfXsaActive(dbsbrly);
	statshr.TxfXsoActive = evalTxfXsoActive(dbsbrly);
	statshr.ChkCdnActive = evalChkCdnActive(dbsbrly);
	statshr.ChkSdnActive = evalChkSdnActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecFaf(dbsbrly, moditems);
	refreshRecEqp(dbsbrly, moditems);

};

void PnlBrlyFltDetail::refreshRecFaf(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMFaflight* _recFaf = NULL;

	if (dbsbrly->tblbrlymfaflight->loadRecByRef(recFaf.ref, &_recFaf)) {
		recFaf = *_recFaf;
		delete _recFaf;
	} else recFaf = BrlyMFaflight();

	contiac.TxfFafFid = recFaf.faFlightID;
	contiac.TxfFafIdt = recFaf.ident;
	contiac.TxfFafAct = recFaf.aircrafttype;
	contiac.TxfFafFet = recFaf.filed_ete;
	contiac.TxfFafFti = Ftm::stamp(recFaf.filed_time);
	contiac.TxfFafFdt = Ftm::stamp(recFaf.filed_departuretime);
	contiac.TxfFafFsk = to_string(recFaf.filed_airspeed_kts);
	contiac.TxfFafFsm = to_string(recFaf.filed_airspeed_mach);
	contiac.TxfFafFat = to_string(recFaf.filed_altitude);
	contiac.TxfFafRte = recFaf.route;
	contiac.TxfFafAdt = Ftm::stamp(recFaf.actualdeparturetime);
	contiac.TxfFafEat = Ftm::stamp(recFaf.estimatedarrivaltime);
	contiac.TxfFafAat = Ftm::stamp(recFaf.actualarrivaltime);
	contiac.TxfFafDvt = recFaf.diverted;
	contiac.TxfFafOrg = recFaf.origin;
	contiac.TxfFafDst = recFaf.destination;
	contiac.TxfFafOnm = recFaf.originName;
	contiac.TxfFafOct = recFaf.originCity;
	contiac.TxfFafDnm = recFaf.destinationName;
	contiac.TxfFafDct = recFaf.destinationCity;

	statshr.ButFafNewAvail = evalButFafNewAvail(dbsbrly);
	statshr.ButFafDeleteAvail = evalButFafDeleteAvail(dbsbrly);
	statshr.TxfFafFidAvail = evalTxfFafFidAvail(dbsbrly);
	statshr.TxfFafFidActive = evalTxfFafFidActive(dbsbrly);
	statshr.TxfFafIdtAvail = evalTxfFafIdtAvail(dbsbrly);
	statshr.TxfFafIdtActive = evalTxfFafIdtActive(dbsbrly);
	statshr.TxfFafActAvail = evalTxfFafActAvail(dbsbrly);
	statshr.TxfFafActActive = evalTxfFafActActive(dbsbrly);
	statshr.TxfFafFetAvail = evalTxfFafFetAvail(dbsbrly);
	statshr.TxfFafFetActive = evalTxfFafFetActive(dbsbrly);
	statshr.TxfFafFtiAvail = evalTxfFafFtiAvail(dbsbrly);
	statshr.TxfFafFtiActive = evalTxfFafFtiActive(dbsbrly);
	statshr.TxfFafFdtAvail = evalTxfFafFdtAvail(dbsbrly);
	statshr.TxfFafFdtActive = evalTxfFafFdtActive(dbsbrly);
	statshr.TxfFafFskAvail = evalTxfFafFskAvail(dbsbrly);
	statshr.TxfFafFskActive = evalTxfFafFskActive(dbsbrly);
	statshr.TxfFafFsmAvail = evalTxfFafFsmAvail(dbsbrly);
	statshr.TxfFafFsmActive = evalTxfFafFsmActive(dbsbrly);
	statshr.TxfFafFatAvail = evalTxfFafFatAvail(dbsbrly);
	statshr.TxfFafFatActive = evalTxfFafFatActive(dbsbrly);
	statshr.TxfFafRteAvail = evalTxfFafRteAvail(dbsbrly);
	statshr.TxfFafRteActive = evalTxfFafRteActive(dbsbrly);
	statshr.TxfFafAdtAvail = evalTxfFafAdtAvail(dbsbrly);
	statshr.TxfFafAdtActive = evalTxfFafAdtActive(dbsbrly);
	statshr.TxfFafEatAvail = evalTxfFafEatAvail(dbsbrly);
	statshr.TxfFafEatActive = evalTxfFafEatActive(dbsbrly);
	statshr.TxfFafAatAvail = evalTxfFafAatAvail(dbsbrly);
	statshr.TxfFafAatActive = evalTxfFafAatActive(dbsbrly);
	statshr.TxfFafDvtAvail = evalTxfFafDvtAvail(dbsbrly);
	statshr.TxfFafDvtActive = evalTxfFafDvtActive(dbsbrly);
	statshr.TxfFafOrgAvail = evalTxfFafOrgAvail(dbsbrly);
	statshr.TxfFafOrgActive = evalTxfFafOrgActive(dbsbrly);
	statshr.TxfFafDstAvail = evalTxfFafDstAvail(dbsbrly);
	statshr.TxfFafDstActive = evalTxfFafDstActive(dbsbrly);
	statshr.TxfFafOnmAvail = evalTxfFafOnmAvail(dbsbrly);
	statshr.TxfFafOnmActive = evalTxfFafOnmActive(dbsbrly);
	statshr.TxfFafOctAvail = evalTxfFafOctAvail(dbsbrly);
	statshr.TxfFafOctActive = evalTxfFafOctActive(dbsbrly);
	statshr.TxfFafDnmAvail = evalTxfFafDnmAvail(dbsbrly);
	statshr.TxfFafDnmActive = evalTxfFafDnmActive(dbsbrly);
	statshr.TxfFafDctAvail = evalTxfFafDctAvail(dbsbrly);
	statshr.TxfFafDctActive = evalTxfFafDctActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlBrlyFltDetail::refreshRecEqp(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMEquipment* _recEqp = NULL;

	if (dbsbrly->tblbrlymequipment->loadRecByRef(recEqp.ref, &_recEqp)) {
		recEqp = *_recEqp;
		ixWSubsetEqp = dbsbrly->getIxWSubsetByBrlyMEquipment(_recEqp);
		delete _recEqp;
	} else {
		recEqp = BrlyMEquipment();
		ixWSubsetEqp = 0;
	};

	continf.TxtEqpOpr = StubBrly::getStubOprStd(dbsbrly, recEqp.refBrlyMOperator, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	continf.TxtEqpPty = StubBrly::getStubPtyStd(dbsbrly, recEqp.refBrlyMPlntype, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfEqpEty = recEqp.srefBrlyKEqptype;
	contiac.ChkEqpFib = recEqp.Fiber;

	statshr.ButEqpNewAvail = evalButEqpNewAvail(dbsbrly);
	statshr.ButEqpDeleteAvail = evalButEqpDeleteAvail(dbsbrly);
	statshr.TxtEqpOprAvail = evalTxtEqpOprAvail(dbsbrly);
	statshr.TxtEqpOprActive = evalTxtEqpOprActive(dbsbrly);
	statshr.ButEqpOprViewAvail = evalButEqpOprViewAvail(dbsbrly);
	statshr.ButEqpOprViewActive = evalButEqpOprViewActive(dbsbrly);
	statshr.TxtEqpPtyAvail = evalTxtEqpPtyAvail(dbsbrly);
	statshr.TxtEqpPtyActive = evalTxtEqpPtyActive(dbsbrly);
	statshr.ButEqpPtyViewAvail = evalButEqpPtyViewAvail(dbsbrly);
	statshr.ButEqpPtyViewActive = evalButEqpPtyViewActive(dbsbrly);
	statshr.ChkEqpFibAvail = evalChkEqpFibAvail(dbsbrly);
	statshr.ChkEqpFibActive = evalChkEqpFibActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupEqpEty(dbsbrly, moditems);

};

void PnlBrlyFltDetail::refresh(
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

void PnlBrlyFltDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFFLT) {
		recFlt.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFFLT, jref);
		refreshRecFlt(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyFltDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTTBVIEWCLICK) {
					handleDpchAppDoButTtbViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFAFNEWCLICK) {
					handleDpchAppDoButFafNewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFAFDELETECLICK) {
					handleDpchAppDoButFafDeleteClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTEQPNEWCLICK) {
					handleDpchAppDoButEqpNewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTEQPDELETECLICK) {
					handleDpchAppDoButEqpDeleteClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTEQPOPRVIEWCLICK) {
					handleDpchAppDoButEqpOprViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTEQPPTYVIEWCLICK) {
					handleDpchAppDoButEqpPtyViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTEQPETYEDITCLICK) {
					handleDpchAppDoButEqpEtyEditClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyFltDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyFltDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSTA, ContIac::TXFSTO, ContIac::TXFXSA, ContIac::TXFXSO, ContIac::CHKCDN, ContIac::CHKSDN, ContIac::TXFFAFFID, ContIac::TXFFAFIDT, ContIac::TXFFAFACT, ContIac::TXFFAFFET, ContIac::TXFFAFFTI, ContIac::TXFFAFFDT, ContIac::TXFFAFFSK, ContIac::TXFFAFFSM, ContIac::TXFFAFFAT, ContIac::TXFFAFRTE, ContIac::TXFFAFADT, ContIac::TXFFAFEAT, ContIac::TXFFAFAAT, ContIac::TXFFAFDVT, ContIac::TXFFAFORG, ContIac::TXFFAFDST, ContIac::TXFFAFONM, ContIac::TXFFAFOCT, ContIac::TXFFAFDNM, ContIac::TXFFAFDCT, ContIac::CHKEQPFIB})) {
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
		if (has(diffitems, ContIac::TXFXSA)) contiac.TxfXsa = _contiac->TxfXsa;
		if (has(diffitems, ContIac::TXFXSO)) contiac.TxfXso = _contiac->TxfXso;
		if (has(diffitems, ContIac::CHKCDN)) contiac.ChkCdn = _contiac->ChkCdn;
		if (has(diffitems, ContIac::CHKSDN)) contiac.ChkSdn = _contiac->ChkSdn;
		if (has(diffitems, ContIac::TXFFAFFID)) contiac.TxfFafFid = _contiac->TxfFafFid;
		if (has(diffitems, ContIac::TXFFAFIDT)) contiac.TxfFafIdt = _contiac->TxfFafIdt;
		if (has(diffitems, ContIac::TXFFAFACT)) contiac.TxfFafAct = _contiac->TxfFafAct;
		if (has(diffitems, ContIac::TXFFAFFET)) contiac.TxfFafFet = _contiac->TxfFafFet;
		if (has(diffitems, ContIac::TXFFAFFTI)) contiac.TxfFafFti = _contiac->TxfFafFti;
		if (has(diffitems, ContIac::TXFFAFFDT)) contiac.TxfFafFdt = _contiac->TxfFafFdt;
		if (has(diffitems, ContIac::TXFFAFFSK)) contiac.TxfFafFsk = _contiac->TxfFafFsk;
		if (has(diffitems, ContIac::TXFFAFFSM)) contiac.TxfFafFsm = _contiac->TxfFafFsm;
		if (has(diffitems, ContIac::TXFFAFFAT)) contiac.TxfFafFat = _contiac->TxfFafFat;
		if (has(diffitems, ContIac::TXFFAFRTE)) contiac.TxfFafRte = _contiac->TxfFafRte;
		if (has(diffitems, ContIac::TXFFAFADT)) contiac.TxfFafAdt = _contiac->TxfFafAdt;
		if (has(diffitems, ContIac::TXFFAFEAT)) contiac.TxfFafEat = _contiac->TxfFafEat;
		if (has(diffitems, ContIac::TXFFAFAAT)) contiac.TxfFafAat = _contiac->TxfFafAat;
		if (has(diffitems, ContIac::TXFFAFDVT)) contiac.TxfFafDvt = _contiac->TxfFafDvt;
		if (has(diffitems, ContIac::TXFFAFORG)) contiac.TxfFafOrg = _contiac->TxfFafOrg;
		if (has(diffitems, ContIac::TXFFAFDST)) contiac.TxfFafDst = _contiac->TxfFafDst;
		if (has(diffitems, ContIac::TXFFAFONM)) contiac.TxfFafOnm = _contiac->TxfFafOnm;
		if (has(diffitems, ContIac::TXFFAFOCT)) contiac.TxfFafOct = _contiac->TxfFafOct;
		if (has(diffitems, ContIac::TXFFAFDNM)) contiac.TxfFafDnm = _contiac->TxfFafDnm;
		if (has(diffitems, ContIac::TXFFAFDCT)) contiac.TxfFafDct = _contiac->TxfFafDct;
		if (has(diffitems, ContIac::CHKEQPFIB)) contiac.ChkEqpFib = _contiac->ChkEqpFib;
	};

	if (has(diffitems, ContIac::TXFEQPETY)) {
		contiac.TxfEqpEty = _contiac->TxfEqpEty;
		refreshPupEqpEty(dbsbrly, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPEQPETY)) {
		contiac.numFPupEqpEty = _contiac->numFPupEqpEty;
		refreshTxfEqpEty(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyFltDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlyFltDetail::handleDpchAppDoButTtbViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButTtbViewAvail && statshr.ButTtbViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref)) {
			sref = "CrdBrlyTtb";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recFlt.refBrlyMTimetable, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyFltDetail::handleDpchAppDoButFafNewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButFafNewClick --- INSERT
};

void PnlBrlyFltDetail::handleDpchAppDoButFafDeleteClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButFafDeleteClick --- INSERT
};

void PnlBrlyFltDetail::handleDpchAppDoButEqpNewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButEqpNewClick --- INSERT
};

void PnlBrlyFltDetail::handleDpchAppDoButEqpDeleteClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButEqpDeleteClick --- INSERT
};

void PnlBrlyFltDetail::handleDpchAppDoButEqpOprViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButEqpOprViewAvail && statshr.ButEqpOprViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACOPR, jref)) {
			sref = "CrdBrlyOpr";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recEqp.refBrlyMOperator, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyFltDetail::handleDpchAppDoButEqpPtyViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButEqpPtyViewAvail && statshr.ButEqpPtyViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPTY, jref)) {
			sref = "CrdBrlyPty";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recEqp.refBrlyMPlntype, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyFltDetail::handleDpchAppDoButEqpEtyEditClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButEqpEtyEditClick --- INSERT
};

void PnlBrlyFltDetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYEQP_HKTEQ) {
		call->abort = handleCallBrlyEqp_hktEq(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYEQP_INSBS) {
		call->abort = handleCallBrlyEqp_inSbs(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYEQP_OPREQ) {
		call->abort = handleCallBrlyEqp_oprEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYEQP_PTYEQ) {
		call->abort = handleCallBrlyEqp_ptyEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFLT_EQPEQ) {
		call->abort = handleCallBrlyFlt_eqpEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFLT_FAFEQ) {
		call->abort = handleCallBrlyFlt_fafEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFLT_TTBEQ) {
		call->abort = handleCallBrlyFlt_ttbEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYEQPUPD_REFEQ) {
		call->abort = handleCallBrlyEqpUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFAFUPD_REFEQ) {
		call->abort = handleCallBrlyFafUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFLTUPD_REFEQ) {
		call->abort = handleCallBrlyFltUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallBrlyKlsAkeyMod_klsEq(dbsbrly, call->jref, call->argInv.ix);
	};
};

bool PnlBrlyFltDetail::handleCallBrlyEqp_hktEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyEqp_hktEq --- BEGIN
	boolvalRet = (recEqp.hkIxVTbl == ixInv);
	// IP handleCallBrlyEqp_hktEq --- END
	return retval;
};

bool PnlBrlyFltDetail::handleCallBrlyEqp_inSbs(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyEqp_inSbs --- BEGIN
	boolvalRet = ((ixWSubsetEqp & ixInv) != 0);
	// IP handleCallBrlyEqp_inSbs --- END
	return retval;
};

bool PnlBrlyFltDetail::handleCallBrlyEqp_oprEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyEqp_oprEq --- BEGIN
	boolvalRet = (recEqp.refBrlyMOperator == refInv);
	// IP handleCallBrlyEqp_oprEq --- END
	return retval;
};

bool PnlBrlyFltDetail::handleCallBrlyEqp_ptyEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyEqp_ptyEq --- BEGIN
	boolvalRet = (recEqp.refBrlyMPlntype == refInv);
	// IP handleCallBrlyEqp_ptyEq --- END
	return retval;
};

bool PnlBrlyFltDetail::handleCallBrlyFlt_eqpEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyFlt_eqpEq --- BEGIN
	boolvalRet = (recFlt.refBrlyMEquipment == refInv);
	// IP handleCallBrlyFlt_eqpEq --- END
	return retval;
};

bool PnlBrlyFltDetail::handleCallBrlyFlt_fafEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyFlt_fafEq --- BEGIN
	boolvalRet = (recFlt.refBrlyMFaflight == refInv);
	// IP handleCallBrlyFlt_fafEq --- END
	return retval;
};

bool PnlBrlyFltDetail::handleCallBrlyFlt_ttbEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyFlt_ttbEq --- BEGIN
	boolvalRet = (recFlt.refBrlyMTimetable == refInv);
	// IP handleCallBrlyFlt_ttbEq --- END
	return retval;
};

bool PnlBrlyFltDetail::handleCallBrlyEqpUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyEqpUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyFltDetail::handleCallBrlyFafUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyFafUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyFltDetail::handleCallBrlyFltUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyFltUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyFltDetail::handleCallBrlyKlsAkeyMod_klsEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecBrlyVKeylist::KLSTBRLYKEQPTYPE) {
		refreshEqpEty(dbsbrly, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

