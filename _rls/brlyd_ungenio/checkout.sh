#!/bin/bash
# file checkout.sh
# checkout script for Brly daemon, release brlyd_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set SRCROOT=/Users/mpsitech/src
export set LIBROOT=/Users/mpsitech/lib
export set BINROOT=/Users/mpsitech/bin
export set REPROOT=/Users/mpsitech/srcrep
export set CMBDSRCROOT=$REPROOT/brly/brlycmbd

mkdir $SRCROOT/brlyd
mkdir $SRCROOT/brlyd/IexBrly
mkdir $SRCROOT/brlyd/VecBrly
mkdir $SRCROOT/brlyd/CrdBrlyNav
mkdir $SRCROOT/brlyd/CrdBrlyUsg
mkdir $SRCROOT/brlyd/CrdBrlyUsr
mkdir $SRCROOT/brlyd/CrdBrlyPrs
mkdir $SRCROOT/brlyd/CrdBrlyFil
mkdir $SRCROOT/brlyd/CrdBrlyOpr
mkdir $SRCROOT/brlyd/CrdBrlyPty
mkdir $SRCROOT/brlyd/CrdBrlyReg
mkdir $SRCROOT/brlyd/CrdBrlyLoc
mkdir $SRCROOT/brlyd/CrdBrlyLeg
mkdir $SRCROOT/brlyd/CrdBrlyTtb
mkdir $SRCROOT/brlyd/CrdBrlyFlt
mkdir $SRCROOT/brlyd/CrdBrlySeg
mkdir $SRCROOT/brlyd/CrdBrlyCon
mkdir $SRCROOT/brlyd/CrdBrlyRly

mkdir $LIBROOT/brlyd

mkdir $BINROOT/brlyd

cp make.sh $SRCROOT/brlyd/
cp remake.sh $SRCROOT/brlyd/

cp Makefile.inc $SRCROOT/brlyd/
cp Makefile $SRCROOT/brlyd/

cp ../../brlyd/Brlyd.h $SRCROOT/brlyd/
cp ../../brlyd/Brlyd.cpp $SRCROOT/brlyd/

cp ../../brlyd/BrlydAppsrv.h $SRCROOT/brlyd/
cp ../../brlyd/BrlydAppsrv.cpp $SRCROOT/brlyd/

cp ../../brlyd/BrlydJobprc.h $SRCROOT/brlyd/
cp ../../brlyd/BrlydJobprc.cpp $SRCROOT/brlyd/

cp ../../brlyd/BrlydOpengconsrv.h $SRCROOT/brlyd/
cp ../../brlyd/BrlydOpengconsrv.cpp $SRCROOT/brlyd/

cp ../../brlyd/BrlydOpengcli.h $SRCROOT/brlyd/
cp ../../brlyd/BrlydOpengcli.cpp $SRCROOT/brlyd/

cp ../../brlyd/Brlyd_exe.h $SRCROOT/brlyd/
cp ../../brlyd/Brlyd_exe.cpp $SRCROOT/brlyd/

cp $CMBDSRCROOT/Brly.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/Brly.cpp $SRCROOT/brlyd/

cp $CMBDSRCROOT/Root*.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/Root*.cpp $SRCROOT/brlyd/

cp $CMBDSRCROOT/Sess*.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/Sess*.cpp $SRCROOT/brlyd/

