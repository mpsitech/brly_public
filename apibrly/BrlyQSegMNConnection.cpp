/**
  * \file BrlyQSegMNConnection.cpp
  * API code for table TblBrlyQSegMNConnection (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQSegMNConnection.h"

/******************************************************************************
 class BrlyQSegMNConnection
 ******************************************************************************/

BrlyQSegMNConnection::BrlyQSegMNConnection(
			const uint jnum
			, const string stubMref
			, const string ftmX1Start
			, const string ftmX1Stop
			, const double x2Legphi0
			, const double x2Legphi1
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->ftmX1Start = ftmX1Start;
	this->ftmX1Stop = ftmX1Stop;
	this->x2Legphi0 = x2Legphi0;
	this->x2Legphi1 = x2Legphi1;
};

bool BrlyQSegMNConnection::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQSegMNConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "ftmX1Start", "sta", ftmX1Start);
		extractStringUclc(docctx, basexpath, "ftmX1Stop", "sto", ftmX1Stop);
		extractDoubleUclc(docctx, basexpath, "x2Legphi0", "lp0", x2Legphi0);
		extractDoubleUclc(docctx, basexpath, "x2Legphi1", "lp1", x2Legphi1);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQSegMNConnection
 ******************************************************************************/

ListBrlyQSegMNConnection::ListBrlyQSegMNConnection() {
};

ListBrlyQSegMNConnection::ListBrlyQSegMNConnection(
			const ListBrlyQSegMNConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegMNConnection(*(src.nodes[i]));
};

ListBrlyQSegMNConnection& ListBrlyQSegMNConnection::operator=(
			const ListBrlyQSegMNConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegMNConnection(*(src.nodes[i]));

	return *this;
};

ListBrlyQSegMNConnection::~ListBrlyQSegMNConnection() {
	clear();
};

void ListBrlyQSegMNConnection::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQSegMNConnection::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQSegMNConnection* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQSegMNConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQSegMNConnection", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQSegMNConnection(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQSegMNConnection[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

