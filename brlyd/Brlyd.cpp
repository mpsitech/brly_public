/**
  * \file Brlyd.cpp
  * inter-thread exchange object for Brly daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "Brlyd.h"

/******************************************************************************
 namespace DpchBrlydAck
 ******************************************************************************/

void DpchBrlydAck::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchBrlydAck");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchBrlydQuit
 ******************************************************************************/

void DpchBrlydQuit::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchBrlydQuit");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchBrlydReg
 ******************************************************************************/

void DpchBrlydReg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, const ubigint nref
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchBrlydReg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrNref", Scr::scramble(mScr, scr, descr, nref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchBrlyopdReg
 ******************************************************************************/

DpchBrlyopdReg::DpchBrlyopdReg() : DpchBrly(VecBrlyVDpch::DPCHBRLYOPDREG) {
};

bool DpchBrlyopdReg::all(
			const set<uint>& items
		) {
	if (!find(items, PORT)) return false;
	if (!find(items, IXBRLYVOPENGTYPE)) return false;
	if (!find(items, OPPRCN)) return false;

	return true;
};

void DpchBrlyopdReg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVOpengtype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchBrlyopdReg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractUsmallintUclc(docctx, basexpath, "port", "", port)) add(PORT);
		if (extractStringUclc(docctx, basexpath, "srefIxBrlyVOpengtype", "", srefIxBrlyVOpengtype)) {
			ixBrlyVOpengtype = VecBrlyVOpengtype::getIx(srefIxBrlyVOpengtype);
			add(IXBRLYVOPENGTYPE);
		};
		if (extractUsmallintUclc(docctx, basexpath, "opprcn", "", opprcn)) add(OPPRCN);
	};
};

/******************************************************************************
 class DpchBrlyopdUnreg
 ******************************************************************************/

DpchBrlyopdUnreg::DpchBrlyopdUnreg() : DpchBrly(VecBrlyVDpch::DPCHBRLYOPDUNREG) {
};

bool DpchBrlyopdUnreg::all(
			const set<uint>& items
		) {
	if (!find(items, NREF)) return false;

	return true;
};

void DpchBrlyopdUnreg::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrNref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchBrlyopdUnreg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrNref", "", scrNref)) {
			nref = Scr::descramble(mScr, descr, scrNref);
			add(NREF);
		};
	};
};

/******************************************************************************
 class DpchAppBrly
 ******************************************************************************/

DpchAppBrly::DpchAppBrly(
			const uint ixBrlyVDpch
		) : DpchBrly(ixBrlyVDpch) {
	jref = 0;
};

DpchAppBrly::~DpchAppBrly() {
};

bool DpchAppBrly::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchAppBrly::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchAppBrly::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrJref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecBrlyVDpch::getSref(ixBrlyVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
	};
};

/******************************************************************************
 class DpchAppBrlyAlert
 ******************************************************************************/

DpchAppBrlyAlert::DpchAppBrlyAlert() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYALERT) {
};

bool DpchAppBrlyAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

string DpchAppBrlyAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(NUMFMCB)) ss.push_back("numFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchAppBrlyAlert::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractUintUclc(docctx, basexpath, "numFMcb", "", numFMcb)) add(NUMFMCB);
	} else {
	};
};

/******************************************************************************
 class DpchAppBrlyInit
 ******************************************************************************/

DpchAppBrlyInit::DpchAppBrlyInit() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYINIT) {
};

/******************************************************************************
 class DpchAppBrlyResume
 ******************************************************************************/

DpchAppBrlyResume::DpchAppBrlyResume() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYRESUME) {
};

/******************************************************************************
 class DpchEngBrly
 ******************************************************************************/

DpchEngBrly::DpchEngBrly(
			const uint ixBrlyVDpch
			, const ubigint jref
		) : DpchBrly(ixBrlyVDpch) {
	this->jref = jref;

	mask = {JREF};
};

DpchEngBrly::~DpchEngBrly() {
};

bool DpchEngBrly::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchEngBrly::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchEngBrly::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngBrly* src = dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
};

void DpchEngBrly::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	string tag = VecBrlyVDpch::getSref(ixBrlyVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngBrlyAck
 ******************************************************************************/

DpchEngBrlyAck::DpchEngBrlyAck(
			const ubigint jref
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYACK, jref) {
};

/******************************************************************************
 class DpchEngBrlyAlert
 ******************************************************************************/

DpchEngBrlyAlert::DpchEngBrlyAlert(
			const ubigint jref
			, ContInfBrlyAlert* continf
			, Feed* feedFMcb
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYALERT, jref) {
	if (continf) this->continf = *continf;
	if (feedFMcb) this->feedFMcb = *feedFMcb;

	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFMCB};
	else this->mask = mask;
};

bool DpchEngBrlyAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

string DpchEngBrlyAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFMCB)) ss.push_back("feedFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngBrlyAlert::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngBrlyAlert* src = (DpchEngBrlyAlert*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFMCB)) {feedFMcb = src->feedFMcb; add(FEEDFMCB);};
};

void DpchEngBrlyAlert::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFMCB)) feedFMcb.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngBrlyConfirm
 ******************************************************************************/

DpchEngBrlyConfirm::DpchEngBrlyConfirm(
			const bool accepted
			, const ubigint jref
			, const string& sref
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONFIRM, jref) {
	this->accepted = accepted;
	this->jref = jref;
	this->sref = sref;

	if (find(mask, ALL)) this->mask = {ACCEPTED, JREF, SREF};
	else this->mask = mask;
};

bool DpchEngBrlyConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

string DpchEngBrlyConfirm::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(ACCEPTED)) ss.push_back("accepted");
	if (has(JREF)) ss.push_back("jref");
	if (has(SREF)) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngBrlyConfirm::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngBrlyConfirm* src = (DpchEngBrlyConfirm*) dpcheng;

	if (src->has(ACCEPTED)) {accepted = src->accepted; add(ACCEPTED);};
	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(SREF)) {sref = src->sref; add(SREF);};
};

void DpchEngBrlyConfirm::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyConfirm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(ACCEPTED)) writeBool(wr, "accepted", accepted);
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(SREF)) writeString(wr, "sref", sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngBrlySuspend
 ******************************************************************************/

DpchEngBrlySuspend::DpchEngBrlySuspend(
			const ubigint jref
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYSUSPEND, jref) {
};

/******************************************************************************
 class StgBrlyd
 ******************************************************************************/

StgBrlyd::StgBrlyd(
			const usmallint jobprcn
			, const usmallint opengsrvport
			, const usmallint appsrvport
			, const bool https
			, const usmallint histlength
		) : Block() {
	this->jobprcn = jobprcn;
	this->opengsrvport = opengsrvport;
	this->appsrvport = appsrvport;
	this->https = https;
	this->histlength = histlength;
	mask = {JOBPRCN, OPENGSRVPORT, APPSRVPORT, HTTPS, HISTLENGTH};
};

bool StgBrlyd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyd";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jobprcn", jobprcn)) add(JOBPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opengsrvport", opengsrvport)) add(OPENGSRVPORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "appsrvport", appsrvport)) add(APPSRVPORT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "https", https)) add(HTTPS);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "histlength", histlength)) add(HISTLENGTH);
	};

	return basefound;
};

void StgBrlyd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "jobprcn", jobprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "opengsrvport", opengsrvport);
		writeUsmallintAttr(wr, itemtag, "sref", "appsrvport", appsrvport);
		writeBoolAttr(wr, itemtag, "sref", "https", https);
		writeUsmallintAttr(wr, itemtag, "sref", "histlength", histlength);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyd::comm(
			const StgBrlyd* comp
		) {
	set<uint> items;

	if (jobprcn == comp->jobprcn) insert(items, JOBPRCN);
	if (opengsrvport == comp->opengsrvport) insert(items, OPENGSRVPORT);
	if (appsrvport == comp->appsrvport) insert(items, APPSRVPORT);
	if (https == comp->https) insert(items, HTTPS);
	if (histlength == comp->histlength) insert(items, HISTLENGTH);

	return(items);
};

set<uint> StgBrlyd::diff(
			const StgBrlyd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JOBPRCN, OPENGSRVPORT, APPSRVPORT, HTTPS, HISTLENGTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyDatabase
 ******************************************************************************/

StgBrlyDatabase::StgBrlyDatabase(
			const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& username
			, const string& password
			, const string& ip
			, const usmallint port
		) : Block() {
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	mask = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
};

bool StgBrlyDatabase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyDatabase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyDatabase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
	};

	return basefound;
};

void StgBrlyDatabase::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyDatabase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyDatabase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyDatabase::comm(
			const StgBrlyDatabase* comp
		) {
	set<uint> items;

	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);

	return(items);
};

set<uint> StgBrlyDatabase::diff(
			const StgBrlyDatabase* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyFlightaware
 ******************************************************************************/

StgBrlyFlightaware::StgBrlyFlightaware(
			const string& ip
			, const string& key
		) : Block() {
	this->ip = ip;
	this->key = key;
	mask = {IP, KEY};
};

bool StgBrlyFlightaware::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyFlightaware");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyFlightaware";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "key", key)) add(KEY);
	};

	return basefound;
};

void StgBrlyFlightaware::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyFlightaware";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyFlightaware";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeStringAttr(wr, itemtag, "sref", "key", key);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyFlightaware::comm(
			const StgBrlyFlightaware* comp
		) {
	set<uint> items;

	if (ip == comp->ip) insert(items, IP);
	if (key == comp->key) insert(items, KEY);

	return(items);
};

set<uint> StgBrlyFlightaware::diff(
			const StgBrlyFlightaware* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IP, KEY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyGeometry
 ******************************************************************************/

StgBrlyGeometry::StgBrlyGeometry(
			const double acraltitude
			, const double corrwidth1
			, const double corrwidth2
			, const double earthradius
			, const double hrznaltitude
		) : Block() {
	this->acraltitude = acraltitude;
	this->corrwidth1 = corrwidth1;
	this->corrwidth2 = corrwidth2;
	this->earthradius = earthradius;
	this->hrznaltitude = hrznaltitude;
	mask = {ACRALTITUDE, CORRWIDTH1, CORRWIDTH2, EARTHRADIUS, HRZNALTITUDE};
};

bool StgBrlyGeometry::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyGeometry");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyGeometry";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acraltitude", acraltitude)) add(ACRALTITUDE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "corrwidth1", corrwidth1)) add(CORRWIDTH1);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "corrwidth2", corrwidth2)) add(CORRWIDTH2);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "earthradius", earthradius)) add(EARTHRADIUS);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "hrznaltitude", hrznaltitude)) add(HRZNALTITUDE);
	};

	return basefound;
};

void StgBrlyGeometry::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyGeometry";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyGeometry";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "acraltitude", acraltitude);
		writeDoubleAttr(wr, itemtag, "sref", "corrwidth1", corrwidth1);
		writeDoubleAttr(wr, itemtag, "sref", "corrwidth2", corrwidth2);
		writeDoubleAttr(wr, itemtag, "sref", "earthradius", earthradius);
		writeDoubleAttr(wr, itemtag, "sref", "hrznaltitude", hrznaltitude);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyGeometry::comm(
			const StgBrlyGeometry* comp
		) {
	set<uint> items;

	if (compareDouble(acraltitude, comp->acraltitude) < 1.0e-4) insert(items, ACRALTITUDE);
	if (compareDouble(corrwidth1, comp->corrwidth1) < 1.0e-4) insert(items, CORRWIDTH1);
	if (compareDouble(corrwidth2, comp->corrwidth2) < 1.0e-4) insert(items, CORRWIDTH2);
	if (compareDouble(earthradius, comp->earthradius) < 1.0e-4) insert(items, EARTHRADIUS);
	if (compareDouble(hrznaltitude, comp->hrznaltitude) < 1.0e-4) insert(items, HRZNALTITUDE);

	return(items);
};

