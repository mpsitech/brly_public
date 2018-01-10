/**
  * \file BrlyQLocMapProxLocation.cpp
  * API code for table TblBrlyQLocMapProxLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocMapProxLocation.h"

/******************************************************************************
 class BrlyQLocMapProxLocation
 ******************************************************************************/

BrlyQLocMapProxLocation::BrlyQLocMapProxLocation(
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

bool BrlyQLocMapProxLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocMapProxLocation");
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
 class ListBrlyQLocMapProxLocation
 ******************************************************************************/

ListBrlyQLocMapProxLocation::ListBrlyQLocMapProxLocation() {
};

ListBrlyQLocMapProxLocation::ListBrlyQLocMapProxLocation(
			const ListBrlyQLocMapProxLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMapProxLocation(*(src.nodes[i]));
};

ListBrlyQLocMapProxLocation& ListBrlyQLocMapProxLocation::operator=(
			const ListBrlyQLocMapProxLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMapProxLocation(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocMapProxLocation::~ListBrlyQLocMapProxLocation() {
	clear();
};

void ListBrlyQLocMapProxLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocMapProxLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocMapProxLocation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocMapProxLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocMapProxLocation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocMapProxLocation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocMapProxLocation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

