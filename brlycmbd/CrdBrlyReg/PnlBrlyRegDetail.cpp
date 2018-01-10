/**
  * \file PnlBrlyRegDetail.cpp
  * job handler for job PnlBrlyRegDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyRegDetail.h"

#include "PnlBrlyRegDetail_blks.cpp"
#include "PnlBrlyRegDetail_evals.cpp"

/******************************************************************************
 class PnlBrlyRegDetail
 ******************************************************************************/

PnlBrlyRegDetail::PnlBrlyRegDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYREGDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFPupDst.tag = "FeedFPupDst";
	VecBrlyVMRegionDst::fillFeed(ixBrlyVLocale, feedFPupDst);
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupJti.tag = "FeedFPupJti";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYREG_INSBS, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYREG_ISLEAF, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYREG_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFREG, jref);
};

PnlBrlyRegDetail::~PnlBrlyRegDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyRegDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupDst, &feedFPupJ, &feedFPupJti, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyRegDetail::refreshJti(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ListBrlyJMRegionTitle regJtits;
	BrlyJMRegionTitle* regJtit = NULL;

	string s;

	// feedFPupJti
	feedFPupJti.clear();

	dbsbrly->tblbrlyjmregiontitle->loadRstByReg(recReg.ref, false, regJtits);

	for (unsigned int i=0;i<regJtits.nodes.size();i++) {
		regJtit = regJtits.nodes[i];

		s = "";
		s = VecBrlyVLocale::getTitle(regJtit->x1IxBrlyVLocale, ixBrlyVLocale);
		if (s.length() == 0) s = "(" + VecBrlyVTag::getTitle(VecBrlyVTag::GENERAL, ixBrlyVLocale) + ")";
		feedFPupJti.appendRefTitles(regJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJTI);

	refreshRecRegJtit(dbsbrly, moditems);

};

void PnlBrlyRegDetail::refreshJ(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ListBrlyJMRegion regJs;
	BrlyJMRegion* regJ = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsbrly->tblbrlyjmregion->loadRstByReg(recReg.ref, false, regJs);

	for (unsigned int i=0;i<regJs.nodes.size();i++) {
		regJ = regJs.nodes[i];

		s = "";
		if (regJ->x1Startd != 0) s = Ftm::date(regJ->x1Startd) + " ";
		if ((regJ->x1Startd != 0) || (regJ->x1Stopd != 0)) s += "-";
		if (regJ->x1Stopd != 0) s += " " + Ftm::date(regJ->x1Stopd);
		if (s.length() == 0) s = "(" + VecBrlyVTag::getTitle(VecBrlyVTag::ALWAYS, ixBrlyVLocale) + ")";
		feedFPupJ.appendRefTitles(regJ->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecRegJ(dbsbrly, moditems);

};

void PnlBrlyRegDetail::refreshRecReg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMRegion* _recReg = NULL;

	if (dbsbrly->tblbrlymregion->loadRecByRef(recReg.ref, &_recReg)) {
		recReg = *_recReg;
		ixWSubsetReg = dbsbrly->getIxWSubsetByBrlyMRegion(_recReg);
		delete _recReg;
	} else {
		recReg = BrlyMRegion();
		ixWSubsetReg = 0;
	};

	dirty = false;

	recRegJtit.ref = recReg.refJTitle;
	xchg->removeClstns(VecBrlyVCall::CALLBRLYREGJTITMOD_REGEQ, jref);
	if (recReg.ref != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYREGJTITMOD_REGEQ, jref, Clstn::VecVJobmask::ALL, 0, recReg.ref, Clstn::VecVJactype::LOCK);

	recRegJ.ref = recReg.refJ;
	xchg->removeClstns(VecBrlyVCall::CALLBRLYREGJMOD_REGEQ, jref);
	if (recReg.ref != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYREGJMOD_REGEQ, jref, Clstn::VecVJobmask::ALL, 0, recReg.ref, Clstn::VecVJactype::LOCK);

	continf.TxtSrf = recReg.sref;
	continf.TxtSup = StubBrly::getStubRegStd(dbsbrly, recReg.supRefBrlyMRegion, ixBrlyVLocale, Stub::VecVNonetype::FULL);

	statshr.TxtSrfActive = evalTxtSrfActive(dbsbrly);
	statshr.TxtSupActive = evalTxtSupActive(dbsbrly);
	statshr.ButSupViewAvail = evalButSupViewAvail(dbsbrly);
	statshr.ButSupViewActive = evalButSupViewActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJti(dbsbrly, moditems);
	refreshJ(dbsbrly, moditems);

};

void PnlBrlyRegDetail::refreshRecRegJtit(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyJMRegionTitle* _recRegJtit = NULL;

	if (dbsbrly->tblbrlyjmregiontitle->loadRecByRef(recRegJtit.ref, &_recRegJtit)) {
		recRegJtit = *_recRegJtit;
		delete _recRegJtit;
	} else recRegJtit = BrlyJMRegionTitle();

	contiac.numFPupJti = feedFPupJti.getNumByRef(recRegJtit.ref);
	continf.TxtTit = recRegJtit.Title;

	statshr.PupJtiActive = evalPupJtiActive(dbsbrly);
	statshr.ButJtiEditAvail = evalButJtiEditAvail(dbsbrly);
	statshr.TxtTitActive = evalTxtTitActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlBrlyRegDetail::refreshRecRegJ(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyJMRegion* _recRegJ = NULL;

	if (dbsbrly->tblbrlyjmregion->loadRecByRef(recRegJ.ref, &_recRegJ)) {
		recRegJ = *_recRegJ;
		delete _recRegJ;
	} else recRegJ = BrlyJMRegion();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recRegJ.ref);
	contiac.numFPupDst = feedFPupDst.getNumByIx(recRegJ.ixVDst);
	continf.TxtTof = to_string(recRegJ.toffset);

	statshr.PupJActive = evalPupJActive(dbsbrly);
	statshr.ButJEditAvail = evalButJEditAvail(dbsbrly);
	statshr.PupDstActive = evalPupDstActive(dbsbrly);
	statshr.TxtTofActive = evalTxtTofActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlBrlyRegDetail::refresh(
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

void PnlBrlyRegDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFREG) {
		recReg.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFREG, jref);
		refreshRecReg(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyRegDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJTIEDITCLICK) {
					handleDpchAppDoButJtiEditClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyRegDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyRegDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPDST})) {
		if (has(diffitems, ContIac::NUMFPUPDST)) contiac.numFPupDst = _contiac->numFPupDst;
	};

	if (has(diffitems, ContIac::NUMFPUPJTI)) {
		recRegJtit.ref = feedFPupJti.getRefByNum(_contiac->numFPupJti);
		refreshRecRegJtit(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recRegJ.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecRegJ(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyRegDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlyRegDetail::handleDpchAppDoButJtiEditClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButJtiEditClick --- INSERT
};

void PnlBrlyRegDetail::handleDpchAppDoButSupViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButSupViewAvail && statshr.ButSupViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACREG, jref)) {
			sref = "CrdBrlyReg";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recReg.supRefBrlyMRegion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyRegDetail::handleDpchAppDoButJEditClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlBrlyRegDetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYREG_INSBS) {
		call->abort = handleCallBrlyReg_inSbs(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREG_ISLEAF) {
		call->abort = handleCallBrlyReg_isLeaf(dbsbrly, call->jref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREG_SUPEQ) {
		call->abort = handleCallBrlyReg_supEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREGUPD_REFEQ) {
		call->abort = handleCallBrlyRegUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREGJTITMOD_REGEQ) {
		call->abort = handleCallBrlyRegJtitMod_regEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREGJMOD_REGEQ) {
		call->abort = handleCallBrlyRegJMod_regEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool PnlBrlyRegDetail::handleCallBrlyReg_inSbs(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyReg_inSbs --- BEGIN
	boolvalRet = ((ixWSubsetReg & ixInv) != 0);
	// IP handleCallBrlyReg_inSbs --- END
	return retval;
};

bool PnlBrlyRegDetail::handleCallBrlyReg_isLeaf(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyReg_isLeaf --- BEGIN
	boolvalRet = [&](){uint cnt = 0; if (recReg.ref != 0) dbsbrly->loadUintBySQL("SELECT COUNT(ref) FROM TblBrlyMRegion WHERE supRefBrlyMRegion = " + to_string(recReg.ref), cnt); return(cnt == 0);}();
	// IP handleCallBrlyReg_isLeaf --- END
	return retval;
};

bool PnlBrlyRegDetail::handleCallBrlyReg_supEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyReg_supEq --- BEGIN
	boolvalRet = (recReg.supRefBrlyMRegion == refInv);
	// IP handleCallBrlyReg_supEq --- END
	return retval;
};

bool PnlBrlyRegDetail::handleCallBrlyRegUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyRegUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyRegDetail::handleCallBrlyRegJtitMod_regEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJti(dbsbrly, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlBrlyRegDetail::handleCallBrlyRegJMod_regEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbsbrly, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

