/**
  * \file VecBrlyVExpstate.h
  * vector VecBrlyVExpstate (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef VECBRLYVEXPSTATE_H
#define VECBRLYVEXPSTATE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecBrlyVExpstate
	*/
namespace VecBrlyVExpstate {
	const uint DETD = 1;
	const uint MAXD = 2;
	const uint MIND = 3;
	const uint REGD = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

