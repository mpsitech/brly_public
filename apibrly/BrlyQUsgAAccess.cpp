/**
  * \file BrlyQUsgAAccess.cpp
  * API code for table TblBrlyQUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQUsgAAccess.h"

/******************************************************************************
 class BrlyQUsgAAccess
 ******************************************************************************/

BrlyQUsgAAccess::BrlyQUsgAAccess(
			const uint jnum
			, const string srefX1IxBrlyVCard
			, const string titX1IxBrlyVCard
			, const string srefsIxBrlyWUiaccess
			, const string titsIxBrlyWUiaccess
		) {
	this->jnum = jnum;
	this->srefX1IxBrlyVCard = srefX1IxBrlyVCard;
	this->titX1IxBrlyVCard = titX1IxBrlyVCard;
	this->srefsIxBrlyWUiaccess = srefsIxBrlyWUiaccess;
	this->titsIxBrlyWUiaccess = titsIxBrlyWUiaccess;
};

bool BrlyQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1IxBrlyVCard", "crd", srefX1IxBrlyVCard);
		extractStringUclc(docctx, basexpath, "titX1IxBrlyVCard", "crd2", titX1IxBrlyVCard);
		extractStringUclc(docctx, basexpath, "srefsIxBrlyWUiaccess", "uac", srefsIxBrlyWUiaccess);
		extractStringUclc(docctx, basexpath, "titsIxBrlyWUiaccess", "uac2", titsIxBrlyWUiaccess);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQUsgAAccess
 ******************************************************************************/

ListBrlyQUsgAAccess::ListBrlyQUsgAAccess() {
};

ListBrlyQUsgAAccess::ListBrlyQUsgAAccess(
			const ListBrlyQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsgAAccess(*(src.nodes[i]));
};

ListBrlyQUsgAAccess& ListBrlyQUsgAAccess::operator=(
			const ListBrlyQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsgAAccess(*(src.nodes[i]));

	return *this;
};

ListBrlyQUsgAAccess::~ListBrlyQUsgAAccess() {
	clear();
};

void ListBrlyQUsgAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQUsgAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQUsgAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQUsgAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQUsgAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

