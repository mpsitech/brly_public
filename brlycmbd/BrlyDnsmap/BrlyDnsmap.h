/**
  * \file BrlyDnsmap.h
  * Brly operation pack global code (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDNSMAP_H
#define BRLYDNSMAP_H

#include "BrlyDnsmap_blks.h"

// IP incl --- IBEGIN
#include <png.h>
// IP incl --- IEND

namespace BrlyDnsmap {
	// IP cust --- IBEGIN
	void scalePng(const string& tmppath, const unsigned int width, const unsigned int height, const bool grayscale);
	void preparePng(vector<double>& zdat, const bool spczmax, double zmax, const unsigned int width, const unsigned int height, const unsigned int fullwidth, const unsigned int fullheight, const unsigned int x0, const unsigned int y0, const bool grayscale, unsigned char** imgdat);
	string writePng(const string& tmppath, unsigned char* imgdat, const unsigned int width, const unsigned int height);
	void setPngPixel(unsigned char* imgdat, const unsigned int width, const unsigned int height, const unsigned int x, const unsigned int y, const unsigned char rval, const unsigned char gval, const unsigned char bval);
	// IP cust --- IEND
};

#endif


