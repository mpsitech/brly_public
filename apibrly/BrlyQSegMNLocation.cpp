/**
  * \file BrlyQSegMNLocation.cpp
  * API code for table TblBrlyQSegMNLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQSegMNLocation.h"

/******************************************************************************
 class BrlyQSegMNLocation
 ******************************************************************************/

BrlyQSegMNLocation::BrlyQSegMNLocation(
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

bool BrlyQSegMNLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQSegMNLocation");
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
 class ListBrlyQSegMNLocation
 ******************************************************************************/

ListBrlyQSegMNLocation::ListBrlyQSegMNLocation() {
};

ListBrlyQSegMNLocation::ListBrlyQSegMNLocation(
			const ListBrlyQSegMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegMNLocation(*(src.nodes[i]));
};

ListBrlyQSegMNLocation& ListBrlyQSegMNLocation::operator=(
			const ListBrlyQSegMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegMNLocation(*(src.nodes[i]));

	return *this;
};

ListBrlyQSegMNLocation::~ListBrlyQSegMNLocation() {
	clear();
};

void ListBrlyQSegMNLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQSegMNLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQSegMNLocation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQSegMNLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQSegMNLocation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQSegMNLocation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQSegMNLocation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

