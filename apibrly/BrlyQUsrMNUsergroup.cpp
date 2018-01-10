/**
  * \file BrlyQUsrMNUsergroup.cpp
  * API code for table TblBrlyQUsrMNUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQUsrMNUsergroup.h"

/******************************************************************************
 class BrlyQUsrMNUsergroup
 ******************************************************************************/

BrlyQUsrMNUsergroup::BrlyQUsrMNUsergroup(
			const uint jnum
			, const string stubMref
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxBrlyVUserlevel = srefIxBrlyVUserlevel;
	this->titIxBrlyVUserlevel = titIxBrlyVUserlevel;
};

bool BrlyQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxBrlyVUserlevel", "ulv", srefIxBrlyVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxBrlyVUserlevel", "ulv2", titIxBrlyVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQUsrMNUsergroup
 ******************************************************************************/

ListBrlyQUsrMNUsergroup::ListBrlyQUsrMNUsergroup() {
};

ListBrlyQUsrMNUsergroup::ListBrlyQUsrMNUsergroup(
			const ListBrlyQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsrMNUsergroup(*(src.nodes[i]));
};

ListBrlyQUsrMNUsergroup& ListBrlyQUsrMNUsergroup::operator=(
			const ListBrlyQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsrMNUsergroup(*(src.nodes[i]));

	return *this;
};

ListBrlyQUsrMNUsergroup::~ListBrlyQUsrMNUsergroup() {
	clear();
};

void ListBrlyQUsrMNUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQUsrMNUsergroup* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQUsrMNUsergroup", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQUsrMNUsergroup(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQUsrMNUsergroup[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

