/**
  * \file BrlyQConMNFlight.h
  * API code for table TblBrlyQConMNFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMNFLIGHT_H
#define BRLYQCONMNFLIGHT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMNFlight
  */
class BrlyQConMNFlight {

public:
	BrlyQConMNFlight(const uint jnum = 0, const string stubMref = "", const string ftmX1Start = "", const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

public:
	uint jnum;
	string stubMref;
	string ftmX1Start;
	string ftmX1Stop;
	double x2Legphi0;
	double x2Legphi1;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQConMNFlight
  */
class ListBrlyQConMNFlight {

public:
	ListBrlyQConMNFlight();
	ListBrlyQConMNFlight(const ListBrlyQConMNFlight& src);
	ListBrlyQConMNFlight& operator=(const ListBrlyQConMNFlight& src);
	~ListBrlyQConMNFlight();

	void clear();

public:
	vector<BrlyQConMNFlight*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

