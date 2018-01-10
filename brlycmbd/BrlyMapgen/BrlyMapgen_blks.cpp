/**
  * \file BrlyMapgen_blks.cpp
  * invocation / return data blocks for operation pack BrlyMapgen (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMapgen_blks.h"

/******************************************************************************
 class DpchInvBrlyMapgenConmap
 ******************************************************************************/

DpchInvBrlyMapgenConmap::DpchInvBrlyMapgenConmap(
			const ubigint oref
			, const ubigint jref
			, const ubigint refBrlyMConnection
			, const ubigint jrefLeg
			, const ubigint jrefLoc
			, const ubigint jrefFlt
			, const ubigint jrefRly
			, const ubigint jrefNde
			, const uint scale
			, const uint width
			, const uint height
			, const int xoffset
			, const int yoffset
			, const bool wrtree
			, const string& filename
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYMAPGENCONMAP, oref, jref) {
	this->refBrlyMConnection = refBrlyMConnection;
	this->jrefLeg = jrefLeg;
	this->jrefLoc = jrefLoc;
	this->jrefFlt = jrefFlt;
	this->jrefRly = jrefRly;
	this->jrefNde = jrefNde;
	this->scale = scale;
	this->width = width;
	this->height = height;
	this->xoffset = xoffset;
	this->yoffset = yoffset;
	this->wrtree = wrtree;
	this->filename = filename;
};

void DpchInvBrlyMapgenConmap::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyMapgenConmap");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refBrlyMConnection", "", refBrlyMConnection)) add(REFBRLYMCONNECTION);
		if (extractUbigintUclc(docctx, basexpath, "jrefLeg", "", jrefLeg)) add(JREFLEG);
		if (extractUbigintUclc(docctx, basexpath, "jrefLoc", "", jrefLoc)) add(JREFLOC);
		if (extractUbigintUclc(docctx, basexpath, "jrefFlt", "", jrefFlt)) add(JREFFLT);
		if (extractUbigintUclc(docctx, basexpath, "jrefRly", "", jrefRly)) add(JREFRLY);
		if (extractUbigintUclc(docctx, basexpath, "jrefNde", "", jrefNde)) add(JREFNDE);
		if (extractUintUclc(docctx, basexpath, "scale", "", scale)) add(SCALE);
		if (extractUintUclc(docctx, basexpath, "width", "", width)) add(WIDTH);
		if (extractUintUclc(docctx, basexpath, "height", "", height)) add(HEIGHT);
		if (extractIntUclc(docctx, basexpath, "xoffset", "", xoffset)) add(XOFFSET);
		if (extractIntUclc(docctx, basexpath, "yoffset", "", yoffset)) add(YOFFSET);
		if (extractBoolUclc(docctx, basexpath, "wrtree", "", wrtree)) add(WRTREE);
		if (extractStringUclc(docctx, basexpath, "filename", "", filename)) add(FILENAME);
	};
};

void DpchInvBrlyMapgenConmap::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyMapgenConmap");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refBrlyMConnection", refBrlyMConnection);
		writeUbigint(wr, "jrefLeg", jrefLeg);
		writeUbigint(wr, "jrefLoc", jrefLoc);
		writeUbigint(wr, "jrefFlt", jrefFlt);
		writeUbigint(wr, "jrefRly", jrefRly);
		writeUbigint(wr, "jrefNde", jrefNde);
		writeUint(wr, "scale", scale);
		writeUint(wr, "width", width);
		writeUint(wr, "height", height);
		writeInt(wr, "xoffset", xoffset);
		writeInt(wr, "yoffset", yoffset);
		writeBool(wr, "wrtree", wrtree);
		writeString(wr, "filename", filename);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyMapgenLegmap
 ******************************************************************************/

DpchInvBrlyMapgenLegmap::DpchInvBrlyMapgenLegmap(
			const ubigint oref
			, const ubigint jref
			, const ubigint refBrlyMLeg
			, const ubigint jrefLeg
			, const ubigint jrefLoc
			, const uint scale
			, const uint width
			, const uint height
			, const int xoffset
			, const int yoffset
			, const string& filename
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYMAPGENLEGMAP, oref, jref) {
	this->refBrlyMLeg = refBrlyMLeg;
	this->jrefLeg = jrefLeg;
	this->jrefLoc = jrefLoc;
	this->scale = scale;
	this->width = width;
	this->height = height;
	this->xoffset = xoffset;
	this->yoffset = yoffset;
	this->filename = filename;
};

