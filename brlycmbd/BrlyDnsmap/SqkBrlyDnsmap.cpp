/**
  * \file SqkBrlyDnsmap.cpp
  * squawk generation for operation pack BrlyDnsmap (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "SqkBrlyDnsmap.h"

/******************************************************************************
 namespace SqkBrlyDnsmap
 ******************************************************************************/

string SqkBrlyDnsmap::getSquawkCollect(
			DbsBrly* dbsbrly
			, DpchInvBrlyDnsmapCollect* dpchinv
		) {
	// example: "collect data for time-resolved density map"
	return("collect data for time-resolved density map"); // IP getSquawkCollect --- RLINE
};

string SqkBrlyDnsmap::getSquawkFrame(
			DbsBrly* dbsbrly
			, DpchInvBrlyDnsmapFrame* dpchinv
		) {
	// example: "generate video out of time-resolved density map"
	return("generate video out of time-resolved density map"); // IP getSquawkFrame --- RLINE
};

string SqkBrlyDnsmap::getSquawkVideo(
			DbsBrly* dbsbrly
			, DpchInvBrlyDnsmapVideo* dpchinv
		) {
	// example: "generate video out of time-resolved density map"
	return("generate video out of time-resolved density map"); // IP getSquawkVideo --- RLINE
};


