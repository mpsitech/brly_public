/**
  * \file BrlyQPrsADetail.h
  * API code for table TblBrlyQPrsADetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQPRSADETAIL_H
#define BRLYQPRSADETAIL_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQPrsADetail
  */
class BrlyQPrsADetail {

public:
	BrlyQPrsADetail(const uint jnum = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");

public:
	uint jnum;
	string x1SrefKType;
	string titX1SrefKType;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQPrsADetail
  */
class ListBrlyQPrsADetail {

public:
	ListBrlyQPrsADetail();
	ListBrlyQPrsADetail(const ListBrlyQPrsADetail& src);
	ListBrlyQPrsADetail& operator=(const ListBrlyQPrsADetail& src);
	~ListBrlyQPrsADetail();

	void clear();

public:
	vector<BrlyQPrsADetail*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

