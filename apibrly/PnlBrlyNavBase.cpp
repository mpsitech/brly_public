/**
  * \file PnlBrlyNavBase.cpp
  * API code for job PnlBrlyNavBase (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyNavBase.h"

/******************************************************************************
 class PnlBrlyNavBase::VecVDo
 ******************************************************************************/

uint PnlBrlyNavBase::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregviewclick") return BUTREGVIEWCLICK;
	else if (s == "butregnewcrdclick") return BUTREGNEWCRDCLICK;
	else if (s == "butlocviewclick") return BUTLOCVIEWCLICK;
	else if (s == "butlocnewcrdclick") return BUTLOCNEWCRDCLICK;
	else if (s == "butlegviewclick") return BUTLEGVIEWCLICK;
	else if (s == "butlegnewcrdclick") return BUTLEGNEWCRDCLICK;
	else if (s == "butttbviewclick") return BUTTTBVIEWCLICK;
	else if (s == "butttbnewcrdclick") return BUTTTBNEWCRDCLICK;
	else if (s == "butfltviewclick") return BUTFLTVIEWCLICK;
	else if (s == "butfltnewcrdclick") return BUTFLTNEWCRDCLICK;
	else if (s == "butsegviewclick") return BUTSEGVIEWCLICK;

	return(0);
};

string PnlBrlyNavBase::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGVIEWCLICK) return("ButRegViewClick");
	else if (ix == BUTREGNEWCRDCLICK) return("ButRegNewcrdClick");
	else if (ix == BUTLOCVIEWCLICK) return("ButLocViewClick");
	else if (ix == BUTLOCNEWCRDCLICK) return("ButLocNewcrdClick");
	else if (ix == BUTLEGVIEWCLICK) return("ButLegViewClick");
	else if (ix == BUTLEGNEWCRDCLICK) return("ButLegNewcrdClick");
	else if (ix == BUTTTBVIEWCLICK) return("ButTtbViewClick");
	else if (ix == BUTTTBNEWCRDCLICK) return("ButTtbNewcrdClick");
	else if (ix == BUTFLTVIEWCLICK) return("ButFltViewClick");
	else if (ix == BUTFLTNEWCRDCLICK) return("ButFltNewcrdClick");
	else if (ix == BUTSEGVIEWCLICK) return("ButSegViewClick");

	return("");
};

/******************************************************************************
 class PnlBrlyNavBase::ContIac
 ******************************************************************************/

PnlBrlyNavBase::ContIac::ContIac(
			const uint numFLstReg
			, const uint numFLstLoc
			, const uint numFLstLeg
			, const uint numFLstTtb
			, const uint numFLstFlt
			, const uint numFLstSeg
		) : Block() {
	this->numFLstReg = numFLstReg;
	this->numFLstLoc = numFLstLoc;
	this->numFLstLeg = numFLstLeg;
	this->numFLstTtb = numFLstTtb;
	this->numFLstFlt = numFLstFlt;
	this->numFLstSeg = numFLstSeg;

	mask = {NUMFLSTREG, NUMFLSTLOC, NUMFLSTLEG, NUMFLSTTTB, NUMFLSTFLT, NUMFLSTSEG};
};

bool PnlBrlyNavBase::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyNavBase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyNavBase";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstReg", numFLstReg)) add(NUMFLSTREG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLoc", numFLstLoc)) add(NUMFLSTLOC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLeg", numFLstLeg)) add(NUMFLSTLEG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTtb", numFLstTtb)) add(NUMFLSTTTB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFlt", numFLstFlt)) add(NUMFLSTFLT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSeg", numFLstSeg)) add(NUMFLSTSEG);
	};

	return basefound;
};

void PnlBrlyNavBase::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyNavBase";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyNavBase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstReg", numFLstReg);
		writeUintAttr(wr, itemtag, "sref", "numFLstLoc", numFLstLoc);
		writeUintAttr(wr, itemtag, "sref", "numFLstLeg", numFLstLeg);
		writeUintAttr(wr, itemtag, "sref", "numFLstTtb", numFLstTtb);
		writeUintAttr(wr, itemtag, "sref", "numFLstFlt", numFLstFlt);
		writeUintAttr(wr, itemtag, "sref", "numFLstSeg", numFLstSeg);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyNavBase::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstReg == comp->numFLstReg) insert(items, NUMFLSTREG);
	if (numFLstLoc == comp->numFLstLoc) insert(items, NUMFLSTLOC);
	if (numFLstLeg == comp->numFLstLeg) insert(items, NUMFLSTLEG);
	if (numFLstTtb == comp->numFLstTtb) insert(items, NUMFLSTTTB);
	if (numFLstFlt == comp->numFLstFlt) insert(items, NUMFLSTFLT);
	if (numFLstSeg == comp->numFLstSeg) insert(items, NUMFLSTSEG);

	return(items);
};

