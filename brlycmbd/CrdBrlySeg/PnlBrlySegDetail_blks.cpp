/**
  * \file PnlBrlySegDetail_blks.cpp
  * job handler for job PnlBrlySegDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class PnlBrlySegDetail::VecVDo
 ******************************************************************************/

uint PnlBrlySegDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butreuviewclick") return BUTREUVIEWCLICK;

	return(0);
};

string PnlBrlySegDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");

	return("");
};

/******************************************************************************
 class PnlBrlySegDetail::ContIac
 ******************************************************************************/

PnlBrlySegDetail::ContIac::ContIac(
			const uint numFPupRet
			, const string& TxfDph
			, const string& TxfAl0
			, const string& TxfAl1
			, const string& TxfTh0
			, const string& TxfTh1
			, const string& TxfPh0
			, const string& TxfPh1
			, const string& TxfSta
			, const string& TxfSto
			, const bool ChkCdn
		) : Block() {
	this->numFPupRet = numFPupRet;
	this->TxfDph = TxfDph;
	this->TxfAl0 = TxfAl0;
	this->TxfAl1 = TxfAl1;
	this->TxfTh0 = TxfTh0;
	this->TxfTh1 = TxfTh1;
	this->TxfPh0 = TxfPh0;
	this->TxfPh1 = TxfPh1;
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->ChkCdn = ChkCdn;

	mask = {NUMFPUPRET, TXFDPH, TXFAL0, TXFAL1, TXFTH0, TXFTH1, TXFPH0, TXFPH1, TXFSTA, TXFSTO, CHKCDN};
};

bool PnlBrlySegDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlySegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlySegDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDph", TxfDph)) add(TXFDPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAl0", TxfAl0)) add(TXFAL0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAl1", TxfAl1)) add(TXFAL1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTh0", TxfTh0)) add(TXFTH0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTh1", TxfTh1)) add(TXFTH1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPh0", TxfPh0)) add(TXFPH0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPh1", TxfPh1)) add(TXFPH1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCdn", ChkCdn)) add(CHKCDN);
	};

	return basefound;
};

void PnlBrlySegDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlySegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlySegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeStringAttr(wr, itemtag, "sref", "TxfDph", TxfDph);
		writeStringAttr(wr, itemtag, "sref", "TxfAl0", TxfAl0);
		writeStringAttr(wr, itemtag, "sref", "TxfAl1", TxfAl1);
		writeStringAttr(wr, itemtag, "sref", "TxfTh0", TxfTh0);
		writeStringAttr(wr, itemtag, "sref", "TxfTh1", TxfTh1);
		writeStringAttr(wr, itemtag, "sref", "TxfPh0", TxfPh0);
		writeStringAttr(wr, itemtag, "sref", "TxfPh1", TxfPh1);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeBoolAttr(wr, itemtag, "sref", "ChkCdn", ChkCdn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (TxfDph == comp->TxfDph) insert(items, TXFDPH);
	if (TxfAl0 == comp->TxfAl0) insert(items, TXFAL0);
	if (TxfAl1 == comp->TxfAl1) insert(items, TXFAL1);
	if (TxfTh0 == comp->TxfTh0) insert(items, TXFTH0);
	if (TxfTh1 == comp->TxfTh1) insert(items, TXFTH1);
	if (TxfPh0 == comp->TxfPh0) insert(items, TXFPH0);
	if (TxfPh1 == comp->TxfPh1) insert(items, TXFPH1);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (ChkCdn == comp->ChkCdn) insert(items, CHKCDN);

	return(items);
};

set<uint> PnlBrlySegDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPRET, TXFDPH, TXFAL0, TXFAL1, TXFTH0, TXFTH1, TXFPH0, TXFPH1, TXFSTA, TXFSTO, CHKCDN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegDetail::ContInf
 ******************************************************************************/

PnlBrlySegDetail::ContInf::ContInf(
			const string& TxtReu
		) : Block() {
	this->TxtReu = TxtReu;

	mask = {TXTREU};
};

void PnlBrlySegDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlySegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlySegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtReu", TxtReu);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtReu == comp->TxtReu) insert(items, TXTREU);

	return(items);
};

set<uint> PnlBrlySegDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegDetail::StatApp
 ******************************************************************************/

void PnlBrlySegDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlySegDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlySegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlySegDetail::StatShr
 ******************************************************************************/

PnlBrlySegDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool TxfDphActive
			, const bool TxfAl0Active
			, const bool TxfAl1Active
			, const bool TxfTh0Active
			, const bool TxfTh1Active
			, const bool TxfPh0Active
			, const bool TxfPh1Active
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool ChkCdnActive
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->TxfDphActive = TxfDphActive;
	this->TxfAl0Active = TxfAl0Active;
	this->TxfAl1Active = TxfAl1Active;
	this->TxfTh0Active = TxfTh0Active;
	this->TxfTh1Active = TxfTh1Active;
	this->TxfPh0Active = TxfPh0Active;
	this->TxfPh1Active = TxfPh1Active;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->ChkCdnActive = ChkCdnActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXFDPHACTIVE, TXFAL0ACTIVE, TXFAL1ACTIVE, TXFTH0ACTIVE, TXFTH1ACTIVE, TXFPH0ACTIVE, TXFPH1ACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, CHKCDNACTIVE};
};

void PnlBrlySegDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlySegDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlySegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtReuActive", TxtReuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewAvail", ButReuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewActive", ButReuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfDphActive", TxfDphActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfAl0Active", TxfAl0Active);
		writeBoolAttr(wr, itemtag, "sref", "TxfAl1Active", TxfAl1Active);
		writeBoolAttr(wr, itemtag, "sref", "TxfTh0Active", TxfTh0Active);
		writeBoolAttr(wr, itemtag, "sref", "TxfTh1Active", TxfTh1Active);
		writeBoolAttr(wr, itemtag, "sref", "TxfPh0Active", TxfPh0Active);
		writeBoolAttr(wr, itemtag, "sref", "TxfPh1Active", TxfPh1Active);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStoActive", TxfStoActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkCdnActive", ChkCdnActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (TxfDphActive == comp->TxfDphActive) insert(items, TXFDPHACTIVE);
	if (TxfAl0Active == comp->TxfAl0Active) insert(items, TXFAL0ACTIVE);
	if (TxfAl1Active == comp->TxfAl1Active) insert(items, TXFAL1ACTIVE);
	if (TxfTh0Active == comp->TxfTh0Active) insert(items, TXFTH0ACTIVE);
	if (TxfTh1Active == comp->TxfTh1Active) insert(items, TXFTH1ACTIVE);
	if (TxfPh0Active == comp->TxfPh0Active) insert(items, TXFPH0ACTIVE);
	if (TxfPh1Active == comp->TxfPh1Active) insert(items, TXFPH1ACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (ChkCdnActive == comp->ChkCdnActive) insert(items, CHKCDNACTIVE);

	return(items);
};

set<uint> PnlBrlySegDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXFDPHACTIVE, TXFAL0ACTIVE, TXFAL1ACTIVE, TXFTH0ACTIVE, TXFTH1ACTIVE, TXFPH0ACTIVE, TXFPH1ACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, CHKCDNACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegDetail::Tag
 ******************************************************************************/

void PnlBrlySegDetail::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlySegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlySegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptReu", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptDph", "angular distance [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptAl0", "start altitude [m]");
			writeStringAttr(wr, itemtag, "sref", "CptAl1", "stop altitude [m]");
			writeStringAttr(wr, itemtag, "sref", "CptTh0", "start latitude [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptTh1", "stop latitude [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptPh0", "start longitude [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptPh1", "stop longitude [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "start time");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "stop time");
			writeStringAttr(wr, itemtag, "sref", "CptCdn", "calculated");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptReu", "Referenz");
			writeStringAttr(wr, itemtag, "sref", "CptDph", "Winkelabstand [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptAl0", "Start H\\u00f6he [m]");
			writeStringAttr(wr, itemtag, "sref", "CptAl1", "Stopp H\\u00f6he [m]");
			writeStringAttr(wr, itemtag, "sref", "CptTh0", "Start Breite [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptTh1", "Stopp Breite [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptPh0", "Start L\\u00e4nge [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptPh1", "Stopp L\\u00e4nge [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "Start");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "Stopp");
			writeStringAttr(wr, itemtag, "sref", "CptCdn", "berechnet");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlySegDetail::DpchAppData
 ******************************************************************************/

PnlBrlySegDetail::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYSEGDETAILDATA) {
};

string PnlBrlySegDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlySegDetailData");
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
 class PnlBrlySegDetail::DpchAppDo
 ******************************************************************************/

PnlBrlySegDetail::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYSEGDETAILDO) {
	ixVDo = 0;
};

string PnlBrlySegDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlySegDetailDo");
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
 class PnlBrlySegDetail::DpchEngData
 ******************************************************************************/

PnlBrlySegDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupRet
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYSEGDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPRET, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPRET) && feedFPupRet) this->feedFPupRet = *feedFPupRet;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlySegDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegDetail::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPRET)) {feedFPupRet = src->feedFPupRet; add(FEEDFPUPRET);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlySegDetail::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlySegDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPRET)) feedFPupRet.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

