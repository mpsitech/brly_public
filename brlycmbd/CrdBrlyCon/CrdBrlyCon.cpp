/**
  * \file CrdBrlyCon.cpp
  * job handler for job CrdBrlyCon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "CrdBrlyCon.h"

#include "CrdBrlyCon_blks.cpp"
#include "CrdBrlyCon_evals.cpp"

/******************************************************************************
 class CrdBrlyCon
 ******************************************************************************/

CrdBrlyCon::CrdBrlyCon(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
			, const ubigint ref
		) : JobBrly(xchg, VecBrlyVJob::CRDBRLYCON, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	dlgnew = NULL;
	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

	// IP constructor.cust1 --- INSERT

	// initialize according to ref
	changeRef(dbsbrly, jref, ((ref+1) == 0) ? 0 : ref, false);

	pnlrec = new PnlBrlyConRec(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnlheadbar = new PnlBrlyConHeadbar(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnllist = new PnlBrlyConList(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	if ((ref+1) == 0) {
		dlgnew = new DlgBrlyConNew(xchg, dbsbrly, jref, ixBrlyVLocale);
		statshr.jrefDlgnew = dlgnew->jref;
	};

	changeStage(dbsbrly, VecVSge::IDLE);

	xchg->addClstn(VecBrlyVCall::CALLBRLYDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdBrlyCon::~CrdBrlyCon() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void CrdBrlyCon::wrBgseg(
			fstream& outfile
			, const unsigned int start
			, const unsigned int mode
			, double x
			, const double y
			, double width
			, const double height
		) {
	x = (x-start)/60;
	width = width/60;

	outfile << "\t\t\t\t\t\t\t\t<rect class=\"";

	switch (mode) {
		case Bgmode::ALONE: outfile << "alone"; break;
		case Bgmode::NCTD: outfile << "nctd"; break;
		case Bgmode::CTDFWD: outfile << "ctdfwd"; break;
		case Bgmode::CTDBWD: outfile << "ctdbwd"; break;
		case Bgmode::CTDBOTH: outfile << "ctdboth"; break;
	};

	outfile << "\" x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\"/>" << endl;
};

double CrdBrlyCon::radToDeg(
			double _rad																					//! angle in degrees (0¡ .. 360¡)
		) {
	return(180.0*_rad/pi);
};
// IP cust --- IEND
DpchEngBrly* CrdBrlyCon::getNewDpchEng(
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

void CrdBrlyCon::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdBrlyCon/" + VecBrlyVLocale::getSref(ixBrlyVLocale);
	continf.MtxCrdCon = StubBrly::getStubConStd(dbsbrly, xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref), ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbsbrly);
	statshr.MitCrdNewAvail = evalMitCrdNewAvail(dbsbrly);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void CrdBrlyCon::changeRef(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixBrlyVAccess;
	xchg->triggerIxRefToIxCall(dbsbrly, VecBrlyVCall::CALLBRLYACCESS, jref, VecBrlyVMaintable::TBLBRLYMCONNECTION, ref, ixBrlyVAccess);

	if (ixBrlyVAccess != VecBrlyVAccess::NONE) {
		xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXACC, jref, ixBrlyVAccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbsbrly, VecBrlyVCall::CALLBRLYLOG, jref, VecBrlyVPreset::VOID, 0, "CrdBrlyCon", ref);
		xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref, ref);

		refresh(dbsbrly, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));

		if (pnllist) pnllist->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFCON, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFCON, jrefTrig, notif);
	};
};

void CrdBrlyCon::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdBrlyCon::changeStage(
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
				case VecVSge::CRGIDLE: leaveSgeCrgidle(dbsbrly); break;
				case VecVSge::CORRGEN: leaveSgeCorrgen(dbsbrly); break;
				case VecVSge::CORRCALC: leaveSgeCorrcalc(dbsbrly); break;
				case VecVSge::CRGDONE: leaveSgeCrgdone(dbsbrly); break;
				case VecVSge::CONGEN: leaveSgeCongen(dbsbrly); break;
				case VecVSge::CNGDONE: leaveSgeCngdone(dbsbrly); break;
				case VecVSge::CALC1: leaveSgeCalc1(dbsbrly); break;
				case VecVSge::CALC2: leaveSgeCalc2(dbsbrly); break;
				case VecVSge::CALC3: leaveSgeCalc3(dbsbrly); break;
				case VecVSge::CALC4: leaveSgeCalc4(dbsbrly); break;
				case VecVSge::DONE: leaveSgeDone(dbsbrly); break;
			};

			ixVSge = _ixVSge;
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::ALRBRLYABT: _ixVSge = enterSgeAlrbrlyabt(dbsbrly, reenter); break;
			case VecVSge::CLOSE: _ixVSge = enterSgeClose(dbsbrly, reenter); break;
			case VecVSge::CRGIDLE: _ixVSge = enterSgeCrgidle(dbsbrly, reenter); break;
			case VecVSge::CORRGEN: _ixVSge = enterSgeCorrgen(dbsbrly, reenter); break;
			case VecVSge::CORRCALC: _ixVSge = enterSgeCorrcalc(dbsbrly, reenter); break;
			case VecVSge::CRGDONE: _ixVSge = enterSgeCrgdone(dbsbrly, reenter); break;
			case VecVSge::CONGEN: _ixVSge = enterSgeCongen(dbsbrly, reenter); break;
			case VecVSge::CNGDONE: _ixVSge = enterSgeCngdone(dbsbrly, reenter); break;
			case VecVSge::CALC1: _ixVSge = enterSgeCalc1(dbsbrly, reenter); break;
			case VecVSge::CALC2: _ixVSge = enterSgeCalc2(dbsbrly, reenter); break;
			case VecVSge::CALC3: _ixVSge = enterSgeCalc3(dbsbrly, reenter); break;
			case VecVSge::CALC4: _ixVSge = enterSgeCalc4(dbsbrly, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint CrdBrlyCon::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdBrlyCon::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdBrlyCon::enterSgeAlrbrlyabt(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::ALRBRLYABT;
	nextIxVSge = VecVSge::IDLE;
	xchg->submitDpch(AlrBrly::prepareAlrAbt(jref, ixBrlyVLocale, feedFMcbAlert)); // IP enterSgeAlrbrlyabt --- LINE
	return retval;
};

void CrdBrlyCon::leaveSgeAlrbrlyabt(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeAlrbrlyabt --- INSERT
};

uint CrdBrlyCon::enterSgeClose(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CLOSE;
	nextIxVSge = retval;
	xchg->triggerIxCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDCLOSE, jref, VecBrlyVCard::CRDBRLYCON);
	return retval;
};

void CrdBrlyCon::leaveSgeClose(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeClose --- INSERT
};

uint CrdBrlyCon::enterSgeCrgidle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CRGIDLE;
	nextIxVSge = VecVSge::CORRGEN;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
	// IP enterSgeCrgidle --- INSERT
	return retval;
};

