/**
  * \file BrlyQTtb1NFlight.h
  * API code for table TblBrlyQTtb1NFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQTTB1NFLIGHT_H
#define BRLYQTTB1NFLIGHT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQTtb1NFlight
  */
class BrlyQTtb1NFlight {

public:
	BrlyQTtb1NFlight(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQTtb1NFlight
  */
class ListBrlyQTtb1NFlight {

public:
	ListBrlyQTtb1NFlight();
	ListBrlyQTtb1NFlight(const ListBrlyQTtb1NFlight& src);
	ListBrlyQTtb1NFlight& operator=(const ListBrlyQTtb1NFlight& src);
	~ListBrlyQTtb1NFlight();

	void clear();

public:
	vector<BrlyQTtb1NFlight*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

