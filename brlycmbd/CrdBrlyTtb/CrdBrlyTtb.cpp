/**
  * \file CrdBrlyTtb.cpp
  * job handler for job CrdBrlyTtb (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "CrdBrlyTtb.h"

#include "CrdBrlyTtb_blks.cpp"
#include "CrdBrlyTtb_evals.cpp"

/******************************************************************************
 class CrdBrlyTtb
 ******************************************************************************/

CrdBrlyTtb::CrdBrlyTtb(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
			, const ubigint ref
		) : JobBrly(xchg, VecBrlyVJob::CRDBRLYTTB, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	dlgimpflt = NULL;
	dlgnew = NULL;
	dlgtrlorig = NULL;
	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;
	iex = NULL;

	// IP constructor.cust1 --- IBEGIN
	fltcnt = 0;
	// IP constructor.cust1 --- IEND

	// initialize according to ref
	changeRef(dbsbrly, jref, ((ref+1) == 0) ? 0 : ref, false);

	pnlrec = new PnlBrlyTtbRec(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnlheadbar = new PnlBrlyTtbHeadbar(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnllist = new PnlBrlyTtbList(xchg, dbsbrly, jref, ixBrlyVLocale);
	iex = new IexBrlyFlt(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	if ((ref+1) == 0) {
		dlgnew = new DlgBrlyTtbNew(xchg, dbsbrly, jref, ixBrlyVLocale);
		statshr.jrefDlgnew = dlgnew->jref;
	};

	changeStage(dbsbrly, VecVSge::IDLE);

	xchg->addClstn(VecBrlyVCall::CALLBRLYDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdBrlyTtb::~CrdBrlyTtb() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void CrdBrlyTtb::stats1_dump(
			DbsBrly* dbsbrly
			, const vector<ubigint>& refsLeg1
			, const vector<ubigint>& refsLeg2
		) {
	cout << "To (" << refsLeg1.size() << " routes): ";
	for (unsigned int i=0;i<refsLeg1.size();i++) {
		if (i != 0) cout << ", ";
		cout << StubBrly::getStubLegShort(dbsbrly, refsLeg1[i]);
	};
	cout << endl;

	cout << "From (" << refsLeg2.size() << " routes): ";
	for (unsigned int i=0;i<refsLeg2.size();i++) {
		if (i != 0) cout << ", ";
		cout << StubBrly::getStubLegShort(dbsbrly, refsLeg2[i]);
	};
	cout << endl;
};
// IP cust --- IEND
DpchEngBrly* CrdBrlyTtb::getNewDpchEng(
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

void CrdBrlyTtb::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdBrlyTtb/" + VecBrlyVLocale::getSref(ixBrlyVLocale);
	continf.MtxCrdTtb = StubBrly::getStubTtbStd(dbsbrly, xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFTTB, jref), ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbsbrly);
	statshr.MitCrdNewAvail = evalMitCrdNewAvail(dbsbrly);
	statshr.MitCrdTrlAvail = evalMitCrdTrlAvail(dbsbrly);
	statshr.MitCrdIflAvail = evalMitCrdIflAvail(dbsbrly);
	statshr.MitCrdIflActive = evalMitCrdIflActive(dbsbrly);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void CrdBrlyTtb::changeRef(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbsbrly, VecBrlyVCall::CALLBRLYLOG, jref, VecBrlyVPreset::VOID, 0, "CrdBrlyTtb", ref);
	xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFTTB, jref, ref);

	refresh(dbsbrly, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));

	if (pnllist) pnllist->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFTTB, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFTTB, jrefTrig, notif);
};

void CrdBrlyTtb::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdBrlyTtb::changeStage(
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
				case VecVSge::IMPIDLE: leaveSgeImpidle(dbsbrly); break;
				case VecVSge::IMPORT: leaveSgeImport(dbsbrly); break;
				case VecVSge::IMPDONE: leaveSgeImpdone(dbsbrly); break;
				case VecVSge::SEGMENT: leaveSgeSegment(dbsbrly); break;
				case VecVSge::SEGDONE: leaveSgeSegdone(dbsbrly); break;
			};

			ixVSge = _ixVSge;
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::ALRBRLYABT: _ixVSge = enterSgeAlrbrlyabt(dbsbrly, reenter); break;
			case VecVSge::CLOSE: _ixVSge = enterSgeClose(dbsbrly, reenter); break;
			case VecVSge::IMPIDLE: _ixVSge = enterSgeImpidle(dbsbrly, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbsbrly, reenter); break;
			case VecVSge::IMPDONE: _ixVSge = enterSgeImpdone(dbsbrly, reenter); break;
			case VecVSge::SEGMENT: _ixVSge = enterSgeSegment(dbsbrly, reenter); break;
			case VecVSge::SEGDONE: _ixVSge = enterSgeSegdone(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint CrdBrlyTtb::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdBrlyTtb::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdBrlyTtb::enterSgeAlrbrlyabt(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::ALRBRLYABT;
	nextIxVSge = VecVSge::IDLE;
	xchg->submitDpch(AlrBrly::prepareAlrAbt(jref, ixBrlyVLocale, feedFMcbAlert)); // IP enterSgeAlrbrlyabt --- LINE
	return retval;
};

void CrdBrlyTtb::leaveSgeAlrbrlyabt(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeAlrbrlyabt --- INSERT
};

uint CrdBrlyTtb::enterSgeClose(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CLOSE;
	nextIxVSge = retval;
	xchg->triggerIxCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDCLOSE, jref, VecBrlyVCard::CRDBRLYTTB);
	return retval;
};

void CrdBrlyTtb::leaveSgeClose(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeClose --- INSERT
};

uint CrdBrlyTtb::enterSgeImpidle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSge = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
	// IP enterSgeImpidle --- INSERT
	return retval;
};

