/**
  * \file SqkBrlyDnsmap.h
  * squawk generation for operation pack BrlyDnsmap (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef SQKBRLYDNSMAP_H
#define SQKBRLYDNSMAP_H

#include "BrlyDnsmap_blks.h"

/**
  * SqkBrlyDnsmap
  */
namespace SqkBrlyDnsmap {
	string getSquawkCollect(DbsBrly* dbsbrly, DpchInvBrlyDnsmapCollect* dpchinv);
	string getSquawkFrame(DbsBrly* dbsbrly, DpchInvBrlyDnsmapFrame* dpchinv);
	string getSquawkVideo(DbsBrly* dbsbrly, DpchInvBrlyDnsmapVideo* dpchinv);
};

#endif

