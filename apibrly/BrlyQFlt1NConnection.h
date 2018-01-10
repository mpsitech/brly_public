/**
  * \file BrlyQFlt1NConnection.h
  * API code for table TblBrlyQFlt1NConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLT1NCONNECTION_H
#define BRLYQFLT1NCONNECTION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFlt1NConnection
  */
class BrlyQFlt1NConnection {

public:
	BrlyQFlt1NConnection(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQFlt1NConnection
  */
class ListBrlyQFlt1NConnection {

public:
	ListBrlyQFlt1NConnection();
	ListBrlyQFlt1NConnection(const ListBrlyQFlt1NConnection& src);
	ListBrlyQFlt1NConnection& operator=(const ListBrlyQFlt1NConnection& src);
	~ListBrlyQFlt1NConnection();

	void clear();

public:
	vector<BrlyQFlt1NConnection*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

