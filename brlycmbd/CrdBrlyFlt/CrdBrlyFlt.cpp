/**
  * \file CrdBrlyFlt.cpp
  * job handler for job CrdBrlyFlt (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "CrdBrlyFlt.h"

#include "CrdBrlyFlt_blks.cpp"

/******************************************************************************
 class CrdBrlyFlt
 ******************************************************************************/

CrdBrlyFlt::CrdBrlyFlt(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
			, const ubigint ref
		) : JobBrly(xchg, VecBrlyVJob::CRDBRLYFLT, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

	// IP constructor.cust1 --- IBEGIN
	con = false;
	seg = false;
	capacity = false;
	pReach = false;
	start = 0;
	stop = 0;

	refBrlyMFile = 0;
	vid = false;
	tIx = 0;
	frmrate = 0;
	fullsize = false;
	grayscale = false;
	altzmax = 0.0;
	// IP constructor.cust1 --- IEND

	// initialize according to ref
	changeRef(dbsbrly, jref, ((ref+1) == 0) ? 0 : ref, false);

	pnlrec = new PnlBrlyFltRec(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnlheadbar = new PnlBrlyFltHeadbar(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnllist = new PnlBrlyFltList(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	changeStage(dbsbrly, VecVSge::IDLE);

	xchg->addClstn(VecBrlyVCall::CALLBRLYDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdBrlyFlt::~CrdBrlyFlt() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* CrdBrlyFlt::getNewDpchEng(
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

void CrdBrlyFlt::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdBrlyFlt/" + VecBrlyVLocale::getSref(ixBrlyVLocale);
	continf.MtxCrdFlt = StubBrly::getStubFltStd(dbsbrly, xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFFLT, jref), ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void CrdBrlyFlt::changeRef(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	BrlyMFlight* rec = NULL;

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbsbrly, VecBrlyVCall::CALLBRLYLOG, jref, VecBrlyVPreset::VOID, 0, "CrdBrlyFlt", ref);
	xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFFLT, jref, ref);

	if (dbsbrly->tblbrlymflight->loadRecByRef(ref, &rec)) {
		xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFFAF, jref, rec->refBrlyMFaflight);
		xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFEQP, jref, rec->refBrlyMEquipment);

		delete rec;
	};

	refresh(dbsbrly, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));

	if (pnllist) pnllist->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFFLT, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFFLT, jrefTrig, notif);
};

void CrdBrlyFlt::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdBrlyFlt::changeStage(
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
				case VecVSge::COLLECT: leaveSgeCollect(dbsbrly); break;
				case VecVSge::COLDONE: leaveSgeColdone(dbsbrly); break;
				case VecVSge::PLOT: leaveSgePlot(dbsbrly); break;
				case VecVSge::PLTDONE: leaveSgePltdone(dbsbrly); break;
			};

			ixVSge = _ixVSge;
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::ALRBRLYABT: _ixVSge = enterSgeAlrbrlyabt(dbsbrly, reenter); break;
			case VecVSge::CLOSE: _ixVSge = enterSgeClose(dbsbrly, reenter); break;
			case VecVSge::COLLECT: _ixVSge = enterSgeCollect(dbsbrly, reenter); break;
			case VecVSge::COLDONE: _ixVSge = enterSgeColdone(dbsbrly, reenter); break;
			case VecVSge::PLOT: _ixVSge = enterSgePlot(dbsbrly, reenter); break;
			case VecVSge::PLTDONE: _ixVSge = enterSgePltdone(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint CrdBrlyFlt::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdBrlyFlt::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdBrlyFlt::enterSgeAlrbrlyabt(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::ALRBRLYABT;
	nextIxVSge = VecVSge::IDLE;
	xchg->submitDpch(AlrBrly::prepareAlrAbt(jref, ixBrlyVLocale, feedFMcbAlert)); // IP enterSgeAlrbrlyabt --- LINE
	return retval;
};

void CrdBrlyFlt::leaveSgeAlrbrlyabt(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeAlrbrlyabt --- INSERT
};

uint CrdBrlyFlt::enterSgeClose(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CLOSE;
	nextIxVSge = retval;
	xchg->triggerIxCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDCLOSE, jref, VecBrlyVCard::CRDBRLYFLT);
	return retval;
};

void CrdBrlyFlt::leaveSgeClose(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeClose --- INSERT
};

