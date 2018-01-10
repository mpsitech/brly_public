/**
  * \file BrlyDynConflt.cpp
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

#include "BrlyDynConflt.h"

DpchRetBrly* BrlyDynConflt::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDynConflt* dpchinv
		) {
	ubigint refBrlyMConnection = dpchinv->refBrlyMConnection;

	bool success;

	// IP run --- IBEGIN
	ostringstream sqlstr;

	BrlyMConnection* con = NULL;

	BrlyRMConnectionMFlight crfprep;

	BrlyMLeg* corr = NULL;

	ListBrlyRMLegMLeg rlegs;
	BrlyRMLegMLeg* rleg = NULL;

	ListBrlyMFlight flts;
	BrlyMFlight* flt = NULL;

	BrlyMEquipment* eqp = NULL;

	vector<bool> filtFlts;
	unsigned int cnt;

	BrlyMLeg* leg = NULL;

	uint start;

	double VisOrgLegphi;

	ListBrlyRMConnectionMFlight crfs;

	double a, b, c, d, e, f;

	double* corrrmat = NULL;
	double* legrmat = NULL;

	BrlyMLocation* bgnloc = NULL;
	BrlyMLocation* endloc = NULL;

	// load connection
	dbsbrly->tblbrlymconnection->loadRecByRef(refBrlyMConnection, &con);

	crfprep.refBrlyMConnection = con->ref;

	// load communication corridor
	sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMLeg WHERE ref = " << con->corRefBrlyMLeg;
	dbsbrly->tblbrlymleg->loadRecBySQL(sqlstr.str(), &corr); legToRad(corr);

	dbsbrly->tblbrlymlocation->loadRecByRef(corr->bgnRefBrlyMLocation, &bgnloc); locToRad(bgnloc);
	dbsbrly->tblbrlymlocation->loadRecByRef(corr->endRefBrlyMLocation, &endloc); locToRad(endloc);

	// find comm. corridor rotation matrix
	getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &corrrmat);

	delete bgnloc;
	delete endloc;

	// load leg-rel-leg (crossing legs)
	dbsbrly->tblbrlyrmlegmleg->loadRstByDlg(corr->ref, false, rlegs);
	for (unsigned int i=0;i<rlegs.nodes.size();i++) legRelLegToRad(rlegs.nodes[i]);

	// load flights on crossing legs within the connection period
	for (unsigned int i=0;i<rlegs.nodes.size();i++) {
		rleg = rlegs.nodes[i];

		sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMFlight WHERE refBrlyMLeg = " << rleg->orgRefBrlyMLeg << " AND start < " << con->stop << " AND stop > " << con->start;
		dbsbrly->tblbrlymflight->loadRstBySQL(sqlstr.str(), false, flts);

		// initialize as valid
		filtFlts.resize(0);
		filtFlts.resize(flts.nodes.size(), true);

		// filter by timetable
		if (con->refBrlyMTimetable != 0) {
			for (unsigned int j=0;j<flts.nodes.size();j++) {
				flt = flts.nodes[j];

				if (flt->refBrlyMTimetable != con->refBrlyMTimetable) filtFlts[j] = false;
			};
		};

		// filter by equipment type
		if (con->srefsBrlyKEqptype.length() > 0) {
			for (unsigned int j=0;j<flts.nodes.size();j++) {
				flt = flts.nodes[j];

				if (filtFlts[j]) {
					if (dbsbrly->tblbrlymequipment->loadRecByHktHku(VecBrlyVMEquipmentHkTbl::FLT, flt->ref, &eqp)) {
						filtFlts[j] = StrMod::srefInSrefs(con->srefsBrlyKEqptype, eqp->srefBrlyKEqptype);
						delete eqp;
					};
				};
			};
		};

		cnt = 0;
		for (unsigned int j=0;j<filtFlts.size();j++) if (filtFlts[j]) cnt++;

		// for each flight, create entry in TblBrlyRMConnectionMFlight
		if (cnt > 0) {
			// load flight's leg and its begin/end locations
			dbsbrly->tblbrlymleg->loadRecByRef(rleg->orgRefBrlyMLeg, &leg);
			legToRad(leg);
	
			dbsbrly->tblbrlymlocation->loadRecByRef(leg->bgnRefBrlyMLocation, &bgnloc);
			locToRad(bgnloc);
			dbsbrly->tblbrlymlocation->loadRecByRef(leg->endRefBrlyMLocation, &endloc);
			locToRad(endloc);

			// find leg rotation matrix
			getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &legrmat);

			delete bgnloc;
			delete endloc;

			// NOTE: in rleg, VisOrgLegphi0, VisOrgLegphi1 are the coordinates on the flight's leg

			for (unsigned int j=0;j<flts.nodes.size();j++) {
				if (filtFlts[j]) {
					flt = flts.nodes[j];
					crfprep.refBrlyMFlight = flt->ref;

					// rleg is ordered, x1VisDstLegphi0 < x1VisDstLegphi1
					crfprep.x2Legphi0 = rleg->x1VisDstLegphi0;
					crfprep.x2Legphi1 = rleg->x1VisDstLegphi1;

					// calculate start and stop times for visibility
					crfprep.x1Start = flt->start + lround( ((double) (flt->stop - flt->start)) * (rleg->VisOrgLegphi0/leg->deltaphi) );
					crfprep.x1Stop = flt->start + lround( ((double) (flt->stop - flt->start)) * (rleg->VisOrgLegphi1/leg->deltaphi) );

					// x1Start needs to be before x1Stop ; x2Legphi0, x2Legphi1 should correspond to x1Start/x1Stop
					if (crfprep.x1Start > crfprep.x1Stop) {
						start = crfprep.x1Start;
						crfprep.x1Start = crfprep.x1Stop;
						crfprep.x1Stop = start;

						VisOrgLegphi = crfprep.x2Legphi0;
						crfprep.x2Legphi0 = crfprep.x2Legphi1;
						crfprep.x2Legphi1 = VisOrgLegphi;
					};

					// check for overlap with connection period
					if ((crfprep.x1Start < con->stop) && (crfprep.x1Stop > con->start)) {

						// corrections so that start and stop fall in the connection period
						if (crfprep.x1Start < con->start) {
							crfprep.x1Start = con->start;

							// correct VisOrgLegphiStart
							VisOrgLegphi = leg->deltaphi * (((double) (con->start - flt->start)) / ((double) (flt->stop - flt->start)));

							// correct crfprep.x2Legphi0/1
							// rotate VisOrgLegphi out of flight leg coordinates into actual cartesian coordinates
							a = legrmat[0]*cos(VisOrgLegphi) + legrmat[3]*sin(VisOrgLegphi) + legrmat[6]*0.0;
							b = legrmat[1]*cos(VisOrgLegphi) + legrmat[4]*sin(VisOrgLegphi) + legrmat[7]*0.0;
							c = legrmat[2]*cos(VisOrgLegphi) + legrmat[5]*sin(VisOrgLegphi) + legrmat[8]*0.0;
							// rotate VisOrgLegphi into corridor coordinates
							d = corrrmat[0]*a + corrrmat[1]*b + corrrmat[2]*c;
							e = corrrmat[3]*a + corrrmat[4]*b + corrrmat[5]*c;
							f = corrrmat[6]*a + corrrmat[7]*b + corrrmat[8]*c;

							// obtain phi in corridor coordinates
							crfprep.x2Legphi0 = atan2(e, d);
						};

						if (crfprep.x1Stop > con->stop) {
							crfprep.x1Stop = con->stop;

							// correct VisOrgLegphiStop
							VisOrgLegphi = leg->deltaphi * (((double) (con->stop - flt->start)) / ((double) (flt->stop - flt->start)));

							// correct crfprep.x2Legphi0/1
							// rotate VisOrgLegphi out of flight leg coordinates into actual cartesian coordinates
							a = legrmat[0]*cos(VisOrgLegphi) + legrmat[3]*sin(VisOrgLegphi) + legrmat[6]*0.0;
							b = legrmat[1]*cos(VisOrgLegphi) + legrmat[4]*sin(VisOrgLegphi) + legrmat[7]*0.0;
							c = legrmat[2]*cos(VisOrgLegphi) + legrmat[5]*sin(VisOrgLegphi) + legrmat[8]*0.0;
							// rotate VisOrgLegphi into corridor coordinates
							d = corrrmat[0]*a + corrrmat[1]*b + corrrmat[2]*c;
							e = corrrmat[3]*a + corrrmat[4]*b + corrrmat[5]*c;
							f = corrrmat[6]*a + corrrmat[7]*b + corrrmat[8]*c;

							// obtain phi in corridor coordinates
							crfprep.x2Legphi1 = atan2(e, d);
						};

						crfs.nodes.push_back(new BrlyRMConnectionMFlight(crfprep));
					};
				};
			};

			delete leg;
		};
	};

	delete con;
	delete corr;

	// insert all crf's at a time
	for (unsigned int i=0;i<crfs.nodes.size();i++) conRelFltToDeg(crfs.nodes[i]);
	dbsbrly->tblbrlyrmconnectionmflight->insertRst(crfs, true);
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- INSERT


