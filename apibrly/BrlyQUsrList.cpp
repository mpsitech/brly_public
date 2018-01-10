/**
  * \file BrlyQUsrList.cpp
  * API code for table TblBrlyQUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQUsrList.h"

/******************************************************************************
 class BrlyQUsrList
 ******************************************************************************/

BrlyQUsrList::BrlyQUsrList(
			const uint jnum
			, const string stubRefBrlyMPerson
			, const string sref
			, const string stubRefBrlyMUsergroup
			, const string srefIxVState
			, const string titIxVState
			, const string srefIxBrlyVLocale
			, const string titIxBrlyVLocale
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	this->jnum = jnum;
	this->stubRefBrlyMPerson = stubRefBrlyMPerson;
	this->sref = sref;
	this->stubRefBrlyMUsergroup = stubRefBrlyMUsergroup;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->srefIxBrlyVLocale = srefIxBrlyVLocale;
	this->titIxBrlyVLocale = titIxBrlyVLocale;
	this->srefIxBrlyVUserlevel = srefIxBrlyVUserlevel;
	this->titIxBrlyVUserlevel = titIxBrlyVUserlevel;
};

bool BrlyQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefBrlyMPerson", "prs", stubRefBrlyMPerson);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefBrlyMUsergroup", "usg", stubRefBrlyMUsergroup);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "srefIxBrlyVLocale", "lcl", srefIxBrlyVLocale);
		extractStringUclc(docctx, basexpath, "titIxBrlyVLocale", "lcl2", titIxBrlyVLocale);
		extractStringUclc(docctx, basexpath, "srefIxBrlyVUserlevel", "ulv", srefIxBrlyVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxBrlyVUserlevel", "ulv2", titIxBrlyVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQUsrList
 ******************************************************************************/

ListBrlyQUsrList::ListBrlyQUsrList() {
};

ListBrlyQUsrList::ListBrlyQUsrList(
			const ListBrlyQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsrList(*(src.nodes[i]));
};

ListBrlyQUsrList& ListBrlyQUsrList::operator=(
			const ListBrlyQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsrList(*(src.nodes[i]));

	return *this;
};

ListBrlyQUsrList::~ListBrlyQUsrList() {
	clear();
};

void ListBrlyQUsrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQUsrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQUsrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQUsrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQUsrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

