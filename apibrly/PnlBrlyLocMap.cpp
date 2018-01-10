/**
  * \file PnlBrlyLocMap.cpp
  * API code for job PnlBrlyLocMap (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyLocMap.h"

/******************************************************************************
 class PnlBrlyLocMap::VecVDo
 ******************************************************************************/

uint PnlBrlyLocMap::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	else if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "buthomeclick") return BUTHOMECLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyLocMap::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	else if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTHOMECLICK) return("ButHomeClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLocMap::VecVSge
 ******************************************************************************/

uint PnlBrlyLocMap::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "mapgen") return MAPGEN;

	return(0);
};

string PnlBrlyLocMap::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == MAPGEN) return("mapgen");

	return("");
};

/******************************************************************************
 class PnlBrlyLocMap::ContIac
 ******************************************************************************/

PnlBrlyLocMap::ContIac::ContIac(
			const double SldH
			, const double SldV
			, const double SldScl
		) : Block() {
	this->SldH = SldH;
	this->SldV = SldV;
	this->SldScl = SldScl;

	mask = {SLDH, SLDV, SLDSCL};
};

bool PnlBrlyLocMap::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyLocMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyLocMap";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldH", SldH)) add(SLDH);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldV", SldV)) add(SLDV);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldScl", SldScl)) add(SLDSCL);
	};

	return basefound;
};

void PnlBrlyLocMap::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyLocMap";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyLocMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldH", SldH);
		writeDoubleAttr(wr, itemtag, "sref", "SldV", SldV);
		writeDoubleAttr(wr, itemtag, "sref", "SldScl", SldScl);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocMap::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldH, comp->SldH) < 1.0e-4) insert(items, SLDH);
	if (compareDouble(SldV, comp->SldV) < 1.0e-4) insert(items, SLDV);
	if (compareDouble(SldScl, comp->SldScl) < 1.0e-4) insert(items, SLDSCL);

	return(items);
};

set<uint> PnlBrlyLocMap::ContIac::diff(
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
 class PnlBrlyLocMap::ContInf
 ******************************************************************************/

PnlBrlyLocMap::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool PnlBrlyLocMap::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyLocMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyLocMap";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> PnlBrlyLocMap::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> PnlBrlyLocMap::ContInf::diff(
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
 class PnlBrlyLocMap::StatShr
 ******************************************************************************/

PnlBrlyLocMap::StatShr::StatShr(
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

bool PnlBrlyLocMap::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyLocMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyLocMap";

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

set<uint> PnlBrlyLocMap::StatShr::comm(
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

set<uint> PnlBrlyLocMap::StatShr::diff(
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
 class PnlBrlyLocMap::StgIac
 ******************************************************************************/

PnlBrlyLocMap::StgIac::StgIac(
			const uint width
			, const uint height
		) : Block() {
	this->width = width;
	this->height = height;

	mask = {WIDTH, HEIGHT};
};

bool PnlBrlyLocMap::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyLocMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyLocMap";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "width", width)) add(WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "height", height)) add(HEIGHT);
	};

	return basefound;
};

void PnlBrlyLocMap::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLocMap";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyLocMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "width", width);
		writeUintAttr(wr, itemtag, "sref", "height", height);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocMap::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (width == comp->width) insert(items, WIDTH);
	if (height == comp->height) insert(items, HEIGHT);

	return(items);
};

set<uint> PnlBrlyLocMap::StgIac::diff(
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
 class PnlBrlyLocMap::Tag
 ******************************************************************************/

PnlBrlyLocMap::Tag::Tag(
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

bool PnlBrlyLocMap::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyLocMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyLocMap";

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
 class PnlBrlyLocMap::DpchAppData
 ******************************************************************************/

PnlBrlyLocMap::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, QryBrlyLocMapLeg::StgIac* stgiacqryleg
			, QryBrlyLocMapProxLocation::StgIac* stgiacqryproxlocation
			, QryBrlyLocMapVisLocation::StgIac* stgiacqryvislocation
			, StgIac* stgiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCMAPDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, STGIACQRYLEG, STGIACQRYPROXLOCATION, STGIACQRYVISLOCATION, STGIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, STGIACQRYLEG) && stgiacqryleg) this->stgiacqryleg = *stgiacqryleg;
		if (find(this->mask, STGIACQRYPROXLOCATION) && stgiacqryproxlocation) this->stgiacqryproxlocation = *stgiacqryproxlocation;
		if (find(this->mask, STGIACQRYVISLOCATION) && stgiacqryvislocation) this->stgiacqryvislocation = *stgiacqryvislocation;
		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
};

