#!/bin/bash
# file checkout.sh
# checkout script for Brly combined daemon, release brlycmbd_jack
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set SRCROOT=/home/mpsitech/src
export set LIBROOT=/home/mpsitech/lib
export set BINROOT=/home/mpsitech/bin

mkdir $SRCROOT/brlycmbd
mkdir $SRCROOT/brlycmbd/IexBrly
mkdir $SRCROOT/brlycmbd/VecBrly
mkdir $SRCROOT/brlycmbd/CrdBrlyNav
mkdir $SRCROOT/brlycmbd/CrdBrlyUsg
mkdir $SRCROOT/brlycmbd/CrdBrlyUsr
mkdir $SRCROOT/brlycmbd/CrdBrlyPrs
mkdir $SRCROOT/brlycmbd/CrdBrlyFil
mkdir $SRCROOT/brlycmbd/CrdBrlyOpr
mkdir $SRCROOT/brlycmbd/CrdBrlyPty
mkdir $SRCROOT/brlycmbd/CrdBrlyReg
mkdir $SRCROOT/brlycmbd/CrdBrlyLoc
mkdir $SRCROOT/brlycmbd/CrdBrlyLeg
mkdir $SRCROOT/brlycmbd/CrdBrlyTtb
mkdir $SRCROOT/brlycmbd/CrdBrlyFlt
mkdir $SRCROOT/brlycmbd/CrdBrlySeg
mkdir $SRCROOT/brlycmbd/CrdBrlyCon
mkdir $SRCROOT/brlycmbd/CrdBrlyRly
mkdir $SRCROOT/brlycmbd/BrlyBase
mkdir $SRCROOT/brlycmbd/BrlyDnsmap
mkdir $SRCROOT/brlycmbd/BrlyDyn
mkdir $SRCROOT/brlycmbd/BrlyMapgen
mkdir $SRCROOT/brlycmbd/BrlyTtimp

mkdir $LIBROOT/brlycmbd

mkdir $BINROOT/brlycmbd

cp make.sh $SRCROOT/brlycmbd/
cp remake.sh $SRCROOT/brlycmbd/

cp Makefile.inc $SRCROOT/brlycmbd/
cp Makefile $SRCROOT/brlycmbd/

cp ../../brlycmbd/Brlycmbd.h $SRCROOT/brlycmbd/
cp ../../brlycmbd/Brlycmbd.cpp $SRCROOT/brlycmbd/

cp ../../brlycmbd/BrlycmbdAppsrv.h $SRCROOT/brlycmbd/
cp ../../brlycmbd/BrlycmbdAppsrv.cpp $SRCROOT/brlycmbd/

cp ../../brlycmbd/BrlycmbdJobprc.h $SRCROOT/brlycmbd/
cp ../../brlycmbd/BrlycmbdJobprc.cpp $SRCROOT/brlycmbd/

cp ../../brlycmbd/BrlycmbdOpprc.h $SRCROOT/brlycmbd/
cp ../../brlycmbd/BrlycmbdOpprc.cpp $SRCROOT/brlycmbd/

cp ../../brlycmbd/Brlycmbd_exe.h $SRCROOT/brlycmbd/
cp ../../brlycmbd/Brlycmbd_exe.cpp $SRCROOT/brlycmbd/

cp ../../brlycmbd/Brly.h $SRCROOT/brlycmbd/
cp ../../brlycmbd/Brly.cpp $SRCROOT/brlycmbd/

cp ../../brlycmbd/Root*.h $SRCROOT/brlycmbd/
cp ../../brlycmbd/Root*.cpp $SRCROOT/brlycmbd/

cp ../../brlycmbd/Sess*.h $SRCROOT/brlycmbd/
cp ../../brlycmbd/Sess*.cpp $SRCROOT/brlycmbd/

