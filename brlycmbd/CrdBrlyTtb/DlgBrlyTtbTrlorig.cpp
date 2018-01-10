/**
  * \file DlgBrlyTtbTrlorig.cpp
  * job handler for job DlgBrlyTtbTrlorig (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "DlgBrlyTtbTrlorig.h"

#include "DlgBrlyTtbTrlorig_blks.cpp"
#include "DlgBrlyTtbTrlorig_evals.cpp"

/******************************************************************************
 class DlgBrlyTtbTrlorig
 ******************************************************************************/

DlgBrlyTtbTrlorig::DlgBrlyTtbTrlorig(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::DLGBRLYTTBTRLORIG, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFDetPupSrc.tag = "FeedFDetPupSrc";
	VecVSrc::fillFeed(feedFDetPupSrc);
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixBrlyVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::DET;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgBrlyTtbTrlorig::~DlgBrlyTtbTrlorig() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* DlgBrlyTtbTrlorig::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &continftrl, &feedFDetPupSrc, &feedFDse, &feedFSge, &statshr, &statshrrfi, &statshrtfi, &statshrtrl, items);
	};

	return dpcheng;
};

void DlgBrlyTtbTrlorig::refreshDet(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIacDet oldContiacdet(contiacdet);

	// IP refreshDet --- BEGIN
	// contiacdet

	// IP refreshDet --- END
	if (contiacdet.diff(&oldContiacdet).size() != 0) insert(moditems, DpchEngData::CONTIACDET);
};

void DlgBrlyTtbTrlorig::refreshRfi(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShrRfi oldStatshrrfi(statshrrfi);

	// IP refreshRfi --- BEGIN
	// statshrrfi
	statshrrfi.UldActive = evalRfiUldActive(dbsbrly);

	// IP refreshRfi --- END
	if (statshrrfi.diff(&oldStatshrrfi).size() != 0) insert(moditems, DpchEngData::STATSHRRFI);
};

void DlgBrlyTtbTrlorig::refreshTrl(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInfTrl oldContinftrl(continftrl);
	StatShrTrl oldStatshrtrl(statshrtrl);

	// IP refreshTrl --- BEGIN
	// continftrl

	// statshrtrl
	statshrtrl.ButRunActive = evalTrlButRunActive(dbsbrly);
	statshrtrl.ButStoActive = evalTrlButStoActive(dbsbrly);

	// IP refreshTrl --- END
	if (continftrl.diff(&oldContinftrl).size() != 0) insert(moditems, DpchEngData::CONTINFTRL);
	if (statshrtrl.diff(&oldStatshrtrl).size() != 0) insert(moditems, DpchEngData::STATSHRTRL);
};

void DlgBrlyTtbTrlorig::refreshTfi(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShrTfi oldStatshrtfi(statshrtfi);

	// IP refreshTfi --- BEGIN
	// statshrtfi
	statshrtfi.DldActive = evalTfiDldActive(dbsbrly);

	// IP refreshTfi --- END
	if (statshrtfi.diff(&oldStatshrtfi).size() != 0) insert(moditems, DpchEngData::STATSHRTFI);
};

void DlgBrlyTtbTrlorig::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// statshr
	statshr.ButDneActive = evalButDneActive(dbsbrly);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshDet(dbsbrly, moditems);
	refreshRfi(dbsbrly, moditems);
	refreshTrl(dbsbrly, moditems);
	refreshTfi(dbsbrly, moditems);
};

void DlgBrlyTtbTrlorig::changeStage(
			DbsBrly* dbsbrly
			, uint _ixVSge
			, DpchEngBrly** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsbrly); break;
				case VecVSge::ULDDONE: leaveSgeUlddone(dbsbrly); break;
				case VecVSge::TRANSLATE: leaveSgeTranslate(dbsbrly); break;
				case VecVSge::DONE: leaveSgeDone(dbsbrly); break;
			};

			ixVSge = _ixVSge;
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::ULDDONE: _ixVSge = enterSgeUlddone(dbsbrly, reenter); break;
			case VecVSge::TRANSLATE: _ixVSge = enterSgeTranslate(dbsbrly, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint DlgBrlyTtbTrlorig::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgBrlyTtbTrlorig::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgBrlyTtbTrlorig::enterSgeUlddone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::ULDDONE;
	nextIxVSge = retval;
	// IP enterSgeUlddone --- INSERT
	return retval;
};

