#!/bin/bash
# file checkin.sh
# checkin script for Brly web-based UI, release webappbrly_awsubt
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set REPROOT=/home/ubuntu/srcrep

cp -r * $REPROOT/brly/webappbrly/

rm $REPROOT/brly/webappbrly/checkin.sh

