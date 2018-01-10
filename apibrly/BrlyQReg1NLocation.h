/**
  * \file BrlyQReg1NLocation.h
  * API code for table TblBrlyQReg1NLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQREG1NLOCATION_H
#define BRLYQREG1NLOCATION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQReg1NLocation
  */
class BrlyQReg1NLocation {

public:
	BrlyQReg1NLocation(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQReg1NLocation
  */
class ListBrlyQReg1NLocation {

public:
	ListBrlyQReg1NLocation();
	ListBrlyQReg1NLocation(const ListBrlyQReg1NLocation& src);
	ListBrlyQReg1NLocation& operator=(const ListBrlyQReg1NLocation& src);
	~ListBrlyQReg1NLocation();

	void clear();

public:
	vector<BrlyQReg1NLocation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

