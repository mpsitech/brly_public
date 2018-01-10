/**
  * \file PnlBrlyLegOrgMNLeg.cpp
  * API code for job PnlBrlyLegOrgMNLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyLegOrgMNLeg.h"

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::VecVDo
 ******************************************************************************/

uint PnlBrlyLegOrgMNLeg::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	else if (s == "butaddclick") return BUTADDCLICK;
	else if (s == "butsubclick") return BUTSUBCLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyLegOrgMNLeg::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	else if (ix == BUTADDCLICK) return("ButAddClick");
	else if (ix == BUTSUBCLICK) return("ButSubClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::ContInf
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlBrlyLegOrgMNLeg::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyLegOrgMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyLegOrgMNLeg";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlBrlyLegOrgMNLeg::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlyLegOrgMNLeg::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::StatApp
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::StatApp::StatApp(
			const uint ixBrlyVExpstate
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;

	mask = {IXBRLYVEXPSTATE};
};

bool PnlBrlyLegOrgMNLeg::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyLegOrgMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyLegOrgMNLeg";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlBrlyLegOrgMNLeg::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);

	return(items);
};

set<uint> PnlBrlyLegOrgMNLeg::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::StatShr
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::StatShr::StatShr(
			const bool ButViewAvail
			, const bool ButViewActive
			, const bool ButAddAvail
			, const bool ButSubAvail
			, const bool ButSubActive
		) : Block() {
	this->ButViewAvail = ButViewAvail;
	this->ButViewActive = ButViewActive;
	this->ButAddAvail = ButAddAvail;
	this->ButSubAvail = ButSubAvail;
	this->ButSubActive = ButSubActive;

	mask = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
};

bool PnlBrlyLegOrgMNLeg::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyLegOrgMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyLegOrgMNLeg";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButViewAvail", ButViewAvail)) add(BUTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButViewActive", ButViewActive)) add(BUTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAddAvail", ButAddAvail)) add(BUTADDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSubAvail", ButSubAvail)) add(BUTSUBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSubActive", ButSubActive)) add(BUTSUBACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyLegOrgMNLeg::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewAvail == comp->ButViewAvail) insert(items, BUTVIEWAVAIL);
	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);
	if (ButAddAvail == comp->ButAddAvail) insert(items, BUTADDAVAIL);
	if (ButSubAvail == comp->ButSubAvail) insert(items, BUTSUBAVAIL);
	if (ButSubActive == comp->ButSubActive) insert(items, BUTSUBACTIVE);

	return(items);
};

set<uint> PnlBrlyLegOrgMNLeg::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::StgIac
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::StgIac::StgIac(
			const uint TcoMrefWidth
			, const uint TcoDp0Width
			, const uint TcoDp1Width
			, const uint TcoOp0Width
			, const uint TcoOp1Width
			, const uint TcoXd0Width
			, const uint TcoXd1Width
			, const uint TcoXo0Width
			, const uint TcoXo1Width
		) : Block() {
	this->TcoMrefWidth = TcoMrefWidth;
	this->TcoDp0Width = TcoDp0Width;
	this->TcoDp1Width = TcoDp1Width;
	this->TcoOp0Width = TcoOp0Width;
	this->TcoOp1Width = TcoOp1Width;
	this->TcoXd0Width = TcoXd0Width;
	this->TcoXd1Width = TcoXd1Width;
	this->TcoXo0Width = TcoXo0Width;
	this->TcoXo1Width = TcoXo1Width;

	mask = {TCOMREFWIDTH, TCODP0WIDTH, TCODP1WIDTH, TCOOP0WIDTH, TCOOP1WIDTH, TCOXD0WIDTH, TCOXD1WIDTH, TCOXO0WIDTH, TCOXO1WIDTH};
};

bool PnlBrlyLegOrgMNLeg::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyLegOrgMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyLegOrgMNLeg";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", TcoMrefWidth)) add(TCOMREFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDp0Width", TcoDp0Width)) add(TCODP0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDp1Width", TcoDp1Width)) add(TCODP1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoOp0Width", TcoOp0Width)) add(TCOOP0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoOp1Width", TcoOp1Width)) add(TCOOP1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXd0Width", TcoXd0Width)) add(TCOXD0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXd1Width", TcoXd1Width)) add(TCOXD1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXo0Width", TcoXo0Width)) add(TCOXO0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXo1Width", TcoXo1Width)) add(TCOXO1WIDTH);
	};

	return basefound;
};

