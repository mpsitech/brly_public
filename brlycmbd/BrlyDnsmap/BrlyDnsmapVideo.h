/**
  * \file BrlyDnsmapVideo.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDNSMAPVIDEO_H
#define BRLYDNSMAPVIDEO_H

#include "BrlyDnsmap.h"

using namespace BrlyDnsmap;

// IP incl --- INSERT

namespace BrlyDnsmapVideo {
	DpchRetBrlyDnsmapVideo* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDnsmapVideo* dpchinv);
	// IP cust --- INSERT
};

#endif