void CrdBrlyCon::leaveSgeCrgidle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCrgidle --- INSERT
};

uint CrdBrlyCon::enterSgeCorrgen(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CORRGEN;
	nextIxVSge = VecVSge::CORRCALC;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeCorrgen --- IBEGIN
	vector<ubigint> refs;

	vector<string> arenas;

	bool ic;
	vector<bool> ics;

	vector<ubigint> refsLeg1;
	vector<ubigint> refsLeg2;

	BrlyMLeg* rt = NULL;
	BrlyMLeg* corr = NULL;

	cout << "\tlist of arenas to select from:" << endl;
	cout << "\t\ttransoceanic (to1/to2/to3/to4)" << endl;
	cout << "\t\tother inter-continental (ico1/ico2/ico3/ico4)" << endl;
	cout << "\t\tcontinental (co1/co2/co3)" << endl;
	cout << "\t\tnon-continental (noco)" << endl;
	cout << "\t\tall" << endl;

	cout << "\tyour choice: ";
	cin >> arena;

	if ((arena.compare("noco") == 0) || (arena.compare("all") == 0)) {
		arenas.push_back("to1");
		arenas.push_back("to2");
		arenas.push_back("to3");
		arenas.push_back("to4");

		arenas.push_back("ico1");
		arenas.push_back("ico2");
		arenas.push_back("ico3");
//		arenas.push_back("ico4");

		if (arena.compare("all") == 0) {
			arenas.push_back("co1");
			arenas.push_back("co2");
			arenas.push_back("co3");
		};

	} else {
		arenas.push_back(arena);
	};

	// - load routes of the selected arenas
	rts.clear();
	corrs.clear();

	for (unsigned int i=0;i<arenas.size();i++) {
		arena = arenas[i];

		refsLeg1.resize(0);
		refsLeg2.resize(0);

		ic = ((arena.substr(0,2).compare("to") == 0) || (arena.substr(0,3).compare("ico") == 0));
		Brly::loadLegsByArena(dbsbrly, arena, true, ic, false, refsLeg1, refsLeg2);

		dbsbrly->tblbrlymleg->loadRstByRefs(refsLeg1, true, rts);
		dbsbrly->tblbrlymleg->loadRstByRefs(refsLeg2, true, rts);

		ics.resize(rts.nodes.size(), ic);
	};

	// - duplicate routes into communication corridors
	for (unsigned int i=0;i<rts.nodes.size();i++) {
		rt = rts.nodes[i];
		ic = ics[i];

		corr = new BrlyMLeg(*rt);
		corr->ref = 0;
		corr->ixVBasetype = VecBrlyVMLegBasetype::CORR;
		corr->refBrlyCLeg = 0;

		// wider corridors for intercontinental communication
		if (ic) {
			corr->alpha = radToDeg(0.5*xchg->stgbrlygeometry.corrwidth2 / xchg->stgbrlygeometry.earthradius);
		} else {
			corr->alpha = radToDeg(0.5*xchg->stgbrlygeometry.corrwidth1 / xchg->stgbrlygeometry.earthradius);
		};

		corr->Calcdone = false;

		dbsbrly->tblbrlymleg->insertRec(corr);
		corrs.nodes.push_back(corr);
	};
	// IP enterSgeCorrgen --- IEND
	retval = nextIxVSge;
	return retval;
};

void CrdBrlyCon::leaveSgeCorrgen(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeCorrgen --- INSERT
};

uint CrdBrlyCon::enterSgeCorrcalc(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CORRCALC;
	nextIxVSge = VecVSge::CRGDONE;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeCorrcalc --- IBEGIN
	vector<ubigint> refs;

	BrlyMLeg* corr = NULL;

	// -- invoke BrlyBaseLegloc and BrlyBaseLegleg (block size: 256)
	for (unsigned int i=0;i<corrs.nodes.size();i++) {
		corr = corrs.nodes[i];

		refs.push_back(corr->ref);
		
		if ( (refs.size() == 256) || (i == (corrs.nodes.size()-1)) ) {
			// leg-loc
			addInv(new DpchInvBrlyBaseLegloc(0, 0, true, false, 0, 0, refs, {}));

			// leg-leg
			addInv(new DpchInvBrlyBaseLegleg(0, 0, true, false, 0, 0, refs));
			addInv(new DpchInvBrlyBaseLegleg(0, 0, false, true, 0, 0, refs));

			refs.resize(0);
		};
	};
	// IP enterSgeCorrcalc --- IEND
	submitInvs(dbsbrly, VecVSge::IDLE, retval);
	return retval;
};

