#!/bin/bash
# file start.sh
# start script for Brly operation daemon(s), release brlyopd_jack
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

num='^[0-9]+$'

if [ "$#" -eq 0 ] ; then
	nohup ./Brlyopd &
	disown
elif [ "$#" -eq 1 ] && [[ "$1" =~ $num ]] ; then
	i=0

	while [ $i -lt "$1" ]
	do
		nohup ./Brlyopd -engsrvportofs=$i &
		i=`expr $i + 1`
	done

	disown
else
  echo "usage: $0 <N>" >&2
  exit 1
fi

