/**
  * \file PnlBrlyLocMNLeg.cpp
  * API code for job PnlBrlyLocMNLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyLocMNLeg.h"

/******************************************************************************
 class PnlBrlyLocMNLeg::VecVDo
 ******************************************************************************/

uint PnlBrlyLocMNLeg::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	else if (s == "butaddclick") return BUTADDCLICK;
	else if (s == "butsubclick") return BUTSUBCLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyLocMNLeg::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	else if (ix == BUTADDCLICK) return("ButAddClick");
	else if (ix == BUTSUBCLICK) return("ButSubClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLocMNLeg::ContInf
 ******************************************************************************/

PnlBrlyLocMNLeg::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlBrlyLocMNLeg::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyLocMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyLocMNLeg";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlBrlyLocMNLeg::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlyLocMNLeg::ContInf::diff(
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
 class PnlBrlyLocMNLeg::StatApp
 ******************************************************************************/

PnlBrlyLocMNLeg::StatApp::StatApp(
			const uint ixBrlyVExpstate
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;

	mask = {IXBRLYVEXPSTATE};
};

bool PnlBrlyLocMNLeg::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyLocMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyLocMNLeg";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlBrlyLocMNLeg::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);

	return(items);
};

set<uint> PnlBrlyLocMNLeg::StatApp::diff(
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
 class PnlBrlyLocMNLeg::StatShr
 ******************************************************************************/

PnlBrlyLocMNLeg::StatShr::StatShr(
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

bool PnlBrlyLocMNLeg::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyLocMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyLocMNLeg";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButViewAvail", ButViewAvail)) add(BUTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButViewActive", ButViewActive)) add(BUTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAddAvail", ButAddAvail)) add(BUTADDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSubAvail", ButSubAvail)) add(BUTSUBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSubActive", ButSubActive)) add(BUTSUBACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyLocMNLeg::StatShr::comm(
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

set<uint> PnlBrlyLocMNLeg::StatShr::diff(
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
 class PnlBrlyLocMNLeg::StgIac
 ******************************************************************************/

PnlBrlyLocMNLeg::StgIac::StgIac(
			const uint TcoMrefWidth
			, const uint TcoLp0Width
			, const uint TcoLp1Width
			, const uint TcoLphWidth
			, const uint TcoLthWidth
			, const uint TcoXp0Width
			, const uint TcoXp1Width
		) : Block() {
	this->TcoMrefWidth = TcoMrefWidth;
	this->TcoLp0Width = TcoLp0Width;
	this->TcoLp1Width = TcoLp1Width;
	this->TcoLphWidth = TcoLphWidth;
	this->TcoLthWidth = TcoLthWidth;
	this->TcoXp0Width = TcoXp0Width;
	this->TcoXp1Width = TcoXp1Width;

	mask = {TCOMREFWIDTH, TCOLP0WIDTH, TCOLP1WIDTH, TCOLPHWIDTH, TCOLTHWIDTH, TCOXP0WIDTH, TCOXP1WIDTH};
};

bool PnlBrlyLocMNLeg::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyLocMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyLocMNLeg";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", TcoMrefWidth)) add(TCOMREFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLp0Width", TcoLp0Width)) add(TCOLP0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLp1Width", TcoLp1Width)) add(TCOLP1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLphWidth", TcoLphWidth)) add(TCOLPHWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLthWidth", TcoLthWidth)) add(TCOLTHWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXp0Width", TcoXp0Width)) add(TCOXP0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXp1Width", TcoXp1Width)) add(TCOXP1WIDTH);
	};

	return basefound;
};

void PnlBrlyLocMNLeg::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLocMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyLocMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLp0Width", TcoLp0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoLp1Width", TcoLp1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoLphWidth", TcoLphWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLthWidth", TcoLthWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoXp0Width", TcoXp0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoXp1Width", TcoXp1Width);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocMNLeg::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoMrefWidth == comp->TcoMrefWidth) insert(items, TCOMREFWIDTH);
	if (TcoLp0Width == comp->TcoLp0Width) insert(items, TCOLP0WIDTH);
	if (TcoLp1Width == comp->TcoLp1Width) insert(items, TCOLP1WIDTH);
	if (TcoLphWidth == comp->TcoLphWidth) insert(items, TCOLPHWIDTH);
	if (TcoLthWidth == comp->TcoLthWidth) insert(items, TCOLTHWIDTH);
	if (TcoXp0Width == comp->TcoXp0Width) insert(items, TCOXP0WIDTH);
	if (TcoXp1Width == comp->TcoXp1Width) insert(items, TCOXP1WIDTH);

	return(items);
};

set<uint> PnlBrlyLocMNLeg::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOMREFWIDTH, TCOLP0WIDTH, TCOLP1WIDTH, TCOLPHWIDTH, TCOLTHWIDTH, TCOXP0WIDTH, TCOXP1WIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocMNLeg::Tag
 ******************************************************************************/

PnlBrlyLocMNLeg::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoMref
			, const string& TcoLp0
			, const string& TcoLp1
			, const string& TcoLph
			, const string& TcoLth
			, const string& TcoXp0
			, const string& TcoXp1
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoMref = TcoMref;
	this->TcoLp0 = TcoLp0;
	this->TcoLp1 = TcoLp1;
	this->TcoLph = TcoLph;
	this->TcoLth = TcoLth;
	this->TcoXp0 = TcoXp0;
	this->TcoXp1 = TcoXp1;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF, TCOLP0, TCOLP1, TCOLPH, TCOLTH, TCOXP0, TCOXP1};
};

bool PnlBrlyLocMNLeg::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyLocMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyLocMNLeg";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoMref", TcoMref)) add(TCOMREF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoLp0", TcoLp0)) add(TCOLP0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoLp1", TcoLp1)) add(TCOLP1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoLph", TcoLph)) add(TCOLPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoLth", TcoLth)) add(TCOLTH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoXp0", TcoXp0)) add(TCOXP0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoXp1", TcoXp1)) add(TCOXP1);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyLocMNLeg::DpchAppData
 ******************************************************************************/

PnlBrlyLocMNLeg::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryBrlyLocMNLeg::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCMNLEGDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlBrlyLocMNLeg::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMNLeg::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLocMNLegData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocMNLeg::DpchAppDo
 ******************************************************************************/

PnlBrlyLocMNLeg::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCMNLEGDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyLocMNLeg::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMNLeg::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLocMNLegDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocMNLeg::DpchEngData
 ******************************************************************************/

PnlBrlyLocMNLeg::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCMNLEGDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlBrlyLocMNLeg::DpchEngData::getSrefsMask() {
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

void PnlBrlyLocMNLeg::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLocMNLegData");
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
		statappqry = QryBrlyLocMNLeg::StatApp();
		statshrqry = QryBrlyLocMNLeg::StatShr();
		stgiacqry = QryBrlyLocMNLeg::StgIac();
	};
};

