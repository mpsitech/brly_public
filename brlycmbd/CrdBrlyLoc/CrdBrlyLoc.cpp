/**
  * \file CrdBrlyLoc.cpp
  * job handler for job CrdBrlyLoc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "CrdBrlyLoc.h"

#include "CrdBrlyLoc_blks.cpp"

/******************************************************************************
 class CrdBrlyLoc
 ******************************************************************************/

CrdBrlyLoc::CrdBrlyLoc(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
			, const ubigint ref
		) : JobBrly(xchg, VecBrlyVJob::CRDBRLYLOC, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

	// IP constructor.cust1 --- INSERT

	// initialize according to ref
	changeRef(dbsbrly, jref, ((ref+1) == 0) ? 0 : ref, false);

	pnlrec = new PnlBrlyLocRec(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnlheadbar = new PnlBrlyLocHeadbar(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnllist = new PnlBrlyLocList(xchg, dbsbrly, jref, ixBrlyVLocale);

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

CrdBrlyLoc::~CrdBrlyLoc() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
double CrdBrlyLoc::degToRad(
			double _deg																					// angle in degrees (0° .. 360°)
		) {
	return(pi*_deg/180.0);
};

void CrdBrlyLoc::locToRad(
			BrlyMLocation* loc
		) {
	loc->theta = degToRad(loc->theta);
	loc->phi = degToRad(loc->phi);
	loc->alpha = degToRad(loc->alpha);
};

double CrdBrlyLoc::evalDfaprDalphagpr(
			const double re
			, const double af
			, const double alphag
			, const double eg
			, const double alphagpr0
		) {
	return((evalFapr(re, af, alphag, eg, alphagpr0+0.5e-6)-evalFapr(re, af, alphag, eg, alphagpr0-0.5e-6))/1.0e-6);
};

double CrdBrlyLoc::evalFapr(
			const double re
			, const double af
			, const double alphag
			, const double eg
			, const double alphagpr0
		) {
	double delta = (re+af)*(1.0-cos(alphagpr0));
	return(alphagpr0 - atan2((af-eg-delta)*tan(alphag), re+af-delta));
};
// IP cust --- IEND
DpchEngBrly* CrdBrlyLoc::getNewDpchEng(
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

void CrdBrlyLoc::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdBrlyLoc/" + VecBrlyVLocale::getSref(ixBrlyVLocale);
	continf.MtxCrdLoc = StubBrly::getStubLocStd(dbsbrly, xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLOC, jref), ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void CrdBrlyLoc::changeRef(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	BrlyMLocation* rec = NULL;

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbsbrly, VecBrlyVCall::CALLBRLYLOG, jref, VecBrlyVPreset::VOID, 0, "CrdBrlyLoc", ref);
	xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFLOC, jref, ref);

	if (dbsbrly->tblbrlymlocation->loadRecByRef(ref, &rec)) {
		xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFEQP, jref, rec->refBrlyMEquipment);

		delete rec;
	};

	refresh(dbsbrly, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));

	if (pnllist) pnllist->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFLOC, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFLOC, jrefTrig, notif);
};

void CrdBrlyLoc::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdBrlyLoc::changeStage(
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

uint CrdBrlyLoc::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdBrlyLoc::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdBrlyLoc::enterSgeAlrbrlyabt(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::ALRBRLYABT;
	nextIxVSge = VecVSge::IDLE;
	xchg->submitDpch(AlrBrly::prepareAlrAbt(jref, ixBrlyVLocale, feedFMcbAlert)); // IP enterSgeAlrbrlyabt --- LINE
	return retval;
};

void CrdBrlyLoc::leaveSgeAlrbrlyabt(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeAlrbrlyabt --- INSERT
};

uint CrdBrlyLoc::enterSgeClose(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CLOSE;
	nextIxVSge = retval;
	xchg->triggerIxCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDCLOSE, jref, VecBrlyVCard::CRDBRLYLOC);
	return retval;
};

void CrdBrlyLoc::leaveSgeClose(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeClose --- INSERT
};

