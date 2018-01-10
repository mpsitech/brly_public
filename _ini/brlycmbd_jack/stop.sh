#!/bin/bash
# file stop.sh
# stop script for Brly combined daemon, release brlycmbd_jack
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

pid=$(pgrep Brlycmbd)
kill -15 $pid