void DpchInvBrlyMapgenLegmap::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyMapgenLegmap");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refBrlyMLeg", "", refBrlyMLeg)) add(REFBRLYMLEG);
		if (extractUbigintUclc(docctx, basexpath, "jrefLeg", "", jrefLeg)) add(JREFLEG);
		if (extractUbigintUclc(docctx, basexpath, "jrefLoc", "", jrefLoc)) add(JREFLOC);
		if (extractUintUclc(docctx, basexpath, "scale", "", scale)) add(SCALE);
		if (extractUintUclc(docctx, basexpath, "width", "", width)) add(WIDTH);
		if (extractUintUclc(docctx, basexpath, "height", "", height)) add(HEIGHT);
		if (extractIntUclc(docctx, basexpath, "xoffset", "", xoffset)) add(XOFFSET);
		if (extractIntUclc(docctx, basexpath, "yoffset", "", yoffset)) add(YOFFSET);
		if (extractStringUclc(docctx, basexpath, "filename", "", filename)) add(FILENAME);
	};
};

void DpchInvBrlyMapgenLegmap::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyMapgenLegmap");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refBrlyMLeg", refBrlyMLeg);
		writeUbigint(wr, "jrefLeg", jrefLeg);
		writeUbigint(wr, "jrefLoc", jrefLoc);
		writeUint(wr, "scale", scale);
		writeUint(wr, "width", width);
		writeUint(wr, "height", height);
		writeInt(wr, "xoffset", xoffset);
		writeInt(wr, "yoffset", yoffset);
		writeString(wr, "filename", filename);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyMapgenLocmap
 ******************************************************************************/

DpchInvBrlyMapgenLocmap::DpchInvBrlyMapgenLocmap(
			const ubigint oref
			, const ubigint jref
			, const ubigint refBrlyMLocation
			, const ubigint jrefLeg
			, const ubigint jrefProxloc
			, const ubigint jrefVisloc
			, const uint scale
			, const uint width
			, const uint height
			, const int xoffset
			, const int yoffset
			, const string& filename
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYMAPGENLOCMAP, oref, jref) {
	this->refBrlyMLocation = refBrlyMLocation;
	this->jrefLeg = jrefLeg;
	this->jrefProxloc = jrefProxloc;
	this->jrefVisloc = jrefVisloc;
	this->scale = scale;
	this->width = width;
	this->height = height;
	this->xoffset = xoffset;
	this->yoffset = yoffset;
	this->filename = filename;
};

void DpchInvBrlyMapgenLocmap::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyMapgenLocmap");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refBrlyMLocation", "", refBrlyMLocation)) add(REFBRLYMLOCATION);
		if (extractUbigintUclc(docctx, basexpath, "jrefLeg", "", jrefLeg)) add(JREFLEG);
		if (extractUbigintUclc(docctx, basexpath, "jrefProxloc", "", jrefProxloc)) add(JREFPROXLOC);
		if (extractUbigintUclc(docctx, basexpath, "jrefVisloc", "", jrefVisloc)) add(JREFVISLOC);
		if (extractUintUclc(docctx, basexpath, "scale", "", scale)) add(SCALE);
		if (extractUintUclc(docctx, basexpath, "width", "", width)) add(WIDTH);
		if (extractUintUclc(docctx, basexpath, "height", "", height)) add(HEIGHT);
		if (extractIntUclc(docctx, basexpath, "xoffset", "", xoffset)) add(XOFFSET);
		if (extractIntUclc(docctx, basexpath, "yoffset", "", yoffset)) add(YOFFSET);
		if (extractStringUclc(docctx, basexpath, "filename", "", filename)) add(FILENAME);
	};
};

void DpchInvBrlyMapgenLocmap::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyMapgenLocmap");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refBrlyMLocation", refBrlyMLocation);
		writeUbigint(wr, "jrefLeg", jrefLeg);
		writeUbigint(wr, "jrefProxloc", jrefProxloc);
		writeUbigint(wr, "jrefVisloc", jrefVisloc);
		writeUint(wr, "scale", scale);
		writeUint(wr, "width", width);
		writeUint(wr, "height", height);
		writeInt(wr, "xoffset", xoffset);
		writeInt(wr, "yoffset", yoffset);
		writeString(wr, "filename", filename);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT

