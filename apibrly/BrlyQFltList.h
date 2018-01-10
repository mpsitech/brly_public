/**
  * \file BrlyQFltList.h
  * API code for table TblBrlyQFltList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTLIST_H
#define BRLYQFLTLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltList
  */
class BrlyQFltList {

public:
	BrlyQFltList(const uint jnum = 0, const string sref = "", const string stubRefBrlyMEquipment = "", const string stubRefBrlyMLeg = "", const string ftmStart = "", const string ftmStop = "");

public:
	uint jnum;
	string sref;
	string stubRefBrlyMEquipment;
	string stubRefBrlyMLeg;
	string ftmStart;
	string ftmStop;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQFltList
  */
class ListBrlyQFltList {

public:
	ListBrlyQFltList();
	ListBrlyQFltList(const ListBrlyQFltList& src);
	ListBrlyQFltList& operator=(const ListBrlyQFltList& src);
	~ListBrlyQFltList();

	void clear();

public:
	vector<BrlyQFltList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

