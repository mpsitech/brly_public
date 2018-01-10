/**
  * \file DlgBrlyTtbTrlorig.cpp
  * API code for job DlgBrlyTtbTrlorig (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "DlgBrlyTtbTrlorig.h"

/******************************************************************************
 class DlgBrlyTtbTrlorig::VecVDit
 ******************************************************************************/

uint DlgBrlyTtbTrlorig::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	else if (s == "rfi") return RFI;
	else if (s == "trl") return TRL;
	else if (s == "tfi") return TFI;

	return(0);
};

string DlgBrlyTtbTrlorig::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	else if (ix == RFI) return("Rfi");
	else if (ix == TRL) return("Trl");
	else if (ix == TFI) return("Tfi");

	return("");
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::VecVDo
 ******************************************************************************/

uint DlgBrlyTtbTrlorig::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgBrlyTtbTrlorig::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::VecVDoTrl
 ******************************************************************************/

uint DlgBrlyTtbTrlorig::VecVDoTrl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	else if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgBrlyTtbTrlorig::VecVDoTrl::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	else if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::VecVSge
 ******************************************************************************/

uint DlgBrlyTtbTrlorig::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "ulddone") return ULDDONE;
	else if (s == "translate") return TRANSLATE;
	else if (s == "done") return DONE;

	return(0);
};

string DlgBrlyTtbTrlorig::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ULDDONE) return("ulddone");
	else if (ix == TRANSLATE) return("translate");
	else if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::VecVSrc
 ******************************************************************************/

uint DlgBrlyTtbTrlorig::VecVSrc::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "star") return STAR;
	else if (s == "ow") return OW;

	return(0);
};

string DlgBrlyTtbTrlorig::VecVSrc::getSref(
			const uint ix
		) {
	if (ix == STAR) return("star");
	else if (ix == OW) return("ow");

	return("");
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::ContIac
 ******************************************************************************/

DlgBrlyTtbTrlorig::ContIac::ContIac(
			const uint numFDse
		) : Block() {
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgBrlyTtbTrlorig::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyTtbTrlorig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyTtbTrlorig";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgBrlyTtbTrlorig::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyTtbTrlorig";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyTtbTrlorig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyTtbTrlorig::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgBrlyTtbTrlorig::ContIac::diff(
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
 class DlgBrlyTtbTrlorig::ContIacDet
 ******************************************************************************/

DlgBrlyTtbTrlorig::ContIacDet::ContIacDet(
			const uint numFPupSrc
		) : Block() {
	this->numFPupSrc = numFPupSrc;

	mask = {NUMFPUPSRC};
};

bool DlgBrlyTtbTrlorig::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyTtbTrlorigDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyTtbTrlorigDet";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSrc", numFPupSrc)) add(NUMFPUPSRC);
	};

	return basefound;
};

void DlgBrlyTtbTrlorig::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyTtbTrlorigDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyTtbTrlorigDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupSrc", numFPupSrc);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyTtbTrlorig::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (numFPupSrc == comp->numFPupSrc) insert(items, NUMFPUPSRC);

	return(items);
};

set<uint> DlgBrlyTtbTrlorig::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPSRC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::ContInf
 ******************************************************************************/

DlgBrlyTtbTrlorig::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgBrlyTtbTrlorig::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgBrlyTtbTrlorig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgBrlyTtbTrlorig";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgBrlyTtbTrlorig::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgBrlyTtbTrlorig::ContInf::diff(
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
 class DlgBrlyTtbTrlorig::ContInfTrl
 ******************************************************************************/

