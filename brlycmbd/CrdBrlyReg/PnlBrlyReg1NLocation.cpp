/**
  * \file PnlBrlyReg1NLocation.cpp
  * job handler for job PnlBrlyReg1NLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyReg1NLocation.h"

#include "PnlBrlyReg1NLocation_blks.cpp"
#include "PnlBrlyReg1NLocation_evals.cpp"

/******************************************************************************
 class PnlBrlyReg1NLocation
 ******************************************************************************/

PnlBrlyReg1NLocation::PnlBrlyReg1NLocation(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYREG1NLOCATION, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::MNR, "ong", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::MNR, ixBrlyVLocale));
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::OOD, "red", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::OOD, ixBrlyVLocale));
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::SLM, "yel", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::SLM, ixBrlyVLocale));
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::UTD, "grn", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::UTD, ixBrlyVLocale));

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref, 0);

	qry = new QryBrlyReg1NLocation(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlBrlyReg1NLocation::~PnlBrlyReg1NLocation() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyReg1NLocation::getNewDpchEng(
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

void PnlBrlyReg1NLocation::refresh(
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
	statshr.ButNewAvail = evalButNewAvail(dbsbrly);
	statshr.ButDeleteAvail = evalButDeleteAvail(dbsbrly);
	statshr.ButDeleteActive = evalButDeleteActive(dbsbrly);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlBrlyReg1NLocation::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFREG) {
		recLoc = BrlyMLocation();
		ixWSubsetLoc = 0;

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

void PnlBrlyReg1NLocation::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREG1NLOCATIONDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsbrly, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbsbrly, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREG1NLOCATIONDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTVIEWCLICK) {
					handleDpchAppDoButViewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyReg1NLocation::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyReg1NLocation::handleDpchAppDataStgiac(
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

void PnlBrlyReg1NLocation::handleDpchAppDataStgiacqry(
			DbsBrly* dbsbrly
			, QryBrlyReg1NLocation::StgIac* _stgiacqry
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	BrlyQReg1NLocation* recSelNew = NULL;

	BrlyMLocation* _recLoc = NULL;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryBrlyReg1NLocation::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryBrlyReg1NLocation::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbsbrly);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryBrlyReg1NLocation::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recLoc = BrlyMLocation();

			if (recSelNew) {
				if (dbsbrly->tblbrlymlocation->loadRecByRef(recSelNew->ref, &_recLoc)) {
					recLoc = *_recLoc;
					ixWSubsetLoc = dbsbrly->getIxWSubsetByBrlyMLocation(_recLoc);
					delete _recLoc;
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

void PnlBrlyReg1NLocation::handleDpchAppDoButViewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButViewAvail && statshr.ButViewActive) {
		if (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref)) {
			sref = "CrdBrlyLoc";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, recLoc.ref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyReg1NLocation::handleDpchAppDoButNewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButNewAvail) {
		if ((xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT) != 0) {
			sref = "CrdBrlyLoc";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, sref, -1, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
		else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, sref);
	};
};

void PnlBrlyReg1NLocation::handleDpchAppDoButDeleteClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlBrlyReg1NLocation::handleDpchAppDoButRefreshClick(
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

void PnlBrlyReg1NLocation::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTATCHG) {
		call->abort = handleCallBrlyStatChg(dbsbrly, call->jref);
	};
};

bool PnlBrlyReg1NLocation::handleCallBrlyStatChg(
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

