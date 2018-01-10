/**
  * \file BrlyMLeg_vecs.cpp
  * database access for table TblBrlyMLeg (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class TblBrlyMLeg::VecVBasetype
 ******************************************************************************/

uint TblBrlyMLeg::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "corr") return CORR;
	else if (s == "rte") return RTE;

	return(0);
};

string TblBrlyMLeg::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == CORR) return("corr");
	else if (ix == RTE) return("rte");

	return("");
};

string TblBrlyMLeg::VecVBasetype::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == CORR) return("corridor");
		else if (ix == RTE) return("route");
	} else if (ixBrlyVLocale == 2) {
		if (ix == CORR) return("Korridor");
		else if (ix == RTE) return("Route");
	};

	return("");
};

void TblBrlyMLeg::VecVBasetype::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class TblBrlyMLeg::VecWSubset
 ******************************************************************************/

uint TblBrlyMLeg::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sbsbrlybmlegcor") ix |= SBSBRLYBMLEGCOR;
		else if (ss[i] == "sbsbrlybmlegrte") ix |= SBSBRLYBMLEGRTE;
	};

	return(ix);
};

void TblBrlyMLeg::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SBSBRLYBMLEGRTE);i*=2) if (ix & i) ics.insert(i);
};

string TblBrlyMLeg::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSBRLYBMLEGCOR) ss.push_back("SbsBrlyBMLegCor");
	if (ix & SBSBRLYBMLEGRTE) ss.push_back("SbsBrlyBMLegRte");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblBrlyMLeg::VecWSubset::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == SBSBRLYBMLEGCOR) return("corridor");
		else if (ix == SBSBRLYBMLEGRTE) return("route");
	} else if (ixBrlyVLocale == 2) {
		if (ix == SBSBRLYBMLEGCOR) return("Korridor");
		else if (ix == SBSBRLYBMLEGRTE) return("Route");
	};

	return("");
};

