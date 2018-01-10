/**
  * \file BrlyQLegCor1NConnection.cpp
  * API code for table TblBrlyQLegCor1NConnection (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLegCor1NConnection.h"

/******************************************************************************
 class BrlyQLegCor1NConnection
 ******************************************************************************/

BrlyQLegCor1NConnection::BrlyQLegCor1NConnection(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQLegCor1NConnection::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLegCor1NConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLegCor1NConnection
 ******************************************************************************/

ListBrlyQLegCor1NConnection::ListBrlyQLegCor1NConnection() {
};

ListBrlyQLegCor1NConnection::ListBrlyQLegCor1NConnection(
			const ListBrlyQLegCor1NConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegCor1NConnection(*(src.nodes[i]));
};

ListBrlyQLegCor1NConnection& ListBrlyQLegCor1NConnection::operator=(
			const ListBrlyQLegCor1NConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegCor1NConnection(*(src.nodes[i]));

	return *this;
};

ListBrlyQLegCor1NConnection::~ListBrlyQLegCor1NConnection() {
	clear();
};

void ListBrlyQLegCor1NConnection::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLegCor1NConnection::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLegCor1NConnection* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLegCor1NConnection");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLegCor1NConnection", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLegCor1NConnection(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLegCor1NConnection[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

