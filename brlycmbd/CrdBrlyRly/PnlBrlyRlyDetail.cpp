/**
  * \file PnlBrlyRlyDetail.cpp
  * job handler for job PnlBrlyRlyDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyRlyDetail.h"

#include "PnlBrlyRlyDetail_blks.cpp"
#include "PnlBrlyRlyDetail_evals.cpp"

/******************************************************************************
 class PnlBrlyRlyDetail
 ******************************************************************************/

PnlBrlyRlyDetail::PnlBrlyRlyDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYRLYDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFPupDir.tag = "FeedFPupDir";
	VecBrlyVMRelayDir::fillFeed(ixBrlyVLocale, feedFPupDir);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYRLY_CONEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFRLY, jref);
};

PnlBrlyRlyDetail::~PnlBrlyRlyDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyRlyDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupDir, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyRlyDetail::refreshRecRly(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMRelay* _recRly = NULL;

	if (dbsbrly->tblbrlymrelay->loadRecByRef(recRly.ref, &_recRly)) {
		recRly = *_recRly;
		delete _recRly;
	} else recRly = BrlyMRelay();

	dirty = false;

	contiac.TxfSta = Ftm::stamp(recRly.x1Start);
	contiac.TxfSto = Ftm::stamp(recRly.x1Stop);
	continf.TxtCon = StubBrly::getStubConStd(dbsbrly, recRly.refBrlyMConnection, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupDir = feedFPupDir.getNumByIx(recRly.ixVDir);
	contiac.ChkCtd = recRly.Connected;
	contiac.TxfNhp = to_string(recRly.Nhop);

	statshr.TxfStaActive = evalTxfStaActive(dbsbrly);
	statshr.TxfStoActive = evalTxfStoActive(dbsbrly);
	statshr.TxtConActive = evalTxtConActive(dbsbrly);
	statshr.ButConViewAvail = evalButConViewAvail(dbsbrly);
	statshr.ButConViewActive = evalButConViewActive(dbsbrly);
	statshr.PupDirActive = evalPupDirActive(dbsbrly);
	statshr.ChkCtdActive = evalChkCtdActive(dbsbrly);
	statshr.TxfNhpActive = evalTxfNhpActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlBrlyRlyDetail::refresh(
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

void PnlBrlyRlyDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFRLY) {
		recRly.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFRLY, jref);
		refreshRecRly(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyRlyDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLYDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLYDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCONVIEWCLICK) {
					handleDpchAppDoButConViewClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyRlyDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyRlyDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSTA, ContIac::TXFSTO, ContIac::NUMFPUPDIR, ContIac::CHKCTD, ContIac::TXFNHP})) {
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
		if (has(diffitems, ContIac::NUMFPUPDIR)) contiac.numFPupDir = _contiac->numFPupDir;
		if (has(diffitems, ContIac::CHKCTD)) contiac.ChkCtd = _contiac->ChkCtd;
		if (has(diffitems, ContIac::TXFNHP)) contiac.TxfNhp = _contiac->TxfNhp;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyRlyDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlyRlyDetail::handleDpchAppDoButConViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButConViewAvail && statshr.ButConViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref)) {
			sref = "CrdBrlyCon";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recRly.refBrlyMConnection, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyRlyDetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYRLY_CONEQ) {
		call->abort = handleCallBrlyRly_conEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYRLYUPD_REFEQ) {
		call->abort = handleCallBrlyRlyUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool PnlBrlyRlyDetail::handleCallBrlyRly_conEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyRly_conEq --- BEGIN
	boolvalRet = (recRly.refBrlyMConnection == refInv);
	// IP handleCallBrlyRly_conEq --- END
	return retval;
};

bool PnlBrlyRlyDetail::handleCallBrlyRlyUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyRlyUpd_refEq --- INSERT
	return retval;
};

