/**
  * \file CrdBrlyNav.cpp
  * API code for job CrdBrlyNav (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "CrdBrlyNav.h"

/******************************************************************************
 class CrdBrlyNav::VecVDo
 ******************************************************************************/

uint CrdBrlyNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	else if (s == "mitappabtclick") return MITAPPABTCLICK;
	else if (s == "mitsestrmclick") return MITSESTRMCLICK;
	else if (s == "mitcrdusgclick") return MITCRDUSGCLICK;
	else if (s == "mitcrdusrclick") return MITCRDUSRCLICK;
	else if (s == "mitcrdprsclick") return MITCRDPRSCLICK;
	else if (s == "mitcrdfilclick") return MITCRDFILCLICK;
	else if (s == "mitcrdoprclick") return MITCRDOPRCLICK;
	else if (s == "mitcrdptyclick") return MITCRDPTYCLICK;
	else if (s == "mitcrdregclick") return MITCRDREGCLICK;
	else if (s == "mitcrdlocclick") return MITCRDLOCCLICK;
	else if (s == "mitcrdlegclick") return MITCRDLEGCLICK;
	else if (s == "mitcrdttbclick") return MITCRDTTBCLICK;
	else if (s == "mitcrdfltclick") return MITCRDFLTCLICK;
	else if (s == "mitcrdconclick") return MITCRDCONCLICK;
	else if (s == "mitapploiclick") return MITAPPLOICLICK;

	return(0);
};

string CrdBrlyNav::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	else if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
	else if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
	else if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
	else if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
	else if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
	else if (ix == MITCRDOPRCLICK) return("MitCrdOprClick");
	else if (ix == MITCRDPTYCLICK) return("MitCrdPtyClick");
	else if (ix == MITCRDREGCLICK) return("MitCrdRegClick");
	else if (ix == MITCRDLOCCLICK) return("MitCrdLocClick");
	else if (ix == MITCRDLEGCLICK) return("MitCrdLegClick");
	else if (ix == MITCRDTTBCLICK) return("MitCrdTtbClick");
	else if (ix == MITCRDFLTCLICK) return("MitCrdFltClick");
	else if (ix == MITCRDCONCLICK) return("MitCrdConClick");
	else if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

	return("");
};

/******************************************************************************
 class CrdBrlyNav::VecVSge
 ******************************************************************************/

uint CrdBrlyNav::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "alrbrlyabt") return ALRBRLYABT;
	else if (s == "close") return CLOSE;

	return(0);
};

string CrdBrlyNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRBRLYABT) return("alrbrlyabt");
	else if (ix == CLOSE) return("close");

	return("");
};

/******************************************************************************
 class CrdBrlyNav::ContInf
 ******************************************************************************/

CrdBrlyNav::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxSesSes1
			, const string& MtxSesSes2
			, const string& MtxSesSes3
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxSesSes1 = MtxSesSes1;
	this->MtxSesSes2 = MtxSesSes2;
	this->MtxSesSes3 = MtxSesSes3;

	mask = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
};

bool CrdBrlyNav::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyNav";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes1", MtxSesSes1)) add(MTXSESSES1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes2", MtxSesSes2)) add(MTXSESSES2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes3", MtxSesSes3)) add(MTXSESSES3);
	};

	return basefound;
};

set<uint> CrdBrlyNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp.compare(comp->MrlAppHlp) == 0) insert(items, MRLAPPHLP);
	if (MtxSesSes1.compare(comp->MtxSesSes1) == 0) insert(items, MTXSESSES1);
	if (MtxSesSes2.compare(comp->MtxSesSes2) == 0) insert(items, MTXSESSES2);
	if (MtxSesSes3.compare(comp->MtxSesSes3) == 0) insert(items, MTXSESSES3);

	return(items);
};

set<uint> CrdBrlyNav::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyNav::StatApp
 ******************************************************************************/

