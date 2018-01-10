/**
  * \file BrlyQLocProxOrgMNLocation.cpp
  * API code for table TblBrlyQLocProxOrgMNLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocProxOrgMNLocation.h"

/******************************************************************************
 class BrlyQLocProxOrgMNLocation
 ******************************************************************************/

BrlyQLocProxOrgMNLocation::BrlyQLocProxOrgMNLocation(
			const uint jnum
			, const string stubMref
			, const double deltaphi
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->deltaphi = deltaphi;
};

bool BrlyQLocProxOrgMNLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocProxOrgMNLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractDoubleUclc(docctx, basexpath, "deltaphi", "dph", deltaphi);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLocProxOrgMNLocation
 ******************************************************************************/

ListBrlyQLocProxOrgMNLocation::ListBrlyQLocProxOrgMNLocation() {
};

ListBrlyQLocProxOrgMNLocation::ListBrlyQLocProxOrgMNLocation(
			const ListBrlyQLocProxOrgMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocProxOrgMNLocation(*(src.nodes[i]));
};

ListBrlyQLocProxOrgMNLocation& ListBrlyQLocProxOrgMNLocation::operator=(
			const ListBrlyQLocProxOrgMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocProxOrgMNLocation(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocProxOrgMNLocation::~ListBrlyQLocProxOrgMNLocation() {
	clear();
};

void ListBrlyQLocProxOrgMNLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocProxOrgMNLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocProxOrgMNLocation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocProxOrgMNLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocProxOrgMNLocation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocProxOrgMNLocation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocProxOrgMNLocation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

