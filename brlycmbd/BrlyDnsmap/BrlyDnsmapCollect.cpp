/**
  * \file BrlyDnsmapCollect.cpp
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

#include "BrlyDnsmapCollect.h"

DpchRetBrlyDnsmapCollect* BrlyDnsmapCollect::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDnsmapCollect* dpchinv
		) {
	bool capacity = dpchinv->capacity;
	bool con = dpchinv->con;
	uint dt = dpchinv->dt;
	bool flt = dpchinv->flt;
	uint fullheight = dpchinv->fullheight;
	uint fullwidth = dpchinv->fullwidth;
	bool leg = dpchinv->leg;
	bool pacctr = dpchinv->pacctr;
	double phi0 = dpchinv->phi0;
	double phi1 = dpchinv->phi1;
	bool pReach = dpchinv->pReach;
	bool seg = dpchinv->seg;
	string srefArena = dpchinv->srefArena;
	string srefsBrlyKEqptype = dpchinv->srefsBrlyKEqptype;
	uint start = dpchinv->start;
	uint stop = dpchinv->stop;
	double theta0 = dpchinv->theta0;
	double theta1 = dpchinv->theta1;

	bool success;

	ubigint refBrlyMFile;

	// IP run --- IBEGIN
	ostringstream sqlstr;

	vector<ubigint> refs;
	vector<ubigint> refs2;

	ListBrlyMFlight flts;
	BrlyMFlight* flt2 = NULL;

	ListBrlyMConnection cons;
	BrlyMConnection* con2 = NULL;

	ListBrlyMFlight dnsflts;
	BrlyMFlight* dnsflt = NULL;

	BrlyMEquipment* eqp = NULL;

	vector<uint> dnscaps;
	uint cap;

	ListBrlyMConnection dnscons;
	BrlyMConnection* dnscon = NULL;

	Rlystat* rlystat = NULL;

	bool ctd;

	ListBrlyMSegment dnssegs;
	BrlyMSegment* dnsseg = NULL;

	ListBrlyMPlntype ptys;
	BrlyMPlntype* pty = NULL;

	bool back;

	unsigned int x0, x1, y0, y1;

	vector<double> dns;
	vector<double> dns2;

	double D, D2;

	string tmpfile;

	unsigned int dimPhi, dimTheta, dimT;

	int cdfRoot;
	int cdfDimPhi, cdfDimTheta, cdfDimT;
	int cdfPhi, cdfTheta, cdfT;
	int cdfDns;

	int cdfFh, cdfFw, cdfX0, cdfX1, cdfY0, cdfY1;

	int* dims = NULL;

	double* var = NULL;
	long* lvar = NULL;

	vector<double> thetavec;
	vector<double> phivec;
	vector<double> tvec;

	unsigned int xp, yp, x, y;
	double theta, phi;
	double dtheta, dphi;

	uint t;
	const uint tick = 30;

	double* rmat = NULL;

	vector<uint> fltsegstarts;
	uint fltsegstart;

	vector<uint> fltsegstops;
	uint fltsegstop;

	vector<double> omegas;
	double omega;

	vector<double*> rtmats;
	double* rtmat = NULL;

	double* cart = NULL;
	double* cart2 = NULL;
	double* sphr = NULL;

	double r;

	unsigned int ix;

	BrlyMLeg* leg2 = NULL;

	BrlyMLocation* bgnloc = NULL;
	BrlyMLocation* endloc = NULL;

	ostringstream str;
	string s, s2;
	vector<string> ss;

	double d;

	bool found;

	// --- active region calculations
	// pixel coordinates vs. geo-coordinates in NASA GISS files
	// theta = 0 .. 719, phi = 0 .. 1439
	// i.e. center coordinate of pixel (i,j) is (theta,phi) = (-pi/2+(i+0.5)*(pi/720), -pi+(j+0.5)*(2*pi/1440))

	phi0 = degToRad(phi0);
	phi1 = degToRad(phi1);
	theta0 = degToRad(theta0);
	theta1 = degToRad(theta1);

	dphi = 2.0*pi/((double) fullwidth);
	dtheta = pi/((double) fullheight);

	phithetaToPix(fullheight, fullwidth, pacctr, theta0, phi0, y0, x0);
	phithetaToPix(fullheight, fullwidth, pacctr, theta1, phi1, y1, x1);

cout << "theta0 = " << theta0 << ", phi0 = " << phi0 << ", y0 = " << y0 << ", x0 = " << x0 << endl;
cout << "theta1 = " << theta1 << ", phi1 = " << phi1 << ", y1 = " << y1 << ", x1 = " << x1 << endl;

	// theta
	dimTheta = y1-y0+1;
	thetavec.resize(dimTheta);

	for (yp=0;yp<dimTheta;yp++) {
		ixToPix(y0, y1, x0, x1, yp, 0, y, x);
		pixToPhitheta(fullheight, fullwidth, pacctr, y, x, theta, phi);

		thetavec[yp] = radToDeg(theta);
	};

	// phi
	dimPhi = x1-x0+1;
	phivec.resize(dimPhi);

	for (xp=0;xp<dimPhi;xp++) {
		ixToPix(y0, y1, x0, x1, 0, xp, y, x);
		pixToPhitheta(fullheight, fullwidth, pacctr, y, x, theta, phi);

		phivec[xp] = radToDeg(phi);
	};

	// time
	dimT = (stop-start)/dt;
	tvec.resize(dimT);

	t = start;
	for (unsigned int i=0;i<dimT;i++) {
		tvec[i] = t + dt/2;
		t += dt;
	};

	// --- select flights / connections
	dbsbrly->tblbrlymplntype->loadRstBySQL("SELECT * FROM TblBrlyMPlntype", false, ptys);

	// co1, co2, co3: no "back" required
	back = !(srefArena.find("co") == 0);
	Brly::loadLegsByArena(dbsbrly, srefArena, true, back, false, refs, refs2);

	refs.resize(refs.size() + refs2.size());
	for (unsigned int i=0;i<refs2.size();i++) refs[refs.size()-refs2.size()+i] = refs2[i];

	// load relevant flights
	for (unsigned int i=0;i<refs.size();i++) {
		sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMFlight WHERE refBrlyMLeg = " << refs[i] << " AND stop > " << start << " AND start < " << stop;
		dbsbrly->tblbrlymflight->loadRstBySQL(sqlstr.str(), false, flts);

		for (unsigned int j=0;j<flts.nodes.size();j++) {
			flt2 = flts.nodes[j];

			if (seg && !flt2->Segdone) continue;

			if (!dbsbrly->tblbrlymequipment->loadRecByHktHku(VecBrlyVMEquipmentHkTbl::FLT, flt2->ref, &eqp)) continue;

			// equipment type discrimination
			if (srefsBrlyKEqptype.length() != 0) if (!StrMod::srefInSrefs(srefsBrlyKEqptype, eqp->srefBrlyKEqptype)) {
				delete eqp;
				continue;
			};

			// flight capacity
			cap = 0;
			for (unsigned int k=0;k<ptys.nodes.size();k++) {
				pty = ptys.nodes[k];

				if (pty->ref == eqp->refBrlyMPlntype) {
					cap = pty->Capacity;
					break;
				};
			};

			delete eqp;

			if (con) {
				// find matching connection
				found = false;

				sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMConnection WHERE refBrlyMFlight = " << flt2->ref;
				dbsbrly->tblbrlymconnection->loadRstBySQL(sqlstr.str(), false, cons);

				for (unsigned int k=0;k<cons.nodes.size();k++) {
					con2 = cons.nodes[k];

					if (con2->srefsBrlyKEqptype.length() == srefsBrlyKEqptype.length()) {
						found = true;

						if (srefsBrlyKEqptype.length() != 0) {
							// require exact match of equipment types
							StrMod::stringToVector(con2->srefsBrlyKEqptype, ss);
							for (unsigned int l=0;l<ss.size();l++) {
								if (!StrMod::srefInSrefs(srefsBrlyKEqptype, ss[l])) {
									found = false;
									break;
								};
							};
						};

						if (found) {
							found = false;

							if (seg && (con2->ixVModel == VecBrlyVMConnectionModel::EXT)) found = true;
							else if (leg && (con2->ixVModel == VecBrlyVMConnectionModel::SPL)) found = true;
						};
					};

					if (found) break;
				};

				if (!found) continue;
			};

			// add to lists on which to determine the density
			dnsflts.nodes.push_back(new BrlyMFlight(*flt2));
			dnscaps.push_back(cap);

			if (con) dnscons.nodes.push_back(new BrlyMConnection(*con2));
		};
	};

	dns.resize(dimT*dimPhi*dimTheta, 0.0);
	if (pReach) dns2.resize(dimT*dimPhi*dimTheta, 0.0);

	D = 0.0;
	D2 = 0.0;

cout << dnsflts.nodes.size() << " flights loaded." << endl;

	// --- traverse flights/connections and accumulate density
	cart = new double[3];
	cart2 = new double[3];
	sphr = new double[3];

	for (unsigned int i=0;i<dnsflts.nodes.size();i++) {
		dnsflt = dnsflts.nodes[i];
		cap = dnscaps[i];

		if (con) {
			dnscon = dnscons.nodes[i];
			if (pReach) rlystat = new Rlystat(dbsbrly, dnscon);
		};

		if (seg) {
			// multiple segments (segments do overlap in time but this is irrelevant)
			sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMSegment WHERE refIxVTbl = " << VecBrlyVMSegmentRefTbl::FLT << " AND refUref = " << dnsflt->ref
						<< " AND stop > " << start << " AND start < " << stop << " ORDER BY refNum ASC";
			dbsbrly->tblbrlymsegment->loadRstBySQL(sqlstr.str(), false, dnssegs);
			for (unsigned int j=0;j<dnssegs.nodes.size();j++) segToRad(dnssegs.nodes[j]);

			for (unsigned int j=0;j<dnssegs.nodes.size();j++) {
				dnsseg = dnssegs.nodes[j];

				rtmat = NULL;
				getRmatEquatorLeg(dnsseg->theta0, dnsseg->phi0, dnsseg->theta1, dnsseg->phi1, &rmat);
				transpAmat(rmat, &rtmat, 3);

				omega = dnsseg->deltaphi / ((double) (dnsseg->stop-dnsseg->start));

				fltsegstarts.push_back(dnsseg->start);
				fltsegstops.push_back(dnsseg->stop);
				omegas.push_back(omega);
				rtmats.push_back(rtmat);
			};

		} else {
			// single leg via begin and end locations
			sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMLeg WHERE ref = " << dnsflt->refBrlyMLeg;
			dbsbrly->tblbrlymleg->loadRecBySQL(sqlstr.str(), &leg2); legToRad(leg2);

			dbsbrly->tblbrlymlocation->loadRecByRef(leg2->bgnRefBrlyMLocation, &bgnloc); locToRad(bgnloc);
			dbsbrly->tblbrlymlocation->loadRecByRef(leg2->endRefBrlyMLocation, &endloc); locToRad(endloc);

			// find flight route inverse rotation matrix
			rtmat = NULL;
			getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &rmat);
			transpAmat(rmat, &rtmat, 3);

			delete bgnloc;
			delete endloc;

			// step through flight time (equiv. segment time, see above)
			omega = leg2->deltaphi / ((double) (dnsflt->stop-dnsflt->start));

			fltsegstarts.push_back(dnsflt->start);
			fltsegstops.push_back(dnsflt->stop);
			omegas.push_back(omega);
			rtmats.push_back(rtmat);
		};

		for (unsigned int j=0;j<fltsegstarts.size();j++) {
			fltsegstart = fltsegstarts[j];
			fltsegstop = fltsegstops[j];
			omega = omegas[j];
			rtmat = rtmats[j];

			if (fltsegstart > start) {
				t = start + tick*ceil(((double) (fltsegstart-start)) / ((double) tick));
			} else {
				t = start;
			};

			while ((t < stop) && (t < fltsegstop)) {
				if (tToIx(start, stop, dt, t, ix)) {
					theta = 0.0;
					phi = omega * ((double) (t-fltsegstart));

// cout << Ftm::stamp(t) << endl;

					cart[0] = cos(phi);
					cart[1] = sin(phi);
					cart[2] = 0.0;

					multAmatBvec(rtmat, cart, &cart2, 3);
					cartToSphr(cart2, &r, &theta, &phi);

//cout << "phi = " << radToDeg(phi) << "°, theta = " << radToDeg(theta) << "°" << endl;

					phithetaToPix(fullheight, fullwidth, pacctr, theta, phi, y, x);

					if (pixToIx(y0, y1, x0, x1, y, x, yp, xp)) {
//cout << "ix = " << ix << ", yp = " << yp << ", xp = " << xp << endl;
						d = tick;
						if (capacity) d *= cap;

						if (con && pReach) {
							if (rlystat->getCtd(t)) {
								dns[ix*dimPhi*dimTheta + xp*dimTheta + yp] += d;
								D += d;
							};
							dns2[ix*dimPhi*dimTheta + xp*dimTheta + yp] += d;
							D2 += d;

						} else {
							dns[ix*dimPhi*dimTheta + xp*dimTheta + yp] += d;
							D += d;
						};
					};

					t += tick;
				};
			};
		};

		// clean up
		if (pReach) delete rlystat;

		fltsegstarts.resize(0);
		fltsegstops.resize(0);
		omegas.resize(0);

		for (unsigned int j=0;j<rtmats.size();j++) {
			delete[] rtmats[j];
			rtmats[j] = NULL;
		};

		rtmats.resize(0);
	};

	if (pReach) {
		// calculate percentage
		for (unsigned int i=0;i<dns.size();i++) {
			if (dns2[i] == 0.0) dns[i] = 0.0;
			else if (dns[i] == 0.0) dns[i] = 1.0e-6;
			else dns[i] = dns[i]/dns2[i];
		};

		cout << "connected pax hours: " << (D/3600.0) << "/" << (D2/3600.0) << " (" << (100.0*D/D2) << "%)" << endl;

	} else {
		// factor in size [km^2] and convert seconds to hours
		for (unsigned int i=0;i<dimT;i++) {
			for (unsigned int j=0;j<dimPhi;j++) {
				for (unsigned int k=0;k<dimTheta;k++) {
					theta = degToRad(thetavec[k]);

					d = xchg->stgbrlygeometry.earthradius*xchg->stgbrlygeometry.earthradius/1000.0/1000.0 * dphi * fabs(sin(theta+dtheta/2.0) - sin(theta-dtheta/2.0));
					dns[i*dimPhi*dimTheta + j*dimTheta + k] /= (d*3600.0);
				};
			};
		};

		cout << "pax hours: " << (D/3600.0) << endl;
	};

	// -- clean up
	if (rmat) delete[] rmat;

	if (cart) delete[] cart;
	if (cart2) delete[] cart2;
	if (sphr) delete[] sphr;

cout << "start write." << endl;

	// --- create and open cdf file
	tmpfile = Tmp::newfile(xchg->tmppath, "cdf");
	s = xchg->tmppath + "/" + tmpfile;

	nc_create(s.c_str(), NC_NETCDF4, &cdfRoot);

	nc_enddef(cdfRoot);

	// -- dimensions

	// - define dimensions and fill corresponding vectors
	nc_redef(cdfRoot);

	nc_def_dim(cdfRoot, "dimTheta", dimTheta, &cdfDimTheta);
	nc_def_dim(cdfRoot, "dimPhi", dimPhi, &cdfDimPhi);
	nc_def_dim(cdfRoot, "dimT", dimT, &cdfDimT);

	nc_enddef(cdfRoot);

	// - write
	dims = new int[1];

	// theta
	nc_redef(cdfRoot);

	dims[0] = cdfDimTheta;
	nc_def_var(cdfRoot, "theta", NC_DOUBLE, 1, dims, &cdfTheta);

	s = "latitude";
	nc_put_att_text(cdfRoot, cdfTheta, "title", s.length(), s.c_str());

	nc_enddef(cdfRoot);

	var = new double[dimTheta];
	for (unsigned int i=0;i<dimTheta;i++) var[i] = thetavec[i];
	nc_put_var_double(cdfRoot, cdfTheta, var);
	delete[] var;

	// phi
	nc_redef(cdfRoot);

	dims[0] = cdfDimPhi;
	nc_def_var(cdfRoot, "phi", NC_DOUBLE, 1, dims, &cdfPhi);

	s = "longitude";
	nc_put_att_text(cdfRoot, cdfPhi, "title", s.length(), s.c_str());

	nc_enddef(cdfRoot);

	var = new double[dimPhi];
	for (unsigned int i=0;i<dimPhi;i++) var[i] = phivec[i];
	nc_put_var_double(cdfRoot, cdfPhi, var);
	delete[] var;

	// time
	nc_redef(cdfRoot);

	dims[0] = cdfDimT;
	nc_def_var(cdfRoot, "t", NC_LONG, 1, dims, &cdfT);

	s = "time";
	nc_put_att_text(cdfRoot, cdfT, "title", s.length(), s.c_str());

	nc_enddef(cdfRoot);

	lvar = new long[dimT];
	for (unsigned int i=0;i<dimT;i++) lvar[i] = tvec[i];
	nc_put_var_long(cdfRoot, cdfT, lvar);
	delete[] lvar;

	delete[] dims;

	// additional variables
	nc_redef(cdfRoot);

	nc_def_var(cdfRoot, "fullheight", NC_UINT, 0, NULL, &cdfFh);
	nc_def_var(cdfRoot, "fullwidth", NC_UINT, 0, NULL, &cdfFw);
	nc_def_var(cdfRoot, "x0", NC_UINT, 0, NULL, &cdfX0);
	nc_def_var(cdfRoot, "x1", NC_UINT, 0, NULL, &cdfX1);
	nc_def_var(cdfRoot, "y0", NC_UINT, 0, NULL, &cdfY0);
	nc_def_var(cdfRoot, "y1", NC_UINT, 0, NULL, &cdfY1);

	nc_enddef(cdfRoot);

	nc_put_var_uint(cdfRoot, cdfFh, &fullheight);
	nc_put_var_uint(cdfRoot, cdfFw, &fullwidth);
	nc_put_var_uint(cdfRoot, cdfX0, &x0);
	nc_put_var_uint(cdfRoot, cdfX1, &x1);
	nc_put_var_uint(cdfRoot, cdfY0, &y0);
	nc_put_var_uint(cdfRoot, cdfY1, &y1);

	// -- density vector
	dims = new int[3];
	dims[0] = cdfDimT; dims[1] = cdfDimPhi; dims[2] = cdfDimTheta;

	var = new double[dimT*dimPhi*dimTheta];

	nc_redef(cdfRoot);

	dims[0] = cdfDimT;
	nc_def_var(cdfRoot, "dns", NC_DOUBLE, 3, dims, &cdfDns);

	s = "density";
	nc_put_att_text(cdfRoot, cdfDns, "title", s.length(), s.c_str());

	nc_enddef(cdfRoot);

	// - dummy data
/*
	for (unsigned int i=0;i<dimT;i++) {
		d = ((double) i)/((double) dimT);

		for (unsigned int j=0;j<dimPhi;j++) {
			for (unsigned int k=0;k<dimTheta;k++) {
				var[i*dimPhi*dimTheta + j*dimTheta + k] = d;
				if ((j%10) < 4) var[i*dimPhi*dimTheta + j*dimTheta + k] = 1.0;

				if ((j == 0) && (k == 0)) var[i*dimPhi*dimTheta + j*dimTheta + k] = 0.5;
				else if ((j == (dimPhi-1)) && (k == 0)) var[i*dimPhi*dimTheta + j*dimTheta + k] = 0.75;
				else if ((j == (dimPhi-1)) && (k == (dimTheta-1))) var[i*dimPhi*dimTheta + j*dimTheta + k] = 0.25;
				else if ((j == 0) && (k == (dimTheta-1))) var[i*dimPhi*dimTheta + j*dimTheta + k] = 0.0;
			};
		};
	};
*/
	// - actual data
	for (unsigned int i=0;i<dns.size();i++) var[i] = dns[i];

	nc_put_var_double(cdfRoot, cdfDns, var);

	delete[] var;
	delete[] dims;

	// store in archive
	nc_close(cdfRoot);

	s = xchg->tmppath + "/" + tmpfile;
	s2 = srefArena + " " + Ftm::stamp(start) + " - " + Ftm::stamp(stop);

	dpchret->refBrlyMFile = Acv::addfile(dbsbrly, xchg->acvpath, s, VecBrlyVMFileRefTbl::VOID, 0, "dnsmap", "dnsdat.cdf", "nc", s2);
	// IP run --- IEND

	return(new DpchRetBrlyDnsmapCollect("", "", success, refBrlyMFile));
};

