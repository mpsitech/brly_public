/**
  * \file BrlyDnsmapFrame.cpp
  * Brly operation processor -  (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyopd.h>
#endif

#include "BrlyDnsmapFrame.h"

DpchRetBrlyDnsmapFrame* BrlyDnsmapFrame::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDnsmapFrame* dpchinv
		) {
	ubigint refBrlyMFile = dpchinv->refBrlyMFile;
	bool fullsize = dpchinv->fullsize;
	bool grayscale = dpchinv->grayscale;
	double altzmax = dpchinv->altzmax;
	uint tIx = dpchinv->tIx;

	bool success;

	string filename;

	// IP run --- IBEGIN
	ostringstream str;
	string s;

	BrlyMFile* fil = NULL;

	string path;

	int cdfRoot;

	int dimid;

	unsigned int width, height;

	bool good, found;

	unsigned char* imgdat = NULL;

	uint fullheight, fullwidth;
	uint x0, x1, y0, y1;

	bool spczmax = (altzmax < 1.0e36);

	// --- load and vaildate data

	// -- cdf file via archive
cout << "refBrlyMFile = " << refBrlyMFile << endl;
	dbsbrly->tblbrlymfile->loadRecByRef(refBrlyMFile, &fil);
	s = xchg->acvpath + "/" + fil->Archivename.substr(0, 5) + "/" + fil->Archivename;
	delete fil;

	nc_open(s.c_str(), 0, &cdfRoot);

	// get single variables
	Cdf::getUint(cdfRoot, "", "fullheight", fullheight);
	Cdf::getUint(cdfRoot, "", "fullwidth", fullwidth);
	Cdf::getUint(cdfRoot, "", "x0", x0);
	Cdf::getUint(cdfRoot, "", "x1", x1);
	Cdf::getUint(cdfRoot, "", "y0", y0);
	Cdf::getUint(cdfRoot, "", "y1", y1);

cout << x0 << " " << x1 << " " << y0 << " " << y1 << endl;

cout << "success fetching single variables!" << endl;

	// get slice in time
	good = Cdf::getDim(cdfRoot, "", "dimPhi", dimid, width);
if (!good) cout << "failure with dimPhi" << endl;
	good = Cdf::getDim(cdfRoot, "", "dimTheta", dimid, height);
if (!good) cout << "failure with dimTheta" << endl;

	vector<string> slcDims;
	slcDims.push_back("dimT");

	vector<int> slcIcs;
	slcIcs.push_back(tIx);

	vector<double> dns;
	dns.resize(width*height);

	good = Cdf::getDoubleVecSlc(cdfRoot, "", "dns", slcDims, slcIcs, width*height, dns);
if (!good) cout << "failure with slice in time" << endl;

	nc_close(cdfRoot);

	// --- generate png output
	if (good) {
		cout << "yeah ;-) !" << endl;

		if (fullsize) {
			preparePng(dns, spczmax, altzmax, width, height, fullwidth, fullheight, x0, y0, grayscale, &imgdat);
			dpchret->filename = writePng(xchg->tmppath, imgdat, fullwidth, fullheight);
		} else {
			preparePng(dns, spczmax, altzmax, width, height, width, height, 0, 0, grayscale, &imgdat);
			dpchret->filename = writePng(xchg->tmppath, imgdat, width, height);
		};
	};

	scalePng(xchg->tmppath, 80, 500, grayscale);
	// IP run --- IEND

	return(new DpchRetBrlyDnsmapFrame("", "", success, filename));
};

// IP cust --- INSERT


