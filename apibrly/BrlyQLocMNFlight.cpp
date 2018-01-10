/**
  * \file BrlyQLocMNFlight.cpp
  * API code for table TblBrlyQLocMNFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocMNFlight.h"

/******************************************************************************
 class BrlyQLocMNFlight
 ******************************************************************************/

BrlyQLocMNFlight::BrlyQLocMNFlight(
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

bool BrlyQLocMNFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocMNFlight");
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
 class ListBrlyQLocMNFlight
 ******************************************************************************/

ListBrlyQLocMNFlight::ListBrlyQLocMNFlight() {
};

ListBrlyQLocMNFlight::ListBrlyQLocMNFlight(
			const ListBrlyQLocMNFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMNFlight(*(src.nodes[i]));
};

ListBrlyQLocMNFlight& ListBrlyQLocMNFlight::operator=(
			const ListBrlyQLocMNFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMNFlight(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocMNFlight::~ListBrlyQLocMNFlight() {
	clear();
};

void ListBrlyQLocMNFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocMNFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocMNFlight* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocMNFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocMNFlight", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocMNFlight(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocMNFlight[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