void CrdBrlyCon::leaveSgeCorrcalc(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeCorrcalc --- INSERT
};

uint CrdBrlyCon::enterSgeCrgdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CRGDONE;
	nextIxVSge = retval;
	// IP enterSgeCrgdone --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
	// IP enterSgeCrgdone --- IEND
	return retval;
};

void CrdBrlyCon::leaveSgeCrgdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCrgdone --- IBEGIN
	BrlyMLeg* corr = NULL;

	for (unsigned int i=0;i<corrs.nodes.size();i++) {
		corr = corrs.nodes[i];

		corr->Calcdone = true;
		dbsbrly->tblbrlymleg->updateRec(corr);
	};
	// IP leaveSgeCrgdone --- IEND
};

uint CrdBrlyCon::enterSgeCongen(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CONGEN;
	nextIxVSge = VecVSge::CNGDONE;
	// IP enterSgeCongen --- IBEGIN

	BrlyMLeg* rt = NULL;
	BrlyMLeg* corr = NULL;

	ListBrlyMPlntype ptys;
	BrlyMPlntype* pty = NULL;

	Feed feed;
	Feeditem* fi = NULL;
	set<unsigned int> icsFeed;

	BrlyMFlight* flt = NULL;

	string srefsKEqptype;

	BrlyMEquipment* eqp = NULL;

	string s;
	vector<string> ss;

	bool found;

	cons.clear();

	// - ask for date
	cout << "\tenter date (DD-MM-YYYY): ";
	cin >> s;
	date = Ftm::invdate(s);

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

	// - set up connection for each flight along the route parallel to the corridor
	for (unsigned int i=0;i<rts.nodes.size();i++) {
		rt = rts.nodes[i];
		corr = corrs.nodes[i];

		// DEBUG
//		dbsbrly->tblbrlymflight->loadRstBySQL("SELECT * FROM TblBrlyMFlight WHERE refBrlyMLeg = " + to_string(rt->ref) + " AND start >= " + to_string(86400*date) + " AND start < "
//					+ to_string(86400*(date+1)-1) + " AND sref LIKE 'LH400\%'", false, flts);

		dbsbrly->tblbrlymflight->loadRstBySQL("SELECT * FROM TblBrlyMFlight WHERE refBrlyMLeg = " + to_string(rt->ref) + " AND start >= " + to_string(86400*date) + " AND start < "
					+ to_string(86400*(date+1)-1), false, flts);

		for (unsigned int j=0;j<flts.nodes.size();j++) {
			flt = flts.nodes[j];

			found = true;

			// equipment used on connection's flight needs to be in eqptype selection as well
			if (srefsKEqptype.length() > 0) {
				found = false;

				if (dbsbrly->tblbrlymequipment->loadRecByHktHku(VecBrlyVMEquipmentHkTbl::FLT, flt->ref, &eqp)) {
					found = StrMod::srefInSrefs(srefsKEqptype, eqp->srefBrlyKEqptype);
					delete eqp;
				};
			};

			if (found) dbsbrly->tblbrlymconnection->appendNewRecToRst(cons, NULL, 0, 0, flt->ref, corr->ref, flt->start, flt->stop, VecBrlyVMConnectionModel::SPL, 0, srefsKEqptype);
		};
	};

	flts.clear();
	// IP enterSgeCongen --- IEND
	retval = nextIxVSge;
	return retval;
};

void CrdBrlyCon::leaveSgeCongen(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCongen --- INSERT
};

uint CrdBrlyCon::enterSgeCngdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CNGDONE;
	nextIxVSge = retval;
	// IP enterSgeCngdone --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
	// IP enterSgeCngdone --- IEND
	return retval;
};

void CrdBrlyCon::leaveSgeCngdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCngdone --- INSERT
};

uint CrdBrlyCon::enterSgeCalc1(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CALC1;
	nextIxVSge = VecVSge::CALC2;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeCalc1 --- IBEGIN
	BrlyMConnection* con = NULL;

	for (unsigned int i=0;i<cons.nodes.size();i++) {
		con = cons.nodes[i];
		addInv(new DpchInvBrlyDynConflt(0, 0, con->ref));
	};
	// IP enterSgeCalc1 --- IEND
	submitInvs(dbsbrly, VecVSge::CNGDONE, retval);
	return retval;
};

void CrdBrlyCon::leaveSgeCalc1(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeCalc1 --- INSERT
};

uint CrdBrlyCon::enterSgeCalc2(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CALC2;
	nextIxVSge = VecVSge::CALC3;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeCalc2 --- IBEGIN
	// flight-flight/location visibility for each flight not yet calculated
	BrlyMConnection* con = NULL;

	ListBrlyRMConnectionMFlight conRflts;
	BrlyRMConnectionMFlight* conRflt = NULL;

	BrlyMFlight* flt = NULL;

	vector<ubigint> refs;

	bool found;

	for (unsigned int i=0;i<cons.nodes.size();i++) {
		con = cons.nodes[i];

		dbsbrly->tblbrlyrmconnectionmflight->loadRstByCon(con->ref, false, conRflts);
		for (unsigned int j=0;j<conRflts.nodes.size();j++) {
			conRflt = conRflts.nodes[j];

			if (dbsbrly->tblbrlymflight->loadRecByRef(conRflt->refBrlyMFlight, &flt)) {
				if (flt->Calcdone == true) {
					delete flt;

				} else {
					found = false;

					// make sure each flight is considered only once
					for (unsigned int k=0;k<flts.nodes.size();k++) {
						if (flts.nodes[k]->ref == flt->ref) {
							found = true;
							break;
						};
					};

					if (found) delete flt;
					else flts.nodes.push_back(flt);
				};
			};
		};
	};

	// - invoke BrlyDynFltfltloc (block size: 256)
	for (unsigned int i=0;i<flts.nodes.size();i++) {
		flt = flts.nodes[i];

		refs.push_back(flt->ref);
		
		if ( (refs.size() == 256) || (i == (flts.nodes.size()-1)) ) {
			addInv(new DpchInvBrlyDynFltfltloc(0, 0, refs));
			refs.resize(0);
		};
	};
	// IP enterSgeCalc2 --- IEND
	submitInvs(dbsbrly, VecVSge::CALC3, retval);
	return retval;
};

