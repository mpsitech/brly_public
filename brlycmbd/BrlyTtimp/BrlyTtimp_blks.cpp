/**
  * \file BrlyTtimp_blks.cpp
  * invocation / return data blocks for operation pack BrlyTtimp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyTtimp_blks.h"

/******************************************************************************
 class DpchInvBrlyTtimpRawstar
 ******************************************************************************/

DpchInvBrlyTtimpRawstar::DpchInvBrlyTtimpRawstar(
			const ubigint oref
			, const ubigint jref
			, const string& infile
			, const string& outfile
		) : DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYTTIMPRAWSTAR, oref, jref) {
	this->infile = infile;
	this->outfile = outfile;
};

void DpchInvBrlyTtimpRawstar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyTtimpRawstar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "infile", "", infile)) add(INFILE);
		if (extractStringUclc(docctx, basexpath, "outfile", "", outfile)) add(OUTFILE);
	};
};

void DpchInvBrlyTtimpRawstar::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyTtimpRawstar");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeString(wr, "infile", infile);
		writeString(wr, "outfile", outfile);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT

