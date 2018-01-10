/**
  * \file BrlyQConMapRelay.cpp
  * API code for table TblBrlyQConMapRelay (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQConMapRelay.h"

/******************************************************************************
 class BrlyQConMapRelay
 ******************************************************************************/

BrlyQConMapRelay::BrlyQConMapRelay(
			const uint jnum
			, const uint x1Start
			, const uint x1Stop
			, const string srefIxVDir
			, const string yesnoConnected
			, const usmallint Nhop
		) {
	this->jnum = jnum;
	this->x1Start = x1Start;
	this->x1Stop = x1Stop;
	this->srefIxVDir = srefIxVDir;
	this->yesnoConnected = yesnoConnected;
	this->Nhop = Nhop;
};

bool BrlyQConMapRelay::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQConMapRelay");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractUintUclc(docctx, basexpath, "x1Start", "sta", x1Start);
		extractUintUclc(docctx, basexpath, "x1Stop", "sto", x1Stop);
		extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir);
		extractStringUclc(docctx, basexpath, "yesnoConnected", "ctd", yesnoConnected);
		extractUsmallintUclc(docctx, basexpath, "Nhop", "nhp", Nhop);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQConMapRelay
 ******************************************************************************/

ListBrlyQConMapRelay::ListBrlyQConMapRelay() {
};

ListBrlyQConMapRelay::ListBrlyQConMapRelay(
			const ListBrlyQConMapRelay& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapRelay(*(src.nodes[i]));
};

ListBrlyQConMapRelay& ListBrlyQConMapRelay::operator=(
			const ListBrlyQConMapRelay& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapRelay(*(src.nodes[i]));

	return *this;
};

ListBrlyQConMapRelay::~ListBrlyQConMapRelay() {
	clear();
};

void ListBrlyQConMapRelay::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQConMapRelay::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQConMapRelay* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQConMapRelay");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQConMapRelay", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQConMapRelay(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQConMapRelay[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

