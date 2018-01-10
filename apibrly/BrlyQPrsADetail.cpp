/**
  * \file BrlyQPrsADetail.cpp
  * API code for table TblBrlyQPrsADetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQPrsADetail.h"

/******************************************************************************
 class BrlyQPrsADetail
 ******************************************************************************/

BrlyQPrsADetail::BrlyQPrsADetail(
			const uint jnum
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	this->jnum = jnum;
	this->x1SrefKType = x1SrefKType;
	this->titX1SrefKType = titX1SrefKType;
	this->Val = Val;
};

bool BrlyQPrsADetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQPrsADetail");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1SrefKType", "typ", x1SrefKType);
		extractStringUclc(docctx, basexpath, "titX1SrefKType", "typ2", titX1SrefKType);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQPrsADetail
 ******************************************************************************/

ListBrlyQPrsADetail::ListBrlyQPrsADetail() {
};

ListBrlyQPrsADetail::ListBrlyQPrsADetail(
			const ListBrlyQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQPrsADetail(*(src.nodes[i]));
};

ListBrlyQPrsADetail& ListBrlyQPrsADetail::operator=(
			const ListBrlyQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQPrsADetail(*(src.nodes[i]));

	return *this;
};

ListBrlyQPrsADetail::~ListBrlyQPrsADetail() {
	clear();
};

void ListBrlyQPrsADetail::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQPrsADetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQPrsADetail* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQPrsADetail");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQPrsADetail", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQPrsADetail(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQPrsADetail[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

