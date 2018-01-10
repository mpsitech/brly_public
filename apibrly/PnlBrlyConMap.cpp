/**
  * \file PnlBrlyConMap.cpp
  * API code for job PnlBrlyConMap (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyConMap.h"

/******************************************************************************
 class PnlBrlyConMap::VecVDo
 ******************************************************************************/

uint PnlBrlyConMap::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	else if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "buthomeclick") return BUTHOMECLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyConMap::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	else if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTHOMECLICK) return("ButHomeClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyConMap::VecVSge
 ******************************************************************************/

uint PnlBrlyConMap::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "mapgen") return MAPGEN;

	return(0);
};

string PnlBrlyConMap::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == MAPGEN) return("mapgen");

	return("");
};

/******************************************************************************
 class PnlBrlyConMap::ContIac
 ******************************************************************************/

PnlBrlyConMap::ContIac::ContIac(
			const double SldH
			, const double SldV
			, const double SldScl
		) : Block() {
	this->SldH = SldH;
	this->SldV = SldV;
	this->SldScl = SldScl;

	mask = {SLDH, SLDV, SLDSCL};
};

bool PnlBrlyConMap::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyConMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyConMap";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldH", SldH)) add(SLDH);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldV", SldV)) add(SLDV);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldScl", SldScl)) add(SLDSCL);
	};

	return basefound;
};

void PnlBrlyConMap::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyConMap";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyConMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldH", SldH);
		writeDoubleAttr(wr, itemtag, "sref", "SldV", SldV);
		writeDoubleAttr(wr, itemtag, "sref", "SldScl", SldScl);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyConMap::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldH, comp->SldH) < 1.0e-4) insert(items, SLDH);
	if (compareDouble(SldV, comp->SldV) < 1.0e-4) insert(items, SLDV);
	if (compareDouble(SldScl, comp->SldScl) < 1.0e-4) insert(items, SLDSCL);

	return(items);
};

set<uint> PnlBrlyConMap::ContIac::diff(
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
 class PnlBrlyConMap::ContInf
 ******************************************************************************/

PnlBrlyConMap::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool PnlBrlyConMap::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyConMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyConMap";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> PnlBrlyConMap::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> PnlBrlyConMap::ContInf::diff(
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
 class PnlBrlyConMap::StatShr
 ******************************************************************************/

PnlBrlyConMap::StatShr::StatShr(
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

bool PnlBrlyConMap::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyConMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyConMap";

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

set<uint> PnlBrlyConMap::StatShr::comm(
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

set<uint> PnlBrlyConMap::StatShr::diff(
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
 class PnlBrlyConMap::StgIac
 ******************************************************************************/

PnlBrlyConMap::StgIac::StgIac(
			const uint width
			, const uint height
		) : Block() {
	this->width = width;
	this->height = height;

	mask = {WIDTH, HEIGHT};
};

bool PnlBrlyConMap::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyConMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyConMap";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "width", width)) add(WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "height", height)) add(HEIGHT);
	};

	return basefound;
};

void PnlBrlyConMap::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyConMap";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyConMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "width", width);
		writeUintAttr(wr, itemtag, "sref", "height", height);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyConMap::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (width == comp->width) insert(items, WIDTH);
	if (height == comp->height) insert(items, HEIGHT);

	return(items);
};

set<uint> PnlBrlyConMap::StgIac::diff(
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
 class PnlBrlyConMap::Tag
 ******************************************************************************/

PnlBrlyConMap::Tag::Tag(
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

bool PnlBrlyConMap::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyConMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyConMap";

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
 class PnlBrlyConMap::DpchAppData
 ******************************************************************************/

PnlBrlyConMap::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, QryBrlyConMapFlight::StgIac* stgiacqryflight
			, QryBrlyConMapLeg::StgIac* stgiacqryleg
			, QryBrlyConMapLocation::StgIac* stgiacqrylocation
			, QryBrlyConMapNode::StgIac* stgiacqrynode
			, QryBrlyConMapRelay::StgIac* stgiacqryrelay
			, StgIac* stgiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONMAPDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, STGIACQRYFLIGHT, STGIACQRYLEG, STGIACQRYLOCATION, STGIACQRYNODE, STGIACQRYRELAY, STGIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, STGIACQRYFLIGHT) && stgiacqryflight) this->stgiacqryflight = *stgiacqryflight;
		if (find(this->mask, STGIACQRYLEG) && stgiacqryleg) this->stgiacqryleg = *stgiacqryleg;
		if (find(this->mask, STGIACQRYLOCATION) && stgiacqrylocation) this->stgiacqrylocation = *stgiacqrylocation;
		if (find(this->mask, STGIACQRYNODE) && stgiacqrynode) this->stgiacqrynode = *stgiacqrynode;
		if (find(this->mask, STGIACQRYRELAY) && stgiacqryrelay) this->stgiacqryrelay = *stgiacqryrelay;
		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
};

