/**
  * \file BrlyMRegion_vecs.cpp
  * database access for table TblBrlyMRegion (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class TblBrlyMRegion::VecVDst
 ******************************************************************************/

uint TblBrlyMRegion::VecVDst::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "none") return NONE;
	else if (s == "ndst") return NDST;
	else if (s == "sdst") return SDST;

	return(0);
};

string TblBrlyMRegion::VecVDst::getSref(
			const uint ix
		) {
	if (ix == NONE) return("none");
	else if (ix == NDST) return("ndst");
	else if (ix == SDST) return("sdst");

	return("");
};

string TblBrlyMRegion::VecVDst::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == NONE) return("none");
		else if (ix == NDST) return("northern hemisphere");
		else if (ix == SDST) return("southern hemisphere");
	} else if (ixBrlyVLocale == 2) {
		if (ix == NONE) return("keine");
		else if (ix == NDST) return("Nordhalbkugel");
		else if (ix == SDST) return("S\\u00fcdhalbkugel");
	};

	return("");
};

void TblBrlyMRegion::VecVDst::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class TblBrlyMRegion::VecWSubset
 ******************************************************************************/

uint TblBrlyMRegion::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sbsbrlybmregionrip") ix |= SBSBRLYBMREGIONRIP;
	};

	return(ix);
};

void TblBrlyMRegion::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SBSBRLYBMREGIONRIP);i*=2) if (ix & i) ics.insert(i);
};

string TblBrlyMRegion::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSBRLYBMREGIONRIP) ss.push_back("SbsBrlyBMRegionRip");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblBrlyMRegion::VecWSubset::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == SBSBRLYBMREGIONRIP) return("impartible region");
	} else if (ixBrlyVLocale == 2) {
		if (ix == SBSBRLYBMREGIONRIP) return("unteilbare Region");
	};

	return("");
};

