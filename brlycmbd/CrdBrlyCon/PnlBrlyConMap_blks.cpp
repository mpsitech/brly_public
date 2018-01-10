/**
  * \file PnlBrlyConMap_blks.cpp
  * job handler for job PnlBrlyConMap (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

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

void PnlBrlyConMap::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void PnlBrlyConMap::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyConMap";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyConMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
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

void PnlBrlyConMap::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyConMap";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyConMap";

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

void PnlBrlyConMap::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyConMap";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyConMap";

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
 class PnlBrlyConMap::DpchAppData
 ******************************************************************************/

PnlBrlyConMap::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONMAPDATA) {
};

string PnlBrlyConMap::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlBrlyConMap::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyConMapData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (stgiacqryflight.readXML(docctx, basexpath, true)) add(STGIACQRYFLIGHT);
		if (stgiacqryleg.readXML(docctx, basexpath, true)) add(STGIACQRYLEG);
		if (stgiacqrylocation.readXML(docctx, basexpath, true)) add(STGIACQRYLOCATION);
		if (stgiacqrynode.readXML(docctx, basexpath, true)) add(STGIACQRYNODE);
		if (stgiacqryrelay.readXML(docctx, basexpath, true)) add(STGIACQRYRELAY);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
	} else {
		contiac = ContIac();
		stgiacqryflight = QryBrlyConMapFlight::StgIac();
		stgiacqryleg = QryBrlyConMapLeg::StgIac();
		stgiacqrylocation = QryBrlyConMapLocation::StgIac();
		stgiacqrynode = QryBrlyConMapNode::StgIac();
		stgiacqryrelay = QryBrlyConMapRelay::StgIac();
		stgiac = StgIac();
	};
};

/******************************************************************************
 class PnlBrlyConMap::DpchAppDo
 ******************************************************************************/

PnlBrlyConMap::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONMAPDO) {
	ixVDo = 0;
};

string PnlBrlyConMap::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConMap::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyConMapDo");
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
 class PnlBrlyConMap::DpchEngData
 ******************************************************************************/

PnlBrlyConMap::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, ListBrlyQConMapFlight* rstflight
			, ListBrlyQConMapLeg* rstleg
			, ListBrlyQConMapLocation* rstlocation
			, ListBrlyQConMapNode* rstnode
			, ListBrlyQConMapRelay* rstrelay
			, QryBrlyConMapFlight::StatShr* statshrqryflight
			, QryBrlyConMapLeg::StatShr* statshrqryleg
			, QryBrlyConMapLocation::StatShr* statshrqrylocation
			, QryBrlyConMapNode::StatShr* statshrqrynode
			, QryBrlyConMapRelay::StatShr* statshrqryrelay
			, QryBrlyConMapFlight::StgIac* stgiacqryflight
			, QryBrlyConMapLeg::StgIac* stgiacqryleg
			, QryBrlyConMapLocation::StgIac* stgiacqrylocation
			, QryBrlyConMapNode::StgIac* stgiacqrynode
			, QryBrlyConMapRelay::StgIac* stgiacqryrelay
			, StgIac* stgiac
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONMAPDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFSGE, STATSHR, TAG, RSTFLIGHT, RSTLEG, RSTLOCATION, RSTNODE, RSTRELAY, STATSHRQRYFLIGHT, STATSHRQRYLEG, STATSHRQRYLOCATION, STATSHRQRYNODE, STATSHRQRYRELAY, STGIACQRYFLIGHT, STGIACQRYLEG, STGIACQRYLOCATION, STGIACQRYNODE, STGIACQRYRELAY, STGIAC};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, RSTFLIGHT) && rstflight) this->rstflight = *rstflight;
	if (find(this->mask, RSTLEG) && rstleg) this->rstleg = *rstleg;
	if (find(this->mask, RSTLOCATION) && rstlocation) this->rstlocation = *rstlocation;
	if (find(this->mask, RSTNODE) && rstnode) this->rstnode = *rstnode;
	if (find(this->mask, RSTRELAY) && rstrelay) this->rstrelay = *rstrelay;
	if (find(this->mask, STATSHRQRYFLIGHT) && statshrqryflight) this->statshrqryflight = *statshrqryflight;
	if (find(this->mask, STATSHRQRYLEG) && statshrqryleg) this->statshrqryleg = *statshrqryleg;
	if (find(this->mask, STATSHRQRYLOCATION) && statshrqrylocation) this->statshrqrylocation = *statshrqrylocation;
	if (find(this->mask, STATSHRQRYNODE) && statshrqrynode) this->statshrqrynode = *statshrqrynode;
	if (find(this->mask, STATSHRQRYRELAY) && statshrqryrelay) this->statshrqryrelay = *statshrqryrelay;
	if (find(this->mask, STGIACQRYFLIGHT) && stgiacqryflight) this->stgiacqryflight = *stgiacqryflight;
	if (find(this->mask, STGIACQRYLEG) && stgiacqryleg) this->stgiacqryleg = *stgiacqryleg;
	if (find(this->mask, STGIACQRYLOCATION) && stgiacqrylocation) this->stgiacqrylocation = *stgiacqrylocation;
	if (find(this->mask, STGIACQRYNODE) && stgiacqrynode) this->stgiacqrynode = *stgiacqrynode;
	if (find(this->mask, STGIACQRYRELAY) && stgiacqryrelay) this->stgiacqryrelay = *stgiacqryrelay;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
};

