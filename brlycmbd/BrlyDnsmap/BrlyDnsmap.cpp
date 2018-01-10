/**
  * \file BrlyDnsmap.cpp
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

#include "BrlyDnsmap.h"

// IP cust --- IBEGIN
void BrlyDnsmap::scalePng(
			const string& tmppath
			, const unsigned int width
			, const unsigned int height
			, const bool grayscale
		) {
	double d;

	unsigned char* imgdat = NULL;

	vector<double> zdat;
	zdat.resize(width*height, 0.0);

	for (unsigned int k=0;k<height;k++) {
		d = ((double) k)/((double) height);
		for (unsigned int l=0;l<width;l++) zdat[l*height+k] = d;
	};

	preparePng(zdat, true, 1.0, width, height, width, height, 0, 0, grayscale, &imgdat);
	cout << "scale file: " << writePng(tmppath, imgdat, width, height) << endl;
};

void BrlyDnsmap::preparePng(
			vector<double>& zdat
			, const bool spczmax
			, double zmax
			, const unsigned int width
			, const unsigned int height
			, const unsigned int fullwidth
			, const unsigned int fullheight
			, const unsigned int x0
			, const unsigned int y0
			, const bool grayscale
			, unsigned char** imgdat
		) {
	unsigned char rval, gval, bval;
	double zval;

	// - determine max. value
	if (!spczmax) {
		zmax = 0.0;
		for (unsigned int i=0;i<zdat.size();i++) if (zdat[i] > zmax) zmax = zdat[i];
	};

cout << "zmax = " << zmax << endl;

	// - set up PNG data structure, initialize in white
	*imgdat = new unsigned char[4*fullwidth*fullheight];

	rval = 255;
	gval = 255;
	bval = 255;

	for (unsigned int k=0;k<fullheight;k++) {
		for (unsigned int l=0;l<fullwidth;l++) {
			setPngPixel(*imgdat, fullwidth, fullheight, l, k, rval, gval, bval);
		};
	};

	// - fill PNG data buffer
	for (unsigned int k=0;k<height;k++) {
		for (unsigned int l=0;l<width;l++) {
			if (zmax == 0.0) {
				rval = 127;
				gval = 127;
				bval = 127;

			} else {
				zval = zdat[l*height+k];
				zval = zval/zmax;

				if (grayscale) {
					rval = (unsigned char) round(255.0 * zval);
					gval = rval;
					bval = rval;

				} else {
					// white -> blue -> cyan -> green -> yellow -> red
					if (zval == 0.0) {
						rval = 255;
						gval = 255;
						bval = 255;
					} else if (zval < 0.25) {
						rval = 0;
						gval = (unsigned char) fabs(round(255.0 * 4.0*(zval)));
						bval = 255;
					} else if ((zval >= 0.25) && (zval < 0.5)) {
						rval = 0;
						gval = 255;
						bval = (unsigned char) fabs(round(255.0 * 4.0*(0.5-zval)));
					} else if ((zval >= 0.5) && (zval < 0.75)) {
						rval = (unsigned char) fabs(round(255.0 * 4.0*(zval-0.5)));
						gval = 255;
						bval = 0;
					} else {
						rval = 255;
						gval = (unsigned char) fabs(round(255.0 * 4.0*(1.0-zval)));
						bval = 0;
					};
				};
			};

			setPngPixel(*imgdat, fullwidth, fullheight, l+x0, k+y0, rval, gval, bval);
		};
	};
};

string BrlyDnsmap::writePng(
			const string& tmppath
			, unsigned char* imgdat
			, const unsigned int width
			, const unsigned int height
		) {
	string s;

	string outfile;
	FILE* fp;

	unsigned char** rowptr;

	png_structp png_ptr;
	png_infop info_ptr;

	// create and open file
	outfile = Tmp::newfile(tmppath, "png");
	s = tmppath + "/" + outfile;

	fp = fopen(s.c_str(), "wb");

	// set row pointers
	rowptr = new unsigned char*[height];
	for (unsigned int k=0;k<height;k++) rowptr[k] = &(imgdat[4*width*(height-k-1)]);

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

	return outfile;
};

inline void BrlyDnsmap::setPngPixel(
			unsigned char* imgdat
			, const unsigned int width
			, const unsigned int height
			, const unsigned int x
			, const unsigned int y
			, const unsigned char rval
			, const unsigned char gval
			, const unsigned char bval
		) {
	if ((x < width) && (y < height)) {
		imgdat[4*(y*width+x)+1] = rval;
		imgdat[4*(y*width+x)+2] = gval;
		imgdat[4*(y*width+x)+3] = bval;
	};
};
// IP cust --- IEND


