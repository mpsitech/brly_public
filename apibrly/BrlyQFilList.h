/**
  * \file BrlyQFilList.h
  * API code for table TblBrlyQFilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFILLIST_H
#define BRLYQFILLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFilList
  */
class BrlyQFilList {

public:
	BrlyQFilList(const uint jnum = 0, const string Filename = "", const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);

public:
	uint jnum;
	string Filename;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	string stubRefUref;
	string osrefKContent;
	string titOsrefKContent;
	string srefKMimetype;
	string titSrefKMimetype;
	usmallint Size;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQFilList
  */
class ListBrlyQFilList {

public:
	ListBrlyQFilList();
	ListBrlyQFilList(const ListBrlyQFilList& src);
	ListBrlyQFilList& operator=(const ListBrlyQFilList& src);
	~ListBrlyQFilList();

	void clear();

public:
	vector<BrlyQFilList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

