/**
  * \file PnlBrlyConMap.cpp
  * job handler for job PnlBrlyConMap (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyConMap.h"

#include "PnlBrlyConMap_blks.cpp"

/******************************************************************************
 class PnlBrlyConMap
 ******************************************************************************/

PnlBrlyConMap::PnlBrlyConMap(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::PNLBRLYCONMAP, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	qryflight = NULL;
	qryleg = NULL;
	qrylocation = NULL;
	qrynode = NULL;
	qryrelay = NULL;

	// IP constructor.cust1 --- IBEGIN
	standalone = false;
	// IP constructor.cust1 --- IEND

	qryflight = new QryBrlyConMapFlight(xchg, dbsbrly, jref, ixBrlyVLocale);
	qryleg = new QryBrlyConMapLeg(xchg, dbsbrly, jref, ixBrlyVLocale);
	qrylocation = new QryBrlyConMapLocation(xchg, dbsbrly, jref, ixBrlyVLocale);
	qrynode = new QryBrlyConMapNode(xchg, dbsbrly, jref, ixBrlyVLocale);
	qryrelay = new QryBrlyConMapRelay(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- IBEGIN
	calcDist(dbsbrly);

	set<uint> moditems;
	refresh(dbsbrly, moditems);
	// IP constructor.cust2 --- IEND

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlBrlyConMap::~PnlBrlyConMap() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void PnlBrlyConMap::calcDist(
			DbsBrly* dbsbrly
		) {
	BrlyMConnection* con = NULL;
	BrlyMLeg* leg = NULL;

	ubigint refBrlyMConnection;
	refBrlyMConnection = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);

	wkm = 0;
	hkm = 0;

	if (dbsbrly->tblbrlymconnection->loadRecByRef(refBrlyMConnection, &con)) {
		if (dbsbrly->tblbrlymleg->loadRecByRef(con->corRefBrlyMLeg, &leg)) {
			wkm = ceil(leg->deltaphi * 2.0*pi/360.0 * xchg->stgbrlygeometry.earthradius / 1000.0);
			hkm = lround(2.0*leg->alpha * 2.0*pi/360.0 * xchg->stgbrlygeometry.earthradius / 1000.0);
			delete leg;
		};

		delete con;
	};
};

// IP cust --- IEND
DpchEngBrly* PnlBrlyConMap::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFSge, &statshr, &(qryflight->rst), &(qryleg->rst), &(qrylocation->rst), &(qrynode->rst), &(qryrelay->rst), &(qryflight->statshr), &(qryleg->statshr), &(qrylocation->statshr), &(qrynode->statshr), &(qryrelay->statshr), &(qryflight->stgiac), &(qryleg->stgiac), &(qrylocation->stgiac), &(qrynode->stgiac), &(qryrelay->stgiac), &stgiac, items);
	};

	return dpcheng;
};

void PnlBrlyConMap::refresh(
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

void PnlBrlyConMap::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFCON) {
	};
	// IP updatePreset --- END
};

void PnlBrlyConMap::changeStage(
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

uint PnlBrlyConMap::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void PnlBrlyConMap::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint PnlBrlyConMap::enterSgeMapgen(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::MAPGEN;
	nextIxVSge = VecVSge::IDLE;

	clearInvs();
	// IP enterSgeMapgen --- IBEGIN

	ubigint refBrlyMConnection;
	refBrlyMConnection = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);

	if (refBrlyMConnection == 0) {
		retval = VecVSge::IDLE;

	} else {
/*
		if (standalone) {
			addInv(new DpchInvBrlyMapgenConmap(0, 0, hkm, qryflight->jref, qryleg->jref, qrylocation->jref, qrynode->jref, qryrelay->jref,
						refBrlyMConnection, 1, 0, true, wrtree, 0, 0));
		} else {
			if (statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD) {
				addInv(new DpchInvBrlyMapgenConmap(0, 0, 300, qryflight->jref, qryleg->jref, qrylocation->jref, qrynode->jref, qryrelay->jref,
							refBrlyMConnection, 1, 400, false, wrtree, 0, 0));
			} else if (statshr.ixBrlyVExpstate == VecBrlyVExpstate::DETD) {
				addInv(new DpchInvBrlyMapgenConmap(0, 0, hkm, qryflight->jref, qryleg->jref, qrylocation->jref, qrynode->jref, qryrelay->jref,
							refBrlyMConnection, 1, stgiac.width, false, wrtree, contiac.SldH, statshr.SldVMax - contiac.SldV + statshr.SldVMin));
			};
		};
*/
	};

	// IP enterSgeMapgen --- IEND
	submitInvs(dbsbrly, retval, retval);
	return retval;
};

