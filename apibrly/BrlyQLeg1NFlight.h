/**
  * \file BrlyQLeg1NFlight.h
  * API code for table TblBrlyQLeg1NFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEG1NFLIGHT_H
#define BRLYQLEG1NFLIGHT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLeg1NFlight
  */
class BrlyQLeg1NFlight {

public:
	BrlyQLeg1NFlight(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLeg1NFlight
  */
class ListBrlyQLeg1NFlight {

public:
	ListBrlyQLeg1NFlight();
	ListBrlyQLeg1NFlight(const ListBrlyQLeg1NFlight& src);
	ListBrlyQLeg1NFlight& operator=(const ListBrlyQLeg1NFlight& src);
	~ListBrlyQLeg1NFlight();

	void clear();

public:
	vector<BrlyQLeg1NFlight*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

