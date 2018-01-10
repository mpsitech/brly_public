/**
  * \file VecBrlyVReqitmode.cpp
  * vector VecBrlyVReqitmode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "VecBrlyVReqitmode.h"

/******************************************************************************
 namespace VecBrlyVReqitmode
 ******************************************************************************/

uint VecBrlyVReqitmode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "notify") return NOTIFY;
	else if (s == "poll") return POLL;

	return(0);
};

string VecBrlyVReqitmode::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == NOTIFY) return("notify");
	else if (ix == POLL) return("poll");

	return("");
};

