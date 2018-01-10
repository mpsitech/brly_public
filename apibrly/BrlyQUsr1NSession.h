/**
  * \file BrlyQUsr1NSession.h
  * API code for table TblBrlyQUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSR1NSESSION_H
#define BRLYQUSR1NSESSION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsr1NSession
  */
class BrlyQUsr1NSession {

public:
	BrlyQUsr1NSession(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQUsr1NSession
  */
class ListBrlyQUsr1NSession {

public:
	ListBrlyQUsr1NSession();
	ListBrlyQUsr1NSession(const ListBrlyQUsr1NSession& src);
	ListBrlyQUsr1NSession& operator=(const ListBrlyQUsr1NSession& src);
	~ListBrlyQUsr1NSession();

	void clear();

public:
	vector<BrlyQUsr1NSession*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

