/**
  * \file BrlyQConMapNode.h
  * API code for table TblBrlyQConMapNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMAPNODE_H
#define BRLYQCONMAPNODE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMapNode
  */
class BrlyQConMapNode {

public:
	BrlyQConMapNode(const uint jnum = 0, const string stubRef = "", const int jnumRly = 0, const double x0 = 0.0, const double y0 = 0.0, const double u0 = 0.0, const double v0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const double du = 0.0, const double dv = 0.0, const int dt = 0);

public:
	uint jnum;
	string stubRef;
	int jnumRly;
	double x0;
	double y0;
	double u0;
	double v0;
	int t0;
	double dx;
	double dy;
	double du;
	double dv;
	int dt;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQConMapNode
  */
class ListBrlyQConMapNode {

public:
	ListBrlyQConMapNode();
	ListBrlyQConMapNode(const ListBrlyQConMapNode& src);
	ListBrlyQConMapNode& operator=(const ListBrlyQConMapNode& src);
	~ListBrlyQConMapNode();

	void clear();

public:
	vector<BrlyQConMapNode*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

