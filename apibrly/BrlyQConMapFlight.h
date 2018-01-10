/**
  * \file BrlyQConMapFlight.h
  * API code for table TblBrlyQConMapFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMAPFLIGHT_H
#define BRLYQCONMAPFLIGHT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMapFlight
  */
class BrlyQConMapFlight {

public:
	BrlyQConMapFlight(const uint jnum = 0, const string stubMref = "", const double x0 = 0.0, const double y0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const int dt = 0);

public:
	uint jnum;
	string stubMref;
	double x0;
	double y0;
	int t0;
	double dx;
	double dy;
	int dt;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQConMapFlight
  */
class ListBrlyQConMapFlight {

public:
	ListBrlyQConMapFlight();
	ListBrlyQConMapFlight(const ListBrlyQConMapFlight& src);
	ListBrlyQConMapFlight& operator=(const ListBrlyQConMapFlight& src);
	~ListBrlyQConMapFlight();

	void clear();

public:
	vector<BrlyQConMapFlight*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