set<uint> PnlBrlyNavBase::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTREG, NUMFLSTLOC, NUMFLSTLEG, NUMFLSTTTB, NUMFLSTFLT, NUMFLSTSEG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavBase::StatApp
 ******************************************************************************/

PnlBrlyNavBase::StatApp::StatApp(
			const uint ixBrlyVExpstate
			, const bool LstRegAlt
			, const bool LstLocAlt
			, const bool LstLegAlt
			, const bool LstTtbAlt
			, const bool LstFltAlt
			, const bool LstSegAlt
			, const uint LstRegNumFirstdisp
			, const uint LstLocNumFirstdisp
			, const uint LstLegNumFirstdisp
			, const uint LstTtbNumFirstdisp
			, const uint LstFltNumFirstdisp
			, const uint LstSegNumFirstdisp
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->LstRegAlt = LstRegAlt;
	this->LstLocAlt = LstLocAlt;
	this->LstLegAlt = LstLegAlt;
	this->LstTtbAlt = LstTtbAlt;
	this->LstFltAlt = LstFltAlt;
	this->LstSegAlt = LstSegAlt;
	this->LstRegNumFirstdisp = LstRegNumFirstdisp;
	this->LstLocNumFirstdisp = LstLocNumFirstdisp;
	this->LstLegNumFirstdisp = LstLegNumFirstdisp;
	this->LstTtbNumFirstdisp = LstTtbNumFirstdisp;
	this->LstFltNumFirstdisp = LstFltNumFirstdisp;
	this->LstSegNumFirstdisp = LstSegNumFirstdisp;

	mask = {IXBRLYVEXPSTATE, LSTREGALT, LSTLOCALT, LSTLEGALT, LSTTTBALT, LSTFLTALT, LSTSEGALT, LSTREGNUMFIRSTDISP, LSTLOCNUMFIRSTDISP, LSTLEGNUMFIRSTDISP, LSTTTBNUMFIRSTDISP, LSTFLTNUMFIRSTDISP, LSTSEGNUMFIRSTDISP};
};

bool PnlBrlyNavBase::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyNavBase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyNavBase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRegAlt", LstRegAlt)) add(LSTREGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLocAlt", LstLocAlt)) add(LSTLOCALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLegAlt", LstLegAlt)) add(LSTLEGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTtbAlt", LstTtbAlt)) add(LSTTTBALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFltAlt", LstFltAlt)) add(LSTFLTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSegAlt", LstSegAlt)) add(LSTSEGALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRegNumFirstdisp", LstRegNumFirstdisp)) add(LSTREGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLocNumFirstdisp", LstLocNumFirstdisp)) add(LSTLOCNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLegNumFirstdisp", LstLegNumFirstdisp)) add(LSTLEGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTtbNumFirstdisp", LstTtbNumFirstdisp)) add(LSTTTBNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFltNumFirstdisp", LstFltNumFirstdisp)) add(LSTFLTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSegNumFirstdisp", LstSegNumFirstdisp)) add(LSTSEGNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlBrlyNavBase::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (LstRegAlt == comp->LstRegAlt) insert(items, LSTREGALT);
	if (LstLocAlt == comp->LstLocAlt) insert(items, LSTLOCALT);
	if (LstLegAlt == comp->LstLegAlt) insert(items, LSTLEGALT);
	if (LstTtbAlt == comp->LstTtbAlt) insert(items, LSTTTBALT);
	if (LstFltAlt == comp->LstFltAlt) insert(items, LSTFLTALT);
	if (LstSegAlt == comp->LstSegAlt) insert(items, LSTSEGALT);
	if (LstRegNumFirstdisp == comp->LstRegNumFirstdisp) insert(items, LSTREGNUMFIRSTDISP);
	if (LstLocNumFirstdisp == comp->LstLocNumFirstdisp) insert(items, LSTLOCNUMFIRSTDISP);
	if (LstLegNumFirstdisp == comp->LstLegNumFirstdisp) insert(items, LSTLEGNUMFIRSTDISP);
	if (LstTtbNumFirstdisp == comp->LstTtbNumFirstdisp) insert(items, LSTTTBNUMFIRSTDISP);
	if (LstFltNumFirstdisp == comp->LstFltNumFirstdisp) insert(items, LSTFLTNUMFIRSTDISP);
	if (LstSegNumFirstdisp == comp->LstSegNumFirstdisp) insert(items, LSTSEGNUMFIRSTDISP);

	return(items);
};

