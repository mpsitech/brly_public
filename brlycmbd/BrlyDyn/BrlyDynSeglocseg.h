/**
  * \file BrlyDynSeglocseg.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDYNSEGLOCSEG_H
#define BRLYDYNSEGLOCSEG_H

#include "BrlyDyn.h"

using namespace BrlyDyn;

// IP incl --- INSERT

namespace BrlyDynSeglocseg {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynSeglocseg* dpchinv);
	// IP cust --- INSERT
};

#endif

