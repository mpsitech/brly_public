/**
  * \file PnlBrlyLegOrgMNLeg_blks.cpp
  * job handler for job PnlBrlyLegOrgMNLeg (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::VecVDo
 ******************************************************************************/

uint PnlBrlyLegOrgMNLeg::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	else if (s == "butaddclick") return BUTADDCLICK;
	else if (s == "butsubclick") return BUTSUBCLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyLegOrgMNLeg::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	else if (ix == BUTADDCLICK) return("ButAddClick");
	else if (ix == BUTSUBCLICK) return("ButSubClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::ContInf
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlBrlyLegOrgMNLeg::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLegOrgMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyLegOrgMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegOrgMNLeg::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlyLegOrgMNLeg::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::StatApp
 ******************************************************************************/

void PnlBrlyLegOrgMNLeg::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyLegOrgMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyLegOrgMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::StatShr
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::StatShr::StatShr(
			const bool ButViewAvail
			, const bool ButViewActive
			, const bool ButAddAvail
			, const bool ButSubAvail
			, const bool ButSubActive
		) : Block() {
	this->ButViewAvail = ButViewAvail;
	this->ButViewActive = ButViewActive;
	this->ButAddAvail = ButAddAvail;
	this->ButSubAvail = ButSubAvail;
	this->ButSubActive = ButSubActive;

	mask = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
};

void PnlBrlyLegOrgMNLeg::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLegOrgMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyLegOrgMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButViewAvail", ButViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButViewActive", ButViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButAddAvail", ButAddAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSubAvail", ButSubAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSubActive", ButSubActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegOrgMNLeg::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewAvail == comp->ButViewAvail) insert(items, BUTVIEWAVAIL);
	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);
	if (ButAddAvail == comp->ButAddAvail) insert(items, BUTADDAVAIL);
	if (ButSubAvail == comp->ButSubAvail) insert(items, BUTSUBAVAIL);
	if (ButSubActive == comp->ButSubActive) insert(items, BUTSUBACTIVE);

	return(items);
};

set<uint> PnlBrlyLegOrgMNLeg::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::StgIac
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::StgIac::StgIac(
			const uint TcoMrefWidth
			, const uint TcoDp0Width
			, const uint TcoDp1Width
			, const uint TcoOp0Width
			, const uint TcoOp1Width
			, const uint TcoXd0Width
			, const uint TcoXd1Width
			, const uint TcoXo0Width
			, const uint TcoXo1Width
		) : Block() {
	this->TcoMrefWidth = TcoMrefWidth;
	this->TcoDp0Width = TcoDp0Width;
	this->TcoDp1Width = TcoDp1Width;
	this->TcoOp0Width = TcoOp0Width;
	this->TcoOp1Width = TcoOp1Width;
	this->TcoXd0Width = TcoXd0Width;
	this->TcoXd1Width = TcoXd1Width;
	this->TcoXo0Width = TcoXo0Width;
	this->TcoXo1Width = TcoXo1Width;
	mask = {TCOMREFWIDTH, TCODP0WIDTH, TCODP1WIDTH, TCOOP0WIDTH, TCOOP1WIDTH, TCOXD0WIDTH, TCOXD1WIDTH, TCOXO0WIDTH, TCOXO1WIDTH};
};

bool PnlBrlyLegOrgMNLeg::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyLegOrgMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyLegOrgMNLeg";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", TcoMrefWidth)) add(TCOMREFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDp0Width", TcoDp0Width)) add(TCODP0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDp1Width", TcoDp1Width)) add(TCODP1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoOp0Width", TcoOp0Width)) add(TCOOP0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoOp1Width", TcoOp1Width)) add(TCOOP1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXd0Width", TcoXd0Width)) add(TCOXD0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXd1Width", TcoXd1Width)) add(TCOXD1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXo0Width", TcoXo0Width)) add(TCOXO0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXo1Width", TcoXo1Width)) add(TCOXO1WIDTH);
	};

	return basefound;
};

