/**
  * \file SqkBrlyTtimp.cpp
  * squawk generation for operation pack BrlyTtimp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "SqkBrlyTtimp.h"

/******************************************************************************
 namespace SqkBrlyTtimp
 ******************************************************************************/

string SqkBrlyTtimp::getSquawkRawstar(
			DbsBrly* dbsbrly
			, DpchInvBrlyTtimpRawstar* dpchinv
		) {
	// example: "transform file 'Star01122006_16022007.txt' from Star Alliance into intermediate format"
	return("translate file '" + dpchinv->infile + "' from StarAlliance into intermediate format"); // IP getSquawkRawstar --- RLINE
};


