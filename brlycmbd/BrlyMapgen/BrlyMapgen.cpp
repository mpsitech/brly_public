/**
  * \file BrlyMapgen.cpp
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

#include "BrlyMapgen.h"

void BrlyMapgen::initXchgdata(
			XchgBrly* xchg
		) {
};

void BrlyMapgen::termXchgdata(
			XchgBrly* xchg
		) {
};

// IP cust --- IBEGIN
/******************************************************************************
 class BrlyMapgen::Coo
 ******************************************************************************/

BrlyMapgen::Coo::Coo(
			const unsigned int type
			, const double x
			, const double y
			, const double lam
		) {

	this->type = type;
	this->x = x;
	this->y = y;
	this->lam = lam;
};

/******************************************************************************
 namespace BrlyMapgen
 ******************************************************************************/

void BrlyMapgen::writeMappng(
			XchgBrly* xchg
			, const string& outpath
			, const int width
			, const int height
			, short* z
		) {
	vector<utinyint>& _RvsZ = xchg->databrlymapgen.RvsZ;
	vector<utinyint>& _GvsZ = xchg->databrlymapgen.GvsZ;
	vector<utinyint>& _BvsZ = xchg->databrlymapgen.BvsZ;

	FILE* fp;

	unsigned int ix;

	unsigned char* imgdat;
	imgdat = new unsigned char[4*width*height];

	unsigned char** rowptr;
	rowptr = new unsigned char*[height];

	// vertical flip
	for (int i=0;i<height;i++) rowptr[i] = &(imgdat[4*width*(height-i-1)]);

	// transform into RGB (8bit per channel)
	for (int i=0;i<height;i++) {
		for (int j=0;j<width;j++) {
			ix = z[i*width+j] + 32768;

			// store in binary image data
			imgdat[4*(i*width+j)+1] = _RvsZ[ix];
			imgdat[4*(i*width+j)+2] = _GvsZ[ix];
			imgdat[4*(i*width+j)+3] = _BvsZ[ix];
		}
	};

	// --- write using libpng
	png_structp png_ptr;
	png_infop info_ptr;

	// open file
	fp = fopen(outpath.c_str(), "wb");
	// if (!fp) return;

	// allocate structures
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	info_ptr = png_create_info_struct(png_ptr);

	// set error handling
	setjmp(png_jmpbuf(png_ptr));

	// set up output control
	png_init_io(png_ptr, fp);

	// set file information
	png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	// write file information
	png_write_info(png_ptr, info_ptr);

	// pack RGB into 3 bytes
	png_set_filler(png_ptr, 0, PNG_FILLER_BEFORE);

	// write image
	png_write_image(png_ptr, rowptr);

	// write rest of file
	png_write_end(png_ptr, info_ptr);

	// clean up
	png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);

	delete[] imgdat;
	delete[] rowptr;

	// close file
	fclose(fp);
};

void BrlyMapgen::getRmatEquatorLeg(
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

void BrlyMapgen::getRmatZeroLocation(
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

void BrlyMapgen::getXRmat(
			double _phiX																				// angle for rotation around x-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = 1.0; rmat[1] = 0.0; rmat[2] = 0.0;
	rmat[3] = 0.0; rmat[4] = cos(_phiX); rmat[5] = -sin(_phiX);
	rmat[6] = 0.0; rmat[7] = sin(_phiX); rmat[8] = cos(_phiX);
};

void BrlyMapgen::getYRmat(
			double _phiY																				// angle for rotation around y-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = cos(_phiY); rmat[1] = 0.0; rmat[2] = -sin(_phiY);
	rmat[3] = 0.0; rmat[4] = 1.0; rmat[5] = 0.0;
	rmat[6] = sin(_phiY); rmat[7] = 0.0; rmat[8] = cos(_phiY);
};

void BrlyMapgen::getZRmat(
			double _phiZ																				// angle for rotation around z-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = cos(_phiZ); rmat[1] = -sin(_phiZ); rmat[2] = 0.0;
	rmat[3] = sin(_phiZ); rmat[4] = cos(_phiZ); rmat[5] = 0.0;
	rmat[6] = 0.0; rmat[7] = 0.0; rmat[8] = 1.0;
};

void BrlyMapgen::multAmatBmat(
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

void BrlyMapgen::multAmatBmatT(
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

void BrlyMapgen::multAmatBvec(
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

void BrlyMapgen::sphrToCart(
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

double BrlyMapgen::degToRad(
			double _deg																					// angle in degrees (0° .. 360°)
		) {
	return(pi*_deg/180.0);
};

double BrlyMapgen::radToDeg(
			double _rad																					// angle in degrees (0° .. 360°)
		) {
	return(180.0*_rad/pi);
};

void BrlyMapgen::locToRad(
			BrlyMLocation* loc
		) {
	loc->theta = degToRad(loc->theta);
	loc->phi = degToRad(loc->phi);
	loc->alpha = degToRad(loc->alpha);
};

void BrlyMapgen::legToRad(
			BrlyMLeg* leg
		) {
	leg->deltaphi = degToRad(leg->deltaphi);
	leg->alpha = degToRad(leg->alpha);
	leg->xPhi0 = degToRad(leg->xPhi0);
	leg->xPhi1 = degToRad(leg->xPhi1);
	leg->xAlpha = degToRad(leg->xAlpha);
};
// IP cust --- IEND


