/**
  * \file PnlBrlySegList_blks.cpp
  * job handler for job PnlBrlySegList (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class PnlBrlySegList::VecVDo
 ******************************************************************************/

uint PnlBrlySegList::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	else if (s == "butnewclick") return BUTNEWCLICK;
	else if (s == "butdeleteclick") return BUTDELETECLICK;
	else if (s == "butfilterclick") return BUTFILTERCLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlySegList::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	else if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTFILTERCLICK) return("ButFilterClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlySegList::ContIac
 ******************************************************************************/

PnlBrlySegList::ContIac::ContIac(
			const uint numFTos
		) : Block() {
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlBrlySegList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlySegList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlySegList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlBrlySegList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlySegList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlySegList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlBrlySegList::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFTOS};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegList::ContInf
 ******************************************************************************/

PnlBrlySegList::ContInf::ContInf(
			const string& TxtFor
			, const string& TxtPre
			, const bool ButFilterOn
			, const uint numFCsiQst
		) : Block() {
	this->TxtFor = TxtFor;
	this->TxtPre = TxtPre;
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
};

void PnlBrlySegList::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlySegList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlySegList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFor", TxtFor);
		writeStringAttr(wr, itemtag, "sref", "TxtPre", TxtPre);
		writeBoolAttr(wr, itemtag, "sref", "ButFilterOn", ButFilterOn);
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFor == comp->TxtFor) insert(items, TXTFOR);
	if (TxtPre == comp->TxtPre) insert(items, TXTPRE);
	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlySegList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegList::StatShr
 ******************************************************************************/

PnlBrlySegList::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const bool ButDeleteActive
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXBRLYVEXPSTATE, BUTDELETEACTIVE};
};

void PnlBrlySegList::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlySegList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlySegList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlBrlySegList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegList::StgIac
 ******************************************************************************/

PnlBrlySegList::StgIac::StgIac(
			const uint TcoRetWidth
			, const uint TcoReuWidth
			, const uint TcoAl0Width
			, const uint TcoAl1Width
			, const uint TcoTh0Width
			, const uint TcoTh1Width
			, const uint TcoPh0Width
			, const uint TcoPh1Width
			, const uint TcoStaWidth
			, const uint TcoStoWidth
		) : Block() {
	this->TcoRetWidth = TcoRetWidth;
	this->TcoReuWidth = TcoReuWidth;
	this->TcoAl0Width = TcoAl0Width;
	this->TcoAl1Width = TcoAl1Width;
	this->TcoTh0Width = TcoTh0Width;
	this->TcoTh1Width = TcoTh1Width;
	this->TcoPh0Width = TcoPh0Width;
	this->TcoPh1Width = TcoPh1Width;
	this->TcoStaWidth = TcoStaWidth;
	this->TcoStoWidth = TcoStoWidth;
	mask = {TCORETWIDTH, TCOREUWIDTH, TCOAL0WIDTH, TCOAL1WIDTH, TCOTH0WIDTH, TCOTH1WIDTH, TCOPH0WIDTH, TCOPH1WIDTH, TCOSTAWIDTH, TCOSTOWIDTH};
};

bool PnlBrlySegList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlySegList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlySegList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRetWidth", TcoRetWidth)) add(TCORETWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoReuWidth", TcoReuWidth)) add(TCOREUWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAl0Width", TcoAl0Width)) add(TCOAL0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAl1Width", TcoAl1Width)) add(TCOAL1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTh0Width", TcoTh0Width)) add(TCOTH0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTh1Width", TcoTh1Width)) add(TCOTH1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPh0Width", TcoPh0Width)) add(TCOPH0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPh1Width", TcoPh1Width)) add(TCOPH1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoStaWidth", TcoStaWidth)) add(TCOSTAWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoStoWidth", TcoStoWidth)) add(TCOSTOWIDTH);
	};

	return basefound;
};

