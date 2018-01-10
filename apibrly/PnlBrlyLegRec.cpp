/**
  * \file PnlBrlyLegRec.cpp
  * API code for job PnlBrlyLegRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyLegRec.h"

/******************************************************************************
 class PnlBrlyLegRec::VecVDo
 ******************************************************************************/

uint PnlBrlyLegRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyLegRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLegRec::ContInf
 ******************************************************************************/

PnlBrlyLegRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlBrlyLegRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyLegRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyLegRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlBrlyLegRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyLegRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegRec::StatApp
 ******************************************************************************/

PnlBrlyLegRec::StatApp::StatApp(
			const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneMap
			, const bool initdoneCor1NConnection
			, const bool initdone1NFlight
			, const bool initdoneMNLocation
			, const bool initdoneOrgMNLeg
		) : Block() {
	this->initdonePre = initdonePre;
	this->initdoneDetail = initdoneDetail;
	this->initdoneMap = initdoneMap;
	this->initdoneCor1NConnection = initdoneCor1NConnection;
	this->initdone1NFlight = initdone1NFlight;
	this->initdoneMNLocation = initdoneMNLocation;
	this->initdoneOrgMNLeg = initdoneOrgMNLeg;

	mask = {INITDONEPRE, INITDONEDETAIL, INITDONEMAP, INITDONECOR1NCONNECTION, INITDONE1NFLIGHT, INITDONEMNLOCATION, INITDONEORGMNLEG};
};

bool PnlBrlyLegRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyLegRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyLegRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMap", initdoneMap)) add(INITDONEMAP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneCor1NConnection", initdoneCor1NConnection)) add(INITDONECOR1NCONNECTION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NFlight", initdone1NFlight)) add(INITDONE1NFLIGHT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNLocation", initdoneMNLocation)) add(INITDONEMNLOCATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneOrgMNLeg", initdoneOrgMNLeg)) add(INITDONEORGMNLEG);
	};

	return basefound;
};

set<uint> PnlBrlyLegRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneMap == comp->initdoneMap) insert(items, INITDONEMAP);
	if (initdoneCor1NConnection == comp->initdoneCor1NConnection) insert(items, INITDONECOR1NCONNECTION);
	if (initdone1NFlight == comp->initdone1NFlight) insert(items, INITDONE1NFLIGHT);
	if (initdoneMNLocation == comp->initdoneMNLocation) insert(items, INITDONEMNLOCATION);
	if (initdoneOrgMNLeg == comp->initdoneOrgMNLeg) insert(items, INITDONEORGMNLEG);

	return(items);
};

set<uint> PnlBrlyLegRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEPRE, INITDONEDETAIL, INITDONEMAP, INITDONECOR1NCONNECTION, INITDONE1NFLIGHT, INITDONEMNLOCATION, INITDONEORGMNLEG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegRec::StatShr
 ******************************************************************************/

PnlBrlyLegRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const string& scrJrefPre
			, const string& scrJrefDetail
			, const string& scrJrefMap
			, const string& scrJrefCor1NConnection
			, const bool pnlcor1nconnectionAvail
			, const string& scrJref1NFlight
			, const bool pnl1nflightAvail
			, const string& scrJrefMNLocation
			, const string& scrJrefOrgMNLeg
			, const bool ButRegularizeActive
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->scrJrefPre = scrJrefPre;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefMap = scrJrefMap;
	this->scrJrefCor1NConnection = scrJrefCor1NConnection;
	this->pnlcor1nconnectionAvail = pnlcor1nconnectionAvail;
	this->scrJref1NFlight = scrJref1NFlight;
	this->pnl1nflightAvail = pnl1nflightAvail;
	this->scrJrefMNLocation = scrJrefMNLocation;
	this->scrJrefOrgMNLeg = scrJrefOrgMNLeg;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFMAP, SCRJREFCOR1NCONNECTION, PNLCOR1NCONNECTIONAVAIL, SCRJREF1NFLIGHT, PNL1NFLIGHTAVAIL, SCRJREFMNLOCATION, SCRJREFORGMNLEG, BUTREGULARIZEACTIVE};
};

bool PnlBrlyLegRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyLegRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyLegRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMap", scrJrefMap)) add(SCRJREFMAP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCor1NConnection", scrJrefCor1NConnection)) add(SCRJREFCOR1NCONNECTION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlcor1nconnectionAvail", pnlcor1nconnectionAvail)) add(PNLCOR1NCONNECTIONAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NFlight", scrJref1NFlight)) add(SCRJREF1NFLIGHT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nflightAvail", pnl1nflightAvail)) add(PNL1NFLIGHTAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNLocation", scrJrefMNLocation)) add(SCRJREFMNLOCATION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefOrgMNLeg", scrJrefOrgMNLeg)) add(SCRJREFORGMNLEG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyLegRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (scrJrefPre.compare(comp->scrJrefPre) == 0) insert(items, SCRJREFPRE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefMap.compare(comp->scrJrefMap) == 0) insert(items, SCRJREFMAP);
	if (scrJrefCor1NConnection.compare(comp->scrJrefCor1NConnection) == 0) insert(items, SCRJREFCOR1NCONNECTION);
	if (pnlcor1nconnectionAvail == comp->pnlcor1nconnectionAvail) insert(items, PNLCOR1NCONNECTIONAVAIL);
	if (scrJref1NFlight.compare(comp->scrJref1NFlight) == 0) insert(items, SCRJREF1NFLIGHT);
	if (pnl1nflightAvail == comp->pnl1nflightAvail) insert(items, PNL1NFLIGHTAVAIL);
	if (scrJrefMNLocation.compare(comp->scrJrefMNLocation) == 0) insert(items, SCRJREFMNLOCATION);
	if (scrJrefOrgMNLeg.compare(comp->scrJrefOrgMNLeg) == 0) insert(items, SCRJREFORGMNLEG);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyLegRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFMAP, SCRJREFCOR1NCONNECTION, PNLCOR1NCONNECTIONAVAIL, SCRJREF1NFLIGHT, PNL1NFLIGHTAVAIL, SCRJREFMNLOCATION, SCRJREFORGMNLEG, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegRec::Tag
 ******************************************************************************/

PnlBrlyLegRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlBrlyLegRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyLegRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyLegRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyLegRec::DpchAppDo
 ******************************************************************************/

PnlBrlyLegRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyLegRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLegRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegRec::DpchEngData
 ******************************************************************************/

PnlBrlyLegRec::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGRECDATA) {
};

string PnlBrlyLegRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLegRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

