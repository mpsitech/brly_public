/**
  * \file BrlyMapgenLegmap.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMAPGENLEGMAP_H
#define BRLYMAPGENLEGMAP_H

#include "BrlyMapgen.h"

using namespace BrlyMapgen;

// IP incl --- INSERT

namespace BrlyMapgenLegmap {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyMapgenLegmap* dpchinv);
	// IP cust --- IBEGIN

	void radToCoo(const double phi, const double theta, const double pixphi, const double pixtheta, const uint height, const uint width, const int xoffset, const int yoffset, double* x, double* y);
	void legToSphr(const double legphi, const double legtheta, const double* legrmat, double* phi, double* theta);
	void qlegphiToLeg(const double qlegphi, const double* qlegrmat, double* legphi, double* legtheta);
	void qlegToRad(BrlyQLegMapLeg* qleg);
	void qlegToDeg(BrlyQLegMapLeg* qleg);
	void qlocToRad(BrlyQLegMapLocation* qloc);
	void qlocToDeg(BrlyQLegMapLocation* qloc);
	// IP cust --- IEND
};

#endif


