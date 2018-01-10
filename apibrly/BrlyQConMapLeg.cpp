/**
  * \file BrlyQConMapLeg.cpp
  * API code for table TblBrlyQConMapLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQConMapLeg.h"

/******************************************************************************
 class BrlyQConMapLeg
 ******************************************************************************/

BrlyQConMapLeg::BrlyQConMapLeg(
			const uint jnum
			, const string stubMref
			, const double dx
			, const double dy
			, const double x0
			, const double y0
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->dx = dx;
	this->dy = dy;
	this->x0 = x0;
	this->y0 = y0;
};

bool BrlyQConMapLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQConMapLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractDoubleUclc(docctx, basexpath, "dx", "dx", dx);
		extractDoubleUclc(docctx, basexpath, "dy", "dy", dy);
		extractDoubleUclc(docctx, basexpath, "x0", "x0", x0);
		extractDoubleUclc(docctx, basexpath, "y0", "y0", y0);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQConMapLeg
 ******************************************************************************/

ListBrlyQConMapLeg::ListBrlyQConMapLeg() {
};

ListBrlyQConMapLeg::ListBrlyQConMapLeg(
			const ListBrlyQConMapLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapLeg(*(src.nodes[i]));
};

ListBrlyQConMapLeg& ListBrlyQConMapLeg::operator=(
			const ListBrlyQConMapLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapLeg(*(src.nodes[i]));

	return *this;
};

ListBrlyQConMapLeg::~ListBrlyQConMapLeg() {
	clear();
};

void ListBrlyQConMapLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQConMapLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQConMapLeg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQConMapLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQConMapLeg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQConMapLeg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQConMapLeg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

