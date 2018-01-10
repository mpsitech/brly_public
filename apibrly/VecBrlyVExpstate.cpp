/**
  * \file VecBrlyVExpstate.cpp
  * vector VecBrlyVExpstate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "VecBrlyVExpstate.h"

/******************************************************************************
 namespace VecBrlyVExpstate
 ******************************************************************************/

uint VecBrlyVExpstate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detd") return DETD;
	else if (s == "maxd") return MAXD;
	else if (s == "mind") return MIND;
	else if (s == "regd") return REGD;

	return(0);
};

string VecBrlyVExpstate::getSref(
			const uint ix
		) {
	if (ix == DETD) return("detd");
	else if (ix == MAXD) return("maxd");
	else if (ix == MIND) return("mind");
	else if (ix == REGD) return("regd");

	return("");
};

