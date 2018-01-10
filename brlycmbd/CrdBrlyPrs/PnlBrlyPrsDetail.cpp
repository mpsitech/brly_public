/**
  * \file PnlBrlyPrsDetail.cpp
  * job handler for job PnlBrlyPrsDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyPrsDetail.h"

#include "PnlBrlyPrsDetail_blks.cpp"
#include "PnlBrlyPrsDetail_evals.cpp"

/******************************************************************************
 class PnlBrlyPrsDetail
 ******************************************************************************/

PnlBrlyPrsDetail::PnlBrlyPrsDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYPRSDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFLstDrv.tag = "FeedFLstDrv";
	VecBrlyWMPersonDerivate::fillFeed(ixBrlyVLocale, feedFLstDrv);
	feedFPupJln.tag = "FeedFPupJln";
	feedFPupSex.tag = "FeedFPupSex";
	VecBrlyVMPersonSex::fillFeed(ixBrlyVLocale, feedFPupSex);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFPRS, jref);
};

PnlBrlyPrsDetail::~PnlBrlyPrsDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyPrsDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstDrv, &feedFPupJln, &feedFPupSex, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyPrsDetail::refreshJln(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ListBrlyJMPersonLastname prsJlnms;
	BrlyJMPersonLastname* prsJlnm = NULL;

	string s;

	// feedFPupJln
	feedFPupJln.clear();

	dbsbrly->tblbrlyjmpersonlastname->loadRstByPrs(recPrs.ref, false, prsJlnms);

	for (unsigned int i=0;i<prsJlnms.nodes.size();i++) {
		prsJlnm = prsJlnms.nodes[i];

		s = "";
		if (prsJlnm->x1Startd != 0) {
			s = Ftm::date(prsJlnm->x1Startd) + " -";
			if ((i+2) < prsJlnms.nodes.size()) if (prsJlnms.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(prsJlnms.nodes[i+1]->x1Startd);
		} else s = "(" + VecBrlyVTag::getTitle(VecBrlyVTag::ALWAYS, ixBrlyVLocale) + ")";
		feedFPupJln.appendRefTitles(prsJlnm->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJLN);

	refreshRecPrsJlnm(dbsbrly, moditems);

};

void PnlBrlyPrsDetail::refreshTxtDrv(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i=0;i<contiac.numsFLstDrv.size();i++) ix |= feedFLstDrv.getIxByNum(contiac.numsFLstDrv[i]);
	continf.TxtDrv = VecBrlyWMPersonDerivate::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlBrlyPrsDetail::refreshRecPrs(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	BrlyMPerson* _recPrs = NULL;

	if (dbsbrly->tblbrlymperson->loadRecByRef(recPrs.ref, &_recPrs)) {
		recPrs = *_recPrs;
		delete _recPrs;
	} else recPrs = BrlyMPerson();

	dirty = false;

	recPrsJlnm.ref = recPrs.refJLastname;
	xchg->removeClstns(VecBrlyVCall::CALLBRLYPRSJLNMMOD_PRSEQ, jref);
	if (recPrs.ref != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYPRSJLNMMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, recPrs.ref, Clstn::VecVJactype::LOCK);

	contiac.TxfTit = recPrs.Title;
	contiac.TxfFnm = recPrs.Firstname;
	contiac.numsFLstDrv.clear();
	VecBrlyWMPersonDerivate::getIcs(recPrs.ixWDerivate, ics);
	for (auto it=ics.begin();it!=ics.end();it++) contiac.numsFLstDrv.push_back(feedFLstDrv.getNumByIx(*it));
	contiac.numFPupSex = feedFPupSex.getNumByIx(recPrs.ixVSex);
	contiac.TxfTel = recPrs.telVal;
	contiac.TxfEml = recPrs.emlVal;
	contiac.TxfSal = recPrs.Salutation;

	statshr.TxfTitActive = evalTxfTitActive(dbsbrly);
	statshr.TxfFnmActive = evalTxfFnmActive(dbsbrly);
	statshr.LstDrvActive = evalLstDrvActive(dbsbrly);
	statshr.PupSexActive = evalPupSexActive(dbsbrly);
	statshr.TxfTelActive = evalTxfTelActive(dbsbrly);
	statshr.TxfEmlActive = evalTxfEmlActive(dbsbrly);
	statshr.TxfSalActive = evalTxfSalActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJln(dbsbrly, moditems);
	refreshTxtDrv(dbsbrly, moditems);

};

void PnlBrlyPrsDetail::refreshRecPrsJlnm(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	BrlyJMPersonLastname* _recPrsJlnm = NULL;

	if (dbsbrly->tblbrlyjmpersonlastname->loadRecByRef(recPrsJlnm.ref, &_recPrsJlnm)) {
		recPrsJlnm = *_recPrsJlnm;
		delete _recPrsJlnm;
	} else recPrsJlnm = BrlyJMPersonLastname();

	contiac.numFPupJln = feedFPupJln.getNumByRef(recPrsJlnm.ref);
	continf.TxtLnm = recPrsJlnm.Lastname;

	statshr.PupJlnActive = evalPupJlnActive(dbsbrly);
	statshr.ButJlnEditAvail = evalButJlnEditAvail(dbsbrly);
	statshr.TxtLnmActive = evalTxtLnmActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlBrlyPrsDetail::refresh(
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

void PnlBrlyPrsDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFPRS) {
		recPrs.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFPRS, jref);
		refreshRecPrs(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyPrsDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPRSDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPRSDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJLNEDITCLICK) {
					handleDpchAppDoButJlnEditClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyPrsDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyPrsDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFFNM, ContIac::NUMFPUPSEX, ContIac::TXFTEL, ContIac::TXFEML, ContIac::TXFSAL})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::NUMFPUPSEX)) contiac.numFPupSex = _contiac->numFPupSex;
		if (has(diffitems, ContIac::TXFTEL)) contiac.TxfTel = _contiac->TxfTel;
		if (has(diffitems, ContIac::TXFEML)) contiac.TxfEml = _contiac->TxfEml;
		if (has(diffitems, ContIac::TXFSAL)) contiac.TxfSal = _contiac->TxfSal;
	};

	if (has(diffitems, ContIac::NUMFPUPJLN)) {
		recPrsJlnm.ref = feedFPupJln.getRefByNum(_contiac->numFPupJln);
		refreshRecPrsJlnm(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTDRV)) {
		contiac.numsFLstDrv = _contiac->numsFLstDrv;
		refreshTxtDrv(dbsbrly, moditems);
		refresh(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyPrsDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlyPrsDetail::handleDpchAppDoButJlnEditClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButJlnEditClick --- INSERT
};

void PnlBrlyPrsDetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYPRSUPD_REFEQ) {
		call->abort = handleCallBrlyPrsUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYPRSJLNMMOD_PRSEQ) {
		call->abort = handleCallBrlyPrsJlnmMod_prsEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool PnlBrlyPrsDetail::handleCallBrlyPrsUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyPrsUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyPrsDetail::handleCallBrlyPrsJlnmMod_prsEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJln(dbsbrly, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

