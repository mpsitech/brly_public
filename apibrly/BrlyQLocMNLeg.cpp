/**
  * \file BrlyQLocMNLeg.cpp
  * API code for table TblBrlyQLocMNLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocMNLeg.h"

/******************************************************************************
 class BrlyQLocMNLeg
 ******************************************************************************/

BrlyQLocMNLeg::BrlyQLocMNLeg(
			const uint jnum
			, const string stubMref
			, const double x1VisLegphi0
			, const double x1VisLegphi1
			, const double legphi
			, const double legtheta
			, const double xVisLegphi0
			, const double xVisLegphi1
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->x1VisLegphi0 = x1VisLegphi0;
	this->x1VisLegphi1 = x1VisLegphi1;
	this->legphi = legphi;
	this->legtheta = legtheta;
	this->xVisLegphi0 = xVisLegphi0;
	this->xVisLegphi1 = xVisLegphi1;
};

bool BrlyQLocMNLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractDoubleUclc(docctx, basexpath, "x1VisLegphi0", "lp0", x1VisLegphi0);
		extractDoubleUclc(docctx, basexpath, "x1VisLegphi1", "lp1", x1VisLegphi1);
		extractDoubleUclc(docctx, basexpath, "legphi", "lph", legphi);
		extractDoubleUclc(docctx, basexpath, "legtheta", "lth", legtheta);
		extractDoubleUclc(docctx, basexpath, "xVisLegphi0", "xp0", xVisLegphi0);
		extractDoubleUclc(docctx, basexpath, "xVisLegphi1", "xp1", xVisLegphi1);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLocMNLeg
 ******************************************************************************/

ListBrlyQLocMNLeg::ListBrlyQLocMNLeg() {
};

ListBrlyQLocMNLeg::ListBrlyQLocMNLeg(
			const ListBrlyQLocMNLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMNLeg(*(src.nodes[i]));
};

ListBrlyQLocMNLeg& ListBrlyQLocMNLeg::operator=(
			const ListBrlyQLocMNLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMNLeg(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocMNLeg::~ListBrlyQLocMNLeg() {
	clear();
};

void ListBrlyQLocMNLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocMNLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocMNLeg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocMNLeg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocMNLeg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocMNLeg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

