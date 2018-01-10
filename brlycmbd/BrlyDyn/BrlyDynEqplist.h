/**
  * \file BrlyDynEqplist.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDYNEQPLIST_H
#define BRLYDYNEQPLIST_H

#include "BrlyDyn.h"

using namespace BrlyDyn;

// IP incl --- INSERT

namespace BrlyDynEqplist {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynEqplist* dpchinv);
	// IP cust --- IBEGIN

	double evalCorrphi(const double phi, const double* rtrmat);
	inline double evalFltlocSwap(const double phi1, const double* rtrmat1, const double phi2);
	inline double evalFltfltSwap(const double phi1, const double* rtrmat1, const double phi2, const double* rtrmat2);
	// IP cust --- IEND
};

#endif


