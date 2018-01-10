#!/bin/bash
# file stopall.sh
# stop script for Brly operation daemon(s), release brlyopd_jack
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

IFS=$'\n'
pids=$(pgrep Brlyopd)

for var in "${pids[@]}"
do
	kill -15 $var
done

