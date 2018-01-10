/**
  * \file BrlyBaseLegloc.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYBASELEGLOC_H
#define BRLYBASELEGLOC_H

#include "BrlyBase.h"

using namespace BrlyBase;

// IP incl --- INSERT

namespace BrlyBaseLegloc {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyBaseLegloc* dpchinv);
	// IP cust --- IBEGIN

	void calcVis(DbsBrly* dbsbrly, const ListBrlyMLeg& legs, const ListBrlyMLocation& locs, const double earthradius);

	double xsecAgp(const double re, const double af, const double eg, const double ag, const double agp0);
	double drvxsecAgp(const double re, const double af, const double eg, const double ag, const double agp0);
	bool zeroAgp(const double re, const double af, const double eg, const double ag, const double agpini, const double tol, double* agp);
	// IP cust --- IEND
};

#endif


