/**
  * \file BrlyQPty1NEquipment.cpp
  * API code for table TblBrlyQPty1NEquipment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQPty1NEquipment.h"

/******************************************************************************
 class BrlyQPty1NEquipment
 ******************************************************************************/

BrlyQPty1NEquipment::BrlyQPty1NEquipment(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQPty1NEquipment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQPty1NEquipment");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQPty1NEquipment
 ******************************************************************************/

ListBrlyQPty1NEquipment::ListBrlyQPty1NEquipment() {
};

ListBrlyQPty1NEquipment::ListBrlyQPty1NEquipment(
			const ListBrlyQPty1NEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQPty1NEquipment(*(src.nodes[i]));
};

ListBrlyQPty1NEquipment& ListBrlyQPty1NEquipment::operator=(
			const ListBrlyQPty1NEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQPty1NEquipment(*(src.nodes[i]));

	return *this;
};

ListBrlyQPty1NEquipment::~ListBrlyQPty1NEquipment() {
	clear();
};

void ListBrlyQPty1NEquipment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQPty1NEquipment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQPty1NEquipment* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQPty1NEquipment");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQPty1NEquipment", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQPty1NEquipment(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQPty1NEquipment[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

