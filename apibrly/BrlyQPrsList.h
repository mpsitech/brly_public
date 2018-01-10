/**
  * \file BrlyQPrsList.h
  * API code for table TblBrlyQPrsList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQPRSLIST_H
#define BRLYQPRSLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQPrsList
  */
class BrlyQPrsList {

public:
	BrlyQPrsList(const uint jnum = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const string stubGrp = "", const string stubOwn = "", const string srefIxVSex = "", const string titIxVSex = "", const string telVal = "", const string emlVal = "");

public:
	uint jnum;
	string Title;
	string Firstname;
	string Lastname;
	string stubGrp;
	string stubOwn;
	string srefIxVSex;
	string titIxVSex;
	string telVal;
	string emlVal;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQPrsList
  */
class ListBrlyQPrsList {

public:
	ListBrlyQPrsList();
	ListBrlyQPrsList(const ListBrlyQPrsList& src);
	ListBrlyQPrsList& operator=(const ListBrlyQPrsList& src);
	~ListBrlyQPrsList();

	void clear();

public:
	vector<BrlyQPrsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

