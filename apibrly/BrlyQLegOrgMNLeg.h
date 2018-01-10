/**
  * \file BrlyQLegOrgMNLeg.h
  * API code for table TblBrlyQLegOrgMNLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGORGMNLEG_H
#define BRLYQLEGORGMNLEG_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegOrgMNLeg
  */
class BrlyQLegOrgMNLeg {

public:
	BrlyQLegOrgMNLeg(const uint jnum = 0, const string stubMref = "", const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);

public:
	uint jnum;
	string stubMref;
	double x1VisDstLegphi0;
	double x1VisDstLegphi1;
	double VisOrgLegphi0;
	double VisOrgLegphi1;
	double xVisDstLegphi0;
	double xVisDstLegphi1;
	double xVisOrgLegphi0;
	double xVisOrgLegphi1;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLegOrgMNLeg
  */
class ListBrlyQLegOrgMNLeg {

public:
	ListBrlyQLegOrgMNLeg();
	ListBrlyQLegOrgMNLeg(const ListBrlyQLegOrgMNLeg& src);
	ListBrlyQLegOrgMNLeg& operator=(const ListBrlyQLegOrgMNLeg& src);
	~ListBrlyQLegOrgMNLeg();

	void clear();

public:
	vector<BrlyQLegOrgMNLeg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

