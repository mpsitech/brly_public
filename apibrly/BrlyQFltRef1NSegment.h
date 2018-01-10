/**
  * \file BrlyQFltRef1NSegment.h
  * API code for table TblBrlyQFltRef1NSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTREF1NSEGMENT_H
#define BRLYQFLTREF1NSEGMENT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltRef1NSegment
  */
class BrlyQFltRef1NSegment {

public:
	BrlyQFltRef1NSegment(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQFltRef1NSegment
  */
class ListBrlyQFltRef1NSegment {

public:
	ListBrlyQFltRef1NSegment();
	ListBrlyQFltRef1NSegment(const ListBrlyQFltRef1NSegment& src);
	ListBrlyQFltRef1NSegment& operator=(const ListBrlyQFltRef1NSegment& src);
	~ListBrlyQFltRef1NSegment();

	void clear();

public:
	vector<BrlyQFltRef1NSegment*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

