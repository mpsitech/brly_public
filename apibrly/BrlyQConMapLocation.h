/**
  * \file BrlyQConMapLocation.h
  * API code for table TblBrlyQConMapLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMAPLOCATION_H
#define BRLYQCONMAPLOCATION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMapLocation
  */
class BrlyQConMapLocation {

public:
	BrlyQConMapLocation(const uint jnum = 0, const string stubMref = "", const double x = 0.0, const double y = 0.0);

public:
	uint jnum;
	string stubMref;
	double x;
	double y;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQConMapLocation
  */
class ListBrlyQConMapLocation {

public:
	ListBrlyQConMapLocation();
	ListBrlyQConMapLocation(const ListBrlyQConMapLocation& src);
	ListBrlyQConMapLocation& operator=(const ListBrlyQConMapLocation& src);
	~ListBrlyQConMapLocation();

	void clear();

public:
	vector<BrlyQConMapLocation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

