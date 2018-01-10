/**
  * \file BrlyMUser_vecs.cpp
  * database access for table TblBrlyMUser (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class TblBrlyMUser::VecVState
 ******************************************************************************/

uint TblBrlyMUser::VecVState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "act") return ACT;
	else if (s == "dsg") return DSG;
	else if (s == "due") return DUE;
	else if (s == "exp") return EXP;

	return(0);
};

string TblBrlyMUser::VecVState::getSref(
			const uint ix
		) {
	if (ix == ACT) return("act");
	else if (ix == DSG) return("dsg");
	else if (ix == DUE) return("due");
	else if (ix == EXP) return("exp");

	return("");
};

string TblBrlyMUser::VecVState::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == ACT) return("active");
		else if (ix == DSG) return("designated");
		else if (ix == DUE) return("due for expiration");
		else if (ix == EXP) return("expired");
	} else if (ixBrlyVLocale == 2) {
		if (ix == ACT) return("aktiv");
		else if (ix == DSG) return("vorgesehen");
		else if (ix == DUE) return("l\\u00e4uft ab");
		else if (ix == EXP) return("abgelaufen");
	};

	return("");
};

void TblBrlyMUser::VecVState::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

