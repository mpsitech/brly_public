/**
  * \file BrlyQConMapFlight.cpp
  * API code for table TblBrlyQConMapFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQConMapFlight.h"

/******************************************************************************
 class BrlyQConMapFlight
 ******************************************************************************/

BrlyQConMapFlight::BrlyQConMapFlight(
			const uint jnum
			, const string stubMref
			, const double x0
			, const double y0
			, const int t0
			, const double dx
			, const double dy
			, const int dt
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->x0 = x0;
	this->y0 = y0;
	this->t0 = t0;
	this->dx = dx;
	this->dy = dy;
	this->dt = dt;
};

bool BrlyQConMapFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQConMapFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractDoubleUclc(docctx, basexpath, "x0", "x0", x0);
		extractDoubleUclc(docctx, basexpath, "y0", "y0", y0);
		extractIntUclc(docctx, basexpath, "t0", "t0", t0);
		extractDoubleUclc(docctx, basexpath, "dx", "dx", dx);
		extractDoubleUclc(docctx, basexpath, "dy", "dy", dy);
		extractIntUclc(docctx, basexpath, "dt", "dt", dt);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQConMapFlight
 ******************************************************************************/

ListBrlyQConMapFlight::ListBrlyQConMapFlight() {
};

ListBrlyQConMapFlight::ListBrlyQConMapFlight(
			const ListBrlyQConMapFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapFlight(*(src.nodes[i]));
};

ListBrlyQConMapFlight& ListBrlyQConMapFlight::operator=(
			const ListBrlyQConMapFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapFlight(*(src.nodes[i]));

	return *this;
};

ListBrlyQConMapFlight::~ListBrlyQConMapFlight() {
	clear();
};

void ListBrlyQConMapFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQConMapFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQConMapFlight* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQConMapFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQConMapFlight", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQConMapFlight(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQConMapFlight[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

