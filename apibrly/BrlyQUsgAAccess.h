/**
  * \file BrlyQUsgAAccess.h
  * API code for table TblBrlyQUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSGAACCESS_H
#define BRLYQUSGAACCESS_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsgAAccess
  */
class BrlyQUsgAAccess {

public:
	BrlyQUsgAAccess(const uint jnum = 0, const string srefX1IxBrlyVCard = "", const string titX1IxBrlyVCard = "", const string srefsIxBrlyWUiaccess = "", const string titsIxBrlyWUiaccess = "");

public:
	uint jnum;
	string srefX1IxBrlyVCard;
	string titX1IxBrlyVCard;
	string srefsIxBrlyWUiaccess;
	string titsIxBrlyWUiaccess;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQUsgAAccess
  */
class ListBrlyQUsgAAccess {

public:
	ListBrlyQUsgAAccess();
	ListBrlyQUsgAAccess(const ListBrlyQUsgAAccess& src);
	ListBrlyQUsgAAccess& operator=(const ListBrlyQUsgAAccess& src);
	~ListBrlyQUsgAAccess();

	void clear();

public:
	vector<BrlyQUsgAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

