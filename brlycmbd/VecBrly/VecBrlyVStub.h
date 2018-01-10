/**
  * \file VecBrlyVStub.h
  * vector VecBrlyVStub (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef VECBRLYVSTUB_H
#define VECBRLYVSTUB_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecBrlyVStub
	*/
namespace VecBrlyVStub {
	const uint STUBBRLYCONSTD = 1;
	const uint STUBBRLYEQPSHORT = 2;
	const uint STUBBRLYEQPSTD = 3;
	const uint STUBBRLYFAFSTD = 4;
	const uint STUBBRLYFILSTD = 5;
	const uint STUBBRLYFLTSREF = 6;
	const uint STUBBRLYFLTSTD = 7;
	const uint STUBBRLYLEGSHORT = 8;
	const uint STUBBRLYLEGSTD = 9;
	const uint STUBBRLYLOCSREF = 10;
	const uint STUBBRLYLOCSTD = 11;
	const uint STUBBRLYLOCTITLE = 12;
	const uint STUBBRLYNDELONG = 13;
	const uint STUBBRLYNDESTD = 14;
	const uint STUBBRLYOPRSREF = 15;
	const uint STUBBRLYOPRSTD = 16;
	const uint STUBBRLYPRSSTD = 17;
	const uint STUBBRLYPTYSREF = 18;
	const uint STUBBRLYPTYSTD = 19;
	const uint STUBBRLYREGHSREF = 20;
	const uint STUBBRLYREGLONG = 21;
	const uint STUBBRLYREGSTD = 22;
	const uint STUBBRLYRLYLONG = 23;
	const uint STUBBRLYRLYSTD = 24;
	const uint STUBBRLYSEGSTD = 25;
	const uint STUBBRLYSESMENU = 26;
	const uint STUBBRLYSESSTD = 27;
	const uint STUBBRLYTTBSTD = 28;
	const uint STUBBRLYTTBTITLE = 29;
	const uint STUBBRLYOWN = 30;
	const uint STUBBRLYUSRSTD = 31;
	const uint STUBBRLYGRP = 32;
	const uint STUBBRLYUSGSTD = 33;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

