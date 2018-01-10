#!/bin/bash
# file make.sh
# make script for Brly operation daemon, release brlyopd_awsubt
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

make Brlyopd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("VecBrly" "BrlyBase" "BrlyDnsmap" "BrlyDyn" "BrlyMapgen" "BrlyTtimp")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j2
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Brlyopd.h.gch

