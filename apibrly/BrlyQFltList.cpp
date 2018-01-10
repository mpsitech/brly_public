/**
  * \file BrlyQFltList.cpp
  * API code for table TblBrlyQFltList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQFltList.h"

/******************************************************************************
 class BrlyQFltList
 ******************************************************************************/

BrlyQFltList::BrlyQFltList(
			const uint jnum
			, const string sref
			, const string stubRefBrlyMEquipment
			, const string stubRefBrlyMLeg
			, const string ftmStart
			, const string ftmStop
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefBrlyMEquipment = stubRefBrlyMEquipment;
	this->stubRefBrlyMLeg = stubRefBrlyMLeg;
	this->ftmStart = ftmStart;
	this->ftmStop = ftmStop;
};

bool BrlyQFltList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQFltList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefBrlyMEquipment", "eqp", stubRefBrlyMEquipment);
		extractStringUclc(docctx, basexpath, "stubRefBrlyMLeg", "leg", stubRefBrlyMLeg);
		extractStringUclc(docctx, basexpath, "ftmStart", "sta", ftmStart);
		extractStringUclc(docctx, basexpath, "ftmStop", "sto", ftmStop);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQFltList
 ******************************************************************************/

ListBrlyQFltList::ListBrlyQFltList() {
};

ListBrlyQFltList::ListBrlyQFltList(
			const ListBrlyQFltList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltList(*(src.nodes[i]));
};

ListBrlyQFltList& ListBrlyQFltList::operator=(
			const ListBrlyQFltList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltList(*(src.nodes[i]));

	return *this;
};

ListBrlyQFltList::~ListBrlyQFltList() {
	clear();
};

void ListBrlyQFltList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQFltList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQFltList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQFltList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQFltList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQFltList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQFltList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

