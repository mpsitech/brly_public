/**
  * \file SqkBrlyDyn.cpp
  * squawk generation for operation pack BrlyDyn (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "SqkBrlyDyn.h"

/******************************************************************************
 namespace SqkBrlyDyn
 ******************************************************************************/

string SqkBrlyDyn::getSquawkConflt(
			DbsBrly* dbsbrly
			, DpchInvBrlyDynConflt* dpchinv
		) {
	// example: "calculate flight availability for connection '(region) eu-c-de - (flight) LH403 2007-2-16 FRA-JFK, t0: 16-02-2007 0:00'"
	return("calculate flight availability for connection '" + StubBrly::getStubConStd(dbsbrly, dpchinv->refBrlyMConnection) + "'"); // IP getSquawkConflt --- RLINE
};

string SqkBrlyDyn::getSquawkConseg(
			DbsBrly* dbsbrly
			, DpchInvBrlyDynConseg* dpchinv
		) {
	// example: "calculate segment availability for connection '(region) eu-c-de - (flight) LH403 2007-2-16 FRA-JFK, t0: 16-02-2007 0:00'"
	return("calculate segment availability for connection '" + StubBrly::getStubConStd(dbsbrly, dpchinv->refBrlyMConnection) + "'"); // IP getSquawkConseg --- RLINE
};

string SqkBrlyDyn::getSquawkEqplist(
			DbsBrly* dbsbrly
			, DpchInvBrlyDynEqplist* dpchinv
		) {
	// example: "calculate equipment line-up for connection '(region) eu-c-de - (flight) LH403 2007-2-16 FRA-JFK, t0: 16-02-2007 0:00'"
	return("calculate equipment line-up for connection '" + StubBrly::getStubConStd(dbsbrly, dpchinv->refBrlyMConnection) + "'"); // IP getSquawkEqplist --- RLINE
};

string SqkBrlyDyn::getSquawkFltfltloc(
			DbsBrly* dbsbrly
			, DpchInvBrlyDynFltfltloc* dpchinv
		) {
	// example: "calculate flight-to-flight and flight-to-location visibility"
	return("calculate flight-to-flight and flight-to-location visibility"); // IP getSquawkFltfltloc --- RLINE
};

string SqkBrlyDyn::getSquawkFltseg(
			DbsBrly* dbsbrly
			, DpchInvBrlyDynFltseg* dpchinv
		) {
	// example: "calculate flight segmentation"
	return("calculate flight segmentation"); // IP getSquawkFltseg --- RLINE
};

string SqkBrlyDyn::getSquawkRly(
			DbsBrly* dbsbrly
			, DpchInvBrlyDynRly* dpchinv
		) {
	// example: "calculate relays for connection '(region) eu-c-de - (flight) LH403 2007-2-16 FRA-JFK, t0: 16-02-2007 0:00'"
	return("calculate relays for connection '" + StubBrly::getStubConStd(dbsbrly, dpchinv->refBrlyMConnection) + "'"); // IP getSquawkRly --- RLINE
};

string SqkBrlyDyn::getSquawkSeglocseg(
			DbsBrly* dbsbrly
			, DpchInvBrlyDynSeglocseg* dpchinv
		) {
	// example: "calculate segment-to-location and segment-to-segment visibility"
	return("calculate segment-to-location and segment-to-segment visibility"); // IP getSquawkSeglocseg --- RLINE
};


