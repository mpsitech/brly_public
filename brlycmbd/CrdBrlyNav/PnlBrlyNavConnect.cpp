/**
  * \file PnlBrlyNavConnect.cpp
  * job handler for job PnlBrlyNavConnect (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyNavConnect.h"

#include "PnlBrlyNavConnect_blks.cpp"
#include "PnlBrlyNavConnect_evals.cpp"

/******************************************************************************
 class PnlBrlyNavConnect
 ******************************************************************************/

PnlBrlyNavConnect::PnlBrlyNavConnect(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYNAVCONNECT, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFLstCon.tag = "FeedFLstCon";
	feedFLstRly.tag = "FeedFLstRly";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshCon(dbsbrly, moditems);
	refreshRly(dbsbrly, moditems);
	refresh(dbsbrly, moditems);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYCON, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYRLY, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
};

PnlBrlyNavConnect::~PnlBrlyNavConnect() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyNavConnect::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstCon, &feedFLstRly, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyNavConnect::refreshLstCon(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstConAvail = evalLstConAvail(dbsbrly);
	statshr.ButConViewActive = evalButConViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavConnect::refreshCon(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCon = 0;

	// feedFLstCon
	feedFLstCon.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYCON, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstCon.appendRefTitles(rec->ref, StubBrly::getStubConStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCON);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCon(dbsbrly, moditems);
};

void PnlBrlyNavConnect::refreshLstRly(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstRlyAvail = evalLstRlyAvail(dbsbrly);
	statshr.ButRlyViewActive = evalButRlyViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavConnect::refreshRly(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstRly = 0;

	// feedFLstRly
	feedFLstRly.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYRLY, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstRly.appendRefTitles(rec->ref, StubBrly::getStubRlyStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTRLY);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstRly(dbsbrly, moditems);
};

void PnlBrlyNavConnect::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	// IP refresh --- INSERT
};

void PnlBrlyNavConnect::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsbrly, moditems);

	refreshLstCon(dbsbrly, moditems);
	refreshLstRly(dbsbrly, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlBrlyNavConnect::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVCONNECTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVCONNECTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCONVIEWCLICK) {
					handleDpchAppDoButConViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCONNEWCRDCLICK) {
					handleDpchAppDoButConNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRLYVIEWCLICK) {
					handleDpchAppDoButRlyViewClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyNavConnect::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyNavConnect::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTCON)) {
		contiac.numFLstCon = _contiac->numFLstCon;
		refreshLstCon(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTRLY)) {
		contiac.numFLstRly = _contiac->numFLstRly;
		refreshLstRly(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyNavConnect::handleDpchAppDoButConViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstConAvail && statshr.ButConViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstCon.getRefByNum(contiac.numFLstCon), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyCon", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyCon");
	};
};

void PnlBrlyNavConnect::handleDpchAppDoButConNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyCon", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyCon");
};

void PnlBrlyNavConnect::handleDpchAppDoButRlyViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstRlyAvail && statshr.ButRlyViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstRly.getRefByNum(contiac.numFLstRly), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyRly", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyRly");
	};
};

void PnlBrlyNavConnect::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallBrlyHusrRunvMod_crdUsrEq(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlBrlyNavConnect::handleCallBrlyHusrRunvMod_crdUsrEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecBrlyVCard::CRDBRLYCON) {
		refreshCon(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYRLY) {
		refreshRly(dbsbrly, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