void PnlBrlyLegOrgMNLeg::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLegOrgMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyLegOrgMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDp0Width", TcoDp0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoDp1Width", TcoDp1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoOp0Width", TcoOp0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoOp1Width", TcoOp1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoXd0Width", TcoXd0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoXd1Width", TcoXd1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoXo0Width", TcoXo0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoXo1Width", TcoXo1Width);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegOrgMNLeg::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoMrefWidth == comp->TcoMrefWidth) insert(items, TCOMREFWIDTH);
	if (TcoDp0Width == comp->TcoDp0Width) insert(items, TCODP0WIDTH);
	if (TcoDp1Width == comp->TcoDp1Width) insert(items, TCODP1WIDTH);
	if (TcoOp0Width == comp->TcoOp0Width) insert(items, TCOOP0WIDTH);
	if (TcoOp1Width == comp->TcoOp1Width) insert(items, TCOOP1WIDTH);
	if (TcoXd0Width == comp->TcoXd0Width) insert(items, TCOXD0WIDTH);
	if (TcoXd1Width == comp->TcoXd1Width) insert(items, TCOXD1WIDTH);
	if (TcoXo0Width == comp->TcoXo0Width) insert(items, TCOXO0WIDTH);
	if (TcoXo1Width == comp->TcoXo1Width) insert(items, TCOXO1WIDTH);

	return(items);
};

set<uint> PnlBrlyLegOrgMNLeg::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOMREFWIDTH, TCODP0WIDTH, TCODP1WIDTH, TCOOP0WIDTH, TCOOP1WIDTH, TCOXD0WIDTH, TCOXD1WIDTH, TCOXO0WIDTH, TCOXO1WIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::Tag
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoMref
			, const string& TcoDp0
			, const string& TcoDp1
			, const string& TcoOp0
			, const string& TcoOp1
			, const string& TcoXd0
			, const string& TcoXd1
			, const string& TcoXo0
			, const string& TcoXo1
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoMref = TcoMref;
	this->TcoDp0 = TcoDp0;
	this->TcoDp1 = TcoDp1;
	this->TcoOp0 = TcoOp0;
	this->TcoOp1 = TcoOp1;
	this->TcoXd0 = TcoXd0;
	this->TcoXd1 = TcoXd1;
	this->TcoXo0 = TcoXo0;
	this->TcoXo1 = TcoXo1;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF, TCODP0, TCODP1, TCOOP0, TCOOP1, TCOXD0, TCOXD1, TCOXO0, TCOXO1};
};

bool PnlBrlyLegOrgMNLeg::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyLegOrgMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyLegOrgMNLeg";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoMref", TcoMref)) add(TCOMREF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoDp0", TcoDp0)) add(TCODP0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoDp1", TcoDp1)) add(TCODP1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoOp0", TcoOp0)) add(TCOOP0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoOp1", TcoOp1)) add(TCOOP1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoXd0", TcoXd0)) add(TCOXD0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoXd1", TcoXd1)) add(TCOXD1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoXo0", TcoXo0)) add(TCOXO0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoXo1", TcoXo1)) add(TCOXO1);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::DpchAppData
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryBrlyLegOrgMNLeg::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGORGMNLEGDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlBrlyLegOrgMNLeg::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegOrgMNLeg::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLegOrgMNLegData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::DpchAppDo
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGORGMNLEGDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyLegOrgMNLeg::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegOrgMNLeg::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLegOrgMNLegDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::DpchEngData
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGORGMNLEGDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlBrlyLegOrgMNLeg::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegOrgMNLeg::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLegOrgMNLegData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFCsiQst.readXML(docctx, basexpath, true)) add(FEEDFCSIQST);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rst.readXML(docctx, basexpath, true)) add(RST);
		if (statappqry.readXML(docctx, basexpath, true)) add(STATAPPQRY);
		if (statshrqry.readXML(docctx, basexpath, true)) add(STATSHRQRY);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		continf = ContInf();
		feedFCsiQst.clear();
		statapp = StatApp();
		statshr = StatShr();
		stgiac = StgIac();
		tag = Tag();
		rst.clear();
		statappqry = QryBrlyLegOrgMNLeg::StatApp();
		statshrqry = QryBrlyLegOrgMNLeg::StatShr();
		stgiacqry = QryBrlyLegOrgMNLeg::StgIac();
	};
};

