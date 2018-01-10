/**
  * \file BrlyQFlt1NConnection.cpp
  * API code for table TblBrlyQFlt1NConnection (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQFlt1NConnection.h"

/******************************************************************************
 class BrlyQFlt1NConnection
 ******************************************************************************/

BrlyQFlt1NConnection::BrlyQFlt1NConnection(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQFlt1NConnection::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQFlt1NConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQFlt1NConnection
 ******************************************************************************/

ListBrlyQFlt1NConnection::ListBrlyQFlt1NConnection() {
};

ListBrlyQFlt1NConnection::ListBrlyQFlt1NConnection(
			const ListBrlyQFlt1NConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFlt1NConnection(*(src.nodes[i]));
};

ListBrlyQFlt1NConnection& ListBrlyQFlt1NConnection::operator=(
			const ListBrlyQFlt1NConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFlt1NConnection(*(src.nodes[i]));

	return *this;
};

ListBrlyQFlt1NConnection::~ListBrlyQFlt1NConnection() {
	clear();
};

void ListBrlyQFlt1NConnection::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQFlt1NConnection::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQFlt1NConnection* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQFlt1NConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQFlt1NConnection", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQFlt1NConnection(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQFlt1NConnection[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

