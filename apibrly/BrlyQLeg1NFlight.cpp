/**
  * \file BrlyQLeg1NFlight.cpp
  * API code for table TblBrlyQLeg1NFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLeg1NFlight.h"

/******************************************************************************
 class BrlyQLeg1NFlight
 ******************************************************************************/

BrlyQLeg1NFlight::BrlyQLeg1NFlight(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQLeg1NFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLeg1NFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLeg1NFlight
 ******************************************************************************/

ListBrlyQLeg1NFlight::ListBrlyQLeg1NFlight() {
};

ListBrlyQLeg1NFlight::ListBrlyQLeg1NFlight(
			const ListBrlyQLeg1NFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLeg1NFlight(*(src.nodes[i]));
};

ListBrlyQLeg1NFlight& ListBrlyQLeg1NFlight::operator=(
			const ListBrlyQLeg1NFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLeg1NFlight(*(src.nodes[i]));

	return *this;
};

ListBrlyQLeg1NFlight::~ListBrlyQLeg1NFlight() {
	clear();
};

void ListBrlyQLeg1NFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLeg1NFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLeg1NFlight* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLeg1NFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLeg1NFlight", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLeg1NFlight(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLeg1NFlight[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