// IP cust --- IBEGIN
void BrlyDnsmapCollect::phithetaToPix(
			const uint fullheight
			, const uint fullwidth
			, const bool pacctr
			, const double theta
			, double phi
			, unsigned int& y
			, unsigned int& x
		) {
	double d;

	if (pacctr) {
		phi = phi + pi;
		if (phi > pi) phi -= 2.0*pi;
	};

	d = (theta+pi/2.0)*(((double) fullheight)/pi) - 0.5;
	if (d < 0.0) d = 0.0;
	y = lround(d);
	if (y >= fullheight) y = fullheight-1;

	d = (phi+pi)*(((double) fullwidth)/(2.0*pi)) - 0.5;
	if (d < 0.0) d = 0.0;
	x = lround(d);
	if (x >= fullwidth) x = fullwidth-1;
};

void BrlyDnsmapCollect::pixToPhitheta(
			const uint fullheight
			, const uint fullwidth
			, const bool pacctr
			, const unsigned int y
			, const unsigned int x
			, double& theta
			, double& phi
		) {
	theta = -pi/2.0  + (((double) y)+0.5)*(pi/((double) fullheight));
	phi = -pi + (((double) x)+0.5)*(2.0*pi/((double) fullwidth));

	if (pacctr) {
		phi += pi;
		if (phi > pi) phi -= 2.0*pi;
	};
};

