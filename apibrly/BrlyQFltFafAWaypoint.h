/**
  * \file BrlyQFltFafAWaypoint.h
  * API code for table TblBrlyQFltFafAWaypoint (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTFAFAWAYPOINT_H
#define BRLYQFLTFAFAWAYPOINT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltFafAWaypoint
  */
class BrlyQFltFafAWaypoint {

public:
	BrlyQFltFafAWaypoint(const uint jnum = 0, const string ftmTimestamp = "", const double latitude = 0.0, const double longitude = 0.0, const usmallint groundspeed = 0, const usmallint altitude = 0, const string altitudeStatus = "", const string updateType = "", const string altitudeChange = "");

public:
	uint jnum;
	string ftmTimestamp;
	double latitude;
	double longitude;
	usmallint groundspeed;
	usmallint altitude;
	string altitudeStatus;
	string updateType;
	string altitudeChange;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQFltFafAWaypoint
  */
class ListBrlyQFltFafAWaypoint {

public:
	ListBrlyQFltFafAWaypoint();
	ListBrlyQFltFafAWaypoint(const ListBrlyQFltFafAWaypoint& src);
	ListBrlyQFltFafAWaypoint& operator=(const ListBrlyQFltFafAWaypoint& src);
	~ListBrlyQFltFafAWaypoint();

	void clear();

public:
	vector<BrlyQFltFafAWaypoint*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

