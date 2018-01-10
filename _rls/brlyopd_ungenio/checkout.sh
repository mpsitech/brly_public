#!/bin/bash
# file checkout.sh
# checkout script for Brly operation daemon, release brlyopd_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set SRCROOT=/Users/mpsitech/src
export set LIBROOT=/Users/mpsitech/lib
export set BINROOT=/Users/mpsitech/bin
export set REPROOT=/Users/mpsitech/srcrep
export set CMBDSRCROOT=$REPROOT/brly/brlycmbd

mkdir $SRCROOT/brlyopd
mkdir $SRCROOT/brlyopd/VecBrly
mkdir $SRCROOT/brlyopd/BrlyBase
mkdir $SRCROOT/brlyopd/BrlyDnsmap
mkdir $SRCROOT/brlyopd/BrlyDyn
mkdir $SRCROOT/brlyopd/BrlyMapgen
mkdir $SRCROOT/brlyopd/BrlyTtimp

mkdir $LIBROOT/brlyopd

mkdir $BINROOT/brlyopd

cp make.sh $SRCROOT/brlyopd/
cp remake.sh $SRCROOT/brlyopd/

cp Makefile.inc $SRCROOT/brlyopd/
cp Makefile $SRCROOT/brlyopd/

cp ../../brlyopd/Brlyopd.h $SRCROOT/brlyopd/
cp ../../brlyopd/Brlyopd.cpp $SRCROOT/brlyopd/

cp ../../brlyopd/BrlyopdEngsrv.h $SRCROOT/brlyopd/
cp ../../brlyopd/BrlyopdEngsrv.cpp $SRCROOT/brlyopd/

cp ../../brlyopd/BrlyopdOpprc.h $SRCROOT/brlyopd/
cp ../../brlyopd/BrlyopdOpprc.cpp $SRCROOT/brlyopd/

cp ../../brlyopd/Brlyopd_exe.h $SRCROOT/brlyopd/
cp ../../brlyopd/Brlyopd_exe.cpp $SRCROOT/brlyopd/

cp $CMBDSRCROOT/Brly.h $SRCROOT/brlyopd/
cp $CMBDSRCROOT/Brly.cpp $SRCROOT/brlyopd/

cp Makefile_VecBrly $SRCROOT/brlyopd/VecBrly/Makefile

cp $CMBDSRCROOT/VecBrly/Vec*.h $SRCROOT/brlyopd/VecBrly/
cp $CMBDSRCROOT/VecBrly/Vec*.cpp $SRCROOT/brlyopd/VecBrly/

cp Makefile_BrlyBase $SRCROOT/brlyopd/BrlyBase/Makefile

cp $CMBDSRCROOT/BrlyBase/BrlyBase*.h $SRCROOT/brlyopd/BrlyBase/
cp $CMBDSRCROOT/BrlyBase/BrlyBase*.cpp $SRCROOT/brlyopd/BrlyBase/

cp Makefile_BrlyDnsmap $SRCROOT/brlyopd/BrlyDnsmap/Makefile

cp $CMBDSRCROOT/BrlyDnsmap/BrlyDnsmap*.h $SRCROOT/brlyopd/BrlyDnsmap/
cp $CMBDSRCROOT/BrlyDnsmap/BrlyDnsmap*.cpp $SRCROOT/brlyopd/BrlyDnsmap/

cp Makefile_BrlyDyn $SRCROOT/brlyopd/BrlyDyn/Makefile

cp $CMBDSRCROOT/BrlyDyn/BrlyDyn*.h $SRCROOT/brlyopd/BrlyDyn/
cp $CMBDSRCROOT/BrlyDyn/BrlyDyn*.cpp $SRCROOT/brlyopd/BrlyDyn/

cp Makefile_BrlyMapgen $SRCROOT/brlyopd/BrlyMapgen/Makefile

cp $CMBDSRCROOT/BrlyMapgen/BrlyMapgen*.h $SRCROOT/brlyopd/BrlyMapgen/
cp $CMBDSRCROOT/BrlyMapgen/BrlyMapgen*.cpp $SRCROOT/brlyopd/BrlyMapgen/

cp Makefile_BrlyTtimp $SRCROOT/brlyopd/BrlyTtimp/Makefile

cp $CMBDSRCROOT/BrlyTtimp/BrlyTtimp*.h $SRCROOT/brlyopd/BrlyTtimp/
cp $CMBDSRCROOT/BrlyTtimp/BrlyTtimp*.cpp $SRCROOT/brlyopd/BrlyTtimp/

