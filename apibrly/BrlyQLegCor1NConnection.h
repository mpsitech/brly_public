/**
  * \file BrlyQLegCor1NConnection.h
  * API code for table TblBrlyQLegCor1NConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGCOR1NCONNECTION_H
#define BRLYQLEGCOR1NCONNECTION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegCor1NConnection
  */
class BrlyQLegCor1NConnection {

public:
	BrlyQLegCor1NConnection(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLegCor1NConnection
  */
class ListBrlyQLegCor1NConnection {

public:
	ListBrlyQLegCor1NConnection();
	ListBrlyQLegCor1NConnection(const ListBrlyQLegCor1NConnection& src);
	ListBrlyQLegCor1NConnection& operator=(const ListBrlyQLegCor1NConnection& src);
	~ListBrlyQLegCor1NConnection();

	void clear();

public:
	vector<BrlyQLegCor1NConnection*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

