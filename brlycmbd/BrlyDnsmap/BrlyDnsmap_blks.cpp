/**
  * \file BrlyDnsmap_blks.cpp
  * invocation / return data blocks for operation pack BrlyDnsmap (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyDnsmap_blks.h"

/******************************************************************************
 class DpchInvBrlyDnsmapCollect
 ******************************************************************************/

DpchInvBrlyDnsmapCollect::DpchInvBrlyDnsmapCollect(
			const ubigint oref
			, const ubigint jref
			, const bool capacity
			, const bool con
			, const uint dt
			, const bool flt
			, const uint fullheight
			, const uint fullwidth
			, const bool leg
			, const bool pacctr
			, const double phi0
			, const double phi1
			, const bool pReach
			, const bool seg
			, const string& srefArena
			, const string& srefsBrlyKEqptype
			, const uint start
			, const uint stop
			, const double theta0
			, const double theta1
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYDNSMAPCOLLECT, oref, jref) {
	this->capacity = capacity;
	this->con = con;
	this->dt = dt;
	this->flt = flt;
	this->fullheight = fullheight;
	this->fullwidth = fullwidth;
	this->leg = leg;
	this->pacctr = pacctr;
	this->phi0 = phi0;
	this->phi1 = phi1;
	this->pReach = pReach;
	this->seg = seg;
	this->srefArena = srefArena;
	this->srefsBrlyKEqptype = srefsBrlyKEqptype;
	this->start = start;
	this->stop = stop;
	this->theta0 = theta0;
	this->theta1 = theta1;
};

void DpchInvBrlyDnsmapCollect::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyDnsmapCollect");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractBoolUclc(docctx, basexpath, "capacity", "", capacity)) add(CAPACITY);
		if (extractBoolUclc(docctx, basexpath, "con", "", con)) add(CON);
		if (extractUintUclc(docctx, basexpath, "dt", "", dt)) add(DT);
		if (extractBoolUclc(docctx, basexpath, "flt", "", flt)) add(FLT);
		if (extractUintUclc(docctx, basexpath, "fullheight", "", fullheight)) add(FULLHEIGHT);
		if (extractUintUclc(docctx, basexpath, "fullwidth", "", fullwidth)) add(FULLWIDTH);
		if (extractBoolUclc(docctx, basexpath, "leg", "", leg)) add(LEG);
		if (extractBoolUclc(docctx, basexpath, "pacctr", "", pacctr)) add(PACCTR);
		if (extractDoubleUclc(docctx, basexpath, "phi0", "", phi0)) add(PHI0);
		if (extractDoubleUclc(docctx, basexpath, "phi1", "", phi1)) add(PHI1);
		if (extractBoolUclc(docctx, basexpath, "pReach", "", pReach)) add(PREACH);
		if (extractBoolUclc(docctx, basexpath, "seg", "", seg)) add(SEG);
		if (extractStringUclc(docctx, basexpath, "srefArena", "", srefArena)) add(SREFARENA);
		if (extractStringUclc(docctx, basexpath, "srefsBrlyKEqptype", "", srefsBrlyKEqptype)) add(SREFSBRLYKEQPTYPE);
		if (extractUintUclc(docctx, basexpath, "start", "", start)) add(START);
		if (extractUintUclc(docctx, basexpath, "stop", "", stop)) add(STOP);
		if (extractDoubleUclc(docctx, basexpath, "theta0", "", theta0)) add(THETA0);
		if (extractDoubleUclc(docctx, basexpath, "theta1", "", theta1)) add(THETA1);
	};
};

void DpchInvBrlyDnsmapCollect::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyDnsmapCollect");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeBool(wr, "capacity", capacity);
		writeBool(wr, "con", con);
		writeUint(wr, "dt", dt);
		writeBool(wr, "flt", flt);
		writeUint(wr, "fullheight", fullheight);
		writeUint(wr, "fullwidth", fullwidth);
		writeBool(wr, "leg", leg);
		writeBool(wr, "pacctr", pacctr);
		writeDouble(wr, "phi0", phi0);
		writeDouble(wr, "phi1", phi1);
		writeBool(wr, "pReach", pReach);
		writeBool(wr, "seg", seg);
		writeString(wr, "srefArena", srefArena);
		writeString(wr, "srefsBrlyKEqptype", srefsBrlyKEqptype);
		writeUint(wr, "start", start);
		writeUint(wr, "stop", stop);
		writeDouble(wr, "theta0", theta0);
		writeDouble(wr, "theta1", theta1);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetBrlyDnsmapCollect
 ******************************************************************************/

DpchRetBrlyDnsmapCollect::DpchRetBrlyDnsmapCollect(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const ubigint refBrlyMFile
		) : DpchRetBrly(VecBrlyVDpch::DPCHRETBRLYDNSMAPCOLLECT, scrOref, scrJref) {
	this->success = success;
	this->refBrlyMFile = refBrlyMFile;
};

