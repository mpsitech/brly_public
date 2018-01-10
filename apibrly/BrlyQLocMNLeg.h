/**
  * \file BrlyQLocMNLeg.h
  * API code for table TblBrlyQLocMNLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMNLEG_H
#define BRLYQLOCMNLEG_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMNLeg
  */
class BrlyQLocMNLeg {

public:
	BrlyQLocMNLeg(const uint jnum = 0, const string stubMref = "", const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);

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
  * ListBrlyQLocMNLeg
  */
class ListBrlyQLocMNLeg {

public:
	ListBrlyQLocMNLeg();
	ListBrlyQLocMNLeg(const ListBrlyQLocMNLeg& src);
	ListBrlyQLocMNLeg& operator=(const ListBrlyQLocMNLeg& src);
	~ListBrlyQLocMNLeg();

	void clear();

public:
	vector<BrlyQLocMNLeg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

