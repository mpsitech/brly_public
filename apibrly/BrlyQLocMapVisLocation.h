/**
  * \file BrlyQLocMapVisLocation.h
  * API code for table TblBrlyQLocMapVisLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMAPVISLOCATION_H
#define BRLYQLOCMAPVISLOCATION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMapVisLocation
  */
class BrlyQLocMapVisLocation {

public:
	BrlyQLocMapVisLocation(const uint jnum = 0, const string stubMref = "", const double x = 0.0, const double y = 0.0);

public:
	uint jnum;
	string stubMref;
	double x;
	double y;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocMapVisLocation
  */
class ListBrlyQLocMapVisLocation {

public:
	ListBrlyQLocMapVisLocation();
	ListBrlyQLocMapVisLocation(const ListBrlyQLocMapVisLocation& src);
	ListBrlyQLocMapVisLocation& operator=(const ListBrlyQLocMapVisLocation& src);
	~ListBrlyQLocMapVisLocation();

	void clear();

public:
	vector<BrlyQLocMapVisLocation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

