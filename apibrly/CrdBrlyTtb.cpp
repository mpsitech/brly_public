/**
  * \file CrdBrlyTtb.cpp
  * API code for job CrdBrlyTtb (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "CrdBrlyTtb.h"

/******************************************************************************
 class CrdBrlyTtb::VecVDo
 ******************************************************************************/

uint CrdBrlyTtb::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	else if (s == "mitappabtclick") return MITAPPABTCLICK;
	else if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	else if (s == "mitcrdtrlclick") return MITCRDTRLCLICK;
	else if (s == "mitcrdiflclick") return MITCRDIFLCLICK;

	return(0);
};

string CrdBrlyTtb::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	else if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	else if (ix == MITCRDTRLCLICK) return("MitCrdTrlClick");
	else if (ix == MITCRDIFLCLICK) return("MitCrdIflClick");

	return("");
};

/******************************************************************************
 class CrdBrlyTtb::VecVSge
 ******************************************************************************/

uint CrdBrlyTtb::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "alrbrlyabt") return ALRBRLYABT;
	else if (s == "close") return CLOSE;
	else if (s == "impidle") return IMPIDLE;
	else if (s == "import") return IMPORT;
	else if (s == "impdone") return IMPDONE;
	else if (s == "segment") return SEGMENT;
	else if (s == "segdone") return SEGDONE;

	return(0);
};

string CrdBrlyTtb::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRBRLYABT) return("alrbrlyabt");
	else if (ix == CLOSE) return("close");
	else if (ix == IMPIDLE) return("impidle");
	else if (ix == IMPORT) return("import");
	else if (ix == IMPDONE) return("impdone");
	else if (ix == SEGMENT) return("segment");
	else if (ix == SEGDONE) return("segdone");

	return("");
};

/******************************************************************************
 class CrdBrlyTtb::ContInf
 ******************************************************************************/

CrdBrlyTtb::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdTtb
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdTtb = MtxCrdTtb;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDTTB};
};

bool CrdBrlyTtb::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyTtb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyTtb";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdTtb", MtxCrdTtb)) add(MTXCRDTTB);
	};

	return basefound;
};

set<uint> CrdBrlyTtb::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp.compare(comp->MrlAppHlp) == 0) insert(items, MRLAPPHLP);
	if (MtxCrdTtb.compare(comp->MtxCrdTtb) == 0) insert(items, MTXCRDTTB);

	return(items);
};

set<uint> CrdBrlyTtb::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDTTB};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyTtb::StatApp
 ******************************************************************************/

CrdBrlyTtb::StatApp::StatApp(
			const uint ixBrlyVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) : Block() {
	this->ixBrlyVReqitmode = ixBrlyVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdoneList = initdoneList;
	this->initdoneRec = initdoneRec;

	mask = {IXBRLYVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdBrlyTtb::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyTtb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyTtb";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVReqitmode", srefIxBrlyVReqitmode)) {
			ixBrlyVReqitmode = VecBrlyVReqitmode::getIx(srefIxBrlyVReqitmode);
			add(IXBRLYVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneList", initdoneList)) add(INITDONELIST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRec", initdoneRec)) add(INITDONEREC);
	};

	return basefound;
};

set<uint> CrdBrlyTtb::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVReqitmode == comp->ixBrlyVReqitmode) insert(items, IXBRLYVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneList == comp->initdoneList) insert(items, INITDONELIST);
	if (initdoneRec == comp->initdoneRec) insert(items, INITDONEREC);

	return(items);
};

set<uint> CrdBrlyTtb::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyTtb::StatShr
 ******************************************************************************/

