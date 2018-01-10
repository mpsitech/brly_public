/**
  * \file BrlyQRegSup1NRegion.cpp
  * API code for table TblBrlyQRegSup1NRegion (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQRegSup1NRegion.h"

/******************************************************************************
 class BrlyQRegSup1NRegion
 ******************************************************************************/

BrlyQRegSup1NRegion::BrlyQRegSup1NRegion(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQRegSup1NRegion::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQRegSup1NRegion");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQRegSup1NRegion
 ******************************************************************************/

ListBrlyQRegSup1NRegion::ListBrlyQRegSup1NRegion() {
};

ListBrlyQRegSup1NRegion::ListBrlyQRegSup1NRegion(
			const ListBrlyQRegSup1NRegion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRegSup1NRegion(*(src.nodes[i]));
};

ListBrlyQRegSup1NRegion& ListBrlyQRegSup1NRegion::operator=(
			const ListBrlyQRegSup1NRegion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRegSup1NRegion(*(src.nodes[i]));

	return *this;
};

ListBrlyQRegSup1NRegion::~ListBrlyQRegSup1NRegion() {
	clear();
};

void ListBrlyQRegSup1NRegion::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQRegSup1NRegion::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQRegSup1NRegion* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQRegSup1NRegion");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQRegSup1NRegion", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQRegSup1NRegion(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQRegSup1NRegion[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

