/**
  * \file PnlBrlyConRec_blks.cpp
  * job handler for job PnlBrlyConRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class PnlBrlyConRec::VecVDo
 ******************************************************************************/

uint PnlBrlyConRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyConRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyConRec::ContInf
 ******************************************************************************/

PnlBrlyConRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlBrlyConRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyConRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyConRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyConRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyConRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConRec::StatApp
 ******************************************************************************/

void PnlBrlyConRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneMap
			, const bool initdone1NRelay
			, const bool initdoneRef1NSegment
			, const bool initdoneMNSegment
			, const bool initdoneMNFlight
			, const bool initdoneConMNEquipment
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyConRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyConRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMap", initdoneMap);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NRelay", initdone1NRelay);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NSegment", initdoneRef1NSegment);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNSegment", initdoneMNSegment);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNFlight", initdoneMNFlight);
		writeBoolAttr(wr, itemtag, "sref", "initdoneConMNEquipment", initdoneConMNEquipment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConRec::StatShr
 ******************************************************************************/

PnlBrlyConRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const ubigint jrefPre
			, const ubigint jrefDetail
			, const ubigint jrefMap
			, const ubigint jref1NRelay
			, const ubigint jrefRef1NSegment
			, const ubigint jrefMNSegment
			, const ubigint jrefMNFlight
			, const ubigint jrefConMNEquipment
			, const bool ButRegularizeActive
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->jrefPre = jrefPre;
	this->jrefDetail = jrefDetail;
	this->jrefMap = jrefMap;
	this->jref1NRelay = jref1NRelay;
	this->jrefRef1NSegment = jrefRef1NSegment;
	this->jrefMNSegment = jrefMNSegment;
	this->jrefMNFlight = jrefMNFlight;
	this->jrefConMNEquipment = jrefConMNEquipment;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, JREFPRE, JREFDETAIL, JREFMAP, JREF1NRELAY, JREFREF1NSEGMENT, JREFMNSEGMENT, JREFMNFLIGHT, JREFCONMNEQUIPMENT, BUTREGULARIZEACTIVE};
};

void PnlBrlyConRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyConRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyConRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(mScr, scr, descr, jrefPre));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMap", Scr::scramble(mScr, scr, descr, jrefMap));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NRelay", Scr::scramble(mScr, scr, descr, jref1NRelay));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NSegment", Scr::scramble(mScr, scr, descr, jrefRef1NSegment));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNSegment", Scr::scramble(mScr, scr, descr, jrefMNSegment));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNFlight", Scr::scramble(mScr, scr, descr, jrefMNFlight));
		writeStringAttr(wr, itemtag, "sref", "scrJrefConMNEquipment", Scr::scramble(mScr, scr, descr, jrefConMNEquipment));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyConRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefMap == comp->jrefMap) insert(items, JREFMAP);
	if (jref1NRelay == comp->jref1NRelay) insert(items, JREF1NRELAY);
	if (jrefRef1NSegment == comp->jrefRef1NSegment) insert(items, JREFREF1NSEGMENT);
	if (jrefMNSegment == comp->jrefMNSegment) insert(items, JREFMNSEGMENT);
	if (jrefMNFlight == comp->jrefMNFlight) insert(items, JREFMNFLIGHT);
	if (jrefConMNEquipment == comp->jrefConMNEquipment) insert(items, JREFCONMNEQUIPMENT);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyConRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, JREFPRE, JREFDETAIL, JREFMAP, JREF1NRELAY, JREFREF1NSEGMENT, JREFMNSEGMENT, JREFMNFLIGHT, JREFCONMNEQUIPMENT, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConRec::Tag
 ******************************************************************************/

void PnlBrlyConRec::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyConRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyConRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Connection");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Verbindung");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConRec::DpchAppDo
 ******************************************************************************/

PnlBrlyConRec::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONRECDO) {
	ixVDo = 0;
};

string PnlBrlyConRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyConRecDo");
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
 class PnlBrlyConRec::DpchEngData
 ******************************************************************************/

PnlBrlyConRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyConRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConRec::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyConRec::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyConRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

