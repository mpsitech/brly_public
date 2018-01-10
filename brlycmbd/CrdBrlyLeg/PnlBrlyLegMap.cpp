/**
  * \file PnlBrlyLegMap.cpp
  * job handler for job PnlBrlyLegMap (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyLegMap.h"

#include "PnlBrlyLegMap_blks.cpp"

/******************************************************************************
 class PnlBrlyLegMap
 ******************************************************************************/

PnlBrlyLegMap::PnlBrlyLegMap(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYLEGMAP, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	qryleg = NULL;
	qrylocation = NULL;

	// IP constructor.cust1 --- IBEGIN
	standalone = false;
	// IP constructor.cust1 --- IEND

	qryleg = new QryBrlyLegMapLeg(xchg, dbsbrly, jref, ixBrlyVLocale);
	qrylocation = new QryBrlyLegMapLocation(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- IBEGIN
	calcDist(dbsbrly);

	set<uint> moditems;
	refresh(dbsbrly, moditems);
	// IP constructor.cust2 --- IEND

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlBrlyLegMap::~PnlBrlyLegMap() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void PnlBrlyLegMap::calcDist(
			DbsBrly* dbsbrly
		) {
	BrlyMLeg* leg = NULL;

	ubigint refBrlyMLeg;
	refBrlyMLeg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLEG, jref);

	wkm = 0;
	hkm = 0;

	if (dbsbrly->tblbrlymleg->loadRecByRef(refBrlyMLeg, &leg)) {
		wkm = ceil(leg->deltaphi * 2.0*pi/360.0 * xchg->stgbrlygeometry.earthradius / 1000.0);
		hkm = lround(2.0 * leg->alpha * 2.0*pi/360.0 * xchg->stgbrlygeometry.earthradius / 1000.0);
		delete leg;
	};
};
// IP cust --- IEND
DpchEngBrly* PnlBrlyLegMap::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFSge, &statshr, &(qryleg->rst), &(qrylocation->rst), &(qryleg->statshr), &(qrylocation->statshr), &(qryleg->stgiac), &(qrylocation->stgiac), &stgiac, items);
	};

	return dpcheng;
};

void PnlBrlyLegMap::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	// IP refresh --- IBEGIN
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// continf
	continf.numFSge = ixVSge;

	// statshr
	statshr.SldHMin = 0;
	statshr.SldHMax = wkm * contiac.SldScl;
	statshr.SldVMin = -((int) hkm)*((int) contiac.SldScl)/2;
	statshr.SldVMax = hkm*contiac.SldScl/2;

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	// IP refresh --- IEND
};

void PnlBrlyLegMap::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFLEG) {
	};
	// IP updatePreset --- END
};

void PnlBrlyLegMap::changeStage(
			DbsBrly* dbsbrly
			, uint _ixVSge
			, DpchEngBrly** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsbrly); break;
				case VecVSge::MAPGEN: leaveSgeMapgen(dbsbrly); break;
			};

			ixVSge = _ixVSge;
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::MAPGEN: _ixVSge = enterSgeMapgen(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint PnlBrlyLegMap::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void PnlBrlyLegMap::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint PnlBrlyLegMap::enterSgeMapgen(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::MAPGEN;
	nextIxVSge = VecVSge::IDLE;

	clearInvs();
// IP enterSgeMapgen --- IBEGIN
	ubigint refBrlyMLeg;
	refBrlyMLeg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLEG, jref);

	if (refBrlyMLeg == 0) {
		retval = VecVSge::IDLE;

	} else {
/*
		if (standalone) {
			addInv(new DpchInvBrlyMapgenLegmap(0, 0, hkm, qryleg->jref, qrylocation->jref, refBrlyMLeg, contiac.SldScl, 0, true, 0, 0));
		} else {
			addInv(new DpchInvBrlyMapgenLegmap(0, 0, stgiac.height, qryleg->jref, qrylocation->jref, refBrlyMLeg, contiac.SldScl, stgiac.width,
						false, contiac.SldH, statshr.SldVMax - contiac.SldV + statshr.SldVMin));
		};
*/
	};
// IP enterSgeMapgen --- IEND
	submitInvs(dbsbrly, retval, retval);
	return retval;
};

void PnlBrlyLegMap::leaveSgeMapgen(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeMapgen --- IBEGIN
	if (standalone) {
		// add qry blocks to srcfile and pack tgzfile
		// ...

		standalone = false;
	};

/*
	fstream outfile;

	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	string folder;

	string s;

	qryleg->fetch(dbsbrly);
	qrylocation->fetch(dbsbrly);

	if (standalone) {
		folder = Tmp::newfolder(xchg->tmppath);

		s = "mv " + xchg->tmppath + "/" + pngfile + " " + xchg->tmppath + "/" + folder + "/map.png";
		system(s.c_str());

		// --- write data source file
		s = xchg->tmppath + "/" + folder + "/legmap_src.xml";
		outfile.open(s.c_str(), ios::out);

		// - XML header
		outfile << "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>" << endl;
		outfile << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">" << endl;
		outfile << "<html xmlns=\"http://www.w3.org/1999/xhtml\" xmlns:brly=\"http://www.epsitechnologies.com/brly\">" << endl;
		outfile << "\t<head>" << endl;
		outfile << "\t\t<title>_src</title>" << endl;
		outfile << "\t</head>" << endl;
		outfile << "\t<body marginwidth=\"0\" marginheight=\"0\">" << endl;
		outfile << "\t\t<src xmlns=\"http://www.epsitechnologies.com/brly\">" << endl;

		outfile << "\t\t\t<w>" << wkm << "</w>" << endl;
		outfile << "\t\t\t<h>" << hkm << "</h>" << endl;

		// -- use libxml to write content into buffer first

		// - legs
		startwriteBuffer(&wr, &buf);
		qryleg->rst.writeXML(wr);
		closewriteBuffer(wr);

		s = string((char*) (buf->content), buf->use);
		xmlBufferFree(buf);
		s = s.substr(s.find("?>") + 2);

		writeRst(outfile, s);

		// - locations
		startwriteBuffer(&wr, &buf);
		qrylocation->rst.writeXML(wr);
		closewriteBuffer(wr);

		s = string((char*) (buf->content), buf->use);
		xmlBufferFree(buf);
		s = s.substr(s.find("?>") + 2);

		writeRst(outfile, s);

		// - XML footer
		outfile << "\t\t</src>" << endl;
		outfile << "\t</body>" << endl;
		outfile << "</html>" << endl;

		outfile.close();

		// --- generate final .tgz package including fixed .xml, .js and .css files

		// ... add files from archive ...

		tgzfile = folder + ".tgz";

		s = "tar czvf " + xchg->tmppath + "/" + tgzfile + " -C " + xchg->tmppath + "/" + folder + " .";
		system(s.c_str());

		// offer command line command to download .tgz'ed map
		cout << "\twget http://192.168.0.12:13100/download/" << jref << "/map.tgz" << endl;

	} else {
		// image update
		xchg->submitDpch(new DpchEngLive(jref, &(qryleg->rst), &(qrylocation->rst), &(qryleg->statshr), &(qrylocation->statshr)));
	};
*/
	// IP leaveSgeMapgen --- IEND
};

