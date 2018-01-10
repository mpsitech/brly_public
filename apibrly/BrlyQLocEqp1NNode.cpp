/**
  * \file BrlyQLocEqp1NNode.cpp
  * API code for table TblBrlyQLocEqp1NNode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocEqp1NNode.h"

/******************************************************************************
 class BrlyQLocEqp1NNode
 ******************************************************************************/

BrlyQLocEqp1NNode::BrlyQLocEqp1NNode(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool BrlyQLocEqp1NNode::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocEqp1NNode");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLocEqp1NNode
 ******************************************************************************/

ListBrlyQLocEqp1NNode::ListBrlyQLocEqp1NNode() {
};

ListBrlyQLocEqp1NNode::ListBrlyQLocEqp1NNode(
			const ListBrlyQLocEqp1NNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocEqp1NNode(*(src.nodes[i]));
};

ListBrlyQLocEqp1NNode& ListBrlyQLocEqp1NNode::operator=(
			const ListBrlyQLocEqp1NNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocEqp1NNode(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocEqp1NNode::~ListBrlyQLocEqp1NNode() {
	clear();
};

void ListBrlyQLocEqp1NNode::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocEqp1NNode::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocEqp1NNode* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocEqp1NNode");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocEqp1NNode", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocEqp1NNode(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocEqp1NNode[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

