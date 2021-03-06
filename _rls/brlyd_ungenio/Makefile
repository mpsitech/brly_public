# file Makefile
# make file for Brly daemon, release brlyd_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DBRLYD

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbsbrly -I$(SRCROOT)/brlyd/VecBrly -I$(SRCROOT)/brlyd/IexBrly -I$(SRCROOT)/brlyd
INCPATH += -I$(SRCROOT)/brlyd/CrdBrlyNav -I$(SRCROOT)/brlyd/CrdBrlyUsg -I$(SRCROOT)/brlyd/CrdBrlyUsr -I$(SRCROOT)/brlyd/CrdBrlyPrs -I$(SRCROOT)/brlyd/CrdBrlyFil -I$(SRCROOT)/brlyd/CrdBrlyOpr -I$(SRCROOT)/brlyd/CrdBrlyPty -I$(SRCROOT)/brlyd/CrdBrlyReg -I$(SRCROOT)/brlyd/CrdBrlyLoc -I$(SRCROOT)/brlyd/CrdBrlyLeg -I$(SRCROOT)/brlyd/CrdBrlyTtb -I$(SRCROOT)/brlyd/CrdBrlyFlt -I$(SRCROOT)/brlyd/CrdBrlySeg -I$(SRCROOT)/brlyd/CrdBrlyCon -I$(SRCROOT)/brlyd/CrdBrlyRly
INCPATH += -I/Library/PostgreSQL/9.6/include -I/usr/include -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include -I/usr/local/opt/sqlite/include

PCHS = Brlyd.h.gch

OBJS = Brly.o BrlydAppsrv.o BrlydJobprc.o BrlydOpengcli.o BrlydOpengconsrv.o Brlyd.o
OBJS += BrlyBase_blks.o SqkBrlyBase.o BrlyDnsmap_blks.o SqkBrlyDnsmap.o BrlyDyn_blks.o SqkBrlyDyn.o BrlyMapgen_blks.o SqkBrlyMapgen.o BrlyTtimp_blks.o SqkBrlyTtimp.o
OBJS += RootBrly.o SessBrly.o
OBJS += Brlyd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlyd
LIBPATH += -L/Library/PostgreSQL/9.6/lib -L/usr/include -L/usr/local/lib -L/usr/local/mysql/lib -L/usr/local/opt/sqlite/lib
LIBPATH += 

LIBS = -lcrdbrlynav -lcrdbrlyusg -lcrdbrlyusr -lcrdbrlyprs -lcrdbrlyfil -lcrdbrlyopr -lcrdbrlypty -lcrdbrlyreg -lcrdbrlyloc -lcrdbrlyleg -lcrdbrlyttb -lcrdbrlyflt -lcrdbrlyseg -lcrdbrlycon -lcrdbrlyrly
LIBS += -liexbrly -lvecbrly -ldbsbrly
LIBS += -lcurl -lmicrohttpd -lnetcdf -lsbecore_dbsmon -lsbecore_mon
LIBS += -ldbswzem -lhdf5_hl
LIBS += -lhdf5 -lsbecore_lite -lsbecore_my -lsbecore_pg
LIBS += -lmysqlclient -lpq -lsbecore -lsqlite3
LIBS += -lxml2
LIBS += -lz
LIBS += 

EXE = Brlyd

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
	mv $(EXE) $(BINROOT)/brlyd/

clean:
	rm -f *.gch
	rm -f *.o

