/**
  * \file BrlyQFltFafAWaypoint.cpp
  * API code for table TblBrlyQFltFafAWaypoint (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQFltFafAWaypoint.h"

/******************************************************************************
 class BrlyQFltFafAWaypoint
 ******************************************************************************/

BrlyQFltFafAWaypoint::BrlyQFltFafAWaypoint(
			const uint jnum
			, const string ftmTimestamp
			, const double latitude
			, const double longitude
			, const usmallint groundspeed
			, const usmallint altitude
			, const string altitudeStatus
			, const string updateType
			, const string altitudeChange
		) {
	this->jnum = jnum;
	this->ftmTimestamp = ftmTimestamp;
	this->latitude = latitude;
	this->longitude = longitude;
	this->groundspeed = groundspeed;
	this->altitude = altitude;
	this->altitudeStatus = altitudeStatus;
	this->updateType = updateType;
	this->altitudeChange = altitudeChange;
};

bool BrlyQFltFafAWaypoint::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQFltFafAWaypoint");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "ftmTimestamp", "tms", ftmTimestamp);
		extractDoubleUclc(docctx, basexpath, "latitude", "lat", latitude);
		extractDoubleUclc(docctx, basexpath, "longitude", "lon", longitude);
		extractUsmallintUclc(docctx, basexpath, "groundspeed", "gsp", groundspeed);
		extractUsmallintUclc(docctx, basexpath, "altitude", "alt", altitude);
		extractStringUclc(docctx, basexpath, "altitudeStatus", "ast", altitudeStatus);
		extractStringUclc(docctx, basexpath, "updateType", "uty", updateType);
		extractStringUclc(docctx, basexpath, "altitudeChange", "ach", altitudeChange);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQFltFafAWaypoint
 ******************************************************************************/

ListBrlyQFltFafAWaypoint::ListBrlyQFltFafAWaypoint() {
};

ListBrlyQFltFafAWaypoint::ListBrlyQFltFafAWaypoint(
			const ListBrlyQFltFafAWaypoint& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltFafAWaypoint(*(src.nodes[i]));
};

ListBrlyQFltFafAWaypoint& ListBrlyQFltFafAWaypoint::operator=(
			const ListBrlyQFltFafAWaypoint& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltFafAWaypoint(*(src.nodes[i]));

	return *this;
};

ListBrlyQFltFafAWaypoint::~ListBrlyQFltFafAWaypoint() {
	clear();
};

void ListBrlyQFltFafAWaypoint::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQFltFafAWaypoint::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQFltFafAWaypoint* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQFltFafAWaypoint");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQFltFafAWaypoint", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQFltFafAWaypoint(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQFltFafAWaypoint[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