void CrdBrlyTtb::leaveSgeImpidle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint CrdBrlyTtb::enterSgeImport(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IMPORT;
	nextIxVSge = VecVSge::IMPDONE;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeImport --- IBEGIN
	DIR* dir = NULL;

	dirent* diritem = NULL;

	vector<string> folders;
	vector<string> files;

	bool success;

	// read flights without waypoints
	iex->reset();
	iex->readTxtFile(infolder + "/IexBrlyFlt.txt");
	iex->import(dbsbrly);

	// read waypoints
	dir = opendir(infolder.c_str());

	if (dir) {
		// traverse directory (survey)
		diritem = readdir(dir);
		while (diritem) {
			if (diritem->d_type == DT_DIR) {
				// sub-folders: avoid '.' and '..'
				if ((strcmp(diritem->d_name, ".") != 0) && (strcmp(diritem->d_name, "..") != 0)) folders.push_back(diritem->d_name);

			} else if (diritem->d_type == DT_REG) {
				files.push_back(diritem->d_name);
			};

			diritem = readdir(dir);
		};
		closedir(dir);
	};

	// traverse folders and look for IexBrlyFlt.txt within
	fltcnt = 0;

	for (unsigned int i=0;i<folders.size();i++) {
		iex->reset();
	
		success = iex->readTxtFile(infolder + "/" + folders[i] + "/IexBrlyFlt.txt");
		if (success) {
			iex->import(dbsbrly);
		} else {
			cout << "\t" << folders[i] << "/IexBrlyFlt.txt" << ": parse error at line " << iex->lineno << endl;
		};

		fltcnt++;
	};
	// IP enterSgeImport --- IEND
	retval = nextIxVSge;
	return retval;
};

void CrdBrlyTtb::leaveSgeImport(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint CrdBrlyTtb::enterSgeImpdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IMPDONE;
	nextIxVSge = VecVSge::IDLE;
	// IP enterSgeImpdone --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
	// IP enterSgeImpdone --- IEND
	retval = nextIxVSge;
	return retval;
};

void CrdBrlyTtb::leaveSgeImpdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeImpdone --- INSERT
};

uint CrdBrlyTtb::enterSgeSegment(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::SEGMENT;
	nextIxVSge = VecVSge::SEGDONE;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeSegment --- IBEGIN

	// PRELIMINARY
	dbsbrly->executeQuery("UPDATE TblBrlyMFlight SET Segdone = 0");

/*
	DpchInvBrlyDynFltseg* dpchinv = NULL;

	dpchinv = new DpchInvBrlyDynFltseg();

	dpchinv->refsBrlyMFlight.push_back(142172); dpchinv->refsBrlyMFlightN++; // BA177 12-3-2014 LHR-JFK
	dpchinv->refsBrlyMFlight.push_back(190980); dpchinv->refsBrlyMFlightN++; // LA533 12-3-2014 JFK-SCL
	dpchinv->refsBrlyMFlight.push_back(17838); dpchinv->refsBrlyMFlightN++; // AB8484 12-3-2014 TXL-LED
	dpchinv->refsBrlyMFlight.push_back(156172); dpchinv->refsBrlyMFlightN++; // IB6463 12-3-2014 MAD-UIO
	dpchinv->refsBrlyMFlight.push_back(28723); dpchinv->refsBrlyMFlightN++; // LA532 12-3-2014 EZE-SCL
	dpchinv->refsBrlyMFlight.push_back(727472); dpchinv->refsBrlyMFlightN++; // LH400 8-2-2012 FRA-JFK

	addInv(dpchinv);
*/

	// count flights
	uint fltcnt;
	ubigint blockcnt;
	ubigint lastcnt;

	dbsbrly->loadUintBySQL("SELECT COUNT(ref) FROM TblBrlyMFlight WHERE start >= " + to_string(start) + " AND start <= " + to_string(stop) + " AND Segdone = 0", fltcnt);

	lastcnt = fltcnt%256;
	blockcnt = (fltcnt-lastcnt)/256;
	if (lastcnt != 0) blockcnt += 1;

	// BrlyDynFltseg - blocks of max 256 flights
	for (unsigned int i=0;i<blockcnt;i++) {
		if ((i == (blockcnt-1)) && (lastcnt != 0)) {
			addInv(new DpchInvBrlyDynFltseg(0, 0, i*256, i*256+lastcnt-1, {}, start, stop));
		} else {
			addInv(new DpchInvBrlyDynFltseg(0, 0, i*256, (i+1)*256-1, {}, start, stop));
		};
	};

	// IP enterSgeSegment --- IEND
	submitInvs(dbsbrly, retval, retval);
	return retval;
};

