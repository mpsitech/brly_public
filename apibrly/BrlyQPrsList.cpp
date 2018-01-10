/**
  * \file BrlyQPrsList.cpp
  * API code for table TblBrlyQPrsList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "BrlyQPrsList.h"

/******************************************************************************
 class BrlyQPrsList
 ******************************************************************************/

BrlyQPrsList::BrlyQPrsList(
			const uint jnum
			, const string Title
			, const string Firstname
			, const string Lastname
			, const string stubGrp
			, const string stubOwn
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->telVal = telVal;
	this->emlVal = emlVal;
};

bool BrlyQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "BrlyQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname);
		extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname);
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex);
		extractStringUclc(docctx, basexpath, "titIxVSex", "sex2", titIxVSex);
		extractStringUclc(docctx, basexpath, "telVal", "tel", telVal);
		extractStringUclc(docctx, basexpath, "emlVal", "eml", emlVal);
	};

	return basefound;
};

/******************************************************************************
 class ListBrlyQPrsList
 ******************************************************************************/

ListBrlyQPrsList::ListBrlyQPrsList() {
};

ListBrlyQPrsList::ListBrlyQPrsList(
			const ListBrlyQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQPrsList(*(src.nodes[i]));
};

ListBrlyQPrsList& ListBrlyQPrsList::operator=(
			const ListBrlyQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQPrsList(*(src.nodes[i]));

	return *this;
};

ListBrlyQPrsList::~ListBrlyQPrsList() {
	clear();
};

void ListBrlyQPrsList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListBrlyQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	BrlyQPrsList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListBrlyQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "BrlyQPrsList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new BrlyQPrsList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/BrlyQPrsList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

