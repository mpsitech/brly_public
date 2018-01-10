/**
  * \file BrlyQLocMapProxLocation.h
  * API code for table TblBrlyQLocMapProxLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMAPPROXLOCATION_H
#define BRLYQLOCMAPPROXLOCATION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMapProxLocation
  */
class BrlyQLocMapProxLocation {

public:
	BrlyQLocMapProxLocation(const uint jnum = 0, const string stubMref = "", const double x = 0.0, const double y = 0.0);

public:
	uint jnum;
	string stubMref;
	double x;
	double y;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocMapProxLocation
  */
class ListBrlyQLocMapProxLocation {

public:
	ListBrlyQLocMapProxLocation();
	ListBrlyQLocMapProxLocation(const ListBrlyQLocMapProxLocation& src);
	ListBrlyQLocMapProxLocation& operator=(const ListBrlyQLocMapProxLocation& src);
	~ListBrlyQLocMapProxLocation();

	void clear();

public:
	vector<BrlyQLocMapProxLocation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

