/**
  * \file PnlBrlyLocMNSegment.cpp
  * API code for job PnlBrlyLocMNSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyLocMNSegment.h"

/******************************************************************************
 class PnlBrlyLocMNSegment::VecVDo
 ******************************************************************************/

uint PnlBrlyLocMNSegment::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butaddclick") return BUTADDCLICK;
	else if (s == "butsubclick") return BUTSUBCLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyLocMNSegment::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTADDCLICK) return("ButAddClick");
	else if (ix == BUTSUBCLICK) return("ButSubClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLocMNSegment::ContInf
 ******************************************************************************/

PnlBrlyLocMNSegment::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlBrlyLocMNSegment::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyLocMNSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyLocMNSegment";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlBrlyLocMNSegment::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlyLocMNSegment::ContInf::diff(
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
 class PnlBrlyLocMNSegment::StatApp
 ******************************************************************************/

PnlBrlyLocMNSegment::StatApp::StatApp(
			const uint ixBrlyVExpstate
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;

	mask = {IXBRLYVEXPSTATE};
};

bool PnlBrlyLocMNSegment::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyLocMNSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyLocMNSegment";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlBrlyLocMNSegment::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);

	return(items);
};

set<uint> PnlBrlyLocMNSegment::StatApp::diff(
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
 class PnlBrlyLocMNSegment::StatShr
 ******************************************************************************/

PnlBrlyLocMNSegment::StatShr::StatShr(
			const bool ButAddAvail
			, const bool ButSubAvail
			, const bool ButSubActive
		) : Block() {
	this->ButAddAvail = ButAddAvail;
	this->ButSubAvail = ButSubAvail;
	this->ButSubActive = ButSubActive;

	mask = {BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
};

bool PnlBrlyLocMNSegment::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyLocMNSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyLocMNSegment";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAddAvail", ButAddAvail)) add(BUTADDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSubAvail", ButSubAvail)) add(BUTSUBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSubActive", ButSubActive)) add(BUTSUBACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyLocMNSegment::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButAddAvail == comp->ButAddAvail) insert(items, BUTADDAVAIL);
	if (ButSubAvail == comp->ButSubAvail) insert(items, BUTSUBAVAIL);
	if (ButSubActive == comp->ButSubActive) insert(items, BUTSUBACTIVE);

	return(items);
};

set<uint> PnlBrlyLocMNSegment::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocMNSegment::StgIac
 ******************************************************************************/

PnlBrlyLocMNSegment::StgIac::StgIac(
			const uint TcoMrefWidth
			, const uint TcoStaWidth
			, const uint TcoStoWidth
			, const uint TcoSp0Width
			, const uint TcoSp1Width
			, const uint TcoSphWidth
			, const uint TcoSthWidth
		) : Block() {
	this->TcoMrefWidth = TcoMrefWidth;
	this->TcoStaWidth = TcoStaWidth;
	this->TcoStoWidth = TcoStoWidth;
	this->TcoSp0Width = TcoSp0Width;
	this->TcoSp1Width = TcoSp1Width;
	this->TcoSphWidth = TcoSphWidth;
	this->TcoSthWidth = TcoSthWidth;

	mask = {TCOMREFWIDTH, TCOSTAWIDTH, TCOSTOWIDTH, TCOSP0WIDTH, TCOSP1WIDTH, TCOSPHWIDTH, TCOSTHWIDTH};
};

bool PnlBrlyLocMNSegment::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyLocMNSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyLocMNSegment";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", TcoMrefWidth)) add(TCOMREFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoStaWidth", TcoStaWidth)) add(TCOSTAWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoStoWidth", TcoStoWidth)) add(TCOSTOWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSp0Width", TcoSp0Width)) add(TCOSP0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSp1Width", TcoSp1Width)) add(TCOSP1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSphWidth", TcoSphWidth)) add(TCOSPHWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSthWidth", TcoSthWidth)) add(TCOSTHWIDTH);
	};

	return basefound;
};

void PnlBrlyLocMNSegment::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLocMNSegment";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyLocMNSegment";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoStaWidth", TcoStaWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoStoWidth", TcoStoWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSp0Width", TcoSp0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoSp1Width", TcoSp1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoSphWidth", TcoSphWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSthWidth", TcoSthWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocMNSegment::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoMrefWidth == comp->TcoMrefWidth) insert(items, TCOMREFWIDTH);
	if (TcoStaWidth == comp->TcoStaWidth) insert(items, TCOSTAWIDTH);
	if (TcoStoWidth == comp->TcoStoWidth) insert(items, TCOSTOWIDTH);
	if (TcoSp0Width == comp->TcoSp0Width) insert(items, TCOSP0WIDTH);
	if (TcoSp1Width == comp->TcoSp1Width) insert(items, TCOSP1WIDTH);
	if (TcoSphWidth == comp->TcoSphWidth) insert(items, TCOSPHWIDTH);
	if (TcoSthWidth == comp->TcoSthWidth) insert(items, TCOSTHWIDTH);

	return(items);
};

set<uint> PnlBrlyLocMNSegment::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOMREFWIDTH, TCOSTAWIDTH, TCOSTOWIDTH, TCOSP0WIDTH, TCOSP1WIDTH, TCOSPHWIDTH, TCOSTHWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocMNSegment::Tag
 ******************************************************************************/

PnlBrlyLocMNSegment::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoMref
			, const string& TcoSta
			, const string& TcoSto
			, const string& TcoSp0
			, const string& TcoSp1
			, const string& TcoSph
			, const string& TcoSth
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoMref = TcoMref;
	this->TcoSta = TcoSta;
	this->TcoSto = TcoSto;
	this->TcoSp0 = TcoSp0;
	this->TcoSp1 = TcoSp1;
	this->TcoSph = TcoSph;
	this->TcoSth = TcoSth;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF, TCOSTA, TCOSTO, TCOSP0, TCOSP1, TCOSPH, TCOSTH};
};

bool PnlBrlyLocMNSegment::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyLocMNSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyLocMNSegment";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoMref", TcoMref)) add(TCOMREF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSta", TcoSta)) add(TCOSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSto", TcoSto)) add(TCOSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSp0", TcoSp0)) add(TCOSP0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSp1", TcoSp1)) add(TCOSP1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSph", TcoSph)) add(TCOSPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSth", TcoSth)) add(TCOSTH);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyLocMNSegment::DpchAppData
 ******************************************************************************/

PnlBrlyLocMNSegment::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryBrlyLocMNSegment::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCMNSEGMENTDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlBrlyLocMNSegment::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMNSegment::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLocMNSegmentData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocMNSegment::DpchAppDo
 ******************************************************************************/

PnlBrlyLocMNSegment::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCMNSEGMENTDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyLocMNSegment::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMNSegment::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLocMNSegmentDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocMNSegment::DpchEngData
 ******************************************************************************/

PnlBrlyLocMNSegment::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCMNSEGMENTDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlBrlyLocMNSegment::DpchEngData::getSrefsMask() {
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

void PnlBrlyLocMNSegment::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLocMNSegmentData");
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
		statappqry = QryBrlyLocMNSegment::StatApp();
		statshrqry = QryBrlyLocMNSegment::StatShr();
		stgiacqry = QryBrlyLocMNSegment::StgIac();
	};
};