string PnlBrlyConMap::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlBrlyConMap::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RSTFLIGHT)) {rstflight = src->rstflight; add(RSTFLIGHT);};
	if (src->has(RSTLEG)) {rstleg = src->rstleg; add(RSTLEG);};
	if (src->has(RSTLOCATION)) {rstlocation = src->rstlocation; add(RSTLOCATION);};
	if (src->has(RSTNODE)) {rstnode = src->rstnode; add(RSTNODE);};
	if (src->has(RSTRELAY)) {rstrelay = src->rstrelay; add(RSTRELAY);};
	if (src->has(STATSHRQRYFLIGHT)) {statshrqryflight = src->statshrqryflight; add(STATSHRQRYFLIGHT);};
	if (src->has(STATSHRQRYLEG)) {statshrqryleg = src->statshrqryleg; add(STATSHRQRYLEG);};
	if (src->has(STATSHRQRYLOCATION)) {statshrqrylocation = src->statshrqrylocation; add(STATSHRQRYLOCATION);};
	if (src->has(STATSHRQRYNODE)) {statshrqrynode = src->statshrqrynode; add(STATSHRQRYNODE);};
	if (src->has(STATSHRQRYRELAY)) {statshrqryrelay = src->statshrqryrelay; add(STATSHRQRYRELAY);};
	if (src->has(STGIACQRYFLIGHT)) {stgiacqryflight = src->stgiacqryflight; add(STGIACQRYFLIGHT);};
	if (src->has(STGIACQRYLEG)) {stgiacqryleg = src->stgiacqryleg; add(STGIACQRYLEG);};
	if (src->has(STGIACQRYLOCATION)) {stgiacqrylocation = src->stgiacqrylocation; add(STGIACQRYLOCATION);};
	if (src->has(STGIACQRYNODE)) {stgiacqrynode = src->stgiacqrynode; add(STGIACQRYNODE);};
	if (src->has(STGIACQRYRELAY)) {stgiacqryrelay = src->stgiacqryrelay; add(STGIACQRYRELAY);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
};

void PnlBrlyConMap::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyConMapData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(RSTFLIGHT)) rstflight.writeXML(wr);
		if (has(RSTLEG)) rstleg.writeXML(wr);
		if (has(RSTLOCATION)) rstlocation.writeXML(wr);
		if (has(RSTNODE)) rstnode.writeXML(wr);
		if (has(RSTRELAY)) rstrelay.writeXML(wr);
		if (has(STATSHRQRYFLIGHT)) statshrqryflight.writeXML(wr);
		if (has(STATSHRQRYLEG)) statshrqryleg.writeXML(wr);
		if (has(STATSHRQRYLOCATION)) statshrqrylocation.writeXML(wr);
		if (has(STATSHRQRYNODE)) statshrqrynode.writeXML(wr);
		if (has(STATSHRQRYRELAY)) statshrqryrelay.writeXML(wr);
		if (has(STGIACQRYFLIGHT)) stgiacqryflight.writeXML(wr);
		if (has(STGIACQRYLEG)) stgiacqryleg.writeXML(wr);
		if (has(STGIACQRYLOCATION)) stgiacqrylocation.writeXML(wr);
		if (has(STGIACQRYNODE)) stgiacqrynode.writeXML(wr);
		if (has(STGIACQRYRELAY)) stgiacqryrelay.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConMap::DpchEngImage
 ******************************************************************************/

