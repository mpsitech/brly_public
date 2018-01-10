/**
  * \file PnlBrlyConDetail.cpp
  * job handler for job PnlBrlyConDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyConDetail.h"

#include "PnlBrlyConDetail_blks.cpp"
#include "PnlBrlyConDetail_evals.cpp"

/******************************************************************************
 class PnlBrlyConDetail
 ******************************************************************************/

PnlBrlyConDetail::PnlBrlyConDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYCONDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFLstEty.tag = "FeedFLstEty";
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, ixBrlyVLocale, feedFLstEty);
	feedFPupMod.tag = "FeedFPupMod";
	VecBrlyVMConnectionModel::fillFeed(ixBrlyVLocale, feedFPupMod);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYCON_FLTEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYCON_TTBEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecBrlyVCall::CALLBRLYKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVKeylist::KLSTBRLYKEQPTYPE, Clstn::VecVJactype::LOCK);

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFCON, jref);
};

PnlBrlyConDetail::~PnlBrlyConDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyConDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstEty, &feedFPupMod, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyConDetail::refreshLstEty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	set<uint> nums;

	vector<string> ss;
	string s;

	// contiac
	contiac.numsFLstEty.clear();

	StrMod::stringToVector(contiac.TxfEty, ss);

	for (unsigned int i=0;i<ss.size();i++) {
		s = ss[i];

		for (unsigned int j=0;j<feedFLstEty.size();j++) {
			if (feedFLstEty.getSrefByNum(j+1) == s) {
				nums.insert(j+1);
				break;
			};
		};
	};

	for (auto it=nums.begin();it!=nums.end();it++) contiac.numsFLstEty.push_back(*it);

	// statshr
	statshr.TxfEtyValid = ( (ss.size() == nums.size()) && (nums.size() == contiac.numsFLstEty.size()) );
	statshr.LstEtyActive = evalLstEtyActive(dbsbrly);
	statshr.ButEtyEditAvail = evalButEtyEditAvail(dbsbrly);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyConDetail::refreshTxfEty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfEty = "";

	for (unsigned int i=0;i<contiac.numsFLstEty.size();i++) {
		if (i != 0) contiac.TxfEty += ";";
		contiac.TxfEty += feedFLstEty.getSrefByNum(contiac.numsFLstEty[i]);
	};

	// statshr
	statshr.TxfEtyValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyConDetail::refreshEty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	// feedFLstEty
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, ixBrlyVLocale, feedFLstEty);

	insert(moditems, DpchEngData::FEEDFLSTETY);

	refreshLstEty(dbsbrly, moditems);
};

void PnlBrlyConDetail::refreshRecCon(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMConnection* _recCon = NULL;

	if (dbsbrly->tblbrlymconnection->loadRecByRef(recCon.ref, &_recCon)) {
		recCon = *_recCon;
		delete _recCon;
	} else recCon = BrlyMConnection();

	dirty = false;

	continf.TxtFlt = StubBrly::getStubFltStd(dbsbrly, recCon.refBrlyMFlight, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	continf.TxtCor = StubBrly::getStubLegStd(dbsbrly, recCon.corRefBrlyMLeg, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfSta = Ftm::stamp(recCon.start);
	contiac.TxfSto = Ftm::stamp(recCon.stop);
	contiac.numFPupMod = feedFPupMod.getNumByIx(recCon.ixVModel);
	continf.TxtTtb = StubBrly::getStubTtbStd(dbsbrly, recCon.refBrlyMTimetable, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfEty = recCon.srefsBrlyKEqptype;

	statshr.TxtFltActive = evalTxtFltActive(dbsbrly);
	statshr.ButFltViewAvail = evalButFltViewAvail(dbsbrly);
	statshr.ButFltViewActive = evalButFltViewActive(dbsbrly);
	statshr.TxtCorActive = evalTxtCorActive(dbsbrly);
	statshr.TxfStaActive = evalTxfStaActive(dbsbrly);
	statshr.TxfStoActive = evalTxfStoActive(dbsbrly);
	statshr.PupModActive = evalPupModActive(dbsbrly);
	statshr.TxtTtbActive = evalTxtTtbActive(dbsbrly);
	statshr.ButTtbViewAvail = evalButTtbViewAvail(dbsbrly);
	statshr.ButTtbViewActive = evalButTtbViewActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshLstEty(dbsbrly, moditems);

};

void PnlBrlyConDetail::refresh(
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

void PnlBrlyConDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFCON) {
		recCon.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);
		refreshRecCon(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyConDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFLTVIEWCLICK) {
					handleDpchAppDoButFltViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTTBVIEWCLICK) {
					handleDpchAppDoButTtbViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTETYEDITCLICK) {
					handleDpchAppDoButEtyEditClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyConDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyConDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSTA, ContIac::TXFSTO, ContIac::NUMFPUPMOD})) {
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
		if (has(diffitems, ContIac::NUMFPUPMOD)) contiac.numFPupMod = _contiac->numFPupMod;
	};

	if (has(diffitems, ContIac::TXFETY)) {
		contiac.TxfEty = _contiac->TxfEty;
		refreshLstEty(dbsbrly, moditems);
	} else if (has(diffitems, ContIac::NUMSFLSTETY)) {
		contiac.numsFLstEty = _contiac->numsFLstEty;
		refreshTxfEty(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyConDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlyConDetail::handleDpchAppDoButFltViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButFltViewAvail && statshr.ButFltViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref)) {
			sref = "CrdBrlyFlt";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recCon.refBrlyMFlight, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyConDetail::handleDpchAppDoButTtbViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButTtbViewAvail && statshr.ButTtbViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref)) {
			sref = "CrdBrlyTtb";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recCon.refBrlyMTimetable, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyConDetail::handleDpchAppDoButEtyEditClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButEtyEditClick --- INSERT
};

void PnlBrlyConDetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYCON_FLTEQ) {
		call->abort = handleCallBrlyCon_fltEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCON_TTBEQ) {
		call->abort = handleCallBrlyCon_ttbEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCONUPD_REFEQ) {
		call->abort = handleCallBrlyConUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallBrlyKlsAkeyMod_klsEq(dbsbrly, call->jref, call->argInv.ix);
	};
};

bool PnlBrlyConDetail::handleCallBrlyCon_fltEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyCon_fltEq --- BEGIN
	boolvalRet = (recCon.refBrlyMFlight == refInv);
	// IP handleCallBrlyCon_fltEq --- END
	return retval;
};

bool PnlBrlyConDetail::handleCallBrlyCon_ttbEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyCon_ttbEq --- BEGIN
	boolvalRet = (recCon.refBrlyMTimetable == refInv);
	// IP handleCallBrlyCon_ttbEq --- END
	return retval;
};

bool PnlBrlyConDetail::handleCallBrlyConUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyConUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyConDetail::handleCallBrlyKlsAkeyMod_klsEq(
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

