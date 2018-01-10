/**
  * \file PnlBrlyLegRec_blks.cpp
  * job handler for job PnlBrlyLegRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class PnlBrlyLegRec::VecVDo
 ******************************************************************************/

uint PnlBrlyLegRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyLegRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLegRec::ContInf
 ******************************************************************************/

PnlBrlyLegRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlBrlyLegRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLegRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyLegRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyLegRec::ContInf::diff(
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
 class PnlBrlyLegRec::StatApp
 ******************************************************************************/

void PnlBrlyLegRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneMap
			, const bool initdoneCor1NConnection
			, const bool initdone1NFlight
			, const bool initdoneMNLocation
			, const bool initdoneOrgMNLeg
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyLegRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyLegRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMap", initdoneMap);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCor1NConnection", initdoneCor1NConnection);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NFlight", initdone1NFlight);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNLocation", initdoneMNLocation);
		writeBoolAttr(wr, itemtag, "sref", "initdoneOrgMNLeg", initdoneOrgMNLeg);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegRec::StatShr
 ******************************************************************************/

PnlBrlyLegRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const ubigint jrefPre
			, const ubigint jrefDetail
			, const ubigint jrefMap
			, const ubigint jrefCor1NConnection
			, const bool pnlcor1nconnectionAvail
			, const ubigint jref1NFlight
			, const bool pnl1nflightAvail
			, const ubigint jrefMNLocation
			, const ubigint jrefOrgMNLeg
			, const bool ButRegularizeActive
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->jrefPre = jrefPre;
	this->jrefDetail = jrefDetail;
	this->jrefMap = jrefMap;
	this->jrefCor1NConnection = jrefCor1NConnection;
	this->pnlcor1nconnectionAvail = pnlcor1nconnectionAvail;
	this->jref1NFlight = jref1NFlight;
	this->pnl1nflightAvail = pnl1nflightAvail;
	this->jrefMNLocation = jrefMNLocation;
	this->jrefOrgMNLeg = jrefOrgMNLeg;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, JREFPRE, JREFDETAIL, JREFMAP, JREFCOR1NCONNECTION, PNLCOR1NCONNECTIONAVAIL, JREF1NFLIGHT, PNL1NFLIGHTAVAIL, JREFMNLOCATION, JREFORGMNLEG, BUTREGULARIZEACTIVE};
};

void PnlBrlyLegRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLegRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyLegRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(mScr, scr, descr, jrefPre));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMap", Scr::scramble(mScr, scr, descr, jrefMap));
		writeStringAttr(wr, itemtag, "sref", "scrJrefCor1NConnection", Scr::scramble(mScr, scr, descr, jrefCor1NConnection));
		writeBoolAttr(wr, itemtag, "sref", "pnlcor1nconnectionAvail", pnlcor1nconnectionAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NFlight", Scr::scramble(mScr, scr, descr, jref1NFlight));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nflightAvail", pnl1nflightAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNLocation", Scr::scramble(mScr, scr, descr, jrefMNLocation));
		writeStringAttr(wr, itemtag, "sref", "scrJrefOrgMNLeg", Scr::scramble(mScr, scr, descr, jrefOrgMNLeg));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefMap == comp->jrefMap) insert(items, JREFMAP);
	if (jrefCor1NConnection == comp->jrefCor1NConnection) insert(items, JREFCOR1NCONNECTION);
	if (pnlcor1nconnectionAvail == comp->pnlcor1nconnectionAvail) insert(items, PNLCOR1NCONNECTIONAVAIL);
	if (jref1NFlight == comp->jref1NFlight) insert(items, JREF1NFLIGHT);
	if (pnl1nflightAvail == comp->pnl1nflightAvail) insert(items, PNL1NFLIGHTAVAIL);
	if (jrefMNLocation == comp->jrefMNLocation) insert(items, JREFMNLOCATION);
	if (jrefOrgMNLeg == comp->jrefOrgMNLeg) insert(items, JREFORGMNLEG);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyLegRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, JREFPRE, JREFDETAIL, JREFMAP, JREFCOR1NCONNECTION, PNLCOR1NCONNECTIONAVAIL, JREF1NFLIGHT, PNL1NFLIGHTAVAIL, JREFMNLOCATION, JREFORGMNLEG, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegRec::Tag
 ******************************************************************************/

void PnlBrlyLegRec::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLegRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyLegRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Leg");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Strecke");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegRec::DpchAppDo
 ******************************************************************************/

PnlBrlyLegRec::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGRECDO) {
	ixVDo = 0;
};

string PnlBrlyLegRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLegRecDo");
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
 class PnlBrlyLegRec::DpchEngData
 ******************************************************************************/

PnlBrlyLegRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyLegRec::DpchEngData::getSrefsMask() {
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

void PnlBrlyLegRec::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyLegRec::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLegRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

