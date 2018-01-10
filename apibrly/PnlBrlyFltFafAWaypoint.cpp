/**
  * \file PnlBrlyFltFafAWaypoint.cpp
  * API code for job PnlBrlyFltFafAWaypoint (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyFltFafAWaypoint.h"

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::VecVDo
 ******************************************************************************/

uint PnlBrlyFltFafAWaypoint::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butupclick") return BUTUPCLICK;
	else if (s == "butdownclick") return BUTDOWNCLICK;
	else if (s == "butnewclick") return BUTNEWCLICK;
	else if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	else if (s == "butdeleteclick") return BUTDELETECLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyFltFafAWaypoint::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUPCLICK) return("ButUpClick");
	else if (ix == BUTDOWNCLICK) return("ButDownClick");
	else if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::ContInf
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlBrlyFltFafAWaypoint::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyFltFafAWaypoint");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyFltFafAWaypoint";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlBrlyFltFafAWaypoint::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlyFltFafAWaypoint::ContInf::diff(
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
 class PnlBrlyFltFafAWaypoint::StatApp
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::StatApp::StatApp(
			const uint ixBrlyVExpstate
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;

	mask = {IXBRLYVEXPSTATE};
};

bool PnlBrlyFltFafAWaypoint::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyFltFafAWaypoint");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyFltFafAWaypoint";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlBrlyFltFafAWaypoint::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);

	return(items);
};

set<uint> PnlBrlyFltFafAWaypoint::StatApp::diff(
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
 class PnlBrlyFltFafAWaypoint::StatShr
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::StatShr::StatShr(
			const bool ButUpAvail
			, const bool ButUpActive
			, const bool ButDownAvail
			, const bool ButDownActive
			, const bool ButNewAvail
			, const bool ButDuplicateAvail
			, const bool ButDuplicateActive
			, const bool ButDeleteAvail
			, const bool ButDeleteActive
		) : Block() {
	this->ButUpAvail = ButUpAvail;
	this->ButUpActive = ButUpActive;
	this->ButDownAvail = ButDownAvail;
	this->ButDownActive = ButDownActive;
	this->ButNewAvail = ButNewAvail;
	this->ButDuplicateAvail = ButDuplicateAvail;
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteAvail = ButDeleteAvail;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE};
};

bool PnlBrlyFltFafAWaypoint::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyFltFafAWaypoint");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyFltFafAWaypoint";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUpAvail", ButUpAvail)) add(BUTUPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUpActive", ButUpActive)) add(BUTUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDownAvail", ButDownAvail)) add(BUTDOWNAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDownActive", ButDownActive)) add(BUTDOWNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButNewAvail", ButNewAvail)) add(BUTNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateAvail", ButDuplicateAvail)) add(BUTDUPLICATEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", ButDuplicateActive)) add(BUTDUPLICATEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteAvail", ButDeleteAvail)) add(BUTDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyFltFafAWaypoint::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUpAvail == comp->ButUpAvail) insert(items, BUTUPAVAIL);
	if (ButUpActive == comp->ButUpActive) insert(items, BUTUPACTIVE);
	if (ButDownAvail == comp->ButDownAvail) insert(items, BUTDOWNAVAIL);
	if (ButDownActive == comp->ButDownActive) insert(items, BUTDOWNACTIVE);
	if (ButNewAvail == comp->ButNewAvail) insert(items, BUTNEWAVAIL);
	if (ButDuplicateAvail == comp->ButDuplicateAvail) insert(items, BUTDUPLICATEAVAIL);
	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteAvail == comp->ButDeleteAvail) insert(items, BUTDELETEAVAIL);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlBrlyFltFafAWaypoint::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::StgIac
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::StgIac::StgIac(
			const uint TcoTmsWidth
			, const uint TcoLatWidth
			, const uint TcoLonWidth
			, const uint TcoGspWidth
			, const uint TcoAltWidth
			, const uint TcoAstWidth
			, const uint TcoUtyWidth
			, const uint TcoAchWidth
		) : Block() {
	this->TcoTmsWidth = TcoTmsWidth;
	this->TcoLatWidth = TcoLatWidth;
	this->TcoLonWidth = TcoLonWidth;
	this->TcoGspWidth = TcoGspWidth;
	this->TcoAltWidth = TcoAltWidth;
	this->TcoAstWidth = TcoAstWidth;
	this->TcoUtyWidth = TcoUtyWidth;
	this->TcoAchWidth = TcoAchWidth;

	mask = {TCOTMSWIDTH, TCOLATWIDTH, TCOLONWIDTH, TCOGSPWIDTH, TCOALTWIDTH, TCOASTWIDTH, TCOUTYWIDTH, TCOACHWIDTH};
};

