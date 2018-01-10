/**
  * \file PnlBrlyFltRec_blks.cpp
  * job handler for job PnlBrlyFltRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class PnlBrlyFltRec::VecVDo
 ******************************************************************************/

uint PnlBrlyFltRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyFltRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyFltRec::ContInf
 ******************************************************************************/

PnlBrlyFltRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlBrlyFltRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyFltRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyFltRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFltRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyFltRec::ContInf::diff(
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
 class PnlBrlyFltRec::StatApp
 ******************************************************************************/

void PnlBrlyFltRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneFafAWaypoint
			, const bool initdone1NConnection
			, const bool initdoneRef1NSegment
			, const bool initdoneEqp1NNode
			, const bool initdoneMNLocation
			, const bool initdoneMNConnection
			, const bool initdoneOrgMNFlight
			, const bool initdoneEqpMNConnection
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyFltRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyFltRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneFafAWaypoint", initdoneFafAWaypoint);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NConnection", initdone1NConnection);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NSegment", initdoneRef1NSegment);
		writeBoolAttr(wr, itemtag, "sref", "initdoneEqp1NNode", initdoneEqp1NNode);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNLocation", initdoneMNLocation);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNConnection", initdoneMNConnection);
		writeBoolAttr(wr, itemtag, "sref", "initdoneOrgMNFlight", initdoneOrgMNFlight);
		writeBoolAttr(wr, itemtag, "sref", "initdoneEqpMNConnection", initdoneEqpMNConnection);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltRec::StatShr
 ******************************************************************************/

PnlBrlyFltRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const ubigint jrefPre
			, const ubigint jrefDetail
			, const ubigint jrefFafAWaypoint
			, const bool pnlfafawaypointAvail
			, const ubigint jref1NConnection
			, const ubigint jrefRef1NSegment
			, const ubigint jrefEqp1NNode
			, const bool pnleqp1nnodeAvail
			, const ubigint jrefMNLocation
			, const ubigint jrefMNConnection
			, const ubigint jrefOrgMNFlight
			, const ubigint jrefEqpMNConnection
			, const bool pnleqpmnconnectionAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->jrefPre = jrefPre;
	this->jrefDetail = jrefDetail;
	this->jrefFafAWaypoint = jrefFafAWaypoint;
	this->pnlfafawaypointAvail = pnlfafawaypointAvail;
	this->jref1NConnection = jref1NConnection;
	this->jrefRef1NSegment = jrefRef1NSegment;
	this->jrefEqp1NNode = jrefEqp1NNode;
	this->pnleqp1nnodeAvail = pnleqp1nnodeAvail;
	this->jrefMNLocation = jrefMNLocation;
	this->jrefMNConnection = jrefMNConnection;
	this->jrefOrgMNFlight = jrefOrgMNFlight;
	this->jrefEqpMNConnection = jrefEqpMNConnection;
	this->pnleqpmnconnectionAvail = pnleqpmnconnectionAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, JREFPRE, JREFDETAIL, JREFFAFAWAYPOINT, PNLFAFAWAYPOINTAVAIL, JREF1NCONNECTION, JREFREF1NSEGMENT, JREFEQP1NNODE, PNLEQP1NNODEAVAIL, JREFMNLOCATION, JREFMNCONNECTION, JREFORGMNFLIGHT, JREFEQPMNCONNECTION, PNLEQPMNCONNECTIONAVAIL, BUTREGULARIZEACTIVE};
};

void PnlBrlyFltRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyFltRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyFltRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(mScr, scr, descr, jrefPre));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefFafAWaypoint", Scr::scramble(mScr, scr, descr, jrefFafAWaypoint));
		writeBoolAttr(wr, itemtag, "sref", "pnlfafawaypointAvail", pnlfafawaypointAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NConnection", Scr::scramble(mScr, scr, descr, jref1NConnection));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NSegment", Scr::scramble(mScr, scr, descr, jrefRef1NSegment));
		writeStringAttr(wr, itemtag, "sref", "scrJrefEqp1NNode", Scr::scramble(mScr, scr, descr, jrefEqp1NNode));
		writeBoolAttr(wr, itemtag, "sref", "pnleqp1nnodeAvail", pnleqp1nnodeAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNLocation", Scr::scramble(mScr, scr, descr, jrefMNLocation));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNConnection", Scr::scramble(mScr, scr, descr, jrefMNConnection));
		writeStringAttr(wr, itemtag, "sref", "scrJrefOrgMNFlight", Scr::scramble(mScr, scr, descr, jrefOrgMNFlight));
		writeStringAttr(wr, itemtag, "sref", "scrJrefEqpMNConnection", Scr::scramble(mScr, scr, descr, jrefEqpMNConnection));
		writeBoolAttr(wr, itemtag, "sref", "pnleqpmnconnectionAvail", pnleqpmnconnectionAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFltRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefFafAWaypoint == comp->jrefFafAWaypoint) insert(items, JREFFAFAWAYPOINT);
	if (pnlfafawaypointAvail == comp->pnlfafawaypointAvail) insert(items, PNLFAFAWAYPOINTAVAIL);
	if (jref1NConnection == comp->jref1NConnection) insert(items, JREF1NCONNECTION);
	if (jrefRef1NSegment == comp->jrefRef1NSegment) insert(items, JREFREF1NSEGMENT);
	if (jrefEqp1NNode == comp->jrefEqp1NNode) insert(items, JREFEQP1NNODE);
	if (pnleqp1nnodeAvail == comp->pnleqp1nnodeAvail) insert(items, PNLEQP1NNODEAVAIL);
	if (jrefMNLocation == comp->jrefMNLocation) insert(items, JREFMNLOCATION);
	if (jrefMNConnection == comp->jrefMNConnection) insert(items, JREFMNCONNECTION);
	if (jrefOrgMNFlight == comp->jrefOrgMNFlight) insert(items, JREFORGMNFLIGHT);
	if (jrefEqpMNConnection == comp->jrefEqpMNConnection) insert(items, JREFEQPMNCONNECTION);
	if (pnleqpmnconnectionAvail == comp->pnleqpmnconnectionAvail) insert(items, PNLEQPMNCONNECTIONAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyFltRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, JREFPRE, JREFDETAIL, JREFFAFAWAYPOINT, PNLFAFAWAYPOINTAVAIL, JREF1NCONNECTION, JREFREF1NSEGMENT, JREFEQP1NNODE, PNLEQP1NNODEAVAIL, JREFMNLOCATION, JREFMNCONNECTION, JREFORGMNFLIGHT, JREFEQPMNCONNECTION, PNLEQPMNCONNECTIONAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltRec::Tag
 ******************************************************************************/

void PnlBrlyFltRec::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyFltRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyFltRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Flight");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Flug");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltRec::DpchAppDo
 ******************************************************************************/

PnlBrlyFltRec::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTRECDO) {
	ixVDo = 0;
};

string PnlBrlyFltRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyFltRecDo");
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
 class PnlBrlyFltRec::DpchEngData
 ******************************************************************************/

PnlBrlyFltRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYFLTRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyFltRec::DpchEngData::getSrefsMask() {
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

void PnlBrlyFltRec::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyFltRec::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyFltRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

