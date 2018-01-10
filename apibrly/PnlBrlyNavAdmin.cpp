/**
  * \file PnlBrlyNavAdmin.cpp
  * API code for job PnlBrlyNavAdmin (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyNavAdmin.h"

/******************************************************************************
 class PnlBrlyNavAdmin::VecVDo
 ******************************************************************************/

uint PnlBrlyNavAdmin::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butusgviewclick") return BUTUSGVIEWCLICK;
	else if (s == "butusgnewcrdclick") return BUTUSGNEWCRDCLICK;
	else if (s == "butusrviewclick") return BUTUSRVIEWCLICK;
	else if (s == "butusrnewcrdclick") return BUTUSRNEWCRDCLICK;
	else if (s == "butprsviewclick") return BUTPRSVIEWCLICK;
	else if (s == "butprsnewcrdclick") return BUTPRSNEWCRDCLICK;
	else if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	else if (s == "butfilnewcrdclick") return BUTFILNEWCRDCLICK;
	else if (s == "butoprviewclick") return BUTOPRVIEWCLICK;
	else if (s == "butoprnewcrdclick") return BUTOPRNEWCRDCLICK;
	else if (s == "butptyviewclick") return BUTPTYVIEWCLICK;
	else if (s == "butptynewcrdclick") return BUTPTYNEWCRDCLICK;

	return(0);
};

string PnlBrlyNavAdmin::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
	else if (ix == BUTUSGNEWCRDCLICK) return("ButUsgNewcrdClick");
	else if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");
	else if (ix == BUTUSRNEWCRDCLICK) return("ButUsrNewcrdClick");
	else if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
	else if (ix == BUTPRSNEWCRDCLICK) return("ButPrsNewcrdClick");
	else if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	else if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");
	else if (ix == BUTOPRVIEWCLICK) return("ButOprViewClick");
	else if (ix == BUTOPRNEWCRDCLICK) return("ButOprNewcrdClick");
	else if (ix == BUTPTYVIEWCLICK) return("ButPtyViewClick");
	else if (ix == BUTPTYNEWCRDCLICK) return("ButPtyNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlBrlyNavAdmin::ContIac
 ******************************************************************************/

PnlBrlyNavAdmin::ContIac::ContIac(
			const uint numFLstUsg
			, const uint numFLstUsr
			, const uint numFLstPrs
			, const uint numFLstFil
			, const uint numFLstOpr
			, const uint numFLstPty
		) : Block() {
	this->numFLstUsg = numFLstUsg;
	this->numFLstUsr = numFLstUsr;
	this->numFLstPrs = numFLstPrs;
	this->numFLstFil = numFLstFil;
	this->numFLstOpr = numFLstOpr;
	this->numFLstPty = numFLstPty;

	mask = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS, NUMFLSTFIL, NUMFLSTOPR, NUMFLSTPTY};
};

bool PnlBrlyNavAdmin::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyNavAdmin";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsg", numFLstUsg)) add(NUMFLSTUSG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsr", numFLstUsr)) add(NUMFLSTUSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrs", numFLstPrs)) add(NUMFLSTPRS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFil", numFLstFil)) add(NUMFLSTFIL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstOpr", numFLstOpr)) add(NUMFLSTOPR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPty", numFLstPty)) add(NUMFLSTPTY);
	};

	return basefound;
};

void PnlBrlyNavAdmin::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstUsg", numFLstUsg);
		writeUintAttr(wr, itemtag, "sref", "numFLstUsr", numFLstUsr);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrs", numFLstPrs);
		writeUintAttr(wr, itemtag, "sref", "numFLstFil", numFLstFil);
		writeUintAttr(wr, itemtag, "sref", "numFLstOpr", numFLstOpr);
		writeUintAttr(wr, itemtag, "sref", "numFLstPty", numFLstPty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyNavAdmin::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstUsg == comp->numFLstUsg) insert(items, NUMFLSTUSG);
	if (numFLstUsr == comp->numFLstUsr) insert(items, NUMFLSTUSR);
	if (numFLstPrs == comp->numFLstPrs) insert(items, NUMFLSTPRS);
	if (numFLstFil == comp->numFLstFil) insert(items, NUMFLSTFIL);
	if (numFLstOpr == comp->numFLstOpr) insert(items, NUMFLSTOPR);
	if (numFLstPty == comp->numFLstPty) insert(items, NUMFLSTPTY);

	return(items);
};

