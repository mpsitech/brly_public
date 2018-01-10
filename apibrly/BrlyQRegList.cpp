/**
  * \file BrlyQRegList.cpp
  * API code for table TblBrlyQRegList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQRegList.h"

/******************************************************************************
 class BrlyQRegList
 ******************************************************************************/

BrlyQRegList::BrlyQRegList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubSupRefBrlyMRegion
			, const string srefIxVDst
			, const string titIxVDst
			, const double toffset
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubSupRefBrlyMRegion = stubSupRefBrlyMRegion;
	this->srefIxVDst = srefIxVDst;
	this->titIxVDst = titIxVDst;
	this->toffset = toffset;
};

bool BrlyQRegList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQRegList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubSupRefBrlyMRegion", "sup", stubSupRefBrlyMRegion);
		extractStringUclc(docctx, basexpath, "srefIxVDst", "dst", srefIxVDst);
		extractStringUclc(docctx, basexpath, "titIxVDst", "dst2", titIxVDst);
		extractDoubleUclc(docctx, basexpath, "toffset", "tof", toffset);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQRegList
 ******************************************************************************/

ListBrlyQRegList::ListBrlyQRegList() {
};

ListBrlyQRegList::ListBrlyQRegList(
			const ListBrlyQRegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRegList(*(src.nodes[i]));
};

ListBrlyQRegList& ListBrlyQRegList::operator=(
			const ListBrlyQRegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRegList(*(src.nodes[i]));

	return *this;
};

ListBrlyQRegList::~ListBrlyQRegList() {
	clear();
};

void ListBrlyQRegList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQRegList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQRegList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQRegList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQRegList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQRegList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQRegList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

