/**
  * \file PnlBrlyConDetail.cpp
  * API code for job PnlBrlyConDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyConDetail.h"

/******************************************************************************
 class PnlBrlyConDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyConDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butfltviewclick") return BUTFLTVIEWCLICK;
	else if (s == "butttbviewclick") return BUTTTBVIEWCLICK;
	else if (s == "butetyeditclick") return BUTETYEDITCLICK;

	return(0);
};

string PnlBrlyConDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTFLTVIEWCLICK) return("ButFltViewClick");
	else if (ix == BUTTTBVIEWCLICK) return("ButTtbViewClick");
	else if (ix == BUTETYEDITCLICK) return("ButEtyEditClick");

	return("");
};

/******************************************************************************
 class PnlBrlyConDetail::ContIac
 ******************************************************************************/

PnlBrlyConDetail::ContIac::ContIac(
			const string& TxfSta
			, const string& TxfSto
			, const uint numFPupMod
			, const vector<uint>& numsFLstEty
			, const string& TxfEty
		) : Block() {
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->numFPupMod = numFPupMod;
	this->numsFLstEty = numsFLstEty;
	this->TxfEty = TxfEty;

	mask = {TXFSTA, TXFSTO, NUMFPUPMOD, NUMSFLSTETY, TXFETY};
};

bool PnlBrlyConDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyConDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMod", numFPupMod)) add(NUMFPUPMOD);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstEty", numsFLstEty)) add(NUMSFLSTETY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEty", TxfEty)) add(TXFETY);
	};

	return basefound;
};

void PnlBrlyConDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyConDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeUintAttr(wr, itemtag, "sref", "numFPupMod", numFPupMod);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstEty", numsFLstEty);
		writeStringAttr(wr, itemtag, "sref", "TxfEty", TxfEty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyConDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSta.compare(comp->TxfSta) == 0) insert(items, TXFSTA);
	if (TxfSto.compare(comp->TxfSto) == 0) insert(items, TXFSTO);
	if (numFPupMod == comp->numFPupMod) insert(items, NUMFPUPMOD);
	if (compareUintvec(numsFLstEty, comp->numsFLstEty)) insert(items, NUMSFLSTETY);
	if (TxfEty.compare(comp->TxfEty) == 0) insert(items, TXFETY);

	return(items);
};

set<uint> PnlBrlyConDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSTA, TXFSTO, NUMFPUPMOD, NUMSFLSTETY, TXFETY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConDetail::ContInf
 ******************************************************************************/

PnlBrlyConDetail::ContInf::ContInf(
			const string& TxtFlt
			, const string& TxtCor
			, const string& TxtTtb
		) : Block() {
	this->TxtFlt = TxtFlt;
	this->TxtCor = TxtCor;
	this->TxtTtb = TxtTtb;

	mask = {TXTFLT, TXTCOR, TXTTTB};
};

bool PnlBrlyConDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyConDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFlt", TxtFlt)) add(TXTFLT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCor", TxtCor)) add(TXTCOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTtb", TxtTtb)) add(TXTTTB);
	};

	return basefound;
};

set<uint> PnlBrlyConDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFlt.compare(comp->TxtFlt) == 0) insert(items, TXTFLT);
	if (TxtCor.compare(comp->TxtCor) == 0) insert(items, TXTCOR);
	if (TxtTtb.compare(comp->TxtTtb) == 0) insert(items, TXTTTB);

	return(items);
};

set<uint> PnlBrlyConDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFLT, TXTCOR, TXTTTB};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConDetail::StatApp
 ******************************************************************************/

PnlBrlyConDetail::StatApp::StatApp(
			const uint ixBrlyVExpstate
			, const bool LstEtyAlt
			, const uint LstEtyNumFirstdisp
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->LstEtyAlt = LstEtyAlt;
	this->LstEtyNumFirstdisp = LstEtyNumFirstdisp;

	mask = {IXBRLYVEXPSTATE, LSTETYALT, LSTETYNUMFIRSTDISP};
};

bool PnlBrlyConDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyConDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstEtyAlt", LstEtyAlt)) add(LSTETYALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstEtyNumFirstdisp", LstEtyNumFirstdisp)) add(LSTETYNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlBrlyConDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (LstEtyAlt == comp->LstEtyAlt) insert(items, LSTETYALT);
	if (LstEtyNumFirstdisp == comp->LstEtyNumFirstdisp) insert(items, LSTETYNUMFIRSTDISP);

	return(items);
};

set<uint> PnlBrlyConDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, LSTETYALT, LSTETYNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConDetail::StatShr
 ******************************************************************************/