set<uint> PnlBrlyNavAdmin::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS, NUMFLSTFIL, NUMFLSTOPR, NUMFLSTPTY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavAdmin::StatApp
 ******************************************************************************/

PnlBrlyNavAdmin::StatApp::StatApp(
			const uint ixBrlyVExpstate
			, const bool LstUsgAlt
			, const bool LstUsrAlt
			, const bool LstPrsAlt
			, const bool LstFilAlt
			, const bool LstOprAlt
			, const bool LstPtyAlt
			, const uint LstUsgNumFirstdisp
			, const uint LstUsrNumFirstdisp
			, const uint LstPrsNumFirstdisp
			, const uint LstFilNumFirstdisp
			, const uint LstOprNumFirstdisp
			, const uint LstPtyNumFirstdisp
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->LstUsgAlt = LstUsgAlt;
	this->LstUsrAlt = LstUsrAlt;
	this->LstPrsAlt = LstPrsAlt;
	this->LstFilAlt = LstFilAlt;
	this->LstOprAlt = LstOprAlt;
	this->LstPtyAlt = LstPtyAlt;
	this->LstUsgNumFirstdisp = LstUsgNumFirstdisp;
	this->LstUsrNumFirstdisp = LstUsrNumFirstdisp;
	this->LstPrsNumFirstdisp = LstPrsNumFirstdisp;
	this->LstFilNumFirstdisp = LstFilNumFirstdisp;
	this->LstOprNumFirstdisp = LstOprNumFirstdisp;
	this->LstPtyNumFirstdisp = LstPtyNumFirstdisp;

	mask = {IXBRLYVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTFILALT, LSTOPRALT, LSTPTYALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP, LSTFILNUMFIRSTDISP, LSTOPRNUMFIRSTDISP, LSTPTYNUMFIRSTDISP};
};

bool PnlBrlyNavAdmin::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyNavAdmin";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgAlt", LstUsgAlt)) add(LSTUSGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrAlt", LstUsrAlt)) add(LSTUSRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsAlt", LstPrsAlt)) add(LSTPRSALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilAlt", LstFilAlt)) add(LSTFILALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOprAlt", LstOprAlt)) add(LSTOPRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPtyAlt", LstPtyAlt)) add(LSTPTYALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgNumFirstdisp", LstUsgNumFirstdisp)) add(LSTUSGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrNumFirstdisp", LstUsrNumFirstdisp)) add(LSTUSRNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsNumFirstdisp", LstPrsNumFirstdisp)) add(LSTPRSNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilNumFirstdisp", LstFilNumFirstdisp)) add(LSTFILNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOprNumFirstdisp", LstOprNumFirstdisp)) add(LSTOPRNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPtyNumFirstdisp", LstPtyNumFirstdisp)) add(LSTPTYNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlBrlyNavAdmin::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (LstUsgAlt == comp->LstUsgAlt) insert(items, LSTUSGALT);
	if (LstUsrAlt == comp->LstUsrAlt) insert(items, LSTUSRALT);
	if (LstPrsAlt == comp->LstPrsAlt) insert(items, LSTPRSALT);
	if (LstFilAlt == comp->LstFilAlt) insert(items, LSTFILALT);
	if (LstOprAlt == comp->LstOprAlt) insert(items, LSTOPRALT);
	if (LstPtyAlt == comp->LstPtyAlt) insert(items, LSTPTYALT);
	if (LstUsgNumFirstdisp == comp->LstUsgNumFirstdisp) insert(items, LSTUSGNUMFIRSTDISP);
	if (LstUsrNumFirstdisp == comp->LstUsrNumFirstdisp) insert(items, LSTUSRNUMFIRSTDISP);
	if (LstPrsNumFirstdisp == comp->LstPrsNumFirstdisp) insert(items, LSTPRSNUMFIRSTDISP);
	if (LstFilNumFirstdisp == comp->LstFilNumFirstdisp) insert(items, LSTFILNUMFIRSTDISP);
	if (LstOprNumFirstdisp == comp->LstOprNumFirstdisp) insert(items, LSTOPRNUMFIRSTDISP);
	if (LstPtyNumFirstdisp == comp->LstPtyNumFirstdisp) insert(items, LSTPTYNUMFIRSTDISP);

	return(items);
};