void PnlBrlySegList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlySegList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlySegList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoRetWidth", TcoRetWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoReuWidth", TcoReuWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAl0Width", TcoAl0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoAl1Width", TcoAl1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoTh0Width", TcoTh0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoTh1Width", TcoTh1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoPh0Width", TcoPh0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoPh1Width", TcoPh1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoStaWidth", TcoStaWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoStoWidth", TcoStoWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoRetWidth == comp->TcoRetWidth) insert(items, TCORETWIDTH);
	if (TcoReuWidth == comp->TcoReuWidth) insert(items, TCOREUWIDTH);
	if (TcoAl0Width == comp->TcoAl0Width) insert(items, TCOAL0WIDTH);
	if (TcoAl1Width == comp->TcoAl1Width) insert(items, TCOAL1WIDTH);
	if (TcoTh0Width == comp->TcoTh0Width) insert(items, TCOTH0WIDTH);
	if (TcoTh1Width == comp->TcoTh1Width) insert(items, TCOTH1WIDTH);
	if (TcoPh0Width == comp->TcoPh0Width) insert(items, TCOPH0WIDTH);
	if (TcoPh1Width == comp->TcoPh1Width) insert(items, TCOPH1WIDTH);
	if (TcoStaWidth == comp->TcoStaWidth) insert(items, TCOSTAWIDTH);
	if (TcoStoWidth == comp->TcoStoWidth) insert(items, TCOSTOWIDTH);

	return(items);
};

set<uint> PnlBrlySegList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCORETWIDTH, TCOREUWIDTH, TCOAL0WIDTH, TCOAL1WIDTH, TCOTH0WIDTH, TCOTH1WIDTH, TCOPH0WIDTH, TCOPH1WIDTH, TCOSTAWIDTH, TCOSTOWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegList::Tag
 ******************************************************************************/

void PnlBrlySegList::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlySegList";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlySegList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Segments");
			writeStringAttr(wr, itemtag, "sref", "TcoRet", "Table of reference");
			writeStringAttr(wr, itemtag, "sref", "TcoReu", "Reference");
			writeStringAttr(wr, itemtag, "sref", "TcoAl0", "Start altitude [m]");
			writeStringAttr(wr, itemtag, "sref", "TcoAl1", "Stop altitude [m]");
			writeStringAttr(wr, itemtag, "sref", "TcoTh0", "Start latitude [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoTh1", "Stop latitude [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoPh0", "Start longitude [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoPh1", "Stop longitude [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoSta", "Start time");
			writeStringAttr(wr, itemtag, "sref", "TcoSto", "Stop time");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Segmente");
			writeStringAttr(wr, itemtag, "sref", "TcoRet", "Referenztabelle");
			writeStringAttr(wr, itemtag, "sref", "TcoReu", "Referenz");
			writeStringAttr(wr, itemtag, "sref", "TcoAl0", "Start H\\u00f6he [m]");
			writeStringAttr(wr, itemtag, "sref", "TcoAl1", "Stopp H\\u00f6he [m]");
			writeStringAttr(wr, itemtag, "sref", "TcoTh0", "Start Breite [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoTh1", "Stopp Breite [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoPh0", "Start L\\u00e4nge [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoPh1", "Stopp L\\u00e4nge [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoSta", "Start");
			writeStringAttr(wr, itemtag, "sref", "TcoSto", "Stopp");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtFor", VecBrlyVTag::getTitle(VecBrlyVTag::FOR, ixBrlyVLocale));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::SHOWLONG, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlySegList::DpchAppData
 ******************************************************************************/

PnlBrlySegList::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYSEGLISTDATA) {
};

string PnlBrlySegList::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegList::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlySegListData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryBrlySegList::StgIac();
	};
};

/******************************************************************************
 class PnlBrlySegList::DpchAppDo
 ******************************************************************************/

PnlBrlySegList::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYSEGLISTDO) {
	ixVDo = 0;
};

string PnlBrlySegList::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegList::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlySegListDo");
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
 class PnlBrlySegList::DpchEngData
 ******************************************************************************/

PnlBrlySegList::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFCsiQst
			, Feed* feedFTos
			, StatShr* statshr
			, StgIac* stgiac
			, ListBrlyQSegList* rst
			, QryBrlySegList::StatShr* statshrqry
			, QryBrlySegList::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYSEGLISTDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFCSIQST, FEEDFTOS, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, FEEDFTOS) && feedFTos) this->feedFTos = *feedFTos;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlBrlySegList::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(FEEDFTOS)) ss.push_back("feedFTos");
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

void PnlBrlySegList::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(FEEDFTOS)) {feedFTos = src->feedFTos; add(FEEDFTOS);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlBrlySegList::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlySegListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(FEEDFTOS)) feedFTos.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryBrlySegList::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

