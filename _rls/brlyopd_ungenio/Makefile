# file Makefile
# make file for Brly operation daemon, release brlyopd_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbsbrly -I$(SRCROOT)/brlyopd/VecBrly -I$(SRCROOT)/brlyopd
INCPATH += -I$(SRCROOT)/brlyopd/BrlyBase -I$(SRCROOT)/brlyopd/BrlyDnsmap -I$(SRCROOT)/brlyopd/BrlyDyn -I$(SRCROOT)/brlyopd/BrlyMapgen -I$(SRCROOT)/brlyopd/BrlyTtimp
INCPATH += -I/Library/PostgreSQL/9.6/include -I/usr/include -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include

PCHS = Brlyopd.h.gch

OBJS = Brly.o BrlyopdEngsrv.o BrlyopdOpprc.o Brlyopd.o
OBJS += Brlyopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlyopd
LIBPATH += -L/Library/PostgreSQL/9.6/lib -L/usr/include -L/usr/local/lib -L/usr/local/mysql/lib
LIBPATH += 

LIBS = -lbrlybase -lbrlydnsmap -lbrlydyn -lbrlymapgen -lbrlyttimp
LIBS += -lvecbrly -ldbsbrly
LIBS += -lcurl -lmicrohttpd -lnetcdf -lsbecore_my -lsbecore_pg
LIBS += -lhdf5_hl -lmysqlclient -lpq -lsbecore
LIBS += -lhdf5 -lxml2
LIBS += -lz
LIBS += 

EXE = Brlyopd

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
	mv $(EXE) $(BINROOT)/brlyopd/

clean:
	rm -f *.gch
	rm -f *.o