set<uint> PnlBrlyNavAdmin::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTFILALT, LSTOPRALT, LSTPTYALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP, LSTFILNUMFIRSTDISP, LSTOPRNUMFIRSTDISP, LSTPTYNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavAdmin::StatShr
 ******************************************************************************/

PnlBrlyNavAdmin::StatShr::StatShr(
			const bool LstUsgAvail
			, const bool ButUsgViewActive
			, const bool LstUsrAvail
			, const bool ButUsrViewActive
			, const bool LstPrsAvail
			, const bool ButPrsViewActive
			, const bool LstFilAvail
			, const bool ButFilViewActive
			, const bool LstOprAvail
			, const bool ButOprViewActive
			, const bool LstPtyAvail
			, const bool ButPtyViewActive
		) : Block() {
	this->LstUsgAvail = LstUsgAvail;
	this->ButUsgViewActive = ButUsgViewActive;
	this->LstUsrAvail = LstUsrAvail;
	this->ButUsrViewActive = ButUsrViewActive;
	this->LstPrsAvail = LstPrsAvail;
	this->ButPrsViewActive = ButPrsViewActive;
	this->LstFilAvail = LstFilAvail;
	this->ButFilViewActive = ButFilViewActive;
	this->LstOprAvail = LstOprAvail;
	this->ButOprViewActive = ButOprViewActive;
	this->LstPtyAvail = LstPtyAvail;
	this->ButPtyViewActive = ButPtyViewActive;

	mask = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE, LSTOPRAVAIL, BUTOPRVIEWACTIVE, LSTPTYAVAIL, BUTPTYVIEWACTIVE};
};

bool PnlBrlyNavAdmin::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyNavAdmin";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgAvail", LstUsgAvail)) add(LSTUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsgViewActive", ButUsgViewActive)) add(BUTUSGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrAvail", LstUsrAvail)) add(LSTUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsrViewActive", ButUsrViewActive)) add(BUTUSRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsAvail", LstPrsAvail)) add(LSTPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrsViewActive", ButPrsViewActive)) add(BUTPRSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilAvail", LstFilAvail)) add(LSTFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFilViewActive", ButFilViewActive)) add(BUTFILVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOprAvail", LstOprAvail)) add(LSTOPRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOprViewActive", ButOprViewActive)) add(BUTOPRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPtyAvail", LstPtyAvail)) add(LSTPTYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPtyViewActive", ButPtyViewActive)) add(BUTPTYVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyNavAdmin::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstUsgAvail == comp->LstUsgAvail) insert(items, LSTUSGAVAIL);
	if (ButUsgViewActive == comp->ButUsgViewActive) insert(items, BUTUSGVIEWACTIVE);
	if (LstUsrAvail == comp->LstUsrAvail) insert(items, LSTUSRAVAIL);
	if (ButUsrViewActive == comp->ButUsrViewActive) insert(items, BUTUSRVIEWACTIVE);
	if (LstPrsAvail == comp->LstPrsAvail) insert(items, LSTPRSAVAIL);
	if (ButPrsViewActive == comp->ButPrsViewActive) insert(items, BUTPRSVIEWACTIVE);
	if (LstFilAvail == comp->LstFilAvail) insert(items, LSTFILAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);
	if (LstOprAvail == comp->LstOprAvail) insert(items, LSTOPRAVAIL);
	if (ButOprViewActive == comp->ButOprViewActive) insert(items, BUTOPRVIEWACTIVE);
	if (LstPtyAvail == comp->LstPtyAvail) insert(items, LSTPTYAVAIL);
	if (ButPtyViewActive == comp->ButPtyViewActive) insert(items, BUTPTYVIEWACTIVE);

	return(items);
};

