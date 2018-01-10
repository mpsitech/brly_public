/**
  * \file PnlBrlyPrsDetail.cpp
  * API code for job PnlBrlyPrsDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyPrsDetail.h"

/******************************************************************************
 class PnlBrlyPrsDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyPrsDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butjlneditclick") return BUTJLNEDITCLICK;

	return(0);
};

string PnlBrlyPrsDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTJLNEDITCLICK) return("ButJlnEditClick");

	return("");
};

/******************************************************************************
 class PnlBrlyPrsDetail::ContIac
 ******************************************************************************/

PnlBrlyPrsDetail::ContIac::ContIac(
			const string& TxfTit
			, const string& TxfFnm
			, const uint numFPupJln
			, const vector<uint>& numsFLstDrv
			, const uint numFPupSex
			, const string& TxfTel
			, const string& TxfEml
			, const string& TxfSal
		) : Block() {
	this->TxfTit = TxfTit;
	this->TxfFnm = TxfFnm;
	this->numFPupJln = numFPupJln;
	this->numsFLstDrv = numsFLstDrv;
	this->numFPupSex = numFPupSex;
	this->TxfTel = TxfTel;
	this->TxfEml = TxfEml;
	this->TxfSal = TxfSal;

	mask = {TXFTIT, TXFFNM, NUMFPUPJLN, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL};
};

bool PnlBrlyPrsDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFnm", TxfFnm)) add(TXFFNM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJln", numFPupJln)) add(NUMFPUPJLN);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstDrv", numsFLstDrv)) add(NUMSFLSTDRV);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSex", numFPupSex)) add(NUMFPUPSEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTel", TxfTel)) add(TXFTEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEml", TxfEml)) add(TXFEML);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSal", TxfSal)) add(TXFSAL);
	};

	return basefound;
};

void PnlBrlyPrsDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeStringAttr(wr, itemtag, "sref", "TxfFnm", TxfFnm);
		writeUintAttr(wr, itemtag, "sref", "numFPupJln", numFPupJln);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstDrv", numsFLstDrv);
		writeUintAttr(wr, itemtag, "sref", "numFPupSex", numFPupSex);
		writeStringAttr(wr, itemtag, "sref", "TxfTel", TxfTel);
		writeStringAttr(wr, itemtag, "sref", "TxfEml", TxfEml);
		writeStringAttr(wr, itemtag, "sref", "TxfSal", TxfSal);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyPrsDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit.compare(comp->TxfTit) == 0) insert(items, TXFTIT);
	if (TxfFnm.compare(comp->TxfFnm) == 0) insert(items, TXFFNM);
	if (numFPupJln == comp->numFPupJln) insert(items, NUMFPUPJLN);
	if (compareUintvec(numsFLstDrv, comp->numsFLstDrv)) insert(items, NUMSFLSTDRV);
	if (numFPupSex == comp->numFPupSex) insert(items, NUMFPUPSEX);
	if (TxfTel.compare(comp->TxfTel) == 0) insert(items, TXFTEL);
	if (TxfEml.compare(comp->TxfEml) == 0) insert(items, TXFEML);
	if (TxfSal.compare(comp->TxfSal) == 0) insert(items, TXFSAL);

	return(items);
};

set<uint> PnlBrlyPrsDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, TXFFNM, NUMFPUPJLN, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyPrsDetail::ContInf
 ******************************************************************************/

PnlBrlyPrsDetail::ContInf::ContInf(
			const string& TxtLnm
			, const string& TxtDrv
		) : Block() {
	this->TxtLnm = TxtLnm;
	this->TxtDrv = TxtDrv;

	mask = {TXTLNM, TXTDRV};
};

bool PnlBrlyPrsDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtLnm", TxtLnm)) add(TXTLNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDrv", TxtDrv)) add(TXTDRV);
	};

	return basefound;
};

set<uint> PnlBrlyPrsDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtLnm.compare(comp->TxtLnm) == 0) insert(items, TXTLNM);
	if (TxtDrv.compare(comp->TxtDrv) == 0) insert(items, TXTDRV);

	return(items);
};

set<uint> PnlBrlyPrsDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTLNM, TXTDRV};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyPrsDetail::StatApp
 ******************************************************************************/

PnlBrlyPrsDetail::StatApp::StatApp(
			const uint ixBrlyVExpstate
			, const bool LstDrvAlt
			, const uint LstDrvNumFirstdisp
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->LstDrvAlt = LstDrvAlt;
	this->LstDrvNumFirstdisp = LstDrvNumFirstdisp;

	mask = {IXBRLYVEXPSTATE, LSTDRVALT, LSTDRVNUMFIRSTDISP};
};

bool PnlBrlyPrsDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDrvAlt", LstDrvAlt)) add(LSTDRVALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDrvNumFirstdisp", LstDrvNumFirstdisp)) add(LSTDRVNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlBrlyPrsDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (LstDrvAlt == comp->LstDrvAlt) insert(items, LSTDRVALT);
	if (LstDrvNumFirstdisp == comp->LstDrvNumFirstdisp) insert(items, LSTDRVNUMFIRSTDISP);

	return(items);
};

set<uint> PnlBrlyPrsDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, LSTDRVALT, LSTDRVNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyPrsDetail::StatShr
 ******************************************************************************/

PnlBrlyPrsDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxfTitActive
			, const bool TxfFnmActive
			, const bool PupJlnActive
			, const bool ButJlnEditAvail
			, const bool TxtLnmActive
			, const bool LstDrvActive
			, const bool PupSexActive
			, const bool TxfTelActive
			, const bool TxfEmlActive
			, const bool TxfSalActive
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxfTitActive = TxfTitActive;
	this->TxfFnmActive = TxfFnmActive;
	this->PupJlnActive = PupJlnActive;
	this->ButJlnEditAvail = ButJlnEditAvail;
	this->TxtLnmActive = TxtLnmActive;
	this->LstDrvActive = LstDrvActive;
	this->PupSexActive = PupSexActive;
	this->TxfTelActive = TxfTelActive;
	this->TxfEmlActive = TxfEmlActive;
	this->TxfSalActive = TxfSalActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXFFNMACTIVE, PUPJLNACTIVE, BUTJLNEDITAVAIL, TXTLNMACTIVE, LSTDRVACTIVE, PUPSEXACTIVE, TXFTELACTIVE, TXFEMLACTIVE, TXFSALACTIVE};
};

bool PnlBrlyPrsDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyPrsDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTitActive", TxfTitActive)) add(TXFTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFnmActive", TxfFnmActive)) add(TXFFNMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJlnActive", PupJlnActive)) add(PUPJLNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJlnEditAvail", ButJlnEditAvail)) add(BUTJLNEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtLnmActive", TxtLnmActive)) add(TXTLNMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDrvActive", LstDrvActive)) add(LSTDRVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupSexActive", PupSexActive)) add(PUPSEXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTelActive", TxfTelActive)) add(TXFTELACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfEmlActive", TxfEmlActive)) add(TXFEMLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSalActive", TxfSalActive)) add(TXFSALACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyPrsDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxfFnmActive == comp->TxfFnmActive) insert(items, TXFFNMACTIVE);
	if (PupJlnActive == comp->PupJlnActive) insert(items, PUPJLNACTIVE);
	if (ButJlnEditAvail == comp->ButJlnEditAvail) insert(items, BUTJLNEDITAVAIL);
	if (TxtLnmActive == comp->TxtLnmActive) insert(items, TXTLNMACTIVE);
	if (LstDrvActive == comp->LstDrvActive) insert(items, LSTDRVACTIVE);
	if (PupSexActive == comp->PupSexActive) insert(items, PUPSEXACTIVE);
	if (TxfTelActive == comp->TxfTelActive) insert(items, TXFTELACTIVE);
	if (TxfEmlActive == comp->TxfEmlActive) insert(items, TXFEMLACTIVE);
	if (TxfSalActive == comp->TxfSalActive) insert(items, TXFSALACTIVE);

	return(items);
};

set<uint> PnlBrlyPrsDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXFFNMACTIVE, PUPJLNACTIVE, BUTJLNEDITAVAIL, TXTLNMACTIVE, LSTDRVACTIVE, PUPSEXACTIVE, TXFTELACTIVE, TXFEMLACTIVE, TXFSALACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyPrsDetail::Tag
 ******************************************************************************/

PnlBrlyPrsDetail::Tag::Tag(
			const string& Cpt
			, const string& CptTit
			, const string& CptFnm
			, const string& CptLnm
			, const string& CptDrv
			, const string& CptSex
			, const string& CptTel
			, const string& CptEml
			, const string& CptSal
		) : Block() {
	this->Cpt = Cpt;
	this->CptTit = CptTit;
	this->CptFnm = CptFnm;
	this->CptLnm = CptLnm;
	this->CptDrv = CptDrv;
	this->CptSex = CptSex;
	this->CptTel = CptTel;
	this->CptEml = CptEml;
	this->CptSal = CptSal;

	mask = {CPT, CPTTIT, CPTFNM, CPTLNM, CPTDRV, CPTSEX, CPTTEL, CPTEML, CPTSAL};
};

bool PnlBrlyPrsDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFnm", CptFnm)) add(CPTFNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLnm", CptLnm)) add(CPTLNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDrv", CptDrv)) add(CPTDRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSex", CptSex)) add(CPTSEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTel", CptTel)) add(CPTTEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEml", CptEml)) add(CPTEML);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSal", CptSal)) add(CPTSAL);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyPrsDetail::DpchAppData
 ******************************************************************************/

PnlBrlyPrsDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYPRSDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlyPrsDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyPrsDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyPrsDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyPrsDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyPrsDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYPRSDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyPrsDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyPrsDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyPrsDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyPrsDetail::DpchEngData
 ******************************************************************************/

PnlBrlyPrsDetail::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYPRSDETAILDATA) {
	feedFLstDrv.tag = "FeedFLstDrv";
	feedFPupJln.tag = "FeedFPupJln";
	feedFPupSex.tag = "FeedFPupSex";
};

string PnlBrlyPrsDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTDRV)) ss.push_back("feedFLstDrv");
	if (has(FEEDFPUPJLN)) ss.push_back("feedFPupJln");
	if (has(FEEDFPUPSEX)) ss.push_back("feedFPupSex");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyPrsDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyPrsDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstDrv.readXML(docctx, basexpath, true)) add(FEEDFLSTDRV);
		if (feedFPupJln.readXML(docctx, basexpath, true)) add(FEEDFPUPJLN);
		if (feedFPupSex.readXML(docctx, basexpath, true)) add(FEEDFPUPSEX);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstDrv.clear();
		feedFPupJln.clear();
		feedFPupSex.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

