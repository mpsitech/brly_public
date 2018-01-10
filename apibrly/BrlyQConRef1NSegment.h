/**
  * \file BrlyQConRef1NSegment.h
  * API code for table TblBrlyQConRef1NSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONREF1NSEGMENT_H
#define BRLYQCONREF1NSEGMENT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConRef1NSegment
  */
class BrlyQConRef1NSegment {

public:
	BrlyQConRef1NSegment(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQConRef1NSegment
  */
class ListBrlyQConRef1NSegment {

public:
	ListBrlyQConRef1NSegment();
	ListBrlyQConRef1NSegment(const ListBrlyQConRef1NSegment& src);
	ListBrlyQConRef1NSegment& operator=(const ListBrlyQConRef1NSegment& src);
	~ListBrlyQConRef1NSegment();

	void clear();

public:
	vector<BrlyQConRef1NSegment*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

