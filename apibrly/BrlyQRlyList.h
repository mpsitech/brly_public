/**
  * \file BrlyQRlyList.h
  * API code for table TblBrlyQRlyList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQRLYLIST_H
#define BRLYQRLYLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQRlyList
  */
class BrlyQRlyList {

public:
	BrlyQRlyList(const uint jnum = 0, const string ftmX1Start = "", const string ftmX1Stop = "", const string stubRefBrlyMConnection = "", const string srefIxVDir = "", const string titIxVDir = "", const string yesnoConnected = "");

public:
	uint jnum;
	string ftmX1Start;
	string ftmX1Stop;
	string stubRefBrlyMConnection;
	string srefIxVDir;
	string titIxVDir;
	string yesnoConnected;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQRlyList
  */
class ListBrlyQRlyList {

public:
	ListBrlyQRlyList();
	ListBrlyQRlyList(const ListBrlyQRlyList& src);
	ListBrlyQRlyList& operator=(const ListBrlyQRlyList& src);
	~ListBrlyQRlyList();

	void clear();

public:
	vector<BrlyQRlyList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

