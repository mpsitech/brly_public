/**
  * \file BrlyDnsmapVideo.cpp
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

#include "BrlyDnsmapVideo.h"

DpchRetBrlyDnsmapVideo* BrlyDnsmapVideo::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDnsmapVideo* dpchinv
		) {
	double altzmax = dpchinv->altzmax;
	uint frmrate = dpchinv->frmrate;
	bool fullsize = dpchinv->fullsize;
	bool grayscale = dpchinv->grayscale;
	ubigint refBrlyMFile = dpchinv->refBrlyMFile;

	bool success;

	string folder;

	// IP run --- INSERT

	return(new DpchRetBrlyDnsmapVideo("", "", success, folder));
};

// IP cust --- INSERT

