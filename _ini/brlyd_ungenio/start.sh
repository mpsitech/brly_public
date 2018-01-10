#!/bin/bash
# file start.sh
# start script for Brly daemon, release brlyd_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

nohup ./Brlyd -nocp &
disown

