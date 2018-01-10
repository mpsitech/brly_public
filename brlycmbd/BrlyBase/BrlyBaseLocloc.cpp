/**
  * \file BrlyBaseLocloc.cpp
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

#include "BrlyBaseLocloc.h"

DpchRetBrly* BrlyBaseLocloc::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyBaseLocloc* dpchinv
		) {
	uint numFirst = dpchinv->numFirst;
	uint numLast = dpchinv->numLast;
	vector<ubigint> refsBrlyMLocation = dpchinv->refsBrlyMLocation;
	bool append = dpchinv->append;
	bool intermix = dpchinv->intermix;

	bool success;

	// IP run --- IBEGIN
	ostringstream sqlstr;

	vector<bool> selDstlocs;
	ListBrlyMLocation dstlocs;
	BrlyMLocation* dstloc = NULL;

	ListBrlyMLocation orglocs;

	ListBrlyMLocation newlocs;
	BrlyMLocation* newloc = NULL;

	for (unsigned int i=0;i<refsBrlyMLocation.size();i++) if (dbsbrly->tblbrlymlocation->loadRecByRef(refsBrlyMLocation[i], &newloc)) newlocs.nodes.push_back(newloc);

	// --- prepare vis

	if (append) {
		// -- standard
		
		// orglocs (airports and ground locations only)
		dbsbrly->tblbrlymlocation->loadRstByTyp(VecBrlyVMLocationBasetype::APT, false, orglocs);
		dbsbrly->tblbrlymlocation->loadRstByTyp(VecBrlyVMLocationBasetype::GND, true, orglocs);

		// dstlocs
		if (refsBrlyMLocation.size() == 0) {
			if ((numFirst == 0) && (numLast == 0)) {
				// all elevated locations
				dbsbrly->tblbrlymlocation->loadRstByTyp(VecBrlyVMLocationBasetype::ELV, false, dstlocs);

			} else {
				// block of elv locations
				dbsbrly->tblbrlymlocation->loadRstByTyp(VecBrlyVMLocationBasetype::ELV, false, dstlocs, numLast-numFirst+1, numFirst);
			};

		} else {
			// new elv locations
			for (unsigned int i=0;i<newlocs.nodes.size();i++) {
				newloc = newlocs.nodes[i];

				if (newloc->ixVBasetype == VecBrlyVMLocationBasetype::ELV) dstlocs.nodes.push_back(new BrlyMLocation(*newloc));
			};
		};

		// all entries are selected
		selDstlocs.resize(dstlocs.nodes.size(), true);
		
	} else if (intermix) {
		// -- intermix

		// orglocs: new non-elv locations
		for (unsigned int i=0;i<newlocs.nodes.size();i++) {
			newloc = newlocs.nodes[i];

			if (newloc->ixVBasetype != VecBrlyVMLocationBasetype::ELV) orglocs.nodes.push_back(new BrlyMLocation(*newloc));
		};

		// dstlocs
		dbsbrly->tblbrlymlocation->loadRstByTyp(VecBrlyVMLocationBasetype::ELV, false, dstlocs);

		// at first, all entries are selected
		selDstlocs.resize(dstlocs.nodes.size(), true);

		// de-select new elv locations
		for (unsigned int i=0;i<newlocs.nodes.size();i++) {
			newloc = newlocs.nodes[i];

			if (newloc->ixVBasetype == VecBrlyVMLocationBasetype::ELV) {
				for (unsigned int j=0;j<dstlocs.nodes.size();j++) {
					dstloc = dstlocs.nodes[j];

					if (newloc->ref == dstloc->ref) {
						selDstlocs[j] = false;
						break;
					};
				};
			};
		};
	};

	calcVis(dbsbrly, dstlocs, selDstlocs, orglocs);

	// --- prepare prox
	selDstlocs.resize(0);
	dstlocs.clear();
	orglocs.clear();

	if (append) {
		// -- standard

		// orglocs
		dbsbrly->tblbrlymlocation->loadRst(false, orglocs);

		// dstlocs
		if (refsBrlyMLocation.size() == 0) {
			if ((numFirst == 0) && (numLast == 0)) {
				// all locations
				dbsbrly->tblbrlymlocation->loadRst(false, dstlocs);

			} else {
				// block of locations
				dbsbrly->tblbrlymlocation->loadRst(false, dstlocs, numLast-numFirst+1, numFirst);
			};

		} else {
			// new locations
			for (unsigned int i=0;i<newlocs.nodes.size();i++) {
				newloc = newlocs.nodes[i];

				dstlocs.nodes.push_back(new BrlyMLocation(*newloc));
			};
		};

		// all entries are selected
		selDstlocs.resize(dstlocs.nodes.size(), true);

	} else if (intermix) {
		// -- intermix

		// orglocs: new locations
		for (unsigned int i=0;i<newlocs.nodes.size();i++) {
			newloc = newlocs.nodes[i];

			orglocs.nodes.push_back(new BrlyMLocation(*newloc));
		};

		// dstlocs
		dbsbrly->tblbrlymlocation->loadRst(false, dstlocs);

		// at first, all entries are selected
		selDstlocs.resize(dstlocs.nodes.size(), true);

		// de-select new locations
		for (unsigned int i=0;i<newlocs.nodes.size();i++) {
			newloc = newlocs.nodes[i];

			for (unsigned int j=0;j<dstlocs.nodes.size();j++) {
				dstloc = dstlocs.nodes[j];

				if (newloc->ref == dstloc->ref) {
					selDstlocs[j] = false;
					break;
				};
			};
		};
	};

	calcProx(dbsbrly, dstlocs, selDstlocs, orglocs, xchg->stgbrlygeometry.earthradius);
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
void BrlyBaseLocloc::calcVis(
			DbsBrly* dbsbrly
			, const ListBrlyMLocation& dstlocs
			, const vector<bool>& selDstlocs
			, const ListBrlyMLocation& orglocs
		) {
	BrlyMLocation* dstloc = NULL;
	BrlyMLocation* orgloc = NULL;

	ListBrlyVisRMLocationMLocation lrls;
	BrlyVisRMLocationMLocation* lrl = NULL;

	for (unsigned int i=0;i<dstlocs.nodes.size();i++) {
		if (selDstlocs[i]) {
			dstloc = dstlocs.nodes[i];

			for (unsigned int j=0;j<orglocs.nodes.size();j++) {
				orgloc = orglocs.nodes[j];

				if (isInZeroApexCone(degToRad(dstloc->theta), degToRad(dstloc->phi), degToRad(dstloc->alpha), degToRad(orgloc->theta), degToRad(orgloc->phi))) {
					lrl = new BrlyVisRMLocationMLocation(0, dstloc->ref, orgloc->ref);
					lrls.nodes.push_back(lrl);
					lrl = new BrlyVisRMLocationMLocation(0, orgloc->ref, dstloc->ref);
					lrls.nodes.push_back(lrl);
				};
			};
		};
	};

	// insert all lrl's at a time
	dbsbrly->tblbrlyvisrmlocationmlocation->insertRst(lrls, true);
};

void BrlyBaseLocloc::calcProx(
			DbsBrly* dbsbrly
			, const ListBrlyMLocation& dstlocs
			, const vector<bool>& selDstlocs
			, const ListBrlyMLocation& orglocs
			, const double earthradius
		) {

	// proximity for a map of 500km x 500km
	double maxdeltaphi = (sqrt(2.0) * 500.0e3/2.0) / earthradius;

	double* dstcart = NULL;
	double* orgcart = NULL;
	double delta;

	BrlyMLocation* dstloc = NULL;
	BrlyMLocation* orgloc = NULL;

	ListBrlyProxRMLocationMLocation lrls;
	BrlyProxRMLocationMLocation* lrl = NULL;

	for (unsigned int i=0;i<dstlocs.nodes.size();i++) {
		if (selDstlocs[i]) {
			dstloc = dstlocs.nodes[i];

			for (unsigned int j=0;j<orglocs.nodes.size();j++) {
				orgloc = orglocs.nodes[j];

				if (orgloc->ref != dstloc->ref) {
					// calculate distance in radian
					sphrToCart(1.0, degToRad(dstloc->theta), degToRad(dstloc->phi), &dstcart);
					sphrToCart(1.0, degToRad(orgloc->theta), degToRad(orgloc->phi), &orgcart);
					delta = acos(dstcart[0]*orgcart[0] + dstcart[1]*orgcart[1] + dstcart[2]*orgcart[2]);

					if (delta <= maxdeltaphi) {
						lrl = new BrlyProxRMLocationMLocation(0, dstloc->ref, orgloc->ref, radToDeg(delta));
						lrls.nodes.push_back(lrl);
					};
				};
			};
		};
	};

	// insert all lrl's at a time
	dbsbrly->tblbrlyproxrmlocationmlocation->insertRst(lrls, true);

	if (dstcart) delete [] dstcart;
	if (orgcart) delete [] orgcart;
};
// IP cust --- IEND


