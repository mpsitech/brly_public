#!/bin/bash
# file checkout.sh
# checkout script for Brly database access library, release dbsbrly_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set SRCROOT=/Users/mpsitech/src

mkdir $SRCROOT/dbsbrly

cp makeall.sh $SRCROOT/dbsbrly/

cp Makefile $SRCROOT/dbsbrly/

cp ../../dbsbrly/DbsBrly.h $SRCROOT/dbsbrly/
cp ../../dbsbrly/DbsBrly_vecs.cpp $SRCROOT/dbsbrly/
cp ../../dbsbrly/DbsBrly.cpp $SRCROOT/dbsbrly/

cp ../../dbsbrly/Brly*.h $SRCROOT/dbsbrly/
cp ../../dbsbrly/Brly*.cpp $SRCROOT/dbsbrly/

