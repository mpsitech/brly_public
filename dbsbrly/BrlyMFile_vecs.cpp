/**
  * \file BrlyMFile_vecs.cpp
  * database access for table TblBrlyMFile (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class TblBrlyMFile::VecVRefTbl
 ******************************************************************************/

uint TblBrlyMFile::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "ttb") return TTB;

	return(0);
};

string TblBrlyMFile::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == TTB) return("ttb");

	return("");
};

string TblBrlyMFile::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == TTB) return("timetable");
	} else if (ixBrlyVLocale == 2) {
		if (ix == VOID) return("keine");
		else if (ix == TTB) return("Flugplan");
	};

	return("");
};

void TblBrlyMFile::VecVRefTbl::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

