/**
  * \file BrlyBaseLocloc.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYBASELOCLOC_H
#define BRLYBASELOCLOC_H

#include "BrlyBase.h"

using namespace BrlyBase;

// IP incl --- INSERT

namespace BrlyBaseLocloc {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyBaseLocloc* dpchinv);
	// IP cust --- IBEGIN

	void calcVis(DbsBrly* dbsbrly, const ListBrlyMLocation& dstlocs, const vector<bool>& selDstlocs, const ListBrlyMLocation& orglocs);
	void calcProx(DbsBrly* dbsbrly, const ListBrlyMLocation& dstlocs, const vector<bool>& selDstlocs, const ListBrlyMLocation& orglocs, const double earthradius);
	// IP cust --- IEND
};

#endif


