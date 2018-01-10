/**
  * \file BrlyMapgenConmap.cpp
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

#include "BrlyMapgenConmap.h"

DpchRetBrly* BrlyMapgenConmap::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyMapgenConmap* dpchinv
		) {
	ubigint refBrlyMConnection = dpchinv->refBrlyMConnection;
	ubigint jrefLeg = dpchinv->jrefLeg;
	ubigint jrefLoc = dpchinv->jrefLoc;
	ubigint jrefFlt = dpchinv->jrefFlt;
	ubigint jrefRly = dpchinv->jrefRly;
	ubigint jrefNde = dpchinv->jrefNde;
	uint scale = dpchinv->scale;
	uint width = dpchinv->width;
	uint height = dpchinv->height;
	int xoffset = dpchinv->xoffset;
	int yoffset = dpchinv->yoffset;
	bool wrtree = dpchinv->wrtree;
	string filename = dpchinv->filename;

	bool success;

	// IP run --- IBEGIN
	short*& _etopo = xchg->databrlymapgen.etopo;
	vector<utinyint>& _RvsZ = xchg->databrlymapgen.RvsZ;
	vector<utinyint>& _GvsZ = xchg->databrlymapgen.GvsZ;
	vector<utinyint>& _BvsZ = xchg->databrlymapgen.BvsZ;

	BrlyMConnection* con = NULL;
	BrlyMFlight* flt = NULL;

	BrlyMLeg* leg = NULL;
	double* legrmat = NULL;

	ListBrlyQConMapLeg qlegs;
	BrlyQConMapLeg* qleg = NULL;

	vector<double*> qlegrmats;
	double* qlegrmat = NULL;

	ListBrlyQConMapFlight qflts;
	BrlyQConMapFlight* qflt = NULL;
	BrlyQConMapFlight* qflt2 = NULL;

	vector<double> omegas;
	double omega;

	map<ubigint, unsigned int> icsQlegs; // key: refEqp (flt), value: ix in qlegs/qlegrmats ; only for qflts with qwr == true
	map<ubigint, unsigned int> icsQflts; // key: refEqp (flt), value: ix in qflts ; only for qflts with qwr == true

	ListBrlyQConMapLocation qlocs;
	BrlyQConMapLocation* qloc = NULL;
	BrlyQConMapLocation* qloc2 = NULL;

	map<ubigint, unsigned int> icsQlocs; // key: refEqp (loc), value: ix in qlocs ; only for qlocs with qwr == true

	ListBrlyQConMapRelay qrlys;
	BrlyQConMapRelay* qrly = NULL;

	ListBrlyQConMapNode qndes;
	BrlyQConMapNode* qnde = NULL;
	BrlyQConMapNode* qnde2 = NULL;

	vector<unsigned int> icsRlynde;

	BrlyMLocation* bgnloc = NULL;
	BrlyMLocation* endloc = NULL;

	vector<Coo*> coos;
	Coo* coo = NULL;
	Coo* coo2 = NULL;

	double deltaphi, minphi, maxphi, pixphi;
	double mintheta, maxtheta, pixtheta;

	double legphi, phi;
	long phiix;

	double legtheta, theta;
	long thetaix;

	double qlegphi0, qlegphi1;

	double* mat = NULL;

	double x, y;

	unsigned int ix;

	double x0, y0, d, dx, dy, lammin;
	unsigned int n, ixmin;

	unsigned int start, stop;
	unsigned int qstart, qstop;

	xmlTextWriter* wr = NULL;

	bool found, good;

	// load connection
	dbsbrly->tblbrlymconnection->loadRecByRef(refBrlyMConnection, &con);

	// load communication corridor
	dbsbrly->tblbrlymleg->loadRecBySQL("SELECT * FROM TblBrlyMLeg WHERE ref = " + to_string(con->corRefBrlyMLeg), &leg); legToRad(leg);

	dbsbrly->tblbrlymlocation->loadRecByRef(leg->bgnRefBrlyMLocation, &bgnloc); locToRad(bgnloc);
	dbsbrly->tblbrlymlocation->loadRecByRef(leg->endRefBrlyMLocation, &endloc); locToRad(endloc);

	// find comm. corridor rotation matrix
	getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &legrmat);

	delete bgnloc;
	delete endloc;

	// load legs within visibility
	dbsbrly->tblbrlyqconmapleg->loadRstByJref(jrefLeg, false, qlegs);
	for (unsigned int i=0;i<qlegs.nodes.size();i++) qlegToRad(qlegs.nodes[i]);

	// load flights
	dbsbrly->tblbrlyqconmapflight->loadRstByJref(jrefFlt, false, qflts);
	for (unsigned int i=0;i<qflts.nodes.size();i++) qfltToRad(qflts.nodes[i]);

	// load locations within visibility
	dbsbrly->tblbrlyqconmaplocation->loadRstByJref(jrefLoc, false, qlocs);
	for (unsigned int i=0;i<qlocs.nodes.size();i++) qlocToRad(qlocs.nodes[i]);

	// load relays
	dbsbrly->tblbrlyqconmaprelay->loadRstByJref(jrefRly, false, qrlys);

	// load nodes
	dbsbrly->tblbrlyqconmapnode->loadRstByJref(jrefNde, false, qndes);

	// --- generate map

	// width of entire pane in radian
	deltaphi = leg->deltaphi;
	minphi = 0.0;
	maxphi = deltaphi;

	// width of a pixel (such that 1km equals 1pix at scale 1)
	pixphi = 1.0e3 / ((double) (xchg->stgbrlygeometry.earthradius * scale));

	// height of entire pane in radian
	mintheta = -leg->alpha;
	maxtheta = leg->alpha;

	// height of a pixel
	pixtheta = 1.0e3 / ((double) (xchg->stgbrlygeometry.earthradius * scale));

	// adjust width to full width if not specified
	if (width == 0) {
		width = ceil(deltaphi/pixphi);
		xoffset = width/2;
	};

	// altitude (z) information
	dpchret->red.resize(width*height);
	dpchret->green.resize(width*height);
	dpchret->blue.resize(width*height);

	for (int i=0;i<height;i++) {
		legtheta = ((double) (i-((int)height)/2+yoffset)) * pixtheta;

		for (int j=0;j<width;j++) {
			legphi = ((double) (j-((int)width)/2+xoffset)) * pixphi;

			if ((legtheta < mintheta) || (legtheta > maxtheta) || (legphi < minphi) || (legphi > maxphi)) {
				// crop
				ix = 65535;

			} else {
				// transform to earth coordinates
				legToSphr(legphi, legtheta, legrmat, &phi, &theta);

				phiix = lround((phi + pi) * 21600.0/(2.0*pi));
				thetaix = lround((theta + pi/2.0) * 10800.0/pi);

				ix = ((int) _etopo[thetaix*21601+phiix]) + 32768;
			};

			dpchret->red[i*width+j] = _RvsZ[ix];
			dpchret->green[i*width+j] = _GvsZ[ix];
			dpchret->blue[i*width+j] = _BvsZ[ix];
		};
	};

///
/// dump geometry basics
//cout << "pixphi = " << pixphi << endl;
//cout << "pixtheta = " << pixtheta << endl;
//cout << "xoffset = " << xoffset << endl;
//cout << "yoffset = " << yoffset << endl;
//cout << "width = " << width << endl;
//cout << "height = " << height << endl;
///

	// --- determine active time span
	start = con->start;
	stop = con->stop;

	dbsbrly->tblbrlymflight->loadRecByRef(con->refBrlyMFlight, &flt);

	// visible phi span of corridor is equivalent to visible phi span of flight's route
	omega = deltaphi / ((double) (flt->stop-flt->start));

	legphi = ((double) (0-((int)width)/2+xoffset)) * pixphi;
	if (legphi > minphi) start = qlegphiToTime(legphi, flt->start, omega);

	legphi = ((double) ((width-1)-((int)width)/2+xoffset)) * pixphi;
	if (legphi < maxphi) stop = qlegphiToTime(legphi, flt->start, omega);

	delete flt;

	// --- legs and flights within visibility
	for (unsigned int i=0;i<qflts.nodes.size();i++) qflts.nodes[i]->qwr = false;
	omegas.resize(qflts.nodes.size(), 0.0);

	for (unsigned int i=0;i<qlegs.nodes.size();i++) {
		qleg = qlegs.nodes[i];

		// load leg begin and end locations
		dbsbrly->tblbrlymlocation->loadRecByRef(qleg->mbgnRefBrlyMLocation, &bgnloc); locToRad(bgnloc);
		dbsbrly->tblbrlymlocation->loadRecByRef(qleg->mendRefBrlyMLocation, &endloc); locToRad(endloc);

		// - determine leg rotation matrix (qleg coordinates to leg coordinates)
		mat = NULL;
		getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &mat);

		delete bgnloc;
		delete endloc;

		// multiply transpose of qlegrmat with legrmat
		qlegrmat = NULL;
		multAmatBmatT(legrmat, mat, &qlegrmat, 3);
		delete[] mat;

		qlegrmats.push_back(qlegrmat);

		// -- initialize preliminary line offset as bgnvis coordinates

		// make sure qleg vector starts with smaller phi of qleg
		if (qleg->VisOrgLegphi0 > qleg->VisOrgLegphi1) {
			d = qleg->VisOrgLegphi0;
			qleg->VisOrgLegphi0 = qleg->VisOrgLegphi1;
			qleg->VisOrgLegphi1 = d;
		};

		qlegphiToLeg(qleg->VisOrgLegphi0, qlegrmat, &phi, &theta);
		radToCoo(phi, theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
		coo = new Coo(Cootype::BGNVIS, x, y, 0.0);
		coos.push_back(coo);

		// -- find endvis coordinates
		qlegphiToLeg(qleg->VisOrgLegphi1, qlegrmat, &phi, &theta);
		radToCoo(phi, theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
		coo = new Coo(Cootype::ENDVIS, x, y, 1.0);
		coos.push_back(coo);

		// -- determine direction
		x0 = coos[0]->x;
		y0 = coos[0]->y;
		dx = coos[1]->x - x0;
		dy = coos[1]->y - y0;

		d = sqrt(dx*dx + dy*dy);
		dx /= d;
		dy /= d;

		coos[1]->lam = d;

		// -- find coordinates of intersections of leg with map boundaries ; only append if part of visible leg and don't coincide with bgnvis and endvis
		if (dx != 0.0) {
			// determine west and east intersections
			coo = new Coo(Cootype::WXSEC, 0.0, 0.0, 0.0);
			coo->lam = (coo->x - x0) / dx;
			coo->y = y0 + coo->lam*dy;
			if ((coo->lam > 0.0) && (coo->lam < d)) {
				if ( ((fabs(coo->x - coos[0]->x) + fabs(coo->y - coos[0]->y)) > 0.1) && ((fabs(coo->x - coos[1]->x) + fabs(coo->y - coos[1]->y)) > 0.1) ) coos.push_back(coo); else delete coo;
			} else {
				delete coo;
			};
			
			coo = new Coo(Cootype::EXSEC, width, 0.0, 0.0);
			coo->lam = (coo->x - x0) / dx;
			coo->y = y0 + coo->lam*dy;
			if ((coo->lam > 0.0) && (coo->lam < d)) {
				if ( ((fabs(coo->x - coos[0]->x) + fabs(coo->y - coos[0]->y)) > 0.1) && ((fabs(coo->x - coos[1]->x) + fabs(coo->y - coos[1]->y)) > 0.1) ) coos.push_back(coo); else delete coo;
			} else {
				delete coo;
			};
		};

		if (dy != 0.0) {
			// determine north and south intersections
			coo = new Coo(Cootype::NXSEC, 0.0, 0.0, 0.0);
			coo->lam = (coo->y - y0) / dy;
			coo->x = x0 + coo->lam*dx;
			if ((coo->lam > 0.0) && (coo->lam < d)) {
				if ( ((fabs(coo->x - coos[0]->x) + fabs(coo->y - coos[0]->y)) > 0.1) && ((fabs(coo->x - coos[1]->x) + fabs(coo->y - coos[1]->y)) > 0.1) ) coos.push_back(coo); else delete coo;
			} else {
				delete coo;
			};

			coo = new Coo(Cootype::SXSEC, 0.0, height, 0.0);
			coo->lam = (coo->y - y0) / dy;
			coo->x = x0 + coo->lam*dx;
			if ((coo->lam > 0.0) && (coo->lam < d)) {
				if ( ((fabs(coo->x - coos[0]->x) + fabs(coo->y - coos[0]->y)) > 0.1) && ((fabs(coo->x - coos[1]->x) + fabs(coo->y - coos[1]->y)) > 0.1) ) coos.push_back(coo); else delete coo;
			} else {
				delete coo;
			};
		};

		// -- validate remaining coordinates (crop)
		for (unsigned int j=0;j<coos.size();j++) {
			coo = coos[j];

			if ((coo->x < -0.1) || (coo->x > (width+0.1)) || (coo->y < -0.1) || (coo->y > (height+0.1))) {
				delete coo;
				coos[j] = NULL;
			};
		};

		// -- stuff remaining coordinates
		for (unsigned int j=0;j<coos.size();j++) {
			if (coos[j] == NULL) {
				for (unsigned int k=j+1;k<coos.size();k++) {
					if (coos[k] != NULL) {
						coos[j] = coos[k];
						coos[k] = NULL;
						break;
					};
				};
			};
		};
		for (n=0;n<coos.size();n++) if (coos[n] == NULL) break;
		coos.resize(n);

		// -- sort remaining coordinates
		for (unsigned int j=0;j<coos.size();j++) {
			coo = coos[j];
			lammin = coo->lam;
			ixmin = j;

			for (unsigned int k=j+1;k<coos.size();k++) {
				coo2 = coos[k];

				if (coo2->lam < lammin) {
					lammin = coo2->lam;
					ixmin = k;
				};
			};

			if (ixmin != j) {
				coos[j] = coos[ixmin];
				coos[ixmin] = coo;
			};
		};

		// -- establish final coordinate system
		if (coos.size() >= 2) {
			qleg->x0 = coos[0]->x;
			qleg->y0 = coos[0]->y;

			// determine phi span visible on pane (needed for flights/nodes)
			// at this stage, lam(VisOrgLegphi0) = 0, lam(VisOrgLegphi1) = d, linear
			qlegphi0 = coos[0]->lam/d * (qleg->VisOrgLegphi1-qleg->VisOrgLegphi0) + qleg->VisOrgLegphi0;
			qlegphi1 = coos[coos.size()-1]->lam/d * (qleg->VisOrgLegphi1-qleg->VisOrgLegphi0) + qleg->VisOrgLegphi0;

			// transform lam of coordinates between coos[0] and coos[coos.size()-1]
			for (unsigned int j=1;j<coos.size();j++) {
				coo = coos[j];
				coo->lam = coo->lam - coos[0]->lam;
			};
			coos[0]->lam = 0.0;

			// factor lam into unity vector
			qleg->dx = coos[coos.size()-1]->lam * dx;
			qleg->dy = coos[coos.size()-1]->lam * dy;

		} else {
			qleg->x0 = -1.0;
			qleg->y0 = -1.0;
		};

		qleg->qwr = ((qleg->x0 != -1.0) && (qleg->y0 != -1.0));

		if (qleg->qwr) {
			// -- process qflts on current qleg
			for (unsigned int j=0;j<qflts.nodes.size();j++) {
				qflt = qflts.nodes[j];

				if (qflt->mrefBrlyMLeg == qleg->mref) {
					omega = qleg->mdeltaphi / ((double) (qflt->mstop - qflt->mstart));
					omegas[j] = omega;

					// - detemine trajectory using parametrization in time

					// use t(qlegphi0), t(qlegphi1) ; qflt->x1Start/x1Stop are not needed
					qstart = qlegphiToTime(qlegphi0, qflt->mstart, omega);
					qstop = qlegphiToTime(qlegphi1, qflt->mstart, omega);

					qflt->qwr = ((qstart < stop) && (qstop > start));

					if (qflt->qwr) {
						if (qstart < start) qstart = start;
						if (qstop > stop) qstop = stop;

						qlegphiToLeg(timeToQlegphi(qstart, qflt->mstart, omega), qlegrmat, &phi, &theta);
						radToCoo(phi, theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
						qflt->x0 = x;
						qflt->y0 = y;

						qflt->t0 = qstart;

						qlegphiToLeg(timeToQlegphi(qstop, qflt->mstart, omega), qlegrmat, &phi, &theta);
						radToCoo(phi, theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
						qflt->dx = x - qflt->x0;
						qflt->dy = y - qflt->y0;

						qflt->dt = qstop-qstart;

						icsQlegs[qflt->mrefBrlyMEquipment] = i;
						icsQflts[qflt->mrefBrlyMEquipment] = j;
					};
				};
			};
		};

		// -- clean up
		for (unsigned int j=0;j<coos.size();j++) if (coos[j] != NULL) delete coos[j];
		coos.resize(0);
	};

	// --- locations within visibility
	for (unsigned int i=0;i<qlocs.nodes.size();i++) {
		qloc = qlocs.nodes[i];

		radToCoo(qloc->legphi, qloc->legtheta, pixphi, pixtheta, height, width, xoffset, yoffset, &(qloc->x), &(qloc->y));

		qloc->qwr = ((qloc->x > -0.1) && (qloc->x < (((double) width)+0.1)) && (qloc->y > -0.1) && (qloc->y < (((double) height)+0.1)));
		if (qloc->qwr) icsQlocs[qloc->mrefBrlyMEquipment] = i;
	};

	// --- relays and their nodes
	for (unsigned int i=0;i<qndes.nodes.size();i++) qndes.nodes[i]->qwr = false;

	for (unsigned int i=0;i<qrlys.nodes.size();i++) {
		qrly = qrlys.nodes[i];

		qrly->qwr = ((qrly->x1Start < stop) && (qrly->x1Stop > start));

		if (qrly->qwr && (qrly->Connected || (!qrly->Connected && wrtree))) {
			// -- flag nodes which are part of the current relay
			icsRlynde.resize(0);
			for (unsigned int j=0;j<qndes.nodes.size();j++) if (qndes.nodes[j]->refBrlyMRelay == qrly->ref) icsRlynde.push_back(j);

			// -- traverse relay nodes
			for (unsigned int j=0;j<icsRlynde.size();j++) {
				qnde = qndes.nodes[icsRlynde[j]];
				qnde->jnumRly = qrly->jnum;

				// find super node
				found = false;
				if (qnde->supRefBrlyMNode != 0) {
					for (unsigned int k=0;k<icsRlynde.size();k++) {
						qnde2 = qndes.nodes[icsRlynde[k]];

						if (qnde2->ref == qnde->supRefBrlyMNode) {
							found = true;
							break;
						};
					};
				};

				if (found) {
					// check for presence of the corresponding equipment
					qflt = NULL; qloc = NULL;
					if (icsQflts.find(qnde->refBrlyMEquipment) != icsQflts.end()) qflt = qflts.nodes[icsQflts[qnde->refBrlyMEquipment]];
					else if (icsQlocs.find(qnde->refBrlyMEquipment) != icsQlocs.end()) qloc = qlocs.nodes[icsQlocs[qnde->refBrlyMEquipment]];

					qflt2 = NULL; qloc2 = NULL;
					if (icsQflts.find(qnde2->refBrlyMEquipment) != icsQflts.end()) qflt2 = qflts.nodes[icsQflts[qnde2->refBrlyMEquipment]];
					else if (icsQlocs.find(qnde2->refBrlyMEquipment) != icsQlocs.end()) qloc2 = qlocs.nodes[icsQlocs[qnde2->refBrlyMEquipment]];

					// - determine trajectory based on equipment type
					if ((qflt || qloc) && (qflt2 || qloc2)) {

						if (qloc) {
							qnde->x0 = qloc->x;
							qnde->y0 = qloc->y;
						};

						if (qloc2) {
							qnde->u0 = qloc2->x;
							qnde->v0 = qloc2->y;
						};

						qnde->dx = 0.0;
						qnde->dy = 0.0;
						qnde->du = 0.0;
						qnde->dv = 0.0;

						if (qloc && qloc2) {
							// both equipments are fixed
							qnde->t0 = qrly->x1Start;
							qnde->dt = qrly->x1Stop-qrly->x1Start;

							qnde->qwr = true;

						} else {
							// narrow down t
							qstart = qrly->x1Start;
							qstop = qrly->x1Stop;

							good = true;

							if (qflt) {
								good = ((qflt->t0 < qstop) && ((qflt->t0+qflt->dt) > qstart));
								if (good) {
									if (qflt->t0 > qstart) qstart = qflt->t0;
									if ((qflt->t0+qflt->dt) < qstop) qstop = (qflt->t0+qflt->dt);
								};
							};

							if (good && qflt2) {
								good = ((qflt2->t0 < qstop) && ((qflt2->t0+qflt2->dt) > qstart));
								if (good) {
									if (qflt2->t0 > qstart) qstart = qflt2->t0;
									if ((qflt2->t0+qflt2->dt) < qstop) qstop = (qflt2->t0+qflt2->dt);
								};
							};

							if (good) {
								qnde->qwr = true;

								if (qflt) {
									qlegrmat = qlegrmats[icsQlegs[qnde->refBrlyMEquipment]];
									omega = omegas[icsQflts[qnde->refBrlyMEquipment]];

									qlegphiToLeg(timeToQlegphi(qstart, qflt->mstart, omega), qlegrmat, &phi, &theta);
									radToCoo(phi, theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
									qnde->x0 = x;
									qnde->y0 = y;

									qlegphiToLeg(timeToQlegphi(qstop, qflt->mstart, omega), qlegrmat, &phi, &theta);
									radToCoo(phi, theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
									qnde->dx = x - qnde->x0;
									qnde->dy = y - qnde->y0;
								};

								if (qflt2) {
									qlegrmat = qlegrmats[icsQlegs[qnde2->refBrlyMEquipment]];
									omega = omegas[icsQflts[qnde2->refBrlyMEquipment]];

									qlegphiToLeg(timeToQlegphi(qstart, qflt2->mstart, omega), qlegrmat, &phi, &theta);
									radToCoo(phi, theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
									qnde->u0 = x;
									qnde->v0 = y;

									qlegphiToLeg(timeToQlegphi(qstop, qflt2->mstart, omega), qlegrmat, &phi, &theta);
									radToCoo(phi, theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
									qnde->du = x - qnde->u0;
									qnde->dv = y - qnde->v0;
								};
							};
						};

						qnde->t0 = qstart;
						qnde->dt = qstop-qstart;
					};
				};
			};
		};
	};

/// DEBUG
unsigned int wrcnt;

wrcnt = 0;
for (unsigned int i=0;i<qlegs.nodes.size();i++) if (qlegs.nodes[i]->qwr == true) wrcnt++;
cout << "qlegs.size() = " << qlegs.nodes.size() << ", " << wrcnt << " to write" << endl;

wrcnt = 0;
for (unsigned int i=0;i<qflts.nodes.size();i++) if (qflts.nodes[i]->qwr == true) wrcnt++;
cout << "qflts.size() = " << qflts.nodes.size() << ", " << wrcnt << " to write" << endl;

wrcnt = 0;
for (unsigned int i=0;i<qlocs.nodes.size();i++) if (qlocs.nodes[i]->qwr == true) wrcnt++;
cout << "qlocs.size() = " << qlocs.nodes.size() << ", " << wrcnt << " to write" << endl;

wrcnt = 0;
for (unsigned int i=0;i<qrlys.nodes.size();i++) if (qrlys.nodes[i]->qwr == true) wrcnt++;
cout << "qrlys.size() = " << qrlys.nodes.size() << ", " << wrcnt << " to write" << endl;

wrcnt = 0;
for (unsigned int i=0;i<qndes.nodes.size();i++) if (qndes.nodes[i]->qwr == true) wrcnt++;
cout << "qndes.size() = " << qndes.nodes.size() << ", " << wrcnt << " to write" << endl;
///

	// --- update query table content
	for (unsigned int i=0;i<qlegs.nodes.size();i++) qlegToDeg(qlegs.nodes[i]);
	for (unsigned int i=0;i<qflts.nodes.size();i++) qfltToDeg(qflts.nodes[i]);
	for (unsigned int i=0;i<qlocs.nodes.size();i++) qlocToDeg(qlocs.nodes[i]);

	for (unsigned int i=0;i<qlegs.nodes.size();i++) dbsbrly->tblbrlyqconmapleg->updateRec(qlegs.nodes[i]);
	for (unsigned int i=0;i<qflts.nodes.size();i++) dbsbrly->tblbrlyqconmapflight->updateRec(qflts.nodes[i]);
	for (unsigned int i=0;i<qlocs.nodes.size();i++) dbsbrly->tblbrlyqconmaplocation->updateRec(qlocs.nodes[i]);
	for (unsigned int i=0;i<qrlys.nodes.size();i++) dbsbrly->tblbrlyqconmaprelay->updateRec(qrlys.nodes[i]);
	for (unsigned int i=0;i<qndes.nodes.size();i++) dbsbrly->tblbrlyqconmapnode->updateRec(qndes.nodes[i]);

	if (wrfile) {
		// --- write .xml source file ; query content is added by engine
		dpchret->filename = Tmp::newfile(xchg->tmppath, "xml");

		startwriteFile(xchg->tmppath + "/" + dpchret->filename, &wr);

		xmlTextWriterStartElement(wr, BAD_CAST "src");
			writeUint(wr, "width", width);
			writeUint(wr, "height", height);
			writeUtinyintvec(wr, "red", dpchret->red);
			writeUtinyintvec(wr, "green", dpchret->green);
			writeUtinyintvec(wr, "blue", dpchret->blue);
		xmlTextWriterEndElement(wr);

		closewriteFile(wr);
	};

	delete leg;
	delete con;
	delete[] legrmat;
	for (unsigned int i=0;i<qlegrmats.size();i++) delete[](qlegrmats[i]);

///
	dpchret->mask = {DpchRetBrlyMapgenConmap::SUCCESS,DpchRetBrlyMapgenConmap::RED,DpchRetBrlyMapgenConmap::GREEN,DpchRetBrlyMapgenConmap::BLUE,DpchRetBrlyMapgenConmap::FILENAME};
///
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
void BrlyMapgenConmap::radToCoo(
			const double phi
			, const double theta
			, const double pixphi
			, const double pixtheta
			, const uint height
			, const uint width
			, const int xoffset
			, const int yoffset
			, double* x
			, double* y
		) {

	*x = phi/pixphi + ((double) (width/2.0)) - ((double) xoffset);
	*y = ((double) height/2.0) - theta/pixtheta + ((double) yoffset);
};

void BrlyMapgenConmap::legToSphr(
			const double legphi
			, const double legtheta
			, const double* legrmat
			, double* phi
			, double* theta
		) {
	double a, b, c;

	a = legrmat[0]*cos(legtheta)*cos(legphi) + legrmat[3]*cos(legtheta)*sin(legphi) + legrmat[6]*sin(legtheta);
	b = legrmat[1]*cos(legtheta)*cos(legphi) + legrmat[4]*cos(legtheta)*sin(legphi) + legrmat[7]*sin(legtheta);
	c = legrmat[2]*cos(legtheta)*cos(legphi) + legrmat[5]*cos(legtheta)*sin(legphi) + legrmat[8]*sin(legtheta);

	*theta = asin(c);
	*phi = atan2(b, a);
};

void BrlyMapgenConmap::qlegphiToLeg(
			const double qlegphi
			, const double* qlegrmat
			, double* legphi
			, double* legtheta
		) {

	*legphi = atan2(qlegrmat[3]*cos(qlegphi) + qlegrmat[4]*sin(qlegphi), qlegrmat[0]*cos(qlegphi) + qlegrmat[1]*sin(qlegphi));
	*legtheta = asin(qlegrmat[6]*cos(qlegphi) + qlegrmat[7]*sin(qlegphi));
};

double BrlyMapgenConmap::timeToQlegphi(
			const unsigned int t
			, const unsigned int start
			, const double omega
		) {
	return(omega * ((double) (t-start)));
};

unsigned int BrlyMapgenConmap::qlegphiToTime(
			const double phi
			, const unsigned int start
			, const double omega
		) {
	return(lround(phi/omega + ((double) start)));
};

void BrlyMapgenConmap::qlegToRad(
			BrlyQConMapLeg* qleg
		) {
	qleg->VisOrgLegphi0 = degToRad(qleg->VisOrgLegphi0);
	qleg->VisOrgLegphi1 = degToRad(qleg->VisOrgLegphi1);
	qleg->mdeltaphi = degToRad(qleg->mdeltaphi);
};

void BrlyMapgenConmap::qlegToDeg(
			BrlyQConMapLeg* qleg
		) {
	qleg->VisOrgLegphi0 = radToDeg(qleg->VisOrgLegphi0);
	qleg->VisOrgLegphi1 = radToDeg(qleg->VisOrgLegphi1);
	qleg->mdeltaphi = radToDeg(qleg->mdeltaphi);
};

void BrlyMapgenConmap::qlocToRad(
			BrlyQConMapLocation* qloc
		) {
	qloc->legphi = degToRad(qloc->legphi);
	qloc->legtheta = degToRad(qloc->legtheta);
};

void BrlyMapgenConmap::qlocToDeg(
			BrlyQConMapLocation* qloc
		) {
	qloc->legphi = radToDeg(qloc->legphi);
	qloc->legtheta = radToDeg(qloc->legtheta);
};

void BrlyMapgenConmap::qfltToRad(
			BrlyQConMapFlight* qflt
		) {
	qflt->x2Legphi0 = degToRad(qflt->x2Legphi0);
	qflt->x2Legphi1 = degToRad(qflt->x2Legphi1);
};

void BrlyMapgenConmap::qfltToDeg(
			BrlyQConMapFlight* qflt
		) {
	qflt->x2Legphi0 = radToDeg(qflt->x2Legphi0);
	qflt->x2Legphi1 = radToDeg(qflt->x2Legphi1);
};
// IP cust --- IEND