void DpchRetBrlyDnsmapCollect::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetBrlyDnsmapCollect");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(mScr, descr, scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractBoolUclc(docctx, basexpath, "success", "", success)) add(SUCCESS);
		if (extractUbigintUclc(docctx, basexpath, "refBrlyMFile", "", refBrlyMFile)) add(REFBRLYMFILE);
	};
};

void DpchRetBrlyDnsmapCollect::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetBrlyDnsmapCollect");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeUbigint(wr, "refBrlyMFile", refBrlyMFile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyDnsmapFrame
 ******************************************************************************/

DpchInvBrlyDnsmapFrame::DpchInvBrlyDnsmapFrame(
			const ubigint oref
			, const ubigint jref
			, const ubigint refBrlyMFile
			, const bool fullsize
			, const bool grayscale
			, const double altzmax
			, const uint tIx
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYDNSMAPFRAME, oref, jref) {
	this->refBrlyMFile = refBrlyMFile;
	this->fullsize = fullsize;
	this->grayscale = grayscale;
	this->altzmax = altzmax;
	this->tIx = tIx;
};

void DpchInvBrlyDnsmapFrame::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyDnsmapFrame");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refBrlyMFile", "", refBrlyMFile)) add(REFBRLYMFILE);
		if (extractBoolUclc(docctx, basexpath, "fullsize", "", fullsize)) add(FULLSIZE);
		if (extractBoolUclc(docctx, basexpath, "grayscale", "", grayscale)) add(GRAYSCALE);
		if (extractDoubleUclc(docctx, basexpath, "altzmax", "", altzmax)) add(ALTZMAX);
		if (extractUintUclc(docctx, basexpath, "tIx", "", tIx)) add(TIX);
	};
};

void DpchInvBrlyDnsmapFrame::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyDnsmapFrame");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refBrlyMFile", refBrlyMFile);
		writeBool(wr, "fullsize", fullsize);
		writeBool(wr, "grayscale", grayscale);
		writeDouble(wr, "altzmax", altzmax);
		writeUint(wr, "tIx", tIx);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetBrlyDnsmapFrame
 ******************************************************************************/

DpchRetBrlyDnsmapFrame::DpchRetBrlyDnsmapFrame(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& filename
		) : DpchRetBrly(VecBrlyVDpch::DPCHRETBRLYDNSMAPFRAME, scrOref, scrJref) {
	this->success = success;
	this->filename = filename;
};

void DpchRetBrlyDnsmapFrame::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetBrlyDnsmapFrame");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(mScr, descr, scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractBoolUclc(docctx, basexpath, "success", "", success)) add(SUCCESS);
		if (extractStringUclc(docctx, basexpath, "filename", "", filename)) add(FILENAME);
	};
};

void DpchRetBrlyDnsmapFrame::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetBrlyDnsmapFrame");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "filename", filename);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyDnsmapVideo
 ******************************************************************************/

DpchInvBrlyDnsmapVideo::DpchInvBrlyDnsmapVideo(
			const ubigint oref
			, const ubigint jref
			, const double altzmax
			, const uint frmrate
			, const bool fullsize
			, const bool grayscale
			, const ubigint refBrlyMFile
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYDNSMAPVIDEO, oref, jref) {
	this->altzmax = altzmax;
	this->frmrate = frmrate;
	this->fullsize = fullsize;
	this->grayscale = grayscale;
	this->refBrlyMFile = refBrlyMFile;
};

void DpchInvBrlyDnsmapVideo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyDnsmapVideo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractDoubleUclc(docctx, basexpath, "altzmax", "", altzmax)) add(ALTZMAX);
		if (extractUintUclc(docctx, basexpath, "frmrate", "", frmrate)) add(FRMRATE);
		if (extractBoolUclc(docctx, basexpath, "fullsize", "", fullsize)) add(FULLSIZE);
		if (extractBoolUclc(docctx, basexpath, "grayscale", "", grayscale)) add(GRAYSCALE);
		if (extractUbigintUclc(docctx, basexpath, "refBrlyMFile", "", refBrlyMFile)) add(REFBRLYMFILE);
	};
};

void DpchInvBrlyDnsmapVideo::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyDnsmapVideo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeDouble(wr, "altzmax", altzmax);
		writeUint(wr, "frmrate", frmrate);
		writeBool(wr, "fullsize", fullsize);
		writeBool(wr, "grayscale", grayscale);
		writeUbigint(wr, "refBrlyMFile", refBrlyMFile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetBrlyDnsmapVideo
 ******************************************************************************/

DpchRetBrlyDnsmapVideo::DpchRetBrlyDnsmapVideo(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& folder
		) : DpchRetBrly(VecBrlyVDpch::DPCHRETBRLYDNSMAPVIDEO, scrOref, scrJref) {
	this->success = success;
	this->folder = folder;
};

void DpchRetBrlyDnsmapVideo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetBrlyDnsmapVideo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(mScr, descr, scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractBoolUclc(docctx, basexpath, "success", "", success)) add(SUCCESS);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchRetBrlyDnsmapVideo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetBrlyDnsmapVideo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT

