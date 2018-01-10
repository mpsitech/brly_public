/**
  * \file BrlyQSegOrgMNSegment.cpp
  * API code for table TblBrlyQSegOrgMNSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQSegOrgMNSegment.h"

/******************************************************************************
 class BrlyQSegOrgMNSegment
 ******************************************************************************/

BrlyQSegOrgMNSegment::BrlyQSegOrgMNSegment(
			const uint jnum
			, const string stubMref
			, const string ftmX1Start
			, const string ftmX1Stop
			, const double x2VisDstSegphi0
			, const double x2VisDstSegphi1
			, const double VisOrgSegphi0
			, const double VisOrgSegphi1
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->ftmX1Start = ftmX1Start;
	this->ftmX1Stop = ftmX1Stop;
	this->x2VisDstSegphi0 = x2VisDstSegphi0;
	this->x2VisDstSegphi1 = x2VisDstSegphi1;
	this->VisOrgSegphi0 = VisOrgSegphi0;
	this->VisOrgSegphi1 = VisOrgSegphi1;
};

bool BrlyQSegOrgMNSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQSegOrgMNSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "ftmX1Start", "sta", ftmX1Start);
		extractStringUclc(docctx, basexpath, "ftmX1Stop", "sto", ftmX1Stop);
		extractDoubleUclc(docctx, basexpath, "x2VisDstSegphi0", "dp0", x2VisDstSegphi0);
		extractDoubleUclc(docctx, basexpath, "x2VisDstSegphi1", "dp1", x2VisDstSegphi1);
		extractDoubleUclc(docctx, basexpath, "VisOrgSegphi0", "op0", VisOrgSegphi0);
		extractDoubleUclc(docctx, basexpath, "VisOrgSegphi1", "op1", VisOrgSegphi1);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQSegOrgMNSegment
 ******************************************************************************/

ListBrlyQSegOrgMNSegment::ListBrlyQSegOrgMNSegment() {
};

ListBrlyQSegOrgMNSegment::ListBrlyQSegOrgMNSegment(
			const ListBrlyQSegOrgMNSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegOrgMNSegment(*(src.nodes[i]));
};

ListBrlyQSegOrgMNSegment& ListBrlyQSegOrgMNSegment::operator=(
			const ListBrlyQSegOrgMNSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegOrgMNSegment(*(src.nodes[i]));

	return *this;
};

ListBrlyQSegOrgMNSegment::~ListBrlyQSegOrgMNSegment() {
	clear();
};

void ListBrlyQSegOrgMNSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQSegOrgMNSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQSegOrgMNSegment* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQSegOrgMNSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQSegOrgMNSegment", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQSegOrgMNSegment(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQSegOrgMNSegment[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

