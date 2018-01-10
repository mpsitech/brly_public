/**
  * \file BrlyQOpr1NEquipment.h
  * API code for table TblBrlyQOpr1NEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQOPR1NEQUIPMENT_H
#define BRLYQOPR1NEQUIPMENT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQOpr1NEquipment
  */
class BrlyQOpr1NEquipment {

public:
	BrlyQOpr1NEquipment(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQOpr1NEquipment
  */
class ListBrlyQOpr1NEquipment {

public:
	ListBrlyQOpr1NEquipment();
	ListBrlyQOpr1NEquipment(const ListBrlyQOpr1NEquipment& src);
	ListBrlyQOpr1NEquipment& operator=(const ListBrlyQOpr1NEquipment& src);
	~ListBrlyQOpr1NEquipment();

	void clear();

public:
	vector<BrlyQOpr1NEquipment*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

