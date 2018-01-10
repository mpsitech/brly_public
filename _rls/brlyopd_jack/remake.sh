#!/bin/bash
# file remake.sh
# re-make script for Brly operation daemon, release brlyopd_jack
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/brly/_rls/brlyopd_jack
./checkout.sh

cd $SRCROOT/brlyopd

./make.sh "$@"

