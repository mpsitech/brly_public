/**
  * \file BrlyQLocBgn1NLeg.cpp
  * API code for table TblBrlyQLocBgn1NLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocBgn1NLeg.h"

/******************************************************************************
 class BrlyQLocBgn1NLeg
 ******************************************************************************/

BrlyQLocBgn1NLeg::BrlyQLocBgn1NLeg(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQLocBgn1NLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocBgn1NLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLocBgn1NLeg
 ******************************************************************************/

ListBrlyQLocBgn1NLeg::ListBrlyQLocBgn1NLeg() {
};

ListBrlyQLocBgn1NLeg::ListBrlyQLocBgn1NLeg(
			const ListBrlyQLocBgn1NLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocBgn1NLeg(*(src.nodes[i]));
};

ListBrlyQLocBgn1NLeg& ListBrlyQLocBgn1NLeg::operator=(
			const ListBrlyQLocBgn1NLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocBgn1NLeg(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocBgn1NLeg::~ListBrlyQLocBgn1NLeg() {
	clear();
};

void ListBrlyQLocBgn1NLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocBgn1NLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocBgn1NLeg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocBgn1NLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocBgn1NLeg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocBgn1NLeg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocBgn1NLeg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

