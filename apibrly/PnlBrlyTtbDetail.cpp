/**
  * \file PnlBrlyTtbDetail.cpp
  * API code for job PnlBrlyTtbDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyTtbDetail.h"

/******************************************************************************
 class PnlBrlyTtbDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyTtbDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	else if (s == "butalieditclick") return BUTALIEDITCLICK;

	return(0);
};

string PnlBrlyTtbDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	else if (ix == BUTALIEDITCLICK) return("ButAliEditClick");

	return("");
};

/******************************************************************************
 class PnlBrlyTtbDetail::ContIac
 ******************************************************************************/

PnlBrlyTtbDetail::ContIac::ContIac(
			const string& TxfTit
			, const uint numFPupAli
			, const string& TxfAli
			, const string& TxfSta
			, const string& TxfSto
		) : Block() {
	this->TxfTit = TxfTit;
	this->numFPupAli = numFPupAli;
	this->TxfAli = TxfAli;
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;

	mask = {TXFTIT, NUMFPUPALI, TXFALI, TXFSTA, TXFSTO};
};

bool PnlBrlyTtbDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyTtbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyTtbDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAli", numFPupAli)) add(NUMFPUPALI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAli", TxfAli)) add(TXFALI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
	};

	return basefound;
};

void PnlBrlyTtbDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyTtbDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyTtbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupAli", numFPupAli);
		writeStringAttr(wr, itemtag, "sref", "TxfAli", TxfAli);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyTtbDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit.compare(comp->TxfTit) == 0) insert(items, TXFTIT);
	if (numFPupAli == comp->numFPupAli) insert(items, NUMFPUPALI);
	if (TxfAli.compare(comp->TxfAli) == 0) insert(items, TXFALI);
	if (TxfSta.compare(comp->TxfSta) == 0) insert(items, TXFSTA);
	if (TxfSto.compare(comp->TxfSto) == 0) insert(items, TXFSTO);

	return(items);
};

set<uint> PnlBrlyTtbDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMFPUPALI, TXFALI, TXFSTA, TXFSTO};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyTtbDetail::ContInf
 ******************************************************************************/

PnlBrlyTtbDetail::ContInf::ContInf(
			const string& TxtFil
		) : Block() {
	this->TxtFil = TxtFil;

	mask = {TXTFIL};
};

bool PnlBrlyTtbDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyTtbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyTtbDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFil", TxtFil)) add(TXTFIL);
	};

	return basefound;
};

set<uint> PnlBrlyTtbDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFil.compare(comp->TxtFil) == 0) insert(items, TXTFIL);

	return(items);
};

set<uint> PnlBrlyTtbDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyTtbDetail::StatApp
 ******************************************************************************/

PnlBrlyTtbDetail::StatApp::StatApp(
			const uint ixBrlyVExpstate
			, const bool PupAliAlt
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->PupAliAlt = PupAliAlt;

	mask = {IXBRLYVEXPSTATE, PUPALIALT};
};

bool PnlBrlyTtbDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyTtbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyTtbDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupAliAlt", PupAliAlt)) add(PUPALIALT);
	};

	return basefound;
};

set<uint> PnlBrlyTtbDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (PupAliAlt == comp->PupAliAlt) insert(items, PUPALIALT);

	return(items);
};

set<uint> PnlBrlyTtbDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, PUPALIALT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyTtbDetail::StatShr
 ******************************************************************************/

PnlBrlyTtbDetail::StatShr::StatShr(
			const bool TxfAliValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxfTitActive
			, const bool TxtFilActive
			, const bool ButFilViewAvail
			, const bool ButFilViewActive
			, const bool PupAliActive
			, const bool ButAliEditAvail
			, const bool TxfStaActive
			, const bool TxfStoActive
		) : Block() {
	this->TxfAliValid = TxfAliValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxfTitActive = TxfTitActive;
	this->TxtFilActive = TxtFilActive;
	this->ButFilViewAvail = ButFilViewAvail;
	this->ButFilViewActive = ButFilViewActive;
	this->PupAliActive = PupAliActive;
	this->ButAliEditAvail = ButAliEditAvail;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;

	mask = {TXFALIVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXTFILACTIVE, BUTFILVIEWAVAIL, BUTFILVIEWACTIVE, PUPALIACTIVE, BUTALIEDITAVAIL, TXFSTAACTIVE, TXFSTOACTIVE};
};

bool PnlBrlyTtbDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyTtbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyTtbDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAliValid", TxfAliValid)) add(TXFALIVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTitActive", TxfTitActive)) add(TXFTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFilActive", TxtFilActive)) add(TXTFILACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFilViewAvail", ButFilViewAvail)) add(BUTFILVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFilViewActive", ButFilViewActive)) add(BUTFILVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupAliActive", PupAliActive)) add(PUPALIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAliEditAvail", ButAliEditAvail)) add(BUTALIEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStoActive", TxfStoActive)) add(TXFSTOACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyTtbDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfAliValid == comp->TxfAliValid) insert(items, TXFALIVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxtFilActive == comp->TxtFilActive) insert(items, TXTFILACTIVE);
	if (ButFilViewAvail == comp->ButFilViewAvail) insert(items, BUTFILVIEWAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);
	if (PupAliActive == comp->PupAliActive) insert(items, PUPALIACTIVE);
	if (ButAliEditAvail == comp->ButAliEditAvail) insert(items, BUTALIEDITAVAIL);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);

	return(items);
};

set<uint> PnlBrlyTtbDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFALIVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXTFILACTIVE, BUTFILVIEWAVAIL, BUTFILVIEWACTIVE, PUPALIACTIVE, BUTALIEDITAVAIL, TXFSTAACTIVE, TXFSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyTtbDetail::Tag
 ******************************************************************************/

PnlBrlyTtbDetail::Tag::Tag(
			const string& Cpt
			, const string& CptTit
			, const string& CptFil
			, const string& CptAli
			, const string& CptSta
			, const string& CptSto
		) : Block() {
	this->Cpt = Cpt;
	this->CptTit = CptTit;
	this->CptFil = CptFil;
	this->CptAli = CptAli;
	this->CptSta = CptSta;
	this->CptSto = CptSto;

	mask = {CPT, CPTTIT, CPTFIL, CPTALI, CPTSTA, CPTSTO};
};

bool PnlBrlyTtbDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyTtbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyTtbDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFil", CptFil)) add(CPTFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAli", CptAli)) add(CPTALI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSto", CptSto)) add(CPTSTO);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyTtbDetail::DpchAppData
 ******************************************************************************/

PnlBrlyTtbDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYTTBDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlyTtbDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyTtbDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyTtbDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyTtbDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyTtbDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYTTBDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyTtbDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyTtbDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyTtbDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyTtbDetail::DpchEngData
 ******************************************************************************/

PnlBrlyTtbDetail::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYTTBDETAILDATA) {
	feedFPupAli.tag = "FeedFPupAli";
};

string PnlBrlyTtbDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPALI)) ss.push_back("feedFPupAli");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyTtbDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyTtbDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupAli.readXML(docctx, basexpath, true)) add(FEEDFPUPALI);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupAli.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

