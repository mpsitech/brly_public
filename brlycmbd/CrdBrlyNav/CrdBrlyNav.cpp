/**
  * \file CrdBrlyNav.cpp
  * job handler for job CrdBrlyNav (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "CrdBrlyNav.h"

#include "CrdBrlyNav_blks.cpp"
#include "CrdBrlyNav_evals.cpp"

/******************************************************************************
 class CrdBrlyNav
 ******************************************************************************/

CrdBrlyNav::CrdBrlyNav(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::CRDBRLYNAV, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	dlgloaini = NULL;
	pnlheadbar = NULL;
	pnladmin = NULL;
	pnlbase = NULL;
	pnlconnect = NULL;

	// IP constructor.cust1 --- INSERT

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	pnlheadbar = new PnlBrlyNavHeadbar(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnladmin = new PnlBrlyNavAdmin(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnlbase = new PnlBrlyNavBase(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnlconnect = new PnlBrlyNavConnect(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefAdmin = pnladmin->jref;
	statshr.jrefBase = pnlbase->jref;
	statshr.jrefConnect = pnlconnect->jref;

	changeStage(dbsbrly, VecVSge::IDLE);

	xchg->addClstn(VecBrlyVCall::CALLBRLYDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdBrlyNav::~CrdBrlyNav() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* CrdBrlyNav::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdBrlyNav::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	string s;
	vector<string> ss;

	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdBrlyNav/" + VecBrlyVLocale::getSref(ixBrlyVLocale);

	s = StubBrly::getStubSesMenu(dbsbrly, xchg->getRefPreset(VecBrlyVPreset::PREBRLYSESS, jref), ixBrlyVLocale, Stub::VecVNonetype::DASH);
	StrMod::stringToVector(s, ss);

	if (ss.size() == 3) {
		continf.MtxSesSes1 = ss[0];
		continf.MtxSesSes2 = ss[1];
		continf.MtxSesSes3 = ss[2];
	};

	// statshr
	statshr.pnladminAvail = evalPnladminAvail(dbsbrly);
	statshr.pnlbaseAvail = evalPnlbaseAvail(dbsbrly);
	statshr.pnlconnectAvail = evalPnlconnectAvail(dbsbrly);
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbsbrly);
	statshr.MitCrdUsgAvail = evalMitCrdUsgAvail(dbsbrly);
	statshr.MitCrdUsrAvail = evalMitCrdUsrAvail(dbsbrly);
	statshr.MitCrdPrsAvail = evalMitCrdPrsAvail(dbsbrly);
	statshr.MitCrdFilAvail = evalMitCrdFilAvail(dbsbrly);
	statshr.MitCrdOprAvail = evalMitCrdOprAvail(dbsbrly);
	statshr.MitCrdPtyAvail = evalMitCrdPtyAvail(dbsbrly);
	statshr.MspCrd2Avail = evalMspCrd2Avail(dbsbrly);
	statshr.MitCrdRegAvail = evalMitCrdRegAvail(dbsbrly);
	statshr.MitCrdLocAvail = evalMitCrdLocAvail(dbsbrly);
	statshr.MitCrdLegAvail = evalMitCrdLegAvail(dbsbrly);
	statshr.MitCrdTtbAvail = evalMitCrdTtbAvail(dbsbrly);
	statshr.MitCrdFltAvail = evalMitCrdFltAvail(dbsbrly);
	statshr.MspCrd3Avail = evalMspCrd3Avail(dbsbrly);
	statshr.MitCrdConAvail = evalMitCrdConAvail(dbsbrly);
	statshr.MspApp2Avail = evalMspApp2Avail(dbsbrly);
	statshr.MitAppLoiAvail = evalMitAppLoiAvail(dbsbrly);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void CrdBrlyNav::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsbrly, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

	if (pnladmin) pnladmin->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
	if (pnlbase) pnlbase->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
	if (pnlconnect) pnlconnect->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
	// IP updatePreset --- END
};

void CrdBrlyNav::changeStage(
			DbsBrly* dbsbrly
			, uint _ixVSge
			, DpchEngBrly** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsbrly); break;
				case VecVSge::ALRBRLYABT: leaveSgeAlrbrlyabt(dbsbrly); break;
				case VecVSge::CLOSE: leaveSgeClose(dbsbrly); break;
			};

			ixVSge = _ixVSge;
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::ALRBRLYABT: _ixVSge = enterSgeAlrbrlyabt(dbsbrly, reenter); break;
			case VecVSge::CLOSE: _ixVSge = enterSgeClose(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint CrdBrlyNav::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdBrlyNav::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdBrlyNav::enterSgeAlrbrlyabt(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::ALRBRLYABT;
	nextIxVSge = VecVSge::IDLE;
	xchg->submitDpch(AlrBrly::prepareAlrAbt(jref, ixBrlyVLocale, feedFMcbAlert)); // IP enterSgeAlrbrlyabt --- LINE
	return retval;
};

void CrdBrlyNav::leaveSgeAlrbrlyabt(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeAlrbrlyabt --- INSERT
};

uint CrdBrlyNav::enterSgeClose(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CLOSE;
	nextIxVSge = retval;
	xchg->triggerIxCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDCLOSE, jref, VecBrlyVCard::CRDBRLYNAV);
	return retval;
};

void CrdBrlyNav::leaveSgeClose(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeClose --- INSERT
};

string CrdBrlyNav::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void CrdBrlyNav::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESTRMCLICK) {
					handleDpchAppDoMitSesTrmClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSGCLICK) {
					handleDpchAppDoMitCrdUsgClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSRCLICK) {
					handleDpchAppDoMitCrdUsrClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRSCLICK) {
					handleDpchAppDoMitCrdPrsClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFILCLICK) {
					handleDpchAppDoMitCrdFilClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDOPRCLICK) {
					handleDpchAppDoMitCrdOprClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPTYCLICK) {
					handleDpchAppDoMitCrdPtyClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDREGCLICK) {
					handleDpchAppDoMitCrdRegClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDLOCCLICK) {
					handleDpchAppDoMitCrdLocClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDLEGCLICK) {
					handleDpchAppDoMitCrdLegClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDTTBCLICK) {
					handleDpchAppDoMitCrdTtbClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFLTCLICK) {
					handleDpchAppDoMitCrdFltClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCONCLICK) {
					handleDpchAppDoMitCrdConClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPLOICLICK) {
					handleDpchAppDoMitAppLoiClick(dbsbrly, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYALERT) {
			handleDpchAppBrlyAlert(dbsbrly, (DpchAppBrlyAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdBrlyNav::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdBrlyNav::handleDpchAppDoClose(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	changeStage(dbsbrly, VecVSge::CLOSE);
};

void CrdBrlyNav::handleDpchAppDoMitAppAbtClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsbrly, VecVSge::ALRBRLYABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdBrlyNav::handleDpchAppDoMitSesTrmClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	changeStage(dbsbrly, VecVSge::CLOSE);
};

void CrdBrlyNav::handleDpchAppDoMitCrdUsgClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyUsg");
};

void CrdBrlyNav::handleDpchAppDoMitCrdUsrClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyUsr");
};

void CrdBrlyNav::handleDpchAppDoMitCrdPrsClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyPrs");
};

void CrdBrlyNav::handleDpchAppDoMitCrdFilClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyFil");
};

void CrdBrlyNav::handleDpchAppDoMitCrdOprClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyOpr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyOpr");
};