set<uint> StgBrlyGeometry::diff(
			const StgBrlyGeometry* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACRALTITUDE, CORRWIDTH1, CORRWIDTH2, EARTHRADIUS, HRZNALTITUDE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyMonitor
 ******************************************************************************/

StgBrlyMonitor::StgBrlyMonitor(
			const string& username
			, const string& password
			, const string& ip
			, const usmallint port
			, const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& dbsusername
			, const string& dbspassword
		) : Block() {
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->dbsusername = dbsusername;
	this->dbspassword = dbspassword;
	mask = {USERNAME, PASSWORD, IP, PORT, IXDBSVDBSTYPE, DBSPATH, DBSNAME, DBSUSERNAME, DBSPASSWORD};
};

bool StgBrlyMonitor::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyMonitor");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyMonitor";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsusername", dbsusername)) add(DBSUSERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspassword", dbspassword)) add(DBSPASSWORD);
	};

	return basefound;
};

void StgBrlyMonitor::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyMonitor";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyMonitor";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "dbsusername", dbsusername);
		writeStringAttr(wr, itemtag, "sref", "dbspassword", dbspassword);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyMonitor::comm(
			const StgBrlyMonitor* comp
		) {
	set<uint> items;

	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);
	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (dbsusername == comp->dbsusername) insert(items, DBSUSERNAME);
	if (dbspassword == comp->dbspassword) insert(items, DBSPASSWORD);

	return(items);
};

set<uint> StgBrlyMonitor::diff(
			const StgBrlyMonitor* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {USERNAME, PASSWORD, IP, PORT, IXDBSVDBSTYPE, DBSPATH, DBSNAME, DBSUSERNAME, DBSPASSWORD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyPath
 ******************************************************************************/

StgBrlyPath::StgBrlyPath(
			const string& acvpath
			, const string& keypath
			, const string& monpath
			, const string& tmppath
			, const string& webpath
			, const string& helpurl
		) : Block() {
	this->acvpath = acvpath;
	this->keypath = keypath;
	this->monpath = monpath;
	this->tmppath = tmppath;
	this->webpath = webpath;
	this->helpurl = helpurl;
	mask = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
};

bool StgBrlyPath::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyPath");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyPath";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acvpath", acvpath)) add(ACVPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "keypath", keypath)) add(KEYPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "monpath", monpath)) add(MONPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "tmppath", tmppath)) add(TMPPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "webpath", webpath)) add(WEBPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "helpurl", helpurl)) add(HELPURL);
	};

	return basefound;
};

void StgBrlyPath::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyPath";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyPath";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "acvpath", acvpath);
		writeStringAttr(wr, itemtag, "sref", "keypath", keypath);
		writeStringAttr(wr, itemtag, "sref", "monpath", monpath);
		writeStringAttr(wr, itemtag, "sref", "tmppath", tmppath);
		writeStringAttr(wr, itemtag, "sref", "webpath", webpath);
		writeStringAttr(wr, itemtag, "sref", "helpurl", helpurl);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyPath::comm(
			const StgBrlyPath* comp
		) {
	set<uint> items;

	if (acvpath == comp->acvpath) insert(items, ACVPATH);
	if (keypath == comp->keypath) insert(items, KEYPATH);
	if (monpath == comp->monpath) insert(items, MONPATH);
	if (tmppath == comp->tmppath) insert(items, TMPPATH);
	if (webpath == comp->webpath) insert(items, WEBPATH);
	if (helpurl == comp->helpurl) insert(items, HELPURL);

	return(items);
};

set<uint> StgBrlyPath::diff(
			const StgBrlyPath* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 namespace AlrBrly
 ******************************************************************************/

DpchEngBrlyAlert* AlrBrly::prepareAlrAbt(
			const ubigint jref
			, const uint ixBrlyVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfBrlyAlert continf;
	// IP prepareAlrAbt --- BEGIN
	continf.TxtCpt = VecBrlyVTag::getTitle(VecBrlyVTag::ABOUT, ixBrlyVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		continf.TxtMsg1 = "BeamRelay version 0.2.2 released on 8-1-2018";
		continf.TxtMsg2 = "\\u00a9 Mpsi Technologies GmbH";
		continf.TxtMsg4 = "contributors: Alexander Wirthmueller";
		continf.TxtMsg6 = "libraries: - and netcdf 4.2.1.1";
		continf.TxtMsg8 = "BeamRelay uses airline alliance timetable data to calculate the feasibility of multi-hop free-space optical data relays.";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		continf.TxtMsg1 = "BeamRelay Version 0.2.2 ver\\u00f6ffentlicht am 8-1-2018";
		continf.TxtMsg2 = "\\u00a9 Mpsi Technologies GmbH";
		continf.TxtMsg4 = "Mitwirkende: Alexander Wirthmueller";
		continf.TxtMsg6 = "Programmbibliotheken: - und netcdf 4.2.1.1";
		continf.TxtMsg8 = "BeamRelay verwendet Flugplandaten von Luftfahrt-Allianzen, um die Machbarkeit optischer Daten\\u00fcbertragung \\u00fcber mehrere Stationen zu berechnen.";
	};

	feedFMcbAlert.clear();

	VecBrlyVTag::appendToFeed(VecBrlyVTag::CLOSE, ixBrlyVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrAbt --- END
	return(new DpchEngBrlyAlert(jref, &continf, &feedFMcbAlert, {DpchEngBrlyAlert::ALL}));
};

DpchEngBrlyAlert* AlrBrly::prepareAlrPer(
			const ubigint jref
			, const uint ixBrlyVLocale
			, const string& lineno
			, Feed& feedFMcbAlert
		) {
	ContInfBrlyAlert continf;
	// IP prepareAlrPer --- BEGIN
	continf.TxtCpt = VecBrlyVTag::getTitle(VecBrlyVTag::ERROR, ixBrlyVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		continf.TxtMsg1 = "Parse error in line " + lineno + ".";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		continf.TxtMsg1 = "Syntaxfehler in Zeile " + lineno + ".";
	};

	feedFMcbAlert.clear();

	VecBrlyVTag::appendToFeed(VecBrlyVTag::OK, ixBrlyVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrPer --- END
	return(new DpchEngBrlyAlert(jref, &continf, &feedFMcbAlert, {DpchEngBrlyAlert::ALL}));
};

DpchEngBrlyAlert* AlrBrly::prepareAlrSav(
			const ubigint jref
			, const uint ixBrlyVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfBrlyAlert continf;
	// IP prepareAlrSav --- BEGIN
	continf.TxtCpt = VecBrlyVTag::getTitle(VecBrlyVTag::QUEST, ixBrlyVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		continf.TxtMsg1 = "Save changes?";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		continf.TxtMsg1 = "\\u00c4nderungen speichern?";
	};

	feedFMcbAlert.clear();

	VecBrlyVTag::appendToFeed(VecBrlyVTag::CANCEL, ixBrlyVLocale, feedFMcbAlert);
	VecBrlyVTag::appendToFeed(VecBrlyVTag::FLS, ixBrlyVLocale, feedFMcbAlert);
	VecBrlyVTag::appendToFeed(VecBrlyVTag::TRU, ixBrlyVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrSav --- END
	return(new DpchEngBrlyAlert(jref, &continf, &feedFMcbAlert, {DpchEngBrlyAlert::ALL}));
};

/******************************************************************************
 class ReqBrly
 ******************************************************************************/

ReqBrly::ReqBrly(
			const uint ixVBasetype
			, const uint ixVState
			, const string& ip
		) {
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	if ((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::REGULAR) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD)) {
		retain = false;
		Mutex::init(&mcReady, false, "mcReady", "ReqBrly", "ReqBrly");
		Cond::init(&cReady, "cReady", "ReqBrly", "ReqBrly");

	} else {
		retain = true;
	};

	file = NULL;
	filelen = 0;

	request = NULL;
	requestlen = 0;

	jref = 0;

	wref = 0;

	call = NULL;

	weak = false;

	dpchapp = NULL;

	dpcheng = NULL;
	ixBrlyVLocale = VecBrlyVLocale::ENUS;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;
};

ReqBrly::~ReqBrly() {
	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD
	if (pp) MHD_destroy_post_processor(pp);

	// specific data for base types CMD, REGULAR, NOTIFY, UPLOAD, DOWNLOAD
	if ((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::REGULAR) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD)) {
		Mutex::destroy(&mcReady, false, "mcReady", "ReqBrly", "~ReqBrly");
		Cond::destroy(&cReady, "cReady", "ReqBrly", "~ReqBrly");
	};

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	if (file) {
		if (file->is_open()) file->close();
		delete file;
	};

	// specific data for base type EXTCALL
	if (call) delete call;

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	if (request) delete[] request;

	// specific data for base types REGULAR
	if (dpchapp) delete dpchapp;

	// specific data for base types REGULAR, NOTIFY, POLL
	if (dpcheng) delete dpcheng;

	// specific data for base types RET
	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	// specific data for base types REGULAR, NOTIFY, POLL
	if (reply) delete[] reply;
};

void ReqBrly::setStateReply() {
	Mutex::lock(&mcReady, "mcReady", "ReqBrly", "setStateReply");
	ixVState = VecVState::REPLY;
	Mutex::unlock(&mcReady, "mcReady", "ReqBrly", "setStateReply");

	Cond::signal(&cReady, &mcReady, "cReady", "mcReady", "ReqBrly", "setStateReply");
};

/******************************************************************************
 class ReqopengconBrly
 ******************************************************************************/

ReqopengconBrly::ReqopengconBrly(
			const uint ixVState
			, const string& ip
		) {
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	request = NULL;
	requestlen = 0;

	dpchopd = NULL;

	reply = NULL;
	replylen = 0;
};

ReqopengconBrly::~ReqopengconBrly() {
	if (pp) MHD_destroy_post_processor(pp);

	if (request) delete[] request;

	if (dpchopd) delete dpchopd;

	if (reply) delete[] reply;
};

/******************************************************************************
 class DcolBrly
 ******************************************************************************/

DcolBrly::DcolBrly(
			const ubigint jref
			, const uint ixBrlyVLocale
		) {
	this->jref = jref;
	this->ixBrlyVLocale = ixBrlyVLocale;

	Mutex::init(&mAccess, false, "mAccess", "DcolBrly", "DcolBrly");

	hot = false;

	req = NULL;
};

DcolBrly::~DcolBrly() {
	Mutex::lock(&mAccess, "mAccess", "DcolBrly", "~DcolBrly");
	Mutex::unlock(&mAccess, "mAccess", "DcolBrly", "~DcolBrly");
	Mutex::destroy(&mAccess, true, "mAccess", "DcolBrly", "~DcolBrly");

	for (auto it=dpchs.begin();it!=dpchs.end();it++) delete(*it);

	if (req) Cond::signal(&(req->cReady), &(req->mcReady), "req->cReady", "req->mcReady", "DcolBrly", "~DcolBrly");
};

int DcolBrly::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "dcol(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int DcolBrly::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "dcol(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

/******************************************************************************
 class JobBrly
 ******************************************************************************/

JobBrly::JobBrly(
			XchgBrly* xchg
			, const uint ixBrlyVJob
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
			, const bool prefmast
		) {
	this->xchg = xchg;

	jref = 0;

	this->ixBrlyVJob = ixBrlyVJob;

	this->jrefSup = jrefSup;

	this->ixBrlyVLocale = ixBrlyVLocale;

	jrefMast = 0;

	this->prefmast = prefmast;

	Mutex::init(&mAccess, true, "mAccess", VecBrlyVJob::getSref(ixBrlyVJob) + "(jrefSup=" + to_string(jrefSup) + ")", VecBrlyVJob::getSref(ixBrlyVJob));

	muteRefresh = false;

	ixVSge = 1;
	nextIxVSge = 1;

	opNdone = 0;
	opN = 0;

	Mutex::init(&mOps, true, "mOps", VecBrlyVJob::getSref(ixBrlyVJob) + "(jrefSup=" + to_string(jrefSup) + ")", VecBrlyVJob::getSref(ixBrlyVJob));

	wrefLast = 0;
	wrefMin = 0;

	reqCmd = NULL;
};

JobBrly::~JobBrly() {
	Mutex::lock(&mAccess, "mAccess", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "~" + VecBrlyVJob::getSref(ixBrlyVJob));
	Mutex::unlock(&mAccess, "mAccess", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "~" + VecBrlyVJob::getSref(ixBrlyVJob));
	Mutex::destroy(&mAccess, true, "mAccess", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "~" + VecBrlyVJob::getSref(ixBrlyVJob));

	Mutex::destroy(&mOps, true, "mOps", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "~" + VecBrlyVJob::getSref(ixBrlyVJob));

	if (reqCmd) delete reqCmd;
};

DpchEngBrly* JobBrly::getNewDpchEng(
			set<uint> items
		) {
	return new DpchEngBrlyConfirm(true, jref, "");
};

void JobBrly::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
};

void JobBrly::refreshWithDpchEng(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	set<uint> moditems;

	DpchEngBrly* _dpcheng = NULL;

	refresh(dbsbrly, moditems);

	if (dpcheng) {
		_dpcheng = getNewDpchEng(moditems);

		if (*dpcheng) {
			if (_dpcheng->ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONFIRM) delete _dpcheng;
			else if (_dpcheng->ixBrlyVDpch == (*dpcheng)->ixBrlyVDpch) {
				(*dpcheng)->merge(_dpcheng);
				delete _dpcheng;

			} else xchg->submitDpch(_dpcheng);

		} else *dpcheng = _dpcheng;

	} else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
};

string JobBrly::getSquawk(
			DbsBrly* dbsbrly
		) {
	return "";
};

void JobBrly::giveupMaster(
			DbsBrly* dbsbrly
		) {
};

void JobBrly::giveupSlave(
			DbsBrly* dbsbrly
		) {
};

void JobBrly::becomeMaster(
			DbsBrly* dbsbrly
		) {
};

void JobBrly::becomeSlave(
			DbsBrly* dbsbrly
		) {
};

bool JobBrly::handleClaimMaster(
			DbsBrly* dbsbrly
		) {
	return false;
};

void JobBrly::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
};

void JobBrly::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
};

