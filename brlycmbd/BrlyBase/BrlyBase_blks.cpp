/**
  * \file BrlyBase_blks.cpp
  * invocation / return data blocks for operation pack BrlyBase (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyBase_blks.h"

/******************************************************************************
 class DpchInvBrlyBaseLegleg
 ******************************************************************************/

DpchInvBrlyBaseLegleg::DpchInvBrlyBaseLegleg(
			const ubigint oref
			, const ubigint jref
			, const uint numFirst
			, const uint numLast
			, const vector<ubigint>& refsBrlyMLeg
			, const bool append
			, const bool intermix
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYBASELEGLEG, oref, jref) {
	this->numFirst = numFirst;
	this->numLast = numLast;
	this->refsBrlyMLeg = refsBrlyMLeg;
	this->append = append;
	this->intermix = intermix;
};

void DpchInvBrlyBaseLegleg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyBaseLegleg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUintUclc(docctx, basexpath, "numFirst", "", numFirst)) add(NUMFIRST);
		if (extractUintUclc(docctx, basexpath, "numLast", "", numLast)) add(NUMLAST);
		if (extractUbigintvecUclc(docctx, basexpath, "refsBrlyMLeg", "", refsBrlyMLeg)) add(REFSBRLYMLEG);
		if (extractBoolUclc(docctx, basexpath, "append", "", append)) add(APPEND);
		if (extractBoolUclc(docctx, basexpath, "intermix", "", intermix)) add(INTERMIX);
	};
};

void DpchInvBrlyBaseLegleg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyBaseLegleg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUint(wr, "numFirst", numFirst);
		writeUint(wr, "numLast", numLast);
		writeUbigintvec(wr, "refsBrlyMLeg", refsBrlyMLeg);
		writeBool(wr, "append", append);
		writeBool(wr, "intermix", intermix);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyBaseLegloc
 ******************************************************************************/

DpchInvBrlyBaseLegloc::DpchInvBrlyBaseLegloc(
			const ubigint oref
			, const ubigint jref
			, const uint numFirst
			, const uint numLast
			, const vector<ubigint>& refsBrlyMLeg
			, const vector<ubigint>& refsBrlyMLocation
			, const bool append
			, const bool appendloc
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYBASELEGLOC, oref, jref) {
	this->numFirst = numFirst;
	this->numLast = numLast;
	this->refsBrlyMLeg = refsBrlyMLeg;
	this->refsBrlyMLocation = refsBrlyMLocation;
	this->append = append;
	this->appendloc = appendloc;
};

void DpchInvBrlyBaseLegloc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyBaseLegloc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUintUclc(docctx, basexpath, "numFirst", "", numFirst)) add(NUMFIRST);
		if (extractUintUclc(docctx, basexpath, "numLast", "", numLast)) add(NUMLAST);
		if (extractUbigintvecUclc(docctx, basexpath, "refsBrlyMLeg", "", refsBrlyMLeg)) add(REFSBRLYMLEG);
		if (extractUbigintvecUclc(docctx, basexpath, "refsBrlyMLocation", "", refsBrlyMLocation)) add(REFSBRLYMLOCATION);
		if (extractBoolUclc(docctx, basexpath, "append", "", append)) add(APPEND);
		if (extractBoolUclc(docctx, basexpath, "appendloc", "", appendloc)) add(APPENDLOC);
	};
};

void DpchInvBrlyBaseLegloc::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyBaseLegloc");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUint(wr, "numFirst", numFirst);
		writeUint(wr, "numLast", numLast);
		writeUbigintvec(wr, "refsBrlyMLeg", refsBrlyMLeg);
		writeUbigintvec(wr, "refsBrlyMLocation", refsBrlyMLocation);
		writeBool(wr, "append", append);
		writeBool(wr, "appendloc", appendloc);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvBrlyBaseLocloc
 ******************************************************************************/

DpchInvBrlyBaseLocloc::DpchInvBrlyBaseLocloc(
			const ubigint oref
			, const ubigint jref
			, const uint numFirst
			, const uint numLast
			, const vector<ubigint>& refsBrlyMLocation
			, const bool append
			, const bool intermix
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYBASELOCLOC, oref, jref) {
	this->numFirst = numFirst;
	this->numLast = numLast;
	this->refsBrlyMLocation = refsBrlyMLocation;
	this->append = append;
	this->intermix = intermix;
};

void DpchInvBrlyBaseLocloc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyBaseLocloc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUintUclc(docctx, basexpath, "numFirst", "", numFirst)) add(NUMFIRST);
		if (extractUintUclc(docctx, basexpath, "numLast", "", numLast)) add(NUMLAST);
		if (extractUbigintvecUclc(docctx, basexpath, "refsBrlyMLocation", "", refsBrlyMLocation)) add(REFSBRLYMLOCATION);
		if (extractBoolUclc(docctx, basexpath, "append", "", append)) add(APPEND);
		if (extractBoolUclc(docctx, basexpath, "intermix", "", intermix)) add(INTERMIX);
	};
};

void DpchInvBrlyBaseLocloc::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyBaseLocloc");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUint(wr, "numFirst", numFirst);
		writeUint(wr, "numLast", numLast);
		writeUbigintvec(wr, "refsBrlyMLocation", refsBrlyMLocation);
		writeBool(wr, "append", append);
		writeBool(wr, "intermix", intermix);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT

