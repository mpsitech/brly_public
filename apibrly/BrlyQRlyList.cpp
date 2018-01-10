/**
  * \file BrlyQRlyList.cpp
  * API code for table TblBrlyQRlyList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQRlyList.h"

/******************************************************************************
 class BrlyQRlyList
 ******************************************************************************/

BrlyQRlyList::BrlyQRlyList(
			const uint jnum
			, const string ftmX1Start
			, const string ftmX1Stop
			, const string stubRefBrlyMConnection
			, const string srefIxVDir
			, const string titIxVDir
			, const string yesnoConnected
		) {
	this->jnum = jnum;
	this->ftmX1Start = ftmX1Start;
	this->ftmX1Stop = ftmX1Stop;
	this->stubRefBrlyMConnection = stubRefBrlyMConnection;
	this->srefIxVDir = srefIxVDir;
	this->titIxVDir = titIxVDir;
	this->yesnoConnected = yesnoConnected;
};

bool BrlyQRlyList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQRlyList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "ftmX1Start", "sta", ftmX1Start);
		extractStringUclc(docctx, basexpath, "ftmX1Stop", "sto", ftmX1Stop);
		extractStringUclc(docctx, basexpath, "stubRefBrlyMConnection", "con", stubRefBrlyMConnection);
		extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir);
		extractStringUclc(docctx, basexpath, "titIxVDir", "dir2", titIxVDir);
		extractStringUclc(docctx, basexpath, "yesnoConnected", "ctd", yesnoConnected);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQRlyList
 ******************************************************************************/

ListBrlyQRlyList::ListBrlyQRlyList() {
};

ListBrlyQRlyList::ListBrlyQRlyList(
			const ListBrlyQRlyList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRlyList(*(src.nodes[i]));
};

ListBrlyQRlyList& ListBrlyQRlyList::operator=(
			const ListBrlyQRlyList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRlyList(*(src.nodes[i]));

	return *this;
};

ListBrlyQRlyList::~ListBrlyQRlyList() {
	clear();
};

void ListBrlyQRlyList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQRlyList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQRlyList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQRlyList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQRlyList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQRlyList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQRlyList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

