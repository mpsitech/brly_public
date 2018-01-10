/**
  * \file PnlBrlyConRec.cpp
  * API code for job PnlBrlyConRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyConRec.h"

/******************************************************************************
 class PnlBrlyConRec::VecVDo
 ******************************************************************************/

uint PnlBrlyConRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyConRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyConRec::ContInf
 ******************************************************************************/

PnlBrlyConRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlBrlyConRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyConRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyConRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlBrlyConRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyConRec::ContInf::diff(
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
 class PnlBrlyConRec::StatApp
 ******************************************************************************/

PnlBrlyConRec::StatApp::StatApp(
			const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneMap
			, const bool initdone1NRelay
			, const bool initdoneRef1NSegment
			, const bool initdoneMNSegment
			, const bool initdoneMNFlight
			, const bool initdoneConMNEquipment
		) : Block() {
	this->initdonePre = initdonePre;
	this->initdoneDetail = initdoneDetail;
	this->initdoneMap = initdoneMap;
	this->initdone1NRelay = initdone1NRelay;
	this->initdoneRef1NSegment = initdoneRef1NSegment;
	this->initdoneMNSegment = initdoneMNSegment;
	this->initdoneMNFlight = initdoneMNFlight;
	this->initdoneConMNEquipment = initdoneConMNEquipment;

	mask = {INITDONEPRE, INITDONEDETAIL, INITDONEMAP, INITDONE1NRELAY, INITDONEREF1NSEGMENT, INITDONEMNSEGMENT, INITDONEMNFLIGHT, INITDONECONMNEQUIPMENT};
};

bool PnlBrlyConRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyConRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyConRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMap", initdoneMap)) add(INITDONEMAP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NRelay", initdone1NRelay)) add(INITDONE1NRELAY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NSegment", initdoneRef1NSegment)) add(INITDONEREF1NSEGMENT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNSegment", initdoneMNSegment)) add(INITDONEMNSEGMENT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNFlight", initdoneMNFlight)) add(INITDONEMNFLIGHT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneConMNEquipment", initdoneConMNEquipment)) add(INITDONECONMNEQUIPMENT);
	};

	return basefound;
};

set<uint> PnlBrlyConRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneMap == comp->initdoneMap) insert(items, INITDONEMAP);
	if (initdone1NRelay == comp->initdone1NRelay) insert(items, INITDONE1NRELAY);
	if (initdoneRef1NSegment == comp->initdoneRef1NSegment) insert(items, INITDONEREF1NSEGMENT);
	if (initdoneMNSegment == comp->initdoneMNSegment) insert(items, INITDONEMNSEGMENT);
	if (initdoneMNFlight == comp->initdoneMNFlight) insert(items, INITDONEMNFLIGHT);
	if (initdoneConMNEquipment == comp->initdoneConMNEquipment) insert(items, INITDONECONMNEQUIPMENT);

	return(items);
};

set<uint> PnlBrlyConRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEPRE, INITDONEDETAIL, INITDONEMAP, INITDONE1NRELAY, INITDONEREF1NSEGMENT, INITDONEMNSEGMENT, INITDONEMNFLIGHT, INITDONECONMNEQUIPMENT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConRec::StatShr
 ******************************************************************************/

PnlBrlyConRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const string& scrJrefPre
			, const string& scrJrefDetail
			, const string& scrJrefMap
			, const string& scrJref1NRelay
			, const string& scrJrefRef1NSegment
			, const string& scrJrefMNSegment
			, const string& scrJrefMNFlight
			, const string& scrJrefConMNEquipment
			, const bool ButRegularizeActive
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->scrJrefPre = scrJrefPre;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefMap = scrJrefMap;
	this->scrJref1NRelay = scrJref1NRelay;
	this->scrJrefRef1NSegment = scrJrefRef1NSegment;
	this->scrJrefMNSegment = scrJrefMNSegment;
	this->scrJrefMNFlight = scrJrefMNFlight;
	this->scrJrefConMNEquipment = scrJrefConMNEquipment;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFMAP, SCRJREF1NRELAY, SCRJREFREF1NSEGMENT, SCRJREFMNSEGMENT, SCRJREFMNFLIGHT, SCRJREFCONMNEQUIPMENT, BUTREGULARIZEACTIVE};
};

bool PnlBrlyConRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyConRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyConRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMap", scrJrefMap)) add(SCRJREFMAP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NRelay", scrJref1NRelay)) add(SCRJREF1NRELAY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NSegment", scrJrefRef1NSegment)) add(SCRJREFREF1NSEGMENT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNSegment", scrJrefMNSegment)) add(SCRJREFMNSEGMENT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNFlight", scrJrefMNFlight)) add(SCRJREFMNFLIGHT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefConMNEquipment", scrJrefConMNEquipment)) add(SCRJREFCONMNEQUIPMENT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyConRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (scrJrefPre.compare(comp->scrJrefPre) == 0) insert(items, SCRJREFPRE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefMap.compare(comp->scrJrefMap) == 0) insert(items, SCRJREFMAP);
	if (scrJref1NRelay.compare(comp->scrJref1NRelay) == 0) insert(items, SCRJREF1NRELAY);
	if (scrJrefRef1NSegment.compare(comp->scrJrefRef1NSegment) == 0) insert(items, SCRJREFREF1NSEGMENT);
	if (scrJrefMNSegment.compare(comp->scrJrefMNSegment) == 0) insert(items, SCRJREFMNSEGMENT);
	if (scrJrefMNFlight.compare(comp->scrJrefMNFlight) == 0) insert(items, SCRJREFMNFLIGHT);
	if (scrJrefConMNEquipment.compare(comp->scrJrefConMNEquipment) == 0) insert(items, SCRJREFCONMNEQUIPMENT);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyConRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFMAP, SCRJREF1NRELAY, SCRJREFREF1NSEGMENT, SCRJREFMNSEGMENT, SCRJREFMNFLIGHT, SCRJREFCONMNEQUIPMENT, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConRec::Tag
 ******************************************************************************/

PnlBrlyConRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlBrlyConRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyConRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyConRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyConRec::DpchAppDo
 ******************************************************************************/

PnlBrlyConRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyConRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyConRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConRec::DpchEngData
 ******************************************************************************/

PnlBrlyConRec::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONRECDATA) {
};

string PnlBrlyConRec::DpchEngData::getSrefsMask() {
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

void PnlBrlyConRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyConRecData");
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

