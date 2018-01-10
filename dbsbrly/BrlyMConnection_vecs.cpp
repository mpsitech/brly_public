/**
  * \file BrlyMConnection_vecs.cpp
  * database access for table TblBrlyMConnection (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class TblBrlyMConnection::VecVModel
 ******************************************************************************/

uint TblBrlyMConnection::VecVModel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "spl") return SPL;
	else if (s == "ext") return EXT;

	return(0);
};

string TblBrlyMConnection::VecVModel::getSref(
			const uint ix
		) {
	if (ix == SPL) return("spl");
	else if (ix == EXT) return("ext");

	return("");
};

string TblBrlyMConnection::VecVModel::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == SPL) return("simple");
		else if (ix == EXT) return("extended");
	} else if (ixBrlyVLocale == 2) {
		if (ix == SPL) return("einfach");
		else if (ix == EXT) return("erweitert");
	};

	return("");
};

void TblBrlyMConnection::VecVModel::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

