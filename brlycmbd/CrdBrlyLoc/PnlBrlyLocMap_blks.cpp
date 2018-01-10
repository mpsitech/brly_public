/**
  * \file PnlBrlyLocMap_blks.cpp
  * job handler for job PnlBrlyLocMap (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

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

void PnlBrlyLocMap::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void PnlBrlyLocMap::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLocMap";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyLocMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
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

void PnlBrlyLocMap::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLocMap";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyLocMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeDoubleAttr(wr, itemtag, "sref", "SldHMin", SldHMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldHMax", SldHMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldVMin", SldVMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldVMax", SldVMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldSclMin", SldSclMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldSclMax", SldSclMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldSclRast", SldSclRast);
	xmlTextWriterEndElement(wr);
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

void PnlBrlyLocMap::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLocMap";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyLocMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Map");
			writeStringAttr(wr, itemtag, "sref", "ButDetach", "");
			writeStringAttr(wr, itemtag, "sref", "ButAttach", "");
			writeStringAttr(wr, itemtag, "sref", "ButHome", "");
			writeStringAttr(wr, itemtag, "sref", "CptScl", "Scale");
			writeStringAttr(wr, itemtag, "sref", "ButRefresh", "");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Landkarte");
			writeStringAttr(wr, itemtag, "sref", "ButDetach", "");
			writeStringAttr(wr, itemtag, "sref", "ButAttach", "");
			writeStringAttr(wr, itemtag, "sref", "ButHome", "");
			writeStringAttr(wr, itemtag, "sref", "CptScl", "Skalierung");
			writeStringAttr(wr, itemtag, "sref", "ButRefresh", "");
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DOWNLOAD, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocMap::DpchAppData
 ******************************************************************************/

PnlBrlyLocMap::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCMAPDATA) {
};

string PnlBrlyLocMap::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIACQRYLEG)) ss.push_back("stgiacqryleg");
	if (has(STGIACQRYPROXLOCATION)) ss.push_back("stgiacqryproxlocation");
	if (has(STGIACQRYVISLOCATION)) ss.push_back("stgiacqryvislocation");
	if (has(STGIAC)) ss.push_back("stgiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMap::DpchAppData::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLocMapData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (stgiacqryleg.readXML(docctx, basexpath, true)) add(STGIACQRYLEG);
		if (stgiacqryproxlocation.readXML(docctx, basexpath, true)) add(STGIACQRYPROXLOCATION);
		if (stgiacqryvislocation.readXML(docctx, basexpath, true)) add(STGIACQRYVISLOCATION);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
	} else {
		contiac = ContIac();
		stgiacqryleg = QryBrlyLocMapLeg::StgIac();
		stgiacqryproxlocation = QryBrlyLocMapProxLocation::StgIac();
		stgiacqryvislocation = QryBrlyLocMapVisLocation::StgIac();
		stgiac = StgIac();
	};
};

/******************************************************************************
 class PnlBrlyLocMap::DpchAppDo
 ******************************************************************************/

PnlBrlyLocMap::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCMAPDO) {
	ixVDo = 0;
};

string PnlBrlyLocMap::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMap::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLocMapDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class PnlBrlyLocMap::DpchEngData
 ******************************************************************************/

PnlBrlyLocMap::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, ListBrlyQLocMapLeg* rstleg
			, ListBrlyQLocMapProxLocation* rstproxlocation
			, ListBrlyQLocMapVisLocation* rstvislocation
			, QryBrlyLocMapLeg::StatShr* statshrqryleg
			, QryBrlyLocMapProxLocation::StatShr* statshrqryproxlocation
			, QryBrlyLocMapVisLocation::StatShr* statshrqryvislocation
			, QryBrlyLocMapLeg::StgIac* stgiacqryleg
			, QryBrlyLocMapProxLocation::StgIac* stgiacqryproxlocation
			, QryBrlyLocMapVisLocation::StgIac* stgiacqryvislocation
			, StgIac* stgiac
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCMAPDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFSGE, STATSHR, TAG, RSTLEG, RSTPROXLOCATION, RSTVISLOCATION, STATSHRQRYLEG, STATSHRQRYPROXLOCATION, STATSHRQRYVISLOCATION, STGIACQRYLEG, STGIACQRYPROXLOCATION, STGIACQRYVISLOCATION, STGIAC};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, RSTLEG) && rstleg) this->rstleg = *rstleg;
	if (find(this->mask, RSTPROXLOCATION) && rstproxlocation) this->rstproxlocation = *rstproxlocation;
	if (find(this->mask, RSTVISLOCATION) && rstvislocation) this->rstvislocation = *rstvislocation;
	if (find(this->mask, STATSHRQRYLEG) && statshrqryleg) this->statshrqryleg = *statshrqryleg;
	if (find(this->mask, STATSHRQRYPROXLOCATION) && statshrqryproxlocation) this->statshrqryproxlocation = *statshrqryproxlocation;
	if (find(this->mask, STATSHRQRYVISLOCATION) && statshrqryvislocation) this->statshrqryvislocation = *statshrqryvislocation;
	if (find(this->mask, STGIACQRYLEG) && stgiacqryleg) this->stgiacqryleg = *stgiacqryleg;
	if (find(this->mask, STGIACQRYPROXLOCATION) && stgiacqryproxlocation) this->stgiacqryproxlocation = *stgiacqryproxlocation;
	if (find(this->mask, STGIACQRYVISLOCATION) && stgiacqryvislocation) this->stgiacqryvislocation = *stgiacqryvislocation;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
};

