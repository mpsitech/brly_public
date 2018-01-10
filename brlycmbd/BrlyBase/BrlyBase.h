/**
  * \file BrlyBase.h
  * Brly operation pack global code (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYBASE_H
#define BRLYBASE_H

#include "BrlyBase_blks.h"

// IP incl --- INSERT

namespace BrlyBase {
	// IP cust --- IBEGIN
	const double pi = 3.141592653589793238462643383279;

	bool isInZeroApexCone(double* _axisCone, double _alphaCone, double _theta, double _phi);
	bool isInZeroApexCone(double _thetaCone, double _phiCone, double _alphaCone, double _theta, double _phi);
	bool isInCone(double _rCone, double _thetaCone, double _phiCone, double _alphaCone, double _r, double _theta, double _phi);
	void getRmatEquatorLeg(double _theta0, double _phi0, double _theta1, double _phi1, double** _rmat);
	void getRmatZeroLocation(double _theta0, double _phi0, double** _rmat);
	void getXRmat(double _phiX, double** _rmat);
	void getYRmat(double _phiY, double** _rmat);
	void getZRmat(double _phiZ, double** _rmat);
	void transpAmat(double* _amat, double** _amatT, unsigned int _N);
	void multAmatBmat(double* _amat, double* _bmat, double** _cmat, unsigned int _N);
	void multAmatBvec(double* _amat, double* _bvec, double** _cvec, unsigned int _N);
	void getCrossProd(double* _avec, double* _bvec, double** _cvec);
	double getDotProd(double* _avec, double* _bvec);
	void sphrToCart(double _r, double _theta, double _phi, double** _vec);
	void cartToSphr(double* _vec, double* _r, double* _theta, double* _phi);
	double degToRad(double _deg);
	double radToDeg(double _rad);
	void legToRad(BrlyMLeg* leg);
	void legToDeg(BrlyMLeg* leg);
	void locToRad(BrlyMLocation* loc);
	void locToDeg(BrlyMLocation* loc);
	void legRelLocToDeg(BrlyRMLegMLocation* lrl);
	void legRelLegToDeg(BrlyRMLegMLeg* lrl);
	void norm(double* _vec);
	// IP cust --- IEND
};

#endif


