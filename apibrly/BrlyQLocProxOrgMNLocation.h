/**
  * \file BrlyQLocProxOrgMNLocation.h
  * API code for table TblBrlyQLocProxOrgMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCPROXORGMNLOCATION_H
#define BRLYQLOCPROXORGMNLOCATION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocProxOrgMNLocation
  */
class BrlyQLocProxOrgMNLocation {

public:
	BrlyQLocProxOrgMNLocation(const uint jnum = 0, const string stubMref = "", const double deltaphi = 0.0);

public:
	uint jnum;
	string stubMref;
	double deltaphi;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocProxOrgMNLocation
  */
class ListBrlyQLocProxOrgMNLocation {

public:
	ListBrlyQLocProxOrgMNLocation();
	ListBrlyQLocProxOrgMNLocation(const ListBrlyQLocProxOrgMNLocation& src);
	ListBrlyQLocProxOrgMNLocation& operator=(const ListBrlyQLocProxOrgMNLocation& src);
	~ListBrlyQLocProxOrgMNLocation();

	void clear();

public:
	vector<BrlyQLocProxOrgMNLocation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