uint CrdBrlyFlt::enterSgeCollect(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::COLLECT;
	nextIxVSge = VecVSge::COLDONE;

	clearInvs();
	// IP enterSgeCollect --- IBEGIN
	const uint fullheight = 720/4;
	const uint fullwidth = 1440/4;

	double phi0, phi1;
	double theta0, theta1;
	bool pacctr = false;

	if (arena.compare("to1") == 0) {
		phi0 = -140.75; phi1 = 39.25;
		theta0 = 7; theta1 = 83.25;
	} else if (arena.compare("to2") == 0) {
		phi0 = -82.75; phi1 = 19;
		theta0 = -55.75; theta1 = 61;
	} else if (arena.compare("to3") == 0) {
		phi0 = 94; phi1 = -74;
		theta0 = -1.75; theta1 = 83.5;
		pacctr = true;
	} else if (arena.compare("to4") == 0) {
		phi0 = -164.75; phi1 = -74;
		theta0 = 12.75; theta1 = 53.25;
		pacctr = true;
	} else if (arena.compare("ico1") == 0) {
		phi0 = -19.5; phi1 = 52;
		theta0 = -38.25; theta1 = 62;
	} else if (arena.compare("ico2") == 0) {
		phi0 = -12.5; phi1 = 145;
		theta0 = 28.75; theta1 = 83;
	} else if (arena.compare("ico3") == 0) {
		phi0 = -130; phi1 = -33.25;
		theta0 = -57.25; theta1 = 63;
	} else if (arena.compare("co1") == 0) {
		phi0 = -25; phi1 = 55;
		theta0 = 33; theta1 = 73.5;
	} else if (arena.compare("co2") == 0) {
		phi0 = -128.25; phi1 = -67;
		theta0 = 21.5; theta1 = 51.5;
	} else if (arena.compare("co3") == 0) {
		phi0 = 72.75; phi1 = 141;
		theta0 = 14.25; theta1 = 55.25;
	} else {
		phi0 = 0.0; phi1 = 0.0;
		theta0 = 0.0; theta1 = 0.0;
	};

	addInv(new DpchInvBrlyDnsmapCollect(0, 0, capacity, con, dt, !con, fullheight, fullwidth, !seg, pacctr, phi0, phi1, pReach, seg,
				arena, srefsKEqptype, start, stop, theta0, theta1));
	// IP enterSgeCollect --- IEND
	submitInvs(dbsbrly, retval, retval);
	return retval;
};

void CrdBrlyFlt::leaveSgeCollect(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCollect --- INSERT
};

uint CrdBrlyFlt::enterSgeColdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::COLDONE;
	nextIxVSge = VecVSge::IDLE;
	// IP enterSgeColdone --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
	// IP enterSgeColdone --- IEND
	retval = nextIxVSge;
	return retval;
};

void CrdBrlyFlt::leaveSgeColdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeColdone --- INSERT
};

uint CrdBrlyFlt::enterSgePlot(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PLOT;
	nextIxVSge = VecVSge::PLTDONE;

	clearInvs();
	// IP enterSgePlot --- IBEGIN
	if (vid) {
		addInv(new DpchInvBrlyDnsmapVideo(0, 0, altzmax, frmrate, fullsize, grayscale, refBrlyMFile));
	} else {
		addInv(new DpchInvBrlyDnsmapFrame(0, 0, altzmax, fullsize, grayscale, refBrlyMFile, tIx));
	};
	// IP enterSgePlot --- IEND
	submitInvs(dbsbrly, retval, retval);
	return retval;
};

void CrdBrlyFlt::leaveSgePlot(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgePlot --- INSERT
};

uint CrdBrlyFlt::enterSgePltdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PLTDONE;
	nextIxVSge = VecVSge::IDLE;
	// IP enterSgePltdone --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
	// IP enterSgePltdone --- IEND
	retval = nextIxVSge;
	return retval;
};

void CrdBrlyFlt::leaveSgePltdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgePltdone --- INSERT
};

string CrdBrlyFlt::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::PLOT) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::COLLECT) retval = "collecting data for time-resolved density map";
			else if (ixVSge == VecVSge::PLOT) retval = "plotting density map";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::COLLECT) retval = "sammle Daten f\\u00fcr zeitaufgel\\u00f6ste Dichtekarte";
			else if (ixVSge == VecVSge::PLOT) retval = "plotte Dichtekarte";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

