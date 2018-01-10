/**
  * \file PnlBrlyFltRec.cpp
  * API code for job PnlBrlyFltRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyFltRec.h"

/******************************************************************************
 class PnlBrlyFltRec::VecVDo
 ******************************************************************************/

uint PnlBrlyFltRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyFltRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyFltRec::ContInf
 ******************************************************************************/

PnlBrlyFltRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlBrlyFltRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyFltRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyFltRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlBrlyFltRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyFltRec::ContInf::diff(
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
 class PnlBrlyFltRec::StatApp
 ******************************************************************************/

PnlBrlyFltRec::StatApp::StatApp(
			const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneFafAWaypoint
			, const bool initdone1NConnection
			, const bool initdoneRef1NSegment
			, const bool initdoneEqp1NNode
			, const bool initdoneMNLocation
			, const bool initdoneMNConnection
			, const bool initdoneOrgMNFlight
			, const bool initdoneEqpMNConnection
		) : Block() {
	this->initdonePre = initdonePre;
	this->initdoneDetail = initdoneDetail;
	this->initdoneFafAWaypoint = initdoneFafAWaypoint;
	this->initdone1NConnection = initdone1NConnection;
	this->initdoneRef1NSegment = initdoneRef1NSegment;
	this->initdoneEqp1NNode = initdoneEqp1NNode;
	this->initdoneMNLocation = initdoneMNLocation;
	this->initdoneMNConnection = initdoneMNConnection;
	this->initdoneOrgMNFlight = initdoneOrgMNFlight;
	this->initdoneEqpMNConnection = initdoneEqpMNConnection;

	mask = {INITDONEPRE, INITDONEDETAIL, INITDONEFAFAWAYPOINT, INITDONE1NCONNECTION, INITDONEREF1NSEGMENT, INITDONEEQP1NNODE, INITDONEMNLOCATION, INITDONEMNCONNECTION, INITDONEORGMNFLIGHT, INITDONEEQPMNCONNECTION};
};

bool PnlBrlyFltRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyFltRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyFltRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneFafAWaypoint", initdoneFafAWaypoint)) add(INITDONEFAFAWAYPOINT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NConnection", initdone1NConnection)) add(INITDONE1NCONNECTION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NSegment", initdoneRef1NSegment)) add(INITDONEREF1NSEGMENT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneEqp1NNode", initdoneEqp1NNode)) add(INITDONEEQP1NNODE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNLocation", initdoneMNLocation)) add(INITDONEMNLOCATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNConnection", initdoneMNConnection)) add(INITDONEMNCONNECTION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneOrgMNFlight", initdoneOrgMNFlight)) add(INITDONEORGMNFLIGHT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneEqpMNConnection", initdoneEqpMNConnection)) add(INITDONEEQPMNCONNECTION);
	};

	return basefound;
};

set<uint> PnlBrlyFltRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneFafAWaypoint == comp->initdoneFafAWaypoint) insert(items, INITDONEFAFAWAYPOINT);
	if (initdone1NConnection == comp->initdone1NConnection) insert(items, INITDONE1NCONNECTION);
	if (initdoneRef1NSegment == comp->initdoneRef1NSegment) insert(items, INITDONEREF1NSEGMENT);
	if (initdoneEqp1NNode == comp->initdoneEqp1NNode) insert(items, INITDONEEQP1NNODE);
	if (initdoneMNLocation == comp->initdoneMNLocation) insert(items, INITDONEMNLOCATION);
	if (initdoneMNConnection == comp->initdoneMNConnection) insert(items, INITDONEMNCONNECTION);
	if (initdoneOrgMNFlight == comp->initdoneOrgMNFlight) insert(items, INITDONEORGMNFLIGHT);
	if (initdoneEqpMNConnection == comp->initdoneEqpMNConnection) insert(items, INITDONEEQPMNCONNECTION);

	return(items);
};

set<uint> PnlBrlyFltRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEPRE, INITDONEDETAIL, INITDONEFAFAWAYPOINT, INITDONE1NCONNECTION, INITDONEREF1NSEGMENT, INITDONEEQP1NNODE, INITDONEMNLOCATION, INITDONEMNCONNECTION, INITDONEORGMNFLIGHT, INITDONEEQPMNCONNECTION};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltRec::StatShr
 ******************************************************************************/

PnlBrlyFltRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const string& scrJrefPre
			, const string& scrJrefDetail
			, const string& scrJrefFafAWaypoint
			, const bool pnlfafawaypointAvail
			, const string& scrJref1NConnection
			, const string& scrJrefRef1NSegment
			, const string& scrJrefEqp1NNode
			, const bool pnleqp1nnodeAvail
			, const string& scrJrefMNLocation
			, const string& scrJrefMNConnection
			, const string& scrJrefOrgMNFlight
			, const string& scrJrefEqpMNConnection
			, const bool pnleqpmnconnectionAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->scrJrefPre = scrJrefPre;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefFafAWaypoint = scrJrefFafAWaypoint;
	this->pnlfafawaypointAvail = pnlfafawaypointAvail;
	this->scrJref1NConnection = scrJref1NConnection;
	this->scrJrefRef1NSegment = scrJrefRef1NSegment;
	this->scrJrefEqp1NNode = scrJrefEqp1NNode;
	this->pnleqp1nnodeAvail = pnleqp1nnodeAvail;
	this->scrJrefMNLocation = scrJrefMNLocation;
	this->scrJrefMNConnection = scrJrefMNConnection;
	this->scrJrefOrgMNFlight = scrJrefOrgMNFlight;
	this->scrJrefEqpMNConnection = scrJrefEqpMNConnection;
	this->pnleqpmnconnectionAvail = pnleqpmnconnectionAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFFAFAWAYPOINT, PNLFAFAWAYPOINTAVAIL, SCRJREF1NCONNECTION, SCRJREFREF1NSEGMENT, SCRJREFEQP1NNODE, PNLEQP1NNODEAVAIL, SCRJREFMNLOCATION, SCRJREFMNCONNECTION, SCRJREFORGMNFLIGHT, SCRJREFEQPMNCONNECTION, PNLEQPMNCONNECTIONAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlBrlyFltRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyFltRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyFltRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefFafAWaypoint", scrJrefFafAWaypoint)) add(SCRJREFFAFAWAYPOINT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlfafawaypointAvail", pnlfafawaypointAvail)) add(PNLFAFAWAYPOINTAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NConnection", scrJref1NConnection)) add(SCRJREF1NCONNECTION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NSegment", scrJrefRef1NSegment)) add(SCRJREFREF1NSEGMENT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefEqp1NNode", scrJrefEqp1NNode)) add(SCRJREFEQP1NNODE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnleqp1nnodeAvail", pnleqp1nnodeAvail)) add(PNLEQP1NNODEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNLocation", scrJrefMNLocation)) add(SCRJREFMNLOCATION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNConnection", scrJrefMNConnection)) add(SCRJREFMNCONNECTION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefOrgMNFlight", scrJrefOrgMNFlight)) add(SCRJREFORGMNFLIGHT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefEqpMNConnection", scrJrefEqpMNConnection)) add(SCRJREFEQPMNCONNECTION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnleqpmnconnectionAvail", pnleqpmnconnectionAvail)) add(PNLEQPMNCONNECTIONAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyFltRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (scrJrefPre.compare(comp->scrJrefPre) == 0) insert(items, SCRJREFPRE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefFafAWaypoint.compare(comp->scrJrefFafAWaypoint) == 0) insert(items, SCRJREFFAFAWAYPOINT);
	if (pnlfafawaypointAvail == comp->pnlfafawaypointAvail) insert(items, PNLFAFAWAYPOINTAVAIL);
	if (scrJref1NConnection.compare(comp->scrJref1NConnection) == 0) insert(items, SCRJREF1NCONNECTION);
	if (scrJrefRef1NSegment.compare(comp->scrJrefRef1NSegment) == 0) insert(items, SCRJREFREF1NSEGMENT);
	if (scrJrefEqp1NNode.compare(comp->scrJrefEqp1NNode) == 0) insert(items, SCRJREFEQP1NNODE);
	if (pnleqp1nnodeAvail == comp->pnleqp1nnodeAvail) insert(items, PNLEQP1NNODEAVAIL);
	if (scrJrefMNLocation.compare(comp->scrJrefMNLocation) == 0) insert(items, SCRJREFMNLOCATION);
	if (scrJrefMNConnection.compare(comp->scrJrefMNConnection) == 0) insert(items, SCRJREFMNCONNECTION);
	if (scrJrefOrgMNFlight.compare(comp->scrJrefOrgMNFlight) == 0) insert(items, SCRJREFORGMNFLIGHT);
	if (scrJrefEqpMNConnection.compare(comp->scrJrefEqpMNConnection) == 0) insert(items, SCRJREFEQPMNCONNECTION);
	if (pnleqpmnconnectionAvail == comp->pnleqpmnconnectionAvail) insert(items, PNLEQPMNCONNECTIONAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyFltRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFFAFAWAYPOINT, PNLFAFAWAYPOINTAVAIL, SCRJREF1NCONNECTION, SCRJREFREF1NSEGMENT, SCRJREFEQP1NNODE, PNLEQP1NNODEAVAIL, SCRJREFMNLOCATION, SCRJREFMNCONNECTION, SCRJREFORGMNFLIGHT, SCRJREFEQPMNCONNECTION, PNLEQPMNCONNECTIONAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltRec::Tag
 ******************************************************************************/

PnlBrlyFltRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlBrlyFltRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyFltRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyFltRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyFltRec::DpchAppDo
 ******************************************************************************/

PnlBrlyFltRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyFltRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyFltRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltRec::DpchEngData
 ******************************************************************************/

PnlBrlyFltRec::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYFLTRECDATA) {
};

string PnlBrlyFltRec::DpchEngData::getSrefsMask() {
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

void PnlBrlyFltRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyFltRecData");
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

