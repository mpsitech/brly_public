#!/bin/bash
# file remake.sh
# re-make script for Brly daemon, release brlyd_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set SRCROOT=/Users/mpsitech/src
export set REPROOT=/Users/mpsitech/srcrep

cd $REPROOT/brly/_rls/brlyd_ungenio
./checkout.sh

cd $SRCROOT/brlyd

./make.sh "$@"

