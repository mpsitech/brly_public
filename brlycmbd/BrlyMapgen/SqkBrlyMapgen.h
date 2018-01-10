/**
  * \file SqkBrlyMapgen.h
  * squawk generation for operation pack BrlyMapgen (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef SQKBRLYMAPGEN_H
#define SQKBRLYMAPGEN_H

#include "BrlyMapgen_blks.h"

/**
  * SqkBrlyMapgen
  */
namespace SqkBrlyMapgen {
	string getSquawkConmap(DbsBrly* dbsbrly, DpchInvBrlyMapgenConmap* dpchinv);
	string getSquawkLegmap(DbsBrly* dbsbrly, DpchInvBrlyMapgenLegmap* dpchinv);
	string getSquawkLocmap(DbsBrly* dbsbrly, DpchInvBrlyMapgenLocmap* dpchinv);
};

#endif

