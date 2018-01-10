/**
  * \file BrlyMLocation_vecs.cpp
  * database access for table TblBrlyMLocation (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class TblBrlyMLocation::VecVBasetype
 ******************************************************************************/

uint TblBrlyMLocation::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "apt") return APT;
	else if (s == "gnd") return GND;
	else if (s == "elv") return ELV;

	return(0);
};

string TblBrlyMLocation::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == APT) return("apt");
	else if (ix == GND) return("gnd");
	else if (ix == ELV) return("elv");

	return("");
};

string TblBrlyMLocation::VecVBasetype::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == APT) return("airport");
		else if (ix == GND) return("ground location");
		else if (ix == ELV) return("elevated location");
	} else if (ixBrlyVLocale == 2) {
		if (ix == APT) return("Flughafen");
		else if (ix == GND) return("Ort am Boden");
		else if (ix == ELV) return("schwebender Ort");
	};

	return("");
};

void TblBrlyMLocation::VecVBasetype::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class TblBrlyMLocation::VecWSubset
 ******************************************************************************/

uint TblBrlyMLocation::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sbsbrlybmlocationapt") ix |= SBSBRLYBMLOCATIONAPT;
	};

	return(ix);
};

void TblBrlyMLocation::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SBSBRLYBMLOCATIONAPT);i*=2) if (ix & i) ics.insert(i);
};

string TblBrlyMLocation::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSBRLYBMLOCATIONAPT) ss.push_back("SbsBrlyBMLocationApt");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblBrlyMLocation::VecWSubset::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == SBSBRLYBMLOCATIONAPT) return("airport");
	} else if (ixBrlyVLocale == 2) {
		if (ix == SBSBRLYBMLOCATIONAPT) return("Flughafen");
	};

	return("");
};