string PnlBrlyLocMap::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIACQRYLEG)) ss.push_back("stgiacqryleg");
	if (has(STGIACQRYPROXLOCATION)) ss.push_back("stgiacqryproxlocation");
	if (has(STGIACQRYVISLOCATION)) ss.push_back("stgiacqryvislocation");
	if (has(STGIAC)) ss.push_back("stgiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMap::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLocMapData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STGIACQRYLEG)) stgiacqryleg.writeXML(wr);
		if (has(STGIACQRYPROXLOCATION)) stgiacqryproxlocation.writeXML(wr);
		if (has(STGIACQRYVISLOCATION)) stgiacqryvislocation.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocMap::DpchAppDo
 ******************************************************************************/

PnlBrlyLocMap::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCMAPDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyLocMap::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMap::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLocMapDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocMap::DpchEngData
 ******************************************************************************/

PnlBrlyLocMap::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCMAPDATA) {
	feedFSge.tag = "FeedFSge";
};

string PnlBrlyLocMap::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");
	if (has(RSTLEG)) ss.push_back("rstleg");
	if (has(RSTPROXLOCATION)) ss.push_back("rstproxlocation");
	if (has(RSTVISLOCATION)) ss.push_back("rstvislocation");
	if (has(STATSHRQRYLEG)) ss.push_back("statshrqryleg");
	if (has(STATSHRQRYPROXLOCATION)) ss.push_back("statshrqryproxlocation");
	if (has(STATSHRQRYVISLOCATION)) ss.push_back("statshrqryvislocation");
	if (has(STGIACQRYLEG)) ss.push_back("stgiacqryleg");
	if (has(STGIACQRYPROXLOCATION)) ss.push_back("stgiacqryproxlocation");
	if (has(STGIACQRYVISLOCATION)) ss.push_back("stgiacqryvislocation");
	if (has(STGIAC)) ss.push_back("stgiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMap::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLocMapData");
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
		if (rstproxlocation.readXML(docctx, basexpath, true)) add(RSTPROXLOCATION);
		if (rstvislocation.readXML(docctx, basexpath, true)) add(RSTVISLOCATION);
		if (statshrqryleg.readXML(docctx, basexpath, true)) add(STATSHRQRYLEG);
		if (statshrqryproxlocation.readXML(docctx, basexpath, true)) add(STATSHRQRYPROXLOCATION);
		if (statshrqryvislocation.readXML(docctx, basexpath, true)) add(STATSHRQRYVISLOCATION);
		if (stgiacqryleg.readXML(docctx, basexpath, true)) add(STGIACQRYLEG);
		if (stgiacqryproxlocation.readXML(docctx, basexpath, true)) add(STGIACQRYPROXLOCATION);
		if (stgiacqryvislocation.readXML(docctx, basexpath, true)) add(STGIACQRYVISLOCATION);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFSge.clear();
		statshr = StatShr();
		tag = Tag();
		rstleg.clear();
		rstproxlocation.clear();
		rstvislocation.clear();
		statshrqryleg = QryBrlyLocMapLeg::StatShr();
		statshrqryproxlocation = QryBrlyLocMapProxLocation::StatShr();
		statshrqryvislocation = QryBrlyLocMapVisLocation::StatShr();
		stgiacqryleg = QryBrlyLocMapLeg::StgIac();
		stgiacqryproxlocation = QryBrlyLocMapProxLocation::StgIac();
		stgiacqryvislocation = QryBrlyLocMapVisLocation::StgIac();
		stgiac = StgIac();
	};
};

/******************************************************************************
 class PnlBrlyLocMap::DpchEngImage
 ******************************************************************************/

PnlBrlyLocMap::DpchEngImage::DpchEngImage() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCMAPIMAGE) {
};

string PnlBrlyLocMap::DpchEngImage::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(RSTLEG)) ss.push_back("rstleg");
	if (has(RSTPROXLOCATION)) ss.push_back("rstproxlocation");
	if (has(RSTVISLOCATION)) ss.push_back("rstvislocation");
	if (has(STATSHRQRYLEG)) ss.push_back("statshrqryleg");
	if (has(STATSHRQRYPROXLOCATION)) ss.push_back("statshrqryproxlocation");
	if (has(STATSHRQRYVISLOCATION)) ss.push_back("statshrqryvislocation");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMap::DpchEngImage::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLocMapImage");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (rstleg.readXML(docctx, basexpath, true)) add(RSTLEG);
		if (rstproxlocation.readXML(docctx, basexpath, true)) add(RSTPROXLOCATION);
		if (rstvislocation.readXML(docctx, basexpath, true)) add(RSTVISLOCATION);
		if (statshrqryleg.readXML(docctx, basexpath, true)) add(STATSHRQRYLEG);
		if (statshrqryproxlocation.readXML(docctx, basexpath, true)) add(STATSHRQRYPROXLOCATION);
		if (statshrqryvislocation.readXML(docctx, basexpath, true)) add(STATSHRQRYVISLOCATION);
	} else {
		rstleg.clear();
		rstproxlocation.clear();
		rstvislocation.clear();
		statshrqryleg = QryBrlyLocMapLeg::StatShr();
		statshrqryproxlocation = QryBrlyLocMapProxLocation::StatShr();
		statshrqryvislocation = QryBrlyLocMapVisLocation::StatShr();
	};
};