bool PnlBrlyFltFafAWaypoint::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyFltFafAWaypoint");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyFltFafAWaypoint";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTmsWidth", TcoTmsWidth)) add(TCOTMSWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLatWidth", TcoLatWidth)) add(TCOLATWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLonWidth", TcoLonWidth)) add(TCOLONWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoGspWidth", TcoGspWidth)) add(TCOGSPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAltWidth", TcoAltWidth)) add(TCOALTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAstWidth", TcoAstWidth)) add(TCOASTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoUtyWidth", TcoUtyWidth)) add(TCOUTYWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAchWidth", TcoAchWidth)) add(TCOACHWIDTH);
	};

	return basefound;
};

void PnlBrlyFltFafAWaypoint::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyFltFafAWaypoint";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyFltFafAWaypoint";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoTmsWidth", TcoTmsWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLatWidth", TcoLatWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLonWidth", TcoLonWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoGspWidth", TcoGspWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAltWidth", TcoAltWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAstWidth", TcoAstWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoUtyWidth", TcoUtyWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAchWidth", TcoAchWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFltFafAWaypoint::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoTmsWidth == comp->TcoTmsWidth) insert(items, TCOTMSWIDTH);
	if (TcoLatWidth == comp->TcoLatWidth) insert(items, TCOLATWIDTH);
	if (TcoLonWidth == comp->TcoLonWidth) insert(items, TCOLONWIDTH);
	if (TcoGspWidth == comp->TcoGspWidth) insert(items, TCOGSPWIDTH);
	if (TcoAltWidth == comp->TcoAltWidth) insert(items, TCOALTWIDTH);
	if (TcoAstWidth == comp->TcoAstWidth) insert(items, TCOASTWIDTH);
	if (TcoUtyWidth == comp->TcoUtyWidth) insert(items, TCOUTYWIDTH);
	if (TcoAchWidth == comp->TcoAchWidth) insert(items, TCOACHWIDTH);

	return(items);
};

set<uint> PnlBrlyFltFafAWaypoint::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOTMSWIDTH, TCOLATWIDTH, TCOLONWIDTH, TCOGSPWIDTH, TCOALTWIDTH, TCOASTWIDTH, TCOUTYWIDTH, TCOACHWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::Tag
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoTms
			, const string& TcoLat
			, const string& TcoLon
			, const string& TcoGsp
			, const string& TcoAlt
			, const string& TcoAst
			, const string& TcoUty
			, const string& TcoAch
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoTms = TcoTms;
	this->TcoLat = TcoLat;
	this->TcoLon = TcoLon;
	this->TcoGsp = TcoGsp;
	this->TcoAlt = TcoAlt;
	this->TcoAst = TcoAst;
	this->TcoUty = TcoUty;
	this->TcoAch = TcoAch;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOTMS, TCOLAT, TCOLON, TCOGSP, TCOALT, TCOAST, TCOUTY, TCOACH};
};

bool PnlBrlyFltFafAWaypoint::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyFltFafAWaypoint");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyFltFafAWaypoint";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTms", TcoTms)) add(TCOTMS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoLat", TcoLat)) add(TCOLAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoLon", TcoLon)) add(TCOLON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoGsp", TcoGsp)) add(TCOGSP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoAlt", TcoAlt)) add(TCOALT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoAst", TcoAst)) add(TCOAST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoUty", TcoUty)) add(TCOUTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoAch", TcoAch)) add(TCOACH);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::DpchAppData
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryBrlyFltFafAWaypoint::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTFAFAWAYPOINTDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlBrlyFltFafAWaypoint::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltFafAWaypoint::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyFltFafAWaypointData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::DpchAppDo
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTFAFAWAYPOINTDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyFltFafAWaypoint::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltFafAWaypoint::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyFltFafAWaypointDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::DpchEngData
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYFLTFAFAWAYPOINTDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlBrlyFltFafAWaypoint::DpchEngData::getSrefsMask() {
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

void PnlBrlyFltFafAWaypoint::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyFltFafAWaypointData");
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
		statappqry = QryBrlyFltFafAWaypoint::StatApp();
		statshrqry = QryBrlyFltFafAWaypoint::StatShr();
		stgiacqry = QryBrlyFltFafAWaypoint::StgIac();
	};
};

