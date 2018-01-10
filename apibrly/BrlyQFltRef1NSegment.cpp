/**
  * \file BrlyQFltRef1NSegment.cpp
  * API code for table TblBrlyQFltRef1NSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQFltRef1NSegment.h"

/******************************************************************************
 class BrlyQFltRef1NSegment
 ******************************************************************************/

BrlyQFltRef1NSegment::BrlyQFltRef1NSegment(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQFltRef1NSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQFltRef1NSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQFltRef1NSegment
 ******************************************************************************/

ListBrlyQFltRef1NSegment::ListBrlyQFltRef1NSegment() {
};

ListBrlyQFltRef1NSegment::ListBrlyQFltRef1NSegment(
			const ListBrlyQFltRef1NSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltRef1NSegment(*(src.nodes[i]));
};

ListBrlyQFltRef1NSegment& ListBrlyQFltRef1NSegment::operator=(
			const ListBrlyQFltRef1NSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltRef1NSegment(*(src.nodes[i]));

	return *this;
};

ListBrlyQFltRef1NSegment::~ListBrlyQFltRef1NSegment() {
	clear();
};

void ListBrlyQFltRef1NSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQFltRef1NSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQFltRef1NSegment* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQFltRef1NSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQFltRef1NSegment", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQFltRef1NSegment(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQFltRef1NSegment[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

