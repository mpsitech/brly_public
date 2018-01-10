/**
  * \file SqkBrlyDyn.h
  * squawk generation for operation pack BrlyDyn (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef SQKBRLYDYN_H
#define SQKBRLYDYN_H

#include "BrlyDyn_blks.h"

/**
  * SqkBrlyDyn
  */
namespace SqkBrlyDyn {
	string getSquawkConflt(DbsBrly* dbsbrly, DpchInvBrlyDynConflt* dpchinv);
	string getSquawkConseg(DbsBrly* dbsbrly, DpchInvBrlyDynConseg* dpchinv);
	string getSquawkEqplist(DbsBrly* dbsbrly, DpchInvBrlyDynEqplist* dpchinv);
	string getSquawkFltfltloc(DbsBrly* dbsbrly, DpchInvBrlyDynFltfltloc* dpchinv);
	string getSquawkFltseg(DbsBrly* dbsbrly, DpchInvBrlyDynFltseg* dpchinv);
	string getSquawkRly(DbsBrly* dbsbrly, DpchInvBrlyDynRly* dpchinv);
	string getSquawkSeglocseg(DbsBrly* dbsbrly, DpchInvBrlyDynSeglocseg* dpchinv);
};

#endif

