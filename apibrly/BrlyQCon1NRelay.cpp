/**
  * \file BrlyQCon1NRelay.cpp
  * API code for table TblBrlyQCon1NRelay (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQCon1NRelay.h"

/******************************************************************************
 class BrlyQCon1NRelay
 ******************************************************************************/

BrlyQCon1NRelay::BrlyQCon1NRelay(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQCon1NRelay::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQCon1NRelay");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQCon1NRelay
 ******************************************************************************/

ListBrlyQCon1NRelay::ListBrlyQCon1NRelay() {
};

ListBrlyQCon1NRelay::ListBrlyQCon1NRelay(
			const ListBrlyQCon1NRelay& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQCon1NRelay(*(src.nodes[i]));
};

ListBrlyQCon1NRelay& ListBrlyQCon1NRelay::operator=(
			const ListBrlyQCon1NRelay& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQCon1NRelay(*(src.nodes[i]));

	return *this;
};

ListBrlyQCon1NRelay::~ListBrlyQCon1NRelay() {
	clear();
};

void ListBrlyQCon1NRelay::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQCon1NRelay::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQCon1NRelay* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQCon1NRelay");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQCon1NRelay", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQCon1NRelay(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQCon1NRelay[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

