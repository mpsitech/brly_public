/**
  * \file VecBrlyVQrystate.h
  * vector VecBrlyVQrystate (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef VECBRLYVQRYSTATE_H
#define VECBRLYVQRYSTATE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecBrlyVQrystate
	*/
namespace VecBrlyVQrystate {
	const uint MNR = 1;
	const uint OOD = 2;
	const uint SLM = 3;
	const uint UTD = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixBrlyVLocale);

	void fillFeed(const uint ixBrlyVLocale, Feed& feed);
};

#endif

