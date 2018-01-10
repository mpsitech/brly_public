/**
  * \file BrlyQFltEqp1NNode.h
  * API code for table TblBrlyQFltEqp1NNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTEQP1NNODE_H
#define BRLYQFLTEQP1NNODE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltEqp1NNode
  */
class BrlyQFltEqp1NNode {

public:
	BrlyQFltEqp1NNode(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQFltEqp1NNode
  */
class ListBrlyQFltEqp1NNode {

public:
	ListBrlyQFltEqp1NNode();
	ListBrlyQFltEqp1NNode(const ListBrlyQFltEqp1NNode& src);
	ListBrlyQFltEqp1NNode& operator=(const ListBrlyQFltEqp1NNode& src);
	~ListBrlyQFltEqp1NNode();

	void clear();

public:
	vector<BrlyQFltEqp1NNode*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

