#!/bin/bash
# file remake.sh
# re-make script for Brly daemon, release brlyd_jack
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/brly/_rls/brlyd_jack
./checkout.sh

cd $SRCROOT/brlyd

./make.sh "$@"

