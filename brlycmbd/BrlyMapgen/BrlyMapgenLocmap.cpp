/**
  * \file BrlyMapgenLocmap.cpp
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

#include "BrlyMapgenLocmap.h"

DpchRetBrly* BrlyMapgenLocmap::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyMapgenLocmap* dpchinv
		) {
	ubigint refBrlyMLocation = dpchinv->refBrlyMLocation;
	ubigint jrefLeg = dpchinv->jrefLeg;
	ubigint jrefProxloc = dpchinv->jrefProxloc;
	ubigint jrefVisloc = dpchinv->jrefVisloc;
	uint scale = dpchinv->scale;
	uint width = dpchinv->width;
	uint height = dpchinv->height;
	int xoffset = dpchinv->xoffset;
	int yoffset = dpchinv->yoffset;
	string filename = dpchinv->filename;

	bool success;

	// IP run --- IBEGIN
	short*& _etopo = xchg->databrlymapgen.etopo;
	vector<utinyint>& _RvsZ = xchg->databrlymapgen.RvsZ;
	vector<utinyint>& _GvsZ = xchg->databrlymapgen.GvsZ;
	vector<utinyint>& _BvsZ = xchg->databrlymapgen.BvsZ;

	BrlyMLocation* loc = NULL;

	ListBrlyQLocMapLeg qlegs;
	BrlyQLocMapLeg* qleg = NULL;

	ListBrlyMLocation bgnlocs;
	BrlyMLocation* bgnloc = NULL;
	ListBrlyMLocation endlocs;
	BrlyMLocation* endloc = NULL;

	ListBrlyQLocMapProxLocation qplocs;
	BrlyQLocMapProxLocation* qploc = NULL;

	ListBrlyQLocMapVisLocation qvlocs;
	BrlyQLocMapVisLocation* qvloc = NULL;

	double deltaphi, minphi, maxphi, pixphi;
	double deltatheta, mintheta, maxtheta, pixtheta;

	double phi;
	long phiix;

	double theta;
	long thetaix;

	double x, y;

	unsigned int ix;

	BrlyMLeg* leg = NULL;
	double* legrmat = NULL;

	vector<Coo*> coos;
	Coo* coo = NULL;
	Coo* coo2 = NULL;

	double x0, y0, d, dx, dy, lam, lammin, lammax;
	unsigned int n, ixmin;

	xmlTextWriter* wr = NULL;

	//cout << "refBrlyMLocation is " << refBrlyMLocation << endl;

	// load location
	dbsbrly->tblbrlymlocation->loadRecByRef(refBrlyMLocation, &loc);
	locToRad(loc);

	// load legs within visibility
	dbsbrly->tblbrlyqlocmapleg->loadRstByJref(jrefLeg, false, qlegs);
	for (unsigned int i=0;i<qlegs.nodes.size();i++) qlegToRad(qlegs.nodes[i]);

	// load locations in proximity
	dbsbrly->tblbrlyqlocmapproxlocation->loadRstByJref(jrefProxloc, false, qplocs);
	for (unsigned int i=0;i<qplocs.nodes.size();i++) qplocToRad(qplocs.nodes[i]);

	// load locations within visibility
	dbsbrly->tblbrlyqlocmapvislocation->loadRstByJref(jrefVisloc, false, qvlocs);
	for (unsigned int i=0;i<qvlocs.nodes.size();i++) qvlocToRad(qvlocs.nodes[i]);

	// width of entire pane in radian
	deltaphi = 400.0e3 / (xchg->stgbrlygeometry.earthradius * cos(loc->theta));
	minphi = loc->phi - 0.5*deltaphi;
	maxphi = loc->phi + 0.5*deltaphi;

	// width of a pixel (such that 1km equals 1pix at scale 1)
	pixphi = deltaphi / ((double) (400.0 * scale));

	// height of entire pane in radian
	deltatheta = 400.0e3 / xchg->stgbrlygeometry.earthradius;
	mintheta = loc->theta - 0.5*deltatheta; if (mintheta < -0.5*pi) mintheta = -0.5*pi;
	maxtheta = loc->theta + 0.5*deltatheta; if (maxtheta > 0.5*pi) maxtheta = 0.5*pi;

	// height of a pixel
	pixtheta = deltatheta / ((double) (400.0 * scale));

	// altitude (z) information
	dpchret->red.resize(width*height);
	dpchret->green.resize(width*height);
	dpchret->blue.resize(width*height);

	for (int i=0;i<height;i++) {
		theta = loc->theta + ((double) (i-((int)height)/2+yoffset)) * pixtheta;

		for (int j=0;j<width;j++) {
			phi = loc->phi + ((double) (j-((int)width)/2+xoffset)) * pixphi;

			if ((theta < mintheta) || (theta > maxtheta) || (phi < minphi) || (phi > maxphi)) {
				// crop
				ix = 65535;

			} else {
				// principal value
				if (phi < -pi) phi += 2.0*pi;
				if (phi > pi) phi -= 2.0*pi;

				phiix = lround((phi + pi) * 21600.0/(2.0*pi));
				thetaix = lround((theta + pi/2.0) * 10800.0/pi);

				ix = ((int) _etopo[thetaix*21601+phiix]) + 32768;
			};

			dpchret->red[i*width+j] = _RvsZ[ix];
			dpchret->green[i*width+j] = _GvsZ[ix];
			dpchret->blue[i*width+j] = _BvsZ[ix];
		};
	};

	// --- legs within visibility
	for (unsigned int i=0;i<qlegs.nodes.size();i++) {
		qleg = qlegs.nodes[i];

		qleg->x0 = -1.0;
		qleg->y0 = -1.0;
		qleg->lam1 = -1.0;
		qleg->lam2 = -1.0;
		qleg->lam3 = -1.0;

		// load leg
		dbsbrly->tblbrlymleg->loadRecByRef(qleg->mref, &leg); legToRad(leg);

		// load leg begin and end locations
		dbsbrly->tblbrlymlocation->loadRecByRef(qleg->mbgnRefBrlyMLocation, &bgnloc); locToRad(bgnloc);
		bgnlocs.nodes.push_back(bgnloc);

		dbsbrly->tblbrlymlocation->loadRecByRef(qleg->mendRefBrlyMLocation, &endloc); locToRad(endloc);
		endlocs.nodes.push_back(endloc);

		// determine leg rotation matrix (leg coordinates to earth coordinates)
		getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &legrmat);

		// -- initialize preliminary line offset as bgnvis coordinates
		legphiToSphr(qleg->x1VisLegphi0, legrmat, &phi, &theta);
		radToCoo(phi, theta, loc->phi, loc->theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
		coo = new Coo(Cootype::BGNVIS, x, y, 0.0);
		coos.push_back(coo);

		// -- find endvis coordinates
		legphiToSphr(qleg->x1VisLegphi1, legrmat, &phi, &theta);
		radToCoo(phi, theta, loc->phi, loc->theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
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

		// -- find coordinates of leg begin and end locations ; only append if don't coincide with bgnvis/endvis coordinates
		legphiToSphr(0.0, legrmat, &phi, &theta);
		radToCoo(phi, theta, loc->phi, loc->theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);

		coo = new Coo(Cootype::BGNLEG, x, y, 0.0);
		if (dx != 0.0) {
			coo->lam = (coo->x - x0) / dx;
		} else if (dy != 0.0) {
			coo->lam = (coo->y - y0) / dy;
		};
		lammin = coo->lam;
		if ( ((fabs(coo->x - coos[0]->x) + fabs(coo->y - coos[0]->y)) > 0.1) && ((fabs(coo->x - coos[1]->x) + fabs(coo->y - coos[1]->y)) > 0.1) ) {
			coos.push_back(coo);
		} else {
			delete coo;
		};

		legphiToSphr(leg->deltaphi, legrmat, &phi, &theta);
		radToCoo(phi, theta, loc->phi, loc->theta, pixphi, pixtheta, height, width, xoffset, yoffset, &x, &y);
		coo = new Coo(Cootype::ENDLEG, x, y, 0.0);
		if (dx != 0.0) {
			coo->lam = (coo->x - x0) / dx;
		} else if (dy != 0.0) {
			coo->lam = (coo->y - y0) / dy;
		};
		lammax = coo->lam;
		if ( ((fabs(coo->x - coos[0]->x) + fabs(coo->y - coos[0]->y)) > 0.1) && ((fabs(coo->x - coos[1]->x) + fabs(coo->y - coos[1]->y)) > 0.1) ) {
			coos.push_back(coo);
		} else {
			delete coo;
		};

		if (lammin > lammax) {
			lam = lammax;
			lammin = lammax;
			lammax = lam;
		};

		// -- find coordinates of intersections of leg with map boundaries ; only append if part of leg
		if (dx != 0.0) {
			// determine west and east intersections
			coo = new Coo(Cootype::WXSEC, 0.0, 0.0, 0.0);
			coo->lam = (coo->x - x0) / dx;
			coo->y = y0 + coo->lam*dy;
			if ((coo->lam > lammin) && (coo->lam < lammax)) coos.push_back(coo); else delete coo;

			coo = new Coo(Cootype::EXSEC, width, 0.0, 0.0);
			coo->lam = (coo->x - x0) / dx;
			coo->y = y0 + coo->lam*dy;
			if ((coo->lam > lammin) && (coo->lam < lammax)) coos.push_back(coo); else delete coo;
		};

		if (dy != 0.0) {
			// determine north and south intersections
			coo = new Coo(Cootype::NXSEC, 0.0, 0.0, 0.0);
			coo->lam = (coo->y - y0) / dy;
			coo->x = x0 + coo->lam*dx;
			if ((coo->lam > lammin) && (coo->lam < lammax)) coos.push_back(coo); else delete coo;

			coo = new Coo(Cootype::SXSEC, 0.0, height, 0.0);
			coo->lam = (coo->y - y0) / dy;
			coo->x = x0 + coo->lam*dx;
			if ((coo->lam > lammin) && (coo->lam < lammax)) coos.push_back(coo); else delete coo;
		};

		// -- validate remaining coordinates (crop)
		for (unsigned int i=0;i<coos.size();i++) {
			coo = coos[i];

			if ((coo->x < -0.1) || (coo->x > (width+0.1)) || (coo->y < -0.1) || (coo->y > (height+0.1))) {
				delete coo;
				coos[i] = NULL;
			};
		};

		// -- stuff remaining coordinates
		for (unsigned int i=0;i<coos.size();i++) {
			if (coos[i] == NULL) {
				for (unsigned int j=i+1;j<coos.size();j++) {
					if (coos[j] != NULL) {
						coos[i] = coos[j];
						coos[j] = NULL;
						break;
					};
				};
			};
		};
		for (n=0;n<coos.size();n++) if (coos[n] == NULL) break;
		coos.resize(n);

		// -- sort remaining coordinates
		for (unsigned int i=0;i<coos.size();i++) {
			coo = coos[i];
			lammin = coo->lam;
			ixmin = i;

			for (unsigned int j=i+1;j<coos.size();j++) {
				coo2 = coos[j];

				if (coo2->lam < lammin) {
					lammin = coo2->lam;
					ixmin = j;
				};
			};

			if (ixmin != i) {
				coos[i] = coos[ixmin];
				coos[ixmin] = coo;
			};
		};

		// -- establish final coordinate system
		if (coos.size() >= 2) {
			qleg->x0 = coos[0]->x;
			qleg->y0 = coos[0]->y;

			qleg->dx = dx;
			qleg->dy = dy;

			// transform lam of coordinates between coos[0] and coos[coos.size()-1]
			for (unsigned int i=1;i<coos.size();i++) {
				coo = coos[i];
				coo->lam = coo->lam - coos[0]->lam;
			};
			coos[0]->lam = 0.0;

			if (coos.size() == 2) {
				// possibilities: BGNVIS/ENDVIS (vis.), BGNLEG/ENDLEG (not vis.), XSEC/XSEC (vis. unknown), BGNENDVIS/XSEC (vis.), BGNENDLEG/XSEC (not vis.)
				bool isbgnendvis0, isbgnendvis1, isbgnendleg0, isbgnendleg1, isxsec0, isxsec1;

				isbgnendvis0 = ((coos[0]->type == Cootype::BGNVIS) || (coos[0]->type == Cootype::ENDVIS));
				isbgnendvis1 = ((coos[1]->type == Cootype::BGNVIS) || (coos[1]->type == Cootype::ENDVIS));

				isbgnendleg0 = ((coos[0]->type == Cootype::BGNLEG) || (coos[0]->type == Cootype::ENDLEG));
				isbgnendleg1 = ((coos[1]->type == Cootype::BGNLEG) || (coos[1]->type == Cootype::ENDLEG));

				isxsec0 = ((coos[0]->type == Cootype::WXSEC) || (coos[0]->type == Cootype::EXSEC) || (coos[0]->type == Cootype::NXSEC) || (coos[0]->type == Cootype::SXSEC));
				isxsec1 = ((coos[1]->type == Cootype::WXSEC) || (coos[1]->type == Cootype::EXSEC) || (coos[1]->type == Cootype::NXSEC) || (coos[1]->type == Cootype::SXSEC));

				if (isbgnendvis0 && isbgnendvis1) {
					qleg->lam1 = 0.0;
					qleg->lam2 = coos[1]->lam;
					qleg->lam3 = qleg->lam2;
				} else if (isbgnendleg0 && isbgnendleg1) {
					qleg->lam1 = coos[1]->lam;
					qleg->lam2 = qleg->lam1;
					qleg->lam3 = qleg->lam1;
				} else if (isxsec0 && isxsec1) {
					qleg->lam1 = coos[1]->lam;
					qleg->lam2 = qleg->lam1;
					qleg->lam3 = qleg->lam1;
				} else {
					// one of both is xsec
					if (isbgnendvis0 || isbgnendvis1) {
						qleg->lam1 = 0.0;
						qleg->lam2 = coos[1]->lam;
						qleg->lam3 = qleg->lam2;
					} else {
						qleg->lam1 = coos[1]->lam;
						qleg->lam2 = qleg->lam1;
						qleg->lam3 = qleg->lam1;
					};
				};

			} else if (coos.size() == 3) {
				// possibilities: XSEC/BGNENDVIS/*, */BGNENDVIS/XSEC, */BGNENDVIS/*
				if (coos[1]->type == Cootype::BGNVIS) {
					qleg->lam1 = coos[1]->lam;
					qleg->lam2 = coos[2]->lam;
					qleg->lam3 = qleg->lam2;
				} else {
					qleg->lam1 = 0.0;
					qleg->lam2 = coos[1]->lam;
					qleg->lam3 = coos[2]->lam;
				};

			} else if (coos.size() == 4) {
				// we begin and end invisible
				qleg->lam1 = coos[1]->lam;
				qleg->lam2 = coos[2]->lam;
				qleg->lam3 = coos[3]->lam;
			};
		};

		qleg->qwr = ((qleg->x0 != -1.0) && (qleg->y0 != -1.0));

		// -- clean up
		delete leg;
		delete[] legrmat; legrmat = NULL;
		for (unsigned int i=0;i<coos.size();i++) if (coos[i] != NULL) delete coos[i];
		coos.resize(0);
	};

	// --- locations in proximity
	for (unsigned int i=0;i<qplocs.nodes.size();i++) {
		qploc = qplocs.nodes[i];

		radToCoo(qploc->mphi, qploc->mtheta, loc->phi, loc->theta, pixphi, pixtheta, height, width, xoffset, yoffset, &(qploc->x), &(qploc->y));

		qploc->qwr = ((qploc->x >= 0) && (qploc->x < width) && (qploc->y >= 0) && (qploc->y < height));
	};

	// --- locations within visibility
	for (unsigned int i=0;i<qvlocs.nodes.size();i++) {
		qvloc = qvlocs.nodes[i];

		radToCoo(qvloc->mphi, qvloc->mtheta, loc->phi, loc->theta, pixphi, pixtheta, height, width, xoffset, yoffset, &(qvloc->x), &(qvloc->y));

		qvloc->qwr = ((qvloc->x >= 0) && (qvloc->x < width) && (qvloc->y >= 0) && (qvloc->y < height));
	};

	// --- update query table content
	for (unsigned int i=0;i<qlegs.nodes.size();i++) qlegToDeg(qlegs.nodes[i]);
	for (unsigned int i=0;i<qplocs.nodes.size();i++) qplocToDeg(qplocs.nodes[i]);
	for (unsigned int i=0;i<qvlocs.nodes.size();i++) qvlocToDeg(qvlocs.nodes[i]);

	dbsbrly->tblbrlyqlocmapleg->updateRst(qlegs);
	dbsbrly->tblbrlyqlocmapproxlocation->updateRst(qplocs);
	dbsbrly->tblbrlyqlocmapvislocation->updateRst(qvlocs);

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

	delete loc;
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
void BrlyMapgenLocmap::radToCoo(
			const double phi
			, const double theta
			, const double locphi
			, const double loctheta
			, const double pixphi
			, const double pixtheta
			, const uint height
			, const uint width
			, const int xoffset
			, const int yoffset
			, double* x
			, double* y
		) {
	double dphi = phi - locphi;
	if (dphi < -pi) dphi += 2.0*pi;
	if (dphi > pi) dphi -= 2.0*pi;
	*x = dphi/pixphi + ((double) (width/2.0)) - ((double) xoffset);

	*y = ((double) height/2.0) - (theta - loctheta)/pixtheta + ((double) yoffset);
};

void BrlyMapgenLocmap::legphiToSphr(
			const double legphi
			, const double* legrmat
			, double* phi
			, double* theta
		) {
	double a, b, c;

	a = legrmat[0]*cos(legphi) + legrmat[3]*sin(legphi);
	b = legrmat[1]*cos(legphi) + legrmat[4]*sin(legphi);
	c = legrmat[2]*cos(legphi) + legrmat[5]*sin(legphi);

	*theta = asin(c);
	*phi = atan2(b, a);
};

void BrlyMapgenLocmap::qlegToRad(
			BrlyQLocMapLeg* qleg
		) {
	qleg->x1VisLegphi0 = degToRad(qleg->x1VisLegphi0);
	qleg->x1VisLegphi1 = degToRad(qleg->x1VisLegphi1);
};

void BrlyMapgenLocmap::qlegToDeg(
			BrlyQLocMapLeg* qleg
		) {
	qleg->x1VisLegphi0 = radToDeg(qleg->x1VisLegphi0);
	qleg->x1VisLegphi1 = radToDeg(qleg->x1VisLegphi1);
};

void BrlyMapgenLocmap::qplocToRad(
			BrlyQLocMapProxLocation* qploc
		) {
	qploc->mtheta = degToRad(qploc->mtheta);
	qploc->mphi = degToRad(qploc->mphi);
};

void BrlyMapgenLocmap::qplocToDeg(
			BrlyQLocMapProxLocation* qploc
		) {
	qploc->mtheta = radToDeg(qploc->mtheta);
	qploc->mphi = radToDeg(qploc->mphi);
};

void BrlyMapgenLocmap::qvlocToRad(
			BrlyQLocMapVisLocation* qvloc
		) {
	qvloc->mtheta = degToRad(qvloc->mtheta);
	qvloc->mphi = degToRad(qvloc->mphi);
};

void BrlyMapgenLocmap::qvlocToDeg(
			BrlyQLocMapVisLocation* qvloc
		) {
	qvloc->mtheta = radToDeg(qvloc->mtheta);
	qvloc->mphi = radToDeg(qvloc->mphi);
};
// IP cust --- IEND


