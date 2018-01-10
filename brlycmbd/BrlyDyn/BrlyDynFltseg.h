/**
  * \file BrlyDynFltseg.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDYNFLTSEG_H
#define BRLYDYNFLTSEG_H

#include "BrlyDyn.h"

using namespace BrlyDyn;

// IP incl --- INSERT

namespace BrlyDynFltseg {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynFltseg* dpchinv);
	// IP cust --- IBEGIN

	void segmentFlight(DbsBrly* dbsbrly, BrlyMFlight* flt);
	double getDeltaphi(const double theta0, const double phi0, const double theta1, const double phi1);
	void segToDeg(BrlyMSegment* seg);
	void wpToRad(BrlyAMFaflightWaypoint* wp);
	// IP cust --- IEND
};

#endif


