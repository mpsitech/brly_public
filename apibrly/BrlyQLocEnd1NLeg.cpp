/**
  * \file BrlyQLocEnd1NLeg.cpp
  * API code for table TblBrlyQLocEnd1NLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocEnd1NLeg.h"

/******************************************************************************
 class BrlyQLocEnd1NLeg
 ******************************************************************************/

BrlyQLocEnd1NLeg::BrlyQLocEnd1NLeg(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQLocEnd1NLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocEnd1NLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLocEnd1NLeg
 ******************************************************************************/

ListBrlyQLocEnd1NLeg::ListBrlyQLocEnd1NLeg() {
};

ListBrlyQLocEnd1NLeg::ListBrlyQLocEnd1NLeg(
			const ListBrlyQLocEnd1NLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocEnd1NLeg(*(src.nodes[i]));
};

ListBrlyQLocEnd1NLeg& ListBrlyQLocEnd1NLeg::operator=(
			const ListBrlyQLocEnd1NLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocEnd1NLeg(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocEnd1NLeg::~ListBrlyQLocEnd1NLeg() {
	clear();
};

void ListBrlyQLocEnd1NLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocEnd1NLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocEnd1NLeg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocEnd1NLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocEnd1NLeg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocEnd1NLeg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocEnd1NLeg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