CrdBrlyTtb::StatShr::StatShr(
			const string& scrJrefDlgimpflt
			, const string& scrJrefDlgnew
			, const string& scrJrefDlgtrlorig
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdTrlAvail
			, const bool MitCrdIflAvail
			, const bool MitCrdIflActive
		) : Block() {
	this->scrJrefDlgimpflt = scrJrefDlgimpflt;
	this->scrJrefDlgnew = scrJrefDlgnew;
	this->scrJrefDlgtrlorig = scrJrefDlgtrlorig;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdNewAvail = MitCrdNewAvail;
	this->MitCrdTrlAvail = MitCrdTrlAvail;
	this->MitCrdIflAvail = MitCrdIflAvail;
	this->MitCrdIflActive = MitCrdIflActive;

	mask = {SCRJREFDLGIMPFLT, SCRJREFDLGNEW, SCRJREFDLGTRLORIG, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDTRLAVAIL, MITCRDIFLAVAIL, MITCRDIFLACTIVE};
};

bool CrdBrlyTtb::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyTtb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyTtb";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgimpflt", scrJrefDlgimpflt)) add(SCRJREFDLGIMPFLT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", scrJrefDlgnew)) add(SCRJREFDLGNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgtrlorig", scrJrefDlgtrlorig)) add(SCRJREFDLGTRLORIG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", MitCrdNewAvail)) add(MITCRDNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTrlAvail", MitCrdTrlAvail)) add(MITCRDTRLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIflAvail", MitCrdIflAvail)) add(MITCRDIFLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIflActive", MitCrdIflActive)) add(MITCRDIFLACTIVE);
	};

	return basefound;
};

set<uint> CrdBrlyTtb::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgimpflt.compare(comp->scrJrefDlgimpflt) == 0) insert(items, SCRJREFDLGIMPFLT);
	if (scrJrefDlgnew.compare(comp->scrJrefDlgnew) == 0) insert(items, SCRJREFDLGNEW);
	if (scrJrefDlgtrlorig.compare(comp->scrJrefDlgtrlorig) == 0) insert(items, SCRJREFDLGTRLORIG);
	if (scrJrefHeadbar.compare(comp->scrJrefHeadbar) == 0) insert(items, SCRJREFHEADBAR);
	if (scrJrefList.compare(comp->scrJrefList) == 0) insert(items, SCRJREFLIST);
	if (scrJrefRec.compare(comp->scrJrefRec) == 0) insert(items, SCRJREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdTrlAvail == comp->MitCrdTrlAvail) insert(items, MITCRDTRLAVAIL);
	if (MitCrdIflAvail == comp->MitCrdIflAvail) insert(items, MITCRDIFLAVAIL);
	if (MitCrdIflActive == comp->MitCrdIflActive) insert(items, MITCRDIFLACTIVE);

	return(items);
};

set<uint> CrdBrlyTtb::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGIMPFLT, SCRJREFDLGNEW, SCRJREFDLGTRLORIG, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDTRLAVAIL, MITCRDIFLAVAIL, MITCRDIFLACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyTtb::Tag
 ******************************************************************************/

CrdBrlyTtb::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdNew
			, const string& MitCrdTrl
			, const string& MitCrdIfl
		) : Block() {
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitCrdNew = MitCrdNew;
	this->MitCrdTrl = MitCrdTrl;
	this->MitCrdIfl = MitCrdIfl;

	mask = {MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDTRL, MITCRDIFL};
};

bool CrdBrlyTtb::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyTtb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyTtb";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdNew", MitCrdNew)) add(MITCRDNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdTrl", MitCrdTrl)) add(MITCRDTRL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIfl", MitCrdIfl)) add(MITCRDIFL);
	};

	return basefound;
};

/******************************************************************************
 class CrdBrlyTtb::DpchAppDo
 ******************************************************************************/

CrdBrlyTtb::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYTTBDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdBrlyTtb::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdBrlyTtb::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyTtbDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdBrlyTtb::DpchEngData
 ******************************************************************************/

CrdBrlyTtb::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYTTBDATA) {
	feedFSge.tag = "FeedFSge";
};

string CrdBrlyTtb::DpchEngData::getSrefsMask() {
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

void CrdBrlyTtb::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyTtbData");
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

