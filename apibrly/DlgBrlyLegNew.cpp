/**
  * \file DlgBrlyLegNew.cpp
  * API code for job DlgBrlyLegNew (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "DlgBrlyLegNew.h"

/******************************************************************************
 class DlgBrlyLegNew::VecVDit
 ******************************************************************************/

uint DlgBrlyLegNew::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	else if (s == "inc") return INC;

	return(0);
};

string DlgBrlyLegNew::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	else if (ix == INC) return("Inc");

	return("");
};

/******************************************************************************
 class DlgBrlyLegNew::VecVDo
 ******************************************************************************/

uint DlgBrlyLegNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgBrlyLegNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgBrlyLegNew::VecVDoDet
 ******************************************************************************/

uint DlgBrlyLegNew::VecVDoDet::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgBrlyLegNew::VecVDoDet::getSref(
			const uint ix
		) {
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgBrlyLegNew::VecVDoInc
 ******************************************************************************/

uint DlgBrlyLegNew::VecVDoInc::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	else if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgBrlyLegNew::VecVDoInc::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	else if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgBrlyLegNew::VecVSge
 ******************************************************************************/

uint DlgBrlyLegNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "create") return CREATE;
	else if (s == "credone") return CREDONE;
	else if (s == "inco") return INCO;
	else if (s == "done") return DONE;

	return(0);
};

string DlgBrlyLegNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == CREATE) return("create");
	else if (ix == CREDONE) return("credone");
	else if (ix == INCO) return("inco");
	else if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgBrlyLegNew::ContIac
 ******************************************************************************/

DlgBrlyLegNew::ContIac::ContIac(
			const uint numFDse
		) : Block() {
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgBrlyLegNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyLegNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyLegNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgBrlyLegNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyLegNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyLegNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyLegNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgBrlyLegNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDSE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::ContIacDet
 ******************************************************************************/

DlgBrlyLegNew::ContIacDet::ContIacDet(
			const uint numFPupTyp
			, const string& TxfBgn
			, const string& TxfEnd
		) : Block() {
	this->numFPupTyp = numFPupTyp;
	this->TxfBgn = TxfBgn;
	this->TxfEnd = TxfEnd;

	mask = {NUMFPUPTYP, TXFBGN, TXFEND};
};

bool DlgBrlyLegNew::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyLegNewDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyLegNewDet";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfBgn", TxfBgn)) add(TXFBGN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEnd", TxfEnd)) add(TXFEND);
	};

	return basefound;
};

void DlgBrlyLegNew::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyLegNewDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyLegNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfBgn", TxfBgn);
		writeStringAttr(wr, itemtag, "sref", "TxfEnd", TxfEnd);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyLegNew::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfBgn.compare(comp->TxfBgn) == 0) insert(items, TXFBGN);
	if (TxfEnd.compare(comp->TxfEnd) == 0) insert(items, TXFEND);

	return(items);
};

set<uint> DlgBrlyLegNew::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, TXFBGN, TXFEND};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::ContInf
 ******************************************************************************/

DlgBrlyLegNew::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgBrlyLegNew::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgBrlyLegNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgBrlyLegNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgBrlyLegNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgBrlyLegNew::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::ContInfInc
 ******************************************************************************/

DlgBrlyLegNew::ContInfInc::ContInfInc(
			const string& TxtPrg
		) : Block() {
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgBrlyLegNew::ContInfInc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgBrlyLegNewInc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgBrlyLegNewInc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgBrlyLegNew::ContInfInc::comm(
			const ContInfInc* comp
		) {
	set<uint> items;

	if (TxtPrg.compare(comp->TxtPrg) == 0) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgBrlyLegNew::ContInfInc::diff(
			const ContInfInc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::StatApp
 ******************************************************************************/

DlgBrlyLegNew::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) : Block() {
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgBrlyLegNew::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgBrlyLegNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgBrlyLegNew";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgBrlyLegNew::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgBrlyLegNew::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONE, SHORTMENU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::StatShr
 ******************************************************************************/

DlgBrlyLegNew::StatShr::StatShr(
			const bool ButDneActive
		) : Block() {
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgBrlyLegNew::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgBrlyLegNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgBrlyLegNew";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgBrlyLegNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgBrlyLegNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDNEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::StatShrDet
 ******************************************************************************/

DlgBrlyLegNew::StatShrDet::StatShrDet(
			const bool ButCreActive
		) : Block() {
	this->ButCreActive = ButCreActive;

	mask = {BUTCREACTIVE};
};

bool DlgBrlyLegNew::StatShrDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgBrlyLegNewDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgBrlyLegNewDet";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCreActive", ButCreActive)) add(BUTCREACTIVE);
	};

	return basefound;
};

