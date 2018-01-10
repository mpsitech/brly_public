/**
  * \file BrlyQConMNFlight.cpp
  * API code for table TblBrlyQConMNFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQConMNFlight.h"

/******************************************************************************
 class BrlyQConMNFlight
 ******************************************************************************/

BrlyQConMNFlight::BrlyQConMNFlight(
			const uint jnum
			, const string stubMref
			, const string ftmX1Start
			, const string ftmX1Stop
			, const double x2Legphi0
			, const double x2Legphi1
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->ftmX1Start = ftmX1Start;
	this->ftmX1Stop = ftmX1Stop;
	this->x2Legphi0 = x2Legphi0;
	this->x2Legphi1 = x2Legphi1;
};

bool BrlyQConMNFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQConMNFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "ftmX1Start", "sta", ftmX1Start);
		extractStringUclc(docctx, basexpath, "ftmX1Stop", "sto", ftmX1Stop);
		extractDoubleUclc(docctx, basexpath, "x2Legphi0", "lp0", x2Legphi0);
		extractDoubleUclc(docctx, basexpath, "x2Legphi1", "lp1", x2Legphi1);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQConMNFlight
 ******************************************************************************/

ListBrlyQConMNFlight::ListBrlyQConMNFlight() {
};

ListBrlyQConMNFlight::ListBrlyQConMNFlight(
			const ListBrlyQConMNFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMNFlight(*(src.nodes[i]));
};

ListBrlyQConMNFlight& ListBrlyQConMNFlight::operator=(
			const ListBrlyQConMNFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMNFlight(*(src.nodes[i]));

	return *this;
};

ListBrlyQConMNFlight::~ListBrlyQConMNFlight() {
	clear();
};

void ListBrlyQConMNFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQConMNFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQConMNFlight* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQConMNFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQConMNFlight", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQConMNFlight(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQConMNFlight[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

