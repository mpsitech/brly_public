/**
  * \file PnlBrlySegDetail.cpp
  * API code for job PnlBrlySegDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlySegDetail.h"

/******************************************************************************
 class PnlBrlySegDetail::VecVDo
 ******************************************************************************/

uint PnlBrlySegDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butreuviewclick") return BUTREUVIEWCLICK;

	return(0);
};

string PnlBrlySegDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");

	return("");
};

/******************************************************************************
 class PnlBrlySegDetail::ContIac
 ******************************************************************************/

PnlBrlySegDetail::ContIac::ContIac(
			const uint numFPupRet
			, const string& TxfDph
			, const string& TxfAl0
			, const string& TxfAl1
			, const string& TxfTh0
			, const string& TxfTh1
			, const string& TxfPh0
			, const string& TxfPh1
			, const string& TxfSta
			, const string& TxfSto
			, const bool ChkCdn
		) : Block() {
	this->numFPupRet = numFPupRet;
	this->TxfDph = TxfDph;
	this->TxfAl0 = TxfAl0;
	this->TxfAl1 = TxfAl1;
	this->TxfTh0 = TxfTh0;
	this->TxfTh1 = TxfTh1;
	this->TxfPh0 = TxfPh0;
	this->TxfPh1 = TxfPh1;
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->ChkCdn = ChkCdn;

	mask = {NUMFPUPRET, TXFDPH, TXFAL0, TXFAL1, TXFTH0, TXFTH1, TXFPH0, TXFPH1, TXFSTA, TXFSTO, CHKCDN};
};

bool PnlBrlySegDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlySegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlySegDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDph", TxfDph)) add(TXFDPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAl0", TxfAl0)) add(TXFAL0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAl1", TxfAl1)) add(TXFAL1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTh0", TxfTh0)) add(TXFTH0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTh1", TxfTh1)) add(TXFTH1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPh0", TxfPh0)) add(TXFPH0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPh1", TxfPh1)) add(TXFPH1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCdn", ChkCdn)) add(CHKCDN);
	};

	return basefound;
};

void PnlBrlySegDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlySegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlySegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeStringAttr(wr, itemtag, "sref", "TxfDph", TxfDph);
		writeStringAttr(wr, itemtag, "sref", "TxfAl0", TxfAl0);
		writeStringAttr(wr, itemtag, "sref", "TxfAl1", TxfAl1);
		writeStringAttr(wr, itemtag, "sref", "TxfTh0", TxfTh0);
		writeStringAttr(wr, itemtag, "sref", "TxfTh1", TxfTh1);
		writeStringAttr(wr, itemtag, "sref", "TxfPh0", TxfPh0);
		writeStringAttr(wr, itemtag, "sref", "TxfPh1", TxfPh1);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeBoolAttr(wr, itemtag, "sref", "ChkCdn", ChkCdn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (TxfDph.compare(comp->TxfDph) == 0) insert(items, TXFDPH);
	if (TxfAl0.compare(comp->TxfAl0) == 0) insert(items, TXFAL0);
	if (TxfAl1.compare(comp->TxfAl1) == 0) insert(items, TXFAL1);
	if (TxfTh0.compare(comp->TxfTh0) == 0) insert(items, TXFTH0);
	if (TxfTh1.compare(comp->TxfTh1) == 0) insert(items, TXFTH1);
	if (TxfPh0.compare(comp->TxfPh0) == 0) insert(items, TXFPH0);
	if (TxfPh1.compare(comp->TxfPh1) == 0) insert(items, TXFPH1);
	if (TxfSta.compare(comp->TxfSta) == 0) insert(items, TXFSTA);
	if (TxfSto.compare(comp->TxfSto) == 0) insert(items, TXFSTO);
	if (ChkCdn == comp->ChkCdn) insert(items, CHKCDN);

	return(items);
};

set<uint> PnlBrlySegDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPRET, TXFDPH, TXFAL0, TXFAL1, TXFTH0, TXFTH1, TXFPH0, TXFPH1, TXFSTA, TXFSTO, CHKCDN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegDetail::ContInf
 ******************************************************************************/

PnlBrlySegDetail::ContInf::ContInf(
			const string& TxtReu
		) : Block() {
	this->TxtReu = TxtReu;

	mask = {TXTREU};
};

bool PnlBrlySegDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlySegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlySegDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReu", TxtReu)) add(TXTREU);
	};

	return basefound;
};

set<uint> PnlBrlySegDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtReu.compare(comp->TxtReu) == 0) insert(items, TXTREU);

	return(items);
};

set<uint> PnlBrlySegDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegDetail::StatApp
 ******************************************************************************/

PnlBrlySegDetail::StatApp::StatApp(
			const uint ixBrlyVExpstate
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;

	mask = {IXBRLYVEXPSTATE};
};

bool PnlBrlySegDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlySegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlySegDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlBrlySegDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);

	return(items);
};

