/**
  * \file PnlBrlyLocDetail.cpp
  * API code for job PnlBrlyLocDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyLocDetail.h"

/******************************************************************************
 class PnlBrlyLocDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyLocDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "buteqpnewclick") return BUTEQPNEWCLICK;
	else if (s == "buteqpdeleteclick") return BUTEQPDELETECLICK;
	else if (s == "buteqpoprviewclick") return BUTEQPOPRVIEWCLICK;
	else if (s == "buteqpptyviewclick") return BUTEQPPTYVIEWCLICK;
	else if (s == "buteqpetyeditclick") return BUTEQPETYEDITCLICK;

	return(0);
};

string PnlBrlyLocDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTEQPNEWCLICK) return("ButEqpNewClick");
	else if (ix == BUTEQPDELETECLICK) return("ButEqpDeleteClick");
	else if (ix == BUTEQPOPRVIEWCLICK) return("ButEqpOprViewClick");
	else if (ix == BUTEQPPTYVIEWCLICK) return("ButEqpPtyViewClick");
	else if (ix == BUTEQPETYEDITCLICK) return("ButEqpEtyEditClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLocDetail::ContIac
 ******************************************************************************/

PnlBrlyLocDetail::ContIac::ContIac(
			const string& TxfIca
			, const string& TxfTit
			, const uint numFPupTyp
			, const string& TxfAlt
			, const string& TxfThe
			, const string& TxfPhi
			, const string& TxfTz
			, const string& TxfAph
			, const bool ChkCdn
			, const uint numFPupEqpEty
			, const string& TxfEqpEty
			, const bool ChkEqpFib
		) : Block() {
	this->TxfIca = TxfIca;
	this->TxfTit = TxfTit;
	this->numFPupTyp = numFPupTyp;
	this->TxfAlt = TxfAlt;
	this->TxfThe = TxfThe;
	this->TxfPhi = TxfPhi;
	this->TxfTz = TxfTz;
	this->TxfAph = TxfAph;
	this->ChkCdn = ChkCdn;
	this->numFPupEqpEty = numFPupEqpEty;
	this->TxfEqpEty = TxfEqpEty;
	this->ChkEqpFib = ChkEqpFib;

	mask = {TXFICA, TXFTIT, NUMFPUPTYP, TXFALT, TXFTHE, TXFPHI, TXFTZ, TXFAPH, CHKCDN, NUMFPUPEQPETY, TXFEQPETY, CHKEQPFIB};
};

bool PnlBrlyLocDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyLocDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyLocDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfIca", TxfIca)) add(TXFICA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAlt", TxfAlt)) add(TXFALT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfThe", TxfThe)) add(TXFTHE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPhi", TxfPhi)) add(TXFPHI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTz", TxfTz)) add(TXFTZ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAph", TxfAph)) add(TXFAPH);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCdn", ChkCdn)) add(CHKCDN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupEqpEty", numFPupEqpEty)) add(NUMFPUPEQPETY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEqpEty", TxfEqpEty)) add(TXFEQPETY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkEqpFib", ChkEqpFib)) add(CHKEQPFIB);
	};

	return basefound;
};

void PnlBrlyLocDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyLocDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyLocDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfIca", TxfIca);
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfAlt", TxfAlt);
		writeStringAttr(wr, itemtag, "sref", "TxfThe", TxfThe);
		writeStringAttr(wr, itemtag, "sref", "TxfPhi", TxfPhi);
		writeStringAttr(wr, itemtag, "sref", "TxfTz", TxfTz);
		writeStringAttr(wr, itemtag, "sref", "TxfAph", TxfAph);
		writeBoolAttr(wr, itemtag, "sref", "ChkCdn", ChkCdn);
		writeUintAttr(wr, itemtag, "sref", "numFPupEqpEty", numFPupEqpEty);
		writeStringAttr(wr, itemtag, "sref", "TxfEqpEty", TxfEqpEty);
		writeBoolAttr(wr, itemtag, "sref", "ChkEqpFib", ChkEqpFib);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfIca.compare(comp->TxfIca) == 0) insert(items, TXFICA);
	if (TxfTit.compare(comp->TxfTit) == 0) insert(items, TXFTIT);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfAlt.compare(comp->TxfAlt) == 0) insert(items, TXFALT);
	if (TxfThe.compare(comp->TxfThe) == 0) insert(items, TXFTHE);
	if (TxfPhi.compare(comp->TxfPhi) == 0) insert(items, TXFPHI);
	if (TxfTz.compare(comp->TxfTz) == 0) insert(items, TXFTZ);
	if (TxfAph.compare(comp->TxfAph) == 0) insert(items, TXFAPH);
	if (ChkCdn == comp->ChkCdn) insert(items, CHKCDN);
	if (numFPupEqpEty == comp->numFPupEqpEty) insert(items, NUMFPUPEQPETY);
	if (TxfEqpEty.compare(comp->TxfEqpEty) == 0) insert(items, TXFEQPETY);
	if (ChkEqpFib == comp->ChkEqpFib) insert(items, CHKEQPFIB);

	return(items);
};

set<uint> PnlBrlyLocDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFICA, TXFTIT, NUMFPUPTYP, TXFALT, TXFTHE, TXFPHI, TXFTZ, TXFAPH, CHKCDN, NUMFPUPEQPETY, TXFEQPETY, CHKEQPFIB};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocDetail::ContInf
 ******************************************************************************/

PnlBrlyLocDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtReg
			, const string& TxtEqpOpr
			, const string& TxtEqpPty
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtReg = TxtReg;
	this->TxtEqpOpr = TxtEqpOpr;
	this->TxtEqpPty = TxtEqpPty;

	mask = {TXTSRF, TXTREG, TXTEQPOPR, TXTEQPPTY};
};

bool PnlBrlyLocDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyLocDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyLocDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReg", TxtReg)) add(TXTREG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtEqpOpr", TxtEqpOpr)) add(TXTEQPOPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtEqpPty", TxtEqpPty)) add(TXTEQPPTY);
	};

	return basefound;
};

set<uint> PnlBrlyLocDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtReg.compare(comp->TxtReg) == 0) insert(items, TXTREG);
	if (TxtEqpOpr.compare(comp->TxtEqpOpr) == 0) insert(items, TXTEQPOPR);
	if (TxtEqpPty.compare(comp->TxtEqpPty) == 0) insert(items, TXTEQPPTY);

	return(items);
};

set<uint> PnlBrlyLocDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTREG, TXTEQPOPR, TXTEQPPTY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocDetail::StatApp
 ******************************************************************************/

PnlBrlyLocDetail::StatApp::StatApp(
			const uint ixBrlyVExpstate
			, const bool PupEqpEtyAlt
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->PupEqpEtyAlt = PupEqpEtyAlt;

	mask = {IXBRLYVEXPSTATE, PUPEQPETYALT};
};

bool PnlBrlyLocDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyLocDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyLocDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupEqpEtyAlt", PupEqpEtyAlt)) add(PUPEQPETYALT);
	};

	return basefound;
};

set<uint> PnlBrlyLocDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (PupEqpEtyAlt == comp->PupEqpEtyAlt) insert(items, PUPEQPETYALT);

	return(items);
};

set<uint> PnlBrlyLocDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, PUPEQPETYALT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocDetail::StatShr
 ******************************************************************************/

