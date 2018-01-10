/**
  * \file BrlyQConMapNode.cpp
  * API code for table TblBrlyQConMapNode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQConMapNode.h"

/******************************************************************************
 class BrlyQConMapNode
 ******************************************************************************/

BrlyQConMapNode::BrlyQConMapNode(
			const uint jnum
			, const string stubRef
			, const int jnumRly
			, const double x0
			, const double y0
			, const double u0
			, const double v0
			, const int t0
			, const double dx
			, const double dy
			, const double du
			, const double dv
			, const int dt
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
	this->jnumRly = jnumRly;
	this->x0 = x0;
	this->y0 = y0;
	this->u0 = u0;
	this->v0 = v0;
	this->t0 = t0;
	this->dx = dx;
	this->dy = dy;
	this->du = du;
	this->dv = dv;
	this->dt = dt;
};

bool BrlyQConMapNode::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQConMapNode");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
		extractIntUclc(docctx, basexpath, "jnumRly", "jnr", jnumRly);
		extractDoubleUclc(docctx, basexpath, "x0", "x0", x0);
		extractDoubleUclc(docctx, basexpath, "y0", "y0", y0);
		extractDoubleUclc(docctx, basexpath, "u0", "u0", u0);
		extractDoubleUclc(docctx, basexpath, "v0", "v0", v0);
		extractIntUclc(docctx, basexpath, "t0", "t0", t0);
		extractDoubleUclc(docctx, basexpath, "dx", "dx", dx);
		extractDoubleUclc(docctx, basexpath, "dy", "dy", dy);
		extractDoubleUclc(docctx, basexpath, "du", "du", du);
		extractDoubleUclc(docctx, basexpath, "dv", "dv", dv);
		extractIntUclc(docctx, basexpath, "dt", "dt", dt);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQConMapNode
 ******************************************************************************/

ListBrlyQConMapNode::ListBrlyQConMapNode() {
};

ListBrlyQConMapNode::ListBrlyQConMapNode(
			const ListBrlyQConMapNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapNode(*(src.nodes[i]));
};

ListBrlyQConMapNode& ListBrlyQConMapNode::operator=(
			const ListBrlyQConMapNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapNode(*(src.nodes[i]));

	return *this;
};

ListBrlyQConMapNode::~ListBrlyQConMapNode() {
	clear();
};

void ListBrlyQConMapNode::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQConMapNode::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQConMapNode* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQConMapNode");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQConMapNode", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQConMapNode(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQConMapNode[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

