/**
  * \file PnlBrlyFltOrgMNFlight.cpp
  * job handler for job PnlBrlyFltOrgMNFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyFltOrgMNFlight.h"

#include "PnlBrlyFltOrgMNFlight_blks.cpp"
#include "PnlBrlyFltOrgMNFlight_evals.cpp"

/******************************************************************************
 class PnlBrlyFltOrgMNFlight
 ******************************************************************************/

PnlBrlyFltOrgMNFlight::PnlBrlyFltOrgMNFlight(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYFLTORGMNFLIGHT, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::MNR, "ong", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::MNR, ixBrlyVLocale));
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::OOD, "red", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::OOD, ixBrlyVLocale));
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::SLM, "yel", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::SLM, ixBrlyVLocale));
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::UTD, "grn", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::UTD, ixBrlyVLocale));

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref, 0);

	qry = new QryBrlyFltOrgMNFlight(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlBrlyFltOrgMNFlight::~PnlBrlyFltOrgMNFlight() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyFltOrgMNFlight::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFCsiQst, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlBrlyFltOrgMNFlight::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixBrlyVQrystate);

	// statshr
	statshr.ButViewAvail = evalButViewAvail(dbsbrly);
	statshr.ButViewActive = evalButViewActive(dbsbrly);
	statshr.ButAddAvail = evalButAddAvail(dbsbrly);
	statshr.ButSubAvail = evalButSubAvail(dbsbrly);
	statshr.ButSubActive = evalButSubActive(dbsbrly);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyFltOrgMNFlight::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFFLT) {
		recFltRflt = BrlyRMFlightMFlight();

		recFlt = BrlyMFlight();

		xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref, 0);

		qry->stgiac.jnumFirstload = 1;

		qry->rerun(dbsbrly);
		refresh(dbsbrly, moditems);

		if (notif) {
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			xchg->submitDpch(getNewDpchEng(moditems));
		};
	};
	// IP updatePreset --- END
};

void PnlBrlyFltOrgMNFlight::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTORGMNFLIGHTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsbrly, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbsbrly, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTORGMNFLIGHTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTVIEWCLICK) {
					handleDpchAppDoButViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTADDCLICK) {
					handleDpchAppDoButAddClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUBCLICK) {
					handleDpchAppDoButSubClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyFltOrgMNFlight::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyFltOrgMNFlight::handleDpchAppDataStgiac(
			DbsBrly* dbsbrly
			, StgIac* _stgiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiac->diff(&stgiac);
	// IP handleDpchAppDataStgiac --- INSERT
	insert(moditems, DpchEngData::STGIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyFltOrgMNFlight::handleDpchAppDataStgiacqry(
			DbsBrly* dbsbrly
			, QryBrlyFltOrgMNFlight::StgIac* _stgiacqry
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	BrlyQFltOrgMNFlight* recSelNew = NULL;

	BrlyRMFlightMFlight* _recFltRflt = NULL;
	BrlyMFlight* _recFlt = NULL;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryBrlyFltOrgMNFlight::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryBrlyFltOrgMNFlight::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbsbrly);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryBrlyFltOrgMNFlight::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recFltRflt = BrlyRMFlightMFlight();

			recFlt = BrlyMFlight();

			if (recSelNew) {
				if (dbsbrly->tblbrlyrmflightmflight->loadRecByRef(recSelNew->ref, &_recFltRflt)) {
					recFltRflt = *_recFltRflt;
					delete _recFltRflt;
				};
				if (dbsbrly->tblbrlymflight->loadRecByRef(recSelNew->mref, &_recFlt)) {
					recFlt = *_recFlt;
					delete _recFlt;
				};
			};

			xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref, ((recSelNew) ? recSelNew->ref : 0));
			qry->refreshJnum();
		};

		refresh(dbsbrly, moditems);
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyFltOrgMNFlight::handleDpchAppDoButViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButViewAvail && statshr.ButViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref)) {
			sref = "CrdBrlyFlt";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recFlt.ref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyFltOrgMNFlight::handleDpchAppDoButAddClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButAddClick --- INSERT
};

void PnlBrlyFltOrgMNFlight::handleDpchAppDoButSubClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButSubClick --- INSERT
};

void PnlBrlyFltOrgMNFlight::handleDpchAppDoButRefreshClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	set<uint> moditems;

	muteRefresh = true;

	qry->rerun(dbsbrly, false);
	refresh(dbsbrly, moditems);

	muteRefresh = false;

	insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyFltOrgMNFlight::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTATCHG) {
		call->abort = handleCallBrlyStatChg(dbsbrly, call->jref);
	};
};

bool PnlBrlyFltOrgMNFlight::handleCallBrlyStatChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlyStatChg --- BEGIN

	set<uint> moditems;

	if (jrefTrig == qry->jref) {
		if (!muteRefresh) {
			refresh(dbsbrly, moditems);
			if (qry->ixBrlyVQrystate == VecBrlyVQrystate::UTD) insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
		};
	};

	// IP handleCallBrlyStatChg --- END
	return retval;
};

