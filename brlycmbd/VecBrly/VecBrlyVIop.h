/**
  * \file VecBrlyVIop.h
  * vector VecBrlyVIop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef VECBRLYVIOP_H
#define VECBRLYVIOP_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecBrlyVIop
	*/
namespace VecBrlyVIop {
	const uint INS = 1;
	const uint RETR = 2;
	const uint RETRINS = 3;
	const uint RETRUPD = 4;
	const uint RMV = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixBrlyVLocale);

	void fillFeed(const uint ixBrlyVLocale, Feed& feed);
};

#endif

