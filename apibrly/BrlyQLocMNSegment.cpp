/**
  * \file BrlyQLocMNSegment.cpp
  * API code for table TblBrlyQLocMNSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocMNSegment.h"

/******************************************************************************
 class BrlyQLocMNSegment
 ******************************************************************************/

BrlyQLocMNSegment::BrlyQLocMNSegment(
			const uint jnum
			, const string stubMref
			, const string ftmX1Start
			, const string ftmX1Stop
			, const double x2VisSegphi0
			, const double x2VisSegphi1
			, const double segphi
			, const double segtheta
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->ftmX1Start = ftmX1Start;
	this->ftmX1Stop = ftmX1Stop;
	this->x2VisSegphi0 = x2VisSegphi0;
	this->x2VisSegphi1 = x2VisSegphi1;
	this->segphi = segphi;
	this->segtheta = segtheta;
};

bool BrlyQLocMNSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocMNSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "ftmX1Start", "sta", ftmX1Start);
		extractStringUclc(docctx, basexpath, "ftmX1Stop", "sto", ftmX1Stop);
		extractDoubleUclc(docctx, basexpath, "x2VisSegphi0", "sp0", x2VisSegphi0);
		extractDoubleUclc(docctx, basexpath, "x2VisSegphi1", "sp1", x2VisSegphi1);
		extractDoubleUclc(docctx, basexpath, "segphi", "sph", segphi);
		extractDoubleUclc(docctx, basexpath, "segtheta", "sth", segtheta);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLocMNSegment
 ******************************************************************************/

ListBrlyQLocMNSegment::ListBrlyQLocMNSegment() {
};

ListBrlyQLocMNSegment::ListBrlyQLocMNSegment(
			const ListBrlyQLocMNSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMNSegment(*(src.nodes[i]));
};

ListBrlyQLocMNSegment& ListBrlyQLocMNSegment::operator=(
			const ListBrlyQLocMNSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMNSegment(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocMNSegment::~ListBrlyQLocMNSegment() {
	clear();
};

void ListBrlyQLocMNSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocMNSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocMNSegment* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocMNSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocMNSegment", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocMNSegment(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocMNSegment[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

