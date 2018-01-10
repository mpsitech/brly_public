/**
  * \file VecBrlyVLop.h
  * vector VecBrlyVLop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef VECBRLYVLOP_H
#define VECBRLYVLOP_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecBrlyVLop
	*/
namespace VecBrlyVLop {
	const uint INS = 1;
	const uint RMV = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

