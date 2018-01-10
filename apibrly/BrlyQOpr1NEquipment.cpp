/**
  * \file BrlyQOpr1NEquipment.cpp
  * API code for table TblBrlyQOpr1NEquipment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQOpr1NEquipment.h"

/******************************************************************************
 class BrlyQOpr1NEquipment
 ******************************************************************************/

BrlyQOpr1NEquipment::BrlyQOpr1NEquipment(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQOpr1NEquipment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQOpr1NEquipment");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQOpr1NEquipment
 ******************************************************************************/

ListBrlyQOpr1NEquipment::ListBrlyQOpr1NEquipment() {
};

ListBrlyQOpr1NEquipment::ListBrlyQOpr1NEquipment(
			const ListBrlyQOpr1NEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQOpr1NEquipment(*(src.nodes[i]));
};

ListBrlyQOpr1NEquipment& ListBrlyQOpr1NEquipment::operator=(
			const ListBrlyQOpr1NEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQOpr1NEquipment(*(src.nodes[i]));

	return *this;
};

ListBrlyQOpr1NEquipment::~ListBrlyQOpr1NEquipment() {
	clear();
};

void ListBrlyQOpr1NEquipment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQOpr1NEquipment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQOpr1NEquipment* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQOpr1NEquipment");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQOpr1NEquipment", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQOpr1NEquipment(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQOpr1NEquipment[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

