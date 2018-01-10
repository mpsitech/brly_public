#!/bin/bash
# file checkout.sh
# checkout script for Brly API library, release apibrly_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set SRCROOT=/Users/mpsitech/src

mkdir $SRCROOT/apibrly

cp makeall.sh $SRCROOT/apibrly/

cp Makefile $SRCROOT/apibrly/

cp ../../apibrly/*.h $SRCROOT/apibrly/
cp ../../apibrly/*.cpp $SRCROOT/apibrly/

