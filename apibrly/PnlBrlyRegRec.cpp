/**
  * \file PnlBrlyRegRec.cpp
  * API code for job PnlBrlyRegRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyRegRec.h"

/******************************************************************************
 class PnlBrlyRegRec::VecVDo
 ******************************************************************************/

uint PnlBrlyRegRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyRegRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyRegRec::ContInf
 ******************************************************************************/

PnlBrlyRegRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlBrlyRegRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyRegRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyRegRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlBrlyRegRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyRegRec::ContInf::diff(
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
 class PnlBrlyRegRec::StatApp
 ******************************************************************************/

PnlBrlyRegRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneADstswitch
			, const bool initdone1NLocation
			, const bool initdoneSup1NRegion
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneADstswitch = initdoneADstswitch;
	this->initdone1NLocation = initdone1NLocation;
	this->initdoneSup1NRegion = initdoneSup1NRegion;

	mask = {INITDONEDETAIL, INITDONEADSTSWITCH, INITDONE1NLOCATION, INITDONESUP1NREGION};
};

bool PnlBrlyRegRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyRegRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyRegRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneADstswitch", initdoneADstswitch)) add(INITDONEADSTSWITCH);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NLocation", initdone1NLocation)) add(INITDONE1NLOCATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NRegion", initdoneSup1NRegion)) add(INITDONESUP1NREGION);
	};

	return basefound;
};

set<uint> PnlBrlyRegRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneADstswitch == comp->initdoneADstswitch) insert(items, INITDONEADSTSWITCH);
	if (initdone1NLocation == comp->initdone1NLocation) insert(items, INITDONE1NLOCATION);
	if (initdoneSup1NRegion == comp->initdoneSup1NRegion) insert(items, INITDONESUP1NREGION);

	return(items);
};

set<uint> PnlBrlyRegRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEADSTSWITCH, INITDONE1NLOCATION, INITDONESUP1NREGION};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRegRec::StatShr
 ******************************************************************************/

PnlBrlyRegRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefADstswitch
			, const string& scrJref1NLocation
			, const bool pnl1nlocationAvail
			, const string& scrJrefSup1NRegion
			, const bool ButRegularizeActive
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefADstswitch = scrJrefADstswitch;
	this->scrJref1NLocation = scrJref1NLocation;
	this->pnl1nlocationAvail = pnl1nlocationAvail;
	this->scrJrefSup1NRegion = scrJrefSup1NRegion;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, SCRJREFDETAIL, SCRJREFADSTSWITCH, SCRJREF1NLOCATION, PNL1NLOCATIONAVAIL, SCRJREFSUP1NREGION, BUTREGULARIZEACTIVE};
};

bool PnlBrlyRegRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyRegRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyRegRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefADstswitch", scrJrefADstswitch)) add(SCRJREFADSTSWITCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NLocation", scrJref1NLocation)) add(SCRJREF1NLOCATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nlocationAvail", pnl1nlocationAvail)) add(PNL1NLOCATIONAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NRegion", scrJrefSup1NRegion)) add(SCRJREFSUP1NREGION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyRegRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefADstswitch.compare(comp->scrJrefADstswitch) == 0) insert(items, SCRJREFADSTSWITCH);
	if (scrJref1NLocation.compare(comp->scrJref1NLocation) == 0) insert(items, SCRJREF1NLOCATION);
	if (pnl1nlocationAvail == comp->pnl1nlocationAvail) insert(items, PNL1NLOCATIONAVAIL);
	if (scrJrefSup1NRegion.compare(comp->scrJrefSup1NRegion) == 0) insert(items, SCRJREFSUP1NREGION);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyRegRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, SCRJREFDETAIL, SCRJREFADSTSWITCH, SCRJREF1NLOCATION, PNL1NLOCATIONAVAIL, SCRJREFSUP1NREGION, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRegRec::Tag
 ******************************************************************************/

PnlBrlyRegRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlBrlyRegRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyRegRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyRegRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyRegRec::DpchAppDo
 ******************************************************************************/

PnlBrlyRegRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYREGRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyRegRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRegRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyRegRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyRegRec::DpchEngData
 ******************************************************************************/

PnlBrlyRegRec::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYREGRECDATA) {
};

string PnlBrlyRegRec::DpchEngData::getSrefsMask() {
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

void PnlBrlyRegRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyRegRecData");
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

