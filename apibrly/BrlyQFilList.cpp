/**
  * \file BrlyQFilList.cpp
  * API code for table TblBrlyQFilList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQFilList.h"

/******************************************************************************
 class BrlyQFilList
 ******************************************************************************/

BrlyQFilList::BrlyQFilList(
			const uint jnum
			, const string Filename
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const usmallint Size
		) {
	this->jnum = jnum;
	this->Filename = Filename;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
	this->osrefKContent = osrefKContent;
	this->titOsrefKContent = titOsrefKContent;
	this->srefKMimetype = srefKMimetype;
	this->titSrefKMimetype = titSrefKMimetype;
	this->Size = Size;
};

bool BrlyQFilList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQFilList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent);
		extractStringUclc(docctx, basexpath, "titOsrefKContent", "cnt2", titOsrefKContent);
		extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype);
		extractStringUclc(docctx, basexpath, "titSrefKMimetype", "mim2", titSrefKMimetype);
		extractUsmallintUclc(docctx, basexpath, "Size", "siz", Size);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQFilList
 ******************************************************************************/

ListBrlyQFilList::ListBrlyQFilList() {
};

ListBrlyQFilList::ListBrlyQFilList(
			const ListBrlyQFilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFilList(*(src.nodes[i]));
};

ListBrlyQFilList& ListBrlyQFilList::operator=(
			const ListBrlyQFilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFilList(*(src.nodes[i]));

	return *this;
};

ListBrlyQFilList::~ListBrlyQFilList() {
	clear();
};

void ListBrlyQFilList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQFilList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQFilList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQFilList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQFilList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQFilList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQFilList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

