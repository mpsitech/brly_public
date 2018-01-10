/**
  * \file BrlyDnsmapCollect.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDNSMAPCOLLECT_H
#define BRLYDNSMAPCOLLECT_H

#include "BrlyDnsmap.h"

using namespace BrlyDnsmap;

// IP incl --- INSERT

namespace BrlyDnsmapCollect {
	DpchRetBrlyDnsmapCollect* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDnsmapCollect* dpchinv);
	// IP cust --- IBEGIN

	const double pi = 3.141592653589793238462643383279;

	void phithetaToPix(const uint fullheight, const uint fullwidth, const bool pacctr, const double theta, double phi, unsigned int& y, unsigned int& x);
	void pixToPhitheta(const uint fullheight, const uint fullwidth, const bool pacctr, const unsigned int y, const unsigned int x, double& theta, double& phi);
	bool pixToIx(const unsigned int y0, const unsigned int y1, const unsigned int x0, const unsigned int x1, const unsigned int y, const unsigned int x, unsigned int& yp, unsigned int& xp);
	void ixToPix(const unsigned int y0, const unsigned int y1, const unsigned int x0, const unsigned int x1, const unsigned int yp, const unsigned int xp, unsigned int& y, unsigned int& x);
	bool tToIx(const uint t0, const uint t1, const uint dt, const uint t, unsigned int& ix);

	void getRmatEquatorLeg(double _theta0, double _phi0, double _theta1, double _phi1, double** _rmat);
	void getRmatZeroLocation(double _theta0, double _phi0, double** _rmat);
	void getXRmat(double _phiX, double** _rmat);
	void getYRmat(double _phiY, double** _rmat);
	void getZRmat(double _phiZ, double** _rmat);
	void transpAmat(double* _amat, double** _amatT, unsigned int _N);
	void multAmatBmat(double* _amat, double* _bmat, double** _cmat, unsigned int _N);
	void multAmatBmatT(double* _amat, double* _bmat, double** _cmat, unsigned int _N);
	void multAmatBvec(double* _amat, double* _bvec, double** _cvec, unsigned int _N);
	double getDotProd(double* _avec, double* _bvec);
	void sphrToCart(double _r, double _theta, double _phi, double** _vec);
	void cartToSphr(double* _vec, double* _r, double* _theta, double* _phi);
	double degToRad(double _deg);
	double radToDeg(double _rad);
	void legToRad(BrlyMLeg* leg);
	void locToRad(BrlyMLocation* loc);
	void segToRad(BrlyMSegment* seg);
	// IP cust --- IEND
};

#endif


