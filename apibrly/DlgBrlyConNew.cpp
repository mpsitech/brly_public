/**
  * \file DlgBrlyConNew.cpp
  * API code for job DlgBrlyConNew (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "DlgBrlyConNew.h"

/******************************************************************************
 class DlgBrlyConNew::VecVDit
 ******************************************************************************/

uint DlgBrlyConNew::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	else if (s == "cal") return CAL;

	return(0);
};

string DlgBrlyConNew::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	else if (ix == CAL) return("Cal");

	return("");
};

/******************************************************************************
 class DlgBrlyConNew::VecVDo
 ******************************************************************************/

uint DlgBrlyConNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgBrlyConNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgBrlyConNew::VecVDoCal
 ******************************************************************************/

uint DlgBrlyConNew::VecVDoCal::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	else if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgBrlyConNew::VecVDoCal::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	else if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgBrlyConNew::VecVDoDet
 ******************************************************************************/

uint DlgBrlyConNew::VecVDoDet::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgBrlyConNew::VecVDoDet::getSref(
			const uint ix
		) {
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgBrlyConNew::VecVSge
 ******************************************************************************/

uint DlgBrlyConNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "create") return CREATE;
	else if (s == "credone") return CREDONE;
	else if (s == "calc1") return CALC1;
	else if (s == "calc2") return CALC2;
	else if (s == "calc3") return CALC3;
	else if (s == "calc4") return CALC4;
	else if (s == "done") return DONE;

	return(0);
};

string DlgBrlyConNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == CREATE) return("create");
	else if (ix == CREDONE) return("credone");
	else if (ix == CALC1) return("calc1");
	else if (ix == CALC2) return("calc2");
	else if (ix == CALC3) return("calc3");
	else if (ix == CALC4) return("calc4");
	else if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgBrlyConNew::ContIac
 ******************************************************************************/

DlgBrlyConNew::ContIac::ContIac(
			const uint numFDse
		) : Block() {
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgBrlyConNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyConNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyConNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgBrlyConNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyConNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyConNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyConNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgBrlyConNew::ContIac::diff(
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
 class DlgBrlyConNew::ContIacDet
 ******************************************************************************/

DlgBrlyConNew::ContIacDet::ContIacDet(
			const string& TxfFlt
			, const uint numFPupMdl
			, const uint numFPupTtb
			, const string& TxfEty
		) : Block() {
	this->TxfFlt = TxfFlt;
	this->numFPupMdl = numFPupMdl;
	this->numFPupTtb = numFPupTtb;
	this->TxfEty = TxfEty;

	mask = {TXFFLT, NUMFPUPMDL, NUMFPUPTTB, TXFETY};
};

bool DlgBrlyConNew::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyConNewDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyConNewDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFlt", TxfFlt)) add(TXFFLT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMdl", numFPupMdl)) add(NUMFPUPMDL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTtb", numFPupTtb)) add(NUMFPUPTTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEty", TxfEty)) add(TXFETY);
	};

	return basefound;
};

void DlgBrlyConNew::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyConNewDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyConNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFlt", TxfFlt);
		writeUintAttr(wr, itemtag, "sref", "numFPupMdl", numFPupMdl);
		writeUintAttr(wr, itemtag, "sref", "numFPupTtb", numFPupTtb);
		writeStringAttr(wr, itemtag, "sref", "TxfEty", TxfEty);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyConNew::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (TxfFlt.compare(comp->TxfFlt) == 0) insert(items, TXFFLT);
	if (numFPupMdl == comp->numFPupMdl) insert(items, NUMFPUPMDL);
	if (numFPupTtb == comp->numFPupTtb) insert(items, NUMFPUPTTB);
	if (TxfEty.compare(comp->TxfEty) == 0) insert(items, TXFETY);

	return(items);
};

set<uint> DlgBrlyConNew::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFLT, NUMFPUPMDL, NUMFPUPTTB, TXFETY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyConNew::ContInf
 ******************************************************************************/

