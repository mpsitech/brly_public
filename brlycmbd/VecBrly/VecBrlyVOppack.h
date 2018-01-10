/**
  * \file VecBrlyVOppack.h
  * vector VecBrlyVOppack (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef VECBRLYVOPPACK_H
#define VECBRLYVOPPACK_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecBrlyVOppack
	*/
namespace VecBrlyVOppack {
	const uint BRLYBASE = 1;
	const uint BRLYDNSMAP = 2;
	const uint BRLYDYN = 3;
	const uint BRLYMAPGEN = 4;
	const uint BRLYTTIMP = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix);
	string getComment(const uint ix);

	void appendToFeed(const uint ix, Feed& feed);
	void fillFeed(Feed& feed);
};

#endif

