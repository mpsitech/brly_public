/**
  * \file BrlyBase.cpp
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

#include "BrlyBase.h"

// IP cust --- IBEGIN
bool BrlyBase::isInZeroApexCone(
			double* _axisCone																		// normal vector of cone axis (double[3])
			, double _alphaCone																	// cone opening angle from axis
			, double _theta																			// angle of test point from equatorial (x-y) plane
			, double _phi																				// angle of test point from x-axis
		) {
	// translate into cartesian coordinates
	double* testcart = NULL;

	sphrToCart(1.0, _theta, _phi, &testcart);

	// find cosine of angle between cone axis and test point
	double costest = _axisCone[0]*testcart[0] + _axisCone[1]*testcart[1] + _axisCone[2]*testcart[2];
	delete[] testcart;

	return(costest > cos(_alphaCone));
};

bool BrlyBase::isInZeroApexCone(
			double _thetaCone																		// angle of cone axis from equatorial (x-y) plane
			, double _phiCone																		// angle of cone axis from x-axis
			, double _alphaCone																	// cone opening angle from axis
			, double _theta																			// angle of test point from equatorial (x-y) plane
			, double _phi																				// angle of test point from x-axis
		) {
	// translate into cartesian coordinates
	double* conecart = NULL;
	double* testcart = NULL;

	sphrToCart(1.0, _thetaCone, _phiCone, &conecart);
	sphrToCart(1.0, _theta, _phi, &testcart);

	// find cosine of angle between cone axis and test point
	double costest = conecart[0]*testcart[0] + conecart[1]*testcart[1] + conecart[2]*testcart[2];

	delete[] conecart;
	delete[] testcart;

	return(costest > cos(_alphaCone));
};

bool BrlyBase::isInCone(
			double _rCone																				// cone apex radius
			, double _thetaCone																	// angle of cone axis from equatorial (x-y) plane
			, double _phiCone																		// angle of cone axis from x-axis
			, double _alphaCone																	// cone opening angle from axis
			, double _r																					// test point radius
			, double _theta																			// angle of test point from equatorial (x-y) plane
			, double _phi																				// angle of test point from x-axis
		) {
	// translate into cartesian coordinates
	double* conecart = NULL;
	double* testcart = NULL;

	sphrToCart(_rCone, _thetaCone, _phiCone, &conecart);
	sphrToCart(_r, _theta, _phi, &testcart);

	// substract apex point from test point
	testcart[0] = testcart[0]-conecart[0];
	testcart[1] = testcart[1]-conecart[1];
	testcart[2] = testcart[2]-conecart[2];

	// find cosine of angle between cone axis and test point
	double costest = conecart[0]*testcart[0] + conecart[1]*testcart[1] + conecart[2]*testcart[2];

	costest /= _rCone;
	costest /= sqrt(testcart[0]*testcart[0] + testcart[1]*testcart[1] + testcart[2]*testcart[2]);

	delete[] conecart;
	delete[] testcart;

	return(costest > cos(_alphaCone));
};

void BrlyBase::getRmatEquatorLeg(
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

void BrlyBase::getRmatZeroLocation(
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

void BrlyBase::getXRmat(
			double _phiX																				// angle for rotation around x-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = 1.0; rmat[1] = 0.0; rmat[2] = 0.0;
	rmat[3] = 0.0; rmat[4] = cos(_phiX); rmat[5] = -sin(_phiX);
	rmat[6] = 0.0; rmat[7] = sin(_phiX); rmat[8] = cos(_phiX);
};

void BrlyBase::getYRmat(
			double _phiY																				// angle for rotation around y-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = cos(_phiY); rmat[1] = 0.0; rmat[2] = -sin(_phiY);
	rmat[3] = 0.0; rmat[4] = 1.0; rmat[5] = 0.0;
	rmat[6] = sin(_phiY); rmat[7] = 0.0; rmat[8] = cos(_phiY);
};

void BrlyBase::getZRmat(
			double _phiZ																				// angle for rotation around z-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = cos(_phiZ); rmat[1] = -sin(_phiZ); rmat[2] = 0.0;
	rmat[3] = sin(_phiZ); rmat[4] = cos(_phiZ); rmat[5] = 0.0;
	rmat[6] = 0.0; rmat[7] = 0.0; rmat[8] = 1.0;
};

void BrlyBase::transpAmat(
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

void BrlyBase::multAmatBmat(
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

void BrlyBase::multAmatBvec(
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

void BrlyBase::getCrossProd(
			double* _avec																				// from input vector (double[3])
			, double* _bvec																			// to input vector (double[3])
			, double** _cvec																		// cross product output vector (double[3]) ; created if NULL
		) {
	if (*_cvec == NULL) *_cvec = new double[3];

	(*_cvec)[0] = _avec[1]*_bvec[2] - _avec[2]*_bvec[1];
	(*_cvec)[1] = _avec[2]*_bvec[0] - _avec[0]*_bvec[2];
	(*_cvec)[2] = _avec[0]*_bvec[1] - _avec[1]*_bvec[0];
};

double BrlyBase::getDotProd(
			double* _avec																				// a input vector (double[3])
			, double* _bvec																			// b input vector (double[3])
		) {
	return(_avec[0]*_bvec[0] + _avec[1]*_bvec[1] + _avec[2]*_bvec[2]);
};

void BrlyBase::sphrToCart(
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

void BrlyBase::cartToSphr(
			double* _vec																				// cartesian vector
			, double* _r																				// pointer to resulting radius
			, double* _theta																		// pointer to resulting angle from equatorial (x-y) plane
			, double* _phi																			// pointer to resulting angle from x-axis
		) {
	*_r = sqrt(_vec[0]*_vec[0] + _vec[1]*_vec[1] + _vec[2]*_vec[2]);
	*_theta = asin(_vec[2] / *_r);
	*_phi = atan2(_vec[1], _vec[0]);
};

double BrlyBase::degToRad(
			double _deg																					// angle in degrees (0° .. 360°)
		) {
	return(pi*_deg/180.0);
};

double BrlyBase::radToDeg(
			double _rad																					// angle in degrees (0° .. 360°)
		) {
	return(180.0*_rad/pi);
};

void BrlyBase::legToRad(
			BrlyMLeg* leg
		) {
	leg->deltaphi = degToRad(leg->deltaphi);
	leg->alpha = degToRad(leg->alpha);
	leg->xPhi0 = degToRad(leg->xPhi0);
	leg->xPhi1 = degToRad(leg->xPhi1);
	leg->xAlpha = degToRad(leg->xAlpha);
};

void BrlyBase::legToDeg(
			BrlyMLeg* leg
		) {
	leg->deltaphi = radToDeg(leg->deltaphi);
	leg->alpha = radToDeg(leg->alpha);
	leg->xPhi0 = radToDeg(leg->xPhi0);
	leg->xPhi1 = radToDeg(leg->xPhi1);
	leg->xAlpha = radToDeg(leg->xAlpha);
};

void BrlyBase::locToRad(
			BrlyMLocation* loc
		) {
	loc->theta = degToRad(loc->theta);
	loc->phi = degToRad(loc->phi);
	loc->alpha = degToRad(loc->alpha);
};

void BrlyBase::locToDeg(
			BrlyMLocation* loc
		) {
	loc->theta = radToDeg(loc->theta);
	loc->phi = radToDeg(loc->phi);
	loc->alpha = radToDeg(loc->alpha);
};

void BrlyBase::legRelLocToDeg(
			BrlyRMLegMLocation* lrl
		) {
	lrl->x1VisLegphi0 = radToDeg(lrl->x1VisLegphi0);
	lrl->x1VisLegphi1 = radToDeg(lrl->x1VisLegphi1);
	lrl->legphi = radToDeg(lrl->legphi);
	lrl->legtheta = radToDeg(lrl->legtheta);
	lrl->xVisLegphi0 = radToDeg(lrl->xVisLegphi0);
	lrl->xVisLegphi1 = radToDeg(lrl->xVisLegphi1);
};

void BrlyBase::legRelLegToDeg(
			BrlyRMLegMLeg* lrl
		) {
	lrl->x1VisDstLegphi0 = radToDeg(lrl->x1VisDstLegphi0);
	lrl->x1VisDstLegphi1 = radToDeg(lrl->x1VisDstLegphi1);
	lrl->VisOrgLegphi0 = radToDeg(lrl->VisOrgLegphi0);
	lrl->VisOrgLegphi1 = radToDeg(lrl->VisOrgLegphi1);
	lrl->xVisDstLegphi0 = radToDeg(lrl->xVisDstLegphi0);
	lrl->xVisDstLegphi1 = radToDeg(lrl->xVisDstLegphi1);
	lrl->xVisOrgLegphi0 = radToDeg(lrl->xVisOrgLegphi0);
	lrl->xVisOrgLegphi1 = radToDeg(lrl->xVisOrgLegphi1);
};

void BrlyBase::norm(
			double* _vec
		) {
	double r = sqrt(_vec[0]*_vec[0] + _vec[1]*_vec[1] + _vec[2]*_vec[2]);

	_vec[0] /= r;
	_vec[1] /= r;
	_vec[2] /= r;
};
// IP cust --- IEND


