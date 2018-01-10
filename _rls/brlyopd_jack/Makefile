# file Makefile
# make file for Brly operation daemon, release brlyopd_jack
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
INCPATH += -I/usr/include -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include

PCHS = Brlyopd.h.gch

OBJS = Brly.o BrlyopdEngsrv.o BrlyopdOpprc.o Brlyopd.o
OBJS += Brlyopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlyopd
LIBPATH += -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lbrlybase -lbrlydnsmap -lbrlydyn -lbrlymapgen -lbrlyttimp
LIBS += -lvecbrly -ldbsbrly
LIBS += -lcurl -lmicrohttpd -lnetcdf -lsbecore_my -lsbecore_pg
LIBS += -lhdf5_hl_cpp -lmysqlclient -lpq -lsbecore
LIBS += -lhdf5_cpp -lxml2
LIBS += -lz
LIBS += -lpthread

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