bool BrlyDnsmapCollect::pixToIx(
			const unsigned int y0
			, const unsigned int y1
			, const unsigned int x0
			, const unsigned int x1
			, const unsigned int y
			, const unsigned int x
			, unsigned int& yp
			, unsigned int& xp
		) {
	bool valid = ((y >= y0) && (y <= y1) && (x >= x0) && (x <= x1));

	if (valid) {
		yp = y-y0;
		xp = x-x0;
	};

	return valid;
};

void BrlyDnsmapCollect::ixToPix(
			const unsigned int y0
			, const unsigned int y1
			, const unsigned int x0
			, const unsigned int x1
			, const unsigned int yp
			, const unsigned int xp
			, unsigned int& y
			, unsigned int& x
		) {
	y = yp+y0;
	x = xp+x0;
};

bool BrlyDnsmapCollect::tToIx(
			const uint t0
			, const uint t1
			, const uint dt
			, const uint t
			, unsigned int& ix
		) {
	bool valid = ((t >= t0) && (t <= t1));

	if (valid) ix = floor(((double) (t-t0))/((double) dt));

	return valid;
};

void BrlyDnsmapCollect::getRmatEquatorLeg(
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

void BrlyDnsmapCollect::getRmatZeroLocation(
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

void BrlyDnsmapCollect::getXRmat(
			double _phiX																				// angle for rotation around x-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = 1.0; rmat[1] = 0.0; rmat[2] = 0.0;
	rmat[3] = 0.0; rmat[4] = cos(_phiX); rmat[5] = -sin(_phiX);
	rmat[6] = 0.0; rmat[7] = sin(_phiX); rmat[8] = cos(_phiX);
};

void BrlyDnsmapCollect::getYRmat(
			double _phiY																				// angle for rotation around y-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = cos(_phiY); rmat[1] = 0.0; rmat[2] = -sin(_phiY);
	rmat[3] = 0.0; rmat[4] = 1.0; rmat[5] = 0.0;
	rmat[6] = sin(_phiY); rmat[7] = 0.0; rmat[8] = cos(_phiY);
};

void BrlyDnsmapCollect::getZRmat(
			double _phiZ																				// angle for rotation around z-axis
			, double** _rmat																		// pointer to 3*3 output matrix ; created if NULL
		) {
	if (*_rmat == NULL) *_rmat = new double[9];
	double* rmat = *_rmat;

	rmat[0] = cos(_phiZ); rmat[1] = -sin(_phiZ); rmat[2] = 0.0;
	rmat[3] = sin(_phiZ); rmat[4] = cos(_phiZ); rmat[5] = 0.0;
	rmat[6] = 0.0; rmat[7] = 0.0; rmat[8] = 1.0;
};

void BrlyDnsmapCollect::transpAmat(
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

void BrlyDnsmapCollect::multAmatBmat(
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

void BrlyDnsmapCollect::multAmatBmatT(
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

void BrlyDnsmapCollect::multAmatBvec(
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

double BrlyDnsmapCollect::getDotProd(
			double* _avec																				// a input vector (double[3])
			, double* _bvec																			// b input vector (double[3])
		) {
	return(_avec[0]*_bvec[0] + _avec[1]*_bvec[1] + _avec[2]*_bvec[2]);
};

void BrlyDnsmapCollect::sphrToCart(
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

void BrlyDnsmapCollect::cartToSphr(
			double* _vec																				// cartesian vector
			, double* _r																				// pointer to resulting radius
			, double* _theta																		// pointer to resulting angle from equatorial (x-y) plane
			, double* _phi																			// pointer to resulting angle from x-axis
		) {
	*_r = sqrt(_vec[0]*_vec[0] + _vec[1]*_vec[1] + _vec[2]*_vec[2]);
	*_theta = asin(_vec[2] / *_r);
	*_phi = atan2(_vec[1], _vec[0]);
};

double BrlyDnsmapCollect::degToRad(
			double _deg																					// angle in degrees (0° .. 360°)
		) {
	return(pi*_deg/180.0);
};

double BrlyDnsmapCollect::radToDeg(
			double _rad																					// angle in degrees (0° .. 360°)
		) {
	return(180.0*_rad/pi);
};

void BrlyDnsmapCollect::legToRad(
			BrlyMLeg* leg
		) {
	leg->deltaphi = degToRad(leg->deltaphi);
	leg->alpha = degToRad(leg->alpha);
	leg->xPhi0 = degToRad(leg->xPhi0);
	leg->xPhi1 = degToRad(leg->xPhi1);
	leg->xAlpha = degToRad(leg->xAlpha);
};

void BrlyDnsmapCollect::locToRad(
			BrlyMLocation* loc
		) {
	loc->theta = degToRad(loc->theta);
	loc->phi = degToRad(loc->phi);
	loc->alpha = degToRad(loc->alpha);
};

void BrlyDnsmapCollect::segToRad(
			BrlyMSegment* seg
		) {
	seg->deltaphi = degToRad(seg->deltaphi);
	seg->theta0 = degToRad(seg->theta0);
	seg->theta1 = degToRad(seg->theta1);
	seg->phi0 = degToRad(seg->phi0);
	seg->phi1 = degToRad(seg->phi1);
};
// IP cust --- IEND


