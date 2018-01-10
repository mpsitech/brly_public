/**
  * \file BrlyMapgenLegmap.cpp
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

#include "BrlyMapgenLegmap.h"

DpchRetBrly* BrlyMapgenLegmap::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyMapgenLegmap* dpchinv
		) {
	ubigint refBrlyMLeg = dpchinv->refBrlyMLeg;
	ubigint jrefLeg = dpchinv->jrefLeg;
	ubigint jrefLoc = dpchinv->jrefLoc;
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

	BrlyMLeg* leg = NULL;
	double* legrmat = NULL;

	ListBrlyQLegMapLeg qlegs;
	BrlyQLegMapLeg* qleg = NULL;

	ListBrlyMLocation bgnlocs;
	BrlyMLocation* bgnloc = NULL;
	ListBrlyMLocation endlocs;
	BrlyMLocation* endloc = NULL;

	ListBrlyQLegMapLocation qlocs;
	BrlyQLegMapLocation* qloc = NULL;

	double* qlegrmat = NULL;

	vector<Coo*> coos;
	Coo* coo = NULL;
	Coo* coo2 = NULL;

	double deltaphi, minphi, maxphi, pixphi;
	double deltatheta, mintheta, maxtheta, pixtheta;

	double legphi, phi;
	long phiix;

	double legtheta, theta;
	long thetaix;

	double* mat = NULL;

	double x, y;

	unsigned int ix;

	double x0, y0, d, dx, dy, lammin;
	unsigned int n, ixmin;

	xmlTextWriter* wr = NULL;

	// load leg
	dbsbrly->tblbrlymleg->loadRecByRef(refBrlyMLeg, &leg);
	legToRad(leg);

	// load leg begin and end locations
	dbsbrly->tblbrlymlocation->loadRecByRef(leg->bgnRefBrlyMLocation, &bgnloc); locToRad(bgnloc);
	dbsbrly->tblbrlymlocation->loadRecByRef(leg->endRefBrlyMLocation, &endloc); locToRad(endloc);

	// determine leg rotation matrix (leg coordinates to earth coordinates)
	getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &legrmat);

	delete bgnloc;
	delete endloc;

	// load legs within visibility
	dbsbrly->tblbrlyqlegmapleg->loadRstByJref(jrefLeg, false, qlegs);
	for (unsigned int i=0;i<qlegs.nodes.size();i++) qlegToRad(qlegs.nodes[i]);

	// load locations within visibility
	dbsbrly->tblbrlyqlegmaplocation->loadRstByJref(jrefLoc, false, qlocs);
	for (unsigned int i=0;i<qlocs.nodes.size();i++) qlocToRad(qlocs.nodes[i]);

	// width of entire pane in radian
	deltaphi = leg->deltaphi;
	minphi = 0.0;
	maxphi = deltaphi;

	// width of a pixel (such that 1km equals 1pix at scale 1)
	pixphi = 1.0e3 / ((double) (xchg->stgbrlygeometry.earthradius * scale));

	// height of entire pane in radian
	deltatheta = 2.0*leg->alpha;
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

/// dump basics
//cout << "pixphi = " << pixphi << endl;
//cout << "pixtheta = " << pixtheta << endl;
//cout << "xoffset = " << xoffset << endl;
//cout << "yoffset = " << yoffset << endl;
//cout << "width = " << width << endl;
//cout << "height = " << height << endl;
///

	// --- legs within visibility
	for (unsigned int i=0;i<qlegs.nodes.size();i++) {
		qleg = qlegs.nodes[i];

		// load leg begin and end locations
		dbsbrly->tblbrlymlocation->loadRecByRef(qleg->mbgnRefBrlyMLocation, &bgnloc); locToRad(bgnloc);
		bgnlocs.nodes.push_back(bgnloc);

		dbsbrly->tblbrlymlocation->loadRecByRef(qleg->mendRefBrlyMLocation, &endloc); locToRad(endloc);
		endlocs.nodes.push_back(endloc);

		// - determine leg rotation matrix (qleg coordinates to leg coordinates)
		mat = NULL;
		getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &mat);

		// multiply transpose of qlegrmat with legrmat
		qlegrmat = NULL;
		multAmatBmatT(legrmat, mat, &qlegrmat, 3);
		delete[] mat;

		// -- initialize preliminary line offset as bgnvis coordinates
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

			// transform lam of coordinates between coos[0] and coos[coos.size()-1]
			for (unsigned int i=1;i<coos.size();i++) {
				coo = coos[i];
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

		// -- clean up
		delete[] qlegrmat; qlegrmat = NULL;
		for (unsigned int i=0;i<coos.size();i++) if (coos[i] != NULL) delete coos[i];
		coos.resize(0);
	};

	// --- locations within visibility
	for (unsigned int i=0;i<qlocs.nodes.size();i++) {
		qloc = qlocs.nodes[i];

		radToCoo(qloc->legphi, qloc->legtheta, pixphi, pixtheta, height, width, xoffset, yoffset, &(qloc->x), &(qloc->y));

		qloc->qwr = ((qloc->x >= 0) && (qloc->x < width) && (qloc->y >= 0) && (qloc->y < height));
	};

	// --- update query table content
	for (unsigned int i=0;i<qlegs.nodes.size();i++) qlegToDeg(qlegs.nodes[i]);
	for (unsigned int i=0;i<qlocs.nodes.size();i++) qlocToDeg(qlocs.nodes[i]);

	for (unsigned int i=0;i<qlegs.nodes.size();i++) dbsbrly->tblbrlyqlegmapleg->updateRec(qlegs.nodes[i]);
	for (unsigned int i=0;i<qlocs.nodes.size();i++) dbsbrly->tblbrlyqlegmaplocation->updateRec(qlocs.nodes[i]);

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
	delete[] legrmat;
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
void BrlyMapgenLegmap::radToCoo(
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

void BrlyMapgenLegmap::legToSphr(
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

void BrlyMapgenLegmap::qlegphiToLeg(
			const double qlegphi
			, const double* qlegrmat
			, double* legphi
			, double* legtheta
		) {

	*legphi = atan2(qlegrmat[3]*cos(qlegphi) + qlegrmat[4]*sin(qlegphi), qlegrmat[0]*cos(qlegphi) + qlegrmat[1]*sin(qlegphi));
	*legtheta = asin(qlegrmat[6]*cos(qlegphi) + qlegrmat[7]*sin(qlegphi));
};

void BrlyMapgenLegmap::qlegToRad(
			BrlyQLegMapLeg* qleg
		) {
	qleg->VisOrgLegphi0 = degToRad(qleg->VisOrgLegphi0);
	qleg->VisOrgLegphi1 = degToRad(qleg->VisOrgLegphi1);
};

void BrlyMapgenLegmap::qlegToDeg(
			BrlyQLegMapLeg* qleg
		) {
	qleg->VisOrgLegphi0 = radToDeg(qleg->VisOrgLegphi0);
	qleg->VisOrgLegphi1 = radToDeg(qleg->VisOrgLegphi1);
};

void BrlyMapgenLegmap::qlocToRad(
			BrlyQLegMapLocation* qloc
		) {
	qloc->legphi = degToRad(qloc->legphi);
	qloc->legtheta = degToRad(qloc->legtheta);
};

void BrlyMapgenLegmap::qlocToDeg(
			BrlyQLegMapLocation* qloc
		) {
	qloc->legphi = radToDeg(qloc->legphi);
	qloc->legtheta = radToDeg(qloc->legtheta);
};
// IP cust --- IEND


