/**
  * \file BrlyQFltEqp1NNode.cpp
  * API code for table TblBrlyQFltEqp1NNode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQFltEqp1NNode.h"

/******************************************************************************
 class BrlyQFltEqp1NNode
 ******************************************************************************/

BrlyQFltEqp1NNode::BrlyQFltEqp1NNode(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQFltEqp1NNode::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQFltEqp1NNode");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQFltEqp1NNode
 ******************************************************************************/

ListBrlyQFltEqp1NNode::ListBrlyQFltEqp1NNode() {
};

ListBrlyQFltEqp1NNode::ListBrlyQFltEqp1NNode(
			const ListBrlyQFltEqp1NNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltEqp1NNode(*(src.nodes[i]));
};

ListBrlyQFltEqp1NNode& ListBrlyQFltEqp1NNode::operator=(
			const ListBrlyQFltEqp1NNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltEqp1NNode(*(src.nodes[i]));

	return *this;
};

ListBrlyQFltEqp1NNode::~ListBrlyQFltEqp1NNode() {
	clear();
};

void ListBrlyQFltEqp1NNode::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQFltEqp1NNode::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQFltEqp1NNode* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQFltEqp1NNode");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQFltEqp1NNode", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQFltEqp1NNode(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQFltEqp1NNode[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

