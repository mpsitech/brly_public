#!/bin/bash
# file make.sh
# make script for Brly combined daemon, release brlycmbd_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

make Brlycmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexBrly" "VecBrly" "CrdBrlyNav" "CrdBrlyUsg" "CrdBrlyUsr" "CrdBrlyPrs" "CrdBrlyFil" "CrdBrlyOpr" "CrdBrlyPty" "CrdBrlyReg" "CrdBrlyLoc" "CrdBrlyLeg" "CrdBrlyTtb" "CrdBrlyFlt" "CrdBrlySeg" "CrdBrlyCon" "CrdBrlyRly" "BrlyBase" "BrlyDnsmap" "BrlyDyn" "BrlyMapgen" "BrlyTtimp")
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

rm Brlycmbd.h.gch

