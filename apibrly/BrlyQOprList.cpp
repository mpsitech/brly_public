/**
  * \file BrlyQOprList.cpp
  * API code for table TblBrlyQOprList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQOprList.h"

/******************************************************************************
 class BrlyQOprList
 ******************************************************************************/

BrlyQOprList::BrlyQOprList(
			const uint jnum
			, const string sref
			, const string srefICAO
			, const string Title
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefICAO = srefICAO;
	this->Title = Title;
};

bool BrlyQOprList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQOprList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefICAO", "ica", srefICAO);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQOprList
 ******************************************************************************/

ListBrlyQOprList::ListBrlyQOprList() {
};

ListBrlyQOprList::ListBrlyQOprList(
			const ListBrlyQOprList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQOprList(*(src.nodes[i]));
};

ListBrlyQOprList& ListBrlyQOprList::operator=(
			const ListBrlyQOprList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQOprList(*(src.nodes[i]));

	return *this;
};

ListBrlyQOprList::~ListBrlyQOprList() {
	clear();
};

void ListBrlyQOprList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQOprList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQOprList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQOprList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQOprList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQOprList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQOprList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

