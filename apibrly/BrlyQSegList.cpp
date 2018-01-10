/**
  * \file BrlyQSegList.cpp
  * API code for table TblBrlyQSegList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQSegList.h"

/******************************************************************************
 class BrlyQSegList
 ******************************************************************************/

BrlyQSegList::BrlyQSegList(
			const uint jnum
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const double alt0
			, const double alt1
			, const double theta0
			, const double theta1
			, const double phi0
			, const double phi1
			, const string ftmStart
			, const string ftmStop
		) {
	this->jnum = jnum;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
	this->alt0 = alt0;
	this->alt1 = alt1;
	this->theta0 = theta0;
	this->theta1 = theta1;
	this->phi0 = phi0;
	this->phi1 = phi1;
	this->ftmStart = ftmStart;
	this->ftmStop = ftmStop;
};

bool BrlyQSegList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQSegList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractDoubleUclc(docctx, basexpath, "alt0", "al0", alt0);
		extractDoubleUclc(docctx, basexpath, "alt1", "al1", alt1);
		extractDoubleUclc(docctx, basexpath, "theta0", "th0", theta0);
		extractDoubleUclc(docctx, basexpath, "theta1", "th1", theta1);
		extractDoubleUclc(docctx, basexpath, "phi0", "ph0", phi0);
		extractDoubleUclc(docctx, basexpath, "phi1", "ph1", phi1);
		extractStringUclc(docctx, basexpath, "ftmStart", "sta", ftmStart);
		extractStringUclc(docctx, basexpath, "ftmStop", "sto", ftmStop);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQSegList
 ******************************************************************************/

ListBrlyQSegList::ListBrlyQSegList() {
};

ListBrlyQSegList::ListBrlyQSegList(
			const ListBrlyQSegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegList(*(src.nodes[i]));
};

ListBrlyQSegList& ListBrlyQSegList::operator=(
			const ListBrlyQSegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegList(*(src.nodes[i]));

	return *this;
};

ListBrlyQSegList::~ListBrlyQSegList() {
	clear();
};

void ListBrlyQSegList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQSegList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQSegList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQSegList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQSegList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQSegList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQSegList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