DlgBrlyTtbTrlorig::ContInfTrl::ContInfTrl(
			const string& TxtPrg
		) : Block() {
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgBrlyTtbTrlorig::ContInfTrl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgBrlyTtbTrlorigTrl");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgBrlyTtbTrlorigTrl";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgBrlyTtbTrlorig::ContInfTrl::comm(
			const ContInfTrl* comp
		) {
	set<uint> items;

	if (TxtPrg.compare(comp->TxtPrg) == 0) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgBrlyTtbTrlorig::ContInfTrl::diff(
			const ContInfTrl* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::StatApp
 ******************************************************************************/

DlgBrlyTtbTrlorig::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) : Block() {
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgBrlyTtbTrlorig::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgBrlyTtbTrlorig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgBrlyTtbTrlorig";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgBrlyTtbTrlorig::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgBrlyTtbTrlorig::StatApp::diff(
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
 class DlgBrlyTtbTrlorig::StatShr
 ******************************************************************************/

DlgBrlyTtbTrlorig::StatShr::StatShr(
			const bool ButDneActive
		) : Block() {
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgBrlyTtbTrlorig::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgBrlyTtbTrlorig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgBrlyTtbTrlorig";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgBrlyTtbTrlorig::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgBrlyTtbTrlorig::StatShr::diff(
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
 class DlgBrlyTtbTrlorig::StatShrRfi
 ******************************************************************************/

DlgBrlyTtbTrlorig::StatShrRfi::StatShrRfi(
			const bool UldActive
		) : Block() {
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

bool DlgBrlyTtbTrlorig::StatShrRfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgBrlyTtbTrlorigRfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgBrlyTtbTrlorigRfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
	};

	return basefound;
};

set<uint> DlgBrlyTtbTrlorig::StatShrRfi::comm(
			const StatShrRfi* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgBrlyTtbTrlorig::StatShrRfi::diff(
			const StatShrRfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::StatShrTfi
 ******************************************************************************/

DlgBrlyTtbTrlorig::StatShrTfi::StatShrTfi(
			const bool DldActive
		) : Block() {
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgBrlyTtbTrlorig::StatShrTfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgBrlyTtbTrlorigTfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgBrlyTtbTrlorigTfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgBrlyTtbTrlorig::StatShrTfi::comm(
			const StatShrTfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgBrlyTtbTrlorig::StatShrTfi::diff(
			const StatShrTfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::StatShrTrl
 ******************************************************************************/

DlgBrlyTtbTrlorig::StatShrTrl::StatShrTrl(
			const bool ButRunActive
			, const bool ButStoActive
		) : Block() {
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgBrlyTtbTrlorig::StatShrTrl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgBrlyTtbTrlorigTrl");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgBrlyTtbTrlorigTrl";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgBrlyTtbTrlorig::StatShrTrl::comm(
			const StatShrTrl* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgBrlyTtbTrlorig::StatShrTrl::diff(
			const StatShrTrl* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::Tag
 ******************************************************************************/

DlgBrlyTtbTrlorig::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) : Block() {
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgBrlyTtbTrlorig::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyTtbTrlorig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyTtbTrlorig";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::TagDet
 ******************************************************************************/

DlgBrlyTtbTrlorig::TagDet::TagDet(
			const string& CptSrc
		) : Block() {
	this->CptSrc = CptSrc;

	mask = {CPTSRC};
};

bool DlgBrlyTtbTrlorig::TagDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyTtbTrlorigDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyTtbTrlorigDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrc", CptSrc)) add(CPTSRC);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::TagRfi
 ******************************************************************************/

DlgBrlyTtbTrlorig::TagRfi::TagRfi(
			const string& Uld
			, const string& Cpt
		) : Block() {
	this->Uld = Uld;
	this->Cpt = Cpt;

	mask = {ULD, CPT};
};

bool DlgBrlyTtbTrlorig::TagRfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyTtbTrlorigRfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyTtbTrlorigRfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::TagTfi
 ******************************************************************************/

DlgBrlyTtbTrlorig::TagTfi::TagTfi(
			const string& Dld
		) : Block() {
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgBrlyTtbTrlorig::TagTfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyTtbTrlorigTfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyTtbTrlorigTfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::TagTrl
 ******************************************************************************/

DlgBrlyTtbTrlorig::TagTrl::TagTrl(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) : Block() {
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgBrlyTtbTrlorig::TagTrl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgBrlyTtbTrlorigTrl");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgBrlyTtbTrlorigTrl";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::DpchAppData
 ******************************************************************************/

DlgBrlyTtbTrlorig::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYTTBTRLORIGDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, CONTIACDET};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
};

string DlgBrlyTtbTrlorig::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyTtbTrlorig::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgBrlyTtbTrlorigData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::DpchAppDo
 ******************************************************************************/

DlgBrlyTtbTrlorig::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoTrl
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYTTBTRLORIGDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOTRL};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoTrl = ixVDoTrl;
};

string DlgBrlyTtbTrlorig::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOTRL)) ss.push_back("ixVDoTrl");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyTtbTrlorig::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgBrlyTtbTrlorigDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOTRL)) writeString(wr, "srefIxVDoTrl", VecVDoTrl::getSref(ixVDoTrl));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::DpchEngData
 ******************************************************************************/

DlgBrlyTtbTrlorig::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGDLGBRLYTTBTRLORIGDATA) {
	feedFDetPupSrc.tag = "FeedFDetPupSrc";
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgBrlyTtbTrlorig::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFTRL)) ss.push_back("continftrl");
	if (has(FEEDFDETPUPSRC)) ss.push_back("feedFDetPupSrc");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRRFI)) ss.push_back("statshrrfi");
	if (has(STATSHRTFI)) ss.push_back("statshrtfi");
	if (has(STATSHRTRL)) ss.push_back("statshrtrl");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGDET)) ss.push_back("tagdet");
	if (has(TAGRFI)) ss.push_back("tagrfi");
	if (has(TAGTFI)) ss.push_back("tagtfi");
	if (has(TAGTRL)) ss.push_back("tagtrl");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyTtbTrlorig::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgBrlyTtbTrlorigData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continftrl.readXML(docctx, basexpath, true)) add(CONTINFTRL);
		if (feedFDetPupSrc.readXML(docctx, basexpath, true)) add(FEEDFDETPUPSRC);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrrfi.readXML(docctx, basexpath, true)) add(STATSHRRFI);
		if (statshrtfi.readXML(docctx, basexpath, true)) add(STATSHRTFI);
		if (statshrtrl.readXML(docctx, basexpath, true)) add(STATSHRTRL);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagdet.readXML(docctx, basexpath, true)) add(TAGDET);
		if (tagrfi.readXML(docctx, basexpath, true)) add(TAGRFI);
		if (tagtfi.readXML(docctx, basexpath, true)) add(TAGTFI);
		if (tagtrl.readXML(docctx, basexpath, true)) add(TAGTRL);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
		continf = ContInf();
		continftrl = ContInfTrl();
		feedFDetPupSrc.clear();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrrfi = StatShrRfi();
		statshrtfi = StatShrTfi();
		statshrtrl = StatShrTrl();
		tag = Tag();
		tagdet = TagDet();
		tagrfi = TagRfi();
		tagtfi = TagTfi();
		tagtrl = TagTrl();
	};
};