cp $CMBDSRCROOT/gbl/*.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/gbl/*.cpp $SRCROOT/brlyd/

cp Makefile_IexBrly $SRCROOT/brlyd/IexBrly/Makefile

cp $CMBDSRCROOT/IexBrly/IexBrly*.h $SRCROOT/brlyd/IexBrly/
cp $CMBDSRCROOT/IexBrly/IexBrly*.cpp $SRCROOT/brlyd/IexBrly/

cp Makefile_VecBrly $SRCROOT/brlyd/VecBrly/Makefile

cp $CMBDSRCROOT/VecBrly/Vec*.h $SRCROOT/brlyd/VecBrly/
cp $CMBDSRCROOT/VecBrly/Vec*.cpp $SRCROOT/brlyd/VecBrly/

cp Makefile_CrdBrlyNav $SRCROOT/brlyd/CrdBrlyNav/Makefile

cp $CMBDSRCROOT/CrdBrlyNav/*.h $SRCROOT/brlyd/CrdBrlyNav/
cp $CMBDSRCROOT/CrdBrlyNav/*.cpp $SRCROOT/brlyd/CrdBrlyNav/

cp Makefile_CrdBrlyUsg $SRCROOT/brlyd/CrdBrlyUsg/Makefile

cp $CMBDSRCROOT/CrdBrlyUsg/*.h $SRCROOT/brlyd/CrdBrlyUsg/
cp $CMBDSRCROOT/CrdBrlyUsg/*.cpp $SRCROOT/brlyd/CrdBrlyUsg/

cp Makefile_CrdBrlyUsr $SRCROOT/brlyd/CrdBrlyUsr/Makefile

cp $CMBDSRCROOT/CrdBrlyUsr/*.h $SRCROOT/brlyd/CrdBrlyUsr/
cp $CMBDSRCROOT/CrdBrlyUsr/*.cpp $SRCROOT/brlyd/CrdBrlyUsr/

cp Makefile_CrdBrlyPrs $SRCROOT/brlyd/CrdBrlyPrs/Makefile

cp $CMBDSRCROOT/CrdBrlyPrs/*.h $SRCROOT/brlyd/CrdBrlyPrs/
cp $CMBDSRCROOT/CrdBrlyPrs/*.cpp $SRCROOT/brlyd/CrdBrlyPrs/

cp Makefile_CrdBrlyFil $SRCROOT/brlyd/CrdBrlyFil/Makefile

cp $CMBDSRCROOT/CrdBrlyFil/*.h $SRCROOT/brlyd/CrdBrlyFil/
cp $CMBDSRCROOT/CrdBrlyFil/*.cpp $SRCROOT/brlyd/CrdBrlyFil/

cp Makefile_CrdBrlyOpr $SRCROOT/brlyd/CrdBrlyOpr/Makefile

cp $CMBDSRCROOT/CrdBrlyOpr/*.h $SRCROOT/brlyd/CrdBrlyOpr/
cp $CMBDSRCROOT/CrdBrlyOpr/*.cpp $SRCROOT/brlyd/CrdBrlyOpr/

cp Makefile_CrdBrlyPty $SRCROOT/brlyd/CrdBrlyPty/Makefile

cp $CMBDSRCROOT/CrdBrlyPty/*.h $SRCROOT/brlyd/CrdBrlyPty/
cp $CMBDSRCROOT/CrdBrlyPty/*.cpp $SRCROOT/brlyd/CrdBrlyPty/

cp Makefile_CrdBrlyReg $SRCROOT/brlyd/CrdBrlyReg/Makefile

cp $CMBDSRCROOT/CrdBrlyReg/*.h $SRCROOT/brlyd/CrdBrlyReg/
cp $CMBDSRCROOT/CrdBrlyReg/*.cpp $SRCROOT/brlyd/CrdBrlyReg/

cp Makefile_CrdBrlyLoc $SRCROOT/brlyd/CrdBrlyLoc/Makefile

cp $CMBDSRCROOT/CrdBrlyLoc/*.h $SRCROOT/brlyd/CrdBrlyLoc/
cp $CMBDSRCROOT/CrdBrlyLoc/*.cpp $SRCROOT/brlyd/CrdBrlyLoc/

cp Makefile_CrdBrlyLeg $SRCROOT/brlyd/CrdBrlyLeg/Makefile

cp $CMBDSRCROOT/CrdBrlyLeg/*.h $SRCROOT/brlyd/CrdBrlyLeg/
cp $CMBDSRCROOT/CrdBrlyLeg/*.cpp $SRCROOT/brlyd/CrdBrlyLeg/

cp Makefile_CrdBrlyTtb $SRCROOT/brlyd/CrdBrlyTtb/Makefile

cp $CMBDSRCROOT/CrdBrlyTtb/*.h $SRCROOT/brlyd/CrdBrlyTtb/
cp $CMBDSRCROOT/CrdBrlyTtb/*.cpp $SRCROOT/brlyd/CrdBrlyTtb/

cp Makefile_CrdBrlyFlt $SRCROOT/brlyd/CrdBrlyFlt/Makefile

cp $CMBDSRCROOT/CrdBrlyFlt/*.h $SRCROOT/brlyd/CrdBrlyFlt/
cp $CMBDSRCROOT/CrdBrlyFlt/*.cpp $SRCROOT/brlyd/CrdBrlyFlt/

cp Makefile_CrdBrlySeg $SRCROOT/brlyd/CrdBrlySeg/Makefile

cp $CMBDSRCROOT/CrdBrlySeg/*.h $SRCROOT/brlyd/CrdBrlySeg/
cp $CMBDSRCROOT/CrdBrlySeg/*.cpp $SRCROOT/brlyd/CrdBrlySeg/

cp Makefile_CrdBrlyCon $SRCROOT/brlyd/CrdBrlyCon/Makefile

cp $CMBDSRCROOT/CrdBrlyCon/*.h $SRCROOT/brlyd/CrdBrlyCon/
cp $CMBDSRCROOT/CrdBrlyCon/*.cpp $SRCROOT/brlyd/CrdBrlyCon/

cp Makefile_CrdBrlyRly $SRCROOT/brlyd/CrdBrlyRly/Makefile

cp $CMBDSRCROOT/CrdBrlyRly/*.h $SRCROOT/brlyd/CrdBrlyRly/
cp $CMBDSRCROOT/CrdBrlyRly/*.cpp $SRCROOT/brlyd/CrdBrlyRly/

cp $CMBDSRCROOT/BrlyBase/BrlyBase_blks.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyBase/BrlyBase_blks.cpp $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyBase/SqkBrlyBase.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyBase/SqkBrlyBase.cpp $SRCROOT/brlyd/

cp $CMBDSRCROOT/BrlyDnsmap/BrlyDnsmap_blks.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyDnsmap/BrlyDnsmap_blks.cpp $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyDnsmap/SqkBrlyDnsmap.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyDnsmap/SqkBrlyDnsmap.cpp $SRCROOT/brlyd/

cp $CMBDSRCROOT/BrlyDyn/BrlyDyn_blks.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyDyn/BrlyDyn_blks.cpp $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyDyn/SqkBrlyDyn.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyDyn/SqkBrlyDyn.cpp $SRCROOT/brlyd/

cp $CMBDSRCROOT/BrlyMapgen/BrlyMapgen_blks.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyMapgen/BrlyMapgen_blks.cpp $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyMapgen/SqkBrlyMapgen.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyMapgen/SqkBrlyMapgen.cpp $SRCROOT/brlyd/

cp $CMBDSRCROOT/BrlyTtimp/BrlyTtimp_blks.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyTtimp/BrlyTtimp_blks.cpp $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyTtimp/SqkBrlyTtimp.h $SRCROOT/brlyd/
cp $CMBDSRCROOT/BrlyTtimp/SqkBrlyTtimp.cpp $SRCROOT/brlyd/

