/**
  * \file BrlyQTtbList.cpp
  * API code for table TblBrlyQTtbList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQTtbList.h"

/******************************************************************************
 class BrlyQTtbList
 ******************************************************************************/

BrlyQTtbList::BrlyQTtbList(
			const uint jnum
			, const string Title
			, const string stubRefBrlyMFile
			, const string srefBrlyKAlliance
			, const string titSrefBrlyKAlliance
			, const string ftmStartd
			, const string ftmStopd
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->stubRefBrlyMFile = stubRefBrlyMFile;
	this->srefBrlyKAlliance = srefBrlyKAlliance;
	this->titSrefBrlyKAlliance = titSrefBrlyKAlliance;
	this->ftmStartd = ftmStartd;
	this->ftmStopd = ftmStopd;
};

bool BrlyQTtbList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQTtbList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefBrlyMFile", "fil", stubRefBrlyMFile);
		extractStringUclc(docctx, basexpath, "srefBrlyKAlliance", "ali", srefBrlyKAlliance);
		extractStringUclc(docctx, basexpath, "titSrefBrlyKAlliance", "ali2", titSrefBrlyKAlliance);
		extractStringUclc(docctx, basexpath, "ftmStartd", "sta", ftmStartd);
		extractStringUclc(docctx, basexpath, "ftmStopd", "sto", ftmStopd);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQTtbList
 ******************************************************************************/

ListBrlyQTtbList::ListBrlyQTtbList() {
};

ListBrlyQTtbList::ListBrlyQTtbList(
			const ListBrlyQTtbList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQTtbList(*(src.nodes[i]));
};

ListBrlyQTtbList& ListBrlyQTtbList::operator=(
			const ListBrlyQTtbList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQTtbList(*(src.nodes[i]));

	return *this;
};

ListBrlyQTtbList::~ListBrlyQTtbList() {
	clear();
};

void ListBrlyQTtbList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQTtbList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQTtbList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQTtbList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQTtbList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQTtbList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQTtbList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

