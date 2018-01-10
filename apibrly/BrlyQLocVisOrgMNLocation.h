/**
  * \file BrlyQLocVisOrgMNLocation.h
  * API code for table TblBrlyQLocVisOrgMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCVISORGMNLOCATION_H
#define BRLYQLOCVISORGMNLOCATION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocVisOrgMNLocation
  */
class BrlyQLocVisOrgMNLocation {

public:
	BrlyQLocVisOrgMNLocation(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocVisOrgMNLocation
  */
class ListBrlyQLocVisOrgMNLocation {

public:
	ListBrlyQLocVisOrgMNLocation();
	ListBrlyQLocVisOrgMNLocation(const ListBrlyQLocVisOrgMNLocation& src);
	ListBrlyQLocVisOrgMNLocation& operator=(const ListBrlyQLocVisOrgMNLocation& src);
	~ListBrlyQLocVisOrgMNLocation();

	void clear();

public:
	vector<BrlyQLocVisOrgMNLocation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

