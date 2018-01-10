/**
  * \file BrlyQRly1NNode.cpp
  * API code for table TblBrlyQRly1NNode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQRly1NNode.h"

/******************************************************************************
 class BrlyQRly1NNode
 ******************************************************************************/

BrlyQRly1NNode::BrlyQRly1NNode(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQRly1NNode::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQRly1NNode");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQRly1NNode
 ******************************************************************************/

ListBrlyQRly1NNode::ListBrlyQRly1NNode() {
};

ListBrlyQRly1NNode::ListBrlyQRly1NNode(
			const ListBrlyQRly1NNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRly1NNode(*(src.nodes[i]));
};

ListBrlyQRly1NNode& ListBrlyQRly1NNode::operator=(
			const ListBrlyQRly1NNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRly1NNode(*(src.nodes[i]));

	return *this;
};

ListBrlyQRly1NNode::~ListBrlyQRly1NNode() {
	clear();
};

void ListBrlyQRly1NNode::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQRly1NNode::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQRly1NNode* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQRly1NNode");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQRly1NNode", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQRly1NNode(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQRly1NNode[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

