/**
  * \file BrlyQFltOrgMNFlight.h
  * API code for table TblBrlyQFltOrgMNFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTORGMNFLIGHT_H
#define BRLYQFLTORGMNFLIGHT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltOrgMNFlight
  */
class BrlyQFltOrgMNFlight {

public:
	BrlyQFltOrgMNFlight(const uint jnum = 0, const string stubMref = "", const string ftmX1VisStart = "", const string ftmX1VisStop = "", const string ftmXVisStart = "", const string ftmXVisStop = "");

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
  * ListBrlyQFltOrgMNFlight
  */
class ListBrlyQFltOrgMNFlight {

public:
	ListBrlyQFltOrgMNFlight();
	ListBrlyQFltOrgMNFlight(const ListBrlyQFltOrgMNFlight& src);
	ListBrlyQFltOrgMNFlight& operator=(const ListBrlyQFltOrgMNFlight& src);
	~ListBrlyQFltOrgMNFlight();

	void clear();

public:
	vector<BrlyQFltOrgMNFlight*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