void CrdBrlyNav::handleDpchAppDoMitCrdPtyClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyPty", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyPty");
};

void CrdBrlyNav::handleDpchAppDoMitCrdRegClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyReg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyReg");
};

void CrdBrlyNav::handleDpchAppDoMitCrdLocClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyLoc", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyLoc");
};

void CrdBrlyNav::handleDpchAppDoMitCrdLegClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyLeg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyLeg");
};

void CrdBrlyNav::handleDpchAppDoMitCrdTtbClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyTtb", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyTtb");
};

void CrdBrlyNav::handleDpchAppDoMitCrdFltClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyFlt", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyFlt");
};

void CrdBrlyNav::handleDpchAppDoMitCrdConClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDOPEN, jref, 0, 0, "CrdBrlyCon", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	else *dpcheng = new DpchEngBrlyConfirm(true, jrefNew, "CrdBrlyCon");
};

void CrdBrlyNav::handleDpchAppDoMitAppLoiClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	if (!dlgloaini) {
		dlgloaini = new DlgBrlyNavLoaini(xchg, dbsbrly, jref, ixBrlyVLocale);
		statshr.jrefDlgloaini = dlgloaini->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdBrlyNav::handleDpchAppBrlyAlert(
			DbsBrly* dbsbrly
			, DpchAppBrlyAlert* dpchappbrlyalert
			, DpchEngBrly** dpcheng
		) {
	if (ixVSge == VecVSge::ALRBRLYABT) {
		changeStage(dbsbrly, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
};

void CrdBrlyNav::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYDLGCLOSE) {
		call->abort = handleCallBrlyDlgClose(dbsbrly, call->jref);
	};
};

bool CrdBrlyNav::handleCallBrlyDlgClose(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgloaini) {
		delete dlgloaini;
		dlgloaini = NULL;
		statshr.jrefDlgloaini = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

