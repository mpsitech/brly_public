/**
  * \file BrlyQTtbList.h
  * API code for table TblBrlyQTtbList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQTTBLIST_H
#define BRLYQTTBLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQTtbList
  */
class BrlyQTtbList {

public:
	BrlyQTtbList(const uint jnum = 0, const string Title = "", const string stubRefBrlyMFile = "", const string srefBrlyKAlliance = "", const string titSrefBrlyKAlliance = "", const string ftmStartd = "", const string ftmStopd = "");

public:
	uint jnum;
	string Title;
	string stubRefBrlyMFile;
	string srefBrlyKAlliance;
	string titSrefBrlyKAlliance;
	string ftmStartd;
	string ftmStopd;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQTtbList
  */
class ListBrlyQTtbList {

public:
	ListBrlyQTtbList();
	ListBrlyQTtbList(const ListBrlyQTtbList& src);
	ListBrlyQTtbList& operator=(const ListBrlyQTtbList& src);
	~ListBrlyQTtbList();

	void clear();

public:
	vector<BrlyQTtbList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

