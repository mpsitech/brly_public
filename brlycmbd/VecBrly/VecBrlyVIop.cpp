/**
  * \file VecBrlyVIop.cpp
  * vector VecBrlyVIop (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "VecBrlyVIop.h"

/******************************************************************************
 namespace VecBrlyVIop
 ******************************************************************************/

uint VecBrlyVIop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	else if (s == "retr") return RETR;
	else if (s == "retrins") return RETRINS;
	else if (s == "retrupd") return RETRUPD;
	else if (s == "rmv") return RMV;

	return(0);
};

string VecBrlyVIop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	else if (ix == RETR) return("retr");
	else if (ix == RETRINS) return("retrins");
	else if (ix == RETRUPD) return("retrupd");
	else if (ix == RMV) return("rmv");

	return("");
};

string VecBrlyVIop::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == INS) return("insert");
		else if (ix == RETR) return("retrieve");
		else if (ix == RETRINS) return("retrieve, else insert");
		else if (ix == RETRUPD) return("retrieve and update");
		else if (ix == RMV) return("remove");
	} else if (ixBrlyVLocale == 2) {
		if (ix == INS) return("einf\\u00fcgen");
		else if (ix == RETR) return("auffinden");
		else if (ix == RETRINS) return("auffinden, sonst einf\\u00fcgen");
		else if (ix == RETRUPD) return("auffinden und aktualisieren");
		else if (ix == RMV) return("entfernen");
	};

	return("");
};

void VecBrlyVIop::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

