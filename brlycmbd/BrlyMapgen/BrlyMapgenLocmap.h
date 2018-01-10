/**
  * \file BrlyMapgenLocmap.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMAPGENLOCMAP_H
#define BRLYMAPGENLOCMAP_H

#include "BrlyMapgen.h"

using namespace BrlyMapgen;

// IP incl --- INSERT

namespace BrlyMapgenLocmap {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyMapgenLocmap* dpchinv);
	// IP cust --- IBEGIN

	void radToCoo(const double phi, const double theta, const double locphi, const double loctheta, const double pixphi, const double pixtheta, const uint height, const uint width, const int xoffset, const int yoffset, double* x, double* y);
	void legphiToSphr(const double legphi, const double* legrmat, double* phi, double* theta);
	void qlegToRad(BrlyQLocMapLeg* qleg);
	void qlegToDeg(BrlyQLocMapLeg* qleg);
	void qplocToRad(BrlyQLocMapProxLocation* qploc);
	void qplocToDeg(BrlyQLocMapProxLocation* qploc);
	void qvlocToRad(BrlyQLocMapVisLocation* qvloc);
	void qvlocToDeg(BrlyQLocMapVisLocation* qvloc);
	// IP cust --- IEND
};

#endif


