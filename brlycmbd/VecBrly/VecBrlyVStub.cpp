/**
  * \file VecBrlyVStub.cpp
  * vector VecBrlyVStub (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "VecBrlyVStub.h"

/******************************************************************************
 namespace VecBrlyVStub
 ******************************************************************************/

uint VecBrlyVStub::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "stubbrlyconstd") return STUBBRLYCONSTD;
	else if (s == "stubbrlyeqpshort") return STUBBRLYEQPSHORT;
	else if (s == "stubbrlyeqpstd") return STUBBRLYEQPSTD;
	else if (s == "stubbrlyfafstd") return STUBBRLYFAFSTD;
	else if (s == "stubbrlyfilstd") return STUBBRLYFILSTD;
	else if (s == "stubbrlyfltsref") return STUBBRLYFLTSREF;
	else if (s == "stubbrlyfltstd") return STUBBRLYFLTSTD;
	else if (s == "stubbrlylegshort") return STUBBRLYLEGSHORT;
	else if (s == "stubbrlylegstd") return STUBBRLYLEGSTD;
	else if (s == "stubbrlylocsref") return STUBBRLYLOCSREF;
	else if (s == "stubbrlylocstd") return STUBBRLYLOCSTD;
	else if (s == "stubbrlyloctitle") return STUBBRLYLOCTITLE;
	else if (s == "stubbrlyndelong") return STUBBRLYNDELONG;
	else if (s == "stubbrlyndestd") return STUBBRLYNDESTD;
	else if (s == "stubbrlyoprsref") return STUBBRLYOPRSREF;
	else if (s == "stubbrlyoprstd") return STUBBRLYOPRSTD;
	else if (s == "stubbrlyprsstd") return STUBBRLYPRSSTD;
	else if (s == "stubbrlyptysref") return STUBBRLYPTYSREF;
	else if (s == "stubbrlyptystd") return STUBBRLYPTYSTD;
	else if (s == "stubbrlyreghsref") return STUBBRLYREGHSREF;
	else if (s == "stubbrlyreglong") return STUBBRLYREGLONG;
	else if (s == "stubbrlyregstd") return STUBBRLYREGSTD;
	else if (s == "stubbrlyrlylong") return STUBBRLYRLYLONG;
	else if (s == "stubbrlyrlystd") return STUBBRLYRLYSTD;
	else if (s == "stubbrlysegstd") return STUBBRLYSEGSTD;
	else if (s == "stubbrlysesmenu") return STUBBRLYSESMENU;
	else if (s == "stubbrlysesstd") return STUBBRLYSESSTD;
	else if (s == "stubbrlyttbstd") return STUBBRLYTTBSTD;
	else if (s == "stubbrlyttbtitle") return STUBBRLYTTBTITLE;
	else if (s == "stubbrlyown") return STUBBRLYOWN;
	else if (s == "stubbrlyusrstd") return STUBBRLYUSRSTD;
	else if (s == "stubbrlygrp") return STUBBRLYGRP;
	else if (s == "stubbrlyusgstd") return STUBBRLYUSGSTD;

	return(0);
};

string VecBrlyVStub::getSref(
			const uint ix
		) {
	if (ix == STUBBRLYCONSTD) return("StubBrlyConStd");
	else if (ix == STUBBRLYEQPSHORT) return("StubBrlyEqpShort");
	else if (ix == STUBBRLYEQPSTD) return("StubBrlyEqpStd");
	else if (ix == STUBBRLYFAFSTD) return("StubBrlyFafStd");
	else if (ix == STUBBRLYFILSTD) return("StubBrlyFilStd");
	else if (ix == STUBBRLYFLTSREF) return("StubBrlyFltSref");
	else if (ix == STUBBRLYFLTSTD) return("StubBrlyFltStd");
	else if (ix == STUBBRLYLEGSHORT) return("StubBrlyLegShort");
	else if (ix == STUBBRLYLEGSTD) return("StubBrlyLegStd");
	else if (ix == STUBBRLYLOCSREF) return("StubBrlyLocSref");
	else if (ix == STUBBRLYLOCSTD) return("StubBrlyLocStd");
	else if (ix == STUBBRLYLOCTITLE) return("StubBrlyLocTitle");
	else if (ix == STUBBRLYNDELONG) return("StubBrlyNdeLong");
	else if (ix == STUBBRLYNDESTD) return("StubBrlyNdeStd");
	else if (ix == STUBBRLYOPRSREF) return("StubBrlyOprSref");
	else if (ix == STUBBRLYOPRSTD) return("StubBrlyOprStd");
	else if (ix == STUBBRLYPRSSTD) return("StubBrlyPrsStd");
	else if (ix == STUBBRLYPTYSREF) return("StubBrlyPtySref");
	else if (ix == STUBBRLYPTYSTD) return("StubBrlyPtyStd");
	else if (ix == STUBBRLYREGHSREF) return("StubBrlyRegHsref");
	else if (ix == STUBBRLYREGLONG) return("StubBrlyRegLong");
	else if (ix == STUBBRLYREGSTD) return("StubBrlyRegStd");
	else if (ix == STUBBRLYRLYLONG) return("StubBrlyRlyLong");
	else if (ix == STUBBRLYRLYSTD) return("StubBrlyRlyStd");
	else if (ix == STUBBRLYSEGSTD) return("StubBrlySegStd");
	else if (ix == STUBBRLYSESMENU) return("StubBrlySesMenu");
	else if (ix == STUBBRLYSESSTD) return("StubBrlySesStd");
	else if (ix == STUBBRLYTTBSTD) return("StubBrlyTtbStd");
	else if (ix == STUBBRLYTTBTITLE) return("StubBrlyTtbTitle");
	else if (ix == STUBBRLYOWN) return("StubBrlyOwn");
	else if (ix == STUBBRLYUSRSTD) return("StubBrlyUsrStd");
	else if (ix == STUBBRLYGRP) return("StubBrlyGrp");
	else if (ix == STUBBRLYUSGSTD) return("StubBrlyUsgStd");

	return("");
};

