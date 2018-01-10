/**
  * \file PnlBrlySegPre.cpp
  * API code for job PnlBrlySegPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlySegPre.h"

/******************************************************************************
 class PnlBrlySegPre::ContIac
 ******************************************************************************/

PnlBrlySegPre::ContIac::ContIac(
			const double SldTme
			, const double SldPhi
		) : Block() {
	this->SldTme = SldTme;
	this->SldPhi = SldPhi;

	mask = {SLDTME, SLDPHI};
};

bool PnlBrlySegPre::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlySegPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlySegPre";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldTme", SldTme)) add(SLDTME);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldPhi", SldPhi)) add(SLDPHI);
	};

	return basefound;
};

void PnlBrlySegPre::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlySegPre";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlySegPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldTme", SldTme);
		writeDoubleAttr(wr, itemtag, "sref", "SldPhi", SldPhi);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegPre::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldTme, comp->SldTme) < 1.0e-4) insert(items, SLDTME);
	if (compareDouble(SldPhi, comp->SldPhi) < 1.0e-4) insert(items, SLDPHI);

	return(items);
};

set<uint> PnlBrlySegPre::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDTME, SLDPHI};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegPre::StatApp
 ******************************************************************************/

PnlBrlySegPre::StatApp::StatApp(
			const uint ixBrlyVExpstate
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;

	mask = {IXBRLYVEXPSTATE};
};

bool PnlBrlySegPre::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlySegPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlySegPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlBrlySegPre::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);

	return(items);
};

set<uint> PnlBrlySegPre::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegPre::StatShr
 ******************************************************************************/

PnlBrlySegPre::StatShr::StatShr(
			const double SldTmeMin
			, const double SldTmeMax
			, const double SldPhiMin
			, const double SldPhiMax
		) : Block() {
	this->SldTmeMin = SldTmeMin;
	this->SldTmeMax = SldTmeMax;
	this->SldPhiMin = SldPhiMin;
	this->SldPhiMax = SldPhiMax;

	mask = {SLDTMEMIN, SLDTMEMAX, SLDPHIMIN, SLDPHIMAX};
};

bool PnlBrlySegPre::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlySegPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlySegPre";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTmeMin", SldTmeMin)) add(SLDTMEMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTmeMax", SldTmeMax)) add(SLDTMEMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldPhiMin", SldPhiMin)) add(SLDPHIMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldPhiMax", SldPhiMax)) add(SLDPHIMAX);
	};

	return basefound;
};

set<uint> PnlBrlySegPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (compareDouble(SldTmeMin, comp->SldTmeMin) < 1.0e-4) insert(items, SLDTMEMIN);
	if (compareDouble(SldTmeMax, comp->SldTmeMax) < 1.0e-4) insert(items, SLDTMEMAX);
	if (compareDouble(SldPhiMin, comp->SldPhiMin) < 1.0e-4) insert(items, SLDPHIMIN);
	if (compareDouble(SldPhiMax, comp->SldPhiMax) < 1.0e-4) insert(items, SLDPHIMAX);

	return(items);
};

set<uint> PnlBrlySegPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDTMEMIN, SLDTMEMAX, SLDPHIMIN, SLDPHIMAX};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegPre::Tag
 ******************************************************************************/

PnlBrlySegPre::Tag::Tag(
			const string& Cpt
			, const string& CptTme
			, const string& CptPhi
		) : Block() {
	this->Cpt = Cpt;
	this->CptTme = CptTme;
	this->CptPhi = CptPhi;

	mask = {CPT, CPTTME, CPTPHI};
};

bool PnlBrlySegPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlySegPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlySegPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTme", CptTme)) add(CPTTME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPhi", CptPhi)) add(CPTPHI);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlySegPre::DpchAppData
 ******************************************************************************/

PnlBrlySegPre::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYSEGPREDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlySegPre::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegPre::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlySegPreData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlySegPre::DpchEngData
 ******************************************************************************/

PnlBrlySegPre::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYSEGPREDATA) {
};

string PnlBrlySegPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlySegPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

