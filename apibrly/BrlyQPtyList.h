/**
  * \file BrlyQPtyList.h
  * API code for table TblBrlyQPtyList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQPTYLIST_H
#define BRLYQPTYLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQPtyList
  */
class BrlyQPtyList {

public:
	BrlyQPtyList(const uint jnum = 0, const string sref = "", const string Title = "", const string srefBrlyKEqptype = "", const string titSrefBrlyKEqptype = "", const usmallint Capacity = 0);

public:
	uint jnum;
	string sref;
	string Title;
	string srefBrlyKEqptype;
	string titSrefBrlyKEqptype;
	usmallint Capacity;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQPtyList
  */
class ListBrlyQPtyList {

public:
	ListBrlyQPtyList();
	ListBrlyQPtyList(const ListBrlyQPtyList& src);
	ListBrlyQPtyList& operator=(const ListBrlyQPtyList& src);
	~ListBrlyQPtyList();

	void clear();

public:
	vector<BrlyQPtyList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

