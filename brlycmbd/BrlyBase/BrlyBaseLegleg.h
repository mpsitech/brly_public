/**
  * \file BrlyBaseLegleg.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYBASELEGLEG_H
#define BRLYBASELEGLEG_H

#include "BrlyBase.h"

using namespace BrlyBase;

// IP incl --- INSERT

namespace BrlyBaseLegleg {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyBaseLegleg* dpchinv);
	// IP cust --- IBEGIN

	void calcVis(DbsBrly* dbsbrly, const ListBrlyMLeg& dstlegs, const vector<bool>& selDstlegs, const ListBrlyMLeg& orglegs);
	inline void org2dst(double* org2dstrmat, const double orgphi, double* dsttheta, double* dstphi);
	inline double orgphi2dstphi(double* org2dstrmat, const double orgphi);
	inline double orgphi2dsttheta(double* org2dstrmat, const double orgphi);
	inline bool xsecDstphi(double* org2dstrmat, const double orgphimin, const double orgphimax, const double orgphi0, const double dstphi, const double dstalpha, const double tol, double* orgphi);
	inline bool xsecDsttheta(double* org2dstrmat, const double orgphimin, const double orgphimax, const double orgphi0, const double dsttheta, const double dstdelatphi, const double tol, double* orgphi);
	// IP cust --- IEND
};

#endif