void CrdBrlyFlt::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tdnscollect" << endl;
			cout << "\tdnsplot" << endl;
		} else if (req->cmd == "dnscollect") {
			req->retain = handleDnscollect(dbsbrly);

		} else if (req->cmd == "dnsplot") {
			req->retain = handleDnsplot(dbsbrly);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYINIT) {
			handleDpchAppBrlyInit(dbsbrly, (DpchAppBrlyInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsbrly, &(req->dpcheng));
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
	};
};

bool CrdBrlyFlt::handleDnscollect(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleDnscollect --- IBEGIN
	ListBrlyMPlntype ptys;
	BrlyMPlntype* pty = NULL;

	Feed feed;
	Feeditem* fi = NULL;
	set<unsigned int> icsFeed;

	string s, s2;
	vector<string> ss;

	bool found;

	// - connections vs. flights
	cout << "\tconsider flights with connections instead of flights (y/n)?" << endl;
	while (true) {
		cout << "\tyour input: "; cin >> s;

		con = (s.compare("y") == 0);
		if ((s.compare("y") == 0) || (s.compare("n") == 0)) break;
	};

	// - segments vs. legs
	cout << "\tuse segments instead of legs (y/n)?" << endl;
	while (true) {
		cout << "\tyour input: "; cin >> s;

		seg = (s.compare("y") == 0);
		if ((s.compare("y") == 0) || (s.compare("n") == 0)) break;
	};

	// - plane capacity
	cout << "\tfactor in plane capacity (y/n)?" << endl;
	while (true) {
		cout << "\tyour input: "; cin >> s;

		capacity = (s.compare("y") == 0);
		if ((s.compare("y") == 0) || (s.compare("n") == 0)) break;
	};

	if (con) {
		// - reachability statistics
		cout << "\tgenerate reachability statistics (y/n)?" << endl;
		while (true) {
			cout << "\tyour input: "; cin >> s;

			pReach = (s.compare("y") == 0);
			if ((s.compare("y") == 0) || (s.compare("n") == 0)) break;
		};
	};

	// - arena selection
	cout << "\tlist of arenas to select from:" << endl;
	cout << "\t\ttransoceanic (to1/to2/to3/to4)" << endl;
	cout << "\t\tother inter-continental (ico1/ico2/ico3)" << endl;
	cout << "\t\tcontinental (co1/co2/co3)" << endl;

	while (true) {
		cout << "\tyour choice: "; cin >> s;

		arena = s;
		if ((s.compare("to1") == 0) || (s.compare("to2") == 0) || (s.compare("to3") == 0) || (s.compare("to4") == 0)
				|| (s.compare("ico1") == 0) || (s.compare("ico2") == 0) || (s.compare("ico3") == 0)
				|| (s.compare("co1") == 0) || (s.compare("co2") == 0) || (s.compare("co3") == 0)) break;
	};

	// - equipment type filter
	dbsbrly->tblbrlymplntype->loadRstBySQL("SELECT * FROM TblBrlyMPlntype", false, ptys);

	for (unsigned int i=0;i<ptys.nodes.size();i++) {
		pty = ptys.nodes[i];

		found = false;
		for (unsigned int j=0;j<feed.size();j++) {
			fi = feed.nodes[j];

			if (fi->sref == pty->srefBrlyKEqptype) {
				found = true;
				break;
			};
		};

		if (!found) feed.appendIxSrefTitles(feed.size(), pty->srefBrlyKEqptype, dbsbrly->getKlstTitleBySref(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, pty->srefBrlyKEqptype, ixBrlyVLocale));
	};

	cout << "\tselect equipment types by entering their identifiers. Type 'done' when finished." << endl;

	while (true) {
		cout << "\t\tlist of equipment types:" << endl;

		for (unsigned int i=0;i<feed.size();i++) {
			fi = feed.nodes[i];

			cout << "\t\t\t";
			if (icsFeed.find(i) == icsFeed.end()) cout << "o\t"; else cout << "x\t";
			cout << fi->sref << "\t" << fi->Title1 << endl;
		};

		cout << "\tyour input: ";
		cin >> s;

		if (s == "done") {
			break;

		} else {
			for (unsigned int i=0;i<feed.size();i++) {
				fi = feed.nodes[i];

				if (fi->sref == s) {
					if (icsFeed.find(i) == icsFeed.end()) icsFeed.insert(i);
					else icsFeed.erase(i);

					break;
				};
			};
		};
	};

	if (icsFeed.size() == feed.size()) srefsKEqptype = "";
	else {
		for (set<unsigned int>::iterator it=icsFeed.begin();it!=icsFeed.end();it++) ss.push_back(feed.nodes[*it]->sref);
		StrMod::vectorToString(ss, srefsKEqptype);
	};

	// - time span and granularity
	start = 0;
	stop = 0;
	dt = 0;

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

	while (dt == 0) {
		cout << "\ttime granularity (hh:mm:ss): ";
		cin >> s;
		dt = Ftm::invtime(s);
	};

	changeStage(dbsbrly, VecVSge::COLLECT);

	return(ixVSge != VecVSge::IDLE);
	// IP handleDnscollect --- IEND
	return retval;
};

