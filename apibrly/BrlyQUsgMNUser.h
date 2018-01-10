/**
  * \file BrlyQUsgMNUser.h
  * API code for table TblBrlyQUsgMNUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSGMNUSER_H
#define BRLYQUSGMNUSER_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsgMNUser
  */
class BrlyQUsgMNUser {

public:
	BrlyQUsgMNUser(const uint jnum = 0, const string stubMref = "", const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");

public:
	uint jnum;
	string stubMref;
	string srefIxBrlyVUserlevel;
	string titIxBrlyVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQUsgMNUser
  */
class ListBrlyQUsgMNUser {

public:
	ListBrlyQUsgMNUser();
	ListBrlyQUsgMNUser(const ListBrlyQUsgMNUser& src);
	ListBrlyQUsgMNUser& operator=(const ListBrlyQUsgMNUser& src);
	~ListBrlyQUsgMNUser();

	void clear();

public:
	vector<BrlyQUsgMNUser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

