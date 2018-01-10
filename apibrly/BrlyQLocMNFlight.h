/**
  * \file BrlyQLocMNFlight.h
  * API code for table TblBrlyQLocMNFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMNFLIGHT_H
#define BRLYQLOCMNFLIGHT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMNFlight
  */
class BrlyQLocMNFlight {

public:
	BrlyQLocMNFlight(const uint jnum = 0, const string stubMref = "", const string ftmX1VisStart = "", const string ftmX1VisStop = "", const string ftmXVisStart = "", const string ftmXVisStop = "");

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
  * ListBrlyQLocMNFlight
  */
class ListBrlyQLocMNFlight {

public:
	ListBrlyQLocMNFlight();
	ListBrlyQLocMNFlight(const ListBrlyQLocMNFlight& src);
	ListBrlyQLocMNFlight& operator=(const ListBrlyQLocMNFlight& src);
	~ListBrlyQLocMNFlight();

	void clear();

public:
	vector<BrlyQLocMNFlight*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

