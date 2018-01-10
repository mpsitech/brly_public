#!/bin/bash
# file remake.sh
# re-make script for Brly combined daemon, release brlycmbd_awsubt
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set SRCROOT=/home/ubuntu/src
export set REPROOT=/home/ubuntu/srcrep

cd $REPROOT/brly/_rls/brlycmbd_awsubt
./checkout.sh

cd $SRCROOT/brlycmbd

./make.sh "$@"

