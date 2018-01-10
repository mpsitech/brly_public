/**
  * \file VecBrlyVOpengtype.h
  * vector VecBrlyVOpengtype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef VECBRLYVOPENGTYPE_H
#define VECBRLYVOPENGTYPE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecBrlyVOpengtype
	*/
namespace VecBrlyVOpengtype {
	const uint BRLYOPD = 1;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixBrlyVLocale);

	void appendToFeed(const uint ix, const uint ixBrlyVLocale, Feed& feed);
	void fillFeed(const uint ixBrlyVLocale, Feed& feed);
};

#endif