PnlBrlyLocDetail::StatShr::StatShr(
			const bool TxfEqpEtyValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfIcaActive
			, const bool TxfTitActive
			, const bool PupTypActive
			, const bool TxtRegActive
			, const bool TxfAltActive
			, const bool TxfTheActive
			, const bool TxfPhiActive
			, const bool TxfTzActive
			, const bool TxfAphActive
			, const bool ChkCdnActive
			, const bool ButEqpNewAvail
			, const bool ButEqpDeleteAvail
			, const bool TxtEqpOprAvail
			, const bool TxtEqpOprActive
			, const bool ButEqpOprViewAvail
			, const bool ButEqpOprViewActive
			, const bool TxtEqpPtyAvail
			, const bool TxtEqpPtyActive
			, const bool ButEqpPtyViewAvail
			, const bool ButEqpPtyViewActive
			, const bool PupEqpEtyAvail
			, const bool PupEqpEtyActive
			, const bool ButEqpEtyEditAvail
			, const bool ChkEqpFibAvail
			, const bool ChkEqpFibActive
		) : Block() {
	this->TxfEqpEtyValid = TxfEqpEtyValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfIcaActive = TxfIcaActive;
	this->TxfTitActive = TxfTitActive;
	this->PupTypActive = PupTypActive;
	this->TxtRegActive = TxtRegActive;
	this->TxfAltActive = TxfAltActive;
	this->TxfTheActive = TxfTheActive;
	this->TxfPhiActive = TxfPhiActive;
	this->TxfTzActive = TxfTzActive;
	this->TxfAphActive = TxfAphActive;
	this->ChkCdnActive = ChkCdnActive;
	this->ButEqpNewAvail = ButEqpNewAvail;
	this->ButEqpDeleteAvail = ButEqpDeleteAvail;
	this->TxtEqpOprAvail = TxtEqpOprAvail;
	this->TxtEqpOprActive = TxtEqpOprActive;
	this->ButEqpOprViewAvail = ButEqpOprViewAvail;
	this->ButEqpOprViewActive = ButEqpOprViewActive;
	this->TxtEqpPtyAvail = TxtEqpPtyAvail;
	this->TxtEqpPtyActive = TxtEqpPtyActive;
	this->ButEqpPtyViewAvail = ButEqpPtyViewAvail;
	this->ButEqpPtyViewActive = ButEqpPtyViewActive;
	this->PupEqpEtyAvail = PupEqpEtyAvail;
	this->PupEqpEtyActive = PupEqpEtyActive;
	this->ButEqpEtyEditAvail = ButEqpEtyEditAvail;
	this->ChkEqpFibAvail = ChkEqpFibAvail;
	this->ChkEqpFibActive = ChkEqpFibActive;

	mask = {TXFEQPETYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFICAACTIVE, TXFTITACTIVE, PUPTYPACTIVE, TXTREGACTIVE, TXFALTACTIVE, TXFTHEACTIVE, TXFPHIACTIVE, TXFTZACTIVE, TXFAPHACTIVE, CHKCDNACTIVE, BUTEQPNEWAVAIL, BUTEQPDELETEAVAIL, TXTEQPOPRAVAIL, TXTEQPOPRACTIVE, BUTEQPOPRVIEWAVAIL, BUTEQPOPRVIEWACTIVE, TXTEQPPTYAVAIL, TXTEQPPTYACTIVE, BUTEQPPTYVIEWAVAIL, BUTEQPPTYVIEWACTIVE, PUPEQPETYAVAIL, PUPEQPETYACTIVE, BUTEQPETYEDITAVAIL, CHKEQPFIBAVAIL, CHKEQPFIBACTIVE};
};

