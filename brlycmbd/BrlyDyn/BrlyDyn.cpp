/**
  * \file BrlyDyn.cpp
  * Brly operation pack global code (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyopd.h>
#endif

#include "BrlyDyn.h"

// IP cust --- IBEGIN
void BrlyDyn::getRmatEquatorLeg(
			double _theta0																			// begin location angle from equatorial (x-y) plane
			, double _phi0																			// begin location angle from x-axis
			, double _theta1																		// end location angle from equatorial (x-y) plane
			, double _phi1																			// end location angle from x-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	// rotate begin location onto (1,0,0)
	double* zeromat = NULL;
	getRmatZeroLocation(_theta0, _phi0, &zeromat);

	// incorporate x-rotation such that end location is on equator
	double* pos1cart = NULL;
	double* rotpos1cart = NULL;

	sphrToCart(1.0, _theta1, _phi1, &pos1cart);
	multAmatBvec(zeromat, pos1cart, &rotpos1cart, 3);
	
	double phix = acos(rotpos1cart[1] / sqrt(rotpos1cart[1]*rotpos1cart[1] + rotpos1cart[2]*rotpos1cart[2]));
	
	double* xrmat = NULL;
	if (rotpos1cart[2] > 0.0)
		getXRmat(-phix, &xrmat);
	else
		getXRmat(phix, &xrmat);

	multAmatBmat(xrmat, zeromat, _rmat, 3);
	
	delete[] zeromat;
	delete[] pos1cart;
	delete[] rotpos1cart;
	delete[] xrmat;
};

void BrlyDyn::getRmatZeroLocation(
			double _theta0																			// location angle from equatorial (x-y) plane
			, double _phi0																			// location angle from x-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	// rotate location onto z axis
	// z-rotation by -phi0, then y-rotation by -(90deg-theta0)
	double* zrmat = NULL;
	getZRmat(-_phi0, &zrmat);
	double* yrmat = NULL;
	getYRmat(-_theta0, &yrmat);

	multAmatBmat(yrmat, zrmat, _rmat, 3);
	
	delete[] zrmat;
	delete[] yrmat;
};

void BrlyDyn::getXRmat(
			double _phiX																				// angle for rotation around x-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = 1.0; rmat[1] = 0.0; rmat[2] = 0.0;
	rmat[3] = 0.0; rmat[4] = cos(_phiX); rmat[5] = -sin(_phiX);
	rmat[6] = 0.0; rmat[7] = sin(_phiX); rmat[8] = cos(_phiX);
};

void BrlyDyn::getYRmat(
			double _phiY																				// angle for rotation around y-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = cos(_phiY); rmat[1] = 0.0; rmat[2] = -sin(_phiY);
	rmat[3] = 0.0; rmat[4] = 1.0; rmat[5] = 0.0;
	rmat[6] = sin(_phiY); rmat[7] = 0.0; rmat[8] = cos(_phiY);
};

void BrlyDyn::getZRmat(
			double _phiZ																				// angle for rotation around z-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = cos(_phiZ); rmat[1] = -sin(_phiZ); rmat[2] = 0.0;
	rmat[3] = sin(_phiZ); rmat[4] = cos(_phiZ); rmat[5] = 0.0;
	rmat[6] = 0.0; rmat[7] = 0.0; rmat[8] = 1.0;
};

void BrlyDyn::transpAmat(
			double* _amat																				// _N*_N input matrix (for matrix operation _amatT=_amat')
			, double** _amatT																		// pointer to _N*_N output matrix ; created if NULL
			, unsigned int _N																		// matrix dimension
		) {
	if (*_amatT == NULL) *_amatT = new double[_N*_N];
	double* amatT = *_amatT;
	
	// i: rows, j: columns
	for (unsigned int i=0;i<_N;i++)
		for (unsigned int j=0;j<_N;j++) amatT[i*_N+j] = _amat[j*_N+i];
};

void BrlyDyn::multAmatBmat(
			double* _amat																				// _N*_N input matrix (for matrix operation _cmat=_amat._bmat)
			, double* _bmat																			// _N*_N input matrix
			, double** _cmat																		// pointer to _N*_N output matrix ; created if NULL
			, unsigned int _N																		// matrix dimension
		) {
	if (*_cmat == NULL) *_cmat = new double[_N*_N];
	double* cmat = *_cmat;
	
	// i: rows, j: columns
	for (unsigned int i=0;i<_N;i++) {
		for (unsigned int j=0;j<_N;j++) {
			cmat[i*_N+j] = 0.0;
			
			for (unsigned int k=0;k<_N;k++) cmat[i*_N+j] += _amat[i*_N+k]*_bmat[k*_N+j];
		};
	};
};

void BrlyDyn::multAmatBmatT(
			double* _amat																				// _N*_N input matrix (for matrix operation _cmat=_amat._bmatT)
			, double* _bmat																			// _N*_N input matrix
			, double** _cmat																		// pointer to _N*_N output matrix ; created if NULL
			, unsigned int _N																		// matrix dimension
		) {
	if (*_cmat == NULL) *_cmat = new double[_N*_N];
	double* cmat = *_cmat;
	
	// i: rows, j: columns
	for (unsigned int i=0;i<_N;i++) {
		for (unsigned int j=0;j<_N;j++) {
			cmat[i*_N+j] = 0.0;
			
			for (unsigned int k=0;k<_N;k++) cmat[i*_N+j] += _amat[i*_N+k]*_bmat[j*_N+k];
		};
	};
};

void BrlyDyn::multAmatBvec(
			double* _amat																				// _N*_N matrix (for matrix operation _cvec=_amat._bvec)
			, double* _bvec																			// _N input vector
			, double** _cvec																		// pointer to _N output vector ; created if NULL
			, unsigned int _N																		// matrix dimension
		) {
	if (*_cvec == NULL) *_cvec = new double[_N];
	double* cvec = *_cvec;

	// i: rows, j: columns
	for (unsigned int i=0;i<_N;i++) {
		cvec[i] = 0.0;

		for (unsigned int j=0;j<_N;j++) cvec[i] += _amat[i*_N+j]*_bvec[j];
	};
};

double BrlyDyn::getDotProd(
			double* _avec																				// a input vector (double[3])
			, double* _bvec																			// b input vector (double[3])
		) {
	return(_avec[0]*_bvec[0] + _avec[1]*_bvec[1] + _avec[2]*_bvec[2]);
};

void BrlyDyn::sphrToCart(
			double _r																						// radius
			, double _theta																			// angle from equatorial (x-y) plane
			, double _phi																				// angle from x-axis
			, double** _vec																			// pointer to carterian result vector (double[3]) ; created if NULL
		) {
	if (*_vec == NULL) *_vec = new double[3];
	
	(*_vec)[0] = _r*cos(_theta)*cos(_phi);
	(*_vec)[1] = _r*cos(_theta)*sin(_phi);
	(*_vec)[2] = _r*sin(_theta);
};

void BrlyDyn::cartToSphr(
			double* _vec																				// cartesian vector
			, double* _r																				// pointer to resulting radius
			, double* _theta																		// pointer to resulting angle from equatorial (x-y) plane
			, double* _phi																			// pointer to resulting angle from x-axis
		) {
	*_r = sqrt(_vec[0]*_vec[0] + _vec[1]*_vec[1] + _vec[2]*_vec[2]);
	*_theta = asin(_vec[2] / *_r);
	*_phi = atan2(_vec[1], _vec[0]);
};

double BrlyDyn::degToRad(
			double _deg																					// angle in degrees (0° .. 360°)
		) {
	return(pi*_deg/180.0);
};

double BrlyDyn::radToDeg(
			double _rad																					// angle in degrees (0° .. 360°)
		) {
	return(180.0*_rad/pi);
};

void BrlyDyn::locToRad(
			BrlyMLocation* loc
		) {
	loc->theta = degToRad(loc->theta);
	loc->phi = degToRad(loc->phi);
	loc->alpha = degToRad(loc->alpha);
};

void BrlyDyn::legToRad(
			BrlyMLeg* leg
		) {
	leg->deltaphi = degToRad(leg->deltaphi);
	leg->alpha = degToRad(leg->alpha);
	leg->xPhi0 = degToRad(leg->xPhi0);
	leg->xPhi1 = degToRad(leg->xPhi1);
	leg->xAlpha = degToRad(leg->xAlpha);
};

void BrlyDyn::legRelLocToRad(
			BrlyRMLegMLocation* lrl
		) {
	lrl->x1VisLegphi0 = degToRad(lrl->x1VisLegphi0);
	lrl->x1VisLegphi1 = degToRad(lrl->x1VisLegphi1);
	lrl->legphi = degToRad(lrl->legphi);
	lrl->legtheta = degToRad(lrl->legtheta);
	lrl->xVisLegphi0 = degToRad(lrl->xVisLegphi0);
	lrl->xVisLegphi1 = degToRad(lrl->xVisLegphi1);
};

void BrlyDyn::legRelLegToRad(
			BrlyRMLegMLeg* lrl
		) {
	lrl->x1VisDstLegphi0 = degToRad(lrl->x1VisDstLegphi0);
	lrl->x1VisDstLegphi1 = degToRad(lrl->x1VisDstLegphi1);
	lrl->VisOrgLegphi0 = degToRad(lrl->VisOrgLegphi0);
	lrl->VisOrgLegphi1 = degToRad(lrl->VisOrgLegphi1);
	lrl->xVisDstLegphi0 = degToRad(lrl->xVisDstLegphi0);
	lrl->xVisDstLegphi1 = degToRad(lrl->xVisDstLegphi1);
	lrl->xVisOrgLegphi0 = degToRad(lrl->xVisOrgLegphi0);
	lrl->xVisOrgLegphi1 = degToRad(lrl->xVisOrgLegphi1);
};

void BrlyDyn::conRelFltToRad(
			BrlyRMConnectionMFlight* crf
		) {
	crf->x2Legphi0 = degToRad(crf->x2Legphi0);
	crf->x2Legphi1 = degToRad(crf->x2Legphi1);
};

void BrlyDyn::conRelFltToDeg(
			BrlyRMConnectionMFlight* crf
		) {
	crf->x2Legphi0 = radToDeg(crf->x2Legphi0);
	crf->x2Legphi1 = radToDeg(crf->x2Legphi1);
};
// IP cust --- IEND


