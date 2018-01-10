/**
  * \file BrlyQOprList.h
  * API code for table TblBrlyQOprList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQOPRLIST_H
#define BRLYQOPRLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQOprList
  */
class BrlyQOprList {

public:
	BrlyQOprList(const uint jnum = 0, const string sref = "", const string srefICAO = "", const string Title = "");

public:
	uint jnum;
	string sref;
	string srefICAO;
	string Title;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQOprList
  */
class ListBrlyQOprList {

public:
	ListBrlyQOprList();
	ListBrlyQOprList(const ListBrlyQOprList& src);
	ListBrlyQOprList& operator=(const ListBrlyQOprList& src);
	~ListBrlyQOprList();

	void clear();

public:
	vector<BrlyQOprList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

