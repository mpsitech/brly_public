/**
  * \file BrlyDynFltseg.cpp
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

#include "BrlyDynFltseg.h"

DpchRetBrly* BrlyDynFltseg::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDynFltseg* dpchinv
		) {
	uint numFirst = dpchinv->numFirst;
	uint numLast = dpchinv->numLast;
	vector<ubigint> refsBrlyMFlight = dpchinv->refsBrlyMFlight;
	uint start = dpchinv->start;
	uint stop = dpchinv->stop;

	bool success;

	// IP run --- IBEGIN
	string sqlstr;

	ListBrlyMFlight flts;
	BrlyMFlight* flt = NULL;

	if (refsBrlyMFlight.size() == 0) {
		// all flights / block of flights
		sqlstr = "SELECT * FROM TblBrlyMFlight WHERE start >= " + to_string(start) + " AND start <= " + to_string(stop) + " AND Segdone = 0 ORDER BY ref ASC";
		if ((numFirst != 0) || (numLast != 0)) sqlstr += " LIMIT " + to_string(numFirst) + ", " + to_string(numLast-numFirst+1);

		dbsbrly->tblbrlymflight->loadRstBySQL(sqlstr, false, flts);

	} else {
		// selected flights
		for (unsigned int i=0;i<refsBrlyMFlight.size();i++) {
			if (dbsbrly->tblbrlymflight->loadRecByRef(refsBrlyMFlight[i], &flt)) flts.nodes.push_back(flt);
		};
	};

	for (unsigned int i=0;i<flts.nodes.size();i++) {
		flt = flts.nodes[i];

		segmentFlight(dbsbrly, flt);
	};
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
void BrlyDynFltseg::segmentFlight(
			DbsBrly* dbsbrly
			, BrlyMFlight* flt
		) {
	BrlyMFaflight* faf = NULL;

	BrlyMLocation* bgnloc = NULL;
	BrlyMLocation* endloc = NULL;

	ListBrlyAMFaflightWaypoint wps;
	BrlyAMFaflightWaypoint* wp = NULL;
	BrlyAMFaflightWaypoint* wp2 = NULL;

	double* rmat = NULL;
	double* rtmat = NULL;

	double* cart = NULL;
	double* cart2 = NULL;
	double* sphr = NULL;

	double r, theta, phi;
	double alt, alt2;

	double theta1, phi1;
	double theta2, phi2;

	double deltaphi;
	double omega;

	BrlyAMFaflightWaypoint* depwp = NULL;
	BrlyAMFaflightWaypoint* arrwp = NULL;

	bool monotonous;

	vector<unsigned int> icsWpsValid;
	vector<unsigned int> icsWpsUse;

	vector<uint> ts;
	double t, dt;

	unsigned int ixLast;

	uint idt;

	unsigned int ixBest;
	uint idtBest;

	ListBrlyMSegment segs;
	BrlyMSegment* seg = NULL;

	unsigned int cnt;

// cout << "processing ref = " << flt->ref << "/" << flt->refBrlyMFaflight << "." << endl;

	// PRELIMINARY
	dbsbrly->executeQuery("DELETE FROM TblBrlyMSegment WHERE refIxVTbl = " + to_string(VecBrlyVMSegmentRefTbl::FLT) + " AND refUref = " + to_string(flt->ref));

	// find departure and arrival airports
	dbsbrly->tblbrlymlocation->loadRecBySQL("SELECT TblBrlyMLocation.* FROM TblBrlyMLocation, TblBrlyMLeg WHERE TblBrlyMLocation.ref = TblBrlyMLeg.bgnRefBrlyMLocation AND TblBrlyMLeg.ref = "
				+ to_string(flt->refBrlyMLeg), &bgnloc);
	if (!bgnloc) return;
	locToRad(bgnloc);

	dbsbrly->tblbrlymlocation->loadRecBySQL("SELECT TblBrlyMLocation.* FROM TblBrlyMLocation, TblBrlyMLeg WHERE TblBrlyMLocation.ref = TblBrlyMLeg.endRefBrlyMLocation AND TblBrlyMLeg.ref = "
				+ to_string(flt->refBrlyMLeg), &endloc);
	if (!endloc) return;
	locToRad(endloc);

	cart = new double[3];
	cart2 = new double[3];
	sphr = new double[3];

	if (dbsbrly->tblbrlymfaflight->loadRecByRef(flt->refBrlyMFaflight, &faf)) {
		if ( ((faf->actualarrivaltime - faf->actualdeparturetime) >= (15*60)) && ((faf->actualarrivaltime - faf->actualdeparturetime) <= (16*3600)) ) {
			// override flt->start and flt->stop
			flt->start = faf->actualdeparturetime;
			flt->stop = faf->actualarrivaltime;

			dbsbrly->tblbrlyamfaflightwaypoint->loadRstByFaf(faf->ref, false, wps);
			for (unsigned int i=0;i<wps.nodes.size();i++) wpToRad(wps.nodes[i]);

			// verify waypoints are monotonously ascending in time
			monotonous = true;
			for (unsigned int i=1;i<wps.nodes.size();i++) {
				wp = wps.nodes[i];

				if (wp->timestamp < wps.nodes[i-1]->timestamp) {
					monotonous = false;
					break;
				};
			};

			if (monotonous) {
//cout << "mon." << endl;
				icsWpsValid.resize(0);

				for (unsigned int i=0;i<wps.nodes.size();i++) {
					wp = wps.nodes[i];

					// validate waypoints by time
					if ((wp->timestamp > flt->start) && (wp->timestamp < flt->stop)) {

						// validate waypoints by latitude/longitude/altitude present
						if ((wp->latitude != 0.0) && (wp->longitude != 0.0) && (wp->altitude != 0)) {

							// validate waypoints by altitude compared to departure and arrival airports
							if ( (wp->timestamp < ((flt->start + flt->stop)/2)) ) {
								if ( (((double) wp->altitude) * 0.3048 * 100.0) > (bgnloc->alt + 100.0) ) icsWpsValid.push_back(i);
							} else {
								if ( (((double) wp->altitude) * 0.3048 * 100.0) > (endloc->alt + 100.0) ) icsWpsValid.push_back(i);
							};
						};
					};
				};

//cout << "icsWpsValid.size() = " << icsWpsValid.size() << endl;

				// requirement for departure/arrival waypoints present: at least three waypoints within 20min from departure/arrival times
				if ( (flt->start + (40*60)) < flt->stop ) {
					cnt = 0;
					for (unsigned int i=0;i<icsWpsValid.size();i++) {
						wp = wps.nodes[icsWpsValid[i]];
						if (wp->timestamp <= (flt->start + 20*60)) cnt++;
					};

					if (cnt < 3) {
						// eliminate all waypoints within the first 20min
						for (unsigned int i=cnt;i<icsWpsValid.size();i++) icsWpsValid[i-cnt] = icsWpsValid[i];
						icsWpsValid.resize(icsWpsValid.size()-cnt);

						if (icsWpsValid.size() > 0) {
							// calculate single waypoint 20min into the flight
							wp = wps.nodes[icsWpsValid[0]];

							deltaphi = getDeltaphi(bgnloc->theta, bgnloc->phi, wp->latitude, wp->longitude);
							omega = deltaphi / ((double) (wp->timestamp-flt->start));

							getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, wp->latitude, wp->longitude, &rmat);
							transpAmat(rmat, &rtmat, 3);

							theta = 0.0;
							phi = omega * (20.0*60.0);

							cart[0] = cos(phi);
							cart[1] = sin(phi);
							cart[2] = 0.0;

							multAmatBvec(rtmat, cart, &cart2, 3);
							cartToSphr(cart2, &r, &theta, &phi);

							depwp = new BrlyAMFaflightWaypoint(0, 0, 0, flt->start + 20*60, theta, phi, 0, wp->altitude, "", "", "");
						};
					};
//cout << "after departure removal: icsWpsValid.size() = " << icsWpsValid.size() << endl;
//if (depwp) cout << "depwp exists!" << endl;

					cnt = 0;
					for (unsigned int i=icsWpsValid.size();i>0;i--) {
						wp = wps.nodes[icsWpsValid[i-1]];
						if ((wp->timestamp + 20*60) >= flt->stop) cnt++;
					};

					if (cnt < 3) {
						// eliminate all waypoints 20min before arrival
						icsWpsValid.resize(icsWpsValid.size()-cnt);

						if (icsWpsValid.size() > 0) {
							// calculate single waypoint 20min before arrival
							wp = wps.nodes[icsWpsValid[icsWpsValid.size()-1]];

							deltaphi = getDeltaphi(wp->latitude, wp->longitude, endloc->theta, endloc->phi);
							omega = deltaphi / ((double) (flt->stop-wp->timestamp));

							getRmatEquatorLeg(wp->latitude, wp->longitude, endloc->theta, endloc->phi, &rmat);
							transpAmat(rmat, &rtmat, 3);

							theta = 0.0;
							phi = deltaphi - omega * (20.0*60.0);

							cart[0] = cos(phi);
							cart[1] = sin(phi);
							cart[2] = 0.0;

							multAmatBvec(rtmat, cart, &cart2, 3);
							cartToSphr(cart2, &r, &theta, &phi);

							arrwp = new BrlyAMFaflightWaypoint(0, 0, 0, flt->stop - 20*60, theta, phi, 0, wp->altitude, "", "", "");
						};
					};
//cout << "after arrival removal: icsWpsValid.size() = " << icsWpsValid.size() << endl;
//if (arrwp) cout << "arrwp exists!" << endl;
				};
//cout << "beep" << endl;
				// establish grid in time
				if ( (flt->start + (40*60)) >= flt->stop ) {
					// 5min granularity throughout
					dt = ((double) (flt->stop-flt->start))
								/ ceil(((double) (flt->stop-flt->start)) / (5.0*60.0));

					for (t=flt->start ; t<=flt->stop ; t+=dt) ts.push_back(lround(t));

				} else {
					// flight time sufficient for departure-cruise-arrival
					if (!depwp) {
						ts.push_back(flt->start + 5*60);
						ts.push_back(flt->start + 10*60);
						ts.push_back(flt->start + 15*60);
					};

					if ((flt->start+20*60) == (flt->stop-20*60)) {
						ts.push_back(flt->start + 20*60);
					} else {
						// 20min granularity in cruise
						dt = ((double) (flt->stop-flt->start-40*60))
									/ ceil(((double) (flt->stop-flt->start-40*60)) / (20.0*60.0));

						for (t=flt->start+20*60 ; (t+20*60)<=flt->stop ; t+=dt) ts.push_back(lround(t));
					};

					if (!arrwp) {
						ts.push_back(flt->stop - 15*60);
						ts.push_back(flt->stop - 10*60);
						ts.push_back(flt->stop - 5*60);
					};
				};

				// select waypoints closest in time, avoid duplicates
				if (icsWpsValid.size() > 0) {
					ixLast = 0;

					for (unsigned int i=0;i<ts.size();i++) {
						if (depwp && (i==0)) {
							icsWpsUse.push_back(wps.nodes.size());
						} else if (arrwp && (i==(ts.size()-1))) {
							icsWpsUse.push_back(wps.nodes.size());

						} else {
							idtBest = (0-1);

							for (unsigned int j=ixLast;j<icsWpsValid.size();j++) {
								wp = wps.nodes[icsWpsValid[j]];

								if (wp->timestamp <= ts[i]) idt = ts[i] - wp->timestamp;
								else idt = wp->timestamp - ts[i];

								if (idt <= idtBest) {
									ixBest = j;
									idtBest = idt;
								} else {
									break;
								};
							};

							if (idtBest == (0-1)) break;

							if (ixBest != ixLast) {
								icsWpsUse.push_back(icsWpsValid[ixBest]);
								ixLast = ixBest;
							};
						};
					};
//cout << "icsWpsUse.size() = " << icsWpsUse.size() << endl;

					// generate segments
					if (icsWpsUse.size() > 0) {
						if (!depwp || (depwp && !arrwp && (icsWpsUse.size() > 1)) || (depwp && arrwp && (icsWpsUse.size() > 2))) {
							for (unsigned int i=0;i<=icsWpsUse.size();i++) {
								if (i == 0) {
//		cout << "first" << endl;
									// first segment
									if (depwp) wp2 = depwp;
									else wp2 = wps.nodes[icsWpsUse[i]]; // <- NOPE !!! icsWpsUse currently refer to icsWpsValid

									deltaphi = getDeltaphi(bgnloc->theta, bgnloc->phi, wp2->latitude, wp2->longitude);
									segs.nodes.push_back(new BrlyMSegment(0, VecBrlyVMSegmentRefTbl::FLT, flt->ref, (i+1), deltaphi, bgnloc->alt, ((double) wp2->altitude)*0.3048*100.0,
												bgnloc->theta, wp2->latitude, bgnloc->phi, wp2->longitude, flt->start, wp2->timestamp, false));

								} else if (i == icsWpsUse.size()) {
//		if (!arrwp) cout << "last icsWpsUse[i-1] = " << icsWpsUse[i-1] << endl;
									// last segment
									if (arrwp) wp = arrwp;
									else wp = wps.nodes[icsWpsUse[i-1]];

//		cout << "good here!" << endl;
									deltaphi = getDeltaphi(wp->latitude, wp->longitude, endloc->theta, endloc->phi);
									segs.nodes.push_back(new BrlyMSegment(0, VecBrlyVMSegmentRefTbl::FLT, flt->ref, (i+1), deltaphi, ((double) wp->altitude)*0.3048*100.0, endloc->alt,
												wp->latitude, endloc->theta, wp->longitude, endloc->phi, wp->timestamp, flt->stop, false));

								} else {
//		cout << "imd" << endl;
									// segment between two waypoints
									if (depwp && (i==1)) wp = depwp;
									else wp = wps.nodes[icsWpsUse[i-1]];

									if (arrwp && (i==(icsWpsUse.size()-1))) wp2 = arrwp;
									else wp2 = wps.nodes[icsWpsUse[i]];

									deltaphi = getDeltaphi(wp->latitude, wp->longitude, wp2->latitude, wp2->longitude);
									segs.nodes.push_back(new BrlyMSegment(0, VecBrlyVMSegmentRefTbl::FLT, flt->ref, (i+1), deltaphi, ((double) wp->altitude)*0.3048*100.0, ((double) wp2->altitude)*0.3048*100.0,
												wp->latitude, wp2->latitude, wp->longitude, wp2->longitude, wp->timestamp, wp2->timestamp, false));
								};
							};
						};
					};
				};
			};
		};

		delete faf;
	};
//cout << "okies." << endl;

	if (segs.nodes.size() < 2) {
		segs.clear();

		// establish default (model) segmentation
		deltaphi = getDeltaphi(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi);
		omega = deltaphi / ((double) (flt->stop-flt->start));

		getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &rmat);
		transpAmat(rmat, &rtmat, 3);

		if ( (flt->start + (40*60)) >= flt->stop ) {
			// - two-segment model
			theta = 0.0;
			phi = deltaphi / 2.0;

			cart[0] = cos(phi);
			cart[1] = sin(phi);
			cart[2] = 0.0;

			multAmatBvec(rtmat, cart, &cart2, 3);
			cartToSphr(cart2, &r, &theta, &phi);

			// altitude is max. achievable with a climb rate of 8m/s
			alt = bgnloc->alt + 8.0*((double) (flt->stop-flt->start))/2.0;
			alt2 = endloc->alt + 8.0*((double) (flt->stop-flt->start))/2.0;
			if (alt2 > alt) alt = alt2;

			segs.nodes.push_back(new BrlyMSegment(0, VecBrlyVMSegmentRefTbl::FLT, flt->ref, 1, deltaphi/2.0, bgnloc->alt, alt, bgnloc->theta, theta, bgnloc->phi, phi, flt->start, (flt->start + flt->stop)/2, false));
			segs.nodes.push_back(new BrlyMSegment(0, VecBrlyVMSegmentRefTbl::FLT, flt->ref, 2, deltaphi/2.0, alt, endloc->alt, theta, endloc->theta, phi, endloc->phi, (flt->start + flt->stop)/2, flt->stop, false));

		} else {
			// - three-segment model
			cart[2] = 0.0;
//cout << "beep" << endl;
			// first support
			theta = 0.0;
			phi = omega*(20.0*60.0);

			cart[0] = cos(phi);
			cart[1] = sin(phi);

			multAmatBvec(rtmat, cart, &cart2, 3);
			cartToSphr(cart2, &r, &theta1, &phi1);

			// second support
			theta = 0.0;
			phi = deltaphi-omega*(20.0*60.0);

			cart[0] = cos(phi);
			cart[1] = sin(phi);

			multAmatBvec(rtmat, cart, &cart2, 3);
			cartToSphr(cart2, &r, &theta2, &phi2);

			segs.nodes.push_back(new BrlyMSegment(0, VecBrlyVMSegmentRefTbl::FLT, flt->ref, 1, omega*(20.0*60.0), bgnloc->alt, 10500.0, bgnloc->theta, theta1, bgnloc->phi, phi1, flt->start, flt->start + 20*60, false));
			segs.nodes.push_back(new BrlyMSegment(0, VecBrlyVMSegmentRefTbl::FLT, flt->ref, 2, deltaphi-omega*(40.0*60.0), 10500.0, 10500.0, theta1, theta2, phi1, phi2, flt->start + 20*60, flt->stop - 20*60, false));
			segs.nodes.push_back(new BrlyMSegment(0, VecBrlyVMSegmentRefTbl::FLT, flt->ref, 3, omega*(20.0*60.0), 10500.0, endloc->alt, theta2, endloc->theta, phi2, endloc->phi, flt->stop - 20*60, flt->stop, false));
		};
	};

	for (unsigned int i=0;i<segs.nodes.size();i++) segToDeg(segs.nodes[i]);
	dbsbrly->tblbrlymsegment->insertRst(segs);

	delete bgnloc;
	delete endloc;

	if (rmat) delete[] rmat;
	if (rtmat) delete[] rtmat;

	if (cart) delete[] cart;
	if (cart2) delete[] cart2;
	if (sphr) delete[] sphr;

	if (depwp) delete depwp;
	if (arrwp) delete arrwp;
};

double BrlyDynFltseg::getDeltaphi(
			const double theta0
			, const double phi0
			, const double theta1
			, const double phi1
		) {
	double retval;

	double* bgncart = NULL;
	double* endcart = NULL;

	sphrToCart(1.0, theta0, phi0, &bgncart);
	sphrToCart(1.0, theta1, phi1, &endcart);
	retval = acos(bgncart[0]*endcart[0] + bgncart[1]*endcart[1] + bgncart[2]*endcart[2]);

	if (bgncart) delete[] bgncart;
	if (endcart) delete[] endcart;

	return retval;
};

void BrlyDynFltseg::segToDeg(
			BrlyMSegment* seg
		) {
	seg->deltaphi = radToDeg(seg->deltaphi);
	seg->theta0 = radToDeg(seg->theta0);
	seg->theta1 = radToDeg(seg->theta1);
	seg->phi0 = radToDeg(seg->phi0);
	seg->phi1 = radToDeg(seg->phi1);
};

void BrlyDynFltseg::wpToRad(
			BrlyAMFaflightWaypoint* wp
		) {
	wp->latitude = degToRad(wp->latitude);
	wp->longitude = degToRad(wp->longitude);
};
// IP cust --- IEND


