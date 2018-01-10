/**
  * \file PnlBrlyNavAdmin.cpp
  * job handler for job PnlBrlyNavAdmin (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyNavAdmin.h"

#include "PnlBrlyNavAdmin_blks.cpp"
#include "PnlBrlyNavAdmin_evals.cpp"

/******************************************************************************
 class PnlBrlyNavAdmin
 ******************************************************************************/

PnlBrlyNavAdmin::PnlBrlyNavAdmin(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYNAVADMIN, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFLstFil.tag = "FeedFLstFil";
	feedFLstOpr.tag = "FeedFLstOpr";
	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstPty.tag = "FeedFLstPty";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshUsg(dbsbrly, moditems);
	refreshUsr(dbsbrly, moditems);
	refreshPrs(dbsbrly, moditems);
	refreshFil(dbsbrly, moditems);
	refreshOpr(dbsbrly, moditems);
	refreshPty(dbsbrly, moditems);
	refresh(dbsbrly, moditems);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYUSG, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYUSR, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYPRS, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYFIL, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYOPR, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecBrlyVCard::CRDBRLYPTY, xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), Clstn::VecVJactype::LOCK);
};

PnlBrlyNavAdmin::~PnlBrlyNavAdmin() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyNavAdmin::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstFil, &feedFLstOpr, &feedFLstPrs, &feedFLstPty, &feedFLstUsg, &feedFLstUsr, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyNavAdmin::refreshLstUsg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsgAvail = evalLstUsgAvail(dbsbrly);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavAdmin::refreshUsg(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsg = 0;

	// feedFLstUsg
	feedFLstUsg.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYUSG, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstUsg.appendRefTitles(rec->ref, StubBrly::getStubUsgStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsg(dbsbrly, moditems);
};

void PnlBrlyNavAdmin::refreshLstUsr(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsrAvail = evalLstUsrAvail(dbsbrly);
	statshr.ButUsrViewActive = evalButUsrViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavAdmin::refreshUsr(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsr = 0;

	// feedFLstUsr
	feedFLstUsr.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYUSR, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstUsr.appendRefTitles(rec->ref, StubBrly::getStubUsrStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsr(dbsbrly, moditems);
};

void PnlBrlyNavAdmin::refreshLstPrs(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrsAvail = evalLstPrsAvail(dbsbrly);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavAdmin::refreshPrs(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrs = 0;

	// feedFLstPrs
	feedFLstPrs.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYPRS, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstPrs.appendRefTitles(rec->ref, StubBrly::getStubPrsStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrs(dbsbrly, moditems);
};

void PnlBrlyNavAdmin::refreshLstFil(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFilAvail = evalLstFilAvail(dbsbrly);
	statshr.ButFilViewActive = evalButFilViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavAdmin::refreshFil(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFil = 0;

	// feedFLstFil
	feedFLstFil.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYFIL, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstFil.appendRefTitles(rec->ref, StubBrly::getStubFilStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFIL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFil(dbsbrly, moditems);
};

void PnlBrlyNavAdmin::refreshLstOpr(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstOprAvail = evalLstOprAvail(dbsbrly);
	statshr.ButOprViewActive = evalButOprViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavAdmin::refreshOpr(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstOpr = 0;

	// feedFLstOpr
	feedFLstOpr.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYOPR, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstOpr.appendRefTitles(rec->ref, StubBrly::getStubOprStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTOPR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstOpr(dbsbrly, moditems);
};

void PnlBrlyNavAdmin::refreshLstPty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPtyAvail = evalLstPtyAvail(dbsbrly);
	statshr.ButPtyViewActive = evalButPtyViewActive(dbsbrly);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyNavAdmin::refreshPty(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListBrlyHistRMUserUniversal rst;
	BrlyHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPty = 0;

	// feedFLstPty
	feedFLstPty.clear();

	dbsbrly->tblbrlyhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWN, jref), VecBrlyVCard::CRDBRLYPTY, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstPty.appendRefTitles(rec->ref, StubBrly::getStubPtyStd(dbsbrly, rec->unvUref, ixBrlyVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPTY);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPty(dbsbrly, moditems);
};

void PnlBrlyNavAdmin::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	// IP refresh --- INSERT
};

void PnlBrlyNavAdmin::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsbrly, moditems);

	refreshLstUsg(dbsbrly, moditems);
	refreshLstUsr(dbsbrly, moditems);
	refreshLstPrs(dbsbrly, moditems);
	refreshLstFil(dbsbrly, moditems);
	refreshLstOpr(dbsbrly, moditems);
	refreshLstPty(dbsbrly, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlBrlyNavAdmin::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVADMINDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVADMINDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGNEWCRDCLICK) {
					handleDpchAppDoButUsgNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRVIEWCLICK) {
					handleDpchAppDoButUsrViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRNEWCRDCLICK) {
					handleDpchAppDoButUsrNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSNEWCRDCLICK) {
					handleDpchAppDoButPrsNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILVIEWCLICK) {
					handleDpchAppDoButFilViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILNEWCRDCLICK) {
					handleDpchAppDoButFilNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPRVIEWCLICK) {
					handleDpchAppDoButOprViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPRNEWCRDCLICK) {
					handleDpchAppDoButOprNewcrdClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPTYVIEWCLICK) {
					handleDpchAppDoButPtyViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPTYNEWCRDCLICK) {
					handleDpchAppDoButPtyNewcrdClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyNavAdmin::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyNavAdmin::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTUSG)) {
		contiac.numFLstUsg = _contiac->numFLstUsg;
		refreshLstUsg(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTUSR)) {
		contiac.numFLstUsr = _contiac->numFLstUsr;
		refreshLstUsr(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPRS)) {
		contiac.numFLstPrs = _contiac->numFLstPrs;
		refreshLstPrs(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTFIL)) {
		contiac.numFLstFil = _contiac->numFLstFil;
		refreshLstFil(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTOPR)) {
		contiac.numFLstOpr = _contiac->numFLstOpr;
		refreshLstOpr(dbsbrly, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPTY)) {
		contiac.numFLstPty = _contiac->numFLstPty;
		refreshLstPty(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyNavAdmin::handleDpchAppDoButUsgViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsgAvail && statshr.ButUsgViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstUsg.getRefByNum(contiac.numFLstUsg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyUsg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyUsg");
	};
};

void PnlBrlyNavAdmin::handleDpchAppDoButUsgNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyUsg");
};

void PnlBrlyNavAdmin::handleDpchAppDoButUsrViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsrAvail && statshr.ButUsrViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstUsr.getRefByNum(contiac.numFLstUsr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyUsr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyUsr");
	};
};

void PnlBrlyNavAdmin::handleDpchAppDoButUsrNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyUsr");
};

void PnlBrlyNavAdmin::handleDpchAppDoButPrsViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrsAvail && statshr.ButPrsViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstPrs.getRefByNum(contiac.numFLstPrs), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyPrs", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyPrs");
	};
};

void PnlBrlyNavAdmin::handleDpchAppDoButPrsNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyPrs");
};

