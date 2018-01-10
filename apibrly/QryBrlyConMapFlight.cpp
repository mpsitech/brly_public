/**
  * \file QryBrlyConMapFlight.cpp
  * API code for job QryBrlyConMapFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "QryBrlyConMapFlight.h"

/******************************************************************************
 class QryBrlyConMapFlight::StatShr
 ******************************************************************************/

QryBrlyConMapFlight::StatShr::StatShr(
			const uint ntot
		) : Block() {
	this->ntot = ntot;

	mask = {NTOT};
};

bool QryBrlyConMapFlight::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrQryBrlyConMapFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrQryBrlyConMapFlight";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ntot", ntot)) add(NTOT);
	};

	return basefound;
};

set<uint> QryBrlyConMapFlight::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);

	return(items);
};

set<uint> QryBrlyConMapFlight::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NTOT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryBrlyConMapFlight::StgIac
 ******************************************************************************/

QryBrlyConMapFlight::StgIac::StgIac(
			const uint jnum
		) : Block() {
	this->jnum = jnum;

	mask = {JNUM};
};

bool QryBrlyConMapFlight::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryBrlyConMapFlight");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryBrlyConMapFlight";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
	};

	return basefound;
};

void QryBrlyConMapFlight::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryBrlyConMapFlight";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryBrlyConMapFlight";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
	xmlTextWriterEndElement(wr);
};

set<uint> QryBrlyConMapFlight::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);

	return(items);
};

set<uint> QryBrlyConMapFlight::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

