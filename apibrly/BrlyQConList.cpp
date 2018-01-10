/**
  * \file BrlyQConList.cpp
  * API code for table TblBrlyQConList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQConList.h"

/******************************************************************************
 class BrlyQConList
 ******************************************************************************/

BrlyQConList::BrlyQConList(
			const uint jnum
			, const string stubRefBrlyMFlight
			, const string stubCorRefBrlyMLeg
			, const string ftmStart
			, const string ftmStop
			, const string srefIxVModel
			, const string titIxVModel
		) {
	this->jnum = jnum;
	this->stubRefBrlyMFlight = stubRefBrlyMFlight;
	this->stubCorRefBrlyMLeg = stubCorRefBrlyMLeg;
	this->ftmStart = ftmStart;
	this->ftmStop = ftmStop;
	this->srefIxVModel = srefIxVModel;
	this->titIxVModel = titIxVModel;
};

bool BrlyQConList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQConList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefBrlyMFlight", "flt", stubRefBrlyMFlight);
		extractStringUclc(docctx, basexpath, "stubCorRefBrlyMLeg", "cor", stubCorRefBrlyMLeg);
		extractStringUclc(docctx, basexpath, "ftmStart", "sta", ftmStart);
		extractStringUclc(docctx, basexpath, "ftmStop", "sto", ftmStop);
		extractStringUclc(docctx, basexpath, "srefIxVModel", "mod", srefIxVModel);
		extractStringUclc(docctx, basexpath, "titIxVModel", "mod2", titIxVModel);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQConList
 ******************************************************************************/

ListBrlyQConList::ListBrlyQConList() {
};

ListBrlyQConList::ListBrlyQConList(
			const ListBrlyQConList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConList(*(src.nodes[i]));
};

ListBrlyQConList& ListBrlyQConList::operator=(
			const ListBrlyQConList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConList(*(src.nodes[i]));

	return *this;
};

ListBrlyQConList::~ListBrlyQConList() {
	clear();
};

void ListBrlyQConList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQConList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQConList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQConList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQConList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQConList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQConList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

