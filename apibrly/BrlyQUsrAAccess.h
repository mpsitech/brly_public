/**
  * \file BrlyQUsrAAccess.h
  * API code for table TblBrlyQUsrAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSRAACCESS_H
#define BRLYQUSRAACCESS_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsrAAccess
  */
class BrlyQUsrAAccess {

public:
	BrlyQUsrAAccess(const uint jnum = 0, const string srefX1IxBrlyVCard = "", const string titX1IxBrlyVCard = "", const string srefsIxBrlyWUiaccess = "", const string titsIxBrlyWUiaccess = "");

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
  * ListBrlyQUsrAAccess
  */
class ListBrlyQUsrAAccess {

public:
	ListBrlyQUsrAAccess();
	ListBrlyQUsrAAccess(const ListBrlyQUsrAAccess& src);
	ListBrlyQUsrAAccess& operator=(const ListBrlyQUsrAAccess& src);
	~ListBrlyQUsrAAccess();

	void clear();

public:
	vector<BrlyQUsrAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