void CrdBrlyTtb::leaveSgeSegment(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeSegment --- IBEGIN
	dbsbrly->executeQuery("UPDATE TblBrlyMFlight SET Segdone = 1 WHERE start >= " + to_string(start) + " AND start <= " + to_string(stop));
	// IP leaveSgeSegment --- IEND
};

uint CrdBrlyTtb::enterSgeSegdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::SEGDONE;
	nextIxVSge = VecVSge::IDLE;
	// IP enterSgeSegdone --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
	// IP enterSgeSegdone --- IEND
	retval = nextIxVSge;
	return retval;
};

void CrdBrlyTtb::leaveSgeSegdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeSegdone --- INSERT
};

string CrdBrlyTtb::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	ostringstream str;

	if ( (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::SEGMENT) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::IMPORT) str << "importiere FlightAware-Daten (" << fltcnt << " Fl\\u00fcge hinzugef\\u00fcgt)";
			else if (ixVSge == VecVSge::SEGMENT) str << "segmentiere Fl\\u00fcge (" << opNdone << "/" << opN << " Operationen ausgef\\u00fchrt, letzte: " << getOpsqkLast() << ")";
		} else if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::IMPORT) str << "importing FlightAware data (" << fltcnt << " flights added)";
			else if (ixVSge == VecVSge::SEGMENT) str << "segmenting flights (" << opNdone << "/" << opN << " operations completed, last: " << getOpsqkLast() << ")";
		};
		retval = str.str();

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

