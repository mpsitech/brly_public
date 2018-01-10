/**
  * \file BrlyQConMNSegment.h
  * API code for table TblBrlyQConMNSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMNSEGMENT_H
#define BRLYQCONMNSEGMENT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMNSegment
  */
class BrlyQConMNSegment {

public:
	BrlyQConMNSegment(const uint jnum = 0, const string stubMref = "", const string ftmX1Start = "", const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

public:
	uint jnum;
	string stubMref;
	string ftmX1Start;
	string ftmX1Stop;
	double x2Legphi0;
	double x2Legphi1;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQConMNSegment
  */
class ListBrlyQConMNSegment {

public:
	ListBrlyQConMNSegment();
	ListBrlyQConMNSegment(const ListBrlyQConMNSegment& src);
	ListBrlyQConMNSegment& operator=(const ListBrlyQConMNSegment& src);
	~ListBrlyQConMNSegment();

	void clear();

public:
	vector<BrlyQConMNSegment*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

