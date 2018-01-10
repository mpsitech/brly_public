/**
  * \file BrlyQLocEnd1NLeg.h
  * API code for table TblBrlyQLocEnd1NLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCEND1NLEG_H
#define BRLYQLOCEND1NLEG_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocEnd1NLeg
  */
class BrlyQLocEnd1NLeg {

public:
	BrlyQLocEnd1NLeg(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocEnd1NLeg
  */
class ListBrlyQLocEnd1NLeg {

public:
	ListBrlyQLocEnd1NLeg();
	ListBrlyQLocEnd1NLeg(const ListBrlyQLocEnd1NLeg& src);
	ListBrlyQLocEnd1NLeg& operator=(const ListBrlyQLocEnd1NLeg& src);
	~ListBrlyQLocEnd1NLeg();

	void clear();

public:
	vector<BrlyQLocEnd1NLeg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

