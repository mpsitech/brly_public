/**
  * \file BrlyQFltOrgMNFlight.cpp
  * API code for table TblBrlyQFltOrgMNFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQFltOrgMNFlight.h"

/******************************************************************************
 class BrlyQFltOrgMNFlight
 ******************************************************************************/

BrlyQFltOrgMNFlight::BrlyQFltOrgMNFlight(
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

bool BrlyQFltOrgMNFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQFltOrgMNFlight");
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
 class ListBrlyQFltOrgMNFlight
 ******************************************************************************/

ListBrlyQFltOrgMNFlight::ListBrlyQFltOrgMNFlight() {
};

ListBrlyQFltOrgMNFlight::ListBrlyQFltOrgMNFlight(
			const ListBrlyQFltOrgMNFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltOrgMNFlight(*(src.nodes[i]));
};

ListBrlyQFltOrgMNFlight& ListBrlyQFltOrgMNFlight::operator=(
			const ListBrlyQFltOrgMNFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltOrgMNFlight(*(src.nodes[i]));

	return *this;
};

ListBrlyQFltOrgMNFlight::~ListBrlyQFltOrgMNFlight() {
	clear();
};

void ListBrlyQFltOrgMNFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQFltOrgMNFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQFltOrgMNFlight* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQFltOrgMNFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQFltOrgMNFlight", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQFltOrgMNFlight(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQFltOrgMNFlight[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

