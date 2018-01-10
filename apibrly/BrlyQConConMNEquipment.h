/**
  * \file BrlyQConConMNEquipment.h
  * API code for table TblBrlyQConConMNEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONCONMNEQUIPMENT_H
#define BRLYQCONCONMNEQUIPMENT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConConMNEquipment
  */
class BrlyQConConMNEquipment {

public:
	BrlyQConConMNEquipment(const uint jnum = 0, const string stubMref = "", const string srefConIxBrlyVLat = "");

public:
	uint jnum;
	string stubMref;
	string srefConIxBrlyVLat;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQConConMNEquipment
  */
class ListBrlyQConConMNEquipment {

public:
	ListBrlyQConConMNEquipment();
	ListBrlyQConConMNEquipment(const ListBrlyQConConMNEquipment& src);
	ListBrlyQConConMNEquipment& operator=(const ListBrlyQConConMNEquipment& src);
	~ListBrlyQConConMNEquipment();

	void clear();

public:
	vector<BrlyQConConMNEquipment*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