void PnlBrlyLegOrgMNLeg::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLegOrgMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyLegOrgMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDp0Width", TcoDp0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoDp1Width", TcoDp1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoOp0Width", TcoOp0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoOp1Width", TcoOp1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoXd0Width", TcoXd0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoXd1Width", TcoXd1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoXo0Width", TcoXo0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoXo1Width", TcoXo1Width);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegOrgMNLeg::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoMrefWidth == comp->TcoMrefWidth) insert(items, TCOMREFWIDTH);
	if (TcoDp0Width == comp->TcoDp0Width) insert(items, TCODP0WIDTH);
	if (TcoDp1Width == comp->TcoDp1Width) insert(items, TCODP1WIDTH);
	if (TcoOp0Width == comp->TcoOp0Width) insert(items, TCOOP0WIDTH);
	if (TcoOp1Width == comp->TcoOp1Width) insert(items, TCOOP1WIDTH);
	if (TcoXd0Width == comp->TcoXd0Width) insert(items, TCOXD0WIDTH);
	if (TcoXd1Width == comp->TcoXd1Width) insert(items, TCOXD1WIDTH);
	if (TcoXo0Width == comp->TcoXo0Width) insert(items, TCOXO0WIDTH);
	if (TcoXo1Width == comp->TcoXo1Width) insert(items, TCOXO1WIDTH);

	return(items);
};

set<uint> PnlBrlyLegOrgMNLeg::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOMREFWIDTH, TCODP0WIDTH, TCODP1WIDTH, TCOOP0WIDTH, TCOOP1WIDTH, TCOXD0WIDTH, TCOXD1WIDTH, TCOXO0WIDTH, TCOXO1WIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::Tag
 ******************************************************************************/

void PnlBrlyLegOrgMNLeg::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLegOrgMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyLegOrgMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Legs");
			writeStringAttr(wr, itemtag, "sref", "TcoMref", "Leg");
			writeStringAttr(wr, itemtag, "sref", "TcoDp0", "Vis. from [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoDp1", "Vis. to [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoOp0", "Vis. leg vis. from [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoOp1", "Vis. leg vis. to [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoXd0", "XVisDstLegphi0");
			writeStringAttr(wr, itemtag, "sref", "TcoXd1", "XVisDstLegphi1");
			writeStringAttr(wr, itemtag, "sref", "TcoXo0", "XVisOrgLegphi0");
			writeStringAttr(wr, itemtag, "sref", "TcoXo1", "XVisOrgLegphi1");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Strecken");
			writeStringAttr(wr, itemtag, "sref", "TcoMref", "Strecke");
			writeStringAttr(wr, itemtag, "sref", "TcoDp0", "Sichtb. von [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoDp1", "Sichtb. bis [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoOp0", "Sichtb. Str. sichtb. von [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoOp1", "Sichtb. Str. sichtb. bis [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoXd0", "XVisDstLegphi0");
			writeStringAttr(wr, itemtag, "sref", "TcoXd1", "XVisDstLegphi1");
			writeStringAttr(wr, itemtag, "sref", "TcoXo0", "XVisOrgLegphi0");
			writeStringAttr(wr, itemtag, "sref", "TcoXo1", "XVisOrgLegphi1");
		};
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecBrlyVTag::getTitle(VecBrlyVTag::SHOWSHORT, ixBrlyVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecBrlyVTag::getTitle(VecBrlyVTag::EMPSHORT, ixBrlyVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::DpchAppData
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGORGMNLEGDATA) {
};

string PnlBrlyLegOrgMNLeg::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegOrgMNLeg::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLegOrgMNLegData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryBrlyLegOrgMNLeg::StgIac();
	};
};

/******************************************************************************
 class PnlBrlyLegOrgMNLeg::DpchAppDo
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGORGMNLEGDO) {
	ixVDo = 0;
};

string PnlBrlyLegOrgMNLeg::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegOrgMNLeg::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLegOrgMNLegDo");
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
 class PnlBrlyLegOrgMNLeg::DpchEngData
 ******************************************************************************/

PnlBrlyLegOrgMNLeg::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListBrlyQLegOrgMNLeg* rst
			, QryBrlyLegOrgMNLeg::StatShr* statshrqry
			, QryBrlyLegOrgMNLeg::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGORGMNLEGDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFCSIQST, STATAPP, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlBrlyLegOrgMNLeg::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegOrgMNLeg::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlBrlyLegOrgMNLeg::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLegOrgMNLegData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryBrlyLegOrgMNLeg::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

