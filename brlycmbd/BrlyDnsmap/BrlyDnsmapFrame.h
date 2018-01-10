/**
  * \file BrlyDnsmapFrame.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDNSMAPFRAME_H
#define BRLYDNSMAPFRAME_H

#include "BrlyDnsmap.h"

using namespace BrlyDnsmap;

// IP incl --- INSERT

namespace BrlyDnsmapFrame {
	DpchRetBrlyDnsmapFrame* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDnsmapFrame* dpchinv);
	// IP cust --- INSERT
};

#endif

