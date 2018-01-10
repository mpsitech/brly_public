/**
  * \file QryBrlyConMapLocation_blks.cpp
  * job handler for job QryBrlyConMapLocation (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class QryBrlyConMapLocation::StatShr
 ******************************************************************************/

QryBrlyConMapLocation::StatShr::StatShr(
			const uint ntot
		) : Block() {
	this->ntot = ntot;

	mask = {NTOT};
};

void QryBrlyConMapLocation::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryBrlyConMapLocation";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryBrlyConMapLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
	xmlTextWriterEndElement(wr);
};

set<uint> QryBrlyConMapLocation::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);

	return(items);
};

set<uint> QryBrlyConMapLocation::StatShr::diff(
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
 class QryBrlyConMapLocation::StgIac
 ******************************************************************************/

QryBrlyConMapLocation::StgIac::StgIac(
			const uint jnum
		) : Block() {
	this->jnum = jnum;
	mask = {JNUM};
};

bool QryBrlyConMapLocation::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryBrlyConMapLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryBrlyConMapLocation";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
	};

	return basefound;
};

void QryBrlyConMapLocation::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryBrlyConMapLocation";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryBrlyConMapLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
	xmlTextWriterEndElement(wr);
};

set<uint> QryBrlyConMapLocation::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);

	return(items);
};

set<uint> QryBrlyConMapLocation::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

