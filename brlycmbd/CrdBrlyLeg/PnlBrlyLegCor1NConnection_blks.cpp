/**
  * \file PnlBrlyLegCor1NConnection_blks.cpp
  * job handler for job PnlBrlyLegCor1NConnection (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class PnlBrlyLegCor1NConnection::VecVDo
 ******************************************************************************/

uint PnlBrlyLegCor1NConnection::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyLegCor1NConnection::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLegCor1NConnection::ContInf
 ******************************************************************************/

PnlBrlyLegCor1NConnection::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlBrlyLegCor1NConnection::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLegCor1NConnection";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyLegCor1NConnection";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegCor1NConnection::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlyLegCor1NConnection::ContInf::diff(
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
 class PnlBrlyLegCor1NConnection::StatApp
 ******************************************************************************/

void PnlBrlyLegCor1NConnection::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyLegCor1NConnection";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyLegCor1NConnection";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegCor1NConnection::StatShr
 ******************************************************************************/

PnlBrlyLegCor1NConnection::StatShr::StatShr(
			const bool ButViewAvail
			, const bool ButViewActive
		) : Block() {
	this->ButViewAvail = ButViewAvail;
	this->ButViewActive = ButViewActive;

	mask = {BUTVIEWAVAIL, BUTVIEWACTIVE};
};

void PnlBrlyLegCor1NConnection::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLegCor1NConnection";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyLegCor1NConnection";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButViewAvail", ButViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButViewActive", ButViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegCor1NConnection::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewAvail == comp->ButViewAvail) insert(items, BUTVIEWAVAIL);
	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);

	return(items);
};

set<uint> PnlBrlyLegCor1NConnection::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWAVAIL, BUTVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegCor1NConnection::StgIac
 ******************************************************************************/

PnlBrlyLegCor1NConnection::StgIac::StgIac(
			const uint TcoRefWidth
		) : Block() {
	this->TcoRefWidth = TcoRefWidth;
	mask = {TCOREFWIDTH};
};

bool PnlBrlyLegCor1NConnection::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyLegCor1NConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyLegCor1NConnection";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRefWidth", TcoRefWidth)) add(TCOREFWIDTH);
	};

	return basefound;
};

void PnlBrlyLegCor1NConnection::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLegCor1NConnection";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyLegCor1NConnection";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoRefWidth", TcoRefWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegCor1NConnection::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoRefWidth == comp->TcoRefWidth) insert(items, TCOREFWIDTH);

	return(items);
};

set<uint> PnlBrlyLegCor1NConnection::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOREFWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegCor1NConnection::Tag
 ******************************************************************************/

void PnlBrlyLegCor1NConnection::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLegCor1NConnection";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyLegCor1NConnection";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Connections");
			writeStringAttr(wr, itemtag, "sref", "TcoRef", "Connection");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Verbindungen");
			writeStringAttr(wr, itemtag, "sref", "TcoRef", "Verbindung");
		};
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecBrlyVTag::getTitle(VecBrlyVTag::SHOWSHORT, ixBrlyVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecBrlyVTag::getTitle(VecBrlyVTag::EMPSHORT, ixBrlyVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegCor1NConnection::DpchAppData
 ******************************************************************************/

PnlBrlyLegCor1NConnection::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGCOR1NCONNECTIONDATA) {
};

string PnlBrlyLegCor1NConnection::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegCor1NConnection::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLegCor1NConnectionData");
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
		stgiacqry = QryBrlyLegCor1NConnection::StgIac();
	};
};

/******************************************************************************
 class PnlBrlyLegCor1NConnection::DpchAppDo
 ******************************************************************************/

PnlBrlyLegCor1NConnection::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGCOR1NCONNECTIONDO) {
	ixVDo = 0;
};

string PnlBrlyLegCor1NConnection::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegCor1NConnection::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLegCor1NConnectionDo");
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
 class PnlBrlyLegCor1NConnection::DpchEngData
 ******************************************************************************/

PnlBrlyLegCor1NConnection::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListBrlyQLegCor1NConnection* rst
			, QryBrlyLegCor1NConnection::StatShr* statshrqry
			, QryBrlyLegCor1NConnection::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGCOR1NCONNECTIONDATA, jref) {
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

string PnlBrlyLegCor1NConnection::DpchEngData::getSrefsMask() {
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

void PnlBrlyLegCor1NConnection::DpchEngData::merge(
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

void PnlBrlyLegCor1NConnection::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLegCor1NConnectionData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryBrlyLegCor1NConnection::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

