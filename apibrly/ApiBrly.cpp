/**
  * \file ApiBrly.cpp
  * Brly API library global functionality (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "ApiBrly.h"

/******************************************************************************
 class StgBrlyapi
 ******************************************************************************/

StgBrlyapi::StgBrlyapi(
			const string ip
			, const uint port
			, const string username
			, const string password
		) : Block() {
	this->ip = ip;
	this->port = port;
	this->username = username;
	this->password = password;

	mask = {IP, PORT, USERNAME, PASSWORD};
};

bool StgBrlyapi::all(
			const set<uint>& items
		) {
	if (!find(items, IP)) return false;
	if (!find(items, PORT)) return false;
	if (!find(items, USERNAME)) return false;
	if (!find(items, PASSWORD)) return false;

	return true;
};

bool StgBrlyapi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyapi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyapi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
	};

	return basefound;
};

void StgBrlyapi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyapi";

	string itemtag;
	if (shorttags)
		itemtag = "Si";
	else
		itemtag = "StgitemBrlyapi";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUintAttr(wr, itemtag, "sref", "port", port);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyapi::compare(
			const StgBrlyapi* comp
		) {
	set<uint> items;

	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);

	return items;
};

/******************************************************************************
 namespace ApiBrly
 ******************************************************************************/

uint ApiBrly::readDpchEng(
			char* buf
			, unsigned long buflen
			, DpchEngBrly** dpcheng
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(buf, buflen, &doc, &docctx);

	uint ixBrlyVDpch = VecBrlyVDpch::getIx(extractRoot(doc));

	if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYACK) {
		*dpcheng = new DpchEngBrlyAck();
		((DpchEngBrlyAck*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYALERT) {
		*dpcheng = new DpchEngBrlyAlert();
		((DpchEngBrlyAlert*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCON1NRELAYDATA) {
		*dpcheng = new PnlBrlyCon1NRelay::DpchEngData();
		((PnlBrlyCon1NRelay::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONCONMNEQUIPMENTDATA) {
		*dpcheng = new PnlBrlyConConMNEquipment::DpchEngData();
		((PnlBrlyConConMNEquipment::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONDATA) {
		*dpcheng = new CrdBrlyCon::DpchEngData();
		((CrdBrlyCon::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONDETAILDATA) {
		*dpcheng = new PnlBrlyConDetail::DpchEngData();
		((PnlBrlyConDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONFIRM) {
		*dpcheng = new DpchEngBrlyConfirm();
		((DpchEngBrlyConfirm*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONHEADBARDATA) {
		*dpcheng = new PnlBrlyConHeadbar::DpchEngData();
		((PnlBrlyConHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONLISTDATA) {
		*dpcheng = new PnlBrlyConList::DpchEngData();
		((PnlBrlyConList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONMAPDATA) {
		*dpcheng = new PnlBrlyConMap::DpchEngData();
		((PnlBrlyConMap::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONMAPIMAGE) {
		*dpcheng = new PnlBrlyConMap::DpchEngImage();
		((PnlBrlyConMap::DpchEngImage*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONMNFLIGHTDATA) {
		*dpcheng = new PnlBrlyConMNFlight::DpchEngData();
		((PnlBrlyConMNFlight::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONMNSEGMENTDATA) {
		*dpcheng = new PnlBrlyConMNSegment::DpchEngData();
		((PnlBrlyConMNSegment::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONPREDATA) {
		*dpcheng = new PnlBrlyConPre::DpchEngData();
		((PnlBrlyConPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONRECDATA) {
		*dpcheng = new PnlBrlyConRec::DpchEngData();
		((PnlBrlyConRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONREF1NSEGMENTDATA) {
		*dpcheng = new PnlBrlyConRef1NSegment::DpchEngData();
		((PnlBrlyConRef1NSegment::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFILDATA) {
		*dpcheng = new CrdBrlyFil::DpchEngData();
		((CrdBrlyFil::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFILDETAILDATA) {
		*dpcheng = new PnlBrlyFilDetail::DpchEngData();
		((PnlBrlyFilDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFILHEADBARDATA) {
		*dpcheng = new PnlBrlyFilHeadbar::DpchEngData();
		((PnlBrlyFilHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFILLISTDATA) {
		*dpcheng = new PnlBrlyFilList::DpchEngData();
		((PnlBrlyFilList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFILRECDATA) {
		*dpcheng = new PnlBrlyFilRec::DpchEngData();
		((PnlBrlyFilRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLT1NCONNECTIONDATA) {
		*dpcheng = new PnlBrlyFlt1NConnection::DpchEngData();
		((PnlBrlyFlt1NConnection::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTDATA) {
		*dpcheng = new CrdBrlyFlt::DpchEngData();
		((CrdBrlyFlt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTDETAILDATA) {
		*dpcheng = new PnlBrlyFltDetail::DpchEngData();
		((PnlBrlyFltDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTEQP1NNODEDATA) {
		*dpcheng = new PnlBrlyFltEqp1NNode::DpchEngData();
		((PnlBrlyFltEqp1NNode::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTEQPMNCONNECTIONDATA) {
		*dpcheng = new PnlBrlyFltEqpMNConnection::DpchEngData();
		((PnlBrlyFltEqpMNConnection::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTFAFAWAYPOINTDATA) {
		*dpcheng = new PnlBrlyFltFafAWaypoint::DpchEngData();
		((PnlBrlyFltFafAWaypoint::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTHEADBARDATA) {
		*dpcheng = new PnlBrlyFltHeadbar::DpchEngData();
		((PnlBrlyFltHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTLISTDATA) {
		*dpcheng = new PnlBrlyFltList::DpchEngData();
		((PnlBrlyFltList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTMNCONNECTIONDATA) {
		*dpcheng = new PnlBrlyFltMNConnection::DpchEngData();
		((PnlBrlyFltMNConnection::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTMNLOCATIONDATA) {
		*dpcheng = new PnlBrlyFltMNLocation::DpchEngData();
		((PnlBrlyFltMNLocation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTORGMNFLIGHTDATA) {
		*dpcheng = new PnlBrlyFltOrgMNFlight::DpchEngData();
		((PnlBrlyFltOrgMNFlight::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTPREDATA) {
		*dpcheng = new PnlBrlyFltPre::DpchEngData();
		((PnlBrlyFltPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTRECDATA) {
		*dpcheng = new PnlBrlyFltRec::DpchEngData();
		((PnlBrlyFltRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYFLTREF1NSEGMENTDATA) {
		*dpcheng = new PnlBrlyFltRef1NSegment::DpchEngData();
		((PnlBrlyFltRef1NSegment::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEG1NFLIGHTDATA) {
		*dpcheng = new PnlBrlyLeg1NFlight::DpchEngData();
		((PnlBrlyLeg1NFlight::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGCOR1NCONNECTIONDATA) {
		*dpcheng = new PnlBrlyLegCor1NConnection::DpchEngData();
		((PnlBrlyLegCor1NConnection::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGDATA) {
		*dpcheng = new CrdBrlyLeg::DpchEngData();
		((CrdBrlyLeg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGDETAILDATA) {
		*dpcheng = new PnlBrlyLegDetail::DpchEngData();
		((PnlBrlyLegDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGHEADBARDATA) {
		*dpcheng = new PnlBrlyLegHeadbar::DpchEngData();
		((PnlBrlyLegHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGLISTDATA) {
		*dpcheng = new PnlBrlyLegList::DpchEngData();
		((PnlBrlyLegList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGMAPDATA) {
		*dpcheng = new PnlBrlyLegMap::DpchEngData();
		((PnlBrlyLegMap::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGMAPIMAGE) {
		*dpcheng = new PnlBrlyLegMap::DpchEngImage();
		((PnlBrlyLegMap::DpchEngImage*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGMNLOCATIONDATA) {
		*dpcheng = new PnlBrlyLegMNLocation::DpchEngData();
		((PnlBrlyLegMNLocation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGORGMNLEGDATA) {
		*dpcheng = new PnlBrlyLegOrgMNLeg::DpchEngData();
		((PnlBrlyLegOrgMNLeg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGPREDATA) {
		*dpcheng = new PnlBrlyLegPre::DpchEngData();
		((PnlBrlyLegPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLEGRECDATA) {
		*dpcheng = new PnlBrlyLegRec::DpchEngData();
		((PnlBrlyLegRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCBGN1NLEGDATA) {
		*dpcheng = new PnlBrlyLocBgn1NLeg::DpchEngData();
		((PnlBrlyLocBgn1NLeg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCDATA) {
		*dpcheng = new CrdBrlyLoc::DpchEngData();
		((CrdBrlyLoc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCDETAILDATA) {
		*dpcheng = new PnlBrlyLocDetail::DpchEngData();
		((PnlBrlyLocDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCEND1NLEGDATA) {
		*dpcheng = new PnlBrlyLocEnd1NLeg::DpchEngData();
		((PnlBrlyLocEnd1NLeg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCEQP1NNODEDATA) {
		*dpcheng = new PnlBrlyLocEqp1NNode::DpchEngData();
		((PnlBrlyLocEqp1NNode::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCEQPMNCONNECTIONDATA) {
		*dpcheng = new PnlBrlyLocEqpMNConnection::DpchEngData();
		((PnlBrlyLocEqpMNConnection::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCHEADBARDATA) {
		*dpcheng = new PnlBrlyLocHeadbar::DpchEngData();
		((PnlBrlyLocHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCLISTDATA) {
		*dpcheng = new PnlBrlyLocList::DpchEngData();
		((PnlBrlyLocList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCMAPDATA) {
		*dpcheng = new PnlBrlyLocMap::DpchEngData();
		((PnlBrlyLocMap::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCMAPIMAGE) {
		*dpcheng = new PnlBrlyLocMap::DpchEngImage();
		((PnlBrlyLocMap::DpchEngImage*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCMNFLIGHTDATA) {
		*dpcheng = new PnlBrlyLocMNFlight::DpchEngData();
		((PnlBrlyLocMNFlight::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCMNLEGDATA) {
		*dpcheng = new PnlBrlyLocMNLeg::DpchEngData();
		((PnlBrlyLocMNLeg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCMNSEGMENTDATA) {
		*dpcheng = new PnlBrlyLocMNSegment::DpchEngData();
		((PnlBrlyLocMNSegment::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCPROXORGMNLOCATIONDATA) {
		*dpcheng = new PnlBrlyLocProxOrgMNLocation::DpchEngData();
		((PnlBrlyLocProxOrgMNLocation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCRECDATA) {
		*dpcheng = new PnlBrlyLocRec::DpchEngData();
		((PnlBrlyLocRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYLOCVISORGMNLOCATIONDATA) {
		*dpcheng = new PnlBrlyLocVisOrgMNLocation::DpchEngData();
		((PnlBrlyLocVisOrgMNLocation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYNAVADMINDATA) {
		*dpcheng = new PnlBrlyNavAdmin::DpchEngData();
		((PnlBrlyNavAdmin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYNAVBASEDATA) {
		*dpcheng = new PnlBrlyNavBase::DpchEngData();
		((PnlBrlyNavBase::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYNAVCONNECTDATA) {
		*dpcheng = new PnlBrlyNavConnect::DpchEngData();
		((PnlBrlyNavConnect::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYNAVDATA) {
		*dpcheng = new CrdBrlyNav::DpchEngData();
		((CrdBrlyNav::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYNAVHEADBARDATA) {
		*dpcheng = new PnlBrlyNavHeadbar::DpchEngData();
		((PnlBrlyNavHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYOPR1NEQUIPMENTDATA) {
		*dpcheng = new PnlBrlyOpr1NEquipment::DpchEngData();
		((PnlBrlyOpr1NEquipment::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYOPRDATA) {
		*dpcheng = new CrdBrlyOpr::DpchEngData();
		((CrdBrlyOpr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYOPRDETAILDATA) {
		*dpcheng = new PnlBrlyOprDetail::DpchEngData();
		((PnlBrlyOprDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYOPRHEADBARDATA) {
		*dpcheng = new PnlBrlyOprHeadbar::DpchEngData();
		((PnlBrlyOprHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYOPRLISTDATA) {
		*dpcheng = new PnlBrlyOprList::DpchEngData();
		((PnlBrlyOprList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYOPRRECDATA) {
		*dpcheng = new PnlBrlyOprRec::DpchEngData();
		((PnlBrlyOprRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPRSADETAILDATA) {
		*dpcheng = new PnlBrlyPrsADetail::DpchEngData();
		((PnlBrlyPrsADetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPRSDATA) {
		*dpcheng = new CrdBrlyPrs::DpchEngData();
		((CrdBrlyPrs::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPRSDETAILDATA) {
		*dpcheng = new PnlBrlyPrsDetail::DpchEngData();
		((PnlBrlyPrsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPRSHEADBARDATA) {
		*dpcheng = new PnlBrlyPrsHeadbar::DpchEngData();
		((PnlBrlyPrsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPRSLISTDATA) {
		*dpcheng = new PnlBrlyPrsList::DpchEngData();
		((PnlBrlyPrsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPRSRECDATA) {
		*dpcheng = new PnlBrlyPrsRec::DpchEngData();
		((PnlBrlyPrsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPTY1NEQUIPMENTDATA) {
		*dpcheng = new PnlBrlyPty1NEquipment::DpchEngData();
		((PnlBrlyPty1NEquipment::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPTYDATA) {
		*dpcheng = new CrdBrlyPty::DpchEngData();
		((CrdBrlyPty::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPTYDETAILDATA) {
		*dpcheng = new PnlBrlyPtyDetail::DpchEngData();
		((PnlBrlyPtyDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPTYHEADBARDATA) {
		*dpcheng = new PnlBrlyPtyHeadbar::DpchEngData();
		((PnlBrlyPtyHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPTYLISTDATA) {
		*dpcheng = new PnlBrlyPtyList::DpchEngData();
		((PnlBrlyPtyList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYPTYRECDATA) {
		*dpcheng = new PnlBrlyPtyRec::DpchEngData();
		((PnlBrlyPtyRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYREG1NLOCATIONDATA) {
		*dpcheng = new PnlBrlyReg1NLocation::DpchEngData();
		((PnlBrlyReg1NLocation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYREGADSTSWITCHDATA) {
		*dpcheng = new PnlBrlyRegADstswitch::DpchEngData();
		((PnlBrlyRegADstswitch::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYREGDATA) {
		*dpcheng = new CrdBrlyReg::DpchEngData();
		((CrdBrlyReg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYREGDETAILDATA) {
		*dpcheng = new PnlBrlyRegDetail::DpchEngData();
		((PnlBrlyRegDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYREGHEADBARDATA) {
		*dpcheng = new PnlBrlyRegHeadbar::DpchEngData();
		((PnlBrlyRegHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYREGLISTDATA) {
		*dpcheng = new PnlBrlyRegList::DpchEngData();
		((PnlBrlyRegList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYREGRECDATA) {
		*dpcheng = new PnlBrlyRegRec::DpchEngData();
		((PnlBrlyRegRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYREGSUP1NREGIONDATA) {
		*dpcheng = new PnlBrlyRegSup1NRegion::DpchEngData();
		((PnlBrlyRegSup1NRegion::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYRLY1NNODEDATA) {
		*dpcheng = new PnlBrlyRly1NNode::DpchEngData();
		((PnlBrlyRly1NNode::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYRLYDATA) {
		*dpcheng = new CrdBrlyRly::DpchEngData();
		((CrdBrlyRly::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYRLYDETAILDATA) {
		*dpcheng = new PnlBrlyRlyDetail::DpchEngData();
		((PnlBrlyRlyDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYRLYHEADBARDATA) {
		*dpcheng = new PnlBrlyRlyHeadbar::DpchEngData();
		((PnlBrlyRlyHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYRLYLISTDATA) {
		*dpcheng = new PnlBrlyRlyList::DpchEngData();
		((PnlBrlyRlyList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYRLYRECDATA) {
		*dpcheng = new PnlBrlyRlyRec::DpchEngData();
		((PnlBrlyRlyRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYSEGDATA) {
		*dpcheng = new CrdBrlySeg::DpchEngData();
		((CrdBrlySeg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYSEGDETAILDATA) {
		*dpcheng = new PnlBrlySegDetail::DpchEngData();
		((PnlBrlySegDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYSEGHEADBARDATA) {
		*dpcheng = new PnlBrlySegHeadbar::DpchEngData();
		((PnlBrlySegHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYSEGLISTDATA) {
		*dpcheng = new PnlBrlySegList::DpchEngData();
		((PnlBrlySegList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYSEGMNCONNECTIONDATA) {
		*dpcheng = new PnlBrlySegMNConnection::DpchEngData();
		((PnlBrlySegMNConnection::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYSEGMNLOCATIONDATA) {
		*dpcheng = new PnlBrlySegMNLocation::DpchEngData();
		((PnlBrlySegMNLocation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYSEGORGMNSEGMENTDATA) {
		*dpcheng = new PnlBrlySegOrgMNSegment::DpchEngData();
		((PnlBrlySegOrgMNSegment::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYSEGPREDATA) {
		*dpcheng = new PnlBrlySegPre::DpchEngData();
		((PnlBrlySegPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYSEGRECDATA) {
		*dpcheng = new PnlBrlySegRec::DpchEngData();
		((PnlBrlySegRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYSUSPEND) {
		*dpcheng = new DpchEngBrlySuspend();
		((DpchEngBrlySuspend*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYTTB1NFLIGHTDATA) {
		*dpcheng = new PnlBrlyTtb1NFlight::DpchEngData();
		((PnlBrlyTtb1NFlight::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYTTBDATA) {
		*dpcheng = new CrdBrlyTtb::DpchEngData();
		((CrdBrlyTtb::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYTTBDETAILDATA) {
		*dpcheng = new PnlBrlyTtbDetail::DpchEngData();
		((PnlBrlyTtbDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYTTBHEADBARDATA) {
		*dpcheng = new PnlBrlyTtbHeadbar::DpchEngData();
		((PnlBrlyTtbHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYTTBLISTDATA) {
		*dpcheng = new PnlBrlyTtbList::DpchEngData();
		((PnlBrlyTtbList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYTTBRECDATA) {
		*dpcheng = new PnlBrlyTtbRec::DpchEngData();
		((PnlBrlyTtbRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYTTBREF1NFILEDATA) {
		*dpcheng = new PnlBrlyTtbRef1NFile::DpchEngData();
		((PnlBrlyTtbRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSGAACCESSDATA) {
		*dpcheng = new PnlBrlyUsgAAccess::DpchEngData();
		((PnlBrlyUsgAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSGDATA) {
		*dpcheng = new CrdBrlyUsg::DpchEngData();
		((CrdBrlyUsg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSGDETAILDATA) {
		*dpcheng = new PnlBrlyUsgDetail::DpchEngData();
		((PnlBrlyUsgDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSGHEADBARDATA) {
		*dpcheng = new PnlBrlyUsgHeadbar::DpchEngData();
		((PnlBrlyUsgHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSGLISTDATA) {
		*dpcheng = new PnlBrlyUsgList::DpchEngData();
		((PnlBrlyUsgList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSGMNUSERDATA) {
		*dpcheng = new PnlBrlyUsgMNUser::DpchEngData();
		((PnlBrlyUsgMNUser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSGRECDATA) {
		*dpcheng = new PnlBrlyUsgRec::DpchEngData();
		((PnlBrlyUsgRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSR1NSESSIONDATA) {
		*dpcheng = new PnlBrlyUsr1NSession::DpchEngData();
		((PnlBrlyUsr1NSession::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSRAACCESSDATA) {
		*dpcheng = new PnlBrlyUsrAAccess::DpchEngData();
		((PnlBrlyUsrAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSRDATA) {
		*dpcheng = new CrdBrlyUsr::DpchEngData();
		((CrdBrlyUsr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSRDETAILDATA) {
		*dpcheng = new PnlBrlyUsrDetail::DpchEngData();
		((PnlBrlyUsrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSRHEADBARDATA) {
		*dpcheng = new PnlBrlyUsrHeadbar::DpchEngData();
		((PnlBrlyUsrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSRLISTDATA) {
		*dpcheng = new PnlBrlyUsrList::DpchEngData();
		((PnlBrlyUsrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSRMNUSERGROUPDATA) {
		*dpcheng = new PnlBrlyUsrMNUsergroup::DpchEngData();
		((PnlBrlyUsrMNUsergroup::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYUSRRECDATA) {
		*dpcheng = new PnlBrlyUsrRec::DpchEngData();
		((PnlBrlyUsrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGDLGBRLYCONNEWDATA) {
		*dpcheng = new DlgBrlyConNew::DpchEngData();
		((DlgBrlyConNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGDLGBRLYLEGNEWDATA) {
		*dpcheng = new DlgBrlyLegNew::DpchEngData();
		((DlgBrlyLegNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGDLGBRLYNAVLOAINIDATA) {
		*dpcheng = new DlgBrlyNavLoaini::DpchEngData();
		((DlgBrlyNavLoaini::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGDLGBRLYTTBIMPFLTDATA) {
		*dpcheng = new DlgBrlyTtbImpflt::DpchEngData();
		((DlgBrlyTtbImpflt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGDLGBRLYTTBNEWDATA) {
		*dpcheng = new DlgBrlyTtbNew::DpchEngData();
		((DlgBrlyTtbNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGDLGBRLYTTBTRLORIGDATA) {
		*dpcheng = new DlgBrlyTtbTrlorig::DpchEngData();
		((DlgBrlyTtbTrlorig::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHENGSESSBRLYDATA) {
		*dpcheng = new SessBrly::DpchEngData();
		((SessBrly::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixBrlyVDpch;
};

void ApiBrly::writeDpchApp(
			DpchAppBrly* dpchapp
			, char** buf
			, unsigned long& buflen
			, unsigned long ofs
		) {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &xbuf);
		dpchapp->writeXML(wr);
	closewriteBuffer(wr);

	buflen = xbuf->use + ofs;
	*buf = new char[buflen];
	memcpy(&((*buf)[ofs]), xbuf->content, buflen-ofs);

	xmlBufferFree(xbuf);
};

