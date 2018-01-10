/**
  * \file PnlBrlyNavBase.cpp
  * job handler for job PnlBrlyNavBase (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyNavBase.h"

#include "PnlBrlyNavBase_blks.cpp"
#include "PnlBrlyNavBase_evals.cpp"

/******************************************************************************
 class PnlBrlyNavBase
 ******************************************************************************/

PnlBrlyNavBase::PnlBrlyNavBase(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYNAVBASE, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFLstFlt.tag = "FeedFLstFlt";
	feedFLstLeg.tag = "FeedFLstLeg";
	feedFLstLoc.tag = "FeedFLstLoc";
	feedFLstReg.tag = "FeedFLstReg";
	feedFLstSeg.tag = "FeedFLstSeg";
	feedFLstTtb.tag = "FeedFLstTtb";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshReg(dbsbrly, moditems);
	refreshLoc(dbsbrly, moditems);
	refreshLeg(dbsbrly, moditems);
	refreshTtb(dbsbrly, moditems);
	refreshFlt(dbsbrly, moditems);
	refreshSeg(dbsbrly, moditems);
	refresh(dbsbrly, moditems);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYREG, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYLOC, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYLEG, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYTTB, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYFLT, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYSEG, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
};

PnlBrlyNavBase::~PnlBrlyNavBase() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyNavBase::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstFlt, &feedFLstLeg, &feedFLstLoc, &feedFLstReg, &feedFLstSeg, &feedFLstTtb, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyNavBase::refreshLstReg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstRegAvail = evalLstRegAvail(dbsbrly);
	statshr.ButRegViewActive = evalButRegViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavBase::refreshReg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstReg = 0;

	// feedFLstReg
	feedFLstReg.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYREG, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstReg.appendRefTitles(rec->ref, StubBrly::getStubRegStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTREG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstReg(dbsbrly, moditems);
};