string PnlBrlyLocMap::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlBrlyLocMap::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RSTLEG)) {rstleg = src->rstleg; add(RSTLEG);};
	if (src->has(RSTPROXLOCATION)) {rstproxlocation = src->rstproxlocation; add(RSTPROXLOCATION);};
	if (src->has(RSTVISLOCATION)) {rstvislocation = src->rstvislocation; add(RSTVISLOCATION);};
	if (src->has(STATSHRQRYLEG)) {statshrqryleg = src->statshrqryleg; add(STATSHRQRYLEG);};
	if (src->has(STATSHRQRYPROXLOCATION)) {statshrqryproxlocation = src->statshrqryproxlocation; add(STATSHRQRYPROXLOCATION);};
	if (src->has(STATSHRQRYVISLOCATION)) {statshrqryvislocation = src->statshrqryvislocation; add(STATSHRQRYVISLOCATION);};
	if (src->has(STGIACQRYLEG)) {stgiacqryleg = src->stgiacqryleg; add(STGIACQRYLEG);};
	if (src->has(STGIACQRYPROXLOCATION)) {stgiacqryproxlocation = src->stgiacqryproxlocation; add(STGIACQRYPROXLOCATION);};
	if (src->has(STGIACQRYVISLOCATION)) {stgiacqryvislocation = src->stgiacqryvislocation; add(STGIACQRYVISLOCATION);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
};

void PnlBrlyLocMap::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLocMapData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(RSTLEG)) rstleg.writeXML(wr);
		if (has(RSTPROXLOCATION)) rstproxlocation.writeXML(wr);
		if (has(RSTVISLOCATION)) rstvislocation.writeXML(wr);
		if (has(STATSHRQRYLEG)) statshrqryleg.writeXML(wr);
		if (has(STATSHRQRYPROXLOCATION)) statshrqryproxlocation.writeXML(wr);
		if (has(STATSHRQRYVISLOCATION)) statshrqryvislocation.writeXML(wr);
		if (has(STGIACQRYLEG)) stgiacqryleg.writeXML(wr);
		if (has(STGIACQRYPROXLOCATION)) stgiacqryproxlocation.writeXML(wr);
		if (has(STGIACQRYVISLOCATION)) stgiacqryvislocation.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocMap::DpchEngImage
 ******************************************************************************/

PnlBrlyLocMap::DpchEngImage::DpchEngImage(
			const ubigint jref
			, ListBrlyQLocMapLeg* rstleg
			, ListBrlyQLocMapProxLocation* rstproxlocation
			, ListBrlyQLocMapVisLocation* rstvislocation
			, QryBrlyLocMapLeg::StatShr* statshrqryleg
			, QryBrlyLocMapProxLocation::StatShr* statshrqryproxlocation
			, QryBrlyLocMapVisLocation::StatShr* statshrqryvislocation
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCMAPIMAGE, jref) {
	if (find(mask, ALL)) this->mask = {JREF, RSTLEG, RSTPROXLOCATION, RSTVISLOCATION, STATSHRQRYLEG, STATSHRQRYPROXLOCATION, STATSHRQRYVISLOCATION};
	else this->mask = mask;

	if (find(this->mask, RSTLEG) && rstleg) this->rstleg = *rstleg;
	if (find(this->mask, RSTPROXLOCATION) && rstproxlocation) this->rstproxlocation = *rstproxlocation;
	if (find(this->mask, RSTVISLOCATION) && rstvislocation) this->rstvislocation = *rstvislocation;
	if (find(this->mask, STATSHRQRYLEG) && statshrqryleg) this->statshrqryleg = *statshrqryleg;
	if (find(this->mask, STATSHRQRYPROXLOCATION) && statshrqryproxlocation) this->statshrqryproxlocation = *statshrqryproxlocation;
	if (find(this->mask, STATSHRQRYVISLOCATION) && statshrqryvislocation) this->statshrqryvislocation = *statshrqryvislocation;
};

string PnlBrlyLocMap::DpchEngImage::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(RSTLEG)) ss.push_back("rstleg");
	if (has(RSTPROXLOCATION)) ss.push_back("rstproxlocation");
	if (has(RSTVISLOCATION)) ss.push_back("rstvislocation");
	if (has(STATSHRQRYLEG)) ss.push_back("statshrqryleg");
	if (has(STATSHRQRYPROXLOCATION)) ss.push_back("statshrqryproxlocation");
	if (has(STATSHRQRYVISLOCATION)) ss.push_back("statshrqryvislocation");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMap::DpchEngImage::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngImage* src = (DpchEngImage*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(RSTLEG)) {rstleg = src->rstleg; add(RSTLEG);};
	if (src->has(RSTPROXLOCATION)) {rstproxlocation = src->rstproxlocation; add(RSTPROXLOCATION);};
	if (src->has(RSTVISLOCATION)) {rstvislocation = src->rstvislocation; add(RSTVISLOCATION);};
	if (src->has(STATSHRQRYLEG)) {statshrqryleg = src->statshrqryleg; add(STATSHRQRYLEG);};
	if (src->has(STATSHRQRYPROXLOCATION)) {statshrqryproxlocation = src->statshrqryproxlocation; add(STATSHRQRYPROXLOCATION);};
	if (src->has(STATSHRQRYVISLOCATION)) {statshrqryvislocation = src->statshrqryvislocation; add(STATSHRQRYVISLOCATION);};
};

void PnlBrlyLocMap::DpchEngImage::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLocMapImage");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(RSTLEG)) rstleg.writeXML(wr);
		if (has(RSTPROXLOCATION)) rstproxlocation.writeXML(wr);
		if (has(RSTVISLOCATION)) rstvislocation.writeXML(wr);
		if (has(STATSHRQRYLEG)) statshrqryleg.writeXML(wr);
		if (has(STATSHRQRYPROXLOCATION)) statshrqryproxlocation.writeXML(wr);
		if (has(STATSHRQRYVISLOCATION)) statshrqryvislocation.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