int JobBrly::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "job(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int JobBrly::trylockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::trylock(&mAccess, "job(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int JobBrly::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "job(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int JobBrly::lockAccess(
			const string& srefMember
		) {
	return Mutex::lock(&mAccess, "mAccess", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", srefMember);
};

int JobBrly::unlockAccess(
			const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "mAccess", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", srefMember);
};

void JobBrly::clearInvs() {
	for (unsigned int i=0;i<invs.size();i++) delete invs[i];
	invs.clear();
};

ubigint JobBrly::addInv(
			DpchInvBrly* inv
		) {
	inv->oref = xchg->orefseq->getNewRef();
	inv->jref = jref;

	invs.push_back(inv);

	opN++;

	return(inv->oref);
};

void JobBrly::addInvs(
			vector<DpchInvBrly*>& _invs
		) {
	for (unsigned int i=0;i<_invs.size();i++) addInv(_invs[i]);
};

void JobBrly::submitInvs(
			DbsBrly* dbsbrly
			, const uint emptyIxVSge
			, uint& _ixVSge
		) {
	if (opN == 0) {
		_ixVSge = emptyIxVSge;

	} else {
		xchg->addInvs(dbsbrly, jref, invs);
		invs.clear();
	};
};

void JobBrly::clearOps() {
	Mutex::lock(&mOps, "mOps", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "clearOps");

	for (auto it=ops.begin();it!=ops.end();it++) delete(*it);
	ops.clear();

	Mutex::unlock(&mOps, "mOps", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "clearOps");
};

void JobBrly::addOp(
			DbsBrly* dbsbrly
			, DpchInvBrly* inv
		) {
	string squawk;

	Mutex::lock(&mOps, "mOps", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "addOp");

	// generate squawk
	if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELEGLEG) {
		squawk = SqkBrlyBase::getSquawkLegleg(dbsbrly, (DpchInvBrlyBaseLegleg*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELEGLOC) {
		squawk = SqkBrlyBase::getSquawkLegloc(dbsbrly, (DpchInvBrlyBaseLegloc*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELOCLOC) {
		squawk = SqkBrlyBase::getSquawkLocloc(dbsbrly, (DpchInvBrlyBaseLocloc*) inv);
	};
	if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPCOLLECT) {
		squawk = SqkBrlyDnsmap::getSquawkCollect(dbsbrly, (DpchInvBrlyDnsmapCollect*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPFRAME) {
		squawk = SqkBrlyDnsmap::getSquawkFrame(dbsbrly, (DpchInvBrlyDnsmapFrame*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPVIDEO) {
		squawk = SqkBrlyDnsmap::getSquawkVideo(dbsbrly, (DpchInvBrlyDnsmapVideo*) inv);
	};
	if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNCONFLT) {
		squawk = SqkBrlyDyn::getSquawkConflt(dbsbrly, (DpchInvBrlyDynConflt*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNCONSEG) {
		squawk = SqkBrlyDyn::getSquawkConseg(dbsbrly, (DpchInvBrlyDynConseg*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNEQPLIST) {
		squawk = SqkBrlyDyn::getSquawkEqplist(dbsbrly, (DpchInvBrlyDynEqplist*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNFLTFLTLOC) {
		squawk = SqkBrlyDyn::getSquawkFltfltloc(dbsbrly, (DpchInvBrlyDynFltfltloc*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNFLTSEG) {
		squawk = SqkBrlyDyn::getSquawkFltseg(dbsbrly, (DpchInvBrlyDynFltseg*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNRLY) {
		squawk = SqkBrlyDyn::getSquawkRly(dbsbrly, (DpchInvBrlyDynRly*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNSEGLOCSEG) {
		squawk = SqkBrlyDyn::getSquawkSeglocseg(dbsbrly, (DpchInvBrlyDynSeglocseg*) inv);
	};
	if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENCONMAP) {
		squawk = SqkBrlyMapgen::getSquawkConmap(dbsbrly, (DpchInvBrlyMapgenConmap*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENLEGMAP) {
		squawk = SqkBrlyMapgen::getSquawkLegmap(dbsbrly, (DpchInvBrlyMapgenLegmap*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENLOCMAP) {
		squawk = SqkBrlyMapgen::getSquawkLocmap(dbsbrly, (DpchInvBrlyMapgenLocmap*) inv);
	};
	if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYTTIMPRAWSTAR) {
		squawk = SqkBrlyTtimp::getSquawkRawstar(dbsbrly, (DpchInvBrlyTtimpRawstar*) inv);
	};

	// append to op list
	ops.push_back(new Op(inv->oref, inv->ixBrlyVDpch, squawk));

	Mutex::unlock(&mOps, "mOps", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "addOp");
};

void JobBrly::removeOp(
			const ubigint oref
		) {
	Op* op = NULL;

	Mutex::lock(&mOps, "mOps", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "removeOp");

	for (auto it=ops.begin();it!=ops.end();it++) {
		op = *it;

		if (op->oref == oref) {
			// found
			ops.erase(it);

			// keep squawk of this op
			opsqkLast = op->squawk;

			delete op;
			
			break;
		};
	};

	Mutex::unlock(&mOps, "mOps", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "removeOp");
};

string JobBrly::getOpsqkLast() {
	string retval;

	Mutex::lock(&mOps, "mOps", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "getOpsqkLast");

	retval = opsqkLast;

	Mutex::unlock(&mOps, "mOps", VecBrlyVJob::getSref(ixBrlyVJob) + "(" + to_string(jref) + ")", "getOpsqkLast");

	return retval;
};

void JobBrly::callback(
			const uint _nextIxVSge
		) {
	nextIxVSge = _nextIxVSge;
	wrefLast = xchg->addWakeup(jref, "callback", 0);
};

void JobBrly::invalidateWakeups() {
	wrefMin = wrefLast + 1;
};

/******************************************************************************
 class StmgrBrly
 ******************************************************************************/

StmgrBrly::StmgrBrly(
			XchgBrly* xchg
			, const ubigint jref
			, const uint ixVNonetype
		) {
	this->xchg = xchg;

	this->jref = jref;
	this->ixVNonetype = ixVNonetype;

	stcch = new Stcch(true);

	Mutex::init(&mAccess, true, "mAccess", "StmgrBrly(" + to_string(jref) + ")", "StmgrBrly");
};

StmgrBrly::~StmgrBrly() {
	Mutex::lock(&mAccess, "mAccess", "StmgrBrly(" + to_string(jref) + ")", "~StmgrBrly");
	Mutex::unlock(&mAccess, "mAccess", "StmgrBrly(" + to_string(jref) + ")", "~StmgrBrly");
	Mutex::destroy(&mAccess, true, "mAccess", "StmgrBrly(" + to_string(jref) + ")", "~StmgrBrly");

	delete stcch;
};

void StmgrBrly::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	set<uint> icsBrlyVStub;
	pair<multimap<stcchitemref_t,Stcchitem*>::iterator,multimap<stcchitemref_t,Stcchitem*>::iterator> rng;

	bool notif = false;

	begin();

	if (call->ixVCall == VecBrlyVCall::CALLBRLYCONUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYCONSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYEQPUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYEQPSHORT);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYEQPSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFAFUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYFAFSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFILUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYFILSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFLTUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYFLTSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYFLTSREF);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEGUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLEGSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLEGSHORT);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOCUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLOCTITLE);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLOCSREF);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLOCSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYNDEUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYNDELONG);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYNDESTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYOPRUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYOPRSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYOPRSREF);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYPRSUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYPRSSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYPTYUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYPTYSREF);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYPTYSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREGUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYREGLONG);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYREGHSREF);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYREGSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYRLYUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYRLYLONG);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYRLYSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSEGUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYSEGSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSESUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYSESMENU);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYSESSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYTTBUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYTTBSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYTTBTITLE);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSGUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYUSGSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYGRP);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSRUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYOWN);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYUSRSTD);
	};

	for (auto it=icsBrlyVStub.begin();it!=icsBrlyVStub.end();it++) {
		rng = stcch->nodes.equal_range(stcchitemref_t(*it, call->argInv.ref, 0));
		for (auto it2=rng.first;it2!=rng.second;it2++) if (refresh(dbsbrly, it2->second)) notif = true;
	};

	commit();

	if (notif) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTUBCHG, jref);
};

bool StmgrBrly::refresh(
			DbsBrly* dbsbrly
			, Stcchitem* stit
		) {
	set<stcchitemref_t> strefsSub_backup;
	string stub_backup;

	while (!stit->strefsSup.empty()) stcch->unlink(*stit->strefsSup.begin(), stit->stref);

	strefsSub_backup = stit->strefsSub;
	stub_backup = stit->stub;

	StubBrly::getStub(dbsbrly, stit->stref.ixVStub, stit->stref.ref, stit->stref.ixVLocale, ixVNonetype, stcch, NULL, true);

	if (stit->stub != stub_backup) {
		for (auto it=strefsSub_backup.begin();it!=strefsSub_backup.end();it++) refresh(dbsbrly, stcch->getStitByStref(*it));
		return true;
	} else return false;
};

void StmgrBrly::begin() {
	stcch->begin();
};

void StmgrBrly::commit() {
	for (auto it=stcch->icsVStubNew.begin();it!=stcch->icsVStubNew.end();it++) {
		if (*it == VecBrlyVStub::STUBBRLYCONSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYCONUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYEQPSHORT) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYEQPUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYEQPSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYEQPUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYFAFSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYFAFUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYFILSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYFILUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYFLTSREF) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYFLTUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYFLTSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYFLTUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYGRP) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYUSGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYLEGSHORT) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLEGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYLEGSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLEGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYLOCSREF) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLOCUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYLOCSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLOCUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYLOCTITLE) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLOCUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYNDELONG) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYNDEUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYNDESTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYNDEUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYOPRSREF) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYOPRUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYOPRSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYOPRUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYOWN) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYUSRUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYPRSSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYPRSUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYPTYSREF) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYPTYUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYPTYSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYPTYUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYREGHSREF) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYREGLONG) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYREGSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYRLYLONG) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYRLYUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYRLYSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYRLYUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYSEGSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYSEGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYSESMENU) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYSESUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYSESSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYSESUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYTTBSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYTTBUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYTTBTITLE) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYTTBUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYUSGSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYUSGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYUSRSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYUSRUPD_REFEQ, jref);
		};
	};

	stcch->commit();
};

