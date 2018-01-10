/**
  * \file BrlyQUsgList.h
  * API code for table TblBrlyQUsgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSGLIST_H
#define BRLYQUSGLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsgList
  */
class BrlyQUsgList {

public:
	BrlyQUsgList(const uint jnum = 0, const string sref = "");

public:
	uint jnum;
	string sref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQUsgList
  */
class ListBrlyQUsgList {

public:
	ListBrlyQUsgList();
	ListBrlyQUsgList(const ListBrlyQUsgList& src);
	ListBrlyQUsgList& operator=(const ListBrlyQUsgList& src);
	~ListBrlyQUsgList();

	void clear();

public:
	vector<BrlyQUsgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

