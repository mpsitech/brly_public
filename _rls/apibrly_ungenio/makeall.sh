#!/bin/bash
# file makeall.sh
# make script for Brly API library, release apibrly_ungenio
# author Alexander Wirthmueller
# date created: 8 Jan 2018
# modified: 8 Jan 2018

make ApiBrly.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

