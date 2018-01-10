/**
  * \file BrlyQLocMapVisLocation.cpp
  * API code for table TblBrlyQLocMapVisLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocMapVisLocation.h"

/******************************************************************************
 class BrlyQLocMapVisLocation
 ******************************************************************************/

BrlyQLocMapVisLocation::BrlyQLocMapVisLocation(
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

bool BrlyQLocMapVisLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocMapVisLocation");
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
 class ListBrlyQLocMapVisLocation
 ******************************************************************************/

ListBrlyQLocMapVisLocation::ListBrlyQLocMapVisLocation() {
};

ListBrlyQLocMapVisLocation::ListBrlyQLocMapVisLocation(
			const ListBrlyQLocMapVisLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMapVisLocation(*(src.nodes[i]));
};

ListBrlyQLocMapVisLocation& ListBrlyQLocMapVisLocation::operator=(
			const ListBrlyQLocMapVisLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMapVisLocation(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocMapVisLocation::~ListBrlyQLocMapVisLocation() {
	clear();
};

void ListBrlyQLocMapVisLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocMapVisLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocMapVisLocation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocMapVisLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocMapVisLocation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocMapVisLocation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocMapVisLocation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