string PnlBrlyConMap::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIACQRYFLIGHT)) ss.push_back("stgiacqryflight");
	if (has(STGIACQRYLEG)) ss.push_back("stgiacqryleg");
	if (has(STGIACQRYLOCATION)) ss.push_back("stgiacqrylocation");
	if (has(STGIACQRYNODE)) ss.push_back("stgiacqrynode");
	if (has(STGIACQRYRELAY)) ss.push_back("stgiacqryrelay");
	if (has(STGIAC)) ss.push_back("stgiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConMap::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyConMapData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STGIACQRYFLIGHT)) stgiacqryflight.writeXML(wr);
		if (has(STGIACQRYLEG)) stgiacqryleg.writeXML(wr);
		if (has(STGIACQRYLOCATION)) stgiacqrylocation.writeXML(wr);
		if (has(STGIACQRYNODE)) stgiacqrynode.writeXML(wr);
		if (has(STGIACQRYRELAY)) stgiacqryrelay.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConMap::DpchAppDo
 ******************************************************************************/

PnlBrlyConMap::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONMAPDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyConMap::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConMap::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyConMapDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConMap::DpchEngData
 ******************************************************************************/

PnlBrlyConMap::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONMAPDATA) {
	feedFSge.tag = "FeedFSge";
};

string PnlBrlyConMap::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");
	if (has(RSTFLIGHT)) ss.push_back("rstflight");
	if (has(RSTLEG)) ss.push_back("rstleg");
	if (has(RSTLOCATION)) ss.push_back("rstlocation");
	if (has(RSTNODE)) ss.push_back("rstnode");
	if (has(RSTRELAY)) ss.push_back("rstrelay");
	if (has(STATSHRQRYFLIGHT)) ss.push_back("statshrqryflight");
	if (has(STATSHRQRYLEG)) ss.push_back("statshrqryleg");
	if (has(STATSHRQRYLOCATION)) ss.push_back("statshrqrylocation");
	if (has(STATSHRQRYNODE)) ss.push_back("statshrqrynode");
	if (has(STATSHRQRYRELAY)) ss.push_back("statshrqryrelay");
	if (has(STGIACQRYFLIGHT)) ss.push_back("stgiacqryflight");
	if (has(STGIACQRYLEG)) ss.push_back("stgiacqryleg");
	if (has(STGIACQRYLOCATION)) ss.push_back("stgiacqrylocation");
	if (has(STGIACQRYNODE)) ss.push_back("stgiacqrynode");
	if (has(STGIACQRYRELAY)) ss.push_back("stgiacqryrelay");
	if (has(STGIAC)) ss.push_back("stgiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConMap::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyConMapData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rstflight.readXML(docctx, basexpath, true)) add(RSTFLIGHT);
		if (rstleg.readXML(docctx, basexpath, true)) add(RSTLEG);
		if (rstlocation.readXML(docctx, basexpath, true)) add(RSTLOCATION);
		if (rstnode.readXML(docctx, basexpath, true)) add(RSTNODE);
		if (rstrelay.readXML(docctx, basexpath, true)) add(RSTRELAY);
		if (statshrqryflight.readXML(docctx, basexpath, true)) add(STATSHRQRYFLIGHT);
		if (statshrqryleg.readXML(docctx, basexpath, true)) add(STATSHRQRYLEG);
		if (statshrqrylocation.readXML(docctx, basexpath, true)) add(STATSHRQRYLOCATION);
		if (statshrqrynode.readXML(docctx, basexpath, true)) add(STATSHRQRYNODE);
		if (statshrqryrelay.readXML(docctx, basexpath, true)) add(STATSHRQRYRELAY);
		if (stgiacqryflight.readXML(docctx, basexpath, true)) add(STGIACQRYFLIGHT);
		if (stgiacqryleg.readXML(docctx, basexpath, true)) add(STGIACQRYLEG);
		if (stgiacqrylocation.readXML(docctx, basexpath, true)) add(STGIACQRYLOCATION);
		if (stgiacqrynode.readXML(docctx, basexpath, true)) add(STGIACQRYNODE);
		if (stgiacqryrelay.readXML(docctx, basexpath, true)) add(STGIACQRYRELAY);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFSge.clear();
		statshr = StatShr();
		tag = Tag();
		rstflight.clear();
		rstleg.clear();
		rstlocation.clear();
		rstnode.clear();
		rstrelay.clear();
		statshrqryflight = QryBrlyConMapFlight::StatShr();
		statshrqryleg = QryBrlyConMapLeg::StatShr();
		statshrqrylocation = QryBrlyConMapLocation::StatShr();
		statshrqrynode = QryBrlyConMapNode::StatShr();
		statshrqryrelay = QryBrlyConMapRelay::StatShr();
		stgiacqryflight = QryBrlyConMapFlight::StgIac();
		stgiacqryleg = QryBrlyConMapLeg::StgIac();
		stgiacqrylocation = QryBrlyConMapLocation::StgIac();
		stgiacqrynode = QryBrlyConMapNode::StgIac();
		stgiacqryrelay = QryBrlyConMapRelay::StgIac();
		stgiac = StgIac();
	};
};