void PnlBrlyConMap::leaveSgeMapgen(
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

	qryflight->fetch(dbsbrly);
	qryleg->fetch(dbsbrly);
	qrylocation->fetch(dbsbrly);
	qrynode->fetch(dbsbrly);
	qryrelay->fetch(dbsbrly);

	if (standalone) {
		folder = Tmp::newfolder(xchg->tmppath);

		s = "mv " + xchg->tmppath + "/" + pngfile + " " + xchg->tmppath + "/" + folder + "/map.png";
		system(s.c_str());

		// --- write data source file
		s = xchg->tmppath + "/" + folder + "/conmap_src.xml";
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

		// - flights
		startwriteBuffer(&wr, &buf);
		qryflight->rst.writeXML(wr);
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

		// - relays
		startwriteBuffer(&wr, &buf);
		qryrelay->rst.writeXML(wr);
		closewriteBuffer(wr);

		s = string((char*) (buf->content), buf->use);
		xmlBufferFree(buf);
		s = s.substr(s.find("?>") + 2);

		writeRst(outfile, s);

		// - nodes
		startwriteBuffer(&wr, &buf);
		qrynode->rst.writeXML(wr);
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
		cout << "\twget http://127.0.0.1:13100/download/" << jref << "/map.tgz" << endl;

	} else {
/// NOT ANYMORE!
		// image update
		xchg->submitDpch(new DpchEngLive(jref, &(qryleg->rst), &(qrylocation->rst),	&(qryflight->rst), &(qryrelay->rst),
						&(qrynode->rst), &(qryleg->statshr), &(qrylocation->statshr), &(qryflight->statshr), &(qryrelay->statshr),
						&(qrynode->statshr)));
	};
*/

	// IP leaveSgeMapgen --- IEND
};

string PnlBrlyConMap::getSquawk(
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

void PnlBrlyConMap::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONMAPDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRYFLIGHT)) {
				handleDpchAppDataStgiacqryflight(dbsbrly, &(dpchappdata->stgiacqryflight), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRYLEG)) {
				handleDpchAppDataStgiacqryleg(dbsbrly, &(dpchappdata->stgiacqryleg), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRYLOCATION)) {
				handleDpchAppDataStgiacqrylocation(dbsbrly, &(dpchappdata->stgiacqrylocation), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRYNODE)) {
				handleDpchAppDataStgiacqrynode(dbsbrly, &(dpchappdata->stgiacqrynode), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRYRELAY)) {
				handleDpchAppDataStgiacqryrelay(dbsbrly, &(dpchappdata->stgiacqryrelay), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsbrly, &(dpchappdata->stgiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONMAPDO) {
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

bool PnlBrlyConMap::handleMapgen(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleMapgen --- IBEGIN
	string s;

	while (true) {
		cout << "\tinclude non-connected trees? (yes/no)" << endl;
		cout << "\tyour input: ";
		
		cin >> s;
		if (s.compare("yes") == 0) {
			wrtree = true;
			break;
		} else if (s.compare("no") == 0) {
			wrtree = false;
			break;
		};
	};

	standalone = true;
	changeStage(dbsbrly, VecVSge::MAPGEN);

	return(ixVSge != VecVSge::IDLE);
	// IP handleMapgen --- IEND
	return retval;
};

void PnlBrlyConMap::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyConMap::handleDpchAppDataContiac(
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

void PnlBrlyConMap::handleDpchAppDataStgiacqryflight(
			DbsBrly* dbsbrly
			, QryBrlyConMapFlight::StgIac* _stgiacqryflight
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqryflight->diff(&(qryflight->stgiac));
	// IP handleDpchAppDataStgiacqryflight --- INSERT
	insert(moditems, DpchEngData::STGIACQRYFLIGHT);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyConMap::handleDpchAppDataStgiacqryleg(
			DbsBrly* dbsbrly
			, QryBrlyConMapLeg::StgIac* _stgiacqryleg
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqryleg->diff(&(qryleg->stgiac));
	// IP handleDpchAppDataStgiacqryleg --- INSERT
	insert(moditems, DpchEngData::STGIACQRYLEG);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyConMap::handleDpchAppDataStgiacqrylocation(
			DbsBrly* dbsbrly
			, QryBrlyConMapLocation::StgIac* _stgiacqrylocation
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqrylocation->diff(&(qrylocation->stgiac));
	// IP handleDpchAppDataStgiacqrylocation --- INSERT
	insert(moditems, DpchEngData::STGIACQRYLOCATION);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyConMap::handleDpchAppDataStgiacqrynode(
			DbsBrly* dbsbrly
			, QryBrlyConMapNode::StgIac* _stgiacqrynode
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqrynode->diff(&(qrynode->stgiac));
	// IP handleDpchAppDataStgiacqrynode --- INSERT
	insert(moditems, DpchEngData::STGIACQRYNODE);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyConMap::handleDpchAppDataStgiacqryrelay(
			DbsBrly* dbsbrly
			, QryBrlyConMapRelay::StgIac* _stgiacqryrelay
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqryrelay->diff(&(qryrelay->stgiac));
	// IP handleDpchAppDataStgiacqryrelay --- INSERT
	insert(moditems, DpchEngData::STGIACQRYRELAY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlBrlyConMap::handleDpchAppDataStgiac(
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

void PnlBrlyConMap::handleDpchAppDoButRegularizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixBrlyVExpstate = VecBrlyVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlBrlyConMap::handleDpchAppDoButMinimizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlBrlyConMap::handleDpchAppDoButHomeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButHomeClick --- INSERT
};

void PnlBrlyConMap::handleDpchAppDoButRefreshClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButRefreshClick --- IBEGIN
	// IP handleDpchAppDoButRefreshClick --- IEND
};

string PnlBrlyConMap::handleDownload(
			DbsBrly* dbsbrly
		) {
	// IP handleDownload --- RBEGIN
	if (tgzfile.length() > 0) return(xchg->tmppath + "/" + tgzfile);
	else return("");
	// IP handleDownload --- REND
};

void PnlBrlyConMap::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTATCHG) {
		call->abort = handleCallBrlyStatChg(dbsbrly, call->jref);
	};
};

bool PnlBrlyConMap::handleCallBrlyStatChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlyStatChg --- INSERT
	return retval;
};


