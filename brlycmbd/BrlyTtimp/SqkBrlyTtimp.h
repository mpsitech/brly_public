/**
  * \file SqkBrlyTtimp.h
  * squawk generation for operation pack BrlyTtimp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef SQKBRLYTTIMP_H
#define SQKBRLYTTIMP_H

#include "BrlyTtimp_blks.h"

/**
  * SqkBrlyTtimp
  */
namespace SqkBrlyTtimp {
	string getSquawkRawstar(DbsBrly* dbsbrly, DpchInvBrlyTtimpRawstar* dpchinv);
};

#endif

