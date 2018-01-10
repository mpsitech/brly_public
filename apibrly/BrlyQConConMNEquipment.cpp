/**
  * \file BrlyQConConMNEquipment.cpp
  * API code for table TblBrlyQConConMNEquipment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQConConMNEquipment.h"

/******************************************************************************
 class BrlyQConConMNEquipment
 ******************************************************************************/

BrlyQConConMNEquipment::BrlyQConConMNEquipment(
			const uint jnum
			, const string stubMref
			, const string srefConIxBrlyVLat
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefConIxBrlyVLat = srefConIxBrlyVLat;
};

bool BrlyQConConMNEquipment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQConConMNEquipment");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefConIxBrlyVLat", "lat", srefConIxBrlyVLat);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQConConMNEquipment
 ******************************************************************************/

ListBrlyQConConMNEquipment::ListBrlyQConConMNEquipment() {
};

ListBrlyQConConMNEquipment::ListBrlyQConConMNEquipment(
			const ListBrlyQConConMNEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConConMNEquipment(*(src.nodes[i]));
};

ListBrlyQConConMNEquipment& ListBrlyQConConMNEquipment::operator=(
			const ListBrlyQConConMNEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConConMNEquipment(*(src.nodes[i]));

	return *this;
};

ListBrlyQConConMNEquipment::~ListBrlyQConConMNEquipment() {
	clear();
};

void ListBrlyQConConMNEquipment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQConConMNEquipment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQConConMNEquipment* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQConConMNEquipment");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQConConMNEquipment", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQConConMNEquipment(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQConConMNEquipment[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

