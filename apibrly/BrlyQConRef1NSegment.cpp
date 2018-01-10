/**
  * \file BrlyQConRef1NSegment.cpp
  * API code for table TblBrlyQConRef1NSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQConRef1NSegment.h"

/******************************************************************************
 class BrlyQConRef1NSegment
 ******************************************************************************/

BrlyQConRef1NSegment::BrlyQConRef1NSegment(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQConRef1NSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQConRef1NSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQConRef1NSegment
 ******************************************************************************/

ListBrlyQConRef1NSegment::ListBrlyQConRef1NSegment() {
};

ListBrlyQConRef1NSegment::ListBrlyQConRef1NSegment(
			const ListBrlyQConRef1NSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConRef1NSegment(*(src.nodes[i]));
};

ListBrlyQConRef1NSegment& ListBrlyQConRef1NSegment::operator=(
			const ListBrlyQConRef1NSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConRef1NSegment(*(src.nodes[i]));

	return *this;
};

ListBrlyQConRef1NSegment::~ListBrlyQConRef1NSegment() {
	clear();
};

void ListBrlyQConRef1NSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQConRef1NSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQConRef1NSegment* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQConRef1NSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQConRef1NSegment", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQConRef1NSegment(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQConRef1NSegment[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