void PnlBrlyNavBase::refreshLstLoc(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstLocAvail = evalLstLocAvail(dbsbrly);
	statshr.ButLocViewActive = evalButLocViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavBase::refreshLoc(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstLoc = 0;

	// feedFLstLoc
	feedFLstLoc.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYLOC, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstLoc.appendRefTitles(rec->ref, StubBrly::getStubLocStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTLOC);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstLoc(dbsbrly, moditems);
};

void PnlBrlyNavBase::refreshLstLeg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstLegAvail = evalLstLegAvail(dbsbrly);
	statshr.ButLegViewActive = evalButLegViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavBase::refreshLeg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstLeg = 0;

	// feedFLstLeg
	feedFLstLeg.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYLEG, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstLeg.appendRefTitles(rec->ref, StubBrly::getStubLegStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTLEG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstLeg(dbsbrly, moditems);
};

void PnlBrlyNavBase::refreshLstTtb(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstTtbAvail = evalLstTtbAvail(dbsbrly);
	statshr.ButTtbViewActive = evalButTtbViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavBase::refreshTtb(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstTtb = 0;

	// feedFLstTtb
	feedFLstTtb.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYTTB, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstTtb.appendRefTitles(rec->ref, StubBrly::getStubTtbStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTTTB);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstTtb(dbsbrly, moditems);
};

void PnlBrlyNavBase::refreshLstFlt(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFltAvail = evalLstFltAvail(dbsbrly);
	statshr.ButFltViewActive = evalButFltViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavBase::refreshFlt(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFlt = 0;

	// feedFLstFlt
	feedFLstFlt.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYFLT, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstFlt.appendRefTitles(rec->ref, StubBrly::getStubFltStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFLT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFlt(dbsbrly, moditems);
};

void PnlBrlyNavBase::refreshLstSeg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSegAvail = evalLstSegAvail(dbsbrly);
	statshr.ButSegViewActive = evalButSegViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavBase::refreshSeg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSeg = 0;

	// feedFLstSeg
	feedFLstSeg.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYSEG, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstSeg.appendRefTitles(rec->ref, StubBrly::getStubSegStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSEG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSeg(dbsbrly, moditems);
};

void PnlBrlyNavBase::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	// IP refresh --- INSERT
};

void PnlBrlyNavBase::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsbrly, moditems);

	refreshLstReg(dbsbrly, moditems);
	refreshLstLoc(dbsbrly, moditems);
	refreshLstLeg(dbsbrly, moditems);
	refreshLstTtb(dbsbrly, moditems);
	refreshLstFlt(dbsbrly, moditems);
	refreshLstSeg(dbsbrly, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlBrlyNavBase::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVBASEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVBASEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGVIEWCLICK) {
					handleDpchAppDoButRegViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGNEWCRDCLICK) {
					handleDpchAppDoButRegNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLOCVIEWCLICK) {
					handleDpchAppDoButLocViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLOCNEWCRDCLICK) {
					handleDpchAppDoButLocNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLEGVIEWCLICK) {
					handleDpchAppDoButLegViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLEGNEWCRDCLICK) {
					handleDpchAppDoButLegNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTTBVIEWCLICK) {
					handleDpchAppDoButTtbViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTTBNEWCRDCLICK) {
					handleDpchAppDoButTtbNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFLTVIEWCLICK) {
					handleDpchAppDoButFltViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFLTNEWCRDCLICK) {
					handleDpchAppDoButFltNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSEGVIEWCLICK) {
					handleDpchAppDoButSegViewClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyNavBase::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyNavBase::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTREG)) {
		contiac.numFLstReg = _contiac->numFLstReg;
		refreshLstReg(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTLOC)) {
		contiac.numFLstLoc = _contiac->numFLstLoc;
		refreshLstLoc(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTLEG)) {
		contiac.numFLstLeg = _contiac->numFLstLeg;
		refreshLstLeg(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTTTB)) {
		contiac.numFLstTtb = _contiac->numFLstTtb;
		refreshLstTtb(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTFLT)) {
		contiac.numFLstFlt = _contiac->numFLstFlt;
		refreshLstFlt(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSEG)) {
		contiac.numFLstSeg = _contiac->numFLstSeg;
		refreshLstSeg(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyNavBase::handleDpchAppDoButRegViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstRegAvail && statshr.ButRegViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstReg.getRefByNum(contiac.numFLstReg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyReg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyReg");
	};
};

void PnlBrlyNavBase::handleDpchAppDoButRegNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyReg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyReg");
};

void PnlBrlyNavBase::handleDpchAppDoButLocViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstLocAvail && statshr.ButLocViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstLoc.getRefByNum(contiac.numFLstLoc), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyLoc", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyLoc");
	};
};

void PnlBrlyNavBase::handleDpchAppDoButLocNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyLoc", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyLoc");
};

void PnlBrlyNavBase::handleDpchAppDoButLegViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstLegAvail && statshr.ButLegViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstLeg.getRefByNum(contiac.numFLstLeg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyLeg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyLeg");
	};
};

void PnlBrlyNavBase::handleDpchAppDoButLegNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyLeg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyLeg");
};

void PnlBrlyNavBase::handleDpchAppDoButTtbViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstTtbAvail && statshr.ButTtbViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstTtb.getRefByNum(contiac.numFLstTtb), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyTtb", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyTtb");
	};
};

void PnlBrlyNavBase::handleDpchAppDoButTtbNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyTtb", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyTtb");
};

void PnlBrlyNavBase::handleDpchAppDoButFltViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFltAvail && statshr.ButFltViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstFlt.getRefByNum(contiac.numFLstFlt), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyFlt", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyFlt");
	};
};

void PnlBrlyNavBase::handleDpchAppDoButFltNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyFlt", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyFlt");
};

void PnlBrlyNavBase::handleDpchAppDoButSegViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSegAvail && statshr.ButSegViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstSeg.getRefByNum(contiac.numFLstSeg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlySeg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlySeg");
	};
};

void PnlBrlyNavBase::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallBrlyHusrRunvMod_crdUsrEq(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlBrlyNavBase::handleCallBrlyHusrRunvMod_crdUsrEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecBrlyVCard::CRDBRLYREG) {
		refreshReg(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYLOC) {
		refreshLoc(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYLEG) {
		refreshLeg(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYTTB) {
		refreshTtb(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYFLT) {
		refreshFlt(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYSEG) {
		refreshSeg(dbsbrly, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

