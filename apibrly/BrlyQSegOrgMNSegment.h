/**
  * \file BrlyQSegOrgMNSegment.h
  * API code for table TblBrlyQSegOrgMNSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQSEGORGMNSEGMENT_H
#define BRLYQSEGORGMNSEGMENT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQSegOrgMNSegment
  */
class BrlyQSegOrgMNSegment {

public:
	BrlyQSegOrgMNSegment(const uint jnum = 0, const string stubMref = "", const string ftmX1Start = "", const string ftmX1Stop = "", const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);

public:
	uint jnum;
	string stubMref;
	string ftmX1Start;
	string ftmX1Stop;
	double x2VisDstSegphi0;
	double x2VisDstSegphi1;
	double VisOrgSegphi0;
	double VisOrgSegphi1;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQSegOrgMNSegment
  */
class ListBrlyQSegOrgMNSegment {

public:
	ListBrlyQSegOrgMNSegment();
	ListBrlyQSegOrgMNSegment(const ListBrlyQSegOrgMNSegment& src);
	ListBrlyQSegOrgMNSegment& operator=(const ListBrlyQSegOrgMNSegment& src);
	~ListBrlyQSegOrgMNSegment();

	void clear();

public:
	vector<BrlyQSegOrgMNSegment*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

