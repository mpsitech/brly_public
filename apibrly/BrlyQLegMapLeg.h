/**
  * \file BrlyQLegMapLeg.h
  * API code for table TblBrlyQLegMapLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGMAPLEG_H
#define BRLYQLEGMAPLEG_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegMapLeg
  */
class BrlyQLegMapLeg {

public:
	BrlyQLegMapLeg(const uint jnum = 0, const string stubMref = "", const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);

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
  * ListBrlyQLegMapLeg
  */
class ListBrlyQLegMapLeg {

public:
	ListBrlyQLegMapLeg();
	ListBrlyQLegMapLeg(const ListBrlyQLegMapLeg& src);
	ListBrlyQLegMapLeg& operator=(const ListBrlyQLegMapLeg& src);
	~ListBrlyQLegMapLeg();

	void clear();

public:
	vector<BrlyQLegMapLeg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