set<uint> PnlBrlyNavBase::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, LSTREGALT, LSTLOCALT, LSTLEGALT, LSTTTBALT, LSTFLTALT, LSTSEGALT, LSTREGNUMFIRSTDISP, LSTLOCNUMFIRSTDISP, LSTLEGNUMFIRSTDISP, LSTTTBNUMFIRSTDISP, LSTFLTNUMFIRSTDISP, LSTSEGNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavBase::StatShr
 ******************************************************************************/

PnlBrlyNavBase::StatShr::StatShr(
			const bool LstRegAvail
			, const bool ButRegViewActive
			, const bool LstLocAvail
			, const bool ButLocViewActive
			, const bool LstLegAvail
			, const bool ButLegViewActive
			, const bool LstTtbAvail
			, const bool ButTtbViewActive
			, const bool LstFltAvail
			, const bool ButFltViewActive
			, const bool LstSegAvail
			, const bool ButSegViewActive
		) : Block() {
	this->LstRegAvail = LstRegAvail;
	this->ButRegViewActive = ButRegViewActive;
	this->LstLocAvail = LstLocAvail;
	this->ButLocViewActive = ButLocViewActive;
	this->LstLegAvail = LstLegAvail;
	this->ButLegViewActive = ButLegViewActive;
	this->LstTtbAvail = LstTtbAvail;
	this->ButTtbViewActive = ButTtbViewActive;
	this->LstFltAvail = LstFltAvail;
	this->ButFltViewActive = ButFltViewActive;
	this->LstSegAvail = LstSegAvail;
	this->ButSegViewActive = ButSegViewActive;

	mask = {LSTREGAVAIL, BUTREGVIEWACTIVE, LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTLEGAVAIL, BUTLEGVIEWACTIVE, LSTTTBAVAIL, BUTTTBVIEWACTIVE, LSTFLTAVAIL, BUTFLTVIEWACTIVE, LSTSEGAVAIL, BUTSEGVIEWACTIVE};
};

bool PnlBrlyNavBase::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyNavBase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyNavBase";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRegAvail", LstRegAvail)) add(LSTREGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegViewActive", ButRegViewActive)) add(BUTREGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLocAvail", LstLocAvail)) add(LSTLOCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLocViewActive", ButLocViewActive)) add(BUTLOCVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLegAvail", LstLegAvail)) add(LSTLEGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLegViewActive", ButLegViewActive)) add(BUTLEGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTtbAvail", LstTtbAvail)) add(LSTTTBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTtbViewActive", ButTtbViewActive)) add(BUTTTBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFltAvail", LstFltAvail)) add(LSTFLTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFltViewActive", ButFltViewActive)) add(BUTFLTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSegAvail", LstSegAvail)) add(LSTSEGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSegViewActive", ButSegViewActive)) add(BUTSEGVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyNavBase::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstRegAvail == comp->LstRegAvail) insert(items, LSTREGAVAIL);
	if (ButRegViewActive == comp->ButRegViewActive) insert(items, BUTREGVIEWACTIVE);
	if (LstLocAvail == comp->LstLocAvail) insert(items, LSTLOCAVAIL);
	if (ButLocViewActive == comp->ButLocViewActive) insert(items, BUTLOCVIEWACTIVE);
	if (LstLegAvail == comp->LstLegAvail) insert(items, LSTLEGAVAIL);
	if (ButLegViewActive == comp->ButLegViewActive) insert(items, BUTLEGVIEWACTIVE);
	if (LstTtbAvail == comp->LstTtbAvail) insert(items, LSTTTBAVAIL);
	if (ButTtbViewActive == comp->ButTtbViewActive) insert(items, BUTTTBVIEWACTIVE);
	if (LstFltAvail == comp->LstFltAvail) insert(items, LSTFLTAVAIL);
	if (ButFltViewActive == comp->ButFltViewActive) insert(items, BUTFLTVIEWACTIVE);
	if (LstSegAvail == comp->LstSegAvail) insert(items, LSTSEGAVAIL);
	if (ButSegViewActive == comp->ButSegViewActive) insert(items, BUTSEGVIEWACTIVE);

	return(items);
};

