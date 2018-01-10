/**
  * \file BrlyQUsrList.h
  * API code for table TblBrlyQUsrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSRLIST_H
#define BRLYQUSRLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsrList
  */
class BrlyQUsrList {

public:
	BrlyQUsrList(const uint jnum = 0, const string stubRefBrlyMPerson = "", const string sref = "", const string stubRefBrlyMUsergroup = "", const string srefIxVState = "", const string titIxVState = "", const string srefIxBrlyVLocale = "", const string titIxBrlyVLocale = "", const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");

public:
	uint jnum;
	string stubRefBrlyMPerson;
	string sref;
	string stubRefBrlyMUsergroup;
	string srefIxVState;
	string titIxVState;
	string srefIxBrlyVLocale;
	string titIxBrlyVLocale;
	string srefIxBrlyVUserlevel;
	string titIxBrlyVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQUsrList
  */
class ListBrlyQUsrList {

public:
	ListBrlyQUsrList();
	ListBrlyQUsrList(const ListBrlyQUsrList& src);
	ListBrlyQUsrList& operator=(const ListBrlyQUsrList& src);
	~ListBrlyQUsrList();

	void clear();

public:
	vector<BrlyQUsrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

