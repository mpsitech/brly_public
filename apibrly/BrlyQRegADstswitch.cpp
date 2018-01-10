/**
  * \file BrlyQRegADstswitch.cpp
  * API code for table TblBrlyQRegADstswitch (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQRegADstswitch.h"

/******************************************************************************
 class BrlyQRegADstswitch
 ******************************************************************************/

BrlyQRegADstswitch::BrlyQRegADstswitch(
			const uint jnum
			, const string ftmStartd
			, const string ftmStartt
		) {
	this->jnum = jnum;
	this->ftmStartd = ftmStartd;
	this->ftmStartt = ftmStartt;
};

bool BrlyQRegADstswitch::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQRegADstswitch");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "ftmStartd", "std", ftmStartd);
		extractStringUclc(docctx, basexpath, "ftmStartt", "stt", ftmStartt);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQRegADstswitch
 ******************************************************************************/

ListBrlyQRegADstswitch::ListBrlyQRegADstswitch() {
};

ListBrlyQRegADstswitch::ListBrlyQRegADstswitch(
			const ListBrlyQRegADstswitch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRegADstswitch(*(src.nodes[i]));
};

ListBrlyQRegADstswitch& ListBrlyQRegADstswitch::operator=(
			const ListBrlyQRegADstswitch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRegADstswitch(*(src.nodes[i]));

	return *this;
};

ListBrlyQRegADstswitch::~ListBrlyQRegADstswitch() {
	clear();
};

void ListBrlyQRegADstswitch::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQRegADstswitch::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQRegADstswitch* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQRegADstswitch");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQRegADstswitch", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQRegADstswitch(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQRegADstswitch[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

