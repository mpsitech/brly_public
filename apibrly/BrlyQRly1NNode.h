/**
  * \file BrlyQRly1NNode.h
  * API code for table TblBrlyQRly1NNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQRLY1NNODE_H
#define BRLYQRLY1NNODE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQRly1NNode
  */
class BrlyQRly1NNode {

public:
	BrlyQRly1NNode(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQRly1NNode
  */
class ListBrlyQRly1NNode {

public:
	ListBrlyQRly1NNode();
	ListBrlyQRly1NNode(const ListBrlyQRly1NNode& src);
	ListBrlyQRly1NNode& operator=(const ListBrlyQRly1NNode& src);
	~ListBrlyQRly1NNode();

	void clear();

public:
	vector<BrlyQRly1NNode*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