string CrdBrlyLoc::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void CrdBrlyLoc::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tvisgraph" << endl;
		} else if (req->cmd == "visgraph") {
			req->retain = handleVisgraph(dbsbrly);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYINIT) {
			handleDpchAppBrlyInit(dbsbrly, (DpchAppBrlyInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCDO) {
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
	};
};

bool CrdBrlyLoc::handleVisgraph(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleVisgraph --- IBEGIN
	ListBrlyMLocation locs;
	BrlyMLocation* loc = NULL;

	double earthradius = xchg->stgbrlygeometry.earthradius;
	double acraltitude;

	unsigned int width;

	string svgfile;
	fstream outfile;

	string s;

	double d;
	double x, y, r;

	double alphagpr, alphagprold;
	double res, resold;

	double dfg;

	// - ask for aircarft altitude and map width (height is width/2)
	cout << "\tenter aircraft altitude above MSL [m]: ";
	cin >> s;
	acraltitude = atof(s.c_str());

	cout << "\tenter map width: ";
	cin >> s;
	width = atol(s.c_str());

	// - write .xml file
	svgfile = Tmp::newfile(xchg->tmppath, "xml");

	s = xchg->tmppath + "/" + svgfile;
	outfile.open(s.c_str(), ios::out);

	outfile << "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>" << endl;
	outfile << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1 plus MathML 2.0 plus SVG 1.1//EN\" \"http://www.w3.org/2002/04/xhtml-math-svg/xhtml-math-svg.dtd\">" << endl;
	outfile << "<html xmlns=\"http://www.w3.org/1999/xhtml\" xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">" << endl;
	outfile << "\t<head>" << endl;
	outfile << "\t\t<title>locvis</title>" << endl;
	outfile << "\t</head>" << endl;
	outfile << "\t<body marginwidth=\"0\" marginheight=\"0\">" << endl;
	outfile << "\t\t<table cellspacing=\"0\" border=\"0\" cellpadding=\"0\">" << endl;
	outfile << "\t\t\t<tbody>" << endl;
	outfile << "\t\t\t\t<tr id=\"trMap\">" << endl;
	outfile << "\t\t\t\t\t<td id=\"tdMap\" height=\"" << (width/2) << "\">" << endl;
	outfile << "\t\t\t\t\t\t<svg id=\"map\" style=\"display:block\" width=\"" << width << "\" height=\"" << (width/2) << "\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	outfile << "\t\t\t\t\t\t\t<image id=\"img\" xlink:href=\"./full.png\" x=\"0\" y=\"0\" width=\"" << width << "\" height=\"" << (width/2) << "\"/>" << endl;

	dbsbrly->tblbrlymlocation->loadRstByTyp(VecBrlyVMLocationBasetype::APT, false, locs);

	for (unsigned int i=0;i<locs.nodes.size();i++) {
		loc = locs.nodes[i];
		locToRad(loc);

		d = width/2;
		x = d + ((double) width)/(2.0*pi) * loc->phi;
		if (x < 0.0) x = 0.0;
		if (x > width) x = width;

		d = width/4;
		y = d - ((double) width)/(2.0*pi) * loc->theta;
		if (y < 0.0) y = 0.0;
		if (y > (width/2)) y = width/2;

		// Newton's method to find alphag'
		alphagpr = 1.0 * 2.0*pi/360.0;
		res = 1.0e6;

		while (res > 1.0e-6) {
			alphagprold = alphagpr;
			resold = res;

			alphagpr = alphagpr - evalFapr(earthradius, acraltitude, 85.0*2.0*pi/360.0, loc->alt, alphagpr)/evalDfaprDalphagpr(earthradius, acraltitude, 85.0*2.0*pi/360.0, loc->alt, alphagpr);
			res = fabs(alphagprold-alphagpr);

			if (res > resold) {
				cout << "no convergence!" << endl;
				break;
			};
		};

		dfg = (earthradius+acraltitude)*alphagpr;
		r = dfg * ((double) width)/(2.0*pi*earthradius*cos(loc->theta));

		outfile << "\t\t\t\t\t\t\t<circle style=\"opacity:.5\" cx=\"" << x << "\" cy=\"" << y <<"\" r=\"" << r << "\" fill=\"red\"/>" << endl;
	};

	outfile << "\t\t\t\t\t\t</svg>" << endl;
	outfile << "\t\t\t\t\t</td>" << endl;
	outfile << "\t\t\t\t</tr>" << endl;
	outfile << "\t\t\t</tbody>" << endl;
	outfile << "\t\t</table>" << endl;
	outfile << "\t</body>" << endl;
	outfile << "</html>" << endl;

	outfile.close();

	cout << "file name: " << svgfile << endl;

	return false;
	// IP handleVisgraph --- IEND
	return retval;
};

void CrdBrlyLoc::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdBrlyLoc::handleDpchAppDoClose(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	changeStage(dbsbrly, VecVSge::CLOSE);
};

void CrdBrlyLoc::handleDpchAppDoMitAppAbtClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsbrly, VecVSge::ALRBRLYABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdBrlyLoc::handleDpchAppBrlyAlert(
			DbsBrly* dbsbrly
			, DpchAppBrlyAlert* dpchappbrlyalert
			, DpchEngBrly** dpcheng
		) {
	if (ixVSge == VecVSge::ALRBRLYABT) {
		changeStage(dbsbrly, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
};

void CrdBrlyLoc::handleCall(
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

bool CrdBrlyLoc::handleCallBrlyDlgClose(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlyDlgClose --- INSERT
	return retval;
};

bool CrdBrlyLoc::handleCallBrlyStatChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD) && (pnlrec->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD)) pnllist->minimize(dbsbrly, true);
	return retval;
};

bool CrdBrlyLoc::handleCallBrlyRefPreSet(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecBrlyVPreset::PREBRLYREFLOC) {
		changeRef(dbsbrly, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbsbrly, true);
	};

	return retval;
};


