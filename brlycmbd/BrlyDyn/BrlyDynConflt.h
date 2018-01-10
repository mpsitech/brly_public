/**
  * \file BrlyDynConflt.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDYNCONFLT_H
#define BRLYDYNCONFLT_H

#include "BrlyDyn.h"

using namespace BrlyDyn;

// IP incl --- INSERT

namespace BrlyDynConflt {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynConflt* dpchinv);
	// IP cust --- INSERT
};

#endif

