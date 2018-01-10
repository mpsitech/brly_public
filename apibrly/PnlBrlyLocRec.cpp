/**
  * \file PnlBrlyLocRec.cpp
  * API code for job PnlBrlyLocRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyLocRec.h"

/******************************************************************************
 class PnlBrlyLocRec::VecVDo
 ******************************************************************************/

uint PnlBrlyLocRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyLocRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLocRec::ContInf
 ******************************************************************************/

PnlBrlyLocRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlBrlyLocRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyLocRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyLocRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlBrlyLocRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyLocRec::ContInf::diff(
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
 class PnlBrlyLocRec::StatApp
 ******************************************************************************/

PnlBrlyLocRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneMap
			, const bool initdoneBgn1NLeg
			, const bool initdoneEnd1NLeg
			, const bool initdoneEqp1NNode
			, const bool initdoneMNSegment
			, const bool initdoneProxOrgMNLocation
			, const bool initdoneVisOrgMNLocation
			, const bool initdoneMNLeg
			, const bool initdoneMNFlight
			, const bool initdoneEqpMNConnection
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneMap = initdoneMap;
	this->initdoneBgn1NLeg = initdoneBgn1NLeg;
	this->initdoneEnd1NLeg = initdoneEnd1NLeg;
	this->initdoneEqp1NNode = initdoneEqp1NNode;
	this->initdoneMNSegment = initdoneMNSegment;
	this->initdoneProxOrgMNLocation = initdoneProxOrgMNLocation;
	this->initdoneVisOrgMNLocation = initdoneVisOrgMNLocation;
	this->initdoneMNLeg = initdoneMNLeg;
	this->initdoneMNFlight = initdoneMNFlight;
	this->initdoneEqpMNConnection = initdoneEqpMNConnection;

	mask = {INITDONEDETAIL, INITDONEMAP, INITDONEBGN1NLEG, INITDONEEND1NLEG, INITDONEEQP1NNODE, INITDONEMNSEGMENT, INITDONEPROXORGMNLOCATION, INITDONEVISORGMNLOCATION, INITDONEMNLEG, INITDONEMNFLIGHT, INITDONEEQPMNCONNECTION};
};

bool PnlBrlyLocRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyLocRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyLocRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMap", initdoneMap)) add(INITDONEMAP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneBgn1NLeg", initdoneBgn1NLeg)) add(INITDONEBGN1NLEG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneEnd1NLeg", initdoneEnd1NLeg)) add(INITDONEEND1NLEG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneEqp1NNode", initdoneEqp1NNode)) add(INITDONEEQP1NNODE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNSegment", initdoneMNSegment)) add(INITDONEMNSEGMENT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneProxOrgMNLocation", initdoneProxOrgMNLocation)) add(INITDONEPROXORGMNLOCATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneVisOrgMNLocation", initdoneVisOrgMNLocation)) add(INITDONEVISORGMNLOCATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNLeg", initdoneMNLeg)) add(INITDONEMNLEG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNFlight", initdoneMNFlight)) add(INITDONEMNFLIGHT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneEqpMNConnection", initdoneEqpMNConnection)) add(INITDONEEQPMNCONNECTION);
	};

	return basefound;
};

set<uint> PnlBrlyLocRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneMap == comp->initdoneMap) insert(items, INITDONEMAP);
	if (initdoneBgn1NLeg == comp->initdoneBgn1NLeg) insert(items, INITDONEBGN1NLEG);
	if (initdoneEnd1NLeg == comp->initdoneEnd1NLeg) insert(items, INITDONEEND1NLEG);
	if (initdoneEqp1NNode == comp->initdoneEqp1NNode) insert(items, INITDONEEQP1NNODE);
	if (initdoneMNSegment == comp->initdoneMNSegment) insert(items, INITDONEMNSEGMENT);
	if (initdoneProxOrgMNLocation == comp->initdoneProxOrgMNLocation) insert(items, INITDONEPROXORGMNLOCATION);
	if (initdoneVisOrgMNLocation == comp->initdoneVisOrgMNLocation) insert(items, INITDONEVISORGMNLOCATION);
	if (initdoneMNLeg == comp->initdoneMNLeg) insert(items, INITDONEMNLEG);
	if (initdoneMNFlight == comp->initdoneMNFlight) insert(items, INITDONEMNFLIGHT);
	if (initdoneEqpMNConnection == comp->initdoneEqpMNConnection) insert(items, INITDONEEQPMNCONNECTION);

	return(items);
};