void CrdBrlyTtb::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\timportFA" << endl;
			cout << "\tsegment" << endl;
			cout << "\tstats1" << endl;
			cout << "\tvalidate" << endl;
		} else if (req->cmd == "importFA") {
			req->retain = handleImportFA(dbsbrly);

		} else if (req->cmd == "segment") {
			req->retain = handleSegment(dbsbrly);

		} else if (req->cmd == "stats1") {
			req->retain = handleStats1(dbsbrly);

		} else if (req->cmd == "validate") {
			req->retain = handleValidate(dbsbrly);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYINIT) {
			handleDpchAppBrlyInit(dbsbrly, (DpchAppBrlyInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDNEWCLICK) {
					handleDpchAppDoMitCrdNewClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDTRLCLICK) {
					handleDpchAppDoMitCrdTrlClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIFLCLICK) {
					handleDpchAppDoMitCrdIflClick(dbsbrly, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYALERT) {
			handleDpchAppBrlyAlert(dbsbrly, (DpchAppBrlyAlert*) (req->dpchapp), &(req->dpcheng));

		};

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

bool CrdBrlyTtb::handleImportFA(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleImportFA --- IBEGIN
	// - ask for path
	cout << "\tpath to flight data: ";
	cin >> infolder;

	changeStage(dbsbrly, VecVSge::IMPIDLE);

	return(ixVSge != VecVSge::IDLE);
	// IP handleImportFA --- IEND
	return retval;
};

bool CrdBrlyTtb::handleSegment(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleSegment --- IBEGIN
	string s, s2;

	start = 0;
	stop = 0;

	// - ask for time span
	while (start == 0) {
		cout << "\tstart time (DD-MM-YYYY hh:mm:ss): ";
		cin >> s; cin >> s2;
		start = Ftm::invstamp(s + " " + s2);
	};

	while (stop == 0) {
		cout << "\tstop time (DD-MM-YYYY hh:mm:ss): ";
		cin >> s; cin >> s2;
		stop = Ftm::invstamp(s + " " + s2);
	};

	changeStage(dbsbrly, VecVSge::SEGMENT);

	return(ixVSge != VecVSge::IDLE);
	// IP handleSegment --- IEND
	return retval;
};

bool CrdBrlyTtb::handleStats1(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleStats1 --- IBEGIN
	ListBrlyMFlight flts;
	BrlyMFlight* flt = NULL;

	ubigint refLeg;

	unsigned int arena;
	const unsigned int arenaN = 23;

	int ixDepblk, ixArrblk;
	bool depoor, arroor;

	vector<unsigned int> depblkN;
	vector<unsigned int> arrblkN;
	vector<unsigned int> blkN;

	fstream outfile;

	unsigned int N;
	double d;

	vector<double> avgWkdayDepN; // arenaN * 7 * 24*12
	vector<double> avgWkdayArrN;
	vector<double> avgWkdayN;

	vector<double> avgDayDepN; // arenaN * 24*12
	vector<double> avgDayArrN;
	vector<double> avgDayN;

	// 0: all routes
	vector<ubigint> refsLegTo1Go, refsLegTo1Back; // 1,2
	vector<ubigint> refsLegTo2Go, refsLegTo2Back; // 3,4
	vector<ubigint> refsLegTo3Go, refsLegTo3Back; // 5,6
	vector<ubigint> refsLegTo4Go, refsLegTo4Back; // 7,8

	vector<ubigint> refsLegIco1Go, refsLegIco1Back; // 9,10
	vector<ubigint> refsLegIco2Go, refsLegIco2Back; // 11,12
	vector<ubigint> refsLegIco3Go, refsLegIco3Back; // 13,14
	vector<ubigint> refsLegIco4Go, refsLegIco4Back; // 15,16

	vector<ubigint> refsLegCo1Go, refsLegCo1Back; // 17,(18)
	vector<ubigint> refsLegCo2Go, refsLegCo2Back; // 19,(20)
	vector<ubigint> refsLegCo3Go, refsLegCo3Back; // 21,(22)

	// --- categorize routes into arenas
	Brly::loadLegsByArena(dbsbrly, "to1", true, true, false, refsLegTo1Go, refsLegTo1Back);
	Brly::loadLegsByArena(dbsbrly, "to2", true, true, false, refsLegTo2Go, refsLegTo2Back);
	Brly::loadLegsByArena(dbsbrly, "to3", true, true, false, refsLegTo3Go, refsLegTo3Back);
	Brly::loadLegsByArena(dbsbrly, "to4", true, true, false, refsLegTo4Go, refsLegTo4Back);

	cout << "trans-oceanic routes determined" << endl;

	Brly::loadLegsByArena(dbsbrly, "ico1", true, true, false, refsLegIco1Go, refsLegIco1Back);
	Brly::loadLegsByArena(dbsbrly, "ico2", true, true, false, refsLegIco2Go, refsLegIco2Back);
	Brly::loadLegsByArena(dbsbrly, "ico3", true, true, false, refsLegIco3Go, refsLegIco3Back);
//	Brly::loadLegsByArena(dbsbrly, "ico4", true, true, false, refsLegIco4Go, refsLegIco4Back);

	cout << "inter-continental routes determined" << endl;

	Brly::loadLegsByArena(dbsbrly, "co1", true, true, false, refsLegCo1Go, refsLegCo1Back);
	Brly::loadLegsByArena(dbsbrly, "co2", true, true, false, refsLegCo2Go, refsLegCo2Back);
	Brly::loadLegsByArena(dbsbrly, "co3", true, true, false, refsLegCo3Go, refsLegCo3Back);

	cout << "continental routes determined" << endl;

	// --- load and traverse flights
	dbsbrly->tblbrlymflight->loadRstBySQL("SELECT * FROM TblBrlyMFlight ORDER BY refBrlyMLeg ASC, start ASC", false, flts);

	refLeg = 0;

	depblkN.resize(arenaN * 76*24*12, 0);
	arrblkN.resize(arenaN * 76*24*12, 0);
	blkN.resize(arenaN * 76*24*12, 0);

	for (unsigned int i=0;i<flts.nodes.size();i++) {
		flt = flts.nodes[i];

		if (flt->refBrlyMLeg != refLeg) {
			// -- locate route in one of the arenas
			refLeg = flt->refBrlyMLeg;
			arena = 0;

			if (Brly::isInArena(refsLegTo1Go, refLeg)) arena = 1;
			else if (Brly::isInArena(refsLegTo1Back, refLeg)) arena = 2;
			else if (Brly::isInArena(refsLegTo2Go, refLeg)) arena = 3;
			else if (Brly::isInArena(refsLegTo2Back, refLeg)) arena = 4;
			else if (Brly::isInArena(refsLegTo3Go, refLeg)) arena = 5;
			else if (Brly::isInArena(refsLegTo3Back, refLeg)) arena = 6;
			else if (Brly::isInArena(refsLegTo4Go, refLeg)) arena = 7;
			else if (Brly::isInArena(refsLegTo4Back, refLeg)) arena = 8;
			else if (Brly::isInArena(refsLegIco1Go, refLeg)) arena = 9;
			else if (Brly::isInArena(refsLegIco1Back, refLeg)) arena = 10;
			else if (Brly::isInArena(refsLegIco2Go, refLeg)) arena = 11;
			else if (Brly::isInArena(refsLegIco2Back, refLeg)) arena = 12;
			else if (Brly::isInArena(refsLegIco3Go, refLeg)) arena = 13;
			else if (Brly::isInArena(refsLegIco3Back, refLeg)) arena = 14;
			else if (Brly::isInArena(refsLegIco4Go, refLeg)) arena = 15;
			else if (Brly::isInArena(refsLegIco4Back, refLeg)) arena = 16;
			else if (Brly::isInArena(refsLegCo1Go, refLeg)) arena = 17;
			else if (Brly::isInArena(refsLegCo1Back, refLeg)) arena = 18;
			else if (Brly::isInArena(refsLegCo2Go, refLeg)) arena = 19;
			else if (Brly::isInArena(refsLegCo2Back, refLeg)) arena = 20;
			else if (Brly::isInArena(refsLegCo3Go, refLeg)) arena = 21;
			else if (Brly::isInArena(refsLegCo3Back, refLeg)) arena = 22;
		};

		// -- extract timing information
		// NOTE: the analysis is tailored to the star2011-12 data set ; the first time stamp is 13-12-2011 0:0:0
		depoor = false;
		arroor = false;

		ixDepblk = (flt->start - 1323734400) / 300;
		if (ixDepblk < 0) {
			depoor = true;
			ixDepblk = 0;
		};
		if (ixDepblk >= (76*24*12)) {
			depoor = true;
			ixDepblk = 76*24*12-1;
		};

		ixArrblk = (flt->stop - 1323734400 - 1) / 300;
		if (ixArrblk < 0) {
			arroor = true;
			ixArrblk = 0;
		};
		if (ixArrblk >= (76*24*12)) {
			arroor = true;
			ixArrblk = 76*24*12-1;
		};

		if (ixArrblk > ixDepblk) {
			if (!depoor) depblkN[ixDepblk]++;
			if (!arroor) arrblkN[ixArrblk]++;
			for (int i=ixDepblk;i<=ixArrblk;i++) blkN[i]++;

			if (arena != 0) {
				if (!depoor) depblkN[arena*(76*24*12) + ixDepblk]++;
				if (!arroor) arrblkN[arena*(76*24*12) + ixArrblk]++;
				for (int i=ixDepblk;i<=ixArrblk;i++) blkN[arena*(76*24*12) + i]++;
			};
		};

		if ((i != 0) && ((i%10000) == 0)) cout << i << " flights analyzed" << endl;
	};

	// -- dump results
	outfile.open("depblkN.txt", ios::out);
	for (unsigned int i=0;i<(76*24*12);i++) {
		outfile << "'" << Ftm::stamp(1323734400 + i*5*60);
		for (unsigned int j=0;j<arenaN;j++) outfile << "\t" << depblkN[j*(76*24*12) + i];
		outfile << endl;
	};
	outfile.close();

	outfile.open("arrblkN.txt", ios::out);
	for (unsigned int i=0;i<(76*24*12);i++) {
		outfile << "'" << Ftm::stamp(1323734400 + i*5*60);
		for (unsigned int j=0;j<arenaN;j++) outfile << "\t" << arrblkN[j*(76*24*12) + i];
		outfile << endl;
	};
	outfile.close();

	outfile.open("blkN.txt", ios::out);
	for (unsigned int i=0;i<(76*24*12);i++) {
		outfile << "'" << Ftm::stamp(1323734400 + i*5*60);
		for (unsigned int j=0;j<arenaN;j++) outfile << "\t" << blkN[j*(76*24*12) + i];
		outfile << endl;
	};
	outfile.close();

	// --- boil down to weekdays (skip first and last days of timetable period)
	avgWkdayDepN.resize(arenaN * 7*24*12, 0.0);
	avgWkdayArrN.resize(arenaN * 7*24*12, 0.0);
	avgWkdayN.resize(arenaN * 7*24*12, 0.0);

	for (unsigned int i=0;i<7;i++) {
		// chart begins on Wed (Dec 14, 2011)

		N = 0; // counts number of week days with index i within timetable period

		for (unsigned int j=((i+1)*24*12);j<((76-1)*24*12);j+=7*24*12) {
			for (unsigned int k=0;k<(24*12);k++) {
				for (unsigned int l=0;l<arenaN;l++) {
					avgWkdayDepN[l*7*24*12 + i*24*12 + k] += depblkN[l*76*24*12 + j + k];
					avgWkdayArrN[l*7*24*12 + i*24*12 + k] += arrblkN[l*76*24*12 + j + k];
					avgWkdayN[l*7*24*12 + i*24*12 + k] += blkN[l*76*24*12 + j + k];
				};
			};

			N++;
		};

		for (unsigned int k=0;k<(24*12);k++) {
			for (unsigned int l=0;l<arenaN;l++) {
				avgWkdayDepN[l*7*24*12 + i*24*12 + k] /= (double) N;
				avgWkdayArrN[l*7*24*12 + i*24*12 + k] /= (double) N;
				avgWkdayN[l*7*24*12 + i*24*12 + k] /= (double) N;
			};
		};
	};

	// -- dump results
	outfile.open("avgWkdayDepN.txt", ios::out);
	for (unsigned int i=0;i<(7*24*12);i++) {
		for (unsigned int j=0;j<arenaN;j++) {
			if (j != 0) outfile << "\t";
			outfile << avgWkdayDepN[j*(7*24*12) + i];
		};
		outfile << endl;
	};
	outfile.close();

	outfile.open("avgWkdayArrN.txt", ios::out);
	for (unsigned int i=0;i<(7*24*12);i++) {
		for (unsigned int j=0;j<arenaN;j++) {
			if (j != 0) outfile << "\t";
			outfile << avgWkdayArrN[j*(7*24*12) + i];
		};
		outfile << endl;
	};
	outfile.close();

	outfile.open("avgWkdayN.txt", ios::out);
	for (unsigned int i=0;i<(7*24*12);i++) {
		for (unsigned int j=0;j<arenaN;j++) {
			if (j != 0) outfile << "\t";
			outfile << avgWkdayN[j*(7*24*12) + i];
		};
		outfile << endl;
	};
	outfile.close();

	// --- boil down to 24h periods (skip first and last days of timetable period)
	avgDayDepN.resize(arenaN * 24*12, 0.0);
	avgDayArrN.resize(arenaN * 24*12, 0.0);
	avgDayN.resize(arenaN * 24*12, 0.0);

	N = 0; // counts number of days taken into account within timetable period

	for (unsigned int i=1;i<(76-1);i++) {

		for (unsigned int k=0;k<(24*12);k++) {
			for (unsigned int l=0;l<arenaN;l++) {
				avgDayDepN[l*24*12 + k] += depblkN[l*76*24*12 + i*24*12 + k];
				avgDayArrN[l*24*12 + k] += arrblkN[l*76*24*12 + i*24*12 + k];
				avgDayN[l*24*12 + k] += blkN[l*76*24*12 + i*24*12 + k];
			};
		};

		N++;
	};

	for (unsigned int k=0;k<(24*12);k++) {
		for (unsigned int l=0;l<arenaN;l++) {
			avgDayDepN[l*24*12 + k] /= (double) N;
			avgDayArrN[l*24*12 + k] /= (double) N;
			avgDayN[l*24*12 + k] /= (double) N;
		};
	};

	// -- dump results
	outfile.open("avgDayDepN.txt", ios::out);
	for (unsigned int i=0;i<(24*12);i++) {
		for (unsigned int j=0;j<arenaN;j++) {
			if (j != 0) outfile << "\t";
			outfile << avgDayDepN[j*(24*12) + i];
		};
		outfile << endl;
	};
	outfile.close();

	outfile.open("avgDayArrN.txt", ios::out);
	for (unsigned int i=0;i<(24*12);i++) {
		for (unsigned int j=0;j<arenaN;j++) {
			if (j != 0) outfile << "\t";
			outfile << avgDayArrN[j*(24*12) + i];
		};
		outfile << endl;
	};
	outfile.close();

	outfile.open("avgDayN.txt", ios::out);
	for (unsigned int i=0;i<(24*12);i++) {
		for (unsigned int j=0;j<arenaN;j++) {
			if (j != 0) outfile << "\t";
			outfile << avgDayN[j*(24*12) + i];
		};
		outfile << endl;
	};
	outfile.close();

	// --- categorize continental arena's 17, 19, 21 routes by leg-loc visibility percentage
	ListBrlyRMLegMLocation legRlocs;
	BrlyRMLegMLocation* legRloc = NULL;

	double lastphi;

	vector<unsigned int> phiix0s;
	vector<unsigned int> phiix1s;

	unsigned int phiix;

	vector<double> phi0;
	vector<double> phi1;

	BrlyMLeg* leg = NULL;

	phiix0s.resize(refsLegCo3Go.size(), 0);
	phiix1s.resize(refsLegCo3Go.size(), 0);

	phiix = 0;

	for (unsigned int i=0;i<refsLegCo3Go.size();i++) {
		dbsbrly->tblbrlyrmlegmlocation->loadRstBySQL("SELECT * FROM TblBrlyRMLegMLocation WHERE refBrlyMLeg = " + to_string(refsLegCo3Go[i]) + " ORDER BY x1VisLegphi0 ASC", false, legRlocs);

		phiix0s[i] = phiix;

		// as all routes begin and end in airports, coverage at phi=0 is guaranteed
		lastphi = 0.0;

		for (unsigned int j=0;j<legRlocs.nodes.size();j++) {
			legRloc = legRlocs.nodes[j];

			if (legRloc->x1VisLegphi0 <= lastphi) {
				if (legRloc->x1VisLegphi1 > lastphi) lastphi = legRloc->x1VisLegphi1;

			} else {
				// un-covered from lastphi to visibility begin
				phi0.push_back(lastphi);
				phi1.push_back(legRloc->x1VisLegphi0);
				phiix++;

				lastphi = legRloc->x1VisLegphi1;
			};
		};

		phiix1s[i] = phiix;
	};

	// -- dump results
	outfile.open("co3coverage.txt", ios::out);
	for (unsigned int i=0;i<refsLegCo3Go.size();i++) {
		outfile << refsLegCo3Go[i] << "\t" << StubBrly::getStubLegShort(dbsbrly, refsLegCo3Go[i]) << "\t";

		if (phiix0s[i] == phiix1s[i]) outfile << 1.0 << endl;
		else {
			d = 0.0;
			for (unsigned int j=phiix0s[i];j<phiix1s[i];j++) d += phi1[j]-phi0[j];
			if (dbsbrly->tblbrlymleg->loadRecByRef(refsLegCo3Go[i], &leg)) {
				d /= leg->deltaphi;
				delete leg;
			};
			outfile << (1.0-d) << endl;
		};
	};
	outfile.close();

	return false;
	// IP handleStats1 --- IEND
	return retval;
};

bool CrdBrlyTtb::handleValidate(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleValidate --- IBEGIN
	ubigint ref;

	ListBrlyMFlight flts;
	BrlyMFlight* flt = NULL;

	BrlyMFaflight* faf = NULL;

	ubigint refLeg;
	BrlyMLeg* leg = NULL;

	vector<ubigint> refsLeg;
	vector<ubigint> refsCLeg;
	vector<double> dphis;
	vector<double> avgvs;
	vector<double> avgdts;

	double d, d2;
	unsigned int N, N2;

	fstream outfile;

	// --- load and traverse flights
	dbsbrly->tblbrlymflight->loadRstBySQL("SELECT * FROM TblBrlyMFlight WHERE refBrlyMTimetable = " + to_string(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFTTB, jref)) + " ORDER BY refBrlyMLeg ASC, start ASC", false, flts);

	refLeg = 0;
	d = 0.0;
	d2 = 0.0;
	N = 0;
	N2 = 0;

	for (unsigned int i=0;i<flts.nodes.size();i++) {
		flt = flts.nodes[i];

		if (flt->refBrlyMLeg != refLeg) {
			// finalize previous leg
			if (i != 0) {
				d /= (double) N;
				avgvs.push_back(d);

				if (N2 == 0) {
					avgdts.push_back(0.0);
				} else {
					d2 /= (double) N2;
					avgdts.push_back(d2);
				};
			};

			// initialize for new leg
			refLeg = flt->refBrlyMLeg;
			refsLeg.push_back(refLeg);
			refsCLeg.push_back(0);
			dphis.push_back(0.0);

			// determine leg angular distance
			if (dbsbrly->tblbrlymleg->loadRecByRef(refLeg, &leg)) {
				refsCLeg[refsCLeg.size()-1] = leg->refBrlyCLeg;
				dphis[dphis.size()-1] = leg->deltaphi;
				delete leg;

			} else {
				cout << "unable to find route with ref " << refLeg << endl;
			};

			d = 0.0;
			d2 = 0.0;
			N = 0;
			N2 = 0;
		};

		d += dphis[dphis.size()-1] / ((double) (flt->stop - flt->start));
		N++;

		if (flt->refBrlyMFaflight != 0) {
			if (dbsbrly->tblbrlymfaflight->loadRecByRef(flt->refBrlyMFaflight, &faf)) {
				if ((faf->actualdeparturetime != 0) && (faf->actualarrivaltime != 0)) {
					if (faf->actualarrivaltime > faf->actualdeparturetime) {
						d2 += ((double) (faf->actualarrivaltime - faf->actualdeparturetime));
						N2++;
					};
				};

				delete faf;
			};
		};
	};

	// finalize last leg
	if (N != 0) {
		d /= (double) N;
		avgvs.push_back(d);

		if (N2 == 0) {
			avgdts.push_back(0.0);
		} else {
			d2 /= (double) N2;
			avgdts.push_back(d2);
		};
	};

	// -- dump results
	outfile.open("avgvs.txt", ios::out);
	for (unsigned int i=0;i<refsLeg.size();i++) {
		outfile << refsLeg[i] << "\t" << StubBrly::getStubLegShort(dbsbrly, refsLeg[i]) << "\t" << dphis[i] << "\t" << avgvs[i];

		// find average velocity of inverse leg
		d = 0.0;
		if (dbsbrly->loadRefBySQL("SELECT ref FROM TblBrlyMLeg WHERE refBrlyCLeg = " + to_string(refsCLeg[i]) + " AND ref <> " + to_string(refsLeg[i]), ref)) {
			for (unsigned int j=0;j<refsLeg.size();j++) {
				if (refsLeg[j] == ref) {
					d = avgvs[j];
					break;
				};
			};
		};

		outfile << "\t" << d  << "\t" << avgdts[i] << endl;
	};
	outfile.close();

	return false;
	// IP handleValidate --- IEND
	return retval;
};

void CrdBrlyTtb::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdBrlyTtb::handleDpchAppDoClose(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	changeStage(dbsbrly, VecVSge::CLOSE);
};

void CrdBrlyTtb::handleDpchAppDoMitAppAbtClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsbrly, VecVSge::ALRBRLYABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdBrlyTtb::handleDpchAppDoMitCrdNewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	if (!dlgnew) {
		dlgnew = new DlgBrlyTtbNew(xchg, dbsbrly, jref, ixBrlyVLocale);
		statshr.jrefDlgnew = dlgnew->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdBrlyTtb::handleDpchAppDoMitCrdTrlClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	if (!dlgtrlorig) {
		dlgtrlorig = new DlgBrlyTtbTrlorig(xchg, dbsbrly, jref, ixBrlyVLocale);
		statshr.jrefDlgtrlorig = dlgtrlorig->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdBrlyTtb::handleDpchAppDoMitCrdIflClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	if (!dlgimpflt) {
		dlgimpflt = new DlgBrlyTtbImpflt(xchg, dbsbrly, jref, ixBrlyVLocale);
		statshr.jrefDlgimpflt = dlgimpflt->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdBrlyTtb::handleDpchAppBrlyAlert(
			DbsBrly* dbsbrly
			, DpchAppBrlyAlert* dpchappbrlyalert
			, DpchEngBrly** dpcheng
		) {
	if (ixVSge == VecVSge::ALRBRLYABT) {
		changeStage(dbsbrly, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
};

void CrdBrlyTtb::handleTimer(
			DbsBrly* dbsbrly
			, const string& sref
		) {
	if (ixVSge == VecVSge::IMPIDLE) {
		changeStage(dbsbrly, nextIxVSge);
	} else if ((ixVSge == VecVSge::IMPORT) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.import.mon --- INSERT
	} else if ((ixVSge == VecVSge::SEGMENT) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.segment.mon --- INSERT
	};
};

void CrdBrlyTtb::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYDLGCLOSE) {
		call->abort = handleCallBrlyDlgClose(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSTATCHG) {
		call->abort = handleCallBrlyStatChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREFPRESET) {
		call->abort = handleCallBrlyRefPreSet(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool CrdBrlyTtb::handleCallBrlyDlgClose(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgimpflt) {
		delete dlgimpflt;
		dlgimpflt = NULL;
		statshr.jrefDlgimpflt = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgnew) {
		delete dlgnew;
		dlgnew = NULL;
		statshr.jrefDlgnew = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgtrlorig) {
		delete dlgtrlorig;
		dlgtrlorig = NULL;
		statshr.jrefDlgtrlorig = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

bool CrdBrlyTtb::handleCallBrlyStatChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD) && (pnlrec->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD)) pnllist->minimize(dbsbrly, true);
	return retval;
};

bool CrdBrlyTtb::handleCallBrlyRefPreSet(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecBrlyVPreset::PREBRLYREFTTB) {
		changeRef(dbsbrly, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbsbrly, true);
		else if ((jrefTrig == statshr.jrefDlgnew) && (refInv != 0)) {
			pnllist->qry->rerun(dbsbrly, true);
			pnllist->minimize(dbsbrly, true);
			pnlrec->regularize(dbsbrly, true);
		};
	};

	return retval;
};


