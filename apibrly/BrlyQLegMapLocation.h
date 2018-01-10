/**
  * \file BrlyQLegMapLocation.h
  * API code for table TblBrlyQLegMapLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGMAPLOCATION_H
#define BRLYQLEGMAPLOCATION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegMapLocation
  */
class BrlyQLegMapLocation {

public:
	BrlyQLegMapLocation(const uint jnum = 0, const string stubMref = "", const double x = 0.0, const double y = 0.0);

public:
	uint jnum;
	string stubMref;
	double x;
	double y;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLegMapLocation
  */
class ListBrlyQLegMapLocation {

public:
	ListBrlyQLegMapLocation();
	ListBrlyQLegMapLocation(const ListBrlyQLegMapLocation& src);
	ListBrlyQLegMapLocation& operator=(const ListBrlyQLegMapLocation& src);
	~ListBrlyQLegMapLocation();

	void clear();

public:
	vector<BrlyQLegMapLocation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

