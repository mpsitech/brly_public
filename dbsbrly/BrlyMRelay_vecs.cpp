/**
  * \file BrlyMRelay_vecs.cpp
  * database access for table TblBrlyMRelay (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class TblBrlyMRelay::VecVDir
 ******************************************************************************/

uint TblBrlyMRelay::VecVDir::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "bwd") return BWD;
	else if (s == "fwd") return FWD;

	return(0);
};

string TblBrlyMRelay::VecVDir::getSref(
			const uint ix
		) {
	if (ix == BWD) return("bwd");
	else if (ix == FWD) return("fwd");

	return("");
};

string TblBrlyMRelay::VecVDir::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == BWD) return("backward");
		else if (ix == FWD) return("forward");
	} else if (ixBrlyVLocale == 2) {
		if (ix == BWD) return("r\\u00fcckw\\u00e4rts");
		else if (ix == FWD) return("vorw\\u00e4rts");
	};

	return("");
};

void TblBrlyMRelay::VecVDir::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

