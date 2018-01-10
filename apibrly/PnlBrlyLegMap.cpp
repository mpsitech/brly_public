/**
  * \file PnlBrlyLegMap.cpp
  * API code for job PnlBrlyLegMap (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyLegMap.h"

/******************************************************************************
 class PnlBrlyLegMap::VecVDo
 ******************************************************************************/

uint PnlBrlyLegMap::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	else if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "buthomeclick") return BUTHOMECLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyLegMap::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	else if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTHOMECLICK) return("ButHomeClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLegMap::VecVSge
 ******************************************************************************/

uint PnlBrlyLegMap::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "mapgen") return MAPGEN;

	return(0);
};

string PnlBrlyLegMap::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == MAPGEN) return("mapgen");

	return("");
};

/******************************************************************************
 class PnlBrlyLegMap::ContIac
 ******************************************************************************/

PnlBrlyLegMap::ContIac::ContIac(
			const double SldH
			, const double SldV
			, const double SldScl
		) : Block() {
	this->SldH = SldH;
	this->SldV = SldV;
	this->SldScl = SldScl;

	mask = {SLDH, SLDV, SLDSCL};
};

bool PnlBrlyLegMap::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyLegMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyLegMap";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldH", SldH)) add(SLDH);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldV", SldV)) add(SLDV);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldScl", SldScl)) add(SLDSCL);
	};

	return basefound;
};

void PnlBrlyLegMap::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyLegMap";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyLegMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldH", SldH);
		writeDoubleAttr(wr, itemtag, "sref", "SldV", SldV);
		writeDoubleAttr(wr, itemtag, "sref", "SldScl", SldScl);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegMap::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldH, comp->SldH) < 1.0e-4) insert(items, SLDH);
	if (compareDouble(SldV, comp->SldV) < 1.0e-4) insert(items, SLDV);
	if (compareDouble(SldScl, comp->SldScl) < 1.0e-4) insert(items, SLDSCL);

	return(items);
};

set<uint> PnlBrlyLegMap::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDH, SLDV, SLDSCL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegMap::ContInf
 ******************************************************************************/

PnlBrlyLegMap::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool PnlBrlyLegMap::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyLegMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyLegMap";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> PnlBrlyLegMap::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> PnlBrlyLegMap::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegMap::StatShr
 ******************************************************************************/

PnlBrlyLegMap::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const double SldHMin
			, const double SldHMax
			, const double SldVMin
			, const double SldVMax
			, const double SldSclMin
			, const double SldSclMax
			, const double SldSclRast
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->SldHMin = SldHMin;
	this->SldHMax = SldHMax;
	this->SldVMin = SldVMin;
	this->SldVMax = SldVMax;
	this->SldSclMin = SldSclMin;
	this->SldSclMax = SldSclMax;
	this->SldSclRast = SldSclRast;

	mask = {IXBRLYVEXPSTATE, SLDHMIN, SLDHMAX, SLDVMIN, SLDVMAX, SLDSCLMIN, SLDSCLMAX, SLDSCLRAST};
};

bool PnlBrlyLegMap::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyLegMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyLegMap";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldHMin", SldHMin)) add(SLDHMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldHMax", SldHMax)) add(SLDHMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldVMin", SldVMin)) add(SLDVMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldVMax", SldVMax)) add(SLDVMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSclMin", SldSclMin)) add(SLDSCLMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSclMax", SldSclMax)) add(SLDSCLMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSclRast", SldSclRast)) add(SLDSCLRAST);
	};

	return basefound;
};

set<uint> PnlBrlyLegMap::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (compareDouble(SldHMin, comp->SldHMin) < 1.0e-4) insert(items, SLDHMIN);
	if (compareDouble(SldHMax, comp->SldHMax) < 1.0e-4) insert(items, SLDHMAX);
	if (compareDouble(SldVMin, comp->SldVMin) < 1.0e-4) insert(items, SLDVMIN);
	if (compareDouble(SldVMax, comp->SldVMax) < 1.0e-4) insert(items, SLDVMAX);
	if (compareDouble(SldSclMin, comp->SldSclMin) < 1.0e-4) insert(items, SLDSCLMIN);
	if (compareDouble(SldSclMax, comp->SldSclMax) < 1.0e-4) insert(items, SLDSCLMAX);
	if (compareDouble(SldSclRast, comp->SldSclRast) < 1.0e-4) insert(items, SLDSCLRAST);

	return(items);
};

set<uint> PnlBrlyLegMap::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, SLDHMIN, SLDHMAX, SLDVMIN, SLDVMAX, SLDSCLMIN, SLDSCLMAX, SLDSCLRAST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegMap::StgIac
 ******************************************************************************/

PnlBrlyLegMap::StgIac::StgIac(
			const uint width
			, const uint height
		) : Block() {
	this->width = width;
	this->height = height;

	mask = {WIDTH, HEIGHT};
};

bool PnlBrlyLegMap::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyLegMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyLegMap";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "width", width)) add(WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "height", height)) add(HEIGHT);
	};

	return basefound;
};

void PnlBrlyLegMap::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLegMap";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyLegMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "width", width);
		writeUintAttr(wr, itemtag, "sref", "height", height);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegMap::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (width == comp->width) insert(items, WIDTH);
	if (height == comp->height) insert(items, HEIGHT);

	return(items);
};

