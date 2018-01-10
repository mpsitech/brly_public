/**
  * \file BrlyDynFltfltloc.cpp
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

#include "BrlyDynFltfltloc.h"

DpchRetBrly* BrlyDynFltfltloc::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDynFltfltloc* dpchinv
		) {
	vector<ubigint> refsBrlyMFlight = dpchinv->refsBrlyMFlight;

	bool success;

	// IP run --- IBEGIN
	ostringstream sqlstr;

	BrlyRMFlightMLocation fltRlocprep;
	BrlyRMFlightMFlight fltRfltprep;

	ListBrlyRMFlightMFlight fltRflts;
	ListBrlyRMFlightMLocation fltRlocs;

	BrlyMLeg* dstleg = NULL;
	BrlyMLeg* orgleg = NULL;

	BrlyMLocation* bgnloc = NULL;
	BrlyMLocation* endloc = NULL;

	ListBrlyRMLegMLocation legRlocs;
	BrlyRMLegMLocation* legRloc = NULL;

	ListBrlyRMLegMLeg legRlegs;
	BrlyRMLegMLeg* legRleg= NULL;

	BrlyMFlight* dstflt = NULL;

	ListBrlyMFlight orgflts;
	BrlyMFlight* orgflt = NULL;

	double* dstrmat = NULL;
	double* orgrmat = NULL;

	double cosalpha;

	double dstomg;
	double orgomg;

	bool invtime;
	uint start;

	uint dststart, dststop;
	uint orgstart, orgstop;

	bool visstart, visstop, visgain, visloss;

	for (unsigned int i=0;i<refsBrlyMFlight.size();i++) {
		if (dbsbrly->tblbrlymflight->loadRecByRef(refsBrlyMFlight[i], &dstflt)) {
			// --- destination flight route
			dbsbrly->tblbrlymleg->loadRecByRef(dstflt->refBrlyMLeg, &dstleg); legToRad(dstleg);

			dbsbrly->tblbrlymlocation->loadRecByRef(dstleg->bgnRefBrlyMLocation, &bgnloc); locToRad(bgnloc);
			dbsbrly->tblbrlymlocation->loadRecByRef(dstleg->endRefBrlyMLocation, &endloc); locToRad(endloc);

			getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &dstrmat);

			delete bgnloc;
			delete endloc;

			cosalpha = cos(dstleg->alpha);

			// --- flight-location
			fltRlocprep.refBrlyMFlight = dstflt->ref;

			dbsbrly->tblbrlyrmlegmlocation->loadRstByLeg(dstleg->ref, false, legRlocs);
			for (unsigned int j=0;j<legRlocs.nodes.size();j++) legRelLocToRad(legRlocs.nodes[j]);

			for (unsigned int j=0;j<legRlocs.nodes.size();j++) {
				legRloc = legRlocs.nodes[j];

				fltRlocprep.refBrlyMLocation = legRloc->refBrlyMLocation;

				fltRlocprep.x1VisStart = dstflt->start + lround( ((double) (dstflt->stop - dstflt->start)) * (legRloc->x1VisLegphi0/dstleg->deltaphi) );
				fltRlocprep.x1VisStop = dstflt->start + lround( ((double) (dstflt->stop - dstflt->start)) * (legRloc->x1VisLegphi1/dstleg->deltaphi) );

				fltRlocs.nodes.push_back(new BrlyRMFlightMLocation(fltRlocprep));
			};

			// --- flight-flight
			fltRfltprep.dstRefBrlyMFlight = dstflt->ref;

			dststart = dstflt->start;
			dststop = dstflt->stop;

			dstomg = dstleg->deltaphi / ((double) (dstflt->stop - dstflt->start));

			// -- origin flight routes
			dbsbrly->tblbrlyrmlegmleg->loadRstByDlg(dstflt->refBrlyMLeg, false, legRlegs);
			for (unsigned int j=0;j<legRlegs.nodes.size();j++) legRelLegToRad(legRlegs.nodes[j]);

			for (unsigned int j=0;j<legRlegs.nodes.size();j++) {
				legRleg = legRlegs.nodes[j];

				dbsbrly->tblbrlymleg->loadRecByRef(legRleg->orgRefBrlyMLeg, &orgleg); legToRad(orgleg);

				dbsbrly->tblbrlymlocation->loadRecByRef(orgleg->bgnRefBrlyMLocation, &bgnloc); locToRad(bgnloc);
				dbsbrly->tblbrlymlocation->loadRecByRef(orgleg->endRefBrlyMLocation, &endloc); locToRad(endloc);

				getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &orgrmat);

				delete bgnloc;
				delete endloc;

				// -- flights on origin flight route
				sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMFlight WHERE refBrlyMLeg = " << orgleg->ref << " AND start < " << dstflt->stop << " AND stop > " << dstflt->start;
				dbsbrly->tblbrlymflight->loadRstBySQL(sqlstr.str(), false, orgflts);

				for (unsigned int k=0;k<orgflts.nodes.size();k++) {
					orgflt = orgflts.nodes[k];

					fltRfltprep.orgRefBrlyMFlight = orgflt->ref;

					orgomg = orgleg->deltaphi / ((double) (orgflt->stop - orgflt->start));

					// find time of orgflt presence in geometrical overlap region ; note that dstflt presence is not required
					orgstart = orgflt->start + legRleg->VisOrgLegphi0/orgomg;
					orgstop = orgflt->start + legRleg->VisOrgLegphi1/orgomg;

					// orgstart needs to be before orgstop
					invtime = (orgstart > orgstop);
					if (invtime) {
						start = orgstart;
						orgstart = orgstop;
						orgstop = start;
					};

					if ((dststop > orgstart) && (dststart < orgstop)) {
						// perform numerical analysis
						fltRfltprep.x1VisStart = dststart; if (orgstart > dststart) fltRfltprep.x1VisStart = orgstart;
						fltRfltprep.x1VisStop = dststop; if (orgstop < dststop) fltRfltprep.x1VisStop = orgstop;

						visstart = (visFltflt(fltRfltprep.x1VisStart, dstrmat, dstomg, dstflt->start, orgrmat, orgomg, orgflt->start, cosalpha) > 0.0);
						visstop = (visFltflt(fltRfltprep.x1VisStop, dstrmat, dstomg, dstflt->start, orgrmat, orgomg, orgflt->start, cosalpha) > 0.0);

						visgain = false;
						visloss = false;

						if (visstart && visstop) {
							// contiguous visibility
						} else if (visstart && !visstop) {
							visloss = true;
						} else if (!visstart && visstop) {
							visgain = true;
						} else {
							// intermediate visibility if derivative at x1VisStart positive and derivative at x1VisStop negative
							if (visdrvFltflt(fltRfltprep.x1VisStart, dstrmat, dstomg, dstflt->start, orgrmat, orgomg, orgflt->start, cosalpha) > 0.0) {
								if (visdrvFltflt(fltRfltprep.x1VisStop, dstrmat, dstomg, dstflt->start, orgrmat, orgomg, orgflt->start, cosalpha) < 0.0) {
									visloss = true;
									visgain = true;
								};
							};
						};

						if (visloss) {
							// find loss of visibility from x1VisStop
							visloss = viszeroFltflt(dstrmat, dstomg, dstflt->start, orgrmat, orgomg, orgflt->start, cosalpha, fltRfltprep.x1VisStart, fltRfltprep.x1VisStop, fltRfltprep.x1VisStop, 1.0e-6, &fltRfltprep.x1VisStop);
						};

						if (visgain) {
							// find gain of visibility from x1VisStart
							visgain = viszeroFltflt(dstrmat, dstomg, dstflt->start, orgrmat, orgomg, orgflt->start, cosalpha, fltRfltprep.x1VisStart, fltRfltprep.x1VisStop, fltRfltprep.x1VisStart, 1.0e-6, &fltRfltprep.x1VisStart);
						};

						// store
						if ((visstart && visstop) || (visstart && visloss) || (visgain && visstop) || (visgain && visloss)) {
							if (fltRfltprep.x1VisStop > fltRfltprep.x1VisStart) fltRflts.nodes.push_back(new BrlyRMFlightMFlight(fltRfltprep));
						};
					};
				};

				delete orgleg;
			};

			delete dstleg;
			delete dstflt;
		};
	};

	if (dstrmat) delete[] dstrmat;
	if (orgrmat) delete[] orgrmat;

	// insert all fltRflt's at a time
	dbsbrly->tblbrlyrmflightmflight->insertRst(fltRflts, true);

	// insert all frl's at a time
	dbsbrly->tblbrlyrmflightmlocation->insertRst(fltRlocs, true);
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
inline double BrlyDynFltfltloc::visFltflt(
			const double t
			, const double* legrmat1
			, const double omega1
			, const uint t01
			, const double* legrmat2
			, const double omega2
			, const uint t02
			, const double cosa0
		) {
	// visibility for retval > 0
	double retval;

	double phi1 = omega1 * (t - ((double) t01));
	double phi2 = omega2 * (t - ((double) t02));

	retval = (legrmat1[0]*legrmat2[0] + legrmat1[1]*legrmat2[1] + legrmat1[2]*legrmat2[2]) * cos(phi1)*cos(phi2);
	retval += (legrmat1[0]*legrmat2[3] + legrmat1[1]*legrmat2[4] + legrmat1[2]*legrmat2[5]) * cos(phi1)*sin(phi2);
	retval += (legrmat1[3]*legrmat2[0] + legrmat1[4]*legrmat2[1] + legrmat1[5]*legrmat2[2]) * sin(phi1)*cos(phi2);
	retval += (legrmat1[3]*legrmat2[3] + legrmat1[4]*legrmat2[4] + legrmat1[5]*legrmat2[5]) * sin(phi1)*sin(phi2);

	return(retval-cosa0);
};

inline double BrlyDynFltfltloc::visdrvFltflt(
			const double t
			, const double* legrmat1
			, const double omega1
			, const uint t01
			, const double* legrmat2
			, const double omega2
			, const uint t02
			, const double cosa0
		) {
	return((visFltflt(t+1.0e-6, legrmat1, omega1, t01, legrmat2, omega2, t02, cosa0) - visFltflt(t-1.0e-6, legrmat1, omega1, t01, legrmat2, omega2, t02, cosa0)) / 2.0e-6);
};

bool BrlyDynFltfltloc::viszeroFltflt(
			const double* legrmat1
			, const double omega1
			, const uint t01
			, const double* legrmat2
			, const double omega2
			, const uint t02
			, const double cosa0
			, const double t0
			, const double t1
			, const double tini
			, const double tol
			, unsigned int* t
		)	{
	bool retval = false;

	double ttest = tini;

	double vis, visnew, dvis, residual;

	vis = visFltflt(ttest, legrmat1, omega1, t01, legrmat2, omega2, t02, cosa0);
	residual = fabs(vis);

	while (residual > tol) {
		// change ttest using Newton method
		dvis = visdrvFltflt(ttest, legrmat1, omega1, t01, legrmat2, omega2, t02, cosa0);
		ttest = ttest - vis/dvis;

		// re-evaluate
		visnew = visFltflt(ttest, legrmat1, omega1, t01, legrmat2, omega2, t02, cosa0);
		if (fabs(visnew-vis) < 1.0e-6) break;
		vis = visnew;
		
		// require that residual becomes smaller on each iteration
		if (fabs(vis) >= residual) break;
		residual = fabs(vis);
	};

	if (residual <= tol) {
		// check if t is in range
		if ((ttest > t0) && (ttest < t1)) {
			if (tini < ttest) *t = ceil(ttest);
			else *t = floor(ttest);

			retval = true;
		};
	};

	return retval;
};
// IP cust --- IEND


