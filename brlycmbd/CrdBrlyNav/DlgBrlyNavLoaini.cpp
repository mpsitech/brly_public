/**
  * \file DlgBrlyNavLoaini.cpp
  * job handler for job DlgBrlyNavLoaini (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "DlgBrlyNavLoaini.h"

#include "DlgBrlyNavLoaini_blks.cpp"
#include "DlgBrlyNavLoaini_evals.cpp"

/******************************************************************************
 class DlgBrlyNavLoaini
 ******************************************************************************/

DlgBrlyNavLoaini::DlgBrlyNavLoaini(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::DLGBRLYNAVLOAINI, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixBrlyVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iex = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::IFI;

	iex = new IexBrlyIni(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgBrlyNavLoaini::~DlgBrlyNavLoaini() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* DlgBrlyNavLoaini::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &continfppr, &feedFDse, &feedFSge, &statshr, &statshrifi, &statshrimp, &statshrlfi, &statshrppr, items);
	};

	return dpcheng;
};

void DlgBrlyNavLoaini::refreshIfi(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShrIfi oldStatshrifi(statshrifi);

	// IP refreshIfi --- BEGIN
	// statshrifi
	statshrifi.UldActive = evalIfiUldActive(dbsbrly);

	// IP refreshIfi --- END
	if (statshrifi.diff(&oldStatshrifi).size() != 0) insert(moditems, DpchEngData::STATSHRIFI);
};

void DlgBrlyNavLoaini::refreshImp(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInfImp oldContinfimp(continfimp);
	StatShrImp oldStatshrimp(statshrimp);

	// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbsbrly);

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbsbrly);
	statshrimp.ButStoActive = evalImpButStoActive(dbsbrly);

	// IP refreshImp --- REND
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
};

void DlgBrlyNavLoaini::refreshPpr(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInfPpr oldContinfppr(continfppr);
	StatShrPpr oldStatshrppr(statshrppr);

	// IP refreshPpr --- RBEGIN
	// continfppr
	continfppr.TxtPrg = getSquawk(dbsbrly);

	// statshrppr
	statshrppr.ButRunActive = evalPprButRunActive(dbsbrly);
	statshrppr.ButStoActive = evalPprButStoActive(dbsbrly);

	// IP refreshPpr --- REND
	if (continfppr.diff(&oldContinfppr).size() != 0) insert(moditems, DpchEngData::CONTINFPPR);
	if (statshrppr.diff(&oldStatshrppr).size() != 0) insert(moditems, DpchEngData::STATSHRPPR);
};

void DlgBrlyNavLoaini::refreshLfi(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShrLfi oldStatshrlfi(statshrlfi);

	// IP refreshLfi --- BEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbsbrly);

	// IP refreshLfi --- END
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
};

void DlgBrlyNavLoaini::refresh(
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

	refreshIfi(dbsbrly, moditems);
	refreshImp(dbsbrly, moditems);
	refreshPpr(dbsbrly, moditems);
	refreshLfi(dbsbrly, moditems);
};

void DlgBrlyNavLoaini::changeStage(
			DbsBrly* dbsbrly
			, uint _ixVSge
			, DpchEngBrly** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsbrly); break;
				case VecVSge::PRSIDLE: leaveSgePrsidle(dbsbrly); break;
				case VecVSge::PARSE: leaveSgeParse(dbsbrly); break;
				case VecVSge::ALRBRLYPER: leaveSgeAlrbrlyper(dbsbrly); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbsbrly); break;
				case VecVSge::IMPIDLE: leaveSgeImpidle(dbsbrly); break;
				case VecVSge::IMPORT: leaveSgeImport(dbsbrly); break;
				case VecVSge::IMPDONE: leaveSgeImpdone(dbsbrly); break;
				case VecVSge::POSTPRC: leaveSgePostprc(dbsbrly); break;
				case VecVSge::DONE: leaveSgeDone(dbsbrly); break;
			};

			ixVSge = _ixVSge;
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::PRSIDLE: _ixVSge = enterSgePrsidle(dbsbrly, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbsbrly, reenter); break;
			case VecVSge::ALRBRLYPER: _ixVSge = enterSgeAlrbrlyper(dbsbrly, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbsbrly, reenter); break;
			case VecVSge::IMPIDLE: _ixVSge = enterSgeImpidle(dbsbrly, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbsbrly, reenter); break;
			case VecVSge::IMPDONE: _ixVSge = enterSgeImpdone(dbsbrly, reenter); break;
			case VecVSge::POSTPRC: _ixVSge = enterSgePostprc(dbsbrly, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint DlgBrlyNavLoaini::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgBrlyNavLoaini::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgBrlyNavLoaini::enterSgePrsidle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSge = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
	// IP enterSgePrsidle --- INSERT
	return retval;
};

