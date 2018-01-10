/**
  * \file BrlyQFltMNLocation.h
  * API code for table TblBrlyQFltMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTMNLOCATION_H
#define BRLYQFLTMNLOCATION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltMNLocation
  */
class BrlyQFltMNLocation {

public:
	BrlyQFltMNLocation(const uint jnum = 0, const string stubMref = "", const string ftmX1VisStart = "", const string ftmX1VisStop = "", const string ftmXVisStart = "", const string ftmXVisStop = "");

public:
	uint jnum;
	string stubMref;
	string ftmX1VisStart;
	string ftmX1VisStop;
	string ftmXVisStart;
	string ftmXVisStop;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQFltMNLocation
  */
class ListBrlyQFltMNLocation {

public:
	ListBrlyQFltMNLocation();
	ListBrlyQFltMNLocation(const ListBrlyQFltMNLocation& src);
	ListBrlyQFltMNLocation& operator=(const ListBrlyQFltMNLocation& src);
	~ListBrlyQFltMNLocation();

	void clear();

public:
	vector<BrlyQFltMNLocation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

