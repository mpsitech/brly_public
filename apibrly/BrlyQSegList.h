/**
  * \file BrlyQSegList.h
  * API code for table TblBrlyQSegList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQSEGLIST_H
#define BRLYQSEGLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQSegList
  */
class BrlyQSegList {

public:
	BrlyQSegList(const uint jnum = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const string stubRefUref = "", const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const string ftmStart = "", const string ftmStop = "");

public:
	uint jnum;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	string stubRefUref;
	double alt0;
	double alt1;
	double theta0;
	double theta1;
	double phi0;
	double phi1;
	string ftmStart;
	string ftmStop;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQSegList
  */
class ListBrlyQSegList {

public:
	ListBrlyQSegList();
	ListBrlyQSegList(const ListBrlyQSegList& src);
	ListBrlyQSegList& operator=(const ListBrlyQSegList& src);
	~ListBrlyQSegList();

	void clear();

public:
	vector<BrlyQSegList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

