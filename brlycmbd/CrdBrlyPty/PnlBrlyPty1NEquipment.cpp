/**
  * \file PnlBrlyPty1NEquipment.cpp
  * job handler for job PnlBrlyPty1NEquipment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyPty1NEquipment.h"

#include "PnlBrlyPty1NEquipment_blks.cpp"

/******************************************************************************
 class PnlBrlyPty1NEquipment
 ******************************************************************************/

PnlBrlyPty1NEquipment::PnlBrlyPty1NEquipment(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYPTY1NEQUIPMENT, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::MNR, "ong", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::MNR, ixBrlyVLocale));
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::OOD, "red", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::OOD, ixBrlyVLocale));
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::SLM, "yel", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::SLM, ixBrlyVLocale));
	feedFCsiQst.appendIxSrefTitles(VecBrlyVQrystate::UTD, "grn", VecBrlyVQrystate::getTitle(VecBrlyVQrystate::UTD, ixBrlyVLocale));

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref, 0);

	qry = new QryBrlyPty1NEquipment(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlBrlyPty1NEquipment::~PnlBrlyPty1NEquipment() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* PnlBrlyPty1NEquipment::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFCsiQst, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlBrlyPty1NEquipment::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixBrlyVQrystate);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlBrlyPty1NEquipment::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFPTY) {
		recEqp = BrlyMEquipment();
		ixWSubsetEqp = 0;

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

void PnlBrlyPty1NEquipment::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTY1NEQUIPMENTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsbrly, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbsbrly, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTY1NEQUIPMENTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyPty1NEquipment::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyPty1NEquipment::handleDpchAppDataStgiac(
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

void PnlBrlyPty1NEquipment::handleDpchAppDataStgiacqry(
			DbsBrly* dbsbrly
			, QryBrlyPty1NEquipment::StgIac* _stgiacqry
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	BrlyQPty1NEquipment* recSelNew = NULL;

	BrlyMEquipment* _recEqp = NULL;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryBrlyPty1NEquipment::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryBrlyPty1NEquipment::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbsbrly);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryBrlyPty1NEquipment::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recEqp = BrlyMEquipment();

			if (recSelNew) {
				if (dbsbrly->tblbrlymequipment->loadRecByRef(recSelNew->ref, &_recEqp)) {
					recEqp = *_recEqp;
					ixWSubsetEqp = dbsbrly->getIxWSubsetByBrlyMEquipment(_recEqp);
					delete _recEqp;
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

void PnlBrlyPty1NEquipment::handleDpchAppDoButRefreshClick(
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

void PnlBrlyPty1NEquipment::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTATCHG) {
		call->abort = handleCallBrlyStatChg(dbsbrly, call->jref);
	};
};

bool PnlBrlyPty1NEquipment::handleCallBrlyStatChg(
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

