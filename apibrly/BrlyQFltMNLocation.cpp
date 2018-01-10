/**
  * \file BrlyQFltMNLocation.cpp
  * API code for table TblBrlyQFltMNLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQFltMNLocation.h"

/******************************************************************************
 class BrlyQFltMNLocation
 ******************************************************************************/

BrlyQFltMNLocation::BrlyQFltMNLocation(
			const uint jnum
			, const string stubMref
			, const string ftmX1VisStart
			, const string ftmX1VisStop
			, const string ftmXVisStart
			, const string ftmXVisStop
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->ftmX1VisStart = ftmX1VisStart;
	this->ftmX1VisStop = ftmX1VisStop;
	this->ftmXVisStart = ftmXVisStart;
	this->ftmXVisStop = ftmXVisStop;
};

bool BrlyQFltMNLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQFltMNLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "ftmX1VisStart", "sta", ftmX1VisStart);
		extractStringUclc(docctx, basexpath, "ftmX1VisStop", "sto", ftmX1VisStop);
		extractStringUclc(docctx, basexpath, "ftmXVisStart", "xsa", ftmXVisStart);
		extractStringUclc(docctx, basexpath, "ftmXVisStop", "xso", ftmXVisStop);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQFltMNLocation
 ******************************************************************************/

ListBrlyQFltMNLocation::ListBrlyQFltMNLocation() {
};

ListBrlyQFltMNLocation::ListBrlyQFltMNLocation(
			const ListBrlyQFltMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltMNLocation(*(src.nodes[i]));
};

ListBrlyQFltMNLocation& ListBrlyQFltMNLocation::operator=(
			const ListBrlyQFltMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltMNLocation(*(src.nodes[i]));

	return *this;
};

ListBrlyQFltMNLocation::~ListBrlyQFltMNLocation() {
	clear();
};

void ListBrlyQFltMNLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQFltMNLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQFltMNLocation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQFltMNLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQFltMNLocation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQFltMNLocation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQFltMNLocation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

