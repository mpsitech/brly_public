/**
  * \file PnlBrlyUsrDetail.cpp
  * job handler for job PnlBrlyUsrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyUsrDetail.h"

#include "PnlBrlyUsrDetail_blks.cpp"
#include "PnlBrlyUsrDetail_evals.cpp"

/******************************************************************************
 class PnlBrlyUsrDetail
 ******************************************************************************/

PnlBrlyUsrDetail::PnlBrlyUsrDetail(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYUSRDETAIL, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFPupJst.tag = "FeedFPupJst";
	feedFPupLcl.tag = "FeedFPupLcl";
	VecBrlyVLocale::fillFeed(ixBrlyVLocale, feedFPupLcl);
	feedFPupSte.tag = "FeedFPupSte";
	VecBrlyVMUserState::fillFeed(ixBrlyVLocale, feedFPupSte);
	feedFPupUlv.tag = "FeedFPupUlv";
	VecBrlyVUserlevel::fillFeed(ixBrlyVLocale, feedFPupUlv);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYUSR_PRSEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYUSR_USGEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFUSR, jref);
};

PnlBrlyUsrDetail::~PnlBrlyUsrDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyUsrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJst, &feedFPupLcl, &feedFPupSte, &feedFPupUlv, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyUsrDetail::refreshJst(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ListBrlyJMUserState usrJstes;
	BrlyJMUserState* usrJste = NULL;

	string s;

	// feedFPupJst
	feedFPupJst.clear();

	dbsbrly->tblbrlyjmuserstate->loadRstByUsr(recUsr.ref, false, usrJstes);

	for (unsigned int i=0;i<usrJstes.nodes.size();i++) {
		usrJste = usrJstes.nodes[i];

		s = "";
		if (usrJste->x1Startd != 0) {
			s = Ftm::date(usrJste->x1Startd) + " -";
			if ((i+2) < usrJstes.nodes.size()) if (usrJstes.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(usrJstes.nodes[i+1]->x1Startd);
		} else s = "(" + VecBrlyVTag::getTitle(VecBrlyVTag::ALWAYS, ixBrlyVLocale) + ")";
		feedFPupJst.appendRefTitles(usrJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJST);

	refreshRecUsrJste(dbsbrly, moditems);

};

void PnlBrlyUsrDetail::refreshRecUsr(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyMUser* _recUsr = NULL;

	if (dbsbrly->tblbrlymuser->loadRecByRef(recUsr.ref, &_recUsr)) {
		recUsr = *_recUsr;
		delete _recUsr;
	} else recUsr = BrlyMUser();

	dirty = false;

	recUsrJste.ref = recUsr.refJState;
	xchg->removeClstns(VecBrlyVCall::CALLBRLYUSRJSTEMOD_USREQ, jref);
	if (recUsr.ref != 0) xchg->addRefClstn(VecBrlyVCall::CALLBRLYUSRJSTEMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, recUsr.ref, Clstn::VecVJactype::LOCK);

	continf.TxtPrs = StubBrly::getStubPrsStd(dbsbrly, recUsr.refBrlyMPerson, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSrf = recUsr.sref;
	continf.TxtUsg = StubBrly::getStubUsgStd(dbsbrly, recUsr.refBrlyMUsergroup, ixBrlyVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupLcl = feedFPupLcl.getNumByIx(recUsr.ixBrlyVLocale);
	contiac.numFPupUlv = feedFPupUlv.getNumByIx(recUsr.ixBrlyVUserlevel);
	contiac.TxfPwd = recUsr.Password;

	statshr.TxtPrsActive = evalTxtPrsActive(dbsbrly);
	statshr.ButPrsViewAvail = evalButPrsViewAvail(dbsbrly);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbsbrly);
	statshr.TxtSrfActive = evalTxtSrfActive(dbsbrly);
	statshr.TxtUsgActive = evalTxtUsgActive(dbsbrly);
	statshr.ButUsgViewAvail = evalButUsgViewAvail(dbsbrly);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbsbrly);
	statshr.PupLclActive = evalPupLclActive(dbsbrly);
	statshr.PupUlvActive = evalPupUlvActive(dbsbrly);
	statshr.TxfPwdActive = evalTxfPwdActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJst(dbsbrly, moditems);

};

void PnlBrlyUsrDetail::refreshRecUsrJste(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	BrlyJMUserState* _recUsrJste = NULL;

	if (dbsbrly->tblbrlyjmuserstate->loadRecByRef(recUsrJste.ref, &_recUsrJste)) {
		recUsrJste = *_recUsrJste;
		delete _recUsrJste;
	} else recUsrJste = BrlyJMUserState();

	contiac.numFPupJst = feedFPupJst.getNumByRef(recUsrJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recUsrJste.ixVState);

	statshr.PupJstActive = evalPupJstActive(dbsbrly);
	statshr.ButJstEditAvail = evalButJstEditAvail(dbsbrly);
	statshr.PupSteActive = evalPupSteActive(dbsbrly);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlBrlyUsrDetail::refresh(
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

void PnlBrlyUsrDetail::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFUSR) {
		recUsr.ref = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFUSR, jref);
		refreshRecUsr(dbsbrly, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyUsrDetail::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJSTEDITCLICK) {
					handleDpchAppDoButJstEditClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyUsrDetail::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyUsrDetail::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPSTE, ContIac::NUMFPUPLCL, ContIac::NUMFPUPULV, ContIac::TXFPWD})) {
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::NUMFPUPLCL)) contiac.numFPupLcl = _contiac->numFPupLcl;
		if (has(diffitems, ContIac::NUMFPUPULV)) contiac.numFPupUlv = _contiac->numFPupUlv;
		if (has(diffitems, ContIac::TXFPWD)) contiac.TxfPwd = _contiac->TxfPwd;
	};

	if (has(diffitems, ContIac::NUMFPUPJST)) {
		recUsrJste.ref = feedFPupJst.getRefByNum(_contiac->numFPupJst);
		refreshRecUsrJste(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyUsrDetail::handleDpchAppDoButSaveClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlBrlyUsrDetail::handleDpchAppDoButPrsViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrsViewAvail && statshr.ButPrsViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref)) {
			sref = "CrdBrlyPrs";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recUsr.refBrlyMPerson, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyUsrDetail::handleDpchAppDoButUsgViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButUsgViewAvail && statshr.ButUsgViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACUSG, jref)) {
			sref = "CrdBrlyUsg";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recUsr.refBrlyMUsergroup, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyUsrDetail::handleDpchAppDoButJstEditClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButJstEditClick --- INSERT
};

void PnlBrlyUsrDetail::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYUSR_PRSEQ) {
		call->abort = handleCallBrlyUsr_prsEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSR_USGEQ) {
		call->abort = handleCallBrlyUsr_usgEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSRUPD_REFEQ) {
		call->abort = handleCallBrlyUsrUpd_refEq(dbsbrly, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSRJSTEMOD_USREQ) {
		call->abort = handleCallBrlyUsrJsteMod_usrEq(dbsbrly, call->jref, call->argInv.ref);
	};
};

bool PnlBrlyUsrDetail::handleCallBrlyUsr_prsEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyUsr_prsEq --- BEGIN
	boolvalRet = (recUsr.refBrlyMPerson == refInv);
	// IP handleCallBrlyUsr_prsEq --- END
	return retval;
};

bool PnlBrlyUsrDetail::handleCallBrlyUsr_usgEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallBrlyUsr_usgEq --- BEGIN
	boolvalRet = (recUsr.refBrlyMUsergroup == refInv);
	// IP handleCallBrlyUsr_usgEq --- END
	return retval;
};

bool PnlBrlyUsrDetail::handleCallBrlyUsrUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallBrlyUsrUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyUsrDetail::handleCallBrlyUsrJsteMod_usrEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJst(dbsbrly, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

