/**
  * \file BrlyQConList.h
  * API code for table TblBrlyQConList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONLIST_H
#define BRLYQCONLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConList
  */
class BrlyQConList {

public:
	BrlyQConList(const uint jnum = 0, const string stubRefBrlyMFlight = "", const string stubCorRefBrlyMLeg = "", const string ftmStart = "", const string ftmStop = "", const string srefIxVModel = "", const string titIxVModel = "");

public:
	uint jnum;
	string stubRefBrlyMFlight;
	string stubCorRefBrlyMLeg;
	string ftmStart;
	string ftmStop;
	string srefIxVModel;
	string titIxVModel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQConList
  */
class ListBrlyQConList {

public:
	ListBrlyQConList();
	ListBrlyQConList(const ListBrlyQConList& src);
	ListBrlyQConList& operator=(const ListBrlyQConList& src);
	~ListBrlyQConList();

	void clear();

public:
	vector<BrlyQConList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