void DlgBrlyNavLoaini::leaveSgePrsidle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgBrlyNavLoaini::enterSgeParse(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PARSE;
	nextIxVSge = retval;
	// IP enterSgeParse --- IBEGIN
	ifstream ififile;

	char* buf;
	string s;

	bool ifitxt;
	bool ifixml;

	bool success;

	iex->reset();

	// check file type
	ififile.open(infilename.c_str(), ifstream::in);

	buf = new char[16];
	ififile.get(buf, 16);
	s = string(buf);

	ifitxt = (s.find("- ") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	success = false;

	if (ifitxt) success = iex->readTxtFile(infilename);
	else if (ifixml) success = iex->readXMLFile(infilename);

	if (success) {
		retval = VecVSge::PRSDONE;
	} else {
		if (reqCmd) {
			cout << "\tparse error at line " << iex->lineno << endl;
			retval = VecVSge::IDLE;
		} else {
			retval = VecVSge::ALRBRLYPER;
		};
	};
	// IP enterSgeParse --- IEND
	return retval;
};

void DlgBrlyNavLoaini::leaveSgeParse(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgBrlyNavLoaini::enterSgeAlrbrlyper(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::ALRBRLYPER;
	nextIxVSge = VecVSge::IDLE;
	// IP enterSgeAlrbrlyper --- RBEGIN
	xchg->submitDpch(AlrBrly::prepareAlrPer(jref, ixBrlyVLocale, to_string(iex->lineno), feedFMcbAlert));
	// IP enterSgeAlrbrlyper --- REND
	return retval;
};

void DlgBrlyNavLoaini::leaveSgeAlrbrlyper(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeAlrbrlyper --- INSERT
};

uint DlgBrlyNavLoaini::enterSgePrsdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;
	nextIxVSge = retval;
	// IP enterSgePrsdone --- INSERT
	return retval;
};

void DlgBrlyNavLoaini::leaveSgePrsdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgBrlyNavLoaini::enterSgeImpidle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSge = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
	// IP enterSgeImpidle --- INSERT
	return retval;
};

void DlgBrlyNavLoaini::leaveSgeImpidle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgBrlyNavLoaini::enterSgeImport(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IMPORT;
	nextIxVSge = VecVSge::IMPDONE;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeImport --- IBEGIN
	iex->import(dbsbrly);
	// IP enterSgeImport --- IEND
	retval = nextIxVSge;
	return retval;
};

void DlgBrlyNavLoaini::leaveSgeImport(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgBrlyNavLoaini::enterSgeImpdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IMPDONE;
	nextIxVSge = retval;
	// IP enterSgeImpdone --- INSERT
	return retval;
};

void DlgBrlyNavLoaini::leaveSgeImpdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeImpdone --- INSERT
};

uint DlgBrlyNavLoaini::enterSgePostprc(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::POSTPRC;
	nextIxVSge = VecVSge::DONE;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgePostprc --- IBEGIN
	uint loccnt;
	ubigint blockcnt;
	ubigint lastcnt;

	dbsbrly->loadUintBySQL("SELECT COUNT(ref) FROM TblBrlyMLocation", loccnt);

	lastcnt = loccnt%256;
	blockcnt = (loccnt-lastcnt)/256;
	if (lastcnt != 0) blockcnt += 1;

	// BrlyBaseLocloc - blocks of max 256 locations
	for (unsigned int i=0;i<blockcnt;i++) {
		if ((i == (blockcnt-1)) && (lastcnt != 0)) {
			addInv(new DpchInvBrlyBaseLocloc(0, 0, true, false, i*256, i*256+lastcnt-1, {}));
		} else {
			addInv(new DpchInvBrlyBaseLocloc(0, 0, true, false, i*256, (i+1)*256-1, {}));
		};
	};
	// IP enterSgePostprc --- IEND
	submitInvs(dbsbrly, VecVSge::DONE, retval);
	return retval;
};

void DlgBrlyNavLoaini::leaveSgePostprc(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgePostprc --- IBEGIN
	dbsbrly->executeQuery("UPDATE TblBrlyMLocation SET Calcdone = 1");
	// IP leaveSgePostprc --- IEND
};

uint DlgBrlyNavLoaini::enterSgeDone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
	// IP enterSgeDone --- INSERT
	return retval;
};

void DlgBrlyNavLoaini::leaveSgeDone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeDone --- INSERT
};

