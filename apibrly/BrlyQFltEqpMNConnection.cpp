/**
  * \file BrlyQFltEqpMNConnection.cpp
  * API code for table TblBrlyQFltEqpMNConnection (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQFltEqpMNConnection.h"

/******************************************************************************
 class BrlyQFltEqpMNConnection
 ******************************************************************************/

BrlyQFltEqpMNConnection::BrlyQFltEqpMNConnection(
			const uint jnum
			, const string stubMref
			, const string srefConIxBrlyVLat
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefConIxBrlyVLat = srefConIxBrlyVLat;
};

bool BrlyQFltEqpMNConnection::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQFltEqpMNConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefConIxBrlyVLat", "lat", srefConIxBrlyVLat);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQFltEqpMNConnection
 ******************************************************************************/

ListBrlyQFltEqpMNConnection::ListBrlyQFltEqpMNConnection() {
};

ListBrlyQFltEqpMNConnection::ListBrlyQFltEqpMNConnection(
			const ListBrlyQFltEqpMNConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltEqpMNConnection(*(src.nodes[i]));
};

ListBrlyQFltEqpMNConnection& ListBrlyQFltEqpMNConnection::operator=(
			const ListBrlyQFltEqpMNConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltEqpMNConnection(*(src.nodes[i]));

	return *this;
};

ListBrlyQFltEqpMNConnection::~ListBrlyQFltEqpMNConnection() {
	clear();
};

void ListBrlyQFltEqpMNConnection::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQFltEqpMNConnection::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQFltEqpMNConnection* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQFltEqpMNConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQFltEqpMNConnection", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQFltEqpMNConnection(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQFltEqpMNConnection[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

