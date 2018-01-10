/**
  * \file BrlyQLegMapLocation.cpp
  * API code for table TblBrlyQLegMapLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLegMapLocation.h"

/******************************************************************************
 class BrlyQLegMapLocation
 ******************************************************************************/

BrlyQLegMapLocation::BrlyQLegMapLocation(
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

bool BrlyQLegMapLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLegMapLocation");
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
 class ListBrlyQLegMapLocation
 ******************************************************************************/

ListBrlyQLegMapLocation::ListBrlyQLegMapLocation() {
};

ListBrlyQLegMapLocation::ListBrlyQLegMapLocation(
			const ListBrlyQLegMapLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegMapLocation(*(src.nodes[i]));
};

ListBrlyQLegMapLocation& ListBrlyQLegMapLocation::operator=(
			const ListBrlyQLegMapLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegMapLocation(*(src.nodes[i]));

	return *this;
};

ListBrlyQLegMapLocation::~ListBrlyQLegMapLocation() {
	clear();
};

void ListBrlyQLegMapLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLegMapLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLegMapLocation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLegMapLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLegMapLocation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLegMapLocation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLegMapLocation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

