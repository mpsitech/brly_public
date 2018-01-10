/**
  * \file PnlBrlyNavConnect.cpp
  * API code for job PnlBrlyNavConnect (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyNavConnect.h"

/******************************************************************************
 class PnlBrlyNavConnect::VecVDo
 ******************************************************************************/

uint PnlBrlyNavConnect::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butconviewclick") return BUTCONVIEWCLICK;
	else if (s == "butconnewcrdclick") return BUTCONNEWCRDCLICK;
	else if (s == "butrlyviewclick") return BUTRLYVIEWCLICK;

	return(0);
};

string PnlBrlyNavConnect::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCONVIEWCLICK) return("ButConViewClick");
	else if (ix == BUTCONNEWCRDCLICK) return("ButConNewcrdClick");
	else if (ix == BUTRLYVIEWCLICK) return("ButRlyViewClick");

	return("");
};

/******************************************************************************
 class PnlBrlyNavConnect::ContIac
 ******************************************************************************/

PnlBrlyNavConnect::ContIac::ContIac(
			const uint numFLstCon
			, const uint numFLstRly
		) : Block() {
	this->numFLstCon = numFLstCon;
	this->numFLstRly = numFLstRly;

	mask = {NUMFLSTCON, NUMFLSTRLY};
};

bool PnlBrlyNavConnect::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyNavConnect");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyNavConnect";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCon", numFLstCon)) add(NUMFLSTCON);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRly", numFLstRly)) add(NUMFLSTRLY);
	};

	return basefound;
};

void PnlBrlyNavConnect::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyNavConnect";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyNavConnect";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstCon", numFLstCon);
		writeUintAttr(wr, itemtag, "sref", "numFLstRly", numFLstRly);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyNavConnect::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstCon == comp->numFLstCon) insert(items, NUMFLSTCON);
	if (numFLstRly == comp->numFLstRly) insert(items, NUMFLSTRLY);

	return(items);
};

set<uint> PnlBrlyNavConnect::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCON, NUMFLSTRLY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavConnect::StatApp
 ******************************************************************************/

PnlBrlyNavConnect::StatApp::StatApp(
			const uint ixBrlyVExpstate
			, const bool LstConAlt
			, const bool LstRlyAlt
			, const uint LstConNumFirstdisp
			, const uint LstRlyNumFirstdisp
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->LstConAlt = LstConAlt;
	this->LstRlyAlt = LstRlyAlt;
	this->LstConNumFirstdisp = LstConNumFirstdisp;
	this->LstRlyNumFirstdisp = LstRlyNumFirstdisp;

	mask = {IXBRLYVEXPSTATE, LSTCONALT, LSTRLYALT, LSTCONNUMFIRSTDISP, LSTRLYNUMFIRSTDISP};
};

bool PnlBrlyNavConnect::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyNavConnect");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyNavConnect";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstConAlt", LstConAlt)) add(LSTCONALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRlyAlt", LstRlyAlt)) add(LSTRLYALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstConNumFirstdisp", LstConNumFirstdisp)) add(LSTCONNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRlyNumFirstdisp", LstRlyNumFirstdisp)) add(LSTRLYNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlBrlyNavConnect::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (LstConAlt == comp->LstConAlt) insert(items, LSTCONALT);
	if (LstRlyAlt == comp->LstRlyAlt) insert(items, LSTRLYALT);
	if (LstConNumFirstdisp == comp->LstConNumFirstdisp) insert(items, LSTCONNUMFIRSTDISP);
	if (LstRlyNumFirstdisp == comp->LstRlyNumFirstdisp) insert(items, LSTRLYNUMFIRSTDISP);

	return(items);
};

set<uint> PnlBrlyNavConnect::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, LSTCONALT, LSTRLYALT, LSTCONNUMFIRSTDISP, LSTRLYNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavConnect::StatShr
 ******************************************************************************/

PnlBrlyNavConnect::StatShr::StatShr(
			const bool LstConAvail
			, const bool ButConViewActive
			, const bool LstRlyAvail
			, const bool ButRlyViewActive
		) : Block() {
	this->LstConAvail = LstConAvail;
	this->ButConViewActive = ButConViewActive;
	this->LstRlyAvail = LstRlyAvail;
	this->ButRlyViewActive = ButRlyViewActive;

	mask = {LSTCONAVAIL, BUTCONVIEWACTIVE, LSTRLYAVAIL, BUTRLYVIEWACTIVE};
};

bool PnlBrlyNavConnect::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyNavConnect");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyNavConnect";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstConAvail", LstConAvail)) add(LSTCONAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButConViewActive", ButConViewActive)) add(BUTCONVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRlyAvail", LstRlyAvail)) add(LSTRLYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRlyViewActive", ButRlyViewActive)) add(BUTRLYVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyNavConnect::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstConAvail == comp->LstConAvail) insert(items, LSTCONAVAIL);
	if (ButConViewActive == comp->ButConViewActive) insert(items, BUTCONVIEWACTIVE);
	if (LstRlyAvail == comp->LstRlyAvail) insert(items, LSTRLYAVAIL);
	if (ButRlyViewActive == comp->ButRlyViewActive) insert(items, BUTRLYVIEWACTIVE);

	return(items);
};

set<uint> PnlBrlyNavConnect::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTCONAVAIL, BUTCONVIEWACTIVE, LSTRLYAVAIL, BUTRLYVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavConnect::Tag
 ******************************************************************************/

PnlBrlyNavConnect::Tag::Tag(
			const string& Cpt
			, const string& CptCon
			, const string& CptRly
		) : Block() {
	this->Cpt = Cpt;
	this->CptCon = CptCon;
	this->CptRly = CptRly;

	mask = {CPT, CPTCON, CPTRLY};
};

bool PnlBrlyNavConnect::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyNavConnect");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyNavConnect";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCon", CptCon)) add(CPTCON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRly", CptRly)) add(CPTRLY);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyNavConnect::DpchAppData
 ******************************************************************************/

PnlBrlyNavConnect::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVCONNECTDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlyNavConnect::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavConnect::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyNavConnectData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavConnect::DpchAppDo
 ******************************************************************************/

PnlBrlyNavConnect::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVCONNECTDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyNavConnect::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavConnect::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyNavConnectDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavConnect::DpchEngData
 ******************************************************************************/

PnlBrlyNavConnect::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYNAVCONNECTDATA) {
	feedFLstCon.tag = "FeedFLstCon";
	feedFLstRly.tag = "FeedFLstRly";
};

string PnlBrlyNavConnect::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCON)) ss.push_back("feedFLstCon");
	if (has(FEEDFLSTRLY)) ss.push_back("feedFLstRly");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavConnect::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyNavConnectData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstCon.readXML(docctx, basexpath, true)) add(FEEDFLSTCON);
		if (feedFLstRly.readXML(docctx, basexpath, true)) add(FEEDFLSTRLY);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstCon.clear();
		feedFLstRly.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

