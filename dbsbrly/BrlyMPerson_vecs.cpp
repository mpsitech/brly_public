/**
  * \file BrlyMPerson_vecs.cpp
  * database access for table TblBrlyMPerson (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class TblBrlyMPerson::VecVSex
 ******************************************************************************/

uint TblBrlyMPerson::VecVSex::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "f") return F;
	else if (s == "m") return M;

	return(0);
};

string TblBrlyMPerson::VecVSex::getSref(
			const uint ix
		) {
	if (ix == F) return("f");
	else if (ix == M) return("m");

	return("");
};

string TblBrlyMPerson::VecVSex::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == F) return("female");
		else if (ix == M) return("male");
	} else if (ixBrlyVLocale == 2) {
		if (ix == F) return("weiblich");
		else if (ix == M) return("m\\u00e4nnlich");
	};

	return("");
};

void TblBrlyMPerson::VecVSex::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class TblBrlyMPerson::VecWDerivate
 ******************************************************************************/

uint TblBrlyMPerson::VecWDerivate::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "usr") ix |= USR;
	};

	return(ix);
};

void TblBrlyMPerson::VecWDerivate::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*USR);i*=2) if (ix & i) ics.insert(i);
};

string TblBrlyMPerson::VecWDerivate::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & USR) ss.push_back("usr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblBrlyMPerson::VecWDerivate::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == USR) return("user");
	} else if (ixBrlyVLocale == 2) {
		if (ix == USR) return("Benutzer");
	};

	return("");
};

void TblBrlyMPerson::VecWDerivate::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=USR;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixBrlyVLocale));
};

