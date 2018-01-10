/**
  * \file BrlyMapgenConmap.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMAPGENCONMAP_H
#define BRLYMAPGENCONMAP_H

#include "BrlyMapgen.h"

using namespace BrlyMapgen;

// IP incl --- INSERT

namespace BrlyMapgenConmap {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyMapgenConmap* dpchinv);
	// IP cust --- IBEGIN

	void radToCoo(const double phi, const double theta, const double pixphi, const double pixtheta, const uint height, const uint width, const int xoffset, const int yoffset, double* x, double* y);
	void legToSphr(const double legphi, const double legtheta, const double* legrmat, double* phi, double* theta);
	void qlegphiToLeg(const double qlegphi, const double* qlegrmat, double* legphi, double* legtheta);
	double timeToQlegphi(const unsigned int t, const unsigned int start, const double omega);
	unsigned int qlegphiToTime(const double phi, const unsigned int start, const double omega);
	void qlegToRad(BrlyQConMapLeg* qleg);
	void qlegToDeg(BrlyQConMapLeg* qleg);
	void qlocToRad(BrlyQConMapLocation* qloc);
	void qlocToDeg(BrlyQConMapLocation* qloc);
	void qfltToRad(BrlyQConMapFlight* qflt);
	void qfltToDeg(BrlyQConMapFlight* qflt);
	// IP cust --- IEND
};

#endif


