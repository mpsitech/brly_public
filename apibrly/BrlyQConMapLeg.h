/**
  * \file BrlyQConMapLeg.h
  * API code for table TblBrlyQConMapLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMAPLEG_H
#define BRLYQCONMAPLEG_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMapLeg
  */
class BrlyQConMapLeg {

public:
	BrlyQConMapLeg(const uint jnum = 0, const string stubMref = "", const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);

public:
	uint jnum;
	string stubMref;
	double dx;
	double dy;
	double x0;
	double y0;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQConMapLeg
  */
class ListBrlyQConMapLeg {

public:
	ListBrlyQConMapLeg();
	ListBrlyQConMapLeg(const ListBrlyQConMapLeg& src);
	ListBrlyQConMapLeg& operator=(const ListBrlyQConMapLeg& src);
	~ListBrlyQConMapLeg();

	void clear();

public:
	vector<BrlyQConMapLeg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