void PnlBrlyNavAdmin::handleDpchAppDoButFilViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFilAvail && statshr.ButFilViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstFil.getRefByNum(contiac.numFLstFil), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyFil", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyFil");
	};
};

void PnlBrlyNavAdmin::handleDpchAppDoButFilNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyFil");
};

void PnlBrlyNavAdmin::handleDpchAppDoButOprViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstOprAvail && statshr.ButOprViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstOpr.getRefByNum(contiac.numFLstOpr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyOpr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyOpr");
	};
};

void PnlBrlyNavAdmin::handleDpchAppDoButOprNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyOpr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyOpr");
};

void PnlBrlyNavAdmin::handleDpchAppDoButPtyViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	BrlyHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPtyAvail && statshr.ButPtyViewActive) {
		if (dbsbrly->tblbrlyhistrmuseruniversal->loadRecByRef(feedFLstPty.getRefByNum(contiac.numFLstPty), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, husrRunv->ixBrlyVPreset, husrRunv->preUref, "CrdBrlyPty", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyPty");
	};
};

void PnlBrlyNavAdmin::handleDpchAppDoButPtyNewcrdClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyPty", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyPty");
};

void PnlBrlyNavAdmin::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallBrlyHusrRunvMod_crdUsrEq(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlBrlyNavAdmin::handleCallBrlyHusrRunvMod_crdUsrEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecBrlyVCard::CRDBRLYUSG) {
		refreshUsg(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYUSR) {
		refreshUsr(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYPRS) {
		refreshPrs(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYFIL) {
		refreshFil(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYOPR) {
		refreshOpr(dbsbrly, moditems);
	} else if (ixInv == VecBrlyVCard::CRDBRLYPTY) {
		refreshPty(dbsbrly, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