/******************************************************************************
 class PnlBrlyConMap::DpchEngImage
 ******************************************************************************/

PnlBrlyConMap::DpchEngImage::DpchEngImage() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONMAPIMAGE) {
};

string PnlBrlyConMap::DpchEngImage::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(RSTLEG)) ss.push_back("rstleg");
	if (has(RSTLOCATION)) ss.push_back("rstlocation");
	if (has(RSTFLIGHT)) ss.push_back("rstflight");
	if (has(RSTRELAY)) ss.push_back("rstrelay");
	if (has(RSTNODE)) ss.push_back("rstnode");
	if (has(STATSHRQRYLEG)) ss.push_back("statshrqryleg");
	if (has(STATSHRQRYLOCATION)) ss.push_back("statshrqrylocation");
	if (has(STATSHRQRYFLIGHT)) ss.push_back("statshrqryflight");
	if (has(STATSHRQRYRELAY)) ss.push_back("statshrqryrelay");
	if (has(STATSHRQRYNODE)) ss.push_back("statshrqrynode");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConMap::DpchEngImage::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyConMapImage");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (rstleg.readXML(docctx, basexpath, true)) add(RSTLEG);
		if (rstlocation.readXML(docctx, basexpath, true)) add(RSTLOCATION);
		if (rstflight.readXML(docctx, basexpath, true)) add(RSTFLIGHT);
		if (rstrelay.readXML(docctx, basexpath, true)) add(RSTRELAY);
		if (rstnode.readXML(docctx, basexpath, true)) add(RSTNODE);
		if (statshrqryleg.readXML(docctx, basexpath, true)) add(STATSHRQRYLEG);
		if (statshrqrylocation.readXML(docctx, basexpath, true)) add(STATSHRQRYLOCATION);
		if (statshrqryflight.readXML(docctx, basexpath, true)) add(STATSHRQRYFLIGHT);
		if (statshrqryrelay.readXML(docctx, basexpath, true)) add(STATSHRQRYRELAY);
		if (statshrqrynode.readXML(docctx, basexpath, true)) add(STATSHRQRYNODE);
	} else {
		rstleg.clear();
		rstlocation.clear();
		rstflight.clear();
		rstrelay.clear();
		rstnode.clear();
		statshrqryleg = QryBrlyConMapLeg::StatShr();
		statshrqrylocation = QryBrlyConMapLocation::StatShr();
		statshrqryflight = QryBrlyConMapFlight::StatShr();
		statshrqryrelay = QryBrlyConMapRelay::StatShr();
		statshrqrynode = QryBrlyConMapNode::StatShr();
	};
};

