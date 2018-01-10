/**
  * \file BrlyQPtyList.cpp
  * API code for table TblBrlyQPtyList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQPtyList.h"

/******************************************************************************
 class BrlyQPtyList
 ******************************************************************************/

BrlyQPtyList::BrlyQPtyList(
			const uint jnum
			, const string sref
			, const string Title
			, const string srefBrlyKEqptype
			, const string titSrefBrlyKEqptype
			, const usmallint Capacity
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->srefBrlyKEqptype = srefBrlyKEqptype;
	this->titSrefBrlyKEqptype = titSrefBrlyKEqptype;
	this->Capacity = Capacity;
};

bool BrlyQPtyList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQPtyList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefBrlyKEqptype", "ety", srefBrlyKEqptype);
		extractStringUclc(docctx, basexpath, "titSrefBrlyKEqptype", "ety2", titSrefBrlyKEqptype);
		extractUsmallintUclc(docctx, basexpath, "Capacity", "cap", Capacity);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQPtyList
 ******************************************************************************/

ListBrlyQPtyList::ListBrlyQPtyList() {
};

ListBrlyQPtyList::ListBrlyQPtyList(
			const ListBrlyQPtyList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQPtyList(*(src.nodes[i]));
};

ListBrlyQPtyList& ListBrlyQPtyList::operator=(
			const ListBrlyQPtyList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQPtyList(*(src.nodes[i]));

	return *this;
};

ListBrlyQPtyList::~ListBrlyQPtyList() {
	clear();
};

void ListBrlyQPtyList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQPtyList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQPtyList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQPtyList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQPtyList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQPtyList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQPtyList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