DlgBrlyConNew::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgBrlyConNew::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgBrlyConNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgBrlyConNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgBrlyConNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgBrlyConNew::ContInf::diff(
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
 class DlgBrlyConNew::ContInfCal
 ******************************************************************************/

DlgBrlyConNew::ContInfCal::ContInfCal(
			const string& TxtPrg
		) : Block() {
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgBrlyConNew::ContInfCal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgBrlyConNewCal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgBrlyConNewCal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgBrlyConNew::ContInfCal::comm(
			const ContInfCal* comp
		) {
	set<uint> items;

	if (TxtPrg.compare(comp->TxtPrg) == 0) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgBrlyConNew::ContInfCal::diff(
			const ContInfCal* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyConNew::StatApp
 ******************************************************************************/

DlgBrlyConNew::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) : Block() {
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgBrlyConNew::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgBrlyConNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgBrlyConNew";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgBrlyConNew::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgBrlyConNew::StatApp::diff(
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
 class DlgBrlyConNew::StatShr
 ******************************************************************************/

DlgBrlyConNew::StatShr::StatShr(
			const bool ButDneActive
		) : Block() {
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgBrlyConNew::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgBrlyConNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgBrlyConNew";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgBrlyConNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgBrlyConNew::StatShr::diff(
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
 class DlgBrlyConNew::StatShrCal
 ******************************************************************************/

DlgBrlyConNew::StatShrCal::StatShrCal(
			const bool ButRunActive
			, const bool ButStoActive
		) : Block() {
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgBrlyConNew::StatShrCal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgBrlyConNewCal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgBrlyConNewCal";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgBrlyConNew::StatShrCal::comm(
			const StatShrCal* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgBrlyConNew::StatShrCal::diff(
			const StatShrCal* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyConNew::StatShrDet
 ******************************************************************************/

DlgBrlyConNew::StatShrDet::StatShrDet(
			const bool ButCreActive
		) : Block() {
	this->ButCreActive = ButCreActive;

	mask = {BUTCREACTIVE};
};

bool DlgBrlyConNew::StatShrDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgBrlyConNewDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgBrlyConNewDet";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCreActive", ButCreActive)) add(BUTCREACTIVE);
	};

	return basefound;
};

set<uint> DlgBrlyConNew::StatShrDet::comm(
			const StatShrDet* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgBrlyConNew::StatShrDet::diff(
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
 class DlgBrlyConNew::Tag
 ******************************************************************************/

DlgBrlyConNew::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) : Block() {
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgBrlyConNew::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyConNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyConNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyConNew::TagCal
 ******************************************************************************/

DlgBrlyConNew::TagCal::TagCal(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) : Block() {
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgBrlyConNew::TagCal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyConNewCal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyConNewCal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyConNew::TagDet
 ******************************************************************************/

DlgBrlyConNew::TagDet::TagDet(
			const string& CptFlt
			, const string& CptMdl
			, const string& CptTtb
			, const string& CptEty
			, const string& ButCre
		) : Block() {
	this->CptFlt = CptFlt;
	this->CptMdl = CptMdl;
	this->CptTtb = CptTtb;
	this->CptEty = CptEty;
	this->ButCre = ButCre;

	mask = {CPTFLT, CPTMDL, CPTTTB, CPTETY, BUTCRE};
};

bool DlgBrlyConNew::TagDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyConNewDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyConNewDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFlt", CptFlt)) add(CPTFLT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMdl", CptMdl)) add(CPTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTtb", CptTtb)) add(CPTTTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEty", CptEty)) add(CPTETY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCre", ButCre)) add(BUTCRE);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyConNew::DpchAppData
 ******************************************************************************/

DlgBrlyConNew::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYCONNEWDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, CONTIACDET};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
};

string DlgBrlyConNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyConNew::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgBrlyConNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyConNew::DpchAppDo
 ******************************************************************************/

DlgBrlyConNew::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoCal
			, const uint ixVDoDet
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYCONNEWDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOCAL, IXVDODET};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoCal = ixVDoCal;
	this->ixVDoDet = ixVDoDet;
};

string DlgBrlyConNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOCAL)) ss.push_back("ixVDoCal");
	if (has(IXVDODET)) ss.push_back("ixVDoDet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyConNew::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgBrlyConNewDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOCAL)) writeString(wr, "srefIxVDoCal", VecVDoCal::getSref(ixVDoCal));
		if (has(IXVDODET)) writeString(wr, "srefIxVDoDet", VecVDoDet::getSref(ixVDoDet));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyConNew::DpchEngData
 ******************************************************************************/

DlgBrlyConNew::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGDLGBRLYCONNEWDATA) {
	feedFDetPupMdl.tag = "FeedFDetPupMdl";
	feedFDetPupTtb.tag = "FeedFDetPupTtb";
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgBrlyConNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFCAL)) ss.push_back("continfcal");
	if (has(FEEDFDETPUPMDL)) ss.push_back("feedFDetPupMdl");
	if (has(FEEDFDETPUPTTB)) ss.push_back("feedFDetPupTtb");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRCAL)) ss.push_back("statshrcal");
	if (has(STATSHRDET)) ss.push_back("statshrdet");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGCAL)) ss.push_back("tagcal");
	if (has(TAGDET)) ss.push_back("tagdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyConNew::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgBrlyConNewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfcal.readXML(docctx, basexpath, true)) add(CONTINFCAL);
		if (feedFDetPupMdl.readXML(docctx, basexpath, true)) add(FEEDFDETPUPMDL);
		if (feedFDetPupTtb.readXML(docctx, basexpath, true)) add(FEEDFDETPUPTTB);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrcal.readXML(docctx, basexpath, true)) add(STATSHRCAL);
		if (statshrdet.readXML(docctx, basexpath, true)) add(STATSHRDET);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagcal.readXML(docctx, basexpath, true)) add(TAGCAL);
		if (tagdet.readXML(docctx, basexpath, true)) add(TAGDET);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
		continf = ContInf();
		continfcal = ContInfCal();
		feedFDetPupMdl.clear();
		feedFDetPupTtb.clear();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrcal = StatShrCal();
		statshrdet = StatShrDet();
		tag = Tag();
		tagcal = TagCal();
		tagdet = TagDet();
	};
};

