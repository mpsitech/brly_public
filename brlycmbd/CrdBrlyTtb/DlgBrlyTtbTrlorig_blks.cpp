/**
  * \file DlgBrlyTtbTrlorig_blks.cpp
  * job handler for job DlgBrlyTtbTrlorig (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

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

string DlgBrlyTtbTrlorig::VecVDit::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == DET) return("Details");
		else if (ix == RFI) return("Raw data file");
		else if (ix == TRL) return("Translation");
		else if (ix == TFI) return("Translated file");
	} else if (ixBrlyVLocale == 2) {
		if (ix == DET) return("Details");
		else if (ix == RFI) return("Rohdaten-Datei");
		else if (ix == TRL) return("\\u00dcbersetzung");
		else if (ix == TFI) return("\\u00dcbersetzte Datei");
	};

	return("");
};

void DlgBrlyTtbTrlorig::VecVDit::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
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

void DlgBrlyTtbTrlorig::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

string DlgBrlyTtbTrlorig::VecVSrc::getTitle(
			const uint ix
		) {
	if (ix == STAR) return("StarAlliance .pdf");
	else if (ix == OW) return("oneworld .pdf");

	return("");
};

void DlgBrlyTtbTrlorig::VecVSrc::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
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

void DlgBrlyTtbTrlorig::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyTtbTrlorig";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyTtbTrlorig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
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

void DlgBrlyTtbTrlorig::ContInfTrl::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyTtbTrlorigTrl";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyTtbTrlorigTrl";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyTtbTrlorig::ContInfTrl::comm(
			const ContInfTrl* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

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

void DlgBrlyTtbTrlorig::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgBrlyTtbTrlorig";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgBrlyTtbTrlorig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
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

void DlgBrlyTtbTrlorig::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyTtbTrlorig";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyTtbTrlorig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
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

void DlgBrlyTtbTrlorig::StatShrRfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyTtbTrlorigRfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyTtbTrlorigRfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
	xmlTextWriterEndElement(wr);
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

void DlgBrlyTtbTrlorig::StatShrTfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyTtbTrlorigTfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyTtbTrlorigTfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
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

void DlgBrlyTtbTrlorig::StatShrTrl::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyTtbTrlorigTrl";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyTtbTrlorigTrl";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
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

void DlgBrlyTtbTrlorig::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyTtbTrlorig";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyTtbTrlorig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Translate from original format");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Aus Original-Format \\u00fcbersetzen");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DONE, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::TagDet
 ******************************************************************************/

void DlgBrlyTtbTrlorig::TagDet::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyTtbTrlorigDet";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyTtbTrlorigDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrc", "Source");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptSrc", "Quelle");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::TagRfi
 ******************************************************************************/

void DlgBrlyTtbTrlorig::TagRfi::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyTtbTrlorigRfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyTtbTrlorigRfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::UPLOAD, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::FILENAME, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::TagTfi
 ******************************************************************************/

void DlgBrlyTtbTrlorig::TagTfi::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyTtbTrlorigTfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyTtbTrlorigTfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DOWNLOAD, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::TagTrl
 ******************************************************************************/

void DlgBrlyTtbTrlorig::TagTrl::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyTtbTrlorigTrl";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyTtbTrlorigTrl";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::PROGRESS, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::RUN, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::STOP, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::DpchAppData
 ******************************************************************************/

DlgBrlyTtbTrlorig::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYTTBTRLORIGDATA) {
};

string DlgBrlyTtbTrlorig::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyTtbTrlorig::DpchAppData::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgBrlyTtbTrlorigData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
	};
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::DpchAppDo
 ******************************************************************************/

DlgBrlyTtbTrlorig::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYTTBTRLORIGDO) {
	ixVDo = 0;
	ixVDoTrl = 0;
};

string DlgBrlyTtbTrlorig::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOTRL)) ss.push_back("ixVDoTrl");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyTtbTrlorig::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoTrl;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgBrlyTtbTrlorigDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoTrl", "", srefIxVDoTrl)) {
			ixVDoTrl = VecVDoTrl::getIx(srefIxVDoTrl);
			add(IXVDOTRL);
		};
	} else {
	};
};

/******************************************************************************
 class DlgBrlyTtbTrlorig::DpchEngData
 ******************************************************************************/

DlgBrlyTtbTrlorig::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, ContInf* continf
			, ContInfTrl* continftrl
			, Feed* feedFDetPupSrc
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrRfi* statshrrfi
			, StatShrTfi* statshrtfi
			, StatShrTrl* statshrtrl
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGDLGBRLYTTBTRLORIGDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACDET, CONTINF, CONTINFTRL, FEEDFDETPUPSRC, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRRFI, STATSHRTFI, STATSHRTRL, TAG, TAGDET, TAGRFI, TAGTFI, TAGTRL};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFTRL) && continftrl) this->continftrl = *continftrl;
	if (find(this->mask, FEEDFDETPUPSRC) && feedFDetPupSrc) this->feedFDetPupSrc = *feedFDetPupSrc;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRRFI) && statshrrfi) this->statshrrfi = *statshrrfi;
	if (find(this->mask, STATSHRTFI) && statshrtfi) this->statshrtfi = *statshrtfi;
	if (find(this->mask, STATSHRTRL) && statshrtrl) this->statshrtrl = *statshrtrl;
};

string DlgBrlyTtbTrlorig::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void DlgBrlyTtbTrlorig::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACDET)) {contiacdet = src->contiacdet; add(CONTIACDET);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFTRL)) {continftrl = src->continftrl; add(CONTINFTRL);};
	if (src->has(FEEDFDETPUPSRC)) {feedFDetPupSrc = src->feedFDetPupSrc; add(FEEDFDETPUPSRC);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRRFI)) {statshrrfi = src->statshrrfi; add(STATSHRRFI);};
	if (src->has(STATSHRTFI)) {statshrtfi = src->statshrtfi; add(STATSHRTFI);};
	if (src->has(STATSHRTRL)) {statshrtrl = src->statshrtrl; add(STATSHRTRL);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGDET)) add(TAGDET);
	if (src->has(TAGRFI)) add(TAGRFI);
	if (src->has(TAGTFI)) add(TAGTFI);
	if (src->has(TAGTRL)) add(TAGTRL);
};

void DlgBrlyTtbTrlorig::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgBrlyTtbTrlorigData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFTRL)) continftrl.writeXML(wr);
		if (has(FEEDFDETPUPSRC)) feedFDetPupSrc.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRRFI)) statshrrfi.writeXML(wr);
		if (has(STATSHRTFI)) statshrtfi.writeXML(wr);
		if (has(STATSHRTRL)) statshrtrl.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(TAGDET)) TagDet::writeXML(ixBrlyVLocale, wr);
		if (has(TAGRFI)) TagRfi::writeXML(ixBrlyVLocale, wr);
		if (has(TAGTFI)) TagTfi::writeXML(ixBrlyVLocale, wr);
		if (has(TAGTRL)) TagTrl::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