set<uint> PnlBrlyNavAdmin::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE, LSTOPRAVAIL, BUTOPRVIEWACTIVE, LSTPTYAVAIL, BUTPTYVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavAdmin::Tag
 ******************************************************************************/

PnlBrlyNavAdmin::Tag::Tag(
			const string& Cpt
			, const string& CptUsg
			, const string& CptUsr
			, const string& CptPrs
			, const string& CptFil
			, const string& CptOpr
			, const string& CptPty
		) : Block() {
	this->Cpt = Cpt;
	this->CptUsg = CptUsg;
	this->CptUsr = CptUsr;
	this->CptPrs = CptPrs;
	this->CptFil = CptFil;
	this->CptOpr = CptOpr;
	this->CptPty = CptPty;

	mask = {CPT, CPTUSG, CPTUSR, CPTPRS, CPTFIL, CPTOPR, CPTPTY};
};

bool PnlBrlyNavAdmin::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyNavAdmin";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsg", CptUsg)) add(CPTUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsr", CptUsr)) add(CPTUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrs", CptPrs)) add(CPTPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFil", CptFil)) add(CPTFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOpr", CptOpr)) add(CPTOPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPty", CptPty)) add(CPTPTY);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyNavAdmin::DpchAppData
 ******************************************************************************/

PnlBrlyNavAdmin::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVADMINDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlyNavAdmin::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavAdmin::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyNavAdminData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavAdmin::DpchAppDo
 ******************************************************************************/

PnlBrlyNavAdmin::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVADMINDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyNavAdmin::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavAdmin::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyNavAdminDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavAdmin::DpchEngData
 ******************************************************************************/

PnlBrlyNavAdmin::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYNAVADMINDATA) {
	feedFLstFil.tag = "FeedFLstFil";
	feedFLstOpr.tag = "FeedFLstOpr";
	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstPty.tag = "FeedFLstPty";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";
};

string PnlBrlyNavAdmin::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFIL)) ss.push_back("feedFLstFil");
	if (has(FEEDFLSTOPR)) ss.push_back("feedFLstOpr");
	if (has(FEEDFLSTPRS)) ss.push_back("feedFLstPrs");
	if (has(FEEDFLSTPTY)) ss.push_back("feedFLstPty");
	if (has(FEEDFLSTUSG)) ss.push_back("feedFLstUsg");
	if (has(FEEDFLSTUSR)) ss.push_back("feedFLstUsr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavAdmin::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyNavAdminData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstFil.readXML(docctx, basexpath, true)) add(FEEDFLSTFIL);
		if (feedFLstOpr.readXML(docctx, basexpath, true)) add(FEEDFLSTOPR);
		if (feedFLstPrs.readXML(docctx, basexpath, true)) add(FEEDFLSTPRS);
		if (feedFLstPty.readXML(docctx, basexpath, true)) add(FEEDFLSTPTY);
		if (feedFLstUsg.readXML(docctx, basexpath, true)) add(FEEDFLSTUSG);
		if (feedFLstUsr.readXML(docctx, basexpath, true)) add(FEEDFLSTUSR);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstFil.clear();
		feedFLstOpr.clear();
		feedFLstPrs.clear();
		feedFLstPty.clear();
		feedFLstUsg.clear();
		feedFLstUsr.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

