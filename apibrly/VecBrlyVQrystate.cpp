/**
  * \file VecBrlyVQrystate.cpp
  * vector VecBrlyVQrystate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "VecBrlyVQrystate.h"

/******************************************************************************
 namespace VecBrlyVQrystate
 ******************************************************************************/

uint VecBrlyVQrystate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mnr") return MNR;
	else if (s == "ood") return OOD;
	else if (s == "slm") return SLM;
	else if (s == "utd") return UTD;

	return(0);
};

string VecBrlyVQrystate::getSref(
			const uint ix
		) {
	if (ix == MNR) return("mnr");
	else if (ix == OOD) return("ood");
	else if (ix == SLM) return("slm");
	else if (ix == UTD) return("utd");

	return("");
};