set<uint> PnlBrlyNavBase::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTREGAVAIL, BUTREGVIEWACTIVE, LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTLEGAVAIL, BUTLEGVIEWACTIVE, LSTTTBAVAIL, BUTTTBVIEWACTIVE, LSTFLTAVAIL, BUTFLTVIEWACTIVE, LSTSEGAVAIL, BUTSEGVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavBase::Tag
 ******************************************************************************/

PnlBrlyNavBase::Tag::Tag(
			const string& Cpt
			, const string& CptReg
			, const string& CptLoc
			, const string& CptLeg
			, const string& CptTtb
			, const string& CptFlt
			, const string& CptSeg
		) : Block() {
	this->Cpt = Cpt;
	this->CptReg = CptReg;
	this->CptLoc = CptLoc;
	this->CptLeg = CptLeg;
	this->CptTtb = CptTtb;
	this->CptFlt = CptFlt;
	this->CptSeg = CptSeg;

	mask = {CPT, CPTREG, CPTLOC, CPTLEG, CPTTTB, CPTFLT, CPTSEG};
};

bool PnlBrlyNavBase::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyNavBase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyNavBase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReg", CptReg)) add(CPTREG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLoc", CptLoc)) add(CPTLOC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLeg", CptLeg)) add(CPTLEG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTtb", CptTtb)) add(CPTTTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFlt", CptFlt)) add(CPTFLT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSeg", CptSeg)) add(CPTSEG);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyNavBase::DpchAppData
 ******************************************************************************/

PnlBrlyNavBase::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVBASEDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlyNavBase::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavBase::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyNavBaseData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavBase::DpchAppDo
 ******************************************************************************/

PnlBrlyNavBase::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVBASEDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyNavBase::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavBase::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyNavBaseDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavBase::DpchEngData
 ******************************************************************************/

PnlBrlyNavBase::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYNAVBASEDATA) {
	feedFLstFlt.tag = "FeedFLstFlt";
	feedFLstLeg.tag = "FeedFLstLeg";
	feedFLstLoc.tag = "FeedFLstLoc";
	feedFLstReg.tag = "FeedFLstReg";
	feedFLstSeg.tag = "FeedFLstSeg";
	feedFLstTtb.tag = "FeedFLstTtb";
};

string PnlBrlyNavBase::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFLT)) ss.push_back("feedFLstFlt");
	if (has(FEEDFLSTLEG)) ss.push_back("feedFLstLeg");
	if (has(FEEDFLSTLOC)) ss.push_back("feedFLstLoc");
	if (has(FEEDFLSTREG)) ss.push_back("feedFLstReg");
	if (has(FEEDFLSTSEG)) ss.push_back("feedFLstSeg");
	if (has(FEEDFLSTTTB)) ss.push_back("feedFLstTtb");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavBase::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyNavBaseData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstFlt.readXML(docctx, basexpath, true)) add(FEEDFLSTFLT);
		if (feedFLstLeg.readXML(docctx, basexpath, true)) add(FEEDFLSTLEG);
		if (feedFLstLoc.readXML(docctx, basexpath, true)) add(FEEDFLSTLOC);
		if (feedFLstReg.readXML(docctx, basexpath, true)) add(FEEDFLSTREG);
		if (feedFLstSeg.readXML(docctx, basexpath, true)) add(FEEDFLSTSEG);
		if (feedFLstTtb.readXML(docctx, basexpath, true)) add(FEEDFLSTTTB);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstFlt.clear();
		feedFLstLeg.clear();
		feedFLstLoc.clear();
		feedFLstReg.clear();
		feedFLstSeg.clear();
		feedFLstTtb.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

