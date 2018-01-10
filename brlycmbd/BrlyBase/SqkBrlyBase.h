/**
  * \file SqkBrlyBase.h
  * squawk generation for operation pack BrlyBase (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef SQKBRLYBASE_H
#define SQKBRLYBASE_H

#include "BrlyBase_blks.h"

/**
  * SqkBrlyBase
  */
namespace SqkBrlyBase {
	string getSquawkLegleg(DbsBrly* dbsbrly, DpchInvBrlyBaseLegleg* dpchinv);
	string getSquawkLegloc(DbsBrly* dbsbrly, DpchInvBrlyBaseLegloc* dpchinv);
	string getSquawkLocloc(DbsBrly* dbsbrly, DpchInvBrlyBaseLocloc* dpchinv);
};

#endif