string PnlBrlyLegMap::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if (ixVSge == VecVSge::MAPGEN) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::MAPGEN) retval = "generating map";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::MAPGEN) retval = "erzeuge Landkarte";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

void PnlBrlyLegMap::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tmapgen" << endl;
		} else if (req->cmd == "mapgen") {
			req->retain = handleMapgen(dbsbrly);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYINIT) {
			handleDpchAppBrlyInit(dbsbrly, (DpchAppBrlyInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGMAPDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRYLEG)) {
				handleDpchAppDataStgiacqryleg(dbsbrly, &(dpchappdata->stgiacqryleg), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRYLOCATION)) {
				handleDpchAppDataStgiacqrylocation(dbsbrly, &(dpchappdata->stgiacqrylocation), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsbrly, &(dpchappdata->stgiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGMAPDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHOMECLICK) {
					handleDpchAppDoButHomeClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbsbrly, &(req->dpcheng));
				};

			};

		};

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

bool PnlBrlyLegMap::handleMapgen(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleMapgen --- IBEGIN
	standalone = true;
	changeStage(dbsbrly, VecVSge::MAPGEN);

	return(ixVSge != VecVSge::IDLE);
	// IP handleMapgen --- IEND
	return retval;
};

void PnlBrlyLegMap::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyLegMap::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	// contiac
	double oldSldScl = contiac.SldScl;

	if (_contiac->SldScl < statshr.SldSclMin) contiac.SldScl = statshr.SldSclMin;
	else if (_contiac->SldScl > statshr.SldSclMax) contiac.SldScl = statshr.SldSclMax;
	else contiac.SldScl = _contiac->SldScl;

	// change in scale should yield adaptation of SldH, SldV
	if (contiac.SldScl != oldSldScl) {
		contiac.SldH = (contiac.SldH * ((int) contiac.SldScl)) / ((int) oldSldScl);
		contiac.SldV = (contiac.SldV * ((int) contiac.SldScl)) / ((int) oldSldScl);
	};

	refresh(dbsbrly, moditems);

	// contiac (2)
	if (contiac.SldH < statshr.SldHMin) contiac.SldH = statshr.SldHMin;
	else if (contiac.SldH > statshr.SldHMax) contiac.SldH = statshr.SldHMax;

	if (contiac.SldV < statshr.SldVMin) contiac.SldV = statshr.SldVMin;
	else if (contiac.SldV > statshr.SldVMax) contiac.SldV = statshr.SldVMax;

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyLegMap::handleDpchAppDataStgiacqryleg(
			DbsBrly* dbsbrly
			, QryBrlyLegMapLeg::StgIac* _stgiacqryleg
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqryleg->diff(&(qryleg->stgiac));
	// IP handleDpchAppDataStgiacqryleg --- INSERT
	insert(moditems, DpchEngData::STGIACQRYLEG);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyLegMap::handleDpchAppDataStgiacqrylocation(
			DbsBrly* dbsbrly
			, QryBrlyLegMapLocation::StgIac* _stgiacqrylocation
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqrylocation->diff(&(qrylocation->stgiac));
	// IP handleDpchAppDataStgiacqrylocation --- INSERT
	insert(moditems, DpchEngData::STGIACQRYLOCATION);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyLegMap::handleDpchAppDataStgiac(
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

void PnlBrlyLegMap::handleDpchAppDoButRegularizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixBrlyVExpstate = VecBrlyVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlBrlyLegMap::handleDpchAppDoButMinimizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlBrlyLegMap::handleDpchAppDoButHomeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButHomeClick --- INSERT
};

void PnlBrlyLegMap::handleDpchAppDoButRefreshClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButRefreshClick --- INSERT
};

string PnlBrlyLegMap::handleDownload(
			DbsBrly* dbsbrly
		) {
	// IP handleDownload --- RBEGIN
	if (tgzfile.length() > 0) return(xchg->tmppath + "/" + tgzfile);
	else return("");
	// IP handleDownload --- REND
};

void PnlBrlyLegMap::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTATCHG) {
		call->abort = handleCallBrlyStatChg(dbsbrly, call->jref);
	};
};

bool PnlBrlyLegMap::handleCallBrlyStatChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlyStatChg --- INSERT
	return retval;
};


