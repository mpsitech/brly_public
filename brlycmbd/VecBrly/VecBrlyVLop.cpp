/**
  * \file VecBrlyVLop.cpp
  * vector VecBrlyVLop (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "VecBrlyVLop.h"

/******************************************************************************
 namespace VecBrlyVLop
 ******************************************************************************/

uint VecBrlyVLop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	else if (s == "rmv") return RMV;

	return(0);
};

string VecBrlyVLop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	else if (ix == RMV) return("rmv");

	return("");
};

