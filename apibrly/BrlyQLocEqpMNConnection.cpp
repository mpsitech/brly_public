/**
  * \file BrlyQLocEqpMNConnection.cpp
  * API code for table TblBrlyQLocEqpMNConnection (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocEqpMNConnection.h"

/******************************************************************************
 class BrlyQLocEqpMNConnection
 ******************************************************************************/

BrlyQLocEqpMNConnection::BrlyQLocEqpMNConnection(
			const uint jnum
			, const string stubMref
			, const string srefConIxBrlyVLat
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefConIxBrlyVLat = srefConIxBrlyVLat;
};

bool BrlyQLocEqpMNConnection::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocEqpMNConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefConIxBrlyVLat", "lat", srefConIxBrlyVLat);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLocEqpMNConnection
 ******************************************************************************/

ListBrlyQLocEqpMNConnection::ListBrlyQLocEqpMNConnection() {
};

ListBrlyQLocEqpMNConnection::ListBrlyQLocEqpMNConnection(
			const ListBrlyQLocEqpMNConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocEqpMNConnection(*(src.nodes[i]));
};

ListBrlyQLocEqpMNConnection& ListBrlyQLocEqpMNConnection::operator=(
			const ListBrlyQLocEqpMNConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocEqpMNConnection(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocEqpMNConnection::~ListBrlyQLocEqpMNConnection() {
	clear();
};

void ListBrlyQLocEqpMNConnection::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocEqpMNConnection::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocEqpMNConnection* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocEqpMNConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocEqpMNConnection", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocEqpMNConnection(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocEqpMNConnection[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

