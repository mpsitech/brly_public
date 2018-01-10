/**
  * \file BrlyDyn_blks.cpp
  * invocation / return data blocks for operation pack BrlyDyn (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyDyn_blks.h"

/******************************************************************************
 class DpchInvBrlyDynConflt
 ******************************************************************************/

DpchInvBrlyDynConflt::DpchInvBrlyDynConflt(
			const ubigint oref
			, const ubigint jref
			, const ubigint refBrlyMConnection
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYDYNCONFLT, oref, jref) {
	this->refBrlyMConnection = refBrlyMConnection;
};

void DpchInvBrlyDynConflt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyDynConflt");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refBrlyMConnection", "", refBrlyMConnection)) add(REFBRLYMCONNECTION);
	};
};

void DpchInvBrlyDynConflt::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyDynConflt");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refBrlyMConnection", refBrlyMConnection);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyDynConseg
 ******************************************************************************/

DpchInvBrlyDynConseg::DpchInvBrlyDynConseg(
			const ubigint oref
			, const ubigint jref
			, const ubigint refBrlyMConnection
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYDYNCONSEG, oref, jref) {
	this->refBrlyMConnection = refBrlyMConnection;
};

void DpchInvBrlyDynConseg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyDynConseg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refBrlyMConnection", "", refBrlyMConnection)) add(REFBRLYMCONNECTION);
	};
};

void DpchInvBrlyDynConseg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyDynConseg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refBrlyMConnection", refBrlyMConnection);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyDynEqplist
 ******************************************************************************/

DpchInvBrlyDynEqplist::DpchInvBrlyDynEqplist(
			const ubigint oref
			, const ubigint jref
			, const ubigint refBrlyMConnection
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYDYNEQPLIST, oref, jref) {
	this->refBrlyMConnection = refBrlyMConnection;
};

void DpchInvBrlyDynEqplist::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyDynEqplist");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refBrlyMConnection", "", refBrlyMConnection)) add(REFBRLYMCONNECTION);
	};
};

void DpchInvBrlyDynEqplist::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyDynEqplist");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refBrlyMConnection", refBrlyMConnection);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyDynFltfltloc
 ******************************************************************************/

DpchInvBrlyDynFltfltloc::DpchInvBrlyDynFltfltloc(
			const ubigint oref
			, const ubigint jref
			, const vector<ubigint>& refsBrlyMFlight
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYDYNFLTFLTLOC, oref, jref) {
	this->refsBrlyMFlight = refsBrlyMFlight;
};

void DpchInvBrlyDynFltfltloc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyDynFltfltloc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintvecUclc(docctx, basexpath, "refsBrlyMFlight", "", refsBrlyMFlight)) add(REFSBRLYMFLIGHT);
	};
};

void DpchInvBrlyDynFltfltloc::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyDynFltfltloc");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigintvec(wr, "refsBrlyMFlight", refsBrlyMFlight);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyDynFltseg
 ******************************************************************************/

DpchInvBrlyDynFltseg::DpchInvBrlyDynFltseg(
			const ubigint oref
			, const ubigint jref
			, const uint numFirst
			, const uint numLast
			, const vector<ubigint>& refsBrlyMFlight
			, const uint start
			, const uint stop
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYDYNFLTSEG, oref, jref) {
	this->numFirst = numFirst;
	this->numLast = numLast;
	this->refsBrlyMFlight = refsBrlyMFlight;
	this->start = start;
	this->stop = stop;
};

void DpchInvBrlyDynFltseg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyDynFltseg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUintUclc(docctx, basexpath, "numFirst", "", numFirst)) add(NUMFIRST);
		if (extractUintUclc(docctx, basexpath, "numLast", "", numLast)) add(NUMLAST);
		if (extractUbigintvecUclc(docctx, basexpath, "refsBrlyMFlight", "", refsBrlyMFlight)) add(REFSBRLYMFLIGHT);
		if (extractUintUclc(docctx, basexpath, "start", "", start)) add(START);
		if (extractUintUclc(docctx, basexpath, "stop", "", stop)) add(STOP);
	};
};

void DpchInvBrlyDynFltseg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyDynFltseg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUint(wr, "numFirst", numFirst);
		writeUint(wr, "numLast", numLast);
		writeUbigintvec(wr, "refsBrlyMFlight", refsBrlyMFlight);
		writeUint(wr, "start", start);
		writeUint(wr, "stop", stop);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyDynRly
 ******************************************************************************/

DpchInvBrlyDynRly::DpchInvBrlyDynRly(
			const ubigint oref
			, const ubigint jref
			, const ubigint refBrlyMConnection
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYDYNRLY, oref, jref) {
	this->refBrlyMConnection = refBrlyMConnection;
};

void DpchInvBrlyDynRly::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyDynRly");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refBrlyMConnection", "", refBrlyMConnection)) add(REFBRLYMCONNECTION);
	};
};

void DpchInvBrlyDynRly::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyDynRly");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refBrlyMConnection", refBrlyMConnection);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyDynSeglocseg
 ******************************************************************************/

DpchInvBrlyDynSeglocseg::DpchInvBrlyDynSeglocseg(
			const ubigint oref
			, const ubigint jref
			, const vector<ubigint>& refsBrlyMFlight
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYDYNSEGLOCSEG, oref, jref) {
	this->refsBrlyMFlight = refsBrlyMFlight;
};

void DpchInvBrlyDynSeglocseg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyDynSeglocseg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintvecUclc(docctx, basexpath, "refsBrlyMFlight", "", refsBrlyMFlight)) add(REFSBRLYMFLIGHT);
	};
};

void DpchInvBrlyDynSeglocseg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyDynSeglocseg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigintvec(wr, "refsBrlyMFlight", refsBrlyMFlight);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT

