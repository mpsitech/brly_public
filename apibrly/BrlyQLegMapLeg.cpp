/**
  * \file BrlyQLegMapLeg.cpp
  * API code for table TblBrlyQLegMapLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLegMapLeg.h"

/******************************************************************************
 class BrlyQLegMapLeg
 ******************************************************************************/

BrlyQLegMapLeg::BrlyQLegMapLeg(
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

bool BrlyQLegMapLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLegMapLeg");
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
 class ListBrlyQLegMapLeg
 ******************************************************************************/

ListBrlyQLegMapLeg::ListBrlyQLegMapLeg() {
};

ListBrlyQLegMapLeg::ListBrlyQLegMapLeg(
			const ListBrlyQLegMapLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegMapLeg(*(src.nodes[i]));
};

ListBrlyQLegMapLeg& ListBrlyQLegMapLeg::operator=(
			const ListBrlyQLegMapLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegMapLeg(*(src.nodes[i]));

	return *this;
};

ListBrlyQLegMapLeg::~ListBrlyQLegMapLeg() {
	clear();
};

void ListBrlyQLegMapLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLegMapLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLegMapLeg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLegMapLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLegMapLeg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLegMapLeg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLegMapLeg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