bool PnlBrlyLocDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyLocDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyLocDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfEqpEtyValid", TxfEqpEtyValid)) add(TXFEQPETYVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfIcaActive", TxfIcaActive)) add(TXFICAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTitActive", TxfTitActive)) add(TXFTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtRegActive", TxtRegActive)) add(TXTREGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAltActive", TxfAltActive)) add(TXFALTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTheActive", TxfTheActive)) add(TXFTHEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPhiActive", TxfPhiActive)) add(TXFPHIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTzActive", TxfTzActive)) add(TXFTZACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAphActive", TxfAphActive)) add(TXFAPHACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkCdnActive", ChkCdnActive)) add(CHKCDNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpNewAvail", ButEqpNewAvail)) add(BUTEQPNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpDeleteAvail", ButEqpDeleteAvail)) add(BUTEQPDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEqpOprAvail", TxtEqpOprAvail)) add(TXTEQPOPRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEqpOprActive", TxtEqpOprActive)) add(TXTEQPOPRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpOprViewAvail", ButEqpOprViewAvail)) add(BUTEQPOPRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpOprViewActive", ButEqpOprViewActive)) add(BUTEQPOPRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEqpPtyAvail", TxtEqpPtyAvail)) add(TXTEQPPTYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEqpPtyActive", TxtEqpPtyActive)) add(TXTEQPPTYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpPtyViewAvail", ButEqpPtyViewAvail)) add(BUTEQPPTYVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpPtyViewActive", ButEqpPtyViewActive)) add(BUTEQPPTYVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupEqpEtyAvail", PupEqpEtyAvail)) add(PUPEQPETYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupEqpEtyActive", PupEqpEtyActive)) add(PUPEQPETYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpEtyEditAvail", ButEqpEtyEditAvail)) add(BUTEQPETYEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkEqpFibAvail", ChkEqpFibAvail)) add(CHKEQPFIBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkEqpFibActive", ChkEqpFibActive)) add(CHKEQPFIBACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyLocDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfEqpEtyValid == comp->TxfEqpEtyValid) insert(items, TXFEQPETYVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfIcaActive == comp->TxfIcaActive) insert(items, TXFICAACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtRegActive == comp->TxtRegActive) insert(items, TXTREGACTIVE);
	if (TxfAltActive == comp->TxfAltActive) insert(items, TXFALTACTIVE);
	if (TxfTheActive == comp->TxfTheActive) insert(items, TXFTHEACTIVE);
	if (TxfPhiActive == comp->TxfPhiActive) insert(items, TXFPHIACTIVE);
	if (TxfTzActive == comp->TxfTzActive) insert(items, TXFTZACTIVE);
	if (TxfAphActive == comp->TxfAphActive) insert(items, TXFAPHACTIVE);
	if (ChkCdnActive == comp->ChkCdnActive) insert(items, CHKCDNACTIVE);
	if (ButEqpNewAvail == comp->ButEqpNewAvail) insert(items, BUTEQPNEWAVAIL);
	if (ButEqpDeleteAvail == comp->ButEqpDeleteAvail) insert(items, BUTEQPDELETEAVAIL);
	if (TxtEqpOprAvail == comp->TxtEqpOprAvail) insert(items, TXTEQPOPRAVAIL);
	if (TxtEqpOprActive == comp->TxtEqpOprActive) insert(items, TXTEQPOPRACTIVE);
	if (ButEqpOprViewAvail == comp->ButEqpOprViewAvail) insert(items, BUTEQPOPRVIEWAVAIL);
	if (ButEqpOprViewActive == comp->ButEqpOprViewActive) insert(items, BUTEQPOPRVIEWACTIVE);
	if (TxtEqpPtyAvail == comp->TxtEqpPtyAvail) insert(items, TXTEQPPTYAVAIL);
	if (TxtEqpPtyActive == comp->TxtEqpPtyActive) insert(items, TXTEQPPTYACTIVE);
	if (ButEqpPtyViewAvail == comp->ButEqpPtyViewAvail) insert(items, BUTEQPPTYVIEWAVAIL);
	if (ButEqpPtyViewActive == comp->ButEqpPtyViewActive) insert(items, BUTEQPPTYVIEWACTIVE);
	if (PupEqpEtyAvail == comp->PupEqpEtyAvail) insert(items, PUPEQPETYAVAIL);
	if (PupEqpEtyActive == comp->PupEqpEtyActive) insert(items, PUPEQPETYACTIVE);
	if (ButEqpEtyEditAvail == comp->ButEqpEtyEditAvail) insert(items, BUTEQPETYEDITAVAIL);
	if (ChkEqpFibAvail == comp->ChkEqpFibAvail) insert(items, CHKEQPFIBAVAIL);
	if (ChkEqpFibActive == comp->ChkEqpFibActive) insert(items, CHKEQPFIBACTIVE);

	return(items);
};