CrdBrlyNav::StatApp::StatApp(
			const uint ixBrlyVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneAdmin
			, const bool initdoneBase
			, const bool initdoneConnect
		) : Block() {
	this->ixBrlyVReqitmode = ixBrlyVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdoneAdmin = initdoneAdmin;
	this->initdoneBase = initdoneBase;
	this->initdoneConnect = initdoneConnect;

	mask = {IXBRLYVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEADMIN, INITDONEBASE, INITDONECONNECT};
};

bool CrdBrlyNav::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVReqitmode", srefIxBrlyVReqitmode)) {
			ixBrlyVReqitmode = VecBrlyVReqitmode::getIx(srefIxBrlyVReqitmode);
			add(IXBRLYVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAdmin", initdoneAdmin)) add(INITDONEADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneBase", initdoneBase)) add(INITDONEBASE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneConnect", initdoneConnect)) add(INITDONECONNECT);
	};

	return basefound;
};

set<uint> CrdBrlyNav::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVReqitmode == comp->ixBrlyVReqitmode) insert(items, IXBRLYVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneAdmin == comp->initdoneAdmin) insert(items, INITDONEADMIN);
	if (initdoneBase == comp->initdoneBase) insert(items, INITDONEBASE);
	if (initdoneConnect == comp->initdoneConnect) insert(items, INITDONECONNECT);

	return(items);
};

set<uint> CrdBrlyNav::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEADMIN, INITDONEBASE, INITDONECONNECT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyNav::StatShr
 ******************************************************************************/

CrdBrlyNav::StatShr::StatShr(
			const string& scrJrefDlgloaini
			, const string& scrJrefHeadbar
			, const string& scrJrefAdmin
			, const bool pnladminAvail
			, const string& scrJrefBase
			, const bool pnlbaseAvail
			, const string& scrJrefConnect
			, const bool pnlconnectAvail
			, const bool MspCrd1Avail
			, const bool MitCrdUsgAvail
			, const bool MitCrdUsrAvail
			, const bool MitCrdPrsAvail
			, const bool MitCrdFilAvail
			, const bool MitCrdOprAvail
			, const bool MitCrdPtyAvail
			, const bool MspCrd2Avail
			, const bool MitCrdRegAvail
			, const bool MitCrdLocAvail
			, const bool MitCrdLegAvail
			, const bool MitCrdTtbAvail
			, const bool MitCrdFltAvail
			, const bool MspCrd3Avail
			, const bool MitCrdConAvail
			, const bool MspApp2Avail
			, const bool MitAppLoiAvail
		) : Block() {
	this->scrJrefDlgloaini = scrJrefDlgloaini;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefAdmin = scrJrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->scrJrefBase = scrJrefBase;
	this->pnlbaseAvail = pnlbaseAvail;
	this->scrJrefConnect = scrJrefConnect;
	this->pnlconnectAvail = pnlconnectAvail;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdUsgAvail = MitCrdUsgAvail;
	this->MitCrdUsrAvail = MitCrdUsrAvail;
	this->MitCrdPrsAvail = MitCrdPrsAvail;
	this->MitCrdFilAvail = MitCrdFilAvail;
	this->MitCrdOprAvail = MitCrdOprAvail;
	this->MitCrdPtyAvail = MitCrdPtyAvail;
	this->MspCrd2Avail = MspCrd2Avail;
	this->MitCrdRegAvail = MitCrdRegAvail;
	this->MitCrdLocAvail = MitCrdLocAvail;
	this->MitCrdLegAvail = MitCrdLegAvail;
	this->MitCrdTtbAvail = MitCrdTtbAvail;
	this->MitCrdFltAvail = MitCrdFltAvail;
	this->MspCrd3Avail = MspCrd3Avail;
	this->MitCrdConAvail = MitCrdConAvail;
	this->MspApp2Avail = MspApp2Avail;
	this->MitAppLoiAvail = MitAppLoiAvail;

	mask = {SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFBASE, PNLBASEAVAIL, SCRJREFCONNECT, PNLCONNECTAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MITCRDOPRAVAIL, MITCRDPTYAVAIL, MSPCRD2AVAIL, MITCRDREGAVAIL, MITCRDLOCAVAIL, MITCRDLEGAVAIL, MITCRDTTBAVAIL, MITCRDFLTAVAIL, MSPCRD3AVAIL, MITCRDCONAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

bool CrdBrlyNav::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgloaini", scrJrefDlgloaini)) add(SCRJREFDLGLOAINI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAdmin", scrJrefAdmin)) add(SCRJREFADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnladminAvail", pnladminAvail)) add(PNLADMINAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefBase", scrJrefBase)) add(SCRJREFBASE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlbaseAvail", pnlbaseAvail)) add(PNLBASEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefConnect", scrJrefConnect)) add(SCRJREFCONNECT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlconnectAvail", pnlconnectAvail)) add(PNLCONNECTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsgAvail", MitCrdUsgAvail)) add(MITCRDUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsrAvail", MitCrdUsrAvail)) add(MITCRDUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrsAvail", MitCrdPrsAvail)) add(MITCRDPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFilAvail", MitCrdFilAvail)) add(MITCRDFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdOprAvail", MitCrdOprAvail)) add(MITCRDOPRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPtyAvail", MitCrdPtyAvail)) add(MITCRDPTYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", MspCrd2Avail)) add(MSPCRD2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdRegAvail", MitCrdRegAvail)) add(MITCRDREGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdLocAvail", MitCrdLocAvail)) add(MITCRDLOCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdLegAvail", MitCrdLegAvail)) add(MITCRDLEGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTtbAvail", MitCrdTtbAvail)) add(MITCRDTTBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFltAvail", MitCrdFltAvail)) add(MITCRDFLTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", MspCrd3Avail)) add(MSPCRD3AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdConAvail", MitCrdConAvail)) add(MITCRDCONAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspApp2Avail", MspApp2Avail)) add(MSPAPP2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitAppLoiAvail", MitAppLoiAvail)) add(MITAPPLOIAVAIL);
	};

	return basefound;
};

