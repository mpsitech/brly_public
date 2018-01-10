/**
  * \file BrlyQLocMNSegment.h
  * API code for table TblBrlyQLocMNSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMNSEGMENT_H
#define BRLYQLOCMNSEGMENT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMNSegment
  */
class BrlyQLocMNSegment {

public:
	BrlyQLocMNSegment(const uint jnum = 0, const string stubMref = "", const string ftmX1Start = "", const string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);

public:
	uint jnum;
	string stubMref;
	string ftmX1Start;
	string ftmX1Stop;
	double x2VisSegphi0;
	double x2VisSegphi1;
	double segphi;
	double segtheta;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocMNSegment
  */
class ListBrlyQLocMNSegment {

public:
	ListBrlyQLocMNSegment();
	ListBrlyQLocMNSegment(const ListBrlyQLocMNSegment& src);
	ListBrlyQLocMNSegment& operator=(const ListBrlyQLocMNSegment& src);
	~ListBrlyQLocMNSegment();

	void clear();

public:
	vector<BrlyQLocMNSegment*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

