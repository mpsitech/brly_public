/**
  * \file BrlyDynSeglocseg.cpp
  * Brly operation processor -  (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyopd.h>
#endif

#include "BrlyDynSeglocseg.h"

DpchRetBrly* BrlyDynSeglocseg::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDynSeglocseg* dpchinv
		) {
	vector<ubigint> refsBrlyMFlight = dpchinv->refsBrlyMFlight;

	bool success;

	// IP run --- INSERT

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- INSERT

