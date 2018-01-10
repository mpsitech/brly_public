/**
  * \file PnlBrlySegDetail.cpp
  * job handler for job PnlBrlySegDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlySegDetail.h"

#include "PnlBrlySegDetail_blks.cpp"
#include "PnlBrlySegDetail_evals.cpp"

/******************************************************************************
 class PnlBrlySegDetail
 ******************************************************************************/

PnlBrlySegDetail::PnlBrlySegDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYSEGDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFPupRet.tag = "FeedFPupRet";
	VecBrlyVMSegmentRefTbl::fillFeed(ixBrlyVLocale, feedFPupRet);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYSEG_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSEG_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFSEG, jref);
};

PnlBrlySegDetail::~PnlBrlySegDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlySegDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupRet, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlySegDetail::refreshRecSeg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMSegment* _recSeg = NULL;

	if (dbsbrly->tblbrlymsegment->loadRecByRef(recSeg.ref, &_recSeg)) {
		recSeg = *_recSeg;
		delete _recSeg;
	} else recSeg = BrlyMSegment();

	dirty = false;

	contiac.numFPupRet = feedFPupRet.getNumByIx(recSeg.refIxVTbl);
	if (recSeg.refIxVTbl == VecBrlyVMSegmentRefTbl::CON) continf.TxtReu = StubBrly::getStubConStd(dbsbrly, recSeg.refUref, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	else if (recSeg.refIxVTbl == VecBrlyVMSegmentRefTbl::FLT) continf.TxtReu = StubBrly::getStubFltStd(dbsbrly, recSeg.refUref, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	contiac.TxfDph = to_string(recSeg.deltaphi);
	contiac.TxfAl0 = to_string(recSeg.alt0);
	contiac.TxfAl1 = to_string(recSeg.alt1);
	contiac.TxfTh0 = to_string(recSeg.theta0);
	contiac.TxfTh1 = to_string(recSeg.theta1);
	contiac.TxfPh0 = to_string(recSeg.phi0);
	contiac.TxfPh1 = to_string(recSeg.phi1);
	contiac.TxfSta = Ftm::stamp(recSeg.start);
	contiac.TxfSto = Ftm::stamp(recSeg.stop);
	contiac.ChkCdn = recSeg.Calcdone;

	statshr.TxtReuActive = evalTxtReuActive(dbsbrly);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbsbrly);
	statshr.ButReuViewActive = evalButReuViewActive(dbsbrly);
	statshr.TxfDphActive = evalTxfDphActive(dbsbrly);
	statshr.TxfAl0Active = evalTxfAl0Active(dbsbrly);
	statshr.TxfAl1Active = evalTxfAl1Active(dbsbrly);
	statshr.TxfTh0Active = evalTxfTh0Active(dbsbrly);
	statshr.TxfTh1Active = evalTxfTh1Active(dbsbrly);
	statshr.TxfPh0Active = evalTxfPh0Active(dbsbrly);
	statshr.TxfPh1Active = evalTxfPh1Active(dbsbrly);
	statshr.TxfStaActive = evalTxfStaActive(dbsbrly);
	statshr.TxfStoActive = evalTxfStoActive(dbsbrly);
	statshr.ChkCdnActive = evalChkCdnActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlBrlySegDetail::refresh(
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

void PnlBrlySegDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFSEG) {
		recSeg.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEG, jref);
		refreshRecSeg(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlySegDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlySegDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlySegDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFDPH, ContIac::TXFAL0, ContIac::TXFAL1, ContIac::TXFTH0, ContIac::TXFTH1, ContIac::TXFPH0, ContIac::TXFPH1, ContIac::TXFSTA, ContIac::TXFSTO, ContIac::CHKCDN})) {
		if (has(diffitems, ContIac::TXFDPH)) contiac.TxfDph = _contiac->TxfDph;
		if (has(diffitems, ContIac::TXFAL0)) contiac.TxfAl0 = _contiac->TxfAl0;
		if (has(diffitems, ContIac::TXFAL1)) contiac.TxfAl1 = _contiac->TxfAl1;
		if (has(diffitems, ContIac::TXFTH0)) contiac.TxfTh0 = _contiac->TxfTh0;
		if (has(diffitems, ContIac::TXFTH1)) contiac.TxfTh1 = _contiac->TxfTh1;
		if (has(diffitems, ContIac::TXFPH0)) contiac.TxfPh0 = _contiac->TxfPh0;
		if (has(diffitems, ContIac::TXFPH1)) contiac.TxfPh1 = _contiac->TxfPh1;
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
		if (has(diffitems, ContIac::CHKCDN)) contiac.ChkCdn = _contiac->ChkCdn;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlySegDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlySegDetail::handleDpchAppDoButReuViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref)) if (recSeg.refIxVTbl == VecBrlyVMSegmentRefTbl::CON) {
			sref = "CrdBrlyCon";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recSeg.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref)) if (recSeg.refIxVTbl == VecBrlyVMSegmentRefTbl::FLT) {
				sref = "CrdBrlyFlt";
				xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recSeg.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlySegDetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSEG_RETEQ) {
		call->abort = handleCallBrlySeg_retEq(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSEG_REUEQ) {
		call->abort = handleCallBrlySeg_reuEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSEGUPD_REFEQ) {
		call->abort = handleCallBrlySegUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool PnlBrlySegDetail::handleCallBrlySeg_retEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlySeg_retEq --- BEGIN
	boolvalRet = (recSeg.refIxVTbl == ixInv);
	// IP handleCallBrlySeg_retEq --- END
	return retval;
};

bool PnlBrlySegDetail::handleCallBrlySeg_reuEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlySeg_reuEq --- BEGIN
	boolvalRet = (recSeg.refUref == refInv);
	// IP handleCallBrlySeg_reuEq --- END
	return retval;
};

bool PnlBrlySegDetail::handleCallBrlySegUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlySegUpd_refEq --- INSERT
	return retval;
};

