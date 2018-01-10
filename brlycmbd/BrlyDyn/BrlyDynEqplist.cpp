/**
  * \file BrlyDynEqplist.cpp
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

#include "BrlyDynEqplist.h"

DpchRetBrly* BrlyDynEqplist::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDynEqplist* dpchinv
		) {
	ubigint refBrlyMConnection = dpchinv->refBrlyMConnection;

	bool success;

	// IP run --- IBEGIN
	ostringstream sqlstr;

	vector<ubigint> refs;

	BrlyMConnection* con = NULL;

	BrlyMLeg* corr = NULL;
	double* corrrmat = NULL;

	BrlyMLocation* bgnloc = NULL;
	BrlyMLocation* endloc = NULL;

	// location equipment complex
	ListBrlyRMLegMLocation rlocs;
	BrlyRMLegMLocation* rloc = NULL;

	ListBrlyMLocation locs;
	BrlyMLocation* loc = NULL;

	ListBrlyLRMConnectionMEquipment loccrles;
	BrlyLRMConnectionMEquipment* loccrle = NULL;

	// flight equipment complex
	ListBrlyRMConnectionMFlight rflts;
	BrlyRMConnectionMFlight* rflt = NULL;
	BrlyRMConnectionMFlight* rflt2 = NULL;

	ListBrlyMFlight flts;
	BrlyMFlight* flt = NULL;
	BrlyMFlight* flt2 = NULL;

	vector<unsigned int> fltixs;
	unsigned int ix, ixmin;

	ListBrlyLRMConnectionMEquipment fltcrles;
	BrlyLRMConnectionMEquipment* fltcrle = NULL;

	vector<double> omegas;
	double omega, omega2;

	vector<double> fltcorrphi0s;
	double fltcorrphi0;

	vector<double> fltcorrphi1s;
	double fltcorrphi1;

	// routes complex
	ListBrlyMLeg rts;
	BrlyMLeg* rt = NULL;
	vector<double*> rtrmats;
	double* rtrmat = NULL;
	double* rtrmat2 = NULL;

	ListBrlyORMConnectionMEquipment ops;
	BrlyORMConnectionMEquipment* op = NULL;

	double phi, phi0, phi1, phi2, phi3;
	unsigned int num, m, n;
	uint start, stop;
	int dt;
	bool pos, pos2;

	vector<double> phis;
	bool found;

	list<ubigint> lineup;
	list<ubigint>::iterator lineupix, lineupix2;

	// load connection
	dbsbrly->tblbrlymconnection->loadRecByRef(refBrlyMConnection, &con);

	// load communication corridor
	sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMLeg WHERE ref = " << con->corRefBrlyMLeg;
	dbsbrly->tblbrlymleg->loadRecBySQL(sqlstr.str(), &corr); legToRad(corr);

	dbsbrly->tblbrlymlocation->loadRecByRef(corr->bgnRefBrlyMLocation, &bgnloc); locToRad(bgnloc);
	dbsbrly->tblbrlymlocation->loadRecByRef(corr->endRefBrlyMLocation, &endloc); locToRad(endloc);

	// find comm. corridor rotation matrix
	getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &corrrmat);

	delete bgnloc;
	delete endloc;

	// --- location equipment complex

	// load locations in corridor
	dbsbrly->tblbrlyrmlegmlocation->loadRstByLeg(corr->ref, false, rlocs);
	for (unsigned int i=0;i<rlocs.nodes.size();i++) legRelLocToRad(rlocs.nodes[i]);

	for (unsigned int i=0;i<rlocs.nodes.size();i++) {
		rloc = rlocs.nodes[i];

		dbsbrly->tblbrlymlocation->loadRecByRef(rloc->refBrlyMLocation, &loc);
		locToRad(loc);
		locs.nodes.push_back(loc);
	};

	// --- flight equipment complex
	dbsbrly->tblbrlyrmconnectionmflight->loadRstByCon(con->ref, false, rflts);
	for (unsigned int i=0;i<rflts.nodes.size();i++) conRelFltToRad(rflts.nodes[i]);

	for (unsigned int i=0;i<rflts.nodes.size();i++) {
		rflt = rflts.nodes[i];

		dbsbrly->tblbrlymflight->loadRecByRef(rflt->refBrlyMFlight, &flt);
		flts.nodes.push_back(flt);
	};

	// filled later, in two parts
	fltcrles.nodes.resize(flts.nodes.size());

	// --- routes complex

	// load each flight route once
	sqlstr.str(""); sqlstr << "SELECT DISTINCT TblBrlyMFlight.refBrlyMLeg FROM TblBrlyMFlight, TblBrlyRMConnectionMFlight WHERE TblBrlyMFlight.ref = TblBrlyRMConnectionMFlight.refBrlyMFlight"
		<< " AND TblBrlyRMConnectionMFlight.refBrlyMConnection = " << con->ref;
	dbsbrly->loadRefsBySQL(sqlstr.str(), false, refs);

	for (unsigned int i=0;i<refs.size();i++) {
		dbsbrly->tblbrlymleg->loadRecByRef(refs[i], &rt);
		legToRad(rt);
		rts.nodes.push_back(rt);
	};

	rtrmats.resize(rts.nodes.size());

	// find rotation matrix for each route
	for (unsigned int i=0;i<rts.nodes.size();i++) {
		rt = rts.nodes[i];

		dbsbrly->tblbrlymlocation->loadRecByRef(rt->bgnRefBrlyMLocation, &bgnloc);
		locToRad(bgnloc);
		dbsbrly->tblbrlymlocation->loadRecByRef(rt->endRefBrlyMLocation, &endloc);
		locToRad(endloc);

		rtrmat = NULL;
		getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &rtrmat);
		rtrmats[i] = rtrmat;

		// multiply transpose of rtrmat with corrrmat
		rtrmat = NULL;
		multAmatBmatT(corrrmat, rtrmats[i], &rtrmat, 3);
		delete[] rtrmats[i];
		rtrmats[i] = rtrmat;

		delete bgnloc;
		delete endloc;
	};

	// --- calculations begin
	omegas.resize(rflts.nodes.size());
	fltcorrphi0s.resize(rflts.nodes.size());
	fltcorrphi1s.resize(rflts.nodes.size());

	// find flight angular velocities and angular enter/exit positions
	for (unsigned int i=0;i<rflts.nodes.size();i++) {
		rflt = rflts.nodes[i];
		flt = flts.nodes[i];

		// find flight route
		for (unsigned int j=0;j<rts.nodes.size();j++) {
			rt = rts.nodes[j];

			if (rt->ref == flt->refBrlyMLeg) {
				omegas[i] = rt->deltaphi / ((double) (flt->stop - flt->start));
				fltcorrphi0s[i] = rflt->x2Legphi0;
				fltcorrphi1s[i] = rflt->x2Legphi1;

				break;
			};
		};
	};

	// index flights by enter positions fltcorrphi0
	fltixs.resize(rflts.nodes.size());
	for (unsigned int i=0;i<fltixs.size();i++) fltixs[i] = i;

	// sort
	for (unsigned int i=0;i<fltixs.size();i++) {
		ixmin = i;

		for (unsigned int j=i;j<fltixs.size();j++) {
			// find minimum in remaining vector
			if (fltcorrphi0s[fltixs[j]] < fltcorrphi0s[fltixs[ixmin]]) ixmin = j;
		};

		// swap (in fltixs!)
		if (ixmin != i) {
			ix = fltixs[i];
			fltixs[i] = fltixs[ixmin];
			fltixs[ixmin] = ix;
		};
	};

	// fill LR table, initial part ; intermix flights entering at con-start and locations
	m = 0; // rloc index
	rloc = rlocs.nodes[m];

	// fltcorrphi0s index (first flt entering at con-start)
	for (n=0;n<fltixs.size();n++) {
		rflt = rflts.nodes[fltixs[n]];

		if (rflt->x1Start == con->start) {
			fltcorrphi0 = fltcorrphi0s[fltixs[n]];
			break;
		};
	};

	num = 1;

	while ((m < locs.nodes.size()) || (n < fltixs.size())) {
		// insert whichever's phi0 is smaller ; prefer locations over flights (relevant for connections of type {reg,loc}-flt)
		if ((n == fltixs.size()) || ((rloc->legphi <= fltcorrphi0) && (m < locs.nodes.size()))) {
			// location equipment
			loccrle = new BrlyLRMConnectionMEquipment(0, VecBrlyVLat::INI, con->ref, num, locs.nodes[m]->refBrlyMEquipment);
			loccrles.nodes.push_back(loccrle);

			num++;

			m++;
			if (m < locs.nodes.size()) rloc = rlocs.nodes[m];

		} else {
			// flight equipment
			fltcrle = new BrlyLRMConnectionMEquipment(0, VecBrlyVLat::INI, con->ref, num, flts.nodes[fltixs[n]]->refBrlyMEquipment);
			fltcrles.nodes[fltixs[n]] = fltcrle;

			num++;

			// find next flt entering at con-start
			for (n+=1;n<fltixs.size();n++) {
				rflt = rflts.nodes[fltixs[n]];

				if (rflt->x1Start == con->start) {
					fltcorrphi0 = fltcorrphi0s[fltixs[n]];
					break;
				};
			};
		};
	};

	// fill LR table, insertion by operator part (not ordered, only flights entering after con-start)
	for (unsigned int i=0;i<rflts.nodes.size();i++) {
		rflt = rflts.nodes[i];

		if (rflt->x1Start != con->start) {
			fltcrle = new BrlyLRMConnectionMEquipment(0, VecBrlyVLat::DLO, con->ref, num, flts.nodes[i]->refBrlyMEquipment);
			fltcrles.nodes[i] = fltcrle;

			num++;
		};
	};

	// insert all LR's here
	dbsbrly->tblbrlylrmconnectionmequipment->insertRst(loccrles, true);
	dbsbrly->tblbrlylrmconnectionmequipment->insertRst(fltcrles, true);

	// add insert after events (neglecting pr2)
	for (unsigned int i=0;i<rflts.nodes.size();i++) {
		rflt = rflts.nodes[i];

		if (rflt->x1Start != con->start) {
			op = new BrlyORMConnectionMEquipment(0, con->ref, rflt->x1Start, VecBrlyVOolop::INA, fltcrles.nodes[i]->ref, 0);
			ops.nodes.push_back(op);
		};
	};

	// add remove events, only flights leaving before con->stop
	for (unsigned int i=0;i<rflts.nodes.size();i++) {
		rflt = rflts.nodes[i];

		if (rflt->x1Stop != con->stop) {
			op = new BrlyORMConnectionMEquipment(0, con->ref, rflt->x1Stop, VecBrlyVOolop::RMV, fltcrles.nodes[i]->ref, 0);
			ops.nodes.push_back(op);
		};
	};

	// add flt-loc swap events
	for (unsigned int i=0;i<rflts.nodes.size();i++) {
		rflt = rflts.nodes[i];
		flt = flts.nodes[i];
		omega = omegas[i];

		// find flight route
		for (unsigned int j=0;j<rts.nodes.size();j++) {
			rt = rts.nodes[j];

			if (rt->ref == flt->refBrlyMLeg) {
				rtrmat = rtrmats[j];
				break;
			};
		};

		fltcorrphi0 = fltcorrphi0s[i];
		fltcorrphi1 = fltcorrphi1s[i];

		// fltcorrphi0 > fltcorrphi1 is possible
		if (fltcorrphi0 < fltcorrphi1) {
			phi0 = fltcorrphi0;
			phi1 = fltcorrphi1;
		} else {
			phi0 = fltcorrphi1;
			phi1 = fltcorrphi0;
		};

		for (unsigned int j=0;j<rlocs.nodes.size();j++) {
			rloc = rlocs.nodes[j];

			// forbid swaps with corridor begin and end locations (leave that to INA and RMV)
			if ((rloc->refBrlyMLocation != corr->bgnRefBrlyMLocation) && (rloc->refBrlyMLocation != corr->endRefBrlyMLocation)) {
				// also forbid swaps with route begin and end locations for same reason
				if ((rloc->refBrlyMLocation != rt->bgnRefBrlyMLocation) && (rloc->refBrlyMLocation != rt->endRefBrlyMLocation)) {

					// check for phi overlap
					if ((phi0 < rloc->legphi) && (phi1 > rloc->legphi)) {
						// initializing x1Start with rflt->x1Start avoids trouble with zero-duration flights
						op = new BrlyORMConnectionMEquipment(0, con->ref, rflt->x1Start, 0, fltcrles.nodes[i]->ref, loccrles.nodes[j]->ref);
						ops.nodes.push_back(op);

						// find flight position relative to location at x1Start
						pos = (evalFltlocSwap(omega * ((double) (rflt->x1Start - flt->start)), rtrmat, rloc->legphi) > 0.0);
						if (pos) {
							op->ixBrlyVOolop = VecBrlyVOolop::TOB;
						} else {
							op->ixBrlyVOolop = VecBrlyVOolop::TOA;
						};

						// find time at which transition takes place
						for (start = rflt->x1Start ; start <= rflt->x1Stop ; start++) {
							if ((evalFltlocSwap(omega * ((double) (start - flt->start)), rtrmat, rloc->legphi) > 0.0) != pos) {
								op->x1Start = start;
								break;
							};
						};

						// (last time checked, none seen) if (start > rflt->x1Stop) cout << "flight-location swap error" << endl;

					};
				};
			};
		};
	};

	// add flt-flt swap events
	for (unsigned int i=0;i<rflts.nodes.size();i++) {
		rflt = rflts.nodes[i];
		flt = flts.nodes[i];
		omega = omegas[i];

		// find flight route
		for (unsigned int j=0;j<rts.nodes.size();j++) {
			rt = rts.nodes[j];

			if (rt->ref == flt->refBrlyMLeg) {
				rtrmat = rtrmats[j];
				break;
			};
		};

		// note that we don't start at j=0
		for (unsigned int j=i;j<rflts.nodes.size();j++) {
			rflt2 = rflts.nodes[j];

			// check for time overlap (eliminates i=j, too)
			if ((rflt->x1Start < rflt2->x1Stop) && (rflt->x1Stop > rflt2->x1Start)) {
				if (rflt->x1Start < rflt2->x1Start)
					start = rflt2->x1Start;
				else
					start = rflt->x1Start;
				
				if (rflt->x1Stop < rflt2->x1Stop)
					stop = rflt->x1Stop;
				else
					stop = rflt2->x1Stop;

				flt2 = flts.nodes[j];
				omega2 = omegas[j];

				// find flight route
				for (unsigned int k=0;k<rts.nodes.size();k++) {
					rt = rts.nodes[k];

					if (rt->ref == flt2->refBrlyMLeg) {
						rtrmat2 = rtrmats[k];
						break;
					};
				};

				// calculate phi's only here ; using start and stop (fltcorrphi0s/1s do not help)
				
				// phi0 and phi1 belong to rflt's route
				phi0 = evalCorrphi(omega * ((double) (start - flt->start)), rtrmat);
				phi1 = evalCorrphi(omega * ((double) (stop - flt->start)), rtrmat);
				if (phi0 > phi1) {
					phi = phi0;
					phi0 = phi1;
					phi1 = phi;
				};

				// phi2 and phi3 belong to rflt2's route
				phi2 = evalCorrphi(omega2 * ((double) (start - flt2->start)), rtrmat2);
				phi3 = evalCorrphi(omega2 * ((double) (stop - flt2->start)), rtrmat2);
				if (phi2 > phi3) {
					phi = phi2;
					phi2 = phi3;
					phi3 = phi;
				};

				// check for phi overlap
				if ((phi0 < phi3) && (phi1 > phi2)) {

					// swap condition / order changes
					if ( ((phi0 > phi2) && (phi1 < phi3)) || ((phi0 < phi2) && (phi1 > phi3)) ) {
						op = new BrlyORMConnectionMEquipment(0, con->ref, start, 0, fltcrles.nodes[i]->ref, fltcrles.nodes[j]->ref);
						ops.nodes.push_back(op);

						// find flight1 position relative to flight2 at start
						pos = (evalFltfltSwap(omega * ((double) (start - flt->start)), rtrmat, omega2 * ((double) (start - flt2->start)), rtrmat2) > 0.0);
						if (pos) {
							op->ixBrlyVOolop = VecBrlyVOolop::TOB;
						} else {
							op->ixBrlyVOolop = VecBrlyVOolop::TOA;
						};

						// find time at which transition takes place
						dt = 1;
						while (dt < ((int) (stop-start))) dt *= 2;
						dt /= 2;

						while (dt != 0) {
							start = start + dt;

							// halve dt and make positive
							dt /= 2;
							if (dt < 0) dt = -dt;

							if (start > stop) {
								// out of range
								dt = -dt;
							} else {
								pos2 = (evalFltfltSwap(omega * ((double) (start - flt->start)), rtrmat, omega2 * ((double) (start - flt2->start)), rtrmat2) > 0.0);
								if (pos2 != pos) dt = -dt;
							};
						};

						op->x1Start = start;
						if (pos2 == pos) op->x1Start++;

/*
						for ( ; start<=stop ; start++) {
							if ((evalFltfltSwap(omega * ((double) (start - flt->start)), rtrmat, omega2 * ((double) (start - flt2->start)), rtrmat2) > 0.0) != pos) {
								op->x1Start = start;
								break;
							};
						};
*/
					};
				};
			};
		};
	};

	// insert all ops here
	dbsbrly->tblbrlyormconnectionmequipment->insertRst(ops, true);

	// --- find&update pr2's of flights to be inserted after con-start
	// initial list content
	dbsbrly->tblbrlylrmconnectionmequipment->loadRefsByConLat(con->ref, VecBrlyVLat::INI, false, refs);
	for (unsigned int i=0;i<refs.size();i++) lineup.push_back(refs[i]);

	// operators ; note that there are some situations in which a SWP with a flight takes place at insertion (INA) time
	dbsbrly->tblbrlyormconnectionmequipment->loadRstByCon(con->ref, false, ops);

	// apply operators sequentially
	for (unsigned int opix=0;opix<ops.nodes.size();opix++) {
		op = ops.nodes[opix];

		if (op->ixBrlyVOolop == VecBrlyVOolop::INA) {
			if (op->pr2RefLR == 0) {
				// -- re-calculate phi line-up
				phis.resize(0);

				for (lineupix=lineup.begin() ; lineupix!=lineup.end() ; lineupix++) {
					found = false;

					// look for static equipment
					for (unsigned int i=0;i<loccrles.nodes.size();i++) {
						if (loccrles.nodes[i]->ref == *(lineupix)) {
							phis.push_back(rlocs.nodes[i]->legphi);
							found = true;
							break;
						};
					};

					if (!found) {
						// look for flights
						for (unsigned int i=0;i<fltcrles.nodes.size();i++) {
							if (fltcrles.nodes[i]->ref == *(lineupix)) {
								omega = omegas[i];
								flt = flts.nodes[i];
								
								// find flight route
								for (unsigned int j=0;j<rts.nodes.size();j++) {
									rt = rts.nodes[j];

									if (rt->ref == flt->refBrlyMLeg) {
										rtrmat = rtrmats[j];
										break;
									};
								};

								phi = evalCorrphi(omega * ((double) (op->x1Start - flt->start)), rtrmat);
								phis.push_back(phi);
								found = true;
								break;
							};
						};
					};
				};

//if (phis.size() != lineup.size()) cout << con->ref << ", phis.size() = " << phis.size() << ", lineup.size() = " << lineup.size() << endl;
// --- list phis to see if they are still in order
//cout << "opix = " << opix << endl;
//for (unsigned int r=0;r<phis.size();r++) cout << "\tphi[" << r << "] = " << phis[r] << endl;
// ---

				// -- calculate phi of flight to be inserted
				for (unsigned int i=0;i<fltcrles.nodes.size();i++) {
					if (fltcrles.nodes[i]->ref == op->pr1RefLR) {
						omega = omegas[i];
						flt = flts.nodes[i];
						
						// find flight route
						for (unsigned int j=0;j<rts.nodes.size();j++) {
							rt = rts.nodes[j];

							if (rt->ref == flt->refBrlyMLeg) {
								rtrmat = rtrmats[j];
								fltcorrphi0 = fltcorrphi0s[j];
								fltcorrphi1 = fltcorrphi1s[j];
								break;
							};
						};

						phi = evalCorrphi(omega * ((double) (op->x1Start - flt->start)), rtrmat);

						// check for insertion at special phi's
						if (fabs(phi) < 5.0e-5) {
							// insert at corridor begin location
							phi = 5.0e-5;

						} else if (fabs(phi - evalCorrphi(0.0, rtrmat)) < 5.0e-5) {
							// insert at route begin location ; offset sign depends on heading of route wrt corridor
							if (fltcorrphi0 <= fltcorrphi1) phi += 5.0e-5; else phi -= 5.0e-5;
						};

						break;
					};
				};

				// adjust pr2RefLR and update in database
				if (lineup.size() > 0) {
					n = 0;
					for (lineupix=lineup.begin() ; lineupix!=lineup.end() ; lineupix++) {
						if (phis[n] < phi) {
							op->pr2RefLR = (*lineupix);
						} else {
							break;
						};
						n++;
					};

					if (op->pr2RefLR != 0) dbsbrly->tblbrlyormconnectionmequipment->updateRec(op);
				};
			};

			// insert in list
			for (lineupix=lineup.begin() ; lineupix!=lineup.end() ; lineupix++) if ((*lineupix) == op->pr2RefLR) break;

			if (lineupix==lineup.end()) {
				lineup.insert(lineup.begin(), op->pr1RefLR);
			} else {
				lineupix++;
				lineup.insert(lineupix, op->pr1RefLR);
			};

		} else if (op->ixBrlyVOolop == VecBrlyVOolop::TOB) {
			for (lineupix=lineup.begin() ; lineupix!=lineup.end() ; lineupix++) if ((*lineupix) == op->pr1RefLR) break;
			for (lineupix2=lineup.begin() ; lineupix2!=lineup.end() ; lineupix2++) if ((*lineupix2) == op->pr2RefLR) break;

			if ((lineupix!=lineup.end()) && (lineupix2!=lineup.end())) {
				lineup.insert(lineupix2, (*lineupix));
				lineup.erase(lineupix);

			} else {
				//cout << "swap error!" << endl;
			};

		} else if (op->ixBrlyVOolop == VecBrlyVOolop::TOA) {
			for (lineupix=lineup.begin() ; lineupix!=lineup.end() ; lineupix++) if ((*lineupix) == op->pr1RefLR) break;
			for (lineupix2=lineup.begin() ; lineupix2!=lineup.end() ; lineupix2++) if ((*lineupix2) == op->pr2RefLR) break;

			if ((lineupix!=lineup.end()) && (lineupix2!=lineup.end())) {
				lineup.insert(++lineupix2, (*lineupix));
				lineup.erase(lineupix);

			} else {
				//cout << "swap error!" << endl;
			};

// --- list phis to see if they are still in order
/*
if (opix < 30) {
	cout << "opix = " << opix << endl;
				// -- re-calculate phi line-up
				phis.resize(0);

				for (lineupix=lineup.begin() ; lineupix!=lineup.end() ; lineupix++) {
					found = false;

					// look for static equipment
					for (unsigned int i=0;i<loccrles.nodes.size();i++) {
						if (loccrles.nodes[i]->ref == *(lineupix)) {
							phis.push_back(rlocs.nodes[i]->legphi);
							found = true;
							break;
						};
					};

					if (!found) {
						// look for flights
						for (unsigned int i=0;i<fltcrles.nodes.size();i++) {
							if (fltcrles.nodes[i]->ref == *(lineupix)) {
								omega = omegas[i];
								flt = flts.nodes[i];
								
								// find flight route
								for (unsigned int j=0;j<rts.nodes.size();j++) {
									rt = rts.nodes[j];

									if (rt->ref == flt->refBrlyMLeg) {
										rtrmat = rtrmats[j];
										break;
									};
								};

								phi = evalCorrphi(omega * ((double) (op->x1Start - flt->start)), rtrmat);
								cout << "\tphi[" << phis.size() << "] = " << phi << " ; omega = " << omega << ", deltaT = " << (op->x1Start - flt->start) << endl;
								phis.push_back(phi);
								found = true;
								break;
							};
						};
					};
				};
};
*/
// ---
		} else if (op->ixBrlyVOolop == VecBrlyVOolop::RMV) {
			lineup.remove(op->pr1RefLR);
		};
	};
	// --- find&update pr2's of flights to be inserted after con-start --- end

	delete con;
	delete corr;
	delete[] corrrmat;

	for (unsigned int i=0;i<rtrmats.size();i++) delete[] rtrmats[i];
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
inline double BrlyDynEqplist::evalCorrphi(
			const double phi
			, const double* rtrmat
		) {
	return(atan2(rtrmat[3]*cos(phi) + rtrmat[4]*sin(phi), rtrmat[0]*cos(phi) + rtrmat[1]*sin(phi)));
};

inline double BrlyDynEqplist::evalFltlocSwap(
			const double phi1
			, const double* rtrmat1
			, const double phi2
		) {
	return(evalCorrphi(phi1, rtrmat1) - phi2);
};

inline double BrlyDynEqplist::evalFltfltSwap(
			const double phi1
			, const double* rtrmat1
			, const double phi2
			, const double* rtrmat2
		) {
	return(evalCorrphi(phi1, rtrmat1) - evalCorrphi(phi2, rtrmat2));
};
// IP cust --- IEND