void CrdBrlyCon::leaveSgeCalc2(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeCalc2 --- IBEGIN
	BrlyMFlight* flt = NULL;

	for (unsigned int i=0;i<flts.nodes.size();i++) {
		flt = flts.nodes[i];

		flt->Calcdone = true;
		dbsbrly->tblbrlymflight->updateRec(flt);
	};
	// IP leaveSgeCalc2 --- IEND
};

uint CrdBrlyCon::enterSgeCalc3(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CALC3;
	nextIxVSge = VecVSge::CALC4;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeCalc3 --- IBEGIN
	BrlyMConnection* con = NULL;

	for (unsigned int i=0;i<cons.nodes.size();i++) {
		con = cons.nodes[i];
		addInv(new DpchInvBrlyDynEqplist(0, 0, con->ref));
	};
	// IP enterSgeCalc3 --- IEND
	submitInvs(dbsbrly, VecVSge::CNGDONE, retval);
	return retval;
};

void CrdBrlyCon::leaveSgeCalc3(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeCalc3 --- INSERT
};

uint CrdBrlyCon::enterSgeCalc4(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CALC4;
	nextIxVSge = VecVSge::DONE;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeCalc4 --- IBEGIN
	BrlyMConnection* con = NULL;

/// DEBUG
//	dbsbrly->executeQuery("DELETE FROM TblBrlyMRelay");
//	dbsbrly->executeQuery("DELETE FROM TblBrlyMNode");
//	dbsbrly->tblbrlymconnection->loadRstBySQL("SELECT * FROM TblBrlyMConnection WHERE ref > 16498", false, cons);
///

	for (unsigned int i=0;i<cons.nodes.size();i++) {
		con = cons.nodes[i];
		addInv(new DpchInvBrlyDynRly(0, 0, con->ref));
	};
	// IP enterSgeCalc4 --- IEND
	submitInvs(dbsbrly, VecVSge::CNGDONE, retval);
	return retval;
};

void CrdBrlyCon::leaveSgeCalc4(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeCalc4 --- INSERT
};

uint CrdBrlyCon::enterSgeDone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
	// IP enterSgeDone --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
	// IP enterSgeDone --- IEND
	return retval;
};

void CrdBrlyCon::leaveSgeDone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeDone --- INSERT
};

string CrdBrlyCon::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::CORRGEN) || (ixVSge == VecVSge::CORRCALC) || (ixVSge == VecVSge::CALC1) || (ixVSge == VecVSge::CALC2) || (ixVSge == VecVSge::CALC3) || (ixVSge == VecVSge::CALC4) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::CORRGEN) retval = "generating corridors (" + to_string(opN) + " operations prepared)";
			else if (ixVSge == VecVSge::CORRCALC) retval = "calculating corridor visibility (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC1) retval = "determining relevant flights (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC2) retval = "calculating flight visibility (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC3) retval = "calculating equipment line-up (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC4) retval = "calculating relays (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::CORRGEN) retval = "erzeuge Korridore (" + to_string(opN) + " Operationen vorbereitet)";
			else if (ixVSge == VecVSge::CORRCALC) retval = "berechne Sichtbarkeit von Korridoren (" + to_string(opNdone) + "/" + to_string(opN) + " Operationen ausgef\\u00fchrt, letzte: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC1) retval = "bestimme relevante Fl\\u00fcge (" + to_string(opNdone) + "/" + to_string(opN) + " Operationen ausgef\\u00fchrt, letzte: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC2) retval = "berechne Sichtbarkeit von Fl\\u00fcgen (" + to_string(opNdone) + "/" + to_string(opN) + " Operationen ausgef\\u00fchrt, letzte: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC3) retval = "berechne Aufreihung von Ger\\u00e4t (" + to_string(opNdone) + "/" + to_string(opN) + " Operationen ausgef\\u00fchrt, letzte: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC4) retval = "berechne Verbindungsketten (" + to_string(opNdone) + "/" + to_string(opN) + " Operationen ausgef\\u00fchrt, letzte: " + getOpsqkLast() + ")";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