int StmgrBrly::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "stmgr(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int StmgrBrly::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "stmgr(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

/******************************************************************************
 class WakeupBrly
 ******************************************************************************/

WakeupBrly::WakeupBrly(
			XchgBrly* xchg
			, const ubigint wref
			, const ubigint jref
			, const string sref
			, const unsigned int deltat
			, const bool weak
		) {
	this->xchg = xchg;
	this->wref = wref;
	this->jref = jref;
	this->sref = sref;
	this->deltat = deltat;
	this->weak = weak;
};

/******************************************************************************
 class ExtcallBrly
 ******************************************************************************/

ExtcallBrly::ExtcallBrly(
			XchgBrly* xchg
			, Call* call
		) {
	this->xchg = xchg;
	this->call = call;
};

/******************************************************************************
 class ConopengBrly
 ******************************************************************************/

ConopengBrly::ConopengBrly(
			const string& ip
			, const uint port
		) {
	string url;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		url = "http://" + ip + ":" + to_string(port) + "/dpch";
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	};

	busy = true;
};

ConopengBrly::~ConopengBrly() {
	if (curl) curl_easy_cleanup(curl);
};

/******************************************************************************
 class NodeBrly
 ******************************************************************************/

NodeBrly::NodeBrly(
			const ubigint nref
			, const string& ip
			, const uint port
			, const uint opprcn
			, const uint ixBrlyVOpengtype
		) {
	this->nref = nref;
	this->ip = ip;
	this->port = port;
	this->opprcn = opprcn;
	this->ixBrlyVOpengtype = ixBrlyVOpengtype;

	vector<uint> icsBrlyVOppack;
	
	OpengBrly::getIcsBrlyVOppackByIxBrlyVOpengtype(ixBrlyVOpengtype, icsBrlyVOppack);
	for (unsigned int i=0;i<icsBrlyVOppack.size();i++) OpengBrly::getIcsBrlyVDpchByIxBrlyVOppack(icsBrlyVOppack[i], icsBrlyVDpch);

	opprcbusy = 0;

	err = false;

	Mutex::init(&mCons, false, "mCons", "NodeBrly", "NodeBrly");
};

NodeBrly::~NodeBrly() {
	Mutex::destroy(&mCons, false, "mCons", "NodeBrly", "~NodeBrly");

	for (unsigned int i=0;i<cons.size();i++) delete cons[i];
};

ConopengBrly* NodeBrly::getCon() {
	ConopengBrly* con;

	Mutex::lock(&mCons, "mCons", "NodeBrly", "getCon");

	con = NULL;

	// look for existing connections that are idle
	for (unsigned int i=0;i<cons.size();i++) {
		if (!cons[i]->busy) {
			con = cons[i];
			con->busy = true;
			break;
		};
	};

	if (!con) {
		// create new connection
		con = new ConopengBrly(ip, port);
		cons.push_back(con);
	};

	Mutex::unlock(&mCons, "mCons", "NodeBrly", "getCon");

	return con;
};

// IP datajobprc.subs --- INSERT

/******************************************************************************
 class XchgdataBrlyJobprc
 ******************************************************************************/

XchgdataBrlyJobprc::XchgdataBrlyJobprc() {
};

/******************************************************************************
 class XchgBrlyd
 ******************************************************************************/

XchgBrlyd::XchgBrlyd() {
	// root job
	jrefRoot = 0;

	// job receiving commands
	jrefCmd = 0;

	// scrambled ref codes
	Mutex::init(&mScr, true, "mScr", "XchgBrlyd", "XchgBrlyd");

	// log file
	Mutex::init(&mLogfile, true, "mLogfile", "XchgBrlyd", "XchgBrlyd");

	// condition for op engine client
	Mutex::init(&mcOpengcli, true, "mcOpengcli", "XchgBrlyd", "XchgBrlyd");
	Cond::init(&cOpengcli, "cOpengcli", "XchgBrlyd", "XchgBrlyd");

	// condition for job processors
	Mutex::init(&mcJobprcs, true, "mcJobprcs", "XchgBrlyd", "XchgBrlyd");
	Cond::init(&cJobprcs, "cJobprcs", "XchgBrlyd", "XchgBrlyd");

	// request list
	Mutex::init(&mReqs, true, "mReqs", "XchgBrlyd", "XchgBrlyd");

	// operation invocation list
	orefseq = new Refseq("orefseq");
	Mutex::init(&mInvs, true, "mInvs", "XchgBrlyd", "XchgBrlyd");

	// presetting list
	Mutex::init(&mPresets, true, "mPresets", "XchgBrlyd", "XchgBrlyd");

	// stub manager list
	Mutex::init(&mStmgrs, true, "mStmgrs", "XchgBrlyd", "XchgBrlyd");

	// call listener list
	Mutex::init(&mClstns, true, "mClstns", "XchgBrlyd", "XchgBrlyd");

	// dispatch collector list
	Mutex::init(&mDcols, true, "mDcols", "XchgBrlyd", "XchgBrlyd");

	// job list
	jrefseq = new Refseq("jrefseq");
	Mutex::init(&mJobs, true, "mJobs", "XchgBrlyd", "XchgBrlyd");

	// sequence for wakeup references
	wrefseq = new Refseq("wrefseq");

	// node list
	nrefseq = new Refseq("nrefseq");
	Mutex::init(&mNodes, true, "mNodes", "XchgBrlyd", "XchgBrlyd");

	curlrecv = NULL;
	curlrecvlen = 0;
};

XchgBrlyd::~XchgBrlyd() {
	// empty out lists
	for (auto it=reqs.begin();it!=reqs.end();it++) delete(*it);
	for (auto it=invs.begin();it!=invs.end();it++) delete(*it);
	for (auto it=presets.begin();it!=presets.end();it++) delete(it->second);
	for (auto it=stmgrs.begin();it!=stmgrs.end();it++) delete(it->second);
	for (auto it=clstns.begin();it!=clstns.end();it++) delete(it->second);
	for (auto it=dcols.begin();it!=dcols.end();it++) delete(it->second);
	for (auto it=jobs.begin();it!=jobs.end();it++) delete(it->second);
	for (auto it=nodes.begin();it!=nodes.end();it++) delete(it->second);

	// scrambled ref codes
	Mutex::destroy(&mScr, true, "mScr", "XchgBrlyd", "~XchgBrlyd");

	// log file
	Mutex::destroy(&mLogfile, true, "mLogfile", "XchgBrlyd", "~XchgBrlyd");

	// condition for op engine client
	Mutex::destroy(&mcOpengcli, true, "mcOpengcli", "XchgBrlyd", "~XchgBrlyd");
	Cond::destroy(&cOpengcli, "cOpengcli", "XchgBrlyd", "~XchgBrlyd");

	// condition for job processors
	Mutex::destroy(&mcJobprcs, true, "mcJobprcs", "XchgBrlyd", "~XchgBrlyd");
	Cond::destroy(&cJobprcs, "cJobprcs", "XchgBrlyd", "~XchgBrlyd");

	// request list
	Mutex::destroy(&mReqs, true, "mReqs", "XchgBrlyd", "~XchgBrlyd");

	// operation invocation list
	delete orefseq;
	Mutex::destroy(&mInvs, true, "mInvs", "XchgBrlyd", "~XchgBrlyd");

	// presetting list
	Mutex::destroy(&mPresets, true, "mPresets", "XchgBrlyd", "~XchgBrlyd");

	// stub manager list
	Mutex::destroy(&mStmgrs, true, "mStmgrs", "XchgBrlyd", "~XchgBrlyd");

	// call listener list
	Mutex::destroy(&mClstns, true, "mClstns", "XchgBrlyd", "~XchgBrlyd");

	// dispatch collector list
	Mutex::destroy(&mDcols, true, "mDcols", "XchgBrlyd", "~XchgBrlyd");

	// job list
	delete jrefseq;
	Mutex::destroy(&mJobs, true, "mJobs", "XchgBrlyd", "~XchgBrlyd");

	// sequence for wakeup references
	delete wrefseq;

	// node list
	delete nrefseq;
	Mutex::destroy(&mNodes, true, "mNodes", "XchgBrlyd", "~XchgBrlyd");
};

// IP cust --- INSERT

void XchgBrlyd::startMon() {
	JobBrly* job = NULL;

	DcolBrly* dcol = NULL;
	bool Dcol;

	StmgrBrly* stmgr = NULL;
	bool Stmgr;

	Clstn* clstn = NULL;
	Preset* preset = NULL;
	NodeBrly* node = NULL;

	mon.start("BeamRelay 0.2.2", stgbrlymonitor.ixDbsVDbstype, stgbrlymonitor.dbspath, stgbrlymonitor.dbsname, stgbrlymonitor.ip, stgbrlymonitor.port, stgbrlymonitor.dbsusername, stgbrlymonitor.dbspassword, stgbrlymonitor.username, stgbrlymonitor.password);

	Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "startMon");
	for (auto it=jobs.begin();it!=jobs.end();it++) {
		job = it->second;

		dcol = getDcolByJref(job->jref, false);
		if (dcol) {
			Dcol = true;
			dcol->unlockAccess("XchgBrlyd", "startMon");
		} else Dcol = false;

		stmgr = getStmgrByJref(job->jref);
		if (stmgr) {
			Stmgr = true;
			stmgr->unlockAccess("XchgBrlyd", "startMon");
		} else Stmgr = false;

		mon.insertJob(job->jrefSup, VecBrlyVJob::getSref(job->ixBrlyVJob), job->jref, (job->jrefMast == job->jref), (job->jrefMast == job->jref) && (job->jrefMast != 0), Dcol, Stmgr);
	};
	Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "startMon");

	Mutex::lock(&mClstns, "mClstns", "XchgBrlyd", "startMon");
	for (auto it=clstns.begin();it!=clstns.end();it++) {
		clstn = it->second;
		mon.insertClstn(clstn->cref.jref, VecBrlyVCall::getSref(clstn->cref.ixVCall), clstn->cref.stmgr, Clstn::VecVJobmask::getSref(clstn->cref.ixVJobmask), clstn->cref.jrefTrig, clstn->argMask.writeText(), Clstn::VecVJactype::getSref(clstn->ixVJactype));
	};
	Mutex::unlock(&mClstns, "mClstns", "XchgBrlyd", "startMon");

	Mutex::lock(&mPresets, "mPresets", "XchgBrlyd", "startMon");
	for (auto it=presets.begin();it!=presets.end();it++) {
		preset = it->second;
		mon.insertPreset(preset->pref.jref, VecBrlyVPreset::getSref(preset->pref.ixVPreset), preset->arg.writeText());
	};
	Mutex::unlock(&mPresets, "mPresets", "XchgBrlyd", "startMon");

	Mutex::lock(&mNodes, "mNodes", "XchgBrlyd", "startMon");
	for (auto it=nodes.begin();it!=nodes.end();it++) {
		node = it->second;
		mon.insertNode(node->nref, node->ip, node->port, node->opprcn);
	};
	Mutex::unlock(&mNodes, "mNodes", "XchgBrlyd", "startMon");

	triggerCall(NULL, VecBrlyVCall::CALLBRLYMONSTATCHG, jrefRoot);
};

