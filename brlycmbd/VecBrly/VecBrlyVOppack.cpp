/**
  * \file VecBrlyVOppack.cpp
  * vector VecBrlyVOppack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "VecBrlyVOppack.h"

/******************************************************************************
 namespace VecBrlyVOppack
 ******************************************************************************/

uint VecBrlyVOppack::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "brlybase") return BRLYBASE;
	else if (s == "brlydnsmap") return BRLYDNSMAP;
	else if (s == "brlydyn") return BRLYDYN;
	else if (s == "brlymapgen") return BRLYMAPGEN;
	else if (s == "brlyttimp") return BRLYTTIMP;

	return(0);
};

string VecBrlyVOppack::getSref(
			const uint ix
		) {
	if (ix == BRLYBASE) return("BrlyBase");
	else if (ix == BRLYDNSMAP) return("BrlyDnsmap");
	else if (ix == BRLYDYN) return("BrlyDyn");
	else if (ix == BRLYMAPGEN) return("BrlyMapgen");
	else if (ix == BRLYTTIMP) return("BrlyTtimp");

	return("");
};

string VecBrlyVOppack::getTitle(
			const uint ix
		) {
	if (ix == BRLYBASE) return("static calculation");
	else if (ix == BRLYDNSMAP) return("density map generation");
	else if (ix == BRLYDYN) return("dynamic calculation");
	else if (ix == BRLYMAPGEN) return("map generation");
	else if (ix == BRLYTTIMP) return("timetable import");

	return("");
};

string VecBrlyVOppack::getComment(
			const uint ix
		) {

	return("");
};

void VecBrlyVOppack::appendToFeed(
			const uint ix
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix));
};

void VecBrlyVOppack::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};