set<uint> CrdBrlyNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgloaini.compare(comp->scrJrefDlgloaini) == 0) insert(items, SCRJREFDLGLOAINI);
	if (scrJrefHeadbar.compare(comp->scrJrefHeadbar) == 0) insert(items, SCRJREFHEADBAR);
	if (scrJrefAdmin.compare(comp->scrJrefAdmin) == 0) insert(items, SCRJREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (scrJrefBase.compare(comp->scrJrefBase) == 0) insert(items, SCRJREFBASE);
	if (pnlbaseAvail == comp->pnlbaseAvail) insert(items, PNLBASEAVAIL);
	if (scrJrefConnect.compare(comp->scrJrefConnect) == 0) insert(items, SCRJREFCONNECT);
	if (pnlconnectAvail == comp->pnlconnectAvail) insert(items, PNLCONNECTAVAIL);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUsgAvail == comp->MitCrdUsgAvail) insert(items, MITCRDUSGAVAIL);
	if (MitCrdUsrAvail == comp->MitCrdUsrAvail) insert(items, MITCRDUSRAVAIL);
	if (MitCrdPrsAvail == comp->MitCrdPrsAvail) insert(items, MITCRDPRSAVAIL);
	if (MitCrdFilAvail == comp->MitCrdFilAvail) insert(items, MITCRDFILAVAIL);
	if (MitCrdOprAvail == comp->MitCrdOprAvail) insert(items, MITCRDOPRAVAIL);
	if (MitCrdPtyAvail == comp->MitCrdPtyAvail) insert(items, MITCRDPTYAVAIL);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdRegAvail == comp->MitCrdRegAvail) insert(items, MITCRDREGAVAIL);
	if (MitCrdLocAvail == comp->MitCrdLocAvail) insert(items, MITCRDLOCAVAIL);
	if (MitCrdLegAvail == comp->MitCrdLegAvail) insert(items, MITCRDLEGAVAIL);
	if (MitCrdTtbAvail == comp->MitCrdTtbAvail) insert(items, MITCRDTTBAVAIL);
	if (MitCrdFltAvail == comp->MitCrdFltAvail) insert(items, MITCRDFLTAVAIL);
	if (MspCrd3Avail == comp->MspCrd3Avail) insert(items, MSPCRD3AVAIL);
	if (MitCrdConAvail == comp->MitCrdConAvail) insert(items, MITCRDCONAVAIL);
	if (MspApp2Avail == comp->MspApp2Avail) insert(items, MSPAPP2AVAIL);
	if (MitAppLoiAvail == comp->MitAppLoiAvail) insert(items, MITAPPLOIAVAIL);

	return(items);
};

