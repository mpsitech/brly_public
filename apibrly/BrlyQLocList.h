/**
  * \file BrlyQLocList.h
  * API code for table TblBrlyQLocList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCLIST_H
#define BRLYQLOCLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocList
  */
class BrlyQLocList {

public:
	BrlyQLocList(const uint jnum = 0, const string sref = "", const string srefICAO = "", const string Title = "", const string srefIxVBasetype = "", const string titIxVBasetype = "", const string stubRefBrlyMRegion = "", const string stubRefBrlyMEquipment = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0);

public:
	uint jnum;
	string sref;
	string srefICAO;
	string Title;
	string srefIxVBasetype;
	string titIxVBasetype;
	string stubRefBrlyMRegion;
	string stubRefBrlyMEquipment;
	double alt;
	double theta;
	double phi;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocList
  */
class ListBrlyQLocList {

public:
	ListBrlyQLocList();
	ListBrlyQLocList(const ListBrlyQLocList& src);
	ListBrlyQLocList& operator=(const ListBrlyQLocList& src);
	~ListBrlyQLocList();

	void clear();

public:
	vector<BrlyQLocList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

