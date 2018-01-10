/**
  * \file PnlBrlyLocDetail_blks.cpp
  * job handler for job PnlBrlyLocDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

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

	if (TxfIca == comp->TxfIca) insert(items, TXFICA);
	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfAlt == comp->TxfAlt) insert(items, TXFALT);
	if (TxfThe == comp->TxfThe) insert(items, TXFTHE);
	if (TxfPhi == comp->TxfPhi) insert(items, TXFPHI);
	if (TxfTz == comp->TxfTz) insert(items, TXFTZ);
	if (TxfAph == comp->TxfAph) insert(items, TXFAPH);
	if (ChkCdn == comp->ChkCdn) insert(items, CHKCDN);
	if (numFPupEqpEty == comp->numFPupEqpEty) insert(items, NUMFPUPEQPETY);
	if (TxfEqpEty == comp->TxfEqpEty) insert(items, TXFEQPETY);
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

void PnlBrlyLocDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLocDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyLocDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtReg", TxtReg);
		writeStringAttr(wr, itemtag, "sref", "TxtEqpOpr", TxtEqpOpr);
		writeStringAttr(wr, itemtag, "sref", "TxtEqpPty", TxtEqpPty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtReg == comp->TxtReg) insert(items, TXTREG);
	if (TxtEqpOpr == comp->TxtEqpOpr) insert(items, TXTEQPOPR);
	if (TxtEqpPty == comp->TxtEqpPty) insert(items, TXTEQPPTY);

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

void PnlBrlyLocDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
			, const bool PupEqpEtyAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyLocDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyLocDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupEqpEtyAlt", PupEqpEtyAlt);
	xmlTextWriterEndElement(wr);
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

void PnlBrlyLocDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLocDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyLocDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfEqpEtyValid", TxfEqpEtyValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfIcaActive", TxfIcaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTitActive", TxfTitActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtRegActive", TxtRegActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfAltActive", TxfAltActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTheActive", TxfTheActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfPhiActive", TxfPhiActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTzActive", TxfTzActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfAphActive", TxfAphActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkCdnActive", ChkCdnActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpNewAvail", ButEqpNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpDeleteAvail", ButEqpDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtEqpOprAvail", TxtEqpOprAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtEqpOprActive", TxtEqpOprActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpOprViewAvail", ButEqpOprViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpOprViewActive", ButEqpOprViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtEqpPtyAvail", TxtEqpPtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtEqpPtyActive", TxtEqpPtyActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpPtyViewAvail", ButEqpPtyViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpPtyViewActive", ButEqpPtyViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupEqpEtyAvail", PupEqpEtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupEqpEtyActive", PupEqpEtyActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpEtyEditAvail", ButEqpEtyEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "ChkEqpFibAvail", ChkEqpFibAvail);
		writeBoolAttr(wr, itemtag, "sref", "ChkEqpFibActive", ChkEqpFibActive);
	xmlTextWriterEndElement(wr);
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

void PnlBrlyLocDetail::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLocDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyLocDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptIca", "ICAO identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptReg", "region");
			writeStringAttr(wr, itemtag, "sref", "CptAlt", "elevation [m]");
			writeStringAttr(wr, itemtag, "sref", "CptThe", "latitude [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptPhi", "longitude [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptTz", "tz database code");
			writeStringAttr(wr, itemtag, "sref", "CptAph", "opening angle [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptCdn", "calculated");
			writeStringAttr(wr, itemtag, "sref", "HdgEqp", "Equipment");
			writeStringAttr(wr, itemtag, "sref", "CptEqpOpr", "operator");
			writeStringAttr(wr, itemtag, "sref", "CptEqpPty", "plane type");
			writeStringAttr(wr, itemtag, "sref", "CptEqpEty", "equipment type");
			writeStringAttr(wr, itemtag, "sref", "CptEqpFib", "Fiber");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "Bezeichner");
			writeStringAttr(wr, itemtag, "sref", "CptIca", "ICAO Bezeichner");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptReg", "Region");
			writeStringAttr(wr, itemtag, "sref", "CptAlt", "H\\u00f6he [m]");
			writeStringAttr(wr, itemtag, "sref", "CptThe", "Breite [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptPhi", "L\\u00e4nge [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptTz", "Code in tz-Datenbank");
			writeStringAttr(wr, itemtag, "sref", "CptAph", "\\u00d6ffnungswinkel [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptCdn", "berechnet");
			writeStringAttr(wr, itemtag, "sref", "HdgEqp", "Ger\\u00e4t");
			writeStringAttr(wr, itemtag, "sref", "CptEqpOpr", "Betreiber");
			writeStringAttr(wr, itemtag, "sref", "CptEqpPty", "Flugzeugtyp");
			writeStringAttr(wr, itemtag, "sref", "CptEqpEty", "Ger\\u00e4tetyp");
			writeStringAttr(wr, itemtag, "sref", "CptEqpFib", "Fiber");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocDetail::DpchAppData
 ******************************************************************************/

PnlBrlyLocDetail::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCDETAILDATA) {
};

string PnlBrlyLocDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLocDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlBrlyLocDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyLocDetail::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCDETAILDO) {
	ixVDo = 0;
};

string PnlBrlyLocDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocDetail::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLocDetailDo");
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
	} else {
	};
};

/******************************************************************************
 class PnlBrlyLocDetail::DpchEngData
 ******************************************************************************/

PnlBrlyLocDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupEqpEty
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPEQPETY, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPEQPETY) && feedFPupEqpEty) this->feedFPupEqpEty = *feedFPupEqpEty;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyLocDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlBrlyLocDetail::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPEQPETY)) {feedFPupEqpEty = src->feedFPupEqpEty; add(FEEDFPUPEQPETY);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyLocDetail::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLocDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPEQPETY)) feedFPupEqpEty.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