PnlBrlyConMap::DpchEngImage::DpchEngImage(
			const ubigint jref
			, ListBrlyQConMapLeg* rstleg
			, ListBrlyQConMapLocation* rstlocation
			, ListBrlyQConMapFlight* rstflight
			, ListBrlyQConMapRelay* rstrelay
			, ListBrlyQConMapNode* rstnode
			, QryBrlyConMapLeg::StatShr* statshrqryleg
			, QryBrlyConMapLocation::StatShr* statshrqrylocation
			, QryBrlyConMapFlight::StatShr* statshrqryflight
			, QryBrlyConMapRelay::StatShr* statshrqryrelay
			, QryBrlyConMapNode::StatShr* statshrqrynode
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONMAPIMAGE, jref) {
	if (find(mask, ALL)) this->mask = {JREF, RSTLEG, RSTLOCATION, RSTFLIGHT, RSTRELAY, RSTNODE, STATSHRQRYLEG, STATSHRQRYLOCATION, STATSHRQRYFLIGHT, STATSHRQRYRELAY, STATSHRQRYNODE};
	else this->mask = mask;

	if (find(this->mask, RSTLEG) && rstleg) this->rstleg = *rstleg;
	if (find(this->mask, RSTLOCATION) && rstlocation) this->rstlocation = *rstlocation;
	if (find(this->mask, RSTFLIGHT) && rstflight) this->rstflight = *rstflight;
	if (find(this->mask, RSTRELAY) && rstrelay) this->rstrelay = *rstrelay;
	if (find(this->mask, RSTNODE) && rstnode) this->rstnode = *rstnode;
	if (find(this->mask, STATSHRQRYLEG) && statshrqryleg) this->statshrqryleg = *statshrqryleg;
	if (find(this->mask, STATSHRQRYLOCATION) && statshrqrylocation) this->statshrqrylocation = *statshrqrylocation;
	if (find(this->mask, STATSHRQRYFLIGHT) && statshrqryflight) this->statshrqryflight = *statshrqryflight;
	if (find(this->mask, STATSHRQRYRELAY) && statshrqryrelay) this->statshrqryrelay = *statshrqryrelay;
	if (find(this->mask, STATSHRQRYNODE) && statshrqrynode) this->statshrqrynode = *statshrqrynode;
};

string PnlBrlyConMap::DpchEngImage::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlBrlyConMap::DpchEngImage::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngImage* src = (DpchEngImage*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(RSTLEG)) {rstleg = src->rstleg; add(RSTLEG);};
	if (src->has(RSTLOCATION)) {rstlocation = src->rstlocation; add(RSTLOCATION);};
	if (src->has(RSTFLIGHT)) {rstflight = src->rstflight; add(RSTFLIGHT);};
	if (src->has(RSTRELAY)) {rstrelay = src->rstrelay; add(RSTRELAY);};
	if (src->has(RSTNODE)) {rstnode = src->rstnode; add(RSTNODE);};
	if (src->has(STATSHRQRYLEG)) {statshrqryleg = src->statshrqryleg; add(STATSHRQRYLEG);};
	if (src->has(STATSHRQRYLOCATION)) {statshrqrylocation = src->statshrqrylocation; add(STATSHRQRYLOCATION);};
	if (src->has(STATSHRQRYFLIGHT)) {statshrqryflight = src->statshrqryflight; add(STATSHRQRYFLIGHT);};
	if (src->has(STATSHRQRYRELAY)) {statshrqryrelay = src->statshrqryrelay; add(STATSHRQRYRELAY);};
	if (src->has(STATSHRQRYNODE)) {statshrqrynode = src->statshrqrynode; add(STATSHRQRYNODE);};
};

void PnlBrlyConMap::DpchEngImage::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyConMapImage");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(RSTLEG)) rstleg.writeXML(wr);
		if (has(RSTLOCATION)) rstlocation.writeXML(wr);
		if (has(RSTFLIGHT)) rstflight.writeXML(wr);
		if (has(RSTRELAY)) rstrelay.writeXML(wr);
		if (has(RSTNODE)) rstnode.writeXML(wr);
		if (has(STATSHRQRYLEG)) statshrqryleg.writeXML(wr);
		if (has(STATSHRQRYLOCATION)) statshrqrylocation.writeXML(wr);
		if (has(STATSHRQRYFLIGHT)) statshrqryflight.writeXML(wr);
		if (has(STATSHRQRYRELAY)) statshrqryrelay.writeXML(wr);
		if (has(STATSHRQRYNODE)) statshrqrynode.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

