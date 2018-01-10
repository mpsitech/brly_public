/**
  * \file PnlBrlyLegDetail_blks.cpp
  * job handler for job PnlBrlyLegDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class PnlBrlyLegDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyLegDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	else if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	else if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;

	return(0);
};

string PnlBrlyLegDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	else if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	else if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLegDetail::ContIac
 ******************************************************************************/

PnlBrlyLegDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFLstClu
			, const string& TxfAlt
			, const string& TxfDph
			, const string& TxfAph
			, const string& TxfXal
			, const string& TxfXp0
			, const string& TxfXp1
			, const string& TxfXap
			, const bool ChkCdn
		) : Block() {
	this->numFPupTyp = numFPupTyp;
	this->numFLstClu = numFLstClu;
	this->TxfAlt = TxfAlt;
	this->TxfDph = TxfDph;
	this->TxfAph = TxfAph;
	this->TxfXal = TxfXal;
	this->TxfXp0 = TxfXp0;
	this->TxfXp1 = TxfXp1;
	this->TxfXap = TxfXap;
	this->ChkCdn = ChkCdn;

	mask = {NUMFPUPTYP, NUMFLSTCLU, TXFALT, TXFDPH, TXFAPH, TXFXAL, TXFXP0, TXFXP1, TXFXAP, CHKCDN};
};

bool PnlBrlyLegDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyLegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyLegDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAlt", TxfAlt)) add(TXFALT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDph", TxfDph)) add(TXFDPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAph", TxfAph)) add(TXFAPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXal", TxfXal)) add(TXFXAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXp0", TxfXp0)) add(TXFXP0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXp1", TxfXp1)) add(TXFXP1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXap", TxfXap)) add(TXFXAP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCdn", ChkCdn)) add(CHKCDN);
	};

	return basefound;
};

void PnlBrlyLegDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyLegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyLegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeStringAttr(wr, itemtag, "sref", "TxfAlt", TxfAlt);
		writeStringAttr(wr, itemtag, "sref", "TxfDph", TxfDph);
		writeStringAttr(wr, itemtag, "sref", "TxfAph", TxfAph);
		writeStringAttr(wr, itemtag, "sref", "TxfXal", TxfXal);
		writeStringAttr(wr, itemtag, "sref", "TxfXp0", TxfXp0);
		writeStringAttr(wr, itemtag, "sref", "TxfXp1", TxfXp1);
		writeStringAttr(wr, itemtag, "sref", "TxfXap", TxfXap);
		writeBoolAttr(wr, itemtag, "sref", "ChkCdn", ChkCdn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (TxfAlt == comp->TxfAlt) insert(items, TXFALT);
	if (TxfDph == comp->TxfDph) insert(items, TXFDPH);
	if (TxfAph == comp->TxfAph) insert(items, TXFAPH);
	if (TxfXal == comp->TxfXal) insert(items, TXFXAL);
	if (TxfXp0 == comp->TxfXp0) insert(items, TXFXP0);
	if (TxfXp1 == comp->TxfXp1) insert(items, TXFXP1);
	if (TxfXap == comp->TxfXap) insert(items, TXFXAP);
	if (ChkCdn == comp->ChkCdn) insert(items, CHKCDN);

	return(items);
};

set<uint> PnlBrlyLegDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFLSTCLU, TXFALT, TXFDPH, TXFAPH, TXFXAL, TXFXP0, TXFXP1, TXFXAP, CHKCDN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegDetail::ContInf
 ******************************************************************************/

PnlBrlyLegDetail::ContInf::ContInf(
			const string& TxtBlo
			, const string& TxtElo
			, const string& TxtClu
		) : Block() {
	this->TxtBlo = TxtBlo;
	this->TxtElo = TxtElo;
	this->TxtClu = TxtClu;

	mask = {TXTBLO, TXTELO, TXTCLU};
};

void PnlBrlyLegDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyLegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtBlo", TxtBlo);
		writeStringAttr(wr, itemtag, "sref", "TxtElo", TxtElo);
		writeStringAttr(wr, itemtag, "sref", "TxtClu", TxtClu);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtBlo == comp->TxtBlo) insert(items, TXTBLO);
	if (TxtElo == comp->TxtElo) insert(items, TXTELO);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);

	return(items);
};

set<uint> PnlBrlyLegDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTBLO, TXTELO, TXTCLU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegDetail::StatApp
 ******************************************************************************/

void PnlBrlyLegDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
			, const bool LstCluAlt
			, const uint LstCluNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyLegDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyLegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCluAlt", LstCluAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegDetail::StatShr
 ******************************************************************************/

PnlBrlyLegDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtBloActive
			, const bool TxtEloActive
			, const bool PupTypActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxfAltActive
			, const bool TxfDphActive
			, const bool TxfAphActive
			, const bool TxfXalActive
			, const bool TxfXp0Active
			, const bool TxfXp1Active
			, const bool TxfXapActive
			, const bool ChkCdnActive
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtBloActive = TxtBloActive;
	this->TxtEloActive = TxtEloActive;
	this->PupTypActive = PupTypActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxfAltActive = TxfAltActive;
	this->TxfDphActive = TxfDphActive;
	this->TxfAphActive = TxfAphActive;
	this->TxfXalActive = TxfXalActive;
	this->TxfXp0Active = TxfXp0Active;
	this->TxfXp1Active = TxfXp1Active;
	this->TxfXapActive = TxfXapActive;
	this->ChkCdnActive = ChkCdnActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTBLOACTIVE, TXTELOACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXFALTACTIVE, TXFDPHACTIVE, TXFAPHACTIVE, TXFXALACTIVE, TXFXP0ACTIVE, TXFXP1ACTIVE, TXFXAPACTIVE, CHKCDNACTIVE};
};

void PnlBrlyLegDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLegDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyLegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtBloActive", TxtBloActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtEloActive", TxtEloActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCluActive", LstCluActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluViewActive", ButCluViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluClusterAvail", ButCluClusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfAltActive", TxfAltActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfDphActive", TxfDphActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfAphActive", TxfAphActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfXalActive", TxfXalActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfXp0Active", TxfXp0Active);
		writeBoolAttr(wr, itemtag, "sref", "TxfXp1Active", TxfXp1Active);
		writeBoolAttr(wr, itemtag, "sref", "TxfXapActive", TxfXapActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkCdnActive", ChkCdnActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtBloActive == comp->TxtBloActive) insert(items, TXTBLOACTIVE);
	if (TxtEloActive == comp->TxtEloActive) insert(items, TXTELOACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxfAltActive == comp->TxfAltActive) insert(items, TXFALTACTIVE);
	if (TxfDphActive == comp->TxfDphActive) insert(items, TXFDPHACTIVE);
	if (TxfAphActive == comp->TxfAphActive) insert(items, TXFAPHACTIVE);
	if (TxfXalActive == comp->TxfXalActive) insert(items, TXFXALACTIVE);
	if (TxfXp0Active == comp->TxfXp0Active) insert(items, TXFXP0ACTIVE);
	if (TxfXp1Active == comp->TxfXp1Active) insert(items, TXFXP1ACTIVE);
	if (TxfXapActive == comp->TxfXapActive) insert(items, TXFXAPACTIVE);
	if (ChkCdnActive == comp->ChkCdnActive) insert(items, CHKCDNACTIVE);

	return(items);
};

set<uint> PnlBrlyLegDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTBLOACTIVE, TXTELOACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXFALTACTIVE, TXFDPHACTIVE, TXFAPHACTIVE, TXFXALACTIVE, TXFXP0ACTIVE, TXFXP1ACTIVE, TXFXAPACTIVE, CHKCDNACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegDetail::Tag
 ******************************************************************************/

void PnlBrlyLegDetail::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyLegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptBlo", "begin location");
			writeStringAttr(wr, itemtag, "sref", "CptElo", "end location");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptAlt", "altitude [m]");
			writeStringAttr(wr, itemtag, "sref", "CptDph", "angular distance [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptAph", "opening angle [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptXal", "xAlt");
			writeStringAttr(wr, itemtag, "sref", "CptXp0", "xPhi0");
			writeStringAttr(wr, itemtag, "sref", "CptXp1", "xPhi1");
			writeStringAttr(wr, itemtag, "sref", "CptXap", "xAlpha");
			writeStringAttr(wr, itemtag, "sref", "CptCdn", "calculated");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptBlo", "Beginn");
			writeStringAttr(wr, itemtag, "sref", "CptElo", "Ende");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptAlt", "H\\u00f6he [m]");
			writeStringAttr(wr, itemtag, "sref", "CptDph", "Winkelabstand [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptAph", "\\u00d6ffnungswinkel [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptXal", "xAlt");
			writeStringAttr(wr, itemtag, "sref", "CptXp0", "xPhi0");
			writeStringAttr(wr, itemtag, "sref", "CptXp1", "xPhi1");
			writeStringAttr(wr, itemtag, "sref", "CptXap", "xAlpha");
			writeStringAttr(wr, itemtag, "sref", "CptCdn", "berechnet");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptClu", VecBrlyVTag::getTitle(VecBrlyVTag::CLUST, ixBrlyVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegDetail::DpchAppData
 ******************************************************************************/

PnlBrlyLegDetail::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGDETAILDATA) {
};

string PnlBrlyLegDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLegDetailData");
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
 class PnlBrlyLegDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyLegDetail::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGDETAILDO) {
	ixVDo = 0;
};

string PnlBrlyLegDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLegDetailDo");
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
 class PnlBrlyLegDetail::DpchEngData
 ******************************************************************************/

PnlBrlyLegDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstClu
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTCLU, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTCLU) && feedFLstClu) this->feedFLstClu = *feedFLstClu;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyLegDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegDetail::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTCLU)) {feedFLstClu = src->feedFLstClu; add(FEEDFLSTCLU);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyLegDetail::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLegDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTCLU)) feedFLstClu.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