set<uint> PnlBrlyLocDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFEQPETYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFICAACTIVE, TXFTITACTIVE, PUPTYPACTIVE, TXTREGACTIVE, TXFALTACTIVE, TXFTHEACTIVE, TXFPHIACTIVE, TXFTZACTIVE, TXFAPHACTIVE, CHKCDNACTIVE, BUTEQPNEWAVAIL, BUTEQPDELETEAVAIL, TXTEQPOPRAVAIL, TXTEQPOPRACTIVE, BUTEQPOPRVIEWAVAIL, BUTEQPOPRVIEWACTIVE, TXTEQPPTYAVAIL, TXTEQPPTYACTIVE, BUTEQPPTYVIEWAVAIL, BUTEQPPTYVIEWACTIVE, PUPEQPETYAVAIL, PUPEQPETYACTIVE, BUTEQPETYEDITAVAIL, CHKEQPFIBAVAIL, CHKEQPFIBACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocDetail::Tag
 ******************************************************************************/

PnlBrlyLocDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptIca
			, const string& CptTit
			, const string& CptTyp
			, const string& CptReg
			, const string& CptAlt
			, const string& CptThe
			, const string& CptPhi
			, const string& CptTz
			, const string& CptAph
			, const string& CptCdn
			, const string& HdgEqp
			, const string& CptEqpOpr
			, const string& CptEqpPty
			, const string& CptEqpEty
			, const string& CptEqpFib
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptIca = CptIca;
	this->CptTit = CptTit;
	this->CptTyp = CptTyp;
	this->CptReg = CptReg;
	this->CptAlt = CptAlt;
	this->CptThe = CptThe;
	this->CptPhi = CptPhi;
	this->CptTz = CptTz;
	this->CptAph = CptAph;
	this->CptCdn = CptCdn;
	this->HdgEqp = HdgEqp;
	this->CptEqpOpr = CptEqpOpr;
	this->CptEqpPty = CptEqpPty;
	this->CptEqpEty = CptEqpEty;
	this->CptEqpFib = CptEqpFib;

	mask = {CPT, CPTSRF, CPTICA, CPTTIT, CPTTYP, CPTREG, CPTALT, CPTTHE, CPTPHI, CPTTZ, CPTAPH, CPTCDN, HDGEQP, CPTEQPOPR, CPTEQPPTY, CPTEQPETY, CPTEQPFIB};
};

bool PnlBrlyLocDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyLocDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyLocDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIca", CptIca)) add(CPTICA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReg", CptReg)) add(CPTREG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAlt", CptAlt)) add(CPTALT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptThe", CptThe)) add(CPTTHE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPhi", CptPhi)) add(CPTPHI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTz", CptTz)) add(CPTTZ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAph", CptAph)) add(CPTAPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCdn", CptCdn)) add(CPTCDN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgEqp", HdgEqp)) add(HDGEQP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEqpOpr", CptEqpOpr)) add(CPTEQPOPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEqpPty", CptEqpPty)) add(CPTEQPPTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEqpEty", CptEqpEty)) add(CPTEQPETY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEqpFib", CptEqpFib)) add(CPTEQPFIB);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyLocDetail::DpchAppData
 ******************************************************************************/

PnlBrlyLocDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlyLocDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLocDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyLocDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyLocDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyLocDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocDetail::DpchEngData
 ******************************************************************************/

PnlBrlyLocDetail::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCDETAILDATA) {
	feedFPupEqpEty.tag = "FeedFPupEqpEty";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlBrlyLocDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPEQPETY)) ss.push_back("feedFPupEqpEty");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyLocDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupEqpEty.readXML(docctx, basexpath, true)) add(FEEDFPUPEQPETY);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupEqpEty.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

