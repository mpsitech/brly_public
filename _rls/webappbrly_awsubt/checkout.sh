#!/bin/bash
# file checkout.sh
# checkout script for Brly web-based UI, release webappbrly_awsubt
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

export set WEBROOT=/home/ubuntu/web

mkdir $WEBROOT/appbrly

cp checkin.sh $WEBROOT/appbrly/

cp -r ../../webappbrly/* $WEBROOT/appbrly/

