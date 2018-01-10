/**
  * \file PnlBrlyLegDetail.cpp
  * API code for job PnlBrlyLegDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyLegDetail.h"

/******************************************************************************
 class PnlBrlyLegDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyLegDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	else if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	else if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;

	return(0);
};

string PnlBrlyLegDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	else if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	else if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLegDetail::ContIac
 ******************************************************************************/

PnlBrlyLegDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFLstClu
			, const string& TxfAlt
			, const string& TxfDph
			, const string& TxfAph
			, const string& TxfXal
			, const string& TxfXp0
			, const string& TxfXp1
			, const string& TxfXap
			, const bool ChkCdn
		) : Block() {
	this->numFPupTyp = numFPupTyp;
	this->numFLstClu = numFLstClu;
	this->TxfAlt = TxfAlt;
	this->TxfDph = TxfDph;
	this->TxfAph = TxfAph;
	this->TxfXal = TxfXal;
	this->TxfXp0 = TxfXp0;
	this->TxfXp1 = TxfXp1;
	this->TxfXap = TxfXap;
	this->ChkCdn = ChkCdn;

	mask = {NUMFPUPTYP, NUMFLSTCLU, TXFALT, TXFDPH, TXFAPH, TXFXAL, TXFXP0, TXFXP1, TXFXAP, CHKCDN};
};

bool PnlBrlyLegDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyLegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyLegDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAlt", TxfAlt)) add(TXFALT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDph", TxfDph)) add(TXFDPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAph", TxfAph)) add(TXFAPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXal", TxfXal)) add(TXFXAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXp0", TxfXp0)) add(TXFXP0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXp1", TxfXp1)) add(TXFXP1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXap", TxfXap)) add(TXFXAP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCdn", ChkCdn)) add(CHKCDN);
	};

	return basefound;
};

void PnlBrlyLegDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyLegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyLegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeStringAttr(wr, itemtag, "sref", "TxfAlt", TxfAlt);
		writeStringAttr(wr, itemtag, "sref", "TxfDph", TxfDph);
		writeStringAttr(wr, itemtag, "sref", "TxfAph", TxfAph);
		writeStringAttr(wr, itemtag, "sref", "TxfXal", TxfXal);
		writeStringAttr(wr, itemtag, "sref", "TxfXp0", TxfXp0);
		writeStringAttr(wr, itemtag, "sref", "TxfXp1", TxfXp1);
		writeStringAttr(wr, itemtag, "sref", "TxfXap", TxfXap);
		writeBoolAttr(wr, itemtag, "sref", "ChkCdn", ChkCdn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (TxfAlt.compare(comp->TxfAlt) == 0) insert(items, TXFALT);
	if (TxfDph.compare(comp->TxfDph) == 0) insert(items, TXFDPH);
	if (TxfAph.compare(comp->TxfAph) == 0) insert(items, TXFAPH);
	if (TxfXal.compare(comp->TxfXal) == 0) insert(items, TXFXAL);
	if (TxfXp0.compare(comp->TxfXp0) == 0) insert(items, TXFXP0);
	if (TxfXp1.compare(comp->TxfXp1) == 0) insert(items, TXFXP1);
	if (TxfXap.compare(comp->TxfXap) == 0) insert(items, TXFXAP);
	if (ChkCdn == comp->ChkCdn) insert(items, CHKCDN);

	return(items);
};

set<uint> PnlBrlyLegDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFLSTCLU, TXFALT, TXFDPH, TXFAPH, TXFXAL, TXFXP0, TXFXP1, TXFXAP, CHKCDN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegDetail::ContInf
 ******************************************************************************/

PnlBrlyLegDetail::ContInf::ContInf(
			const string& TxtBlo
			, const string& TxtElo
			, const string& TxtClu
		) : Block() {
	this->TxtBlo = TxtBlo;
	this->TxtElo = TxtElo;
	this->TxtClu = TxtClu;

	mask = {TXTBLO, TXTELO, TXTCLU};
};

bool PnlBrlyLegDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyLegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyLegDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtBlo", TxtBlo)) add(TXTBLO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtElo", TxtElo)) add(TXTELO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
	};

	return basefound;
};

set<uint> PnlBrlyLegDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtBlo.compare(comp->TxtBlo) == 0) insert(items, TXTBLO);
	if (TxtElo.compare(comp->TxtElo) == 0) insert(items, TXTELO);
	if (TxtClu.compare(comp->TxtClu) == 0) insert(items, TXTCLU);

	return(items);
};

set<uint> PnlBrlyLegDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTBLO, TXTELO, TXTCLU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegDetail::StatApp
 ******************************************************************************/

PnlBrlyLegDetail::StatApp::StatApp(
			const uint ixBrlyVExpstate
			, const bool LstCluAlt
			, const uint LstCluNumFirstdisp
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->LstCluAlt = LstCluAlt;
	this->LstCluNumFirstdisp = LstCluNumFirstdisp;

	mask = {IXBRLYVEXPSTATE, LSTCLUALT, LSTCLUNUMFIRSTDISP};
};

bool PnlBrlyLegDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyLegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyLegDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluAlt", LstCluAlt)) add(LSTCLUALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp)) add(LSTCLUNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlBrlyLegDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);

	return(items);
};

set<uint> PnlBrlyLegDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, LSTCLUALT, LSTCLUNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegDetail::StatShr
 ******************************************************************************/

PnlBrlyLegDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtBloActive
			, const bool TxtEloActive
			, const bool PupTypActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxfAltActive
			, const bool TxfDphActive
			, const bool TxfAphActive
			, const bool TxfXalActive
			, const bool TxfXp0Active
			, const bool TxfXp1Active
			, const bool TxfXapActive
			, const bool ChkCdnActive
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtBloActive = TxtBloActive;
	this->TxtEloActive = TxtEloActive;
	this->PupTypActive = PupTypActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxfAltActive = TxfAltActive;
	this->TxfDphActive = TxfDphActive;
	this->TxfAphActive = TxfAphActive;
	this->TxfXalActive = TxfXalActive;
	this->TxfXp0Active = TxfXp0Active;
	this->TxfXp1Active = TxfXp1Active;
	this->TxfXapActive = TxfXapActive;
	this->ChkCdnActive = ChkCdnActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTBLOACTIVE, TXTELOACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXFALTACTIVE, TXFDPHACTIVE, TXFAPHACTIVE, TXFXALACTIVE, TXFXP0ACTIVE, TXFXP1ACTIVE, TXFXAPACTIVE, CHKCDNACTIVE};
};

bool PnlBrlyLegDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyLegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyLegDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtBloActive", TxtBloActive)) add(TXTBLOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEloActive", TxtEloActive)) add(TXTELOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluActive", LstCluActive)) add(LSTCLUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluViewActive", ButCluViewActive)) add(BUTCLUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", ButCluClusterAvail)) add(BUTCLUCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail)) add(BUTCLUUNCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAltActive", TxfAltActive)) add(TXFALTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDphActive", TxfDphActive)) add(TXFDPHACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAphActive", TxfAphActive)) add(TXFAPHACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfXalActive", TxfXalActive)) add(TXFXALACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfXp0Active", TxfXp0Active)) add(TXFXP0ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfXp1Active", TxfXp1Active)) add(TXFXP1ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfXapActive", TxfXapActive)) add(TXFXAPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkCdnActive", ChkCdnActive)) add(CHKCDNACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyLegDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtBloActive == comp->TxtBloActive) insert(items, TXTBLOACTIVE);
	if (TxtEloActive == comp->TxtEloActive) insert(items, TXTELOACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxfAltActive == comp->TxfAltActive) insert(items, TXFALTACTIVE);
	if (TxfDphActive == comp->TxfDphActive) insert(items, TXFDPHACTIVE);
	if (TxfAphActive == comp->TxfAphActive) insert(items, TXFAPHACTIVE);
	if (TxfXalActive == comp->TxfXalActive) insert(items, TXFXALACTIVE);
	if (TxfXp0Active == comp->TxfXp0Active) insert(items, TXFXP0ACTIVE);
	if (TxfXp1Active == comp->TxfXp1Active) insert(items, TXFXP1ACTIVE);
	if (TxfXapActive == comp->TxfXapActive) insert(items, TXFXAPACTIVE);
	if (ChkCdnActive == comp->ChkCdnActive) insert(items, CHKCDNACTIVE);

	return(items);
};

set<uint> PnlBrlyLegDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTBLOACTIVE, TXTELOACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXFALTACTIVE, TXFDPHACTIVE, TXFAPHACTIVE, TXFXALACTIVE, TXFXP0ACTIVE, TXFXP1ACTIVE, TXFXAPACTIVE, CHKCDNACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegDetail::Tag
 ******************************************************************************/

PnlBrlyLegDetail::Tag::Tag(
			const string& Cpt
			, const string& CptBlo
			, const string& CptElo
			, const string& CptTyp
			, const string& CptClu
			, const string& CptAlt
			, const string& CptDph
			, const string& CptAph
			, const string& CptXal
			, const string& CptXp0
			, const string& CptXp1
			, const string& CptXap
			, const string& CptCdn
		) : Block() {
	this->Cpt = Cpt;
	this->CptBlo = CptBlo;
	this->CptElo = CptElo;
	this->CptTyp = CptTyp;
	this->CptClu = CptClu;
	this->CptAlt = CptAlt;
	this->CptDph = CptDph;
	this->CptAph = CptAph;
	this->CptXal = CptXal;
	this->CptXp0 = CptXp0;
	this->CptXp1 = CptXp1;
	this->CptXap = CptXap;
	this->CptCdn = CptCdn;

	mask = {CPT, CPTBLO, CPTELO, CPTTYP, CPTCLU, CPTALT, CPTDPH, CPTAPH, CPTXAL, CPTXP0, CPTXP1, CPTXAP, CPTCDN};
};

bool PnlBrlyLegDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyLegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyLegDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBlo", CptBlo)) add(CPTBLO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptElo", CptElo)) add(CPTELO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAlt", CptAlt)) add(CPTALT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDph", CptDph)) add(CPTDPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAph", CptAph)) add(CPTAPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptXal", CptXal)) add(CPTXAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptXp0", CptXp0)) add(CPTXP0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptXp1", CptXp1)) add(CPTXP1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptXap", CptXap)) add(CPTXAP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCdn", CptCdn)) add(CPTCDN);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyLegDetail::DpchAppData
 ******************************************************************************/

PnlBrlyLegDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlyLegDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLegDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyLegDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyLegDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLegDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegDetail::DpchEngData
 ******************************************************************************/

PnlBrlyLegDetail::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGDETAILDATA) {
	feedFLstClu.tag = "FeedFLstClu";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlBrlyLegDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLegDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstClu.readXML(docctx, basexpath, true)) add(FEEDFLSTCLU);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstClu.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