void XchgBrlyd::stopMon() {
	mon.stop();

	triggerCall(NULL, VecBrlyVCall::CALLBRLYMONSTATCHG, jrefRoot);
};

void XchgBrlyd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	Mutex::lock(&mLogfile, "mLogfile", "XchgBrlyd", "appendToLogfile");

	time(&rawtime);

	logfile.open("./log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	Mutex::unlock(&mLogfile, "mLogfile", "XchgBrlyd", "appendToLogfile");
};

void XchgBrlyd::addReq(
			ReqBrly* req
		) {
	Mutex::lock(&mReqs, "mReqs", "XchgBrlyd", "addReq");

	req->ixVState = ReqBrly::VecVState::WAITPRC;
	reqs.push_back(req);

	Mutex::unlock(&mReqs, "mReqs", "XchgBrlyd", "addReq");

	Cond::signal(&cJobprcs, &mcJobprcs, "cJobprcs", "mcJobprcs", "XchgBrlyd", "addReq");
};

ReqBrly* XchgBrlyd::pullFirstReq() {
	ReqBrly* req;

	// get first element from list
	Mutex::lock(&mReqs, "mReqs", "XchgBrlyd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqBrly::VecVState::PRC;
		reqs.pop_front();
	};

	Mutex::unlock(&mReqs, "mReqs", "XchgBrlyd", "pullFirstReq");

	return req;
};

void XchgBrlyd::addInvs(
			DbsBrly* dbsbrly
			, const ubigint jref
			, vector<DpchInvBrly*>& dpchinvs
		) {
	JobBrly* job;

	job = getJobByJref(jref);

	if (job != NULL) {
		// append to inv list and signal the news (note the double-lock)
		Mutex::lock(&mInvs, "mInvs", "XchgBrlyd", "addInvs");
		Mutex::lock(&(job->mOps), "job->mOps", "XchgBrlyd", "addInvs");

		for (unsigned int i=0;i<dpchinvs.size();i++) {
			job->addOp(dbsbrly, dpchinvs[i]);

			invs.push_back(dpchinvs[i]);

			mon.eventAddInv(jref, VecBrlyVDpch::getSref(dpchinvs[i]->ixBrlyVDpch), "", dpchinvs[i]->oref);
		};

		Mutex::unlock(&(job->mOps), "job->mOps", "XchgBrlyd", "addInvs");
		Mutex::unlock(&mInvs, "mInvs", "XchgBrlyd", "addInvs");

		Cond::signal(&cOpengcli, &mcOpengcli, "cOpengcli", "mcOpengcli", "XchgBrlyd", "addInvs");
	};
};

bool XchgBrlyd::pullFirstInv(
			DpchInvBrly** dpchinv
			, NodeBrly** node
		) {
	bool match = false;

	// retrieve first match inv-node
	Mutex::lock(&mInvs, "mInvs", "XchgBrlyd", "pullFirstInv");
	Mutex::lock(&mNodes, "mNodes", "XchgBrlyd", "pullFirstInv");

	for (auto it=invs.begin();it!=invs.end();it++) {
		*dpchinv = *it;

		for (auto it2=nodes.begin();it2!=nodes.end();it2++) {
			*node = it2->second;

			if ( ((*node)->opprcbusy < (*node)->opprcn) && !(*node)->err ) {

				// node available ; check compatibility with inv

				if ((*node)->icsBrlyVDpch.find((*dpchinv)->ixBrlyVDpch) != (*node)->icsBrlyVDpch.end()) {
					// match found

					// remove inv from list
					invs.erase(it);

					// increase busy count for node
					(*node)->opprcbusy++;

					match = true;
					break;
				};
			};

			if (match) break;
		};
		if (match) break;
	};

	if (!match) {
		*dpchinv = NULL;
		*node = NULL;
	};

	Mutex::unlock(&mNodes, "mNodes", "XchgBrlyd", "pullFirstInv");
	Mutex::unlock(&mInvs, "mInvs", "XchgBrlyd", "pullFirstInv");

	return(match);
};

void XchgBrlyd::returnInv(
			DpchInvBrly* dpchinv
		) {
	// un-successful execution of op returns

	// append to inv list and signal the news
	Mutex::lock(&mInvs, "mInvs", "XchgBrlyd", "returnInv");
	invs.push_back(dpchinv);
	Mutex::unlock(&mInvs, "mInvs", "XchgBrlyd", "returnInv");

	Cond::signal(&cOpengcli, &mcOpengcli, "cOpengcli", "mcOpengcli", "XchgBrlyd", "returnInv");
};

Preset* XchgBrlyd::addPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const Arg& arg
		) {
	presetref_t pref(jref, ixBrlyVPreset);
	Preset* preset;

	// create new presetting (override value if exists) and append to presetting list
	Mutex::lock(&mPresets, "mPresets", "XchgBrlyd", "addPreset");

	preset = getPresetByPref(pref);

	if (preset) {
		preset->arg = arg;

		mon.eventChangePreset(jref, VecBrlyVPreset::getSref(ixBrlyVPreset), arg.writeText());

	} else {
		preset = new Preset(pref, arg);
		presets.insert(pair<presetref_t,Preset*>(pref, preset));

		mon.eventAddPreset(jref, VecBrlyVPreset::getSref(ixBrlyVPreset), arg.writeText());
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgBrlyd", "addPreset");

	return(preset);
};

Preset* XchgBrlyd::addIxPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const uint ix
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX)));
};

Preset* XchgBrlyd::addRefPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const ubigint ref
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF)));
};

Preset* XchgBrlyd::addRefsPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const vector<ubigint>& refs
		) {
	Arg arg(0, 0, refs, "", 0, 0.0, false, "", Arg::REFS);

	return(addPreset(ixBrlyVPreset, jref, arg));
};

Preset* XchgBrlyd::addSrefPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const string& sref
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF)));
};

Preset* XchgBrlyd::addIntvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const int intval
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, 0, {}, "", intval, 0.0, false, "", Arg::INTVAL)));
};

Preset* XchgBrlyd::addDblvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const double dblval
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, 0, {}, "", 0, dblval, false, "", Arg::DBLVAL)));
};

Preset* XchgBrlyd::addBoolvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const bool boolval
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, boolval, "", Arg::BOOLVAL)));
};

Preset* XchgBrlyd::addTxtvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const string& txtval
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, false, txtval, Arg::TXTVAL)));
};

Preset* XchgBrlyd::getPresetByPref(
			const presetref_t& pref
		) {
	Preset* preset = NULL;

	Mutex::lock(&mPresets, "mPresets", "XchgBrlyd", "getPresetByPref");

	auto it = presets.find(pref);
	if (it != presets.end()) preset = it->second;

	Mutex::unlock(&mPresets, "mPresets", "XchgBrlyd", "getPresetByPref");

	return preset;
};

Arg XchgBrlyd::getPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg;

	JobBrly* job = NULL;
	Preset* preset = NULL;

	if ( (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSDATE) || (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSTIME) || (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSSTAMP) ) {
		time_t rawtime;
		time(&rawtime);

		arg.mask = Arg::INTVAL;

		if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSDATE) arg.intval = (rawtime-rawtime%(3600*24))/(3600*24);
		else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSTIME) arg.intval = rawtime%(3600*24);
		else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSSTAMP) arg.intval = rawtime;

	} else {
		Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "getPreset");
		Mutex::lock(&mPresets, "mPresets", "XchgBrlyd", "getPreset");
		
		job = getJobByJref(jref);

		if ( (job != NULL) && (ixBrlyVPreset == VecBrlyVPreset::PREBRLYIXLCL) ) {
			arg.mask = Arg::IX;
			arg.ix = job->ixBrlyVLocale;

		} else {
			while (job && !preset) {
				preset = getPresetByPref(presetref_t(job->jref, ixBrlyVPreset));

				if (preset) arg = preset->arg;
				else job = getJobByJref(job->jrefSup);
			};
		};

		Mutex::unlock(&mPresets, "mPresets", "XchgBrlyd", "getPreset");
		Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "getPreset");
	};

	return(arg);
};

uint XchgBrlyd::getIxPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::IX) return(arg.ix);
	else return(0);
};

ubigint XchgBrlyd::getRefPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::REF) return(arg.ref);
	else return(0);
};

vector<ubigint> XchgBrlyd::getRefsPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);
	vector<ubigint> empty;

	if (arg.mask & Arg::REFS) return(arg.refs);
	else return(empty);
};

string XchgBrlyd::getSrefPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::SREF) return(arg.sref);
	else return("");
};

int XchgBrlyd::getIntvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::INTVAL) return(arg.intval);
	else return(intvalInvalid);
};

double XchgBrlyd::getDblvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::DBLVAL) return(arg.dblval);
	else return(dblvalInvalid);
};

bool XchgBrlyd::getBoolvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::BOOLVAL) return(arg.boolval);
	else return(false);
};

string XchgBrlyd::getTxtvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::TXTVAL) return(arg.txtval);
	else return("");
};

void XchgBrlyd::getPresetsByJref(
			const ubigint jref
			, vector<uint>& icsBrlyVPreset
			, vector<Arg>& args
		) {
	Preset* preset = NULL;

	icsBrlyVPreset.clear();
	args.clear();

	Mutex::lock(&mPresets, "mPresets", "XchgBrlyd", "getPresetsByJref");

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		preset = it->second;

		icsBrlyVPreset.push_back(preset->pref.ixVPreset);
		args.push_back(preset->arg);
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgBrlyd", "getPresetsByJref");
};

void XchgBrlyd::removePreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Mutex::lock(&mPresets, "mPresets", "XchgBrlyd", "removePreset");

	auto it = presets.find(presetref_t(jref, ixBrlyVPreset));
	if (it != presets.end()) {
		delete it->second;
		presets.erase(it);

		mon.eventRemovePreset(jref, VecBrlyVPreset::getSref(ixBrlyVPreset));
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgBrlyd", "removePreset");
};

void XchgBrlyd::removePresetsByJref(
			const ubigint jref
		) {
	Mutex::lock(&mPresets, "mPresets", "XchgBrlyd", "removePresetsByJref");

	uint ixVPreset;

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		ixVPreset = it->second->pref.ixVPreset;
		delete it->second;

		mon.eventRemovePreset(jref, VecBrlyVPreset::getSref(ixVPreset));
	};
	presets.erase(rng.first, rng.second);

	Mutex::unlock(&mPresets, "mPresets", "XchgBrlyd", "removePresetsByJref");
};