void CrdBrlyCon::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tbargraph" << endl;
			cout << "\tcalc" << endl;
			cout << "\tcleanup1" << endl;
			cout << "\tcleanup2" << endl;
			cout << "\tcongen" << endl;
			cout << "\tcorrgen" << endl;
			cout << "\tlineup" << endl;
			cout << "\tpickup" << endl;
			cout << "\tstats2" << endl;
		} else if (req->cmd == "bargraph") {
			req->retain = handleBargraph(dbsbrly);

		} else if (req->cmd == "calc") {
			req->retain = handleCalc(dbsbrly);

		} else if (req->cmd == "cleanup1") {
			req->retain = handleCleanup1(dbsbrly);

		} else if (req->cmd == "cleanup2") {
			req->retain = handleCleanup2(dbsbrly);

		} else if (req->cmd == "congen") {
			req->retain = handleCongen(dbsbrly);

		} else if (req->cmd == "corrgen") {
			req->retain = handleCorrgen(dbsbrly);

		} else if (req->cmd == "lineup") {
			req->retain = handleLineup(dbsbrly);

		} else if (req->cmd == "pickup") {
			req->retain = handlePickup(dbsbrly);

		} else if (req->cmd == "stats2") {
			req->retain = handleStats2(dbsbrly);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYINIT) {
			handleDpchAppBrlyInit(dbsbrly, (DpchAppBrlyInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDNEWCLICK) {
					handleDpchAppDoMitCrdNewClick(dbsbrly, &(req->dpcheng));
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

bool CrdBrlyCon::handleBargraph(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleBargraph --- IBEGIN
	BrlyMConnection* con = NULL;
	BrlyMFlight* flt = NULL;

	fstream outfile;

	Rlystat* rlystat = NULL;

	unsigned int mode, newmode;

	unsigned int width, height;
	unsigned int x, y;

	unsigned int t;

	string s, s2;
	size_t ptr1, ptr2;

	cons.clear();
	flts.clear();

	// - ask for date
	cout << "\tenter date (DD-MM-YYYY): ";
	cin >> s;
	date = Ftm::invdate(s);

	// - ask for flights
	cout << "\tselect flights by entering their flight numbers. Type 'done' when finished." << endl;

	while (true) {
		cout << "\tyour input: ";
		cin >> s;

		if (s.compare("done") == 0) {
			break;

		} else {
			if (dbsbrly->tblbrlymflight->loadRecBySQL("SELECT * FROM TblBrlyMFlight WHERE sref LIKE '" + s + " %' AND start >= " + to_string(86400*date) + " AND start < " + to_string(86400*(date+1)-1), &flt)) {

				if (dbsbrly->tblbrlymconnection->loadRecBySQL("SELECT * FROM TblBrlyMConnection WHERE refBrlyMFlight = " + to_string(flt->ref), &con)) {
					cons.nodes.push_back(con);
					flts.nodes.push_back(flt);

				} else {
					cout << "\tconnection ending at this flight not found!" << endl;
					delete flt;
				};

			} else {
				cout << "\tflight not found!" << endl;
			};

			cout << "\tflights selected:" << endl;
			for (unsigned int i=0;i<flts.nodes.size();i++) {
				flt = flts.nodes[i];
				cout << "\t\t" << StubBrly::getStubFltStd(dbsbrly, flt->ref) << endl;
			};
		};
	};

	if (cons.nodes.size() > 0) {
		width = 0;
		for (unsigned int i=0;i<cons.nodes.size();i++) {
			con = cons.nodes[i];
			if (((con->stop-con->start)/60) > width) width = (con->stop-con->start)/60;
		};
		width += 300;

		height = 30*cons.nodes.size() - 10;
		height += 50;

		svgfile = Tmp::newfile(xchg->tmppath, "xml");

		s = xchg->tmppath + "/" + svgfile;
		outfile.open(s.c_str(), ios::out);

		outfile << "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>" << endl;
		outfile << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1 plus MathML 2.0 plus SVG 1.1//EN\" \"http://www.w3.org/2002/04/xhtml-math-svg/xhtml-math-svg.dtd\">" << endl;
		outfile << "<html xmlns=\"http://www.w3.org/1999/xhtml\" xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">" << endl;
		outfile << "\t<head>" << endl;
		outfile << "\t\t<title>bargraph</title>" << endl;
		outfile << "\t\t<link href=\"./graph.css\" rel=\"styleSheet\" type=\"text/css\"/>" << endl;
		outfile << "\t</head>" << endl;
		outfile << "\t<body marginwidth=\"0\" marginheight=\"0\">" << endl;
		outfile << "\t\t<table cellspacing=\"0\" border=\"0\" cellpadding=\"0\">" << endl;
		outfile << "\t\t\t<tbody>" << endl;
		outfile << "\t\t\t\t<tr id=\"trChart\">" << endl;
		outfile << "\t\t\t\t\t<td id=\"tdChart\" height=\"" << height << "\">" << endl;
		outfile << "\t\t\t\t\t\t<svg id=\"chart\" style=\"display:block\" width=\"" << width << "\" height=\"" << height << "\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

		// ticks
		for (unsigned int i=60;i<(width-300);i+=60) {
			outfile << "\t\t\t\t\t\t\t<line class=\"tck\" x1=\"" << (((double) (150+i))-0.5) << "\" y1=\"" << (height-32) << "\" x2=\"" << (((double) (150+i))-0.5) << "\" y2=\"5\"/>" << endl;
			outfile << "\t\t\t\t\t\t\t<text class=\"tcktxt\" x=\"" << (150+i) << "\" y=\"" << (height-20) << "\" text-anchor=\"middle\">" << (i/60) << ":";
			if ((i%60) < 10) outfile << "0";
			outfile << (i%60) << "</text>" << endl;
		};

		// x-axis
		outfile << "\t\t\t\t\t\t\t<line class=\"xy\" x1=\"145\" y1=\"" << (((double) (height-35))-0.5) << "\" x2=\"" << (width-135) << "\" y2=\"" << (((double) (height-35))-0.5) << "\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t<polygon transform=\"translate(" << (width-131) << "," << (height-36) << ")\" points=\"-4,-4 4,0 -4,4\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t<text class=\"xytxt\" x=\"" << (width-130) << "\" y=\"" << (height-20) << "\">flight time [h]</text>" << endl;

		// y-axis
		outfile << "\t\t\t\t\t\t\t<line class=\"xy\" x1=\"149.5\" y1=\"" << (height-30) << "\" x2=\"149.5\" y2=\"5\"/>" << endl;

		height = 20;

		for (unsigned int i=0;i<cons.nodes.size();i++) {
			con = cons.nodes[i];
			flt = flts.nodes[i];

			rlystat = new Rlystat(dbsbrly, con);

			cout << "\trelay statistics for flight " << StubBrly::getStubFltStd(dbsbrly, flt->ref) << ":" << endl;
			for (list<Rlychunk>::iterator it=rlystat->listRly.begin() ; it != rlystat->listRly.end() ; it++) (*it).dump();

			// ex.: LH400 FRA-JFK (-> 08:40)
			outfile << "\t\t\t\t\t\t\t<text class=\"flttxt\" x=\"140\" y=\"" << ((i*30)+25) << "\" text-anchor=\"end\">";
			s = StubBrly::getStubFltStd(dbsbrly, flt->ref);
			ptr1 = s.find(' ');
			if (ptr1 != string::npos) {
				ptr2 = s.find(' ', ptr1+1);
				if (ptr2 != string::npos) {
					s2 = Ftm::timeOfDay(flt->start);
					if (s2.rfind(':') != string::npos) s2 = s2.substr(0, s2.rfind(':'));
					s = s.substr(0, ptr1) + s.substr(ptr2) + " (-> " + s2 + ")";
				};
			};
			outfile << s <<  "</text>" << endl;

			// ex.: 2:34/4:05 (20%)
			outfile << "\t\t\t\t\t\t\t<text class=\"flttxt\" x=\"" << (150+(con->stop-con->start)/60+10) << "\" y=\"" << ((i*30)+25) << "\">";

			t = lround(rlystat->pCtd * ((double) (con->stop-con->start)) / 60.0);
			outfile << (t/60) << ":";
			if ((t%60) < 10) outfile << "0";
			outfile << (t%60) << "/";

			t = lround(((double) (con->stop-con->start)) / 60.0);
			outfile << (t/60) << ":";
			if ((t%60) < 10) outfile << "0";
			outfile << (t%60);

			outfile << " (" << lround(100.0*rlystat->pCtd) << "%)";
			outfile << "</text>" << endl;

			outfile << "\t\t\t\t\t\t\t<g transform=\"translate(150,10)\">" << endl;

			mode = 0;

			y = i*30;

			for (list<Rlychunk>::iterator it=rlystat->listRly.begin() ; it != rlystat->listRly.end() ; it++) {
				if (!(*it).ctdBwd && !(*it).ctdFwd) {
					if ((*it).Nhop == 0) newmode = Bgmode::ALONE;
					else newmode = Bgmode::NCTD;

				} else if (!(*it).ctdBwd && (*it).ctdFwd) {
					newmode = Bgmode::CTDFWD;

				} else if ((*it).ctdBwd && !(*it).ctdFwd) {
					newmode = Bgmode::CTDBWD;

				} else if ((*it).ctdBwd && (*it).ctdFwd) {
					newmode = Bgmode::CTDBOTH;
				};

				if (it == rlystat->listRly.begin()) {
					x = (*it).start;
					width = (*it).stop-x+1;
					mode = newmode;

				} else {
					if ((*it).start == (x+width)) {
						// contiguous in time
						if (newmode == mode) {
							// stretch current segment
							width = (*it).stop-x+1;

						} else {
							// finalize previous segment and start new segment
							wrBgseg(outfile, con->start, mode, x, y, width, height);

							x = (*it).start;
							width = (*it).stop-x+1;
							mode = newmode;
						};

					} else {
						// finalize previous segment, place gap and start new segment
						wrBgseg(outfile, con->start, mode, x, y, width, height);

						x = x+width;
						width = (*it).start-x;

						wrBgseg(outfile, con->start, Bgmode::ALONE, x, y, width, height);
						
						x = (*it).start;
						width = (*it).stop-x+1;
						mode = newmode;
					};
				};
			};

			// finalize final segment, if neccessary fill with gap (in practice impossible, as forward connection to end location has to be possible)
			if ((x+width) == con->stop) {
				wrBgseg(outfile, con->start, mode, x, y, width, height);

			} else {
				wrBgseg(outfile, con->start, mode, x, y, width, height);

				x = x+width;
				width = con->stop-x+1;
				wrBgseg(outfile, con->start, Bgmode::ALONE, x, y, width, height);

				cout << "what a mess: x=" << x << ", width=" << width << ", con->stop=" << con->stop << endl;
			};

			delete rlystat;

			outfile << "\t\t\t\t\t\t\t</g>" << endl;
		};

		outfile << "\t\t\t\t\t\t</svg>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;
		outfile << "\t\t\t\t</tr>" << endl;
		outfile << "\t\t\t</tbody>" << endl;
		outfile << "\t\t</table>" << endl;
		outfile << "\t</body>" << endl;
		outfile << "</html>" << endl;

		outfile.close();

		// offer command line command to download SVG chart .xml
		cout << "\twget http://127.0.0.1:13100/download/" << jref << "/bargraph.xml" << endl;
	};

	return false;
	// IP handleBargraph --- IEND
	return retval;
};

bool CrdBrlyCon::handleCalc(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCalc --- IBEGIN
	changeStage(dbsbrly, VecVSge::CALC1);

	return(ixVSge != VecVSge::IDLE);
	// IP handleCalc --- IEND
	return retval;
};

bool CrdBrlyCon::handleCleanup1(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCleanup1 --- IBEGIN
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMLegMLocation WHERE refBrlyMLeg IN (SELECT ref FROM TblBrlyMLeg WHERE ixVBasetype = " + to_string(VecBrlyVMLegBasetype::CORR) + ")");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMLegMLeg WHERE dstRefBrlyMLeg IN (SELECT ref FROM TblBrlyMLeg WHERE ixVBasetype = " + to_string(VecBrlyVMLegBasetype::CORR) + ")");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMLegMLeg WHERE orgRefBrlyMLeg IN (SELECT ref FROM TblBrlyMLeg WHERE ixVBasetype = " + to_string(VecBrlyVMLegBasetype::CORR) + ")");

	dbsbrly->executeQuery("DELETE FROM TblBrlyMLeg WHERE ixVBasetype = " + to_string(VecBrlyVMLegBasetype::CORR));
	
	dbsbrly->executeQuery("DELETE FROM TblBrlyMConnection");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMConnectionMFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyLRMConnectionMEquipment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyORMConnectionMEquipment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMRelay");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMNode");

	return false;
	// IP handleCleanup1 --- IEND
	return retval;
};

bool CrdBrlyCon::handleCleanup2(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCleanup2 --- IBEGIN
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMFlightMFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMFlightMLocation");

	dbsbrly->executeQuery("UPDATE TblBrlyMFlight SET Calcdone = 0");

	return false;
	// IP handleCleanup2 --- IEND
	return retval;
};

bool CrdBrlyCon::handleCongen(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCongen --- IBEGIN
	changeStage(dbsbrly, VecVSge::CONGEN);

	return(ixVSge != VecVSge::IDLE);
	// IP handleCongen --- IEND
	return retval;
};

bool CrdBrlyCon::handleCorrgen(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCorrgen --- IBEGIN
	changeStage(dbsbrly, VecVSge::CRGIDLE);

	return(ixVSge != VecVSge::IDLE);
	// IP handleCorrgen --- IEND
	return retval;
};

bool CrdBrlyCon::handleLineup(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleLineup --- IBEGIN
	string s;

	BrlyMFlight* flt = NULL;
	BrlyMConnection* con = NULL;

	list<ubigint> lineup;
	ListBrlyORMConnectionMEquipment ops;

	unsigned int dt;

	unsigned int t;
	unsigned int opix;

	// - ask for date
	cout << "\tenter date (DD-MM-YYYY): ";
	cin >> s;
	date = Ftm::invdate(s);

	// - ask for flight
	cout << "\tselect flight by its flight number: ";
	cin >> s;

	if (dbsbrly->tblbrlymflight->loadRecBySQL("SELECT * FROM TblBrlyMFlight WHERE sref LIKE '" + s + " %' AND start >= " + to_string(86400*date) + " AND start < " + to_string(86400*(date+1)-1), &flt)) {

		if (dbsbrly->tblbrlymconnection->loadRecBySQL("SELECT * FROM TblBrlyMConnection WHERE refBrlyMFlight = " + to_string(flt->ref), &con)) {

			cout << "\tenter number of minutes from connection start/stop time: ";
			cin >> s;
			dt = atoi(s.c_str())*60;

			opix = 0;

			Brly::initEqplineup(dbsbrly, con->ref, lineup, ops);

			t = con->start + dt;
			opix = Brly::advanceEqplineup(lineup, ops, opix, t);

			cout << "line-up at t=" << Ftm::stamp(t) << endl;
			for (list<ubigint>::iterator it=lineup.begin() ; it!=lineup.end() ; it++) {
				if (it != lineup.begin()) cout << ", ";

				s = StubBrly::getStubEqpShort(dbsbrly, *it);
				if (s.find(' ') != string::npos) s = s.substr(0, s.find(' '));
				cout << s;
			};
			cout << endl;

			t = (con->stop+con->start)/2;
			opix = Brly::advanceEqplineup(lineup, ops, opix, t);

			cout << "line-up at t=" << Ftm::stamp(t) << endl;
			for (list<ubigint>::iterator it=lineup.begin() ; it!=lineup.end() ; it++) {
				if (it != lineup.begin()) cout << ", ";

				s = StubBrly::getStubEqpShort(dbsbrly, *it);
				if (s.find(' ') != string::npos) s = s.substr(0, s.find(' '));
				cout << s;
			};
			cout << endl;

			t = con->stop - dt;
			opix = Brly::advanceEqplineup(lineup, ops, opix, t);

			cout << "line-up at t=" << Ftm::stamp(t) << endl;
			for (list<ubigint>::iterator it=lineup.begin() ; it!=lineup.end() ; it++) {
				if (it != lineup.begin()) cout << ", ";

				s = StubBrly::getStubEqpShort(dbsbrly, *it);
				if (s.find(' ') != string::npos) s = s.substr(0, s.find(' '));
				cout << s;
			};
			cout << endl;

			delete con;

		} else {
			cout << "\terror: no connection calculation for this flight found." << endl;
		};

		delete flt;

	} else {
		cout << "\terror: flight not found." << endl;
	};

	return false;
	// IP handleLineup --- IEND
	return retval;
};

bool CrdBrlyCon::handlePickup(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handlePickup --- IBEGIN
	vector<string> arenas;

	bool ic;

	vector<ubigint> refsLeg1;
	vector<ubigint> refsLeg2;

	BrlyMLeg* rt = NULL;
	BrlyMLeg* corr = NULL;

	string s;

	rts.clear();
	corrs.clear();
	cons.clear();
	flts.clear();

	// - find routes and corridors
	cout << "\tlist of arenas to select from:" << endl;
	cout << "\t\ttransoceanic (to1/to2/to3/to4)" << endl;
	cout << "\t\tother inter-continental (ico1/ico2/ico3/ico4)" << endl;
	cout << "\t\tcontinental (co1/co2/co3)" << endl;
	cout << "\t\tnon-continental (noco)" << endl;
	cout << "\t\tall" << endl;

	cout << "\tyour choice: ";
	cin >> arena;

	if ((arena.compare("noco") == 0) || (arena.compare("all") == 0)) {
		arenas.push_back("to1");
		arenas.push_back("to2");
		arenas.push_back("to3");
		arenas.push_back("to4");

		arenas.push_back("ico1");
		arenas.push_back("ico2");
		arenas.push_back("ico3");
//		arenas.push_back("ico4");

		if (arena.compare("all") == 0) {
			arenas.push_back("co1");
			arenas.push_back("co2");
			arenas.push_back("co3");
		};

	} else {
		arenas.push_back(arena);
	};

	// load routes of the selected arenas
	for (unsigned int i=0;i<arenas.size();i++) {
		arena = arenas[i];

		refsLeg1.resize(0);
		refsLeg2.resize(0);

		ic = ((arena.substr(0,2).compare("to") == 0) || (arena.substr(0,3).compare("ico") == 0));
		Brly::loadLegsByArena(dbsbrly, arena, true, ic, false, refsLeg1, refsLeg2);

		dbsbrly->tblbrlymleg->loadRstByRefs(refsLeg1, true, rts);
		dbsbrly->tblbrlymleg->loadRstByRefs(refsLeg2, true, rts);
	};

	// add corresponding corridors
	for (unsigned int i=0;i<rts.nodes.size();i++) {
		rt = rts.nodes[i];

		dbsbrly->tblbrlymleg->loadRstBySQL("SELECT * FROM TblBrlyMLeg WHERE ixVBasetype = " + to_string(VecBrlyVMLegBasetype::CORR) + " AND bgnRefBrlyMLocation = " + to_string(rt->bgnRefBrlyMLocation)
					+ " AND endRefBrlyMLocation = " + to_string(rt->endRefBrlyMLocation), true, corrs);
	};

	if (corrs.nodes.size() != rts.nodes.size()) cout << "error: " << rts.nodes.size() << " routes but " << corrs.nodes.size() << " communication corridors!" << endl;

	// - optional: connections by date
	cout << "\tselect date (yes/no)?" << endl;

	cout << "\tyour choice: ";
	cin >> s;

	if (s.compare("yes") == 0) {
		// find connections on these corridors
		cout << "\tenter date (DD-MM-YYYY): ";
		cin >> s;
		date = Ftm::invdate(s);

		for (unsigned int i=0;i<corrs.nodes.size();i++) {
			corr = corrs.nodes[i];

			dbsbrly->tblbrlymconnection->loadRstBySQL("SELECT * FROM TblBrlyMConnection WHERE corRefBrlyMLeg = " + to_string(corr->ref) + " AND start >= " + to_string(86400*date) + " AND start < "
						+ to_string(86400*(date+1)-1), true, cons);
		};
	};

	return false;
	// IP handlePickup --- IEND
	return retval;
};

bool CrdBrlyCon::handleStats2(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleStats2 --- IBEGIN
	fstream outfile;

	BrlyMConnection* con = NULL;
	Rlystat* rlystat = NULL;

	outfile.open("rlystats.txt", ios::out);

	for (unsigned int i=0;i<cons.nodes.size();i++) {
		con = cons.nodes[i];

		rlystat = new Rlystat(dbsbrly, con);

		outfile << con->ref << "\t" << StubBrly::getStubConStd(dbsbrly, con->ref) << "\t" << rlystat->pCtdBwd << "\t" << rlystat->pCtdFwd << "\t" << rlystat->avgNhopBwd
					<< "\t" << rlystat->avgNhopFwd << "\t" << rlystat->pCtd << "\t" << rlystat->pCtdBoth << "\t" << rlystat->avgNhop << endl;

		delete rlystat;
	};

	outfile.close();

	return false;
	// IP handleStats2 --- IEND
	return retval;
};

void CrdBrlyCon::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdBrlyCon::handleDpchAppDoClose(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	changeStage(dbsbrly, VecVSge::CLOSE);
};

void CrdBrlyCon::handleDpchAppDoMitAppAbtClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsbrly, VecVSge::ALRBRLYABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdBrlyCon::handleDpchAppDoMitCrdNewClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	if (!dlgnew) {
		dlgnew = new DlgBrlyConNew(xchg, dbsbrly, jref, ixBrlyVLocale);
		statshr.jrefDlgnew = dlgnew->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdBrlyCon::handleDpchAppBrlyAlert(
			DbsBrly* dbsbrly
			, DpchAppBrlyAlert* dpchappbrlyalert
			, DpchEngBrly** dpcheng
		) {
	if (ixVSge == VecVSge::ALRBRLYABT) {
		changeStage(dbsbrly, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
};

void CrdBrlyCon::handleTimer(
			DbsBrly* dbsbrly
			, const string& sref
		) {
	if (ixVSge == VecVSge::CRGIDLE) {
		changeStage(dbsbrly, nextIxVSge);
	} else if ((ixVSge == VecVSge::CORRGEN) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.corrgen.mon --- INSERT
	} else if ((ixVSge == VecVSge::CORRCALC) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.corrcalc.mon --- INSERT
	} else if ((ixVSge == VecVSge::CALC1) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.calc1.mon --- INSERT
	} else if ((ixVSge == VecVSge::CALC2) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.calc2.mon --- INSERT
	} else if ((ixVSge == VecVSge::CALC3) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.calc3.mon --- INSERT
	} else if ((ixVSge == VecVSge::CALC4) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.calc4.mon --- INSERT
	};
};

void CrdBrlyCon::handleCall(
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

bool CrdBrlyCon::handleCallBrlyDlgClose(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgnew) {
		delete dlgnew;
		dlgnew = NULL;
		statshr.jrefDlgnew = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

bool CrdBrlyCon::handleCallBrlyStatChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD) && (pnlrec->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD)) pnllist->minimize(dbsbrly, true);
	return retval;
};

bool CrdBrlyCon::handleCallBrlyRefPreSet(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecBrlyVPreset::PREBRLYREFCON) {
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


