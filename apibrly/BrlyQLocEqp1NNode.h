/**
  * \file BrlyQLocEqp1NNode.h
  * API code for table TblBrlyQLocEqp1NNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCEQP1NNODE_H
#define BRLYQLOCEQP1NNODE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocEqp1NNode
  */
class BrlyQLocEqp1NNode {

public:
	BrlyQLocEqp1NNode(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocEqp1NNode
  */
class ListBrlyQLocEqp1NNode {

public:
	ListBrlyQLocEqp1NNode();
	ListBrlyQLocEqp1NNode(const ListBrlyQLocEqp1NNode& src);
	ListBrlyQLocEqp1NNode& operator=(const ListBrlyQLocEqp1NNode& src);
	~ListBrlyQLocEqp1NNode();

	void clear();

public:
	vector<BrlyQLocEqp1NNode*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

