/**
  * \file BrlyQLegOrgMNLeg.cpp
  * API code for table TblBrlyQLegOrgMNLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLegOrgMNLeg.h"

/******************************************************************************
 class BrlyQLegOrgMNLeg
 ******************************************************************************/

BrlyQLegOrgMNLeg::BrlyQLegOrgMNLeg(
			const uint jnum
			, const string stubMref
			, const double x1VisDstLegphi0
			, const double x1VisDstLegphi1
			, const double VisOrgLegphi0
			, const double VisOrgLegphi1
			, const double xVisDstLegphi0
			, const double xVisDstLegphi1
			, const double xVisOrgLegphi0
			, const double xVisOrgLegphi1
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->x1VisDstLegphi0 = x1VisDstLegphi0;
	this->x1VisDstLegphi1 = x1VisDstLegphi1;
	this->VisOrgLegphi0 = VisOrgLegphi0;
	this->VisOrgLegphi1 = VisOrgLegphi1;
	this->xVisDstLegphi0 = xVisDstLegphi0;
	this->xVisDstLegphi1 = xVisDstLegphi1;
	this->xVisOrgLegphi0 = xVisOrgLegphi0;
	this->xVisOrgLegphi1 = xVisOrgLegphi1;
};

bool BrlyQLegOrgMNLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLegOrgMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractDoubleUclc(docctx, basexpath, "x1VisDstLegphi0", "dp0", x1VisDstLegphi0);
		extractDoubleUclc(docctx, basexpath, "x1VisDstLegphi1", "dp1", x1VisDstLegphi1);
		extractDoubleUclc(docctx, basexpath, "VisOrgLegphi0", "op0", VisOrgLegphi0);
		extractDoubleUclc(docctx, basexpath, "VisOrgLegphi1", "op1", VisOrgLegphi1);
		extractDoubleUclc(docctx, basexpath, "xVisDstLegphi0", "xd0", xVisDstLegphi0);
		extractDoubleUclc(docctx, basexpath, "xVisDstLegphi1", "xd1", xVisDstLegphi1);
		extractDoubleUclc(docctx, basexpath, "xVisOrgLegphi0", "xo0", xVisOrgLegphi0);
		extractDoubleUclc(docctx, basexpath, "xVisOrgLegphi1", "xo1", xVisOrgLegphi1);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLegOrgMNLeg
 ******************************************************************************/

ListBrlyQLegOrgMNLeg::ListBrlyQLegOrgMNLeg() {
};

ListBrlyQLegOrgMNLeg::ListBrlyQLegOrgMNLeg(
			const ListBrlyQLegOrgMNLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegOrgMNLeg(*(src.nodes[i]));
};

ListBrlyQLegOrgMNLeg& ListBrlyQLegOrgMNLeg::operator=(
			const ListBrlyQLegOrgMNLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegOrgMNLeg(*(src.nodes[i]));

	return *this;
};

ListBrlyQLegOrgMNLeg::~ListBrlyQLegOrgMNLeg() {
	clear();
};

void ListBrlyQLegOrgMNLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLegOrgMNLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLegOrgMNLeg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLegOrgMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLegOrgMNLeg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLegOrgMNLeg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLegOrgMNLeg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

