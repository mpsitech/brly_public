/**
  * \file BrlyQLegList.h
  * API code for table TblBrlyQLegList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGLIST_H
#define BRLYQLEGLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegList
  */
class BrlyQLegList {

public:
	BrlyQLegList(const uint jnum = 0, const string stubBgnRefBrlyMLocation = "", const string stubEndRefBrlyMLocation = "", const string srefIxVBasetype = "", const string titIxVBasetype = "", const double alt = 0.0);

public:
	uint jnum;
	string stubBgnRefBrlyMLocation;
	string stubEndRefBrlyMLocation;
	string srefIxVBasetype;
	string titIxVBasetype;
	double alt;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLegList
  */
class ListBrlyQLegList {

public:
	ListBrlyQLegList();
	ListBrlyQLegList(const ListBrlyQLegList& src);
	ListBrlyQLegList& operator=(const ListBrlyQLegList& src);
	~ListBrlyQLegList();

	void clear();

public:
	vector<BrlyQLegList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

