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

string VecBrlyVQrystate::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == MNR) return("might need refresh");
		else if (ix == OOD) return("out of date");
		else if (ix == SLM) return("slightly modified");
		else if (ix == UTD) return("up to date");
	} else if (ixBrlyVLocale == 2) {
		if (ix == MNR) return("eventuell veraltet");
		else if (ix == OOD) return("veraltet");
		else if (ix == SLM) return("geringf\\u00fcgig ver\\u00e4ndert");
		else if (ix == UTD) return("aktuell");
	};

	return("");
};

void VecBrlyVQrystate::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

