/**
  * \file BrlyDynFltfltloc.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDYNFLTFLTLOC_H
#define BRLYDYNFLTFLTLOC_H

#include "BrlyDyn.h"

using namespace BrlyDyn;

// IP incl --- INSERT

namespace BrlyDynFltfltloc {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynFltfltloc* dpchinv);
	// IP cust --- IBEGIN

	inline double visFltflt(const double t, const double* legrmat1, const double omega1, const uint t01, const double* legrmat2, const double omega2, const uint t02, const double cosa0);
	inline double visdrvFltflt(const double t, const double* legrmat1, const double omega1, const uint t01, const double* legrmat2, const double omega2, const uint t02, const double cosa0);
	bool viszeroFltflt(const double* legrmat1, const double omega1, const uint t01, const double* legrmat2, const double omega2, const uint t02, const double cosa0, const double t0, const double t1, const double tini, const double tol, unsigned int* t);
	// IP cust --- IEND
};

#endif