set<uint> PnlBrlySegDetail::StatApp::diff(
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
 class PnlBrlySegDetail::StatShr
 ******************************************************************************/

PnlBrlySegDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool TxfDphActive
			, const bool TxfAl0Active
			, const bool TxfAl1Active
			, const bool TxfTh0Active
			, const bool TxfTh1Active
			, const bool TxfPh0Active
			, const bool TxfPh1Active
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool ChkCdnActive
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->TxfDphActive = TxfDphActive;
	this->TxfAl0Active = TxfAl0Active;
	this->TxfAl1Active = TxfAl1Active;
	this->TxfTh0Active = TxfTh0Active;
	this->TxfTh1Active = TxfTh1Active;
	this->TxfPh0Active = TxfPh0Active;
	this->TxfPh1Active = TxfPh1Active;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->ChkCdnActive = ChkCdnActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXFDPHACTIVE, TXFAL0ACTIVE, TXFAL1ACTIVE, TXFTH0ACTIVE, TXFTH1ACTIVE, TXFPH0ACTIVE, TXFPH1ACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, CHKCDNACTIVE};
};

bool PnlBrlySegDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlySegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlySegDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtReuActive", TxtReuActive)) add(TXTREUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", ButReuViewAvail)) add(BUTREUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewActive", ButReuViewActive)) add(BUTREUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDphActive", TxfDphActive)) add(TXFDPHACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAl0Active", TxfAl0Active)) add(TXFAL0ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAl1Active", TxfAl1Active)) add(TXFAL1ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTh0Active", TxfTh0Active)) add(TXFTH0ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTh1Active", TxfTh1Active)) add(TXFTH1ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPh0Active", TxfPh0Active)) add(TXFPH0ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPh1Active", TxfPh1Active)) add(TXFPH1ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStoActive", TxfStoActive)) add(TXFSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkCdnActive", ChkCdnActive)) add(CHKCDNACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlySegDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (TxfDphActive == comp->TxfDphActive) insert(items, TXFDPHACTIVE);
	if (TxfAl0Active == comp->TxfAl0Active) insert(items, TXFAL0ACTIVE);
	if (TxfAl1Active == comp->TxfAl1Active) insert(items, TXFAL1ACTIVE);
	if (TxfTh0Active == comp->TxfTh0Active) insert(items, TXFTH0ACTIVE);
	if (TxfTh1Active == comp->TxfTh1Active) insert(items, TXFTH1ACTIVE);
	if (TxfPh0Active == comp->TxfPh0Active) insert(items, TXFPH0ACTIVE);
	if (TxfPh1Active == comp->TxfPh1Active) insert(items, TXFPH1ACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (ChkCdnActive == comp->ChkCdnActive) insert(items, CHKCDNACTIVE);

	return(items);
};

set<uint> PnlBrlySegDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXFDPHACTIVE, TXFAL0ACTIVE, TXFAL1ACTIVE, TXFTH0ACTIVE, TXFTH1ACTIVE, TXFPH0ACTIVE, TXFPH1ACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, CHKCDNACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegDetail::Tag
 ******************************************************************************/

PnlBrlySegDetail::Tag::Tag(
			const string& Cpt
			, const string& CptReu
			, const string& CptDph
			, const string& CptAl0
			, const string& CptAl1
			, const string& CptTh0
			, const string& CptTh1
			, const string& CptPh0
			, const string& CptPh1
			, const string& CptSta
			, const string& CptSto
			, const string& CptCdn
		) : Block() {
	this->Cpt = Cpt;
	this->CptReu = CptReu;
	this->CptDph = CptDph;
	this->CptAl0 = CptAl0;
	this->CptAl1 = CptAl1;
	this->CptTh0 = CptTh0;
	this->CptTh1 = CptTh1;
	this->CptPh0 = CptPh0;
	this->CptPh1 = CptPh1;
	this->CptSta = CptSta;
	this->CptSto = CptSto;
	this->CptCdn = CptCdn;

	mask = {CPT, CPTREU, CPTDPH, CPTAL0, CPTAL1, CPTTH0, CPTTH1, CPTPH0, CPTPH1, CPTSTA, CPTSTO, CPTCDN};
};

bool PnlBrlySegDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlySegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlySegDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReu", CptReu)) add(CPTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDph", CptDph)) add(CPTDPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAl0", CptAl0)) add(CPTAL0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAl1", CptAl1)) add(CPTAL1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTh0", CptTh0)) add(CPTTH0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTh1", CptTh1)) add(CPTTH1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPh0", CptPh0)) add(CPTPH0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPh1", CptPh1)) add(CPTPH1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSto", CptSto)) add(CPTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCdn", CptCdn)) add(CPTCDN);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlySegDetail::DpchAppData
 ******************************************************************************/

PnlBrlySegDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYSEGDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlySegDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlySegDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlySegDetail::DpchAppDo
 ******************************************************************************/

PnlBrlySegDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYSEGDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlySegDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlySegDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlySegDetail::DpchEngData
 ******************************************************************************/

PnlBrlySegDetail::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYSEGDETAILDATA) {
	feedFPupRet.tag = "FeedFPupRet";
};

string PnlBrlySegDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlySegDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupRet.readXML(docctx, basexpath, true)) add(FEEDFPUPRET);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupRet.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