set<uint> DlgBrlyLegNew::StatShrDet::comm(
			const StatShrDet* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgBrlyLegNew::StatShrDet::diff(
			const StatShrDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCREACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::StatShrInc
 ******************************************************************************/

DlgBrlyLegNew::StatShrInc::StatShrInc(
			const bool ButRunActive
			, const bool ButStoActive
		) : Block() {
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgBrlyLegNew::StatShrInc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgBrlyLegNewInc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgBrlyLegNewInc";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgBrlyLegNew::StatShrInc::comm(
			const StatShrInc* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgBrlyLegNew::StatShrInc::diff(
			const StatShrInc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::Tag
 ******************************************************************************/

DlgBrlyLegNew::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) : Block() {
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgBrlyLegNew::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyLegNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyLegNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyLegNew::TagDet
 ******************************************************************************/

DlgBrlyLegNew::TagDet::TagDet(
			const string& CptTyp
			, const string& CptBgn
			, const string& CptEnd
			, const string& ButCre
		) : Block() {
	this->CptTyp = CptTyp;
	this->CptBgn = CptBgn;
	this->CptEnd = CptEnd;
	this->ButCre = ButCre;

	mask = {CPTTYP, CPTBGN, CPTEND, BUTCRE};
};

bool DlgBrlyLegNew::TagDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyLegNewDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyLegNewDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBgn", CptBgn)) add(CPTBGN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEnd", CptEnd)) add(CPTEND);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCre", ButCre)) add(BUTCRE);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyLegNew::TagInc
 ******************************************************************************/

DlgBrlyLegNew::TagInc::TagInc(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) : Block() {
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgBrlyLegNew::TagInc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyLegNewInc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyLegNewInc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyLegNew::DpchAppData
 ******************************************************************************/

DlgBrlyLegNew::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYLEGNEWDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, CONTIACDET};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
};

string DlgBrlyLegNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyLegNew::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgBrlyLegNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyLegNew::DpchAppDo
 ******************************************************************************/

DlgBrlyLegNew::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoDet
			, const uint ixVDoInc
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYLEGNEWDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDODET, IXVDOINC};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoDet = ixVDoDet;
	this->ixVDoInc = ixVDoInc;
};

string DlgBrlyLegNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDODET)) ss.push_back("ixVDoDet");
	if (has(IXVDOINC)) ss.push_back("ixVDoInc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyLegNew::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgBrlyLegNewDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDODET)) writeString(wr, "srefIxVDoDet", VecVDoDet::getSref(ixVDoDet));
		if (has(IXVDOINC)) writeString(wr, "srefIxVDoInc", VecVDoInc::getSref(ixVDoInc));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyLegNew::DpchEngData
 ******************************************************************************/

DlgBrlyLegNew::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGDLGBRLYLEGNEWDATA) {
	feedFDetPupTyp.tag = "FeedFDetPupTyp";
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgBrlyLegNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFINC)) ss.push_back("continfinc");
	if (has(FEEDFDETPUPTYP)) ss.push_back("feedFDetPupTyp");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRDET)) ss.push_back("statshrdet");
	if (has(STATSHRINC)) ss.push_back("statshrinc");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGDET)) ss.push_back("tagdet");
	if (has(TAGINC)) ss.push_back("taginc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyLegNew::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgBrlyLegNewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfinc.readXML(docctx, basexpath, true)) add(CONTINFINC);
		if (feedFDetPupTyp.readXML(docctx, basexpath, true)) add(FEEDFDETPUPTYP);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrdet.readXML(docctx, basexpath, true)) add(STATSHRDET);
		if (statshrinc.readXML(docctx, basexpath, true)) add(STATSHRINC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagdet.readXML(docctx, basexpath, true)) add(TAGDET);
		if (taginc.readXML(docctx, basexpath, true)) add(TAGINC);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
		continf = ContInf();
		continfinc = ContInfInc();
		feedFDetPupTyp.clear();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrdet = StatShrDet();
		statshrinc = StatShrInc();
		tag = Tag();
		tagdet = TagDet();
		taginc = TagInc();
	};
};