cp ../../brlycmbd/gbl/*.h $SRCROOT/brlycmbd/
cp ../../brlycmbd/gbl/*.cpp $SRCROOT/brlycmbd/

cp Makefile_IexBrly $SRCROOT/brlycmbd/IexBrly/Makefile

cp ../../brlycmbd/IexBrly/IexBrly*.h $SRCROOT/brlycmbd/IexBrly/
cp ../../brlycmbd/IexBrly/IexBrly*.cpp $SRCROOT/brlycmbd/IexBrly/

cp Makefile_VecBrly $SRCROOT/brlycmbd/VecBrly/Makefile

cp ../../brlycmbd/VecBrly/Vec*.h $SRCROOT/brlycmbd/VecBrly/
cp ../../brlycmbd/VecBrly/Vec*.cpp $SRCROOT/brlycmbd/VecBrly/

cp Makefile_CrdBrlyNav $SRCROOT/brlycmbd/CrdBrlyNav/Makefile

cp ../../brlycmbd/CrdBrlyNav/*.h $SRCROOT/brlycmbd/CrdBrlyNav/
cp ../../brlycmbd/CrdBrlyNav/*.cpp $SRCROOT/brlycmbd/CrdBrlyNav/

cp Makefile_CrdBrlyUsg $SRCROOT/brlycmbd/CrdBrlyUsg/Makefile

cp ../../brlycmbd/CrdBrlyUsg/*.h $SRCROOT/brlycmbd/CrdBrlyUsg/
cp ../../brlycmbd/CrdBrlyUsg/*.cpp $SRCROOT/brlycmbd/CrdBrlyUsg/

cp Makefile_CrdBrlyUsr $SRCROOT/brlycmbd/CrdBrlyUsr/Makefile

cp ../../brlycmbd/CrdBrlyUsr/*.h $SRCROOT/brlycmbd/CrdBrlyUsr/
cp ../../brlycmbd/CrdBrlyUsr/*.cpp $SRCROOT/brlycmbd/CrdBrlyUsr/

cp Makefile_CrdBrlyPrs $SRCROOT/brlycmbd/CrdBrlyPrs/Makefile

cp ../../brlycmbd/CrdBrlyPrs/*.h $SRCROOT/brlycmbd/CrdBrlyPrs/
cp ../../brlycmbd/CrdBrlyPrs/*.cpp $SRCROOT/brlycmbd/CrdBrlyPrs/

cp Makefile_CrdBrlyFil $SRCROOT/brlycmbd/CrdBrlyFil/Makefile

cp ../../brlycmbd/CrdBrlyFil/*.h $SRCROOT/brlycmbd/CrdBrlyFil/
cp ../../brlycmbd/CrdBrlyFil/*.cpp $SRCROOT/brlycmbd/CrdBrlyFil/

cp Makefile_CrdBrlyOpr $SRCROOT/brlycmbd/CrdBrlyOpr/Makefile

cp ../../brlycmbd/CrdBrlyOpr/*.h $SRCROOT/brlycmbd/CrdBrlyOpr/
cp ../../brlycmbd/CrdBrlyOpr/*.cpp $SRCROOT/brlycmbd/CrdBrlyOpr/

cp Makefile_CrdBrlyPty $SRCROOT/brlycmbd/CrdBrlyPty/Makefile

cp ../../brlycmbd/CrdBrlyPty/*.h $SRCROOT/brlycmbd/CrdBrlyPty/
cp ../../brlycmbd/CrdBrlyPty/*.cpp $SRCROOT/brlycmbd/CrdBrlyPty/

cp Makefile_CrdBrlyReg $SRCROOT/brlycmbd/CrdBrlyReg/Makefile

cp ../../brlycmbd/CrdBrlyReg/*.h $SRCROOT/brlycmbd/CrdBrlyReg/
cp ../../brlycmbd/CrdBrlyReg/*.cpp $SRCROOT/brlycmbd/CrdBrlyReg/

cp Makefile_CrdBrlyLoc $SRCROOT/brlycmbd/CrdBrlyLoc/Makefile

cp ../../brlycmbd/CrdBrlyLoc/*.h $SRCROOT/brlycmbd/CrdBrlyLoc/
cp ../../brlycmbd/CrdBrlyLoc/*.cpp $SRCROOT/brlycmbd/CrdBrlyLoc/

cp Makefile_CrdBrlyLeg $SRCROOT/brlycmbd/CrdBrlyLeg/Makefile

cp ../../brlycmbd/CrdBrlyLeg/*.h $SRCROOT/brlycmbd/CrdBrlyLeg/
cp ../../brlycmbd/CrdBrlyLeg/*.cpp $SRCROOT/brlycmbd/CrdBrlyLeg/

cp Makefile_CrdBrlyTtb $SRCROOT/brlycmbd/CrdBrlyTtb/Makefile

cp ../../brlycmbd/CrdBrlyTtb/*.h $SRCROOT/brlycmbd/CrdBrlyTtb/
cp ../../brlycmbd/CrdBrlyTtb/*.cpp $SRCROOT/brlycmbd/CrdBrlyTtb/

cp Makefile_CrdBrlyFlt $SRCROOT/brlycmbd/CrdBrlyFlt/Makefile

cp ../../brlycmbd/CrdBrlyFlt/*.h $SRCROOT/brlycmbd/CrdBrlyFlt/
cp ../../brlycmbd/CrdBrlyFlt/*.cpp $SRCROOT/brlycmbd/CrdBrlyFlt/

cp Makefile_CrdBrlySeg $SRCROOT/brlycmbd/CrdBrlySeg/Makefile

cp ../../brlycmbd/CrdBrlySeg/*.h $SRCROOT/brlycmbd/CrdBrlySeg/
cp ../../brlycmbd/CrdBrlySeg/*.cpp $SRCROOT/brlycmbd/CrdBrlySeg/

cp Makefile_CrdBrlyCon $SRCROOT/brlycmbd/CrdBrlyCon/Makefile

cp ../../brlycmbd/CrdBrlyCon/*.h $SRCROOT/brlycmbd/CrdBrlyCon/
cp ../../brlycmbd/CrdBrlyCon/*.cpp $SRCROOT/brlycmbd/CrdBrlyCon/

cp Makefile_CrdBrlyRly $SRCROOT/brlycmbd/CrdBrlyRly/Makefile

cp ../../brlycmbd/CrdBrlyRly/*.h $SRCROOT/brlycmbd/CrdBrlyRly/
cp ../../brlycmbd/CrdBrlyRly/*.cpp $SRCROOT/brlycmbd/CrdBrlyRly/

cp Makefile_BrlyBase $SRCROOT/brlycmbd/BrlyBase/Makefile

cp ../../brlycmbd/BrlyBase/*.h $SRCROOT/brlycmbd/BrlyBase/
cp ../../brlycmbd/BrlyBase/*.cpp $SRCROOT/brlycmbd/BrlyBase/

cp Makefile_BrlyDnsmap $SRCROOT/brlycmbd/BrlyDnsmap/Makefile

cp ../../brlycmbd/BrlyDnsmap/*.h $SRCROOT/brlycmbd/BrlyDnsmap/
cp ../../brlycmbd/BrlyDnsmap/*.cpp $SRCROOT/brlycmbd/BrlyDnsmap/

cp Makefile_BrlyDyn $SRCROOT/brlycmbd/BrlyDyn/Makefile

cp ../../brlycmbd/BrlyDyn/*.h $SRCROOT/brlycmbd/BrlyDyn/
cp ../../brlycmbd/BrlyDyn/*.cpp $SRCROOT/brlycmbd/BrlyDyn/

cp Makefile_BrlyMapgen $SRCROOT/brlycmbd/BrlyMapgen/Makefile

cp ../../brlycmbd/BrlyMapgen/*.h $SRCROOT/brlycmbd/BrlyMapgen/
cp ../../brlycmbd/BrlyMapgen/*.cpp $SRCROOT/brlycmbd/BrlyMapgen/

cp Makefile_BrlyTtimp $SRCROOT/brlycmbd/BrlyTtimp/Makefile

cp ../../brlycmbd/BrlyTtimp/*.h $SRCROOT/brlycmbd/BrlyTtimp/
cp ../../brlycmbd/BrlyTtimp/*.cpp $SRCROOT/brlycmbd/BrlyTtimp/

