/**
  * \file BrlyQUsrMNUsergroup.h
  * API code for table TblBrlyQUsrMNUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSRMNUSERGROUP_H
#define BRLYQUSRMNUSERGROUP_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsrMNUsergroup
  */
class BrlyQUsrMNUsergroup {

public:
	BrlyQUsrMNUsergroup(const uint jnum = 0, const string stubMref = "", const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");

public:
	uint jnum;
	string stubMref;
	string srefIxBrlyVUserlevel;
	string titIxBrlyVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQUsrMNUsergroup
  */
class ListBrlyQUsrMNUsergroup {

public:
	ListBrlyQUsrMNUsergroup();
	ListBrlyQUsrMNUsergroup(const ListBrlyQUsrMNUsergroup& src);
	ListBrlyQUsrMNUsergroup& operator=(const ListBrlyQUsrMNUsergroup& src);
	~ListBrlyQUsrMNUsergroup();

	void clear();

public:
	vector<BrlyQUsrMNUsergroup*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

