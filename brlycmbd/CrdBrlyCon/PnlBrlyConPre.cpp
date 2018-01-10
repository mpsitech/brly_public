/**
  * \file PnlBrlyConPre.cpp
  * job handler for job PnlBrlyConPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyConPre.h"

#include "PnlBrlyConPre_blks.cpp"

/******************************************************************************
 class PnlBrlyConPre
 ******************************************************************************/

PnlBrlyConPre::PnlBrlyConPre(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYCONPRE, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

};

PnlBrlyConPre::~PnlBrlyConPre() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyConPre::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyConPre::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	// IP refresh --- IBEGIN
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	BrlyMConnection* con = NULL;
	BrlyMLeg* corr = NULL;
	BrlyMFlight* flt = NULL;

	dbsbrly->tblbrlymconnection->loadRecByRef(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref), &con);
	if (con) {
		dbsbrly->tblbrlymleg->loadRecByRef(con->corRefBrlyMLeg, &corr);
		dbsbrly->tblbrlymflight->loadRecByRef(con->refBrlyMFlight, &flt);
	};

	if (corr && flt) {
		statshr.SldTmeMin = flt->start;
		statshr.SldTmeMax = flt->stop;
		statshr.SldPhiMin =	0.0;
		statshr.SldPhiMax = corr->deltaphi;

	} else {
		statshr.SldTmeMin = 0;
		statshr.SldTmeMax = 0;
		statshr.SldPhiMin = 0.0;
		statshr.SldPhiMax = 0.0;
	};

	contiac.SldTme = statshr.SldTmeMin;
	contiac.SldPhi = statshr.SldPhiMin;

	if (flt) delete flt;
	if (corr) delete corr;
	if (con) delete con;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	// IP refresh --- IEND
};

void PnlBrlyConPre::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFCON) {
	};
	// IP updatePreset --- END
};

void PnlBrlyConPre::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONPREDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		};
	};
};

void PnlBrlyConPre::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyConPre::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	if (has(diffitems, ContIac::SLDTME)) {
		contiac.SldTme = _contiac->SldTme;
		xchg->triggerIxIntvalCall(dbsbrly, VecBrlyVCall::CALLBRLYINTVALPRESET, jref, VecBrlyVPreset::PREBRLYTIME, contiac.SldTme);
	};

/*
	if (has(diffitems, ContIac::CHKTME)) {
		contiac.ChkTme = _contiac->ChkTme;

		if (contiac.ChkTme) xchg->triggerIxIntvalCall(dbsbrly, VecBrlyVCall::CALLBRLYINTVALPRESET, jref, VecBrlyVPreset::PREBRLYTIME, contiac.SldTme);
		else xchg->triggerIxIntvalCall(dbsbrly, VecBrlyVCall::CALLBRLYINTVALPRESET, jref, VecBrlyVPreset::PREBRLYTIME, numeric_limits<int>::min());
	};
*/

	if (has(diffitems, ContIac::SLDPHI)) {
		contiac.SldPhi = _contiac->SldPhi;
		xchg->triggerIxDblvalCall(dbsbrly, VecBrlyVCall::CALLBRLYDBLVALPRESET, jref, VecBrlyVPreset::PREBRLYPHI, contiac.SldPhi);
	};

/*
	if (has(diffitems, ContIac::CHKPHI)) {
		contiac.ChkPhi = _contiac->ChkPhi;

		if (contiac.ChkPhi) xchg->triggerIxDblvalCall(dbsbrly, VecBrlyVCall::CALLBRLYDBLVALPRESET, jref, VecBrlyVPreset::PREBRLYPHI, contiac.SldPhi);
		else xchg->triggerIxDblvalCall(dbsbrly, VecBrlyVCall::CALLBRLYDBLVALPRESET, jref, VecBrlyVPreset::PREBRLYPHI, -numeric_limits<double>::infinity());
	};

	if (has(diffitems, ContIac::CHKLCK)) {
		contiac.ChkLck = _contiac->ChkLck;

		if (contiac.ChkLck && (statshr.SldTmeMax > statshr.SldTmeMin)) {
			_contiac->SldPhi = contiac.SldPhi; // backup
			contiac.SldPhi = statshr.SldPhiMin + (statshr.SldPhiMax-statshr.SldPhiMin) * (contiac.SldTme-statshr.SldTmeMin)/(statshr.SldTmeMax-statshr.SldTmeMin);

			if (contiac.SldPhi != _contiac->SldPhi) xchg->triggerIxDblvalCall(dbsbrly, VecBrlyVCall::CALLBRLYDBLVALPRESET, jref, VecBrlyVPreset::PREBRLYPHI, contiac.SldPhi);
		};
	};
*/

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};


