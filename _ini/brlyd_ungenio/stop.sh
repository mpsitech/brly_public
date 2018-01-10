#!/bin/bash
# file stop.sh
# stop script for Brly daemon, release brlyd_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

pid=$(pgrep Brlyd)
kill -15 $pid

