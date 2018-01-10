/**
  * \file PnlBrlyRlyDetail.cpp
  * API code for job PnlBrlyRlyDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyRlyDetail.h"

/******************************************************************************
 class PnlBrlyRlyDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyRlyDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butconviewclick") return BUTCONVIEWCLICK;

	return(0);
};

string PnlBrlyRlyDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTCONVIEWCLICK) return("ButConViewClick");

	return("");
};

/******************************************************************************
 class PnlBrlyRlyDetail::ContIac
 ******************************************************************************/

PnlBrlyRlyDetail::ContIac::ContIac(
			const string& TxfSta
			, const string& TxfSto
			, const uint numFPupDir
			, const bool ChkCtd
			, const string& TxfNhp
		) : Block() {
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->numFPupDir = numFPupDir;
	this->ChkCtd = ChkCtd;
	this->TxfNhp = TxfNhp;

	mask = {TXFSTA, TXFSTO, NUMFPUPDIR, CHKCTD, TXFNHP};
};

bool PnlBrlyRlyDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyRlyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyRlyDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupDir", numFPupDir)) add(NUMFPUPDIR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCtd", ChkCtd)) add(CHKCTD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfNhp", TxfNhp)) add(TXFNHP);
	};

	return basefound;
};

void PnlBrlyRlyDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyRlyDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyRlyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeUintAttr(wr, itemtag, "sref", "numFPupDir", numFPupDir);
		writeBoolAttr(wr, itemtag, "sref", "ChkCtd", ChkCtd);
		writeStringAttr(wr, itemtag, "sref", "TxfNhp", TxfNhp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyRlyDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSta.compare(comp->TxfSta) == 0) insert(items, TXFSTA);
	if (TxfSto.compare(comp->TxfSto) == 0) insert(items, TXFSTO);
	if (numFPupDir == comp->numFPupDir) insert(items, NUMFPUPDIR);
	if (ChkCtd == comp->ChkCtd) insert(items, CHKCTD);
	if (TxfNhp.compare(comp->TxfNhp) == 0) insert(items, TXFNHP);

	return(items);
};

set<uint> PnlBrlyRlyDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSTA, TXFSTO, NUMFPUPDIR, CHKCTD, TXFNHP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRlyDetail::ContInf
 ******************************************************************************/

PnlBrlyRlyDetail::ContInf::ContInf(
			const string& TxtCon
		) : Block() {
	this->TxtCon = TxtCon;

	mask = {TXTCON};
};

bool PnlBrlyRlyDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyRlyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyRlyDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCon", TxtCon)) add(TXTCON);
	};

	return basefound;
};

set<uint> PnlBrlyRlyDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtCon.compare(comp->TxtCon) == 0) insert(items, TXTCON);

	return(items);
};

set<uint> PnlBrlyRlyDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCON};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRlyDetail::StatApp
 ******************************************************************************/

PnlBrlyRlyDetail::StatApp::StatApp(
			const uint ixBrlyVExpstate
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;

	mask = {IXBRLYVEXPSTATE};
};

bool PnlBrlyRlyDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyRlyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyRlyDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlBrlyRlyDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);

	return(items);
};

set<uint> PnlBrlyRlyDetail::StatApp::diff(
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
 class PnlBrlyRlyDetail::StatShr
 ******************************************************************************/

PnlBrlyRlyDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool TxtConActive
			, const bool ButConViewAvail
			, const bool ButConViewActive
			, const bool PupDirActive
			, const bool ChkCtdActive
			, const bool TxfNhpActive
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->TxtConActive = TxtConActive;
	this->ButConViewAvail = ButConViewAvail;
	this->ButConViewActive = ButConViewActive;
	this->PupDirActive = PupDirActive;
	this->ChkCtdActive = ChkCtdActive;
	this->TxfNhpActive = TxfNhpActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXTCONACTIVE, BUTCONVIEWAVAIL, BUTCONVIEWACTIVE, PUPDIRACTIVE, CHKCTDACTIVE, TXFNHPACTIVE};
};

bool PnlBrlyRlyDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyRlyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyRlyDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStoActive", TxfStoActive)) add(TXFSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtConActive", TxtConActive)) add(TXTCONACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButConViewAvail", ButConViewAvail)) add(BUTCONVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButConViewActive", ButConViewActive)) add(BUTCONVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupDirActive", PupDirActive)) add(PUPDIRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkCtdActive", ChkCtdActive)) add(CHKCTDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfNhpActive", TxfNhpActive)) add(TXFNHPACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyRlyDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (TxtConActive == comp->TxtConActive) insert(items, TXTCONACTIVE);
	if (ButConViewAvail == comp->ButConViewAvail) insert(items, BUTCONVIEWAVAIL);
	if (ButConViewActive == comp->ButConViewActive) insert(items, BUTCONVIEWACTIVE);
	if (PupDirActive == comp->PupDirActive) insert(items, PUPDIRACTIVE);
	if (ChkCtdActive == comp->ChkCtdActive) insert(items, CHKCTDACTIVE);
	if (TxfNhpActive == comp->TxfNhpActive) insert(items, TXFNHPACTIVE);

	return(items);
};

set<uint> PnlBrlyRlyDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXTCONACTIVE, BUTCONVIEWAVAIL, BUTCONVIEWACTIVE, PUPDIRACTIVE, CHKCTDACTIVE, TXFNHPACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRlyDetail::Tag
 ******************************************************************************/

PnlBrlyRlyDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSta
			, const string& CptSto
			, const string& CptCon
			, const string& CptDir
			, const string& CptCtd
			, const string& CptNhp
		) : Block() {
	this->Cpt = Cpt;
	this->CptSta = CptSta;
	this->CptSto = CptSto;
	this->CptCon = CptCon;
	this->CptDir = CptDir;
	this->CptCtd = CptCtd;
	this->CptNhp = CptNhp;

	mask = {CPT, CPTSTA, CPTSTO, CPTCON, CPTDIR, CPTCTD, CPTNHP};
};

bool PnlBrlyRlyDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyRlyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyRlyDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSto", CptSto)) add(CPTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCon", CptCon)) add(CPTCON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDir", CptDir)) add(CPTDIR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtd", CptCtd)) add(CPTCTD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptNhp", CptNhp)) add(CPTNHP);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyRlyDetail::DpchAppData
 ******************************************************************************/

PnlBrlyRlyDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYRLYDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlyRlyDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRlyDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyRlyDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyRlyDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyRlyDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYRLYDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyRlyDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRlyDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyRlyDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyRlyDetail::DpchEngData
 ******************************************************************************/

PnlBrlyRlyDetail::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYRLYDETAILDATA) {
	feedFPupDir.tag = "FeedFPupDir";
};

string PnlBrlyRlyDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPDIR)) ss.push_back("feedFPupDir");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRlyDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyRlyDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupDir.readXML(docctx, basexpath, true)) add(FEEDFPUPDIR);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupDir.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

