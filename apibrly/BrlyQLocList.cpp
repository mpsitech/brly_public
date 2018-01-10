/**
  * \file BrlyQLocList.cpp
  * API code for table TblBrlyQLocList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLocList.h"

/******************************************************************************
 class BrlyQLocList
 ******************************************************************************/

BrlyQLocList::BrlyQLocList(
			const uint jnum
			, const string sref
			, const string srefICAO
			, const string Title
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefBrlyMRegion
			, const string stubRefBrlyMEquipment
			, const double alt
			, const double theta
			, const double phi
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefICAO = srefICAO;
	this->Title = Title;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubRefBrlyMRegion = stubRefBrlyMRegion;
	this->stubRefBrlyMEquipment = stubRefBrlyMEquipment;
	this->alt = alt;
	this->theta = theta;
	this->phi = phi;
};

bool BrlyQLocList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLocList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefICAO", "ica", srefICAO);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefBrlyMRegion", "reg", stubRefBrlyMRegion);
		extractStringUclc(docctx, basexpath, "stubRefBrlyMEquipment", "eqp", stubRefBrlyMEquipment);
		extractDoubleUclc(docctx, basexpath, "alt", "alt", alt);
		extractDoubleUclc(docctx, basexpath, "theta", "the", theta);
		extractDoubleUclc(docctx, basexpath, "phi", "phi", phi);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLocList
 ******************************************************************************/

ListBrlyQLocList::ListBrlyQLocList() {
};

ListBrlyQLocList::ListBrlyQLocList(
			const ListBrlyQLocList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocList(*(src.nodes[i]));
};

ListBrlyQLocList& ListBrlyQLocList::operator=(
			const ListBrlyQLocList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocList(*(src.nodes[i]));

	return *this;
};

ListBrlyQLocList::~ListBrlyQLocList() {
	clear();
};

void ListBrlyQLocList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLocList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLocList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLocList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLocList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLocList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLocList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

