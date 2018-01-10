/**
  * \file BrlyQLocMapLeg.h
  * API code for table TblBrlyQLocMapLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMAPLEG_H
#define BRLYQLOCMAPLEG_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMapLeg
  */
class BrlyQLocMapLeg {

public:
	BrlyQLocMapLeg(const uint jnum = 0, const string stubMref = "", const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0, const double lam1 = 0.0, const double lam2 = 0.0, const double lam3 = 0.0);

public:
	uint jnum;
	string stubMref;
	double dx;
	double dy;
	double x0;
	double y0;
	double lam1;
	double lam2;
	double lam3;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocMapLeg
  */
class ListBrlyQLocMapLeg {

public:
	ListBrlyQLocMapLeg();
	ListBrlyQLocMapLeg(const ListBrlyQLocMapLeg& src);
	ListBrlyQLocMapLeg& operator=(const ListBrlyQLocMapLeg& src);
	~ListBrlyQLocMapLeg();

	void clear();

public:
	vector<BrlyQLocMapLeg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