bool CrdBrlyFlt::handleDnsplot(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleDnsplot --- IBEGIN
	ListBrlyMFile fils;
	BrlyMFile* fil = NULL;

	string s;

	bool found;

	// - data file
	cout << "\tselect data file by its reference." << endl;

	dbsbrly->tblbrlymfile->loadRstBySQL("SELECT * FROM TblBrlyMFile WHERE osrefKContent = 'dnsmap' ORDER BY ref ASC", false, fils);

	while (true) {
		cout << "\t\tlist of data files:" << endl;

		for (unsigned int i=0;i<fils.nodes.size();i++) {
			fil = fils.nodes[i];

			cout << "\t\t\t";
			cout << fil->ref << "\t" << fil->Filename << "\t" << fil->Comment << endl;
		};

		cout << "\t\tyour input: ";
		cin >> s;

		refBrlyMFile = atoll(s.c_str());

		for (unsigned int i=0;i<fils.nodes.size();i++) {
			fil = fils.nodes[i];

			if (fil->ref == refBrlyMFile) {
				found = true;
				break;
			};
		};

		if (found) break;
	};

	// - video vs. single frame
	cout << "\tgenerate frame sequence / video (y/n)?" << endl;
	while (true) {
		cout << "\tyour input: "; cin >> s;

		vid = (s.compare("y") == 0);
		if ((s.compare("y") == 0) || (s.compare("n") == 0)) break;
	};

	// - index in time dimension
	if (!vid) {
		cout << "\tindex in time dimension: " << endl;
		cin >> s;
		tIx = atoi(s.c_str());
	};

	// - frame rate
	if (vid) {
		cout << "\tframe rate [fps]: ";
		cin >> s;
		frmrate = atoi(s.c_str());
	};

	// - full size vs. size as per data file
	cout << "\tgenerate full size frames (y/n)?" << endl;
	while (true) {
		cout << "\tyour input: "; cin >> s;

		fullsize = (s.compare("y") == 0);
		if ((s.compare("y") == 0) || (s.compare("n") == 0)) break;
	};

	// - grayscale vs. color
	cout << "\tgenerate grayscale frames (y/n)?" << endl;
	while (true) {
		cout << "\tyour input: "; cin >> s;

		grayscale = (s.compare("y") == 0);
		if ((s.compare("y") == 0) || (s.compare("n") == 0)) break;
	};

	// - custom max. z value
	cout << "\tuse custom max. value (type value, 'n' else)?" << endl;
	cout << "\tyour input: "; cin >> s;

	if (s.compare("n") == 0) altzmax = 1.0e36;
	else altzmax = atof(s.c_str());

	changeStage(dbsbrly, VecVSge::PLOT);

	return(ixVSge != VecVSge::IDLE);
	// IP handleDnsplot --- IEND
	return retval;
};

void CrdBrlyFlt::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdBrlyFlt::handleDpchAppDoClose(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	changeStage(dbsbrly, VecVSge::CLOSE);
};

void CrdBrlyFlt::handleDpchAppDoMitAppAbtClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsbrly, VecVSge::ALRBRLYABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdBrlyFlt::handleDpchAppBrlyAlert(
			DbsBrly* dbsbrly
			, DpchAppBrlyAlert* dpchappbrlyalert
			, DpchEngBrly** dpcheng
		) {
	if (ixVSge == VecVSge::ALRBRLYABT) {
		changeStage(dbsbrly, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
};

void CrdBrlyFlt::handleCall(
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

bool CrdBrlyFlt::handleCallBrlyDlgClose(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlyDlgClose --- INSERT
	return retval;
};

bool CrdBrlyFlt::handleCallBrlyStatChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD) && (pnlrec->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD)) pnllist->minimize(dbsbrly, true);
	return retval;
};

bool CrdBrlyFlt::handleCallBrlyRefPreSet(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecBrlyVPreset::PREBRLYREFFLT) {
		changeRef(dbsbrly, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbsbrly, true);
	};

	return retval;
};