void DlgBrlyTtbTrlorig::leaveSgeUlddone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeUlddone --- INSERT
};

uint DlgBrlyTtbTrlorig::enterSgeTranslate(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::TRANSLATE;
	nextIxVSge = VecVSge::DONE;

	clearInvs();
	// IP enterSgeTranslate --- INSERT
	submitInvs(dbsbrly, retval, retval);
	return retval;
};

void DlgBrlyTtbTrlorig::leaveSgeTranslate(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeTranslate --- INSERT
};

uint DlgBrlyTtbTrlorig::enterSgeDone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
	// IP enterSgeDone --- INSERT
	return retval;
};

void DlgBrlyTtbTrlorig::leaveSgeDone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeDone --- INSERT
};

string DlgBrlyTtbTrlorig::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::ULDDONE) || (ixVSge == VecVSge::TRANSLATE) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::ULDDONE) retval = "raw data file loaded";
			else if (ixVSge == VecVSge::TRANSLATE) retval = "translating";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::ULDDONE) retval = "Rohdaten-Datei geladen";
			else if (ixVSge == VecVSge::TRANSLATE) retval = "\\u00fcbersetze";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

void DlgBrlyTtbTrlorig::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBTRLORIGDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbsbrly, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBTRLORIGDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsbrly, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoTrl != 0) {
				if (dpchappdo->ixVDoTrl == VecVDoTrl::BUTRUNCLICK) {
					handleDpchAppDoTrlButRunClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDoTrl == VecVDoTrl::BUTSTOCLICK) {
					handleDpchAppDoTrlButStoClick(dbsbrly, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::UPLOAD) {
		handleUpload(dbsbrly, req->filename);

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DOWNLOAD) {
		req->filename = handleDownload(dbsbrly);

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::RET) {
		opNdone++;

		if (opNdone == opN) {
			clearOps();

			opNdone = 0;
			opN = 0;

			changeStage(dbsbrly, nextIxVSge);
		};
	};
};

void DlgBrlyTtbTrlorig::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgBrlyTtbTrlorig::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::TFI)) ixVDit = _contiac->numFDse;
		refresh(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgBrlyTtbTrlorig::handleDpchAppDataContiacdet(
			DbsBrly* dbsbrly
			, ContIacDet* _contiacdet
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- INSERT
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgBrlyTtbTrlorig::handleDpchAppDoButDneClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
		xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButDneClick --- IEND
};

void DlgBrlyTtbTrlorig::handleDpchAppDoTrlButRunClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoTrlButRunClick --- BEGIN
	if (statshrtrl.ButRunActive) {
		if (ixVSge == VecVSge::ULDDONE) {
			changeStage(dbsbrly, VecVSge::TRANSLATE, dpcheng);
		};
	};
	// IP handleDpchAppDoTrlButRunClick --- END
};

void DlgBrlyTtbTrlorig::handleDpchAppDoTrlButStoClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoTrlButStoClick --- INSERT
};

void DlgBrlyTtbTrlorig::handleUpload(
			DbsBrly* dbsbrly
			, const string& filename
		) {
	// IP handleUpload --- BEGIN
	if (ixVSge == VecVSge::IDLE) {
		// IP handleUpload.ulddone --- INSERT
		changeStage(dbsbrly, VecVSge::ULDDONE);
	};
	// IP handleUpload --- END
};

string DlgBrlyTtbTrlorig::handleDownload(
			DbsBrly* dbsbrly
		) {
	return(""); // IP handleDownload --- LINE
};


