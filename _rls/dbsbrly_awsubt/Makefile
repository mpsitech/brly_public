# file Makefile
# make file for Brly database access library, release dbsbrly_awsubt
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

LIBROOT = /home/ubuntu/lib

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

STATLIB = ar
STATLIBFLAGS = rcs

INCPATH = -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include

PCHS = DbsBrly.h.gch

OBJS = DbsBrly.o
OBJS += BrlyAccRMUserUniversal.o BrlyAMFaflightWaypoint.o BrlyAMPersonDetail.o BrlyAMRegionDstswitch.o BrlyAMUserAccess.o BrlyAMUsergroupAccess.o BrlyAVControlPar.o BrlyAVKeylistKey.o BrlyAVValuelistVal.o BrlyCFile.o BrlyCLeg.o BrlyHistRMUserUniversal.o BrlyJAVKeylistKey.o BrlyJMPersonLastname.o BrlyJMRegion.o BrlyJMRegionTitle.o BrlyJMUserState.o BrlyLRMConnectionMEquipment.o BrlyMConnection.o BrlyMEquipment.o BrlyMFaflight.o BrlyMFile.o BrlyMFlight.o BrlyMLeg.o BrlyMLocation.o BrlyMNode.o BrlyMOperator.o BrlyMPerson.o BrlyMPlntype.o BrlyMRegion.o BrlyMRelay.o BrlyMSegment.o BrlyMSession.o BrlyMTimetable.o BrlyMUser.o BrlyMUsergroup.o BrlyORMConnectionMEquipment.o BrlyProxRMLocationMLocation.o BrlyRMConnectionMFlight.o BrlyRMConnectionMSegment.o BrlyRMFlightMFlight.o BrlyRMFlightMLocation.o BrlyRMLegMLeg.o BrlyRMLegMLocation.o BrlyRMLocationMSegment.o BrlyRMSegmentMSegment.o BrlyRMUsergroupUniversal.o BrlyRMUserMUsergroup.o BrlyVisRMLocationMLocation.o
OBJS += BrlyQCon1NRelay.o BrlyQConConMNEquipment.o BrlyQConList.o BrlyQConMapFlight.o BrlyQConMapLeg.o BrlyQConMapLocation.o BrlyQConMapNode.o BrlyQConMapRelay.o BrlyQConMNFlight.o BrlyQConMNSegment.o BrlyQConRef1NSegment.o BrlyQFilList.o BrlyQFlt1NConnection.o BrlyQFltEqp1NNode.o BrlyQFltEqpMNConnection.o BrlyQFltFafAWaypoint.o BrlyQFltList.o BrlyQFltMNConnection.o BrlyQFltMNLocation.o BrlyQFltOrgMNFlight.o BrlyQFltRef1NSegment.o BrlyQLeg1NFlight.o BrlyQLegCor1NConnection.o BrlyQLegList.o BrlyQLegMapLeg.o BrlyQLegMapLocation.o BrlyQLegMNLocation.o BrlyQLegOrgMNLeg.o BrlyQLocBgn1NLeg.o BrlyQLocEnd1NLeg.o BrlyQLocEqp1NNode.o BrlyQLocEqpMNConnection.o BrlyQLocList.o BrlyQLocMapLeg.o BrlyQLocMapProxLocation.o BrlyQLocMapVisLocation.o BrlyQLocMNFlight.o BrlyQLocMNLeg.o BrlyQLocMNSegment.o BrlyQLocProxOrgMNLocation.o BrlyQLocVisOrgMNLocation.o BrlyQOpr1NEquipment.o BrlyQOprList.o BrlyQPreselect.o BrlyQPrsADetail.o BrlyQPrsList.o BrlyQPty1NEquipment.o BrlyQPtyList.o BrlyQReg1NLocation.o BrlyQRegADstswitch.o BrlyQRegList.o BrlyQRegSup1NRegion.o BrlyQRly1NNode.o BrlyQRlyList.o BrlyQSegList.o BrlyQSegMNConnection.o BrlyQSegMNLocation.o BrlyQSegOrgMNSegment.o BrlyQSelect.o BrlyQTtb1NFlight.o BrlyQTtbList.o BrlyQTtbRef1NFile.o BrlyQUsgAAccess.o BrlyQUsgList.o BrlyQUsgMNUser.o BrlyQUsr1NSession.o BrlyQUsrAAccess.o BrlyQUsrList.o BrlyQUsrMNUsergroup.o

LIB = libdbsbrly

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

