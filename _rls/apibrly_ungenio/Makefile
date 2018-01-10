# file Makefile
# make file for Brly API library, release apibrly_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

LIBROOT = /Users/mpsitech/lib

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

STATLIB = ar
STATLIBFLAGS = rcs

INCPATH = -I/usr/local/include -I/usr/local/include/libxml2

PCHS = ApiBrly.h.gch

OBJS = ApiBrly_blks.o ApiBrly.o
OBJS += VecBrlyVDpch.o VecBrlyVExpstate.o VecBrlyVQrystate.o VecBrlyVReqitmode.o
OBJS += BrlyQCon1NRelay.o BrlyQConConMNEquipment.o BrlyQConList.o BrlyQConMapFlight.o BrlyQConMapLeg.o BrlyQConMapLocation.o BrlyQConMapNode.o BrlyQConMapRelay.o BrlyQConMNFlight.o BrlyQConMNSegment.o BrlyQConRef1NSegment.o BrlyQFilList.o BrlyQFlt1NConnection.o BrlyQFltEqp1NNode.o BrlyQFltEqpMNConnection.o BrlyQFltFafAWaypoint.o BrlyQFltList.o BrlyQFltMNConnection.o BrlyQFltMNLocation.o BrlyQFltOrgMNFlight.o BrlyQFltRef1NSegment.o BrlyQLeg1NFlight.o BrlyQLegCor1NConnection.o BrlyQLegList.o BrlyQLegMapLeg.o BrlyQLegMapLocation.o BrlyQLegMNLocation.o BrlyQLegOrgMNLeg.o BrlyQLocBgn1NLeg.o BrlyQLocEnd1NLeg.o BrlyQLocEqp1NNode.o BrlyQLocEqpMNConnection.o BrlyQLocList.o BrlyQLocMapLeg.o BrlyQLocMapProxLocation.o BrlyQLocMapVisLocation.o BrlyQLocMNFlight.o BrlyQLocMNLeg.o BrlyQLocMNSegment.o BrlyQLocProxOrgMNLocation.o BrlyQLocVisOrgMNLocation.o BrlyQOpr1NEquipment.o BrlyQOprList.o BrlyQPrsADetail.o BrlyQPrsList.o BrlyQPty1NEquipment.o BrlyQPtyList.o BrlyQReg1NLocation.o BrlyQRegADstswitch.o BrlyQRegList.o BrlyQRegSup1NRegion.o BrlyQRly1NNode.o BrlyQRlyList.o BrlyQSegList.o BrlyQSegMNConnection.o BrlyQSegMNLocation.o BrlyQSegOrgMNSegment.o BrlyQTtb1NFlight.o BrlyQTtbList.o BrlyQTtbRef1NFile.o BrlyQUsgAAccess.o BrlyQUsgList.o BrlyQUsgMNUser.o BrlyQUsr1NSession.o BrlyQUsrAAccess.o BrlyQUsrList.o BrlyQUsrMNUsergroup.o
OBJS += CrdBrlyCon.o CrdBrlyFil.o CrdBrlyFlt.o CrdBrlyLeg.o CrdBrlyLoc.o CrdBrlyNav.o CrdBrlyOpr.o CrdBrlyPrs.o CrdBrlyPty.o CrdBrlyReg.o CrdBrlyRly.o CrdBrlySeg.o CrdBrlyTtb.o CrdBrlyUsg.o CrdBrlyUsr.o DlgBrlyConNew.o DlgBrlyLegNew.o DlgBrlyNavLoaini.o DlgBrlyTtbImpflt.o DlgBrlyTtbNew.o DlgBrlyTtbTrlorig.o PnlBrlyCon1NRelay.o PnlBrlyConConMNEquipment.o PnlBrlyConDetail.o PnlBrlyConHeadbar.o PnlBrlyConList.o PnlBrlyConMap.o PnlBrlyConMNFlight.o PnlBrlyConMNSegment.o PnlBrlyConPre.o PnlBrlyConRec.o PnlBrlyConRef1NSegment.o PnlBrlyFilDetail.o PnlBrlyFilHeadbar.o PnlBrlyFilList.o PnlBrlyFilRec.o PnlBrlyFlt1NConnection.o PnlBrlyFltDetail.o PnlBrlyFltEqp1NNode.o PnlBrlyFltEqpMNConnection.o PnlBrlyFltFafAWaypoint.o PnlBrlyFltHeadbar.o PnlBrlyFltList.o PnlBrlyFltMNConnection.o PnlBrlyFltMNLocation.o PnlBrlyFltOrgMNFlight.o PnlBrlyFltPre.o PnlBrlyFltRec.o PnlBrlyFltRef1NSegment.o PnlBrlyLeg1NFlight.o PnlBrlyLegCor1NConnection.o PnlBrlyLegDetail.o PnlBrlyLegHeadbar.o PnlBrlyLegList.o PnlBrlyLegMap.o PnlBrlyLegMNLocation.o PnlBrlyLegOrgMNLeg.o PnlBrlyLegPre.o PnlBrlyLegRec.o PnlBrlyLocBgn1NLeg.o PnlBrlyLocDetail.o PnlBrlyLocEnd1NLeg.o PnlBrlyLocEqp1NNode.o PnlBrlyLocEqpMNConnection.o PnlBrlyLocHeadbar.o PnlBrlyLocList.o PnlBrlyLocMap.o PnlBrlyLocMNFlight.o PnlBrlyLocMNLeg.o PnlBrlyLocMNSegment.o PnlBrlyLocProxOrgMNLocation.o PnlBrlyLocRec.o PnlBrlyLocVisOrgMNLocation.o PnlBrlyNavAdmin.o PnlBrlyNavBase.o PnlBrlyNavConnect.o PnlBrlyNavHeadbar.o PnlBrlyOpr1NEquipment.o PnlBrlyOprDetail.o PnlBrlyOprHeadbar.o PnlBrlyOprList.o PnlBrlyOprRec.o PnlBrlyPrsADetail.o PnlBrlyPrsDetail.o PnlBrlyPrsHeadbar.o PnlBrlyPrsList.o PnlBrlyPrsRec.o PnlBrlyPty1NEquipment.o PnlBrlyPtyDetail.o PnlBrlyPtyHeadbar.o PnlBrlyPtyList.o PnlBrlyPtyRec.o PnlBrlyReg1NLocation.o PnlBrlyRegADstswitch.o PnlBrlyRegDetail.o PnlBrlyRegHeadbar.o PnlBrlyRegList.o PnlBrlyRegRec.o PnlBrlyRegSup1NRegion.o PnlBrlyRly1NNode.o PnlBrlyRlyDetail.o PnlBrlyRlyHeadbar.o PnlBrlyRlyList.o PnlBrlyRlyRec.o PnlBrlySegDetail.o PnlBrlySegHeadbar.o PnlBrlySegList.o PnlBrlySegMNConnection.o PnlBrlySegMNLocation.o PnlBrlySegOrgMNSegment.o PnlBrlySegPre.o PnlBrlySegRec.o PnlBrlyTtb1NFlight.o PnlBrlyTtbDetail.o PnlBrlyTtbHeadbar.o PnlBrlyTtbList.o PnlBrlyTtbRec.o PnlBrlyTtbRef1NFile.o PnlBrlyUsgAAccess.o PnlBrlyUsgDetail.o PnlBrlyUsgHeadbar.o PnlBrlyUsgList.o PnlBrlyUsgMNUser.o PnlBrlyUsgRec.o PnlBrlyUsr1NSession.o PnlBrlyUsrAAccess.o PnlBrlyUsrDetail.o PnlBrlyUsrHeadbar.o PnlBrlyUsrList.o PnlBrlyUsrMNUsergroup.o PnlBrlyUsrRec.o QryBrlyCon1NRelay.o QryBrlyConConMNEquipment.o QryBrlyConList.o QryBrlyConMapFlight.o QryBrlyConMapLeg.o QryBrlyConMapLocation.o QryBrlyConMapNode.o QryBrlyConMapRelay.o QryBrlyConMNFlight.o QryBrlyConMNSegment.o QryBrlyConRef1NSegment.o QryBrlyFilList.o QryBrlyFlt1NConnection.o QryBrlyFltEqp1NNode.o QryBrlyFltEqpMNConnection.o QryBrlyFltFafAWaypoint.o QryBrlyFltList.o QryBrlyFltMNConnection.o QryBrlyFltMNLocation.o QryBrlyFltOrgMNFlight.o QryBrlyFltRef1NSegment.o QryBrlyLeg1NFlight.o QryBrlyLegCor1NConnection.o QryBrlyLegList.o QryBrlyLegMapLeg.o QryBrlyLegMapLocation.o QryBrlyLegMNLocation.o QryBrlyLegOrgMNLeg.o QryBrlyLocBgn1NLeg.o QryBrlyLocEnd1NLeg.o QryBrlyLocEqp1NNode.o QryBrlyLocEqpMNConnection.o QryBrlyLocList.o QryBrlyLocMapLeg.o QryBrlyLocMapProxLocation.o QryBrlyLocMapVisLocation.o QryBrlyLocMNFlight.o QryBrlyLocMNLeg.o QryBrlyLocMNSegment.o QryBrlyLocProxOrgMNLocation.o QryBrlyLocVisOrgMNLocation.o QryBrlyOpr1NEquipment.o QryBrlyOprList.o QryBrlyPrsADetail.o QryBrlyPrsList.o QryBrlyPty1NEquipment.o QryBrlyPtyList.o QryBrlyReg1NLocation.o QryBrlyRegADstswitch.o QryBrlyRegList.o QryBrlyRegSup1NRegion.o QryBrlyRly1NNode.o QryBrlyRlyList.o QryBrlySegList.o QryBrlySegMNConnection.o QryBrlySegMNLocation.o QryBrlySegOrgMNSegment.o QryBrlyTtb1NFlight.o QryBrlyTtbList.o QryBrlyTtbRef1NFile.o QryBrlyUsgAAccess.o QryBrlyUsgList.o QryBrlyUsgMNUser.o QryBrlyUsr1NSession.o QryBrlyUsrAAccess.o QryBrlyUsrList.o QryBrlyUsrMNUsergroup.o RootBrly.o SessBrly.o

LIB = libapibrly

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(LIB)

$(LIB):	$(PCHS) $(OBJS)
	$(STATLIB) $(STATLIBFLAGS) $(LIB).a $(OBJS)
	rm -f *.o

install:
	mv $(LIB).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o

