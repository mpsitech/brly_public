/**
  * \file BrlyQUsgMNUser.cpp
  * API code for table TblBrlyQUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQUsgMNUser.h"

/******************************************************************************
 class BrlyQUsgMNUser
 ******************************************************************************/

BrlyQUsgMNUser::BrlyQUsgMNUser(
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

bool BrlyQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQUsgMNUser");
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
 class ListBrlyQUsgMNUser
 ******************************************************************************/

ListBrlyQUsgMNUser::ListBrlyQUsgMNUser() {
};

ListBrlyQUsgMNUser::ListBrlyQUsgMNUser(
			const ListBrlyQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsgMNUser(*(src.nodes[i]));
};

ListBrlyQUsgMNUser& ListBrlyQUsgMNUser::operator=(
			const ListBrlyQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsgMNUser(*(src.nodes[i]));

	return *this;
};

ListBrlyQUsgMNUser::~ListBrlyQUsgMNUser() {
	clear();
};

void ListBrlyQUsgMNUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQUsgMNUser* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQUsgMNUser");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQUsgMNUser", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQUsgMNUser(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQUsgMNUser[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

