/**
  * \file BrlyQTtb1NFlight.cpp
  * API code for table TblBrlyQTtb1NFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQTtb1NFlight.h"

/******************************************************************************
 class BrlyQTtb1NFlight
 ******************************************************************************/

BrlyQTtb1NFlight::BrlyQTtb1NFlight(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQTtb1NFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQTtb1NFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQTtb1NFlight
 ******************************************************************************/

ListBrlyQTtb1NFlight::ListBrlyQTtb1NFlight() {
};

ListBrlyQTtb1NFlight::ListBrlyQTtb1NFlight(
			const ListBrlyQTtb1NFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQTtb1NFlight(*(src.nodes[i]));
};

ListBrlyQTtb1NFlight& ListBrlyQTtb1NFlight::operator=(
			const ListBrlyQTtb1NFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQTtb1NFlight(*(src.nodes[i]));

	return *this;
};

ListBrlyQTtb1NFlight::~ListBrlyQTtb1NFlight() {
	clear();
};

void ListBrlyQTtb1NFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQTtb1NFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQTtb1NFlight* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQTtb1NFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQTtb1NFlight", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQTtb1NFlight(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQTtb1NFlight[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

