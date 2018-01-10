/**
  * \file BrlyQRegADstswitch.h
  * API code for table TblBrlyQRegADstswitch (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQREGADSTSWITCH_H
#define BRLYQREGADSTSWITCH_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQRegADstswitch
  */
class BrlyQRegADstswitch {

public:
	BrlyQRegADstswitch(const uint jnum = 0, const string ftmStartd = "", const string ftmStartt = "");

public:
	uint jnum;
	string ftmStartd;
	string ftmStartt;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQRegADstswitch
  */
class ListBrlyQRegADstswitch {

public:
	ListBrlyQRegADstswitch();
	ListBrlyQRegADstswitch(const ListBrlyQRegADstswitch& src);
	ListBrlyQRegADstswitch& operator=(const ListBrlyQRegADstswitch& src);
	~ListBrlyQRegADstswitch();

	void clear();

public:
	vector<BrlyQRegADstswitch*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