set<uint> PnlBrlyLocRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEMAP, INITDONEBGN1NLEG, INITDONEEND1NLEG, INITDONEEQP1NNODE, INITDONEMNSEGMENT, INITDONEPROXORGMNLOCATION, INITDONEVISORGMNLOCATION, INITDONEMNLEG, INITDONEMNFLIGHT, INITDONEEQPMNCONNECTION};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocRec::StatShr
 ******************************************************************************/

PnlBrlyLocRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefMap
			, const string& scrJrefBgn1NLeg
			, const bool pnlbgn1nlegAvail
			, const string& scrJrefEnd1NLeg
			, const bool pnlend1nlegAvail
			, const string& scrJrefEqp1NNode
			, const bool pnleqp1nnodeAvail
			, const string& scrJrefMNSegment
			, const string& scrJrefProxOrgMNLocation
			, const string& scrJrefVisOrgMNLocation
			, const string& scrJrefMNLeg
			, const string& scrJrefMNFlight
			, const string& scrJrefEqpMNConnection
			, const bool pnleqpmnconnectionAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefMap = scrJrefMap;
	this->scrJrefBgn1NLeg = scrJrefBgn1NLeg;
	this->pnlbgn1nlegAvail = pnlbgn1nlegAvail;
	this->scrJrefEnd1NLeg = scrJrefEnd1NLeg;
	this->pnlend1nlegAvail = pnlend1nlegAvail;
	this->scrJrefEqp1NNode = scrJrefEqp1NNode;
	this->pnleqp1nnodeAvail = pnleqp1nnodeAvail;
	this->scrJrefMNSegment = scrJrefMNSegment;
	this->scrJrefProxOrgMNLocation = scrJrefProxOrgMNLocation;
	this->scrJrefVisOrgMNLocation = scrJrefVisOrgMNLocation;
	this->scrJrefMNLeg = scrJrefMNLeg;
	this->scrJrefMNFlight = scrJrefMNFlight;
	this->scrJrefEqpMNConnection = scrJrefEqpMNConnection;
	this->pnleqpmnconnectionAvail = pnleqpmnconnectionAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, SCRJREFDETAIL, SCRJREFMAP, SCRJREFBGN1NLEG, PNLBGN1NLEGAVAIL, SCRJREFEND1NLEG, PNLEND1NLEGAVAIL, SCRJREFEQP1NNODE, PNLEQP1NNODEAVAIL, SCRJREFMNSEGMENT, SCRJREFPROXORGMNLOCATION, SCRJREFVISORGMNLOCATION, SCRJREFMNLEG, SCRJREFMNFLIGHT, SCRJREFEQPMNCONNECTION, PNLEQPMNCONNECTIONAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlBrlyLocRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyLocRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyLocRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMap", scrJrefMap)) add(SCRJREFMAP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefBgn1NLeg", scrJrefBgn1NLeg)) add(SCRJREFBGN1NLEG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlbgn1nlegAvail", pnlbgn1nlegAvail)) add(PNLBGN1NLEGAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefEnd1NLeg", scrJrefEnd1NLeg)) add(SCRJREFEND1NLEG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlend1nlegAvail", pnlend1nlegAvail)) add(PNLEND1NLEGAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefEqp1NNode", scrJrefEqp1NNode)) add(SCRJREFEQP1NNODE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnleqp1nnodeAvail", pnleqp1nnodeAvail)) add(PNLEQP1NNODEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNSegment", scrJrefMNSegment)) add(SCRJREFMNSEGMENT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefProxOrgMNLocation", scrJrefProxOrgMNLocation)) add(SCRJREFPROXORGMNLOCATION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefVisOrgMNLocation", scrJrefVisOrgMNLocation)) add(SCRJREFVISORGMNLOCATION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNLeg", scrJrefMNLeg)) add(SCRJREFMNLEG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNFlight", scrJrefMNFlight)) add(SCRJREFMNFLIGHT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefEqpMNConnection", scrJrefEqpMNConnection)) add(SCRJREFEQPMNCONNECTION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnleqpmnconnectionAvail", pnleqpmnconnectionAvail)) add(PNLEQPMNCONNECTIONAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyLocRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefMap.compare(comp->scrJrefMap) == 0) insert(items, SCRJREFMAP);
	if (scrJrefBgn1NLeg.compare(comp->scrJrefBgn1NLeg) == 0) insert(items, SCRJREFBGN1NLEG);
	if (pnlbgn1nlegAvail == comp->pnlbgn1nlegAvail) insert(items, PNLBGN1NLEGAVAIL);
	if (scrJrefEnd1NLeg.compare(comp->scrJrefEnd1NLeg) == 0) insert(items, SCRJREFEND1NLEG);
	if (pnlend1nlegAvail == comp->pnlend1nlegAvail) insert(items, PNLEND1NLEGAVAIL);
	if (scrJrefEqp1NNode.compare(comp->scrJrefEqp1NNode) == 0) insert(items, SCRJREFEQP1NNODE);
	if (pnleqp1nnodeAvail == comp->pnleqp1nnodeAvail) insert(items, PNLEQP1NNODEAVAIL);
	if (scrJrefMNSegment.compare(comp->scrJrefMNSegment) == 0) insert(items, SCRJREFMNSEGMENT);
	if (scrJrefProxOrgMNLocation.compare(comp->scrJrefProxOrgMNLocation) == 0) insert(items, SCRJREFPROXORGMNLOCATION);
	if (scrJrefVisOrgMNLocation.compare(comp->scrJrefVisOrgMNLocation) == 0) insert(items, SCRJREFVISORGMNLOCATION);
	if (scrJrefMNLeg.compare(comp->scrJrefMNLeg) == 0) insert(items, SCRJREFMNLEG);
	if (scrJrefMNFlight.compare(comp->scrJrefMNFlight) == 0) insert(items, SCRJREFMNFLIGHT);
	if (scrJrefEqpMNConnection.compare(comp->scrJrefEqpMNConnection) == 0) insert(items, SCRJREFEQPMNCONNECTION);
	if (pnleqpmnconnectionAvail == comp->pnleqpmnconnectionAvail) insert(items, PNLEQPMNCONNECTIONAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyLocRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, SCRJREFDETAIL, SCRJREFMAP, SCRJREFBGN1NLEG, PNLBGN1NLEGAVAIL, SCRJREFEND1NLEG, PNLEND1NLEGAVAIL, SCRJREFEQP1NNODE, PNLEQP1NNODEAVAIL, SCRJREFMNSEGMENT, SCRJREFPROXORGMNLOCATION, SCRJREFVISORGMNLOCATION, SCRJREFMNLEG, SCRJREFMNFLIGHT, SCRJREFEQPMNCONNECTION, PNLEQPMNCONNECTIONAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocRec::Tag
 ******************************************************************************/

PnlBrlyLocRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlBrlyLocRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyLocRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyLocRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyLocRec::DpchAppDo
 ******************************************************************************/

PnlBrlyLocRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyLocRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLocRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocRec::DpchEngData
 ******************************************************************************/

PnlBrlyLocRec::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCRECDATA) {
};

string PnlBrlyLocRec::DpchEngData::getSrefsMask() {
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

void PnlBrlyLocRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLocRecData");
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

