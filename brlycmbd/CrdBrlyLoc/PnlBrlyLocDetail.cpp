/**
  * \file PnlBrlyLocDetail.cpp
  * job handler for job PnlBrlyLocDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyLocDetail.h"

#include "PnlBrlyLocDetail_blks.cpp"
#include "PnlBrlyLocDetail_evals.cpp"

/******************************************************************************
 class PnlBrlyLocDetail
 ******************************************************************************/

PnlBrlyLocDetail::PnlBrlyLocDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYLOCDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFPupEqpEty.tag = "FeedFPupEqpEty";
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, ixBrlyVLocale, feedFPupEqpEty);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecBrlyVMLocationBasetype::fillFeed(ixBrlyVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYEQP_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYEQP_INSBS, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYEQP_OPREQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYEQP_PTYEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYLOC_EQPEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYLOC_INSBS, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYLOC_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecBrlyVCall::CALLBRLYKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVKeylist::KLSTBRLYKEQPTYPE, Clstn::VecVJactype::LOCK);

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFLOC, jref);
};

PnlBrlyLocDetail::~PnlBrlyLocDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyLocDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupEqpEty, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyLocDetail::refreshPupEqpEty(
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

void PnlBrlyLocDetail::refreshTxfEqpEty(
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

void PnlBrlyLocDetail::refreshEqpEty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	// feedFPupEqpEty
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, ixBrlyVLocale, feedFPupEqpEty);

	insert(moditems, DpchEngData::FEEDFPUPEQPETY);

	refreshPupEqpEty(dbsbrly, moditems);
};

void PnlBrlyLocDetail::refreshRecLoc(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMLocation* _recLoc = NULL;

	if (dbsbrly->tblbrlymlocation->loadRecByRef(recLoc.ref, &_recLoc)) {
		recLoc = *_recLoc;
		ixWSubsetLoc = dbsbrly->getIxWSubsetByBrlyMLocation(_recLoc);
		delete _recLoc;
	} else {
		recLoc = BrlyMLocation();
		ixWSubsetLoc = 0;
	};

	dirty = false;

	recEqp.ref = recLoc.refBrlyMEquipment;

	continf.TxtSrf = recLoc.sref;
	contiac.TxfIca = recLoc.srefICAO;
	contiac.TxfTit = recLoc.Title;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recLoc.ixVBasetype);
	continf.TxtReg = StubBrly::getStubRegStd(dbsbrly, recLoc.refBrlyMRegion, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfAlt = to_string(recLoc.alt);
	contiac.TxfThe = to_string(recLoc.theta);
	contiac.TxfPhi = to_string(recLoc.phi);
	contiac.TxfTz = recLoc.tz;
	contiac.TxfAph = to_string(recLoc.alpha);
	contiac.ChkCdn = recLoc.Calcdone;

	statshr.TxtSrfActive = evalTxtSrfActive(dbsbrly);
	statshr.TxfIcaActive = evalTxfIcaActive(dbsbrly);
	statshr.TxfTitActive = evalTxfTitActive(dbsbrly);
	statshr.PupTypActive = evalPupTypActive(dbsbrly);
	statshr.TxtRegActive = evalTxtRegActive(dbsbrly);
	statshr.TxfAltActive = evalTxfAltActive(dbsbrly);
	statshr.TxfTheActive = evalTxfTheActive(dbsbrly);
	statshr.TxfPhiActive = evalTxfPhiActive(dbsbrly);
	statshr.TxfTzActive = evalTxfTzActive(dbsbrly);
	statshr.TxfAphActive = evalTxfAphActive(dbsbrly);
	statshr.ChkCdnActive = evalChkCdnActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecEqp(dbsbrly, moditems);

};

void PnlBrlyLocDetail::refreshRecEqp(
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

void PnlBrlyLocDetail::refresh(
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

void PnlBrlyLocDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFLOC) {
		recLoc.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLOC, jref);
		refreshRecLoc(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyLocDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
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

void PnlBrlyLocDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyLocDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFICA, ContIac::TXFTIT, ContIac::NUMFPUPTYP, ContIac::TXFALT, ContIac::TXFTHE, ContIac::TXFPHI, ContIac::TXFTZ, ContIac::TXFAPH, ContIac::CHKCDN, ContIac::CHKEQPFIB})) {
		if (has(diffitems, ContIac::TXFICA)) contiac.TxfIca = _contiac->TxfIca;
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFALT)) contiac.TxfAlt = _contiac->TxfAlt;
		if (has(diffitems, ContIac::TXFTHE)) contiac.TxfThe = _contiac->TxfThe;
		if (has(diffitems, ContIac::TXFPHI)) contiac.TxfPhi = _contiac->TxfPhi;
		if (has(diffitems, ContIac::TXFTZ)) contiac.TxfTz = _contiac->TxfTz;
		if (has(diffitems, ContIac::TXFAPH)) contiac.TxfAph = _contiac->TxfAph;
		if (has(diffitems, ContIac::CHKCDN)) contiac.ChkCdn = _contiac->ChkCdn;
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

void PnlBrlyLocDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlyLocDetail::handleDpchAppDoButEqpNewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButEqpNewClick --- INSERT
};

void PnlBrlyLocDetail::handleDpchAppDoButEqpDeleteClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButEqpDeleteClick --- INSERT
};

void PnlBrlyLocDetail::handleDpchAppDoButEqpOprViewClick(
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

void PnlBrlyLocDetail::handleDpchAppDoButEqpPtyViewClick(
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

void PnlBrlyLocDetail::handleDpchAppDoButEqpEtyEditClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButEqpEtyEditClick --- INSERT
};

void PnlBrlyLocDetail::handleCall(
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
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOC_EQPEQ) {
		call->abort = handleCallBrlyLoc_eqpEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOC_INSBS) {
		call->abort = handleCallBrlyLoc_inSbs(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOC_TYPEQ) {
		call->abort = handleCallBrlyLoc_typEq(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYEQPUPD_REFEQ) {
		call->abort = handleCallBrlyEqpUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOCUPD_REFEQ) {
		call->abort = handleCallBrlyLocUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallBrlyKlsAkeyMod_klsEq(dbsbrly, call->jref, call->argInv.ix);
	};
};

bool PnlBrlyLocDetail::handleCallBrlyEqp_hktEq(
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

bool PnlBrlyLocDetail::handleCallBrlyEqp_inSbs(
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

bool PnlBrlyLocDetail::handleCallBrlyEqp_oprEq(
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

bool PnlBrlyLocDetail::handleCallBrlyEqp_ptyEq(
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

bool PnlBrlyLocDetail::handleCallBrlyLoc_eqpEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyLoc_eqpEq --- BEGIN
	boolvalRet = (recLoc.refBrlyMEquipment == refInv);
	// IP handleCallBrlyLoc_eqpEq --- END
	return retval;
};

bool PnlBrlyLocDetail::handleCallBrlyLoc_inSbs(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyLoc_inSbs --- BEGIN
	boolvalRet = ((ixWSubsetLoc & ixInv) != 0);
	// IP handleCallBrlyLoc_inSbs --- END
	return retval;
};

bool PnlBrlyLocDetail::handleCallBrlyLoc_typEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyLoc_typEq --- BEGIN
	boolvalRet = (recLoc.ixVBasetype == ixInv);
	// IP handleCallBrlyLoc_typEq --- END
	return retval;
};

bool PnlBrlyLocDetail::handleCallBrlyEqpUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyEqpUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyLocDetail::handleCallBrlyLocUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyLocUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyLocDetail::handleCallBrlyKlsAkeyMod_klsEq(
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