set<uint> PnlBrlyLegMap::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {WIDTH, HEIGHT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegMap::Tag
 ******************************************************************************/

PnlBrlyLegMap::Tag::Tag(
			const string& Cpt
			, const string& ButDetach
			, const string& ButAttach
			, const string& ButHome
			, const string& CptScl
			, const string& ButRefresh
			, const string& Dld
		) : Block() {
	this->Cpt = Cpt;
	this->ButDetach = ButDetach;
	this->ButAttach = ButAttach;
	this->ButHome = ButHome;
	this->CptScl = CptScl;
	this->ButRefresh = ButRefresh;
	this->Dld = Dld;

	mask = {CPT, BUTDETACH, BUTATTACH, BUTHOME, CPTSCL, BUTREFRESH, DLD};
};

bool PnlBrlyLegMap::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyLegMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyLegMap";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDetach", ButDetach)) add(BUTDETACH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButAttach", ButAttach)) add(BUTATTACH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButHome", ButHome)) add(BUTHOME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptScl", CptScl)) add(CPTSCL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRefresh", ButRefresh)) add(BUTREFRESH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyLegMap::DpchAppData
 ******************************************************************************/

PnlBrlyLegMap::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, QryBrlyLegMapLeg::StgIac* stgiacqryleg
			, QryBrlyLegMapLocation::StgIac* stgiacqrylocation
			, StgIac* stgiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGMAPDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, STGIACQRYLEG, STGIACQRYLOCATION, STGIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, STGIACQRYLEG) && stgiacqryleg) this->stgiacqryleg = *stgiacqryleg;
		if (find(this->mask, STGIACQRYLOCATION) && stgiacqrylocation) this->stgiacqrylocation = *stgiacqrylocation;
		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
};

string PnlBrlyLegMap::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIACQRYLEG)) ss.push_back("stgiacqryleg");
	if (has(STGIACQRYLOCATION)) ss.push_back("stgiacqrylocation");
	if (has(STGIAC)) ss.push_back("stgiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegMap::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLegMapData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STGIACQRYLEG)) stgiacqryleg.writeXML(wr);
		if (has(STGIACQRYLOCATION)) stgiacqrylocation.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegMap::DpchAppDo
 ******************************************************************************/

PnlBrlyLegMap::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGMAPDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyLegMap::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegMap::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLegMapDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegMap::DpchEngData
 ******************************************************************************/

PnlBrlyLegMap::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGMAPDATA) {
	feedFSge.tag = "FeedFSge";
};

string PnlBrlyLegMap::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");
	if (has(RSTLEG)) ss.push_back("rstleg");
	if (has(RSTLOCATION)) ss.push_back("rstlocation");
	if (has(STATSHRQRYLEG)) ss.push_back("statshrqryleg");
	if (has(STATSHRQRYLOCATION)) ss.push_back("statshrqrylocation");
	if (has(STGIACQRYLEG)) ss.push_back("stgiacqryleg");
	if (has(STGIACQRYLOCATION)) ss.push_back("stgiacqrylocation");
	if (has(STGIAC)) ss.push_back("stgiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegMap::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLegMapData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rstleg.readXML(docctx, basexpath, true)) add(RSTLEG);
		if (rstlocation.readXML(docctx, basexpath, true)) add(RSTLOCATION);
		if (statshrqryleg.readXML(docctx, basexpath, true)) add(STATSHRQRYLEG);
		if (statshrqrylocation.readXML(docctx, basexpath, true)) add(STATSHRQRYLOCATION);
		if (stgiacqryleg.readXML(docctx, basexpath, true)) add(STGIACQRYLEG);
		if (stgiacqrylocation.readXML(docctx, basexpath, true)) add(STGIACQRYLOCATION);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFSge.clear();
		statshr = StatShr();
		tag = Tag();
		rstleg.clear();
		rstlocation.clear();
		statshrqryleg = QryBrlyLegMapLeg::StatShr();
		statshrqrylocation = QryBrlyLegMapLocation::StatShr();
		stgiacqryleg = QryBrlyLegMapLeg::StgIac();
		stgiacqrylocation = QryBrlyLegMapLocation::StgIac();
		stgiac = StgIac();
	};
};

/******************************************************************************
 class PnlBrlyLegMap::DpchEngImage
 ******************************************************************************/

PnlBrlyLegMap::DpchEngImage::DpchEngImage() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGMAPIMAGE) {
};

string PnlBrlyLegMap::DpchEngImage::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(RSTLEG)) ss.push_back("rstleg");
	if (has(RSTLOCATION)) ss.push_back("rstlocation");
	if (has(STATSHRQRYLEG)) ss.push_back("statshrqryleg");
	if (has(STATSHRQRYLOCATION)) ss.push_back("statshrqrylocation");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegMap::DpchEngImage::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLegMapImage");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (rstleg.readXML(docctx, basexpath, true)) add(RSTLEG);
		if (rstlocation.readXML(docctx, basexpath, true)) add(RSTLOCATION);
		if (statshrqryleg.readXML(docctx, basexpath, true)) add(STATSHRQRYLEG);
		if (statshrqrylocation.readXML(docctx, basexpath, true)) add(STATSHRQRYLOCATION);
	} else {
		rstleg.clear();
		rstlocation.clear();
		statshrqryleg = QryBrlyLegMapLeg::StatShr();
		statshrqrylocation = QryBrlyLegMapLocation::StatShr();
	};
};

