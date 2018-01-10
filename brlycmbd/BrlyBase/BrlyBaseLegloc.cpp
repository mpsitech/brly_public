/**
  * \file BrlyBaseLegloc.cpp
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

#include "BrlyBaseLegloc.h"

DpchRetBrly* BrlyBaseLegloc::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyBaseLegloc* dpchinv
		) {
	uint numFirst = dpchinv->numFirst;
	uint numLast = dpchinv->numLast;
	vector<ubigint> refsBrlyMLeg = dpchinv->refsBrlyMLeg;
	vector<ubigint> refsBrlyMLocation = dpchinv->refsBrlyMLocation;
	bool append = dpchinv->append;
	bool appendloc = dpchinv->appendloc;

	bool success;

	// IP run --- IBEGIN
	ostringstream sqlstr;

	ListBrlyMLeg legs;
	BrlyMLeg* leg = NULL;

	ListBrlyMLocation locs;
	BrlyMLocation* loc = NULL;

	ListBrlyMLeg newlegs;
	BrlyMLeg* newleg = NULL;

	ListBrlyMLocation newlocs;
	BrlyMLocation* newloc = NULL;

	for (unsigned int i=0;i<refsBrlyMLeg.size();i++) {
		if (dbsbrly->tblbrlymleg->loadRecByRef(refsBrlyMLeg[i], &newleg)) {
			legToRad(newleg);
			newlegs.nodes.push_back(newleg);
		};
	};

	for (unsigned int i=0;i<refsBrlyMLocation.size();i++) {
		if (dbsbrly->tblbrlymlocation->loadRecByRef(refsBrlyMLocation[i], &newloc)) {
			locToRad(newloc);
			newlocs.nodes.push_back(newloc);
		};
	};

	if (append) {
		// standard / add legs
		
		// all locations
		dbsbrly->tblbrlymlocation->loadRst(false, locs);
		for (unsigned int i=0;i<locs.nodes.size();i++) locToRad(locs.nodes[i]);

		if (refsBrlyMLeg.size() == 0) {
			if ((numFirst == 0) && (numLast == 0)) {
				// all legs
				dbsbrly->tblbrlymleg->loadRst(false, legs);
				for (unsigned int i=0;i<legs.nodes.size();i++) legToRad(legs.nodes[i]);

			} else {
				// block of legs
				sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMLeg WHERE Calcdone = 0 ORDER BY ref ASC LIMIT " << numFirst << ", " << (numLast-numFirst+1);
				dbsbrly->tblbrlymleg->loadRstBySQL(sqlstr.str(), false, legs);
				for (unsigned int i=0;i<legs.nodes.size();i++) legToRad(legs.nodes[i]);
			};
		
		} else {
			// new legs
			for (unsigned int i=0;i<newlegs.nodes.size();i++) {
				leg = new BrlyMLeg(*(newlegs.nodes[i]));
				legs.nodes.push_back(leg);
			};
		};

	} else if (appendloc) {
		// add locations

		// all legs
		dbsbrly->tblbrlymleg->loadRst(false, legs);
		for (unsigned int i=0;i<legs.nodes.size();i++) legToRad(legs.nodes[i]);

		// new locations
		for (unsigned int i=0;i<newlocs.nodes.size();i++) {
			loc = new BrlyMLocation(*(newlocs.nodes[i]));
			locs.nodes.push_back(loc);
		};
	};

	calcVis(dbsbrly, legs, locs, xchg->stgbrlygeometry.earthradius);
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
void BrlyBaseLegloc::calcVis(
			DbsBrly* dbsbrly
			, const ListBrlyMLeg& legs
			, const ListBrlyMLocation& locs
			, const double earthradius
		) {
	ostringstream sqlstr;

	BrlyMLeg* leg = NULL;
	BrlyMLocation* loc = NULL;

	ListBrlyRMLegMLocation lrls;

	BrlyRMLegMLocation lrlprep;

	double a, b, c;

	double* loccart = NULL;
	double locr, loctheta, locphi;

	double* legrmat = NULL;
	double legr = 0.0;
	bool legrnew;

	vector<double> localpha1s;
	double localpha1;

	ListBrlyMLocation bgnlocs;
	BrlyMLocation* bgnloc = NULL;
	ListBrlyMLocation endlocs;
	BrlyMLocation* endloc = NULL;

	// load leg begin and end locations
	for (unsigned int i=0;i<legs.nodes.size();i++) {
		leg = legs.nodes[i];

		dbsbrly->tblbrlymlocation->loadRecByRef(leg->bgnRefBrlyMLocation, &loc);
		locToRad(loc);
		bgnlocs.nodes.push_back(loc);

		dbsbrly->tblbrlymlocation->loadRecByRef(leg->endRefBrlyMLocation, &loc);
		locToRad(loc);
		endlocs.nodes.push_back(loc);
	};

	localpha1s.resize(locs.nodes.size(), 0.0);
	for (unsigned int i=0;i<locs.nodes.size();i++) localpha1s[i] = locs.nodes[i]->alpha;

	// traverse legs
	for (unsigned int i=0;i<legs.nodes.size();i++) {
		leg = legs.nodes[i];

		legrnew = ((earthradius+leg->alt) != legr);
		legr = earthradius + leg->alt;

		bgnloc = bgnlocs.nodes[i];
		endloc = endlocs.nodes[i];

		// find inverse of leg rotation matrix
		getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &legrmat);

		// as for ground locations, re-calculate substitutional opening angles, if legr has changed
		if (legrnew) {
			for (unsigned int j=0;j<locs.nodes.size();j++) {
				loc = locs.nodes[j];

//				if (loc->ixVBasetype != VecBrlyVMLocationBasetype::ELV) localpha1s[j] = atan2(leg->alt-loc->alt, tan(pi/2.0-loc->alpha) * (earthradius+leg->alt));
				if (loc->ixVBasetype != VecBrlyVMLocationBasetype::ELV) zeroAgp(earthradius, leg->alt, loc->alt, loc->alpha, 1.0*2.0*pi/360.0, 1.0e-6, &localpha1s[j]);
			};
		};

		// traverse locations
		for (unsigned int j=0;j<locs.nodes.size();j++) {
			loc = locs.nodes[j];
			locr = earthradius + loc->alt;
			localpha1 = localpha1s[j];

			// rotate loc into leg cartesian and spherical coordinates (targets loccart and locr/loctheta/locphi)
			sphrToCart(1.0, loc->theta, loc->phi, &loccart);
			a = legrmat[0]*loccart[0] + legrmat[1]*loccart[1] + legrmat[2]*loccart[2];
			b = legrmat[3]*loccart[0] + legrmat[4]*loccart[1] + legrmat[5]*loccart[2];
			c = legrmat[6]*loccart[0] + legrmat[7]*loccart[1] + legrmat[8]*loccart[2];
			loccart[0] = a; loccart[1] = b; loccart[2] = c;
			cartToSphr(loccart, &locr, &loctheta, &locphi);

			// prepare database entry with information already known here
			lrlprep.x1VisLegphi0 = 0.0;
			lrlprep.x1VisLegphi1 = 0.0;
			lrlprep.refBrlyMLeg = leg->ref;
			lrlprep.refBrlyMLocation = loc->ref;
			if (fabs(locphi) < 1.0e-9) locphi = 0.0;
			lrlprep.legphi = locphi;
			if (fabs(loctheta) < 1.0e-9) loctheta = 0.0;
			lrlprep.legtheta = loctheta;

			if (leg->ixVBasetype == VecBrlyVMLegBasetype::CORR) {
				// simple is-in check (x1VisLegphi0/1 not calculated)
				if ((loctheta > (-leg->alpha)) && (loctheta < leg->alpha)) {
					// relax this condition a little to include begin/end locations (correct would be 0.0 .. leg->delatphi)
					if ((locphi > -1.0e-6) && (locphi < (leg->deltaphi+1.0e-6))) {
						lrls.nodes.push_back(new BrlyRMLegMLocation(lrlprep));
					};
				};

			} else if (leg->ixVBasetype == VecBrlyVMLegBasetype::RTE) {
				// complex cone-pierce check
				if ((loctheta > (-localpha1)) && (loctheta < localpha1)) {
					lrlprep.x1VisLegphi0 = locphi - sqrt(localpha1*localpha1 - loctheta*loctheta);
					lrlprep.x1VisLegphi1 = locphi + sqrt(localpha1*localpha1 - loctheta*loctheta);
					
					// check for overlap with leg
					if ((lrlprep.x1VisLegphi0 < leg->deltaphi) && (lrlprep.x1VisLegphi1 > 0.0)) {
						if (lrlprep.x1VisLegphi0 < 0.0) lrlprep.x1VisLegphi0 = 0.0;
						if (lrlprep.x1VisLegphi1 > leg->deltaphi) lrlprep.x1VisLegphi1 = leg->deltaphi;

						lrls.nodes.push_back(new BrlyRMLegMLocation(lrlprep));
					};
				};
			};
		};
	};

	// insert all lrl's at a time
	for (unsigned int i=0;i<lrls.nodes.size();i++) legRelLocToDeg(lrls.nodes[i]);
	dbsbrly->tblbrlyrmlegmlocation->insertRst(lrls, true);
};

inline double BrlyBaseLegloc::xsecAgp(
			const double re
			, const double af
			, const double eg
			, const double ag
			, const double agp0
		) {
	double delta = (re+af)*(1.0-cos(agp0));
	return(agp0 - atan2(af-eg-delta, (re+af-delta)*tan(pi/2.0-ag)));
};

inline double BrlyBaseLegloc::drvxsecAgp(
			const double re
			, const double af
			, const double eg
			, const double ag
			, const double agp0
		) {
	return((xsecAgp(re, af, eg, ag, agp0+1.0e-6)-xsecAgp(re, af, eg, ag, agp0-1.0e-6)) / 2.0e-6);
};

bool BrlyBaseLegloc::zeroAgp(
			const double re
			, const double af
			, const double eg
			, const double ag
			, const double agpini
			, const double tol
			, double* agp
		)	{
	bool retval = false;

	double agptest = agpini;

	double xsec, xsecnew, dxsec, residual;

	xsec = xsecAgp(re, af, eg, ag, agptest);
	residual = fabs(xsec);

	while (residual > tol) {
		// change agptest using Newton method
		dxsec = drvxsecAgp(re, af, eg, ag, agptest);
		agptest = agptest - xsec/dxsec;

		// re-evaluate
		xsecnew = xsecAgp(re, af, eg, ag, agptest);
		if (fabs(xsecnew-xsec) < 1.0e-6) break;
		xsec = xsecnew;
		
		// require that residual becomes smaller on each iteration
		if (fabs(xsec) >= residual) break;
		residual = fabs(xsec);
	};

	if (residual <= tol) {
		// check if agp is in range
		if ((agptest > 0.0) && (agptest < (0.5*pi))) {
			*agp = agptest;
			retval = true;
		};
	};

	return retval;
};
// IP cust --- IEND


