/**
  * \file BrlyMSegment_vecs.cpp
  * database access for table TblBrlyMSegment (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class TblBrlyMSegment::VecVRefTbl
 ******************************************************************************/

uint TblBrlyMSegment::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "con") return CON;
	else if (s == "flt") return FLT;

	return(0);
};

string TblBrlyMSegment::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == CON) return("con");
	else if (ix == FLT) return("flt");

	return("");
};

string TblBrlyMSegment::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == CON) return("connection");
		else if (ix == FLT) return("flight");
	} else if (ixBrlyVLocale == 2) {
		if (ix == CON) return("Verbindung");
		else if (ix == FLT) return("Flug");
	};

	return("");
};

void TblBrlyMSegment::VecVRefTbl::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

