/**
  * \file BrlyQCon1NRelay.h
  * API code for table TblBrlyQCon1NRelay (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCON1NRELAY_H
#define BRLYQCON1NRELAY_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQCon1NRelay
  */
class BrlyQCon1NRelay {

public:
	BrlyQCon1NRelay(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQCon1NRelay
  */
class ListBrlyQCon1NRelay {

public:
	ListBrlyQCon1NRelay();
	ListBrlyQCon1NRelay(const ListBrlyQCon1NRelay& src);
	ListBrlyQCon1NRelay& operator=(const ListBrlyQCon1NRelay& src);
	~ListBrlyQCon1NRelay();

	void clear();

public:
	vector<BrlyQCon1NRelay*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

