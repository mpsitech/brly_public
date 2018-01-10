/**
  * \file VecBrlyVReqitmode.h
  * vector VecBrlyVReqitmode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef VECBRLYVREQITMODE_H
#define VECBRLYVREQITMODE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecBrlyVReqitmode
	*/
namespace VecBrlyVReqitmode {
	const uint IDLE = 1;
	const uint NOTIFY = 2;
	const uint POLL = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

