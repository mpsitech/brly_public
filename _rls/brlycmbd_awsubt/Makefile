# file Makefile
# make file for Brly combined daemon, release brlycmbd_awsubt
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DBRLYCMBD

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbsbrly -I$(SRCROOT)/brlycmbd/VecBrly -I$(SRCROOT)/brlycmbd/IexBrly -I$(SRCROOT)/brlycmbd
INCPATH += -I$(SRCROOT)/brlycmbd/CrdBrlyNav -I$(SRCROOT)/brlycmbd/CrdBrlyUsg -I$(SRCROOT)/brlycmbd/CrdBrlyUsr -I$(SRCROOT)/brlycmbd/CrdBrlyPrs -I$(SRCROOT)/brlycmbd/CrdBrlyFil -I$(SRCROOT)/brlycmbd/CrdBrlyOpr -I$(SRCROOT)/brlycmbd/CrdBrlyPty -I$(SRCROOT)/brlycmbd/CrdBrlyReg -I$(SRCROOT)/brlycmbd/CrdBrlyLoc -I$(SRCROOT)/brlycmbd/CrdBrlyLeg -I$(SRCROOT)/brlycmbd/CrdBrlyTtb -I$(SRCROOT)/brlycmbd/CrdBrlyFlt -I$(SRCROOT)/brlycmbd/CrdBrlySeg -I$(SRCROOT)/brlycmbd/CrdBrlyCon -I$(SRCROOT)/brlycmbd/CrdBrlyRly
INCPATH += -I$(SRCROOT)/brlycmbd/BrlyBase -I$(SRCROOT)/brlycmbd/BrlyDnsmap -I$(SRCROOT)/brlycmbd/BrlyDyn -I$(SRCROOT)/brlycmbd/BrlyMapgen -I$(SRCROOT)/brlycmbd/BrlyTtimp
INCPATH += -I/usr/include -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include

PCHS = Brlycmbd.h.gch

OBJS = Brly.o BrlycmbdAppsrv.o BrlycmbdJobprc.o BrlycmbdOpprc.o Brlycmbd.o
OBJS += RootBrly.o SessBrly.o
OBJS += Brlycmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlycmbd
LIBPATH += -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lcrdbrlynav -lcrdbrlyusg -lcrdbrlyusr -lcrdbrlyprs -lcrdbrlyfil -lcrdbrlyopr -lcrdbrlypty -lcrdbrlyreg -lcrdbrlyloc -lcrdbrlyleg -lcrdbrlyttb -lcrdbrlyflt -lcrdbrlyseg -lcrdbrlycon -lcrdbrlyrly
LIBS += -lbrlybase -lbrlydnsmap -lbrlydyn -lbrlymapgen -lbrlyttimp
LIBS += -liexbrly -lvecbrly -ldbsbrly
LIBS += -lmicrohttpd -lnetcdf -lsbecore_dbsmon -lsbecore_mon
LIBS += -ldbswzem -lhdf5_hl_cpp
LIBS += -lhdf5_cpp -lsbecore_lite -lsbecore_my -lsbecore_pg
LIBS += -lmysqlclient -lpq -lsbecore -lsqlite3
LIBS += -lxml2
LIBS += -lz
LIBS += -lpthread

EXE = Brlycmbd

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJS)
	$(LINK) $(LINKFLAGS) $(OBJS) $(LIBPATH) $(LIBS) -o $(EXE)
	rm -f *.o

pch:	$(PCHS)

install:
	mv $(EXE) $(BINROOT)/brlycmbd/

clean:
	rm -f *.gch
	rm -f *.o

