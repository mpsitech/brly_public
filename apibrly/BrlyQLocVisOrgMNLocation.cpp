/**
  * \file BrlyQLocVisOrgMNLocation.cpp
  * API code for table TblBrlyQLocVisOrgMNLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocVisOrgMNLocation.h"

/******************************************************************************
 class BrlyQLocVisOrgMNLocation
 ******************************************************************************/

BrlyQLocVisOrgMNLocation::BrlyQLocVisOrgMNLocation(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool BrlyQLocVisOrgMNLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocVisOrgMNLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLocVisOrgMNLocation
 ******************************************************************************/

ListBrlyQLocVisOrgMNLocation::ListBrlyQLocVisOrgMNLocation() {
};

ListBrlyQLocVisOrgMNLocation::ListBrlyQLocVisOrgMNLocation(
			const ListBrlyQLocVisOrgMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocVisOrgMNLocation(*(src.nodes[i]));
};

ListBrlyQLocVisOrgMNLocation& ListBrlyQLocVisOrgMNLocation::operator=(
			const ListBrlyQLocVisOrgMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocVisOrgMNLocation(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocVisOrgMNLocation::~ListBrlyQLocVisOrgMNLocation() {
	clear();
};

void ListBrlyQLocVisOrgMNLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocVisOrgMNLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocVisOrgMNLocation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocVisOrgMNLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocVisOrgMNLocation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocVisOrgMNLocation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocVisOrgMNLocation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

