/**
  * \file BrlyQLegMNLocation.h
  * API code for table TblBrlyQLegMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGMNLOCATION_H
#define BRLYQLEGMNLOCATION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegMNLocation
  */
class BrlyQLegMNLocation {

public:
	BrlyQLegMNLocation(const uint jnum = 0, const string stubMref = "", const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);

public:
	uint jnum;
	string stubMref;
	double x1VisLegphi0;
	double x1VisLegphi1;
	double legphi;
	double legtheta;
	double xVisLegphi0;
	double xVisLegphi1;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLegMNLocation
  */
class ListBrlyQLegMNLocation {

public:
	ListBrlyQLegMNLocation();
	ListBrlyQLegMNLocation(const ListBrlyQLegMNLocation& src);
	ListBrlyQLegMNLocation& operator=(const ListBrlyQLegMNLocation& src);
	~ListBrlyQLegMNLocation();

	void clear();

public:
	vector<BrlyQLegMNLocation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