string DlgBrlyNavLoaini::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRBRLYPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::IMPDONE) || (ixVSge == VecVSge::POSTPRC) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::ALRBRLYPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::IMPDONE) retval = "import done";
			else if (ixVSge == VecVSge::POSTPRC) retval = "incorporating locations (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed)";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::PARSE) retval = "lese Initialisierungsdaten ein";
			else if (ixVSge == VecVSge::ALRBRLYPER) retval = "Fehler beim Einlesen";
			else if (ixVSge == VecVSge::PRSDONE) retval = "Initialisierungsdaten eingelesen";
			else if (ixVSge == VecVSge::IMPORT) retval = "importiere Initialisierungsdaten (" + to_string(iex->impcnt) + " Datens\\u00e4tze hinzugef\\u00fcgt)";
			else if (ixVSge == VecVSge::IMPDONE) retval = "Import abgeschlossen";
			else if (ixVSge == VecVSge::POSTPRC) retval = "gliedere Orte ein (" + to_string(opNdone) + "/" + to_string(opN) + " Operationen ausgef\\u00fchrt)";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

void DlgBrlyNavLoaini::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYNAVLOAINIDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYNAVLOAINIDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsbrly, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoImp != 0) {
				if (dpchappdo->ixVDoImp == VecVDoImp::BUTRUNCLICK) {
					handleDpchAppDoImpButRunClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDoImp == VecVDoImp::BUTSTOCLICK) {
					handleDpchAppDoImpButStoClick(dbsbrly, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoPpr != 0) {
				if (dpchappdo->ixVDoPpr == VecVDoPpr::BUTRUNCLICK) {
					handleDpchAppDoPprButRunClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDoPpr == VecVDoPpr::BUTSTOCLICK) {
					handleDpchAppDoPprButStoClick(dbsbrly, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYALERT) {
			handleDpchAppBrlyAlert(dbsbrly, (DpchAppBrlyAlert*) (req->dpchapp), &(req->dpcheng));

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

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::TIMER) {
		handleTimer(dbsbrly, req->sref);
	};
};

void DlgBrlyNavLoaini::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgBrlyNavLoaini::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::IFI) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgBrlyNavLoaini::handleDpchAppDoButDneClick(
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

void DlgBrlyNavLoaini::handleDpchAppDoImpButRunClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		if (ixVSge == VecVSge::PRSDONE) {
			changeStage(dbsbrly, VecVSge::IMPIDLE, dpcheng);
		};
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgBrlyNavLoaini::handleDpchAppDoImpButStoClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgBrlyNavLoaini::handleDpchAppDoPprButRunClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoPprButRunClick --- BEGIN
	if (statshrppr.ButRunActive) {
		if (ixVSge == VecVSge::IMPDONE) {
			changeStage(dbsbrly, VecVSge::POSTPRC, dpcheng);
		};
	};
	// IP handleDpchAppDoPprButRunClick --- END
};

void DlgBrlyNavLoaini::handleDpchAppDoPprButStoClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoPprButStoClick --- INSERT
};

void DlgBrlyNavLoaini::handleDpchAppBrlyAlert(
			DbsBrly* dbsbrly
			, DpchAppBrlyAlert* dpchappbrlyalert
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppBrlyAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRBRLYPER) {
		changeStage(dbsbrly, VecVSge::IDLE);
	};
	// IP handleDpchAppBrlyAlert --- IEND
};

void DlgBrlyNavLoaini::handleUpload(
			DbsBrly* dbsbrly
			, const string& filename
		) {
	// IP handleUpload --- BEGIN
	if (ixVSge == VecVSge::IDLE) {
		infilename = filename; // IP handleUpload.prsidle --- ILINE
		changeStage(dbsbrly, VecVSge::PRSIDLE);
	};
	// IP handleUpload --- END
};

string DlgBrlyNavLoaini::handleDownload(
			DbsBrly* dbsbrly
		) {
	return(""); // IP handleDownload --- LINE
};

void DlgBrlyNavLoaini::handleTimer(
			DbsBrly* dbsbrly
			, const string& sref
		) {
	if (ixVSge == VecVSge::PRSIDLE) {
		changeStage(dbsbrly, nextIxVSge);
	} else if (ixVSge == VecVSge::IMPIDLE) {
		changeStage(dbsbrly, nextIxVSge);
	} else if ((ixVSge == VecVSge::IMPORT) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.import.mon --- IBEGIN
		set<uint> moditems;
		refresh(dbsbrly, moditems);
		xchg->submitDpch(getNewDpchEng(moditems));
		// IP handleTimer.import.mon --- IEND
	} else if ((ixVSge == VecVSge::POSTPRC) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.postprc.mon --- IBEGIN
		set<uint> moditems;
		refresh(dbsbrly, moditems);
		xchg->submitDpch(getNewDpchEng(moditems));
		// IP handleTimer.postprc.mon --- IEND
	};
};


