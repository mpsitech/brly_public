/**
  * \file BrlyDynConseg.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDYNCONSEG_H
#define BRLYDYNCONSEG_H

#include "BrlyDyn.h"

using namespace BrlyDyn;

// IP incl --- INSERT

namespace BrlyDynConseg {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynConseg* dpchinv);
	// IP cust --- INSERT
};

#endif

