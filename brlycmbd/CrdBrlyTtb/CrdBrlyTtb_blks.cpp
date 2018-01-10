/**
  * \file CrdBrlyTtb_blks.cpp
  * job handler for job CrdBrlyTtb (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class CrdBrlyTtb::VecVDo
 ******************************************************************************/

uint CrdBrlyTtb::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	else if (s == "mitappabtclick") return MITAPPABTCLICK;
	else if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	else if (s == "mitcrdtrlclick") return MITCRDTRLCLICK;
	else if (s == "mitcrdiflclick") return MITCRDIFLCLICK;

	return(0);
};

string CrdBrlyTtb::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	else if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	else if (ix == MITCRDTRLCLICK) return("MitCrdTrlClick");
	else if (ix == MITCRDIFLCLICK) return("MitCrdIflClick");

	return("");
};

/******************************************************************************
 class CrdBrlyTtb::VecVSge
 ******************************************************************************/

uint CrdBrlyTtb::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "alrbrlyabt") return ALRBRLYABT;
	else if (s == "close") return CLOSE;
	else if (s == "impidle") return IMPIDLE;
	else if (s == "import") return IMPORT;
	else if (s == "impdone") return IMPDONE;
	else if (s == "segment") return SEGMENT;
	else if (s == "segdone") return SEGDONE;

	return(0);
};

string CrdBrlyTtb::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRBRLYABT) return("alrbrlyabt");
	else if (ix == CLOSE) return("close");
	else if (ix == IMPIDLE) return("impidle");
	else if (ix == IMPORT) return("import");
	else if (ix == IMPDONE) return("impdone");
	else if (ix == SEGMENT) return("segment");
	else if (ix == SEGDONE) return("segdone");

	return("");
};

void CrdBrlyTtb::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=8;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdBrlyTtb::ContInf
 ******************************************************************************/

CrdBrlyTtb::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdTtb
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdTtb = MtxCrdTtb;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDTTB};
};

void CrdBrlyTtb::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyTtb";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyTtb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdTtb", MtxCrdTtb);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdBrlyTtb::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdTtb == comp->MtxCrdTtb) insert(items, MTXCRDTTB);

	return(items);
};

set<uint> CrdBrlyTtb::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDTTB};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyTtb::StatApp
 ******************************************************************************/

void CrdBrlyTtb::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyTtb";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyTtb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVReqitmode", VecBrlyVReqitmode::getSref(ixBrlyVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneList", initdoneList);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRec", initdoneRec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdBrlyTtb::StatShr
 ******************************************************************************/

CrdBrlyTtb::StatShr::StatShr(
			const ubigint jrefDlgimpflt
			, const ubigint jrefDlgnew
			, const ubigint jrefDlgtrlorig
			, const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdTrlAvail
			, const bool MitCrdIflAvail
			, const bool MitCrdIflActive
		) : Block() {
	this->jrefDlgimpflt = jrefDlgimpflt;
	this->jrefDlgnew = jrefDlgnew;
	this->jrefDlgtrlorig = jrefDlgtrlorig;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefList = jrefList;
	this->jrefRec = jrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdNewAvail = MitCrdNewAvail;
	this->MitCrdTrlAvail = MitCrdTrlAvail;
	this->MitCrdIflAvail = MitCrdIflAvail;
	this->MitCrdIflActive = MitCrdIflActive;

	mask = {JREFDLGIMPFLT, JREFDLGNEW, JREFDLGTRLORIG, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDTRLAVAIL, MITCRDIFLAVAIL, MITCRDIFLACTIVE};
};

void CrdBrlyTtb::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyTtb";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyTtb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgimpflt", Scr::scramble(mScr, scr, descr, jrefDlgimpflt));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgnew", Scr::scramble(mScr, scr, descr, jrefDlgnew));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgtrlorig", Scr::scramble(mScr, scr, descr, jrefDlgtrlorig));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(mScr, scr, descr, jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(mScr, scr, descr, jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(mScr, scr, descr, jrefRec));
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdNewAvail", MitCrdNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTrlAvail", MitCrdTrlAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIflAvail", MitCrdIflAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIflActive", MitCrdIflActive);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdBrlyTtb::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgimpflt == comp->jrefDlgimpflt) insert(items, JREFDLGIMPFLT);
	if (jrefDlgnew == comp->jrefDlgnew) insert(items, JREFDLGNEW);
	if (jrefDlgtrlorig == comp->jrefDlgtrlorig) insert(items, JREFDLGTRLORIG);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdTrlAvail == comp->MitCrdTrlAvail) insert(items, MITCRDTRLAVAIL);
	if (MitCrdIflAvail == comp->MitCrdIflAvail) insert(items, MITCRDIFLAVAIL);
	if (MitCrdIflActive == comp->MitCrdIflActive) insert(items, MITCRDIFLACTIVE);

	return(items);
};

set<uint> CrdBrlyTtb::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGIMPFLT, JREFDLGNEW, JREFDLGTRLORIG, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDTRLAVAIL, MITCRDIFLAVAIL, MITCRDIFLACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyTtb::Tag
 ******************************************************************************/

void CrdBrlyTtb::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyTtb";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyTtb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdTrl", "Translate from original format ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIfl", "Import flights ...");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdTrl", "Aus Original-Format \\u00fcbersetzen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIfl", "Fl\\u00fcge importieren ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::ABOUT, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::HELP, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitCrdNew", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::NEW, ixBrlyVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdBrlyTtb::DpchAppDo
 ******************************************************************************/

CrdBrlyTtb::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYTTBDO) {
	ixVDo = 0;
};

string CrdBrlyTtb::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdBrlyTtb::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyTtbDo");
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
 class CrdBrlyTtb::DpchEngData
 ******************************************************************************/

CrdBrlyTtb::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYTTBDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdBrlyTtb::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdBrlyTtb::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdBrlyTtb::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyTtbData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

