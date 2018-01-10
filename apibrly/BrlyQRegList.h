/**
  * \file BrlyQRegList.h
  * API code for table TblBrlyQRegList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQREGLIST_H
#define BRLYQREGLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQRegList
  */
class BrlyQRegList {

public:
	BrlyQRegList(const uint jnum = 0, const string sref = "", const string Title = "", const string stubSupRefBrlyMRegion = "", const string srefIxVDst = "", const string titIxVDst = "", const double toffset = 0.0);

public:
	uint jnum;
	string sref;
	string Title;
	string stubSupRefBrlyMRegion;
	string srefIxVDst;
	string titIxVDst;
	double toffset;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQRegList
  */
class ListBrlyQRegList {

public:
	ListBrlyQRegList();
	ListBrlyQRegList(const ListBrlyQRegList& src);
	ListBrlyQRegList& operator=(const ListBrlyQRegList& src);
	~ListBrlyQRegList();

	void clear();

public:
	vector<BrlyQRegList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

