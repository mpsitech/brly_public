/**
  * \file BrlyQRegSup1NRegion.h
  * API code for table TblBrlyQRegSup1NRegion (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQREGSUP1NREGION_H
#define BRLYQREGSUP1NREGION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQRegSup1NRegion
  */
class BrlyQRegSup1NRegion {

public:
	BrlyQRegSup1NRegion(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQRegSup1NRegion
  */
class ListBrlyQRegSup1NRegion {

public:
	ListBrlyQRegSup1NRegion();
	ListBrlyQRegSup1NRegion(const ListBrlyQRegSup1NRegion& src);
	ListBrlyQRegSup1NRegion& operator=(const ListBrlyQRegSup1NRegion& src);
	~ListBrlyQRegSup1NRegion();

	void clear();

public:
	vector<BrlyQRegSup1NRegion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

