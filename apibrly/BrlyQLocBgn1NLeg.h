/**
  * \file BrlyQLocBgn1NLeg.h
  * API code for table TblBrlyQLocBgn1NLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCBGN1NLEG_H
#define BRLYQLOCBGN1NLEG_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocBgn1NLeg
  */
class BrlyQLocBgn1NLeg {

public:
	BrlyQLocBgn1NLeg(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocBgn1NLeg
  */
class ListBrlyQLocBgn1NLeg {

public:
	ListBrlyQLocBgn1NLeg();
	ListBrlyQLocBgn1NLeg(const ListBrlyQLocBgn1NLeg& src);
	ListBrlyQLocBgn1NLeg& operator=(const ListBrlyQLocBgn1NLeg& src);
	~ListBrlyQLocBgn1NLeg();

	void clear();

public:
	vector<BrlyQLocBgn1NLeg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

