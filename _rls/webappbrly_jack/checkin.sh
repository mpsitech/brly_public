#!/bin/bash
# file checkin.sh
# checkin script for Brly web-based UI, release webappbrly_jack
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set REPROOT=/home/mpsitech/srcrep

cp -r * $REPROOT/brly/webappbrly/

rm $REPROOT/brly/webappbrly/checkin.sh

