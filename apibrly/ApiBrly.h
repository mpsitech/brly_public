/**
  * \file ApiBrly.h
  * Brly API library global functionality (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef APIBRLY_H
#define APIBRLY_H

#define BRLY_VERSION "0.2.2"
#define BRLY_VERSION_MAJOR 0
#define BRLY_VERSION_MINOR 2
#define BRLY_VERSION_SUB 2

#include "ApiBrly_blks.h"

#include "BrlyQCon1NRelay.h"
#include "BrlyQConConMNEquipment.h"
#include "BrlyQConList.h"
#include "BrlyQConMapFlight.h"
#include "BrlyQConMapLeg.h"
#include "BrlyQConMapLocation.h"
#include "BrlyQConMapNode.h"
#include "BrlyQConMapRelay.h"
#include "BrlyQConMNFlight.h"
#include "BrlyQConMNSegment.h"
#include "BrlyQConRef1NSegment.h"
#include "BrlyQFilList.h"
#include "BrlyQFlt1NConnection.h"
#include "BrlyQFltEqp1NNode.h"
#include "BrlyQFltEqpMNConnection.h"
#include "BrlyQFltFafAWaypoint.h"
#include "BrlyQFltList.h"
#include "BrlyQFltMNConnection.h"
#include "BrlyQFltMNLocation.h"
#include "BrlyQFltOrgMNFlight.h"
#include "BrlyQFltRef1NSegment.h"
#include "BrlyQLeg1NFlight.h"
#include "BrlyQLegCor1NConnection.h"
#include "BrlyQLegList.h"
#include "BrlyQLegMapLeg.h"
#include "BrlyQLegMapLocation.h"
#include "BrlyQLegMNLocation.h"
#include "BrlyQLegOrgMNLeg.h"
#include "BrlyQLocBgn1NLeg.h"
#include "BrlyQLocEnd1NLeg.h"
#include "BrlyQLocEqp1NNode.h"
#include "BrlyQLocEqpMNConnection.h"
#include "BrlyQLocList.h"
#include "BrlyQLocMapLeg.h"
#include "BrlyQLocMapProxLocation.h"
#include "BrlyQLocMapVisLocation.h"
#include "BrlyQLocMNFlight.h"
#include "BrlyQLocMNLeg.h"
#include "BrlyQLocMNSegment.h"
#include "BrlyQLocProxOrgMNLocation.h"
#include "BrlyQLocVisOrgMNLocation.h"
#include "BrlyQOpr1NEquipment.h"
#include "BrlyQOprList.h"
#include "BrlyQPrsADetail.h"
#include "BrlyQPrsList.h"
#include "BrlyQPty1NEquipment.h"
#include "BrlyQPtyList.h"
#include "BrlyQReg1NLocation.h"
#include "BrlyQRegADstswitch.h"
#include "BrlyQRegList.h"
#include "BrlyQRegSup1NRegion.h"
#include "BrlyQRly1NNode.h"
#include "BrlyQRlyList.h"
#include "BrlyQSegList.h"
#include "BrlyQSegMNConnection.h"
#include "BrlyQSegMNLocation.h"
#include "BrlyQSegOrgMNSegment.h"
#include "BrlyQTtb1NFlight.h"
#include "BrlyQTtbList.h"
#include "BrlyQTtbRef1NFile.h"
#include "BrlyQUsgAAccess.h"
#include "BrlyQUsgList.h"
#include "BrlyQUsgMNUser.h"
#include "BrlyQUsr1NSession.h"
#include "BrlyQUsrAAccess.h"
#include "BrlyQUsrList.h"
#include "BrlyQUsrMNUsergroup.h"

#include "CrdBrlyCon.h"
#include "CrdBrlyFil.h"
#include "CrdBrlyFlt.h"
#include "CrdBrlyLeg.h"
#include "CrdBrlyLoc.h"
#include "CrdBrlyNav.h"
#include "CrdBrlyOpr.h"
#include "CrdBrlyPrs.h"
#include "CrdBrlyPty.h"
#include "CrdBrlyReg.h"
#include "CrdBrlyRly.h"
#include "CrdBrlySeg.h"
#include "CrdBrlyTtb.h"
#include "CrdBrlyUsg.h"
#include "CrdBrlyUsr.h"
#include "DlgBrlyConNew.h"
#include "DlgBrlyLegNew.h"
#include "DlgBrlyNavLoaini.h"
#include "DlgBrlyTtbImpflt.h"
#include "DlgBrlyTtbNew.h"
#include "DlgBrlyTtbTrlorig.h"
#include "PnlBrlyCon1NRelay.h"
#include "PnlBrlyConConMNEquipment.h"
#include "PnlBrlyConDetail.h"
#include "PnlBrlyConHeadbar.h"
#include "PnlBrlyConList.h"
#include "PnlBrlyConMap.h"
#include "PnlBrlyConMNFlight.h"
#include "PnlBrlyConMNSegment.h"
#include "PnlBrlyConPre.h"
#include "PnlBrlyConRec.h"
#include "PnlBrlyConRef1NSegment.h"
#include "PnlBrlyFilDetail.h"
#include "PnlBrlyFilHeadbar.h"
#include "PnlBrlyFilList.h"
#include "PnlBrlyFilRec.h"
#include "PnlBrlyFlt1NConnection.h"
#include "PnlBrlyFltDetail.h"
#include "PnlBrlyFltEqp1NNode.h"
#include "PnlBrlyFltEqpMNConnection.h"
#include "PnlBrlyFltFafAWaypoint.h"
#include "PnlBrlyFltHeadbar.h"
#include "PnlBrlyFltList.h"
#include "PnlBrlyFltMNConnection.h"
#include "PnlBrlyFltMNLocation.h"
#include "PnlBrlyFltOrgMNFlight.h"
#include "PnlBrlyFltPre.h"
#include "PnlBrlyFltRec.h"
#include "PnlBrlyFltRef1NSegment.h"
#include "PnlBrlyLeg1NFlight.h"
#include "PnlBrlyLegCor1NConnection.h"
#include "PnlBrlyLegDetail.h"
#include "PnlBrlyLegHeadbar.h"
#include "PnlBrlyLegList.h"
#include "PnlBrlyLegMap.h"
#include "PnlBrlyLegMNLocation.h"
#include "PnlBrlyLegOrgMNLeg.h"
#include "PnlBrlyLegPre.h"
#include "PnlBrlyLegRec.h"
#include "PnlBrlyLocBgn1NLeg.h"
#include "PnlBrlyLocDetail.h"
#include "PnlBrlyLocEnd1NLeg.h"
#include "PnlBrlyLocEqp1NNode.h"
#include "PnlBrlyLocEqpMNConnection.h"
#include "PnlBrlyLocHeadbar.h"
#include "PnlBrlyLocList.h"
#include "PnlBrlyLocMap.h"
#include "PnlBrlyLocMNFlight.h"
#include "PnlBrlyLocMNLeg.h"
#include "PnlBrlyLocMNSegment.h"
#include "PnlBrlyLocProxOrgMNLocation.h"
#include "PnlBrlyLocRec.h"
#include "PnlBrlyLocVisOrgMNLocation.h"
#include "PnlBrlyNavAdmin.h"
#include "PnlBrlyNavBase.h"
#include "PnlBrlyNavConnect.h"
#include "PnlBrlyNavHeadbar.h"
#include "PnlBrlyOpr1NEquipment.h"
#include "PnlBrlyOprDetail.h"
#include "PnlBrlyOprHeadbar.h"
#include "PnlBrlyOprList.h"
#include "PnlBrlyOprRec.h"
#include "PnlBrlyPrsADetail.h"
#include "PnlBrlyPrsDetail.h"
#include "PnlBrlyPrsHeadbar.h"
#include "PnlBrlyPrsList.h"
#include "PnlBrlyPrsRec.h"
#include "PnlBrlyPty1NEquipment.h"
#include "PnlBrlyPtyDetail.h"
#include "PnlBrlyPtyHeadbar.h"
#include "PnlBrlyPtyList.h"
#include "PnlBrlyPtyRec.h"
#include "PnlBrlyReg1NLocation.h"
#include "PnlBrlyRegADstswitch.h"
#include "PnlBrlyRegDetail.h"
#include "PnlBrlyRegHeadbar.h"
#include "PnlBrlyRegList.h"
#include "PnlBrlyRegRec.h"
#include "PnlBrlyRegSup1NRegion.h"
#include "PnlBrlyRly1NNode.h"
#include "PnlBrlyRlyDetail.h"
#include "PnlBrlyRlyHeadbar.h"
#include "PnlBrlyRlyList.h"
#include "PnlBrlyRlyRec.h"
#include "PnlBrlySegDetail.h"
#include "PnlBrlySegHeadbar.h"
#include "PnlBrlySegList.h"
#include "PnlBrlySegMNConnection.h"
#include "PnlBrlySegMNLocation.h"
#include "PnlBrlySegOrgMNSegment.h"
#include "PnlBrlySegPre.h"
#include "PnlBrlySegRec.h"
#include "PnlBrlyTtb1NFlight.h"
#include "PnlBrlyTtbDetail.h"
#include "PnlBrlyTtbHeadbar.h"
#include "PnlBrlyTtbList.h"
#include "PnlBrlyTtbRec.h"
#include "PnlBrlyTtbRef1NFile.h"
#include "PnlBrlyUsgAAccess.h"
#include "PnlBrlyUsgDetail.h"
#include "PnlBrlyUsgHeadbar.h"
#include "PnlBrlyUsgList.h"
#include "PnlBrlyUsgMNUser.h"
#include "PnlBrlyUsgRec.h"
#include "PnlBrlyUsr1NSession.h"
#include "PnlBrlyUsrAAccess.h"
#include "PnlBrlyUsrDetail.h"
#include "PnlBrlyUsrHeadbar.h"
#include "PnlBrlyUsrList.h"
#include "PnlBrlyUsrMNUsergroup.h"
#include "PnlBrlyUsrRec.h"
#include "QryBrlyCon1NRelay.h"
#include "QryBrlyConConMNEquipment.h"
#include "QryBrlyConList.h"
#include "QryBrlyConMapFlight.h"
#include "QryBrlyConMapLeg.h"
#include "QryBrlyConMapLocation.h"
#include "QryBrlyConMapNode.h"
#include "QryBrlyConMapRelay.h"
#include "QryBrlyConMNFlight.h"
#include "QryBrlyConMNSegment.h"
#include "QryBrlyConRef1NSegment.h"
#include "QryBrlyFilList.h"
#include "QryBrlyFlt1NConnection.h"
#include "QryBrlyFltEqp1NNode.h"
#include "QryBrlyFltEqpMNConnection.h"
#include "QryBrlyFltFafAWaypoint.h"
#include "QryBrlyFltList.h"
#include "QryBrlyFltMNConnection.h"
#include "QryBrlyFltMNLocation.h"
#include "QryBrlyFltOrgMNFlight.h"
#include "QryBrlyFltRef1NSegment.h"
#include "QryBrlyLeg1NFlight.h"
#include "QryBrlyLegCor1NConnection.h"
#include "QryBrlyLegList.h"
#include "QryBrlyLegMapLeg.h"
#include "QryBrlyLegMapLocation.h"
#include "QryBrlyLegMNLocation.h"
#include "QryBrlyLegOrgMNLeg.h"
#include "QryBrlyLocBgn1NLeg.h"
#include "QryBrlyLocEnd1NLeg.h"
#include "QryBrlyLocEqp1NNode.h"
#include "QryBrlyLocEqpMNConnection.h"
#include "QryBrlyLocList.h"
#include "QryBrlyLocMapLeg.h"
#include "QryBrlyLocMapProxLocation.h"
#include "QryBrlyLocMapVisLocation.h"
#include "QryBrlyLocMNFlight.h"
#include "QryBrlyLocMNLeg.h"
#include "QryBrlyLocMNSegment.h"
#include "QryBrlyLocProxOrgMNLocation.h"
#include "QryBrlyLocVisOrgMNLocation.h"
#include "QryBrlyOpr1NEquipment.h"
#include "QryBrlyOprList.h"
#include "QryBrlyPrsADetail.h"
#include "QryBrlyPrsList.h"
#include "QryBrlyPty1NEquipment.h"
#include "QryBrlyPtyList.h"
#include "QryBrlyReg1NLocation.h"
#include "QryBrlyRegADstswitch.h"
#include "QryBrlyRegList.h"
#include "QryBrlyRegSup1NRegion.h"
#include "QryBrlyRly1NNode.h"
#include "QryBrlyRlyList.h"
#include "QryBrlySegList.h"
#include "QryBrlySegMNConnection.h"
#include "QryBrlySegMNLocation.h"
#include "QryBrlySegOrgMNSegment.h"
#include "QryBrlyTtb1NFlight.h"
#include "QryBrlyTtbList.h"
#include "QryBrlyTtbRef1NFile.h"
#include "QryBrlyUsgAAccess.h"
#include "QryBrlyUsgList.h"
#include "QryBrlyUsgMNUser.h"
#include "QryBrlyUsr1NSession.h"
#include "QryBrlyUsrAAccess.h"
#include "QryBrlyUsrList.h"
#include "QryBrlyUsrMNUsergroup.h"
#include "RootBrly.h"
#include "SessBrly.h"

/**
  * StgBrlyapi
  */
class StgBrlyapi : public Block {

public:
	static const ubigint IP = 1;
	static const ubigint PORT = 2;
	static const ubigint USERNAME = 3;
	static const ubigint PASSWORD = 4;

public:
	StgBrlyapi(const string ip = "", const uint port = 0, const string username = "", const string password = "");

public:
	string ip;
	uint port;
	string username;
	string password;

public:
	static bool all(const set<uint>& items);
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> compare(const StgBrlyapi* comp);
};

/**
  * ApiBrly
  */
namespace ApiBrly {
	uint readDpchEng(char* buf, unsigned long buflen, DpchEngBrly** dpcheng);
	void writeDpchApp(DpchAppBrly* dpchapp, char** buf, unsigned long& buflen, unsigned long ofs = 0);
};

#endif