StmgrBrly* XchgBrlyd::addStmgr(
			const ubigint jref
			, const uint ixVNonetype
		) {
	StmgrBrly* stmgr = NULL;

	// create new stmgr and append to stmgr list
	Mutex::lock(&mStmgrs, "mStmgrs", "XchgBrlyd", "addStmgr");

	stmgr = getStmgrByJref(jref);

	if (!stmgr) {
		stmgr = new StmgrBrly(this, jref, ixVNonetype);
		stmgrs[jref] = stmgr;

		mon.eventAddStmgr(jref);
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgBrlyd", "addStmgr");

	return(stmgr);
};

StmgrBrly* XchgBrlyd::getStmgrByJref(
			const ubigint jref
		) {
	StmgrBrly* stmgr = NULL;

	Mutex::lock(&mStmgrs, "mStmgrs", "XchgBrlyd", "getStmgrByJref");

	auto it = stmgrs.find(jref);

	if (it != stmgrs.end()) {
		stmgr = it->second;
		stmgr->lockAccess("XchgBrlyd", "getStmgrByJref");
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgBrlyd", "getStmgrByJref");

	return(stmgr);
};

void XchgBrlyd::removeStmgrByJref(
			const ubigint jref
		) {
	Mutex::lock(&mStmgrs, "mStmgrs", "XchgBrlyd", "removeStmgrByJref");

	removeClstnsByJref(jref, true);

	auto it = stmgrs.find(jref);
	if (it != stmgrs.end()) {
		delete it->second;
		stmgrs.erase(it);

		mon.eventRemoveStmgr(jref);
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgBrlyd", "removeStmgrByJref");
};

Clstn* XchgBrlyd::addClstn(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const Arg& argMask
			, const uint ixVJactype
		) {
	clstnref_t cref(ixBrlyVCall, jref, false, ixVJobmask, jrefTrig);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	Mutex::lock(&mClstns, "mClstns", "XchgBrlyd", "addClstn");

	clstn = getClstnByCref(cref);

	if (clstn) {
		clstn->argMask = argMask;
		clstn->ixVJactype = ixVJactype;

		mon.eventChangeClstn(jref, VecBrlyVCall::getSref(ixBrlyVCall), false, Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, argMask.writeText(), Clstn::VecVJactype::getSref(ixVJactype));

	} else {
		clstn = new Clstn(cref, argMask, ixVJactype);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(jref, VecBrlyVCall::getSref(ixBrlyVCall), false, Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, argMask.writeText(), Clstn::VecVJactype::getSref(ixVJactype));
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgBrlyd", "addClstn");

	return(clstn);
};

Clstn* XchgBrlyd::addIxClstn(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, 0, {}, "", 0, 0.0, false, "", Arg::IX);

	return(addClstn(ixBrlyVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgBrlyd::addRefClstn(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const ubigint refMask
			, const uint ixVJactype
		) {
	Arg argMask(0, refMask, {}, "", 0, 0.0, false, "", Arg::REF);

	return(addClstn(ixBrlyVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgBrlyd::addIxRefClstn(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const ubigint refMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, refMask, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);

	return(addClstn(ixBrlyVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgBrlyd::addIxRefSrefClstn(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const ubigint refMask
			, const string& srefMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, refMask, {}, srefMask, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);

	return(addClstn(ixBrlyVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgBrlyd::addClstnStmgr(
			const uint ixBrlyVCall
			, const ubigint jref
		) {
	clstnref_t cref(ixBrlyVCall, jref, true, Clstn::VecVJobmask::ALL, 0);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	Mutex::lock(&mClstns, "mClstns", "XchgBrlyd", "addClstnStmgr");

	clstn = getClstnByCref(cref);

	if (!clstn) {
		clstn = new Clstn(cref, Arg(), Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(jref, VecBrlyVCall::getSref(ixBrlyVCall), true, Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::ALL), 0, "", Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgBrlyd", "addClstnStmgr");

	return(clstn);
};

Clstn* XchgBrlyd::getClstnByCref(
			const clstnref_t& cref
		) {
	Clstn* clstn = NULL;

	Mutex::lock(&mClstns, "mClstns", "XchgBrlyd", "getClstnByCref");

	auto it = clstns.find(cref);
	if (it != clstns.end()) clstn = it->second;

	Mutex::unlock(&mClstns, "mClstns", "XchgBrlyd", "getClstnByCref");

	return clstn;
};

void XchgBrlyd::getClstnsByJref(
			const ubigint jref
			, const bool stmgr
			, vector<uint>& icsBrlyVCall
			, vector<uint>& icsVJobmask
		) {
	Clstn* clstn = NULL;

	icsBrlyVCall.clear();
	icsVJobmask.clear();

	Mutex::lock(&mClstns, "mClstns", "XchgBrlyd", "getClstnsByJref");

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, stmgr, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		clstn = getClstnByCref(it->second);

		if (clstn) {
			icsBrlyVCall.push_back(clstn->cref.ixVCall);
			icsVJobmask.push_back(clstn->cref.ixVJobmask);
		};
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgBrlyd", "getClstnsByJref");
};

void XchgBrlyd::removeClstns(
			const uint ixBrlyVCall
			, const ubigint jref
			, const bool stmgr
		) {
	Mutex::lock(&mClstns, "mClstns", "XchgBrlyd", "removeClstns");

	uint ixVJobmask;
	ubigint jrefTrig;

	auto rng = clstns.equal_range(clstnref_t(ixBrlyVCall, jref, stmgr));
	for (auto it=rng.first;it!=rng.second;it++) {
		ixVJobmask = it->second->cref.ixVJobmask;
		jrefTrig = it->second->cref.jrefTrig;

		cref2sClstns.erase(clstnref2_t(it->first));
		delete it->second;

		mon.eventRemoveClstn(jref, VecBrlyVCall::getSref(ixBrlyVCall), stmgr, Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig);
	};
	clstns.erase(rng.first, rng.second);

	Mutex::unlock(&mClstns, "mClstns", "XchgBrlyd", "removeClstns");
};

void XchgBrlyd::removeClstnsByJref(
			const ubigint jref
			, const bool stmgr
		) {
	Mutex::lock(&mClstns, "mClstns", "XchgBrlyd", "removeClstnsByJref");

	uint ixVCall;
	uint ixVJobmask;
	ubigint jrefTrig;

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, stmgr));
	for (auto it=rng.first;it!=rng.second;it++) {
		auto it2 = clstns.find(it->second);

		ixVCall = it2->second->cref.ixVCall;
		ixVJobmask = it2->second->cref.ixVJobmask;
		jrefTrig = it2->second->cref.jrefTrig;

		delete it2->second;
		clstns.erase(it2);

		mon.eventRemoveClstn(jref, VecBrlyVCall::getSref(ixVCall), stmgr, Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig);
	};
	cref2sClstns.erase(rng.first, rng.second);

	Mutex::unlock(&mClstns, "mClstns", "XchgBrlyd", "removeClstnsByJref");
};

void XchgBrlyd::findJrefsByCall(
			Call* call
			, vector<ubigint>& jrefs
			, vector<bool>& stmgrs
			, vector<uint>& icsVJactype
		) {
	Clstn* clstn = NULL;

	JobBrly* job = NULL;

	bool match;

	Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "findJrefsByCall");
	Mutex::lock(&mClstns, "mClstns", "XchgBrlyd", "findJrefsByCall");

	auto rng = clstns.equal_range(clstnref_t(call->ixVCall, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		clstn = it->second;

		if (clstn->cref.stmgr) {
			jrefs.push_back(clstn->cref.jref);
			stmgrs.push_back(true);
			icsVJactype.push_back(0);

		} else {
			match = true;

			if (clstn->argMask.mask & Arg::IX) if (clstn->argMask.ix != call->argInv.ix) match = false;
			if (clstn->argMask.mask & Arg::REF) if (clstn->argMask.ref != call->argInv.ref) match = false;
			if (clstn->argMask.mask & Arg::SREF) if (clstn->argMask.sref != call->argInv.sref) match = false;
			if (clstn->argMask.mask & Arg::INTVAL) if (clstn->argMask.intval != call->argInv.intval) match = false;
			if (clstn->argMask.mask & Arg::DBLVAL) if (clstn->argMask.dblval != call->argInv.dblval) match = false;
			if (clstn->argMask.mask & Arg::BOOLVAL) if (clstn->argMask.boolval != call->argInv.boolval) match = false;
			if (clstn->argMask.mask & Arg::TXTVAL) if (clstn->argMask.txtval != call->argInv.txtval) match = false;

			if (match) {
				match = false;

				if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::ALL) {
					// don't care about call->jref
					match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::IMM) {
					// check if trigger job is immediate sub-job to listener job
					job = getJobByJref(call->jref);
					if (job) if (job->jrefSup == clstn->cref.jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::MAST) {
					// check if trigger job is master-job to listener job
					if (call->jref != clstn->cref.jref) {
						job = getJobByJref(clstn->cref.jref);
						if (job) if (call->jref == job->jrefMast) match = true;
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SELF) {
					// check if trigger job is equivalent to listener job
					if (call->jref == clstn->cref.jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SLV) {
					// check if listener job is master-job to trigger job
					if (call->jref != clstn->cref.jref) {
						job = getJobByJref(call->jref);
						if (job) if (clstn->cref.jref == job->jrefMast) match = true;
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
					// require specific jref
					if (clstn->cref.jrefTrig == call->jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::TREE) {
					// check if trigger job is down the tree from listener job ; note that the order in jobs is unordered (unfortunately)
					job = getJobByJref(call->jref);

					while (job != NULL) {
						if (job->jref == clstn->cref.jref) {
							// add
							match = true;
							break;
						};

						job = getJobByJref(job->jrefSup);
					};
				};
			};

			if (match) {
				jrefs.push_back(clstn->cref.jref);
				stmgrs.push_back(false);
				icsVJactype.push_back(clstn->ixVJactype);
			};
		};
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgBrlyd", "findJrefsByCall");
	Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "findJrefsByCall");
};

void XchgBrlyd::triggerCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	vector<ubigint> jrefs;
	vector<bool> stmgrs;
	vector<uint> icsVJactype;

	ubigint jref;
	uint ixVJactype;

	StmgrBrly* stmgr = NULL;

	JobBrly* job = NULL;

	ubigint eref;

	Arg argRet_old;

	eref = mon.eventTriggerCall(call->jref, VecBrlyVCall::getSref(call->ixVCall), call->argInv.writeText());

	findJrefsByCall(call, jrefs, stmgrs, icsVJactype);

	for (unsigned int i=0;i<jrefs.size();i++) {
		jref = jrefs[i];
		ixVJactype = icsVJactype[i];

		if (stmgrs[i]) {
			stmgr = getStmgrByJref(jref);

			if (stmgr) {
				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				stmgr->handleCall(dbsbrly, call);

				if (!(call->argRet == argRet_old)) mon.eventRetCall(eref, jref, call->argRet.writeText());

				stmgr->unlockAccess("XchgBrlyd", "triggerCall");
			};

		} else {
			job = getJobByJref(jref);
			if (job) {
				if (ixVJactype != Clstn::VecVJactype::WEAK) {
					if (ixVJactype == Clstn::VecVJactype::LOCK) {
						job->lockAccess("XchgBrlyd", "triggerCall");

					} else if (ixVJactype == Clstn::VecVJactype::TRY) {
						if (Mutex::trylock(&(job->mAccess), "job(" + to_string(jref) + ")->mAccess", "XchgBrlyd", "triggerCall") == EBUSY) continue;
					};
				};

				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				job->handleCall(dbsbrly, call);

				if (call->argRet != argRet_old) mon.eventRetCall(eref, jref, call->argRet.writeText());
			};

			if (ixVJactype != Clstn::VecVJactype::WEAK) {
				job = getJobByJref(jref);
				if (job) job->unlockAccess("XchgBrlyd", "triggerCall");
			};
		};

		if (call->abort) break;
	};

	mon.eventFinalizeCall(eref);
};

bool XchgBrlyd::triggerArgToArgCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const Arg& argInv
			, Arg& argRet
		) {
	Call* call;
	ubigint retval;

  call = new Call(ixBrlyVCall, jref, argInv);
	triggerCall(dbsbrly, call);

	argRet = call->argRet;
	retval = call->abort;

  delete call;
	return retval;
};

bool XchgBrlyd::triggerCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
		) {
	Arg argInv;
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlyd::triggerIxCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlyd::triggerRefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const ubigint refInv
		) {
	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlyd::triggerIntvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const int intvalInv
		) {
	Arg argInv(0, 0, {}, "", intvalInv, 0.0, false, "", Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlyd::triggerBoolvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const bool boolvalInv
		) {
	Arg argInv(0, 0, {}, "", 0, 0.0, boolvalInv, "", Arg::BOOLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlyd::triggerIxRefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
		) {
	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlyd::triggerIxSrefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
		) {
	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlyd::triggerIxIntvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const int intvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", intvalInv, 0.0, false, "", Arg::IX + Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlyd::triggerIxDblvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const double dblvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, dblvalInv, false, "", Arg::IX + Arg::DBLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlyd::triggerIxTxtvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const string& txtvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, txtvalInv, Arg::IX + Arg::TXTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlyd::triggerToBoolvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv;
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgBrlyd::triggerIxToBoolvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgBrlyd::triggerRefToSrefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const ubigint refInv
			, string& srefRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) srefRet = argRet.sref;

	return(retval);
};

bool XchgBrlyd::triggerRefToBoolvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgBrlyd::triggerIxRefToIxCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgBrlyd::triggerIxRefToRefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgBrlyd::triggerIxRefSrefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgBrlyd::triggerIxRefSrefIntvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgBrlyd::triggerIxRefSrefIntvalToRefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgBrlyd::triggerRefToIxCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgBrlyd::triggerSrefToRefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const string& srefInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

DcolBrly* XchgBrlyd::addDcol(
			const ubigint jref
		) {
	JobBrly* job = NULL;

	DcolBrly* dcol = NULL;

	// create new dcol and append to dcol list
	Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "addDcol");
	Mutex::lock(&mDcols, "mDcols", "XchgBrlyd", "addDcol");

	job = getJobByJref(jref);

	if (job) {
		dcol = getDcolByJref(jref);

		if (!dcol) {
			dcol = new DcolBrly(jref, job->ixBrlyVLocale);
			dcols[jref] = dcol;

			mon.eventAddDcol(jref);

			dcol->lockAccess("XchgBrlyd", "addDcol");
		};

		// make dcol the session's active notify dcol
		triggerIxRefCall(NULL, VecBrlyVCall::CALLBRLYREFPRESET, jref, VecBrlyVPreset::PREBRLYJREFNOTIFY, jref);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgBrlyd", "addDcol");
	Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "addDcol");

	return(dcol);
};

DcolBrly* XchgBrlyd::getDcolByJref(
			const ubigint jref
			, const bool tree
		) {
	JobBrly* job = NULL;

	DcolBrly* dcol = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "getDcolByJref");
	Mutex::lock(&mDcols, "mDcols", "XchgBrlyd", "getDcolByJref");

	job = getJobByJref(jref);

	while (job != NULL) {
		auto it = dcols.find(job->jref);

		if (it != dcols.end()) {
			dcol = it->second;
			dcol->lockAccess("XchgBrlyd", "getDcolByJref");

			break;
		};

		if (!tree) break;

		job = getJobByJref(job->jrefSup);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgBrlyd", "addDcol");
	Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "addDcol");

	return(dcol);
};

void XchgBrlyd::removeDcolByJref(
			const ubigint jref
		) {
	Mutex::lock(&mDcols, "mDcols", "XchgBrlyd", "removeDcolByJref");

	auto it = dcols.find(jref);
	if (it != dcols.end()) {
		delete it->second;
		dcols.erase(it);

		mon.eventRemoveDcol(jref);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgBrlyd", "removeDcolByJref");
};

void XchgBrlyd::submitDpch(
			DpchEngBrly* dpcheng
		) {
	DcolBrly* dcol = NULL;

	pthread_cond_t* cReady_backup;
	pthread_mutex_t* mcReady_backup;

	DpchEngBrly* dpchtest;

	// find dcol in charge
	dcol = getDcolByJref(dpcheng->jref);

	if (dcol) {
		mon.eventSubmitDpch(dpcheng->jref, VecBrlyVDpch::getSref(dpcheng->ixBrlyVDpch), dpcheng->getSrefsMask(), "");

		if (dcol->req != NULL) {
			// a request is waiting
			delete dcol->req->dpcheng;
			dcol->req->dpcheng = dpcheng;

			cReady_backup = &(dcol->req->cReady);
			mcReady_backup = &(dcol->req->mcReady);

			dcol->req = NULL;
			//cout << "XchgBrlyd::submitDpch() waiting request for ixBrlyVDpch = " << dpcheng->ixBrlyVDpch << ", jref = " << dpcheng->jref << endl;

			Cond::signal(cReady_backup, mcReady_backup, "dcol(" + to_string(dcol->jref) + ")->req->cReady", "dcol(" + to_string(dcol->jref) + ")->req->mcReady", "XchgBrlyd", "submitDpch");

			dcol->unlockAccess("XchgBrlyd", "submitDpch");

		} else {
			// merge with similar dispatch if available
			for (auto it=dcol->dpchs.begin();it!=dcol->dpchs.end();) {
				dpchtest = *it;

				if ((dpchtest->ixBrlyVDpch == dpcheng->ixBrlyVDpch) && (dpchtest->jref == dpcheng->jref)) {
					dpchtest->merge(dpcheng);
					//cout << "XchgBrlyd::submitDpch() merge for ixBrlyVDpch = " << dpcheng->ixBrlyVDpch << ", jref = " << dpcheng->jref << endl;

					delete dpcheng;
					dpcheng = NULL;

					break;

				} else it++;
			};

			// append to list of dispatches
			if (dpcheng) {
				dcol->dpchs.push_back(dpcheng);
				//cout << "XchgBrlyd::submitDpch() append for ixBrlyVDpch = " << dpcheng->ixBrlyVDpch << ", jref = " << dpcheng->jref << endl;
			};

			dcol->unlockAccess("XchgBrlyd", "submitDpch");
		};

	} else {
		delete dpcheng;
	};
};

DpchEngBrly* XchgBrlyd::pullFirstDpch(
			DcolBrly* dcol
		) {
	DpchEngBrly* dpcheng = NULL;

	// get first element from list ; assume access is locked
	if (!dcol->dpchs.empty()) {
		dpcheng = *(dcol->dpchs.begin());
		dcol->dpchs.pop_front();
	};

	return dpcheng;
};

ubigint XchgBrlyd::addJob(
			JobBrly* job
		) {
	JobBrly* supjob = NULL;

	// get new jref and append to job list
	Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "addJob");

	job->jref = jrefseq->getNewRef();
	jobs[job->jref] = job;

	if (jobs.size() == 1) {
		// root job
		jrefRoot = job->jref;
		jrefCmd = job->jref;
	};

	supjob = getJobByJref(job->jrefSup);
	if (supjob) supjob->jrefsSub.insert(job->jref);

	mon.eventAddJob(job->jrefSup, VecBrlyVJob::getSref(job->ixBrlyVJob), job->jref);

	Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "addJob");

	return(job->jref);
};

ubigint XchgBrlyd::addJob(
			DbsBrly* dbsbrly
			, JobBrly* job
		) {
	JobBrly* supjob = NULL;

	JobBrly* mastjob = NULL;

	// get new jref, append to job list and integrate into master/slave structure
	Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "addJob");

	job->jref = jrefseq->getNewRef();
	jobs[job->jref] = job;

	supjob = getJobByJref(job->jrefSup);
	if (supjob) supjob->jrefsSub.insert(job->jref);

	mon.eventAddJob(job->jrefSup, VecBrlyVJob::getSref(job->ixBrlyVJob), job->jref);

	// find current master job
	for (auto it=jobs.begin();it!=jobs.end();it++) {
		if (it->second->ixBrlyVJob == job->ixBrlyVJob) {
			mastjob = getJobByJref(it->second->jrefMast);
			break;
		};
	};

	if (mastjob) {
		job->jrefMast = mastjob->jref;

		if (job->prefmast) {
			// priority for becoming new master
			mastjob->jrefsSlv.push_front(job->jref);

			mon.eventBecomeSlave(job->jref);

			job->becomeSlave(dbsbrly);

			claimMaster(dbsbrly, job->jref);

		} else {
			mastjob->jrefsSlv.push_back(job->jref);

			mon.eventBecomeSlave(job->jref);

			job->becomeSlave(dbsbrly);
		};

	} else {
		// only job of its type
		job->jrefMast = job->jref;

		mon.eventBecomeMaster(job->jref);

		job->becomeMaster(dbsbrly);
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "addJob");

	return(job->jref);
};

JobBrly* XchgBrlyd::getJobByJref(
			const ubigint jref
		) {
	JobBrly* job = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "getJobByJref");

	auto it = jobs.find(jref);
	if (it != jobs.end()) job = it->second;

	Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "getJobByJref");

	return job;
};

void XchgBrlyd::removeJobByJref(
			const ubigint jref
		) {
	JobBrly* supjob = NULL;
	JobBrly* job = NULL;
	JobBrly* subjob = NULL;

	JobBrly* mastjob = NULL;
	JobBrly* slvjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "removeJobByJref");

	job = getJobByJref(jref);

	if (job) {
		job->invalidateWakeups();

		removePresetsByJref(jref);
		removeStmgrByJref(jref);
		removeClstnsByJref(jref);
		removeDcolByJref(jref);

		// remove from master/slave structure
		if (job->jrefMast != 0) {
			if (job->jref == job->jrefMast) {
				mastjob = NULL;

				if (!job->jrefsSlv.empty()) {
					mon.eventGiveupMaster(job->jref);
					job->giveupMaster(NULL);

					mastjob = getJobByJref(job->jrefsSlv.front());
				};

				if (mastjob) {
					mon.eventGiveupSlave(mastjob->jref);
					mastjob->giveupSlave(NULL);

					mon.eventGiveupMaster(job->jref);
					job->giveupMaster(NULL);

					mastjob->jrefsSlv = job->jrefsSlv;
					mastjob->jrefsSlv.pop_front();

					mastjob->jrefMast = mastjob->jref;

					for (auto it=mastjob->jrefsSlv.begin();it!=mastjob->jrefsSlv.end();it++) {
						slvjob = getJobByJref(*it);
						if (slvjob) slvjob->jrefMast = mastjob->jref;
					};

					mon.eventBecomeMaster(mastjob->jref);
					mastjob->becomeMaster(NULL);

					triggerCall(NULL, VecBrlyVCall::CALLBRLYMASTSLVCHG, mastjob->jref);

				} else {
					mon.eventGiveupMaster(job->jref);
					job->giveupMaster(NULL);
				};

			} else {
				mon.eventGiveupSlave(job->jref);
				job->giveupSlave(NULL);

				mastjob = getJobByJref(job->jrefMast);
				if (mastjob) mastjob->jrefsSlv.remove(job->jref);
			};
		};

		// super-job
		supjob = getJobByJref(job->jrefSup);
		if (supjob) supjob->jrefsSub.erase(jref);

		// sub-jobs
		while (job->jrefsSub.size() > 0) {
			subjob = getJobByJref(*(job->jrefsSub.begin()));
			if (subjob) delete subjob;
		};

		// remove job from list only here otherwise sub-job delete will loop forever
		jobs.erase(jref);

		mon.eventRemoveJob(jref);
	};

	if (jobs.empty()) {
		// root job
		jrefRoot = 0;
		jrefCmd = 0;
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "removeJobByJref");
};

void XchgBrlyd::transferMaster(
			DbsBrly* dbsbrly
			, JobBrly* fromjob
			, JobBrly* tojob
		) {
	// requires mJobs locked and tojob at first position in fromjob->jrefsSlv
	JobBrly* job = NULL;

	mon.eventGiveupSlave(tojob->jref);
	tojob->giveupSlave(dbsbrly);

	mon.eventGiveupMaster(fromjob->jref);
	fromjob->giveupMaster(dbsbrly);

	tojob->jrefsSlv = fromjob->jrefsSlv;
	fromjob->jrefsSlv.clear();
	tojob->jrefsSlv.pop_front();

	if (fromjob->prefmast) tojob->jrefsSlv.push_front(fromjob->jref);
	else tojob->jrefsSlv.push_back(fromjob->jref);

	tojob->jrefMast = tojob->jref;

	for (auto it=tojob->jrefsSlv.begin();it!=tojob->jrefsSlv.end();it++) {
		job = getJobByJref(*it);
		if (job) job->jrefMast = tojob->jref;
	};

	mon.eventBecomeMaster(tojob->jref);
	tojob->becomeMaster(dbsbrly);

	mon.eventBecomeSlave(fromjob->jref);
	fromjob->becomeSlave(dbsbrly);

	triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYMASTSLVCHG, tojob->jref);
	triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYMASTSLVCHG, fromjob->jref);
};

void XchgBrlyd::offerMaster(
			DbsBrly* dbsbrly
			, const ubigint jref
		) {
	JobBrly* mastjob = NULL;
	JobBrly* slvjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "offerMaster");

	mastjob = getJobByJref(jref);

	if (mastjob) {
		if (!mastjob->jrefsSlv.empty()) {
			slvjob = getJobByJref(mastjob->jrefsSlv.front());

			if (slvjob) if (slvjob->prefmast) transferMaster(dbsbrly, mastjob, slvjob);
		};
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "offerMaster");
};

bool XchgBrlyd::claimMaster(
			DbsBrly* dbsbrly
			, const ubigint jref
		) {
	bool retval = false;

	JobBrly* mastjob = NULL;
	JobBrly* slvjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgBrlyd", "claimMaster");

	slvjob = getJobByJref(jref);

	if (slvjob) {
		if (slvjob->jref != slvjob->jrefMast) {
			mastjob = getJobByJref(slvjob->jrefMast);

			if (mastjob) {
				for (auto it=mastjob->jrefsSlv.begin();it!=mastjob->jrefsSlv.end();it++) {
					// put slvjob first
					if (*it == jref) {
						*it = mastjob->jrefsSlv.front();
						mastjob->jrefsSlv.pop_front();
						mastjob->jrefsSlv.push_front(jref);

						break;
					};
				};

				if (mastjob->handleClaimMaster(dbsbrly)) transferMaster(dbsbrly, mastjob, slvjob);
			};
		};

		retval = (slvjob->jref == slvjob->jrefMast);
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgBrlyd", "claimMaster");

	return retval;
};

ubigint XchgBrlyd::addWakeup(
			const ubigint jref
			, const string sref
			, const unsigned int deltat
			, const bool weak
		) {
	int res;

	ubigint wref;

	pthread_t timer;

	wref = wrefseq->getNewRef();

	if (deltat == 0) {
		// immediate callback: generate request to be treated by job processor
		ReqBrly* req = new ReqBrly(ReqBrly::VecVBasetype::TIMER);
		req->jref = jref;
		req->wref = wref;
		req->sref = sref;
		req->weak = false;

		addReq(req);

	} else {
		// delayed callback: generate dedicated wait thread
		WakeupBrly* wakeup = new WakeupBrly(this, wref, jref, sref, deltat, weak);

		res = pthread_create(&timer, NULL, &runWakeup, (void*) wakeup);
		if (res != 0) cout << "XchgBrlyd::addWakeup() error creating timer thread (" << res << ")" << endl;
		res = pthread_detach(timer);
		if (res != 0) cout << "XchgBrlyd::addWakeup() error detaching timer thread (" << res << ")" << endl;
	};

	return(wref);
};

void* XchgBrlyd::runWakeup(
			void* arg
		) {
	WakeupBrly* wakeup = (WakeupBrly*) arg;

	// wait for time specified in microseconds
	timespec deltat;
	deltat.tv_sec = wakeup->deltat / 1000000;
	deltat.tv_nsec = 1000 * (wakeup->deltat%1000000);
#ifdef _WIN32
	usleep(wakeup->deltat);
#else
	nanosleep(&deltat, NULL);
#endif

	// generate request to be treated by job processor
	ReqBrly* req = new ReqBrly(ReqBrly::VecVBasetype::TIMER);
	req->jref = wakeup->jref;
	req->wref = wakeup->wref;
	req->sref = wakeup->sref;
	req->weak = wakeup->weak;

	wakeup->xchg->addReq(req);

	delete wakeup;

	return(NULL);
};

void XchgBrlyd::runExtcall(
			void* arg
		) {
	ExtcallBrly* extcall = (ExtcallBrly*) arg;

	// generate request to be treated by job processor
	ReqBrly* req = new ReqBrly(ReqBrly::VecVBasetype::EXTCALL);
	req->call = new Call(*(extcall->call));

	extcall->xchg->addReq(req);
};

NodeBrly* XchgBrlyd::addNode(
			const string& ip
			, const uint port
			, const uint opprcn
			, const uint ixBrlyVOpengtype
		) {
	NodeBrly* node = NULL;

	Mutex::lock(&mNodes, "mNodes", "XchgBrlyd", "addNode");

	node = new NodeBrly(nrefseq->getNewRef(), ip, port, opprcn, ixBrlyVOpengtype);
	nodes[node->nref] = node;

	mon.eventAddNode(node->nref, ip, port, opprcn);

	Mutex::unlock(&mNodes, "mNodes", "XchgBrlyd", "addNode");

	Cond::signal(&cOpengcli, &mcOpengcli, "cOpengcli", "mcOpengcli", "XchgBrlyd", "addNode");

	triggerCall(NULL, VecBrlyVCall::CALLBRLYNODECHG, jrefRoot);

	return(node);
};

NodeBrly* XchgBrlyd::getNodeByNref(
			const ubigint nref
		) {
	NodeBrly* node = NULL;

	Mutex::lock(&mNodes, "mNodes", "XchgBrlyd", "getNodeByNref");

	auto it = nodes.find(nref);
	if (it != nodes.end()) node = it->second;

	Mutex::unlock(&mNodes, "mNodes", "XchgBrlyd", "getNodeByNref");

	return(node);
};

void XchgBrlyd::quitNodes() {
	Mutex::lock(&mNodes, "mNodes", "XchgBrlyd", "quitNodes");

	for (auto it=nodes.begin();it!=nodes.end();it++) quitNodeByNref(it->first);

	Mutex::unlock(&mNodes, "mNodes", "XchgBrlyd", "quitNodes");
};

void XchgBrlyd::quitNodeByNref(
			const ubigint nref
		) {
	NodeBrly* node = NULL;

	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;
	string rplydpch;

	Mutex::lock(&mNodes, "mNodes", "XchgBrlyd", "quitNodeByNref");

	node = getNodeByNref(nref);
	
	if (node) {
		// POST content (DpchBrlydQuit)
		Xmlio::startwriteBuffer(&wr, &xbuf);
			DpchBrlydQuit::writeXML(wr);
		Xmlio::closewriteBuffer(wr);

		if (CurlPostDpch("http://" + node->ip + ":" + to_string(node->port) + "/dpch", xbuf, &doc, &docctx, rplydpch)) {
			// evaluate reply
			if (rplydpch == "dpchbrlyopdack") {
				// acknowledged
			};

		} else {
			// cout << "\terror notifying op engine!" << endl;
		};

		if (docctx) xmlXPathFreeContext(docctx);
		if (doc) xmlFreeDoc(doc);
		xmlBufferFree(xbuf);
	};

	Mutex::unlock(&mNodes, "mNodes", "XchgBrlyd", "quitNodeByNref");
};

void XchgBrlyd::removeNodeByNref(
			const ubigint nref
		) {
	Mutex::lock(&mNodes, "mNodes", "XchgBrlyd", "removeNodeByNref");

	auto it = nodes.find(nref);
	if (it != nodes.end()) {
		delete it->second;
		nodes.erase(it);

		mon.eventRemoveNode(nref);
	};

	Mutex::unlock(&mNodes, "mNodes", "XchgBrlyd", "removeNodeByNref");

	triggerCall(NULL, VecBrlyVCall::CALLBRLYNODECHG, jrefRoot);
};

uint XchgBrlyd::CurlPostrecv(
			void* data
			, uint size
			, uint blocksize
			, void* _inst
		) {
	XchgBrlyd* inst = (XchgBrlyd*) _inst;

	char* olddata;

	if (size > 0) {
		if (!inst->curlrecv) {
			inst->curlrecv = new char[size*blocksize];
			memcpy(inst->curlrecv, data, size*blocksize);
			inst->curlrecvlen = size*blocksize;

		} else {
			olddata = inst->curlrecv;

			inst->curlrecv = new char[inst->curlrecvlen + size*blocksize];
			memcpy(inst->curlrecv, olddata, inst->curlrecvlen);
			memcpy(&(inst->curlrecv[inst->curlrecvlen]), data, size*blocksize);
			inst->curlrecvlen = inst->curlrecvlen + size*blocksize;

			delete[] olddata;
		};
	};

  return(size*blocksize);
};

bool XchgBrlyd::CurlPostDpch(
			const string& url
			, xmlBuffer* xbuf
			, xmlDoc** rplydoc
			, xmlXPathContext** rplydocctx
			, string& rplydpch
		) {
	CURL* curl;
	CURLcode res;

	bool retval = false;

	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

		// receive buffer
		if (curlrecv) delete[] curlrecv;
		curlrecv = NULL;
		curlrecvlen = 0;

		// string to be sent is "xml=<xbuf>"
		size_t buflen = xbuf->use + 4;
		char* buf = new char[buflen];

		buf[0] = 'x'; buf[1] = 'm'; buf[2] = 'l'; buf[3] = '=';
		memcpy(&(buf[4]), xbuf->content, xbuf->use);

		// strip '\r' and '\n' characters
		for (size_t i=0;i<buflen;) {
			if ((buf[i] == '\r') || (buf[i] == '\n')) {
				memmove(&(buf[i]), &(buf[i+1]), buflen-i-1);
				buflen--;
			} else i++;
		};

		// curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buf);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, buflen);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlPostrecv);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);

		res = curl_easy_perform(curl);

		delete[] buf;

		curl_easy_cleanup(curl);

		// evaluate result
		if (curlrecv) {
			if (res == 0) {
				// check for root XML node
				Xmlio::parseBuffer(curlrecv, curlrecvlen, rplydoc, rplydocctx);
				rplydpch = StrMod::lc(Xmlio::extractRoot(*rplydoc));
				retval = true;
			};

			delete[] curlrecv;
			curlrecv = NULL;
			curlrecvlen = 0;
		};
	};

	return retval;
};

