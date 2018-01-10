/**
  * \file BrlyQLocMapLeg.cpp
  * API code for table TblBrlyQLocMapLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocMapLeg.h"

/******************************************************************************
 class BrlyQLocMapLeg
 ******************************************************************************/

BrlyQLocMapLeg::BrlyQLocMapLeg(
			const uint jnum
			, const string stubMref
			, const double dx
			, const double dy
			, const double x0
			, const double y0
			, const double lam1
			, const double lam2
			, const double lam3
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->dx = dx;
	this->dy = dy;
	this->x0 = x0;
	this->y0 = y0;
	this->lam1 = lam1;
	this->lam2 = lam2;
	this->lam3 = lam3;
};

bool BrlyQLocMapLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocMapLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractDoubleUclc(docctx, basexpath, "dx", "dx", dx);
		extractDoubleUclc(docctx, basexpath, "dy", "dy", dy);
		extractDoubleUclc(docctx, basexpath, "x0", "x0", x0);
		extractDoubleUclc(docctx, basexpath, "y0", "y0", y0);
		extractDoubleUclc(docctx, basexpath, "lam1", "lm1", lam1);
		extractDoubleUclc(docctx, basexpath, "lam2", "lm2", lam2);
		extractDoubleUclc(docctx, basexpath, "lam3", "lm3", lam3);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLocMapLeg
 ******************************************************************************/

ListBrlyQLocMapLeg::ListBrlyQLocMapLeg() {
};

ListBrlyQLocMapLeg::ListBrlyQLocMapLeg(
			const ListBrlyQLocMapLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMapLeg(*(src.nodes[i]));
};

ListBrlyQLocMapLeg& ListBrlyQLocMapLeg::operator=(
			const ListBrlyQLocMapLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMapLeg(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocMapLeg::~ListBrlyQLocMapLeg() {
	clear();
};

void ListBrlyQLocMapLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocMapLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocMapLeg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocMapLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocMapLeg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocMapLeg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocMapLeg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

