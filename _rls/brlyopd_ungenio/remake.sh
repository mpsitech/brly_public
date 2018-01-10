#!/bin/bash
# file remake.sh
# re-make script for Brly operation daemon, release brlyopd_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set SRCROOT=/Users/mpsitech/src
export set REPROOT=/Users/mpsitech/srcrep

cd $REPROOT/brly/_rls/brlyopd_ungenio
./checkout.sh

cd $SRCROOT/brlyopd

./make.sh "$@"

