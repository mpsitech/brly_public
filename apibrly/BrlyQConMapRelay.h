/**
  * \file BrlyQConMapRelay.h
  * API code for table TblBrlyQConMapRelay (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMAPRELAY_H
#define BRLYQCONMAPRELAY_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMapRelay
  */
class BrlyQConMapRelay {

public:
	BrlyQConMapRelay(const uint jnum = 0, const uint x1Start = 0, const uint x1Stop = 0, const string srefIxVDir = "", const string yesnoConnected = "", const usmallint Nhop = 0);

public:
	uint jnum;
	uint x1Start;
	uint x1Stop;
	string srefIxVDir;
	string yesnoConnected;
	usmallint Nhop;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQConMapRelay
  */
class ListBrlyQConMapRelay {

public:
	ListBrlyQConMapRelay();
	ListBrlyQConMapRelay(const ListBrlyQConMapRelay& src);
	ListBrlyQConMapRelay& operator=(const ListBrlyQConMapRelay& src);
	~ListBrlyQConMapRelay();

	void clear();

public:
	vector<BrlyQConMapRelay*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