set<uint> CrdBrlyNav::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFBASE, PNLBASEAVAIL, SCRJREFCONNECT, PNLCONNECTAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MITCRDOPRAVAIL, MITCRDPTYAVAIL, MSPCRD2AVAIL, MITCRDREGAVAIL, MITCRDLOCAVAIL, MITCRDLEGAVAIL, MITCRDTTBAVAIL, MITCRDFLTAVAIL, MSPCRD3AVAIL, MITCRDCONAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyNav::Tag
 ******************************************************************************/

CrdBrlyNav::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitSesTrm
			, const string& MitCrdUsg
			, const string& MitCrdUsr
			, const string& MitCrdPrs
			, const string& MitCrdFil
			, const string& MitCrdOpr
			, const string& MitCrdPty
			, const string& MitCrdReg
			, const string& MitCrdLoc
			, const string& MitCrdLeg
			, const string& MitCrdTtb
			, const string& MitCrdFlt
			, const string& MitCrdCon
			, const string& MitAppLoi
		) : Block() {
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitSesTrm = MitSesTrm;
	this->MitCrdUsg = MitCrdUsg;
	this->MitCrdUsr = MitCrdUsr;
	this->MitCrdPrs = MitCrdPrs;
	this->MitCrdFil = MitCrdFil;
	this->MitCrdOpr = MitCrdOpr;
	this->MitCrdPty = MitCrdPty;
	this->MitCrdReg = MitCrdReg;
	this->MitCrdLoc = MitCrdLoc;
	this->MitCrdLeg = MitCrdLeg;
	this->MitCrdTtb = MitCrdTtb;
	this->MitCrdFlt = MitCrdFlt;
	this->MitCrdCon = MitCrdCon;
	this->MitAppLoi = MitAppLoi;

	mask = {MITAPPABT, MRLAPPHLP, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDFIL, MITCRDOPR, MITCRDPTY, MITCRDREG, MITCRDLOC, MITCRDLEG, MITCRDTTB, MITCRDFLT, MITCRDCON, MITAPPLOI};
};

bool CrdBrlyNav::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesTrm", MitSesTrm)) add(MITSESTRM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsg", MitCrdUsg)) add(MITCRDUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsr", MitCrdUsr)) add(MITCRDUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrs", MitCrdPrs)) add(MITCRDPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFil", MitCrdFil)) add(MITCRDFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdOpr", MitCrdOpr)) add(MITCRDOPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPty", MitCrdPty)) add(MITCRDPTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdReg", MitCrdReg)) add(MITCRDREG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdLoc", MitCrdLoc)) add(MITCRDLOC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdLeg", MitCrdLeg)) add(MITCRDLEG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdTtb", MitCrdTtb)) add(MITCRDTTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFlt", MitCrdFlt)) add(MITCRDFLT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCon", MitCrdCon)) add(MITCRDCON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppLoi", MitAppLoi)) add(MITAPPLOI);
	};

	return basefound;
};

/******************************************************************************
 class CrdBrlyNav::DpchAppDo
 ******************************************************************************/

CrdBrlyNav::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdBrlyNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdBrlyNav::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyNavDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdBrlyNav::DpchEngData
 ******************************************************************************/

CrdBrlyNav::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYNAVDATA) {
	feedFSge.tag = "FeedFSge";
};

string CrdBrlyNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdBrlyNav::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyNavData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

