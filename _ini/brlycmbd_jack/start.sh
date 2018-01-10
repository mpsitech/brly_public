#!/bin/bash
# file start.sh
# start script for Brly combined daemon, release brlycmbd_jack
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

nohup ./Brlycmbd -nocp &
disown

