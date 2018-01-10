/**
  * \file BrlyQLegList.cpp
  * API code for table TblBrlyQLegList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQLegList.h"

/******************************************************************************
 class BrlyQLegList
 ******************************************************************************/

BrlyQLegList::BrlyQLegList(
			const uint jnum
			, const string stubBgnRefBrlyMLocation
			, const string stubEndRefBrlyMLocation
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const double alt
		) {
	this->jnum = jnum;
	this->stubBgnRefBrlyMLocation = stubBgnRefBrlyMLocation;
	this->stubEndRefBrlyMLocation = stubEndRefBrlyMLocation;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->alt = alt;
};

bool BrlyQLegList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQLegList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubBgnRefBrlyMLocation", "blo", stubBgnRefBrlyMLocation);
		extractStringUclc(docctx, basexpath, "stubEndRefBrlyMLocation", "elo", stubEndRefBrlyMLocation);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractDoubleUclc(docctx, basexpath, "alt", "alt", alt);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQLegList
 ******************************************************************************/

ListBrlyQLegList::ListBrlyQLegList() {
};

ListBrlyQLegList::ListBrlyQLegList(
			const ListBrlyQLegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegList(*(src.nodes[i]));
};

ListBrlyQLegList& ListBrlyQLegList::operator=(
			const ListBrlyQLegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegList(*(src.nodes[i]));

	return *this;
};

ListBrlyQLegList::~ListBrlyQLegList() {
	clear();
};

void ListBrlyQLegList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQLegList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQLegList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQLegList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQLegList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQLegList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQLegList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

