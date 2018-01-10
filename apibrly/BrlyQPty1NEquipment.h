/**
  * \file BrlyQPty1NEquipment.h
  * API code for table TblBrlyQPty1NEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQPTY1NEQUIPMENT_H
#define BRLYQPTY1NEQUIPMENT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQPty1NEquipment
  */
class BrlyQPty1NEquipment {

public:
	BrlyQPty1NEquipment(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQPty1NEquipment
  */
class ListBrlyQPty1NEquipment {

public:
	ListBrlyQPty1NEquipment();
	ListBrlyQPty1NEquipment(const ListBrlyQPty1NEquipment& src);
	ListBrlyQPty1NEquipment& operator=(const ListBrlyQPty1NEquipment& src);
	~ListBrlyQPty1NEquipment();

	void clear();

public:
	vector<BrlyQPty1NEquipment*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