PnlBrlyConDetail::StatShr::StatShr(
			const bool TxfEtyValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtFltActive
			, const bool ButFltViewAvail
			, const bool ButFltViewActive
			, const bool TxtCorActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool PupModActive
			, const bool TxtTtbActive
			, const bool ButTtbViewAvail
			, const bool ButTtbViewActive
			, const bool LstEtyActive
			, const bool ButEtyEditAvail
		) : Block() {
	this->TxfEtyValid = TxfEtyValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtFltActive = TxtFltActive;
	this->ButFltViewAvail = ButFltViewAvail;
	this->ButFltViewActive = ButFltViewActive;
	this->TxtCorActive = TxtCorActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->PupModActive = PupModActive;
	this->TxtTtbActive = TxtTtbActive;
	this->ButTtbViewAvail = ButTtbViewAvail;
	this->ButTtbViewActive = ButTtbViewActive;
	this->LstEtyActive = LstEtyActive;
	this->ButEtyEditAvail = ButEtyEditAvail;

	mask = {TXFETYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFLTACTIVE, BUTFLTVIEWAVAIL, BUTFLTVIEWACTIVE, TXTCORACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, PUPMODACTIVE, TXTTTBACTIVE, BUTTTBVIEWAVAIL, BUTTTBVIEWACTIVE, LSTETYACTIVE, BUTETYEDITAVAIL};
};

bool PnlBrlyConDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyConDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfEtyValid", TxfEtyValid)) add(TXFETYVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFltActive", TxtFltActive)) add(TXTFLTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFltViewAvail", ButFltViewAvail)) add(BUTFLTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFltViewActive", ButFltViewActive)) add(BUTFLTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCorActive", TxtCorActive)) add(TXTCORACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStoActive", TxfStoActive)) add(TXFSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupModActive", PupModActive)) add(PUPMODACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTtbActive", TxtTtbActive)) add(TXTTTBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTtbViewAvail", ButTtbViewAvail)) add(BUTTTBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTtbViewActive", ButTtbViewActive)) add(BUTTTBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstEtyActive", LstEtyActive)) add(LSTETYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEtyEditAvail", ButEtyEditAvail)) add(BUTETYEDITAVAIL);
	};

	return basefound;
};

set<uint> PnlBrlyConDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfEtyValid == comp->TxfEtyValid) insert(items, TXFETYVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtFltActive == comp->TxtFltActive) insert(items, TXTFLTACTIVE);
	if (ButFltViewAvail == comp->ButFltViewAvail) insert(items, BUTFLTVIEWAVAIL);
	if (ButFltViewActive == comp->ButFltViewActive) insert(items, BUTFLTVIEWACTIVE);
	if (TxtCorActive == comp->TxtCorActive) insert(items, TXTCORACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (PupModActive == comp->PupModActive) insert(items, PUPMODACTIVE);
	if (TxtTtbActive == comp->TxtTtbActive) insert(items, TXTTTBACTIVE);
	if (ButTtbViewAvail == comp->ButTtbViewAvail) insert(items, BUTTTBVIEWAVAIL);
	if (ButTtbViewActive == comp->ButTtbViewActive) insert(items, BUTTTBVIEWACTIVE);
	if (LstEtyActive == comp->LstEtyActive) insert(items, LSTETYACTIVE);
	if (ButEtyEditAvail == comp->ButEtyEditAvail) insert(items, BUTETYEDITAVAIL);

	return(items);
};

set<uint> PnlBrlyConDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFETYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFLTACTIVE, BUTFLTVIEWAVAIL, BUTFLTVIEWACTIVE, TXTCORACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, PUPMODACTIVE, TXTTTBACTIVE, BUTTTBVIEWAVAIL, BUTTTBVIEWACTIVE, LSTETYACTIVE, BUTETYEDITAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConDetail::Tag
 ******************************************************************************/

PnlBrlyConDetail::Tag::Tag(
			const string& Cpt
			, const string& CptFlt
			, const string& CptCor
			, const string& CptSta
			, const string& CptSto
			, const string& CptMod
			, const string& CptTtb
			, const string& CptEty
		) : Block() {
	this->Cpt = Cpt;
	this->CptFlt = CptFlt;
	this->CptCor = CptCor;
	this->CptSta = CptSta;
	this->CptSto = CptSto;
	this->CptMod = CptMod;
	this->CptTtb = CptTtb;
	this->CptEty = CptEty;

	mask = {CPT, CPTFLT, CPTCOR, CPTSTA, CPTSTO, CPTMOD, CPTTTB, CPTETY};
};

bool PnlBrlyConDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyConDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFlt", CptFlt)) add(CPTFLT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCor", CptCor)) add(CPTCOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSto", CptSto)) add(CPTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMod", CptMod)) add(CPTMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTtb", CptTtb)) add(CPTTTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEty", CptEty)) add(CPTETY);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyConDetail::DpchAppData
 ******************************************************************************/

PnlBrlyConDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlyConDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyConDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyConDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyConDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyConDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConDetail::DpchEngData
 ******************************************************************************/

PnlBrlyConDetail::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONDETAILDATA) {
	feedFLstEty.tag = "FeedFLstEty";
	feedFPupMod.tag = "FeedFPupMod";
};

string PnlBrlyConDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTETY)) ss.push_back("feedFLstEty");
	if (has(FEEDFPUPMOD)) ss.push_back("feedFPupMod");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyConDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstEty.readXML(docctx, basexpath, true)) add(FEEDFLSTETY);
		if (feedFPupMod.readXML(docctx, basexpath, true)) add(FEEDFPUPMOD);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstEty.clear();
		feedFPupMod.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

