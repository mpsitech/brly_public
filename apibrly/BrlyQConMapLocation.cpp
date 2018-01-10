/**
  * \file BrlyQConMapLocation.cpp
  * API code for table TblBrlyQConMapLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQConMapLocation.h"

/******************************************************************************
 class BrlyQConMapLocation
 ******************************************************************************/

BrlyQConMapLocation::BrlyQConMapLocation(
			const uint jnum
			, const string stubMref
			, const double x
			, const double y
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->x = x;
	this->y = y;
};

bool BrlyQConMapLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQConMapLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractDoubleUclc(docctx, basexpath, "x", "x", x);
		extractDoubleUclc(docctx, basexpath, "y", "y", y);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQConMapLocation
 ******************************************************************************/

ListBrlyQConMapLocation::ListBrlyQConMapLocation() {
};

ListBrlyQConMapLocation::ListBrlyQConMapLocation(
			const ListBrlyQConMapLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapLocation(*(src.nodes[i]));
};

ListBrlyQConMapLocation& ListBrlyQConMapLocation::operator=(
			const ListBrlyQConMapLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapLocation(*(src.nodes[i]));

	return *this;
};

ListBrlyQConMapLocation::~ListBrlyQConMapLocation() {
	clear();
};

void ListBrlyQConMapLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQConMapLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQConMapLocation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQConMapLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQConMapLocation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQConMapLocation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQConMapLocation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

