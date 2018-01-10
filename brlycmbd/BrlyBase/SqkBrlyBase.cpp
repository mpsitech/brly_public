/**
  * \file SqkBrlyBase.cpp
  * squawk generation for operation pack BrlyBase (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "SqkBrlyBase.h"

/******************************************************************************
 namespace SqkBrlyBase
 ******************************************************************************/

string SqkBrlyBase::getSquawkLegleg(
			DbsBrly* dbsbrly
			, DpchInvBrlyBaseLegleg* dpchinv
		) {
	// example: "calculate leg-to-leg visibility"
	return("calculate leg-to-leg visibility"); // IP getSquawkLegleg --- RLINE
};

string SqkBrlyBase::getSquawkLegloc(
			DbsBrly* dbsbrly
			, DpchInvBrlyBaseLegloc* dpchinv
		) {
	// example: "calculate location-to-leg visibility"
	return("calculate location-to-leg visibility"); // IP getSquawkLegloc --- RLINE
};

string SqkBrlyBase::getSquawkLocloc(
			DbsBrly* dbsbrly
			, DpchInvBrlyBaseLocloc* dpchinv
		) {
	// example: "calculate location-to-location proximity and visibility"
	return("calculate location-to-location proximity and visibility"); // IP getSquawkLocloc --- RLINE
};


