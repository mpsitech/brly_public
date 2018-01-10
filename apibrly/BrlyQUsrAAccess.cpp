/**
  * \file BrlyQUsrAAccess.cpp
  * API code for table TblBrlyQUsrAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQUsrAAccess.h"

/******************************************************************************
 class BrlyQUsrAAccess
 ******************************************************************************/

BrlyQUsrAAccess::BrlyQUsrAAccess(
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

bool BrlyQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQUsrAAccess");
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
 class ListBrlyQUsrAAccess
 ******************************************************************************/

ListBrlyQUsrAAccess::ListBrlyQUsrAAccess() {
};

ListBrlyQUsrAAccess::ListBrlyQUsrAAccess(
			const ListBrlyQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsrAAccess(*(src.nodes[i]));
};

ListBrlyQUsrAAccess& ListBrlyQUsrAAccess::operator=(
			const ListBrlyQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsrAAccess(*(src.nodes[i]));

	return *this;
};

ListBrlyQUsrAAccess::~ListBrlyQUsrAAccess() {
	clear();
};

void ListBrlyQUsrAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQUsrAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQUsrAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQUsrAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQUsrAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQUsrAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

