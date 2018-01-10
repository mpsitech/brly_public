/**
  * \file BrlyBaseLegleg.cpp
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

#include "BrlyBaseLegleg.h"

DpchRetBrly* BrlyBaseLegleg::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyBaseLegleg* dpchinv
		) {
	uint numFirst = dpchinv->numFirst;
	uint numLast = dpchinv->numLast;
	vector<ubigint> refsBrlyMLeg = dpchinv->refsBrlyMLeg;
	bool append = dpchinv->append;
	bool intermix = dpchinv->intermix;

	bool success;

	// IP run --- IBEGIN
	ostringstream sqlstr;

	vector<bool> selDstlegs;
	ListBrlyMLeg dstlegs;
	BrlyMLeg* dstleg = NULL;

	ListBrlyMLeg orglegs;

	ListBrlyMLeg newlegs;
	BrlyMLeg* newleg;

	// analyze legs
	for (unsigned int i=0;i<refsBrlyMLeg.size();i++) {
		if (dbsbrly->tblbrlymleg->loadRecByRef(refsBrlyMLeg[i], &newleg)) {
			legToRad(newleg);
			newlegs.nodes.push_back(newleg);
		};
	};

	if (append) {
		// --- standard
		
		// orglegs (routes only)
		dbsbrly->tblbrlymleg->loadRstByTyp(VecBrlyVMLegBasetype::RTE, false, orglegs);
		for (unsigned int i=0;i<orglegs.nodes.size();i++) legToRad(orglegs.nodes[i]);

		// dstlegs
		if (refsBrlyMLeg.size() == 0) {
			if ((numFirst == 0) && (numLast == 0)) {
				// all legs
				dbsbrly->tblbrlymleg->loadRst(false, dstlegs);
				for (unsigned int i=0;i<dstlegs.nodes.size();i++) legToRad(dstlegs.nodes[i]);

			} else {
				// block of legs
				sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMLeg WHERE Calcdone = 0 ORDER BY ref ASC LIMIT " << numFirst << ", " << (numLast-numFirst+1);
				dbsbrly->tblbrlymleg->loadRstBySQL(sqlstr.str(), false, dstlegs);
				for (unsigned int i=0;i<dstlegs.nodes.size();i++) legToRad(dstlegs.nodes[i]);
			};

		} else {
			// new legs
			for (unsigned int i=0;i<newlegs.nodes.size();i++) {
				newleg = newlegs.nodes[i];

				dstlegs.nodes.push_back(new BrlyMLeg(*newleg));
			};
		};

		// all entries are selected
		selDstlegs.resize(dstlegs.nodes.size(), true);
		
	} else if (intermix) {
		// --- intermix
		if (refsBrlyMLeg.size() == 0) {

			// orglegs (routes only)
			sqlstr.str("");
			if ((numFirst == 0) && (numLast == 0)) {
				// all legs with Calcdone = 0
				sqlstr << "SELECT * FROM TblBrlyMLeg WHERE ixVBasetype = " << VecBrlyVMLegBasetype::RTE << " AND Calcdone = 0";
			} else {
				// block of legs (with Calcdone = 0)
				sqlstr << "SELECT * FROM TblBrlyMLeg WHERE Calcdone = 0 ORDER BY ref ASC LIMIT " << numFirst << ", " << (numLast-numFirst+1);
			};
			dbsbrly->tblbrlymleg->loadRstBySQL(sqlstr.str(), false, orglegs);
		
			// dstlegs: all Calcdone legs
			sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMLeg WHERE Calcdone = 1";
			dbsbrly->tblbrlymleg->loadRstBySQL(sqlstr.str(), false, dstlegs);

			// all entries are selected
			selDstlegs.resize(dstlegs.nodes.size(), true);

		} else {
			// orglegs: new legs (routes only)
			for (unsigned int i=0;i<newlegs.nodes.size();i++) {
				newleg = newlegs.nodes[i];

				if (newleg->ixVBasetype == VecBrlyVMLegBasetype::RTE) orglegs.nodes.push_back(new BrlyMLeg(*newleg));
			};

			// dstlegs: all legs except for the new ones
			dbsbrly->tblbrlymleg->loadRst(false, dstlegs);
			for (unsigned int i=0;i<dstlegs.nodes.size();i++) legToRad(dstlegs.nodes[i]);

			// at first, all entries are selected
			selDstlegs.resize(dstlegs.nodes.size(), true);

			// de-select new legs
			for (unsigned int i=0;i<newlegs.nodes.size();i++) {
				newleg = newlegs.nodes[i];

				for (unsigned int j=0;j<dstlegs.nodes.size();j++) {
					dstleg = dstlegs.nodes[j];

					if (newleg->ref == dstleg->ref) {
						selDstlegs[j] = false;
						break;
					};
				};
			};
		};
	};

	calcVis(dbsbrly, dstlegs, selDstlegs, orglegs);
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
void BrlyBaseLegleg::calcVis(
			DbsBrly* dbsbrly
			, const ListBrlyMLeg& dstlegs
			, const vector<bool>& selDstlegs
			, const ListBrlyMLeg& orglegs
		) {
	ostringstream sqlstr;

	// begin/end location and rotation matrices
	BrlyMLocation* bgnloc = NULL;
	BrlyMLocation* endloc = NULL;

	vector<BrlyMLocation*> dstlegbgnlocs;	// note that we don't use ListBrlyMLocation's because they might be holey (cf. selDstlegs)
	vector<BrlyMLocation*> dstlegendlocs;
	vector<double*> dstlegnorms;
	vector<double*> dstlegrmats;

	ListBrlyMLocation orglegbgnlocs;
	ListBrlyMLocation orglegendlocs;
	vector<double*> orglegnorms;
	vector<double*> orglegrmats;

	// mutual leg characterization
	const uint WEST = 1; // location west of dst corridor, i.e. phi < 0
	const uint IN = 2; // location in dst corridor, i.e. 0 < phi < deltaphi
	const uint EAST = 4; // location east of dst corridor, i.e. phi > deltaphi

	const uint SOUTH = 8; // location south of dst corridor, i.e. theta < -legtheta
	// const uint IN = 16; // location in dst corridor, i.e. -legtheta < theta < legtheta
	const uint NORTH = 32; // location north of dst corridor, i.e. theta > legtheta

	uint phibgn_type;
	uint thetabgn_type;
	uint phiend_type;
	uint thetaend_type;

	const uint ORGBGN_EQ_DSTBGN = 1;
	const uint ORGBGN_EQ_DSTEND = 2;
	const uint ORGEND_EQ_DSTBGN = 4;
	const uint ORGEND_EQ_DSTEND = 8;

	uint bgnend_eq;

	const uint DJ = 1; // org and dst legs disjoint
	const uint CNT = 2; // org leg contained in dst leg
	const uint OLP = 3; // org and dst legs have partial overlap
	const uint BGN = 4; // org leg begins in dst leg and ends outside
	const uint END = 5; // org leg ends in dst leg and begins outside
	const uint POLP = 6; // org and dst legs possibly overlap
	const uint EQV = 7; // org and dst legs have equivalent begin and end locations
	const uint INV = 8; // org and dst legs have inverse begin and end locations

	uint olp_type;

	uint pp1_check; // check for pierce point 1 (combination of WEST, EAST, SOUTH, NORTH)
	uint pp2_check; // check for pierce point 2 (combination of WEST, EAST, SOUTH, NORTH)

	// other variables
	BrlyRMLegMLeg lrlprep;
	ListBrlyRMLegMLeg lrls;

	BrlyMLeg* dstleg = NULL;
	double* dstlegnorm = NULL;
	double* dstlegrmat = NULL;

	BrlyMLeg* orgleg = NULL;
	double* orglegnorm = NULL;
	double* orglegrmat = NULL;

	double* bgnloccart = NULL;
	double* endloccart = NULL;

	double bgnlocr, bgnloctheta, bgnlocphi;
	double endlocr, endloctheta, endlocphi;

	double* orglegrmatT = NULL;
	double* org2dstrmat = NULL;

	double pp1_phi;
	double pp2_phi;

	double a, b, c, d;
	bool found;

	// --- load leg data / initialize variables

	// -- destination leg begin/end locations and norm vectors
	dstlegnorms.resize(dstlegs.nodes.size()); for (unsigned int i=0;i<dstlegnorms.size();i++) dstlegnorms[i] = NULL;
	dstlegrmats.resize(dstlegs.nodes.size()); for (unsigned int i=0;i<dstlegrmats.size();i++) dstlegrmats[i] = NULL;

	for (unsigned int i=0;i<dstlegs.nodes.size();i++) {
		dstleg = dstlegs.nodes[i];

		if (selDstlegs[i]) {
			dbsbrly->tblbrlymlocation->loadRecByRef(dstleg->bgnRefBrlyMLocation, &bgnloc);
			locToRad(bgnloc);
			dstlegbgnlocs.push_back(bgnloc);

			dbsbrly->tblbrlymlocation->loadRecByRef(dstleg->endRefBrlyMLocation, &endloc);
			locToRad(endloc);
			dstlegendlocs.push_back(endloc);

			// norm vector
			sphrToCart(1.0, bgnloc->theta, bgnloc->phi, &bgnloccart);
			sphrToCart(1.0, endloc->theta, endloc->phi, &endloccart);

			getCrossProd(bgnloccart, endloccart, &(dstlegnorms[i]));
			norm(dstlegnorms[i]);

			// inverse of leg rotation matrix
			getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &(dstlegrmats[i]));

		} else {
			dstlegbgnlocs.push_back(NULL);
			dstlegendlocs.push_back(NULL);
		};
	};

	// -- origin leg begin/end locations and norm vectors
	orglegnorms.resize(orglegs.nodes.size()); for (unsigned int i=0;i<orglegnorms.size();i++) orglegnorms[i] = NULL;
	orglegrmats.resize(orglegs.nodes.size()); for (unsigned int i=0;i<orglegrmats.size();i++) orglegrmats[i] = NULL;

	for (unsigned int i=0;i<orglegs.nodes.size();i++) {
		orgleg = orglegs.nodes[i];
	
		dbsbrly->tblbrlymlocation->loadRecByRef(orgleg->bgnRefBrlyMLocation, &bgnloc);
		locToRad(bgnloc);
		orglegbgnlocs.nodes.push_back(bgnloc);

		dbsbrly->tblbrlymlocation->loadRecByRef(orgleg->endRefBrlyMLocation, &endloc);
		locToRad(endloc);
		orglegendlocs.nodes.push_back(endloc);

		// norm vector
		sphrToCart(1.0, bgnloc->theta, bgnloc->phi, &bgnloccart);
		sphrToCart(1.0, endloc->theta, endloc->phi, &endloccart);

		getCrossProd(bgnloccart, endloccart, &(orglegnorms[i]));
		norm(orglegnorms[i]);

		// inverse of leg rotation matrix
		getRmatEquatorLeg(bgnloc->theta, bgnloc->phi, endloc->theta, endloc->phi, &(orglegrmats[i]));
	};

	// --- traverse (selected) destination legs
	for (unsigned int i=0;i<dstlegs.nodes.size();i++) {
		if (selDstlegs[i]) {
			dstleg = dstlegs.nodes[i];
			lrlprep.dstRefBrlyMLeg = dstleg->ref;

			dstlegnorm = dstlegnorms[i];
			dstlegrmat = dstlegrmats[i];

			// --- traverse origin legs
			for (unsigned int j=0;j<orglegs.nodes.size();j++) {
				orgleg = orglegs.nodes[j];
				if (orgleg->ref != dstleg->ref) {
					lrlprep.orgRefBrlyMLeg = orgleg->ref;

					orglegnorm = orglegnorms[j];
					orglegrmat = orglegrmats[j];

					// -- calculate matrix that rotates from origin leg coordinates into destination leg coordinates (cartesian)
					transpAmat(orglegrmat, &orglegrmatT, 3);
					multAmatBmat(dstlegrmat, orglegrmatT, &org2dstrmat, 3);

					// -- rotate origin leg begin and end locations into destination cartesian and spherical coordinates
					bgnloc = orglegbgnlocs.nodes[j];
					sphrToCart(1.0, bgnloc->theta, bgnloc->phi, &bgnloccart);
					a = dstlegrmat[0]*bgnloccart[0] + dstlegrmat[1]*bgnloccart[1] + dstlegrmat[2]*bgnloccart[2];
					b = dstlegrmat[3]*bgnloccart[0] + dstlegrmat[4]*bgnloccart[1] + dstlegrmat[5]*bgnloccart[2];
					c = dstlegrmat[6]*bgnloccart[0] + dstlegrmat[7]*bgnloccart[1] + dstlegrmat[8]*bgnloccart[2];
					bgnloccart[0] = a; bgnloccart[1] = b; bgnloccart[2] = c;
					cartToSphr(bgnloccart, &bgnlocr, &bgnloctheta, &bgnlocphi);

					endloc = orglegendlocs.nodes[j];
					sphrToCart(1.0, endloc->theta, endloc->phi, &endloccart);
					a = dstlegrmat[0]*endloccart[0] + dstlegrmat[1]*endloccart[1] + dstlegrmat[2]*endloccart[2];
					b = dstlegrmat[3]*endloccart[0] + dstlegrmat[4]*endloccart[1] + dstlegrmat[5]*endloccart[2];
					c = dstlegrmat[6]*endloccart[0] + dstlegrmat[7]*endloccart[1] + dstlegrmat[8]*endloccart[2];
					endloccart[0] = a; endloccart[1] = b; endloccart[2] = c;
					cartToSphr(endloccart, &endlocr, &endloctheta, &endlocphi);

					olp_type = POLP;

					// -- check if dst/org leg begin/end locations coincide
					bgnend_eq = 0;

					if (orgleg->bgnRefBrlyMLocation == dstleg->bgnRefBrlyMLocation) {
						bgnend_eq += ORGBGN_EQ_DSTBGN;
					} else if (orgleg->bgnRefBrlyMLocation == dstleg->endRefBrlyMLocation) {
						bgnend_eq += ORGBGN_EQ_DSTEND;
					};
					if (orgleg->endRefBrlyMLocation == dstleg->bgnRefBrlyMLocation) {
						bgnend_eq += ORGEND_EQ_DSTBGN;
					} else if (orgleg->endRefBrlyMLocation == dstleg->endRefBrlyMLocation) {
						bgnend_eq += ORGEND_EQ_DSTEND;
					};

					if (bgnend_eq != 0) {
						if ((bgnend_eq & ORGBGN_EQ_DSTBGN) && (bgnend_eq & ORGEND_EQ_DSTEND)) {
							olp_type = EQV;
						} else if ((bgnend_eq & ORGBGN_EQ_DSTEND) && (bgnend_eq & ORGEND_EQ_DSTBGN)) {
							olp_type = INV;

						} else {
							// eliminate cases of legs beginning/ending at coinciding locations but pointing in more-than-perpendicular directions
							d = dstlegnorm[0]*orglegnorm[0] + dstlegnorm[1]*orglegnorm[1] + dstlegnorm[2]*orglegnorm[2];

							if ((bgnend_eq & ORGBGN_EQ_DSTBGN) || (bgnend_eq & ORGEND_EQ_DSTEND)) {
								// disjoint for dot product negative
								if (d < 0) olp_type = DJ;

							} else if ((bgnend_eq & ORGBGN_EQ_DSTEND) || (bgnend_eq & ORGEND_EQ_DSTBGN)) {
								// disjoint for dot product positive
								if (d > 0) olp_type = DJ;
							};
						};
					};

					if ((olp_type != EQV) && (olp_type != INV)) {
						if (olp_type != DJ) {
							// -- characterize origin leg begin and end locations wrt destination leg
							// i.e. set phibgn_type, thetabgn_type, phiend_type, thetaend_type
							if (bgnlocphi < 0.0) {
								phibgn_type = WEST;
							} else if ((bgnlocphi >= 0.0) && (bgnlocphi <= dstleg->deltaphi)) {
								phibgn_type = IN;
							} else {
								phibgn_type = EAST;
							};

							if (bgnloctheta < (-dstleg->alpha)) {
								thetabgn_type = SOUTH;
							} else if ((bgnloctheta >= (-dstleg->alpha)) && (bgnloctheta <= dstleg->alpha)) {
								thetabgn_type = IN;
							} else {
								thetabgn_type = NORTH;
							};

							if (endlocphi < 0.0) {
								phiend_type = WEST;
							} else if ((endlocphi >= 0.0) && (endlocphi <= dstleg->deltaphi)) {
								phiend_type = IN;
							} else {
								phiend_type = EAST;
							};

							if (endloctheta < (-dstleg->alpha)) {
								thetaend_type = SOUTH;
							} else if ((endloctheta >= (-dstleg->alpha)) && (endloctheta <= dstleg->alpha)) {
								thetaend_type = IN;
							} else {
								thetaend_type = NORTH;
							};

							// -- eliminate cases of legs on the remote side of the sphere
							if ((phibgn_type == WEST) && (phiend_type == EAST)) {
								if ((endlocphi-bgnlocphi) > pi) olp_type = DJ;
							};
							if ((phibgn_type == EAST) && (phiend_type == WEST)) {
								if ((bgnlocphi-endlocphi) > pi) olp_type = DJ;
							};
						};

						if (olp_type != DJ) {
							// -- evaluate intersections/pierce points to test (81 possibilities)
							pp1_check = 0;
							pp2_check = 0;

							if (phibgn_type == WEST) {
								if (thetabgn_type == SOUTH) {
									if (phiend_type == WEST) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											olp_type = DJ;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									} else if (phiend_type == IN) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											olp_type = END;
											pp1_check = WEST + SOUTH;
										} else if (thetaend_type == NORTH) {
											pp1_check = WEST + SOUTH;
											pp2_check = NORTH;
										};
									} else if (phiend_type == EAST) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											pp1_check = WEST + SOUTH;
											pp2_check = EAST;
										} else if (thetaend_type == NORTH) {
											pp1_check = WEST + SOUTH;
											pp2_check = EAST + NORTH;
										};
									};
								} else if (thetabgn_type == IN) {
									if (phiend_type == WEST) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											olp_type = DJ;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									} else if (phiend_type == IN) {
										if (thetaend_type == SOUTH) {
											pp1_check = WEST;
											pp2_check = SOUTH;
										} else if (thetaend_type == IN) {
											olp_type = END;
											pp1_check = WEST;
										} else if (thetaend_type == NORTH) {
											pp1_check = WEST;
											pp2_check = NORTH;
										};
									} else if (phiend_type == EAST) {
										if (thetaend_type == SOUTH) {
											pp1_check = WEST;
											pp2_check = EAST + SOUTH;
										} else if (thetaend_type == IN) {
											olp_type = OLP;
											pp1_check = WEST;
											pp2_check = EAST;
										} else if (thetaend_type == NORTH) {
											pp1_check = WEST;
											pp2_check = EAST + NORTH;
										};
									};
								} else if (thetabgn_type == NORTH) {
									if (phiend_type == WEST) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											olp_type = DJ;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									} else if (phiend_type == IN) {
										if (thetaend_type == SOUTH) {
											pp1_check = WEST + NORTH;
											pp2_check = SOUTH;
										} else if (thetaend_type == IN) {
											olp_type = END;
											pp1_check = WEST + NORTH;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									} else if (phiend_type == EAST) {
										if (thetaend_type == SOUTH) {
											pp1_check = WEST + NORTH;
											pp2_check = EAST + SOUTH;
										} else if (thetaend_type == IN) {
											pp1_check = WEST + NORTH;
											pp2_check = EAST;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									};
								};
							} else if (phibgn_type == IN) {
								if (thetabgn_type == SOUTH) {
									if (phiend_type == WEST) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											pp1_check = SOUTH;
											pp2_check = WEST;
										} else if (thetaend_type == NORTH) {
											pp1_check = SOUTH;
											pp2_check = WEST + NORTH;
										};
									} else if (phiend_type == IN) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											olp_type = END;
											pp1_check = SOUTH;
										} else if (thetaend_type == NORTH) {
											olp_type = OLP;
											pp1_check = SOUTH;
											pp2_check = NORTH;
										};
									} else if (phiend_type == EAST) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											pp1_check = SOUTH;
											pp2_check = EAST;
										} else if (thetaend_type == NORTH) {
											pp1_check = SOUTH;
											pp2_check = EAST + NORTH;
										};
									};
								} else if (thetabgn_type == IN) {
									if (phiend_type == WEST) {
										if (thetaend_type == SOUTH) {
											olp_type = BGN;
											pp2_check = WEST + SOUTH;
										} else if (thetaend_type == IN) {
											olp_type = BGN;
											pp2_check = WEST;
										} else if (thetaend_type == NORTH) {
											olp_type = BGN;
											pp2_check = WEST + NORTH;
										};
									} else if (phiend_type == IN) {
										if (thetaend_type == SOUTH) {
											olp_type = BGN;
											pp2_check = SOUTH;
										} else if (thetaend_type == IN) {
											olp_type = CNT;
										} else if (thetaend_type == NORTH) {
											olp_type = BGN;
											pp2_check = NORTH;
										};
									} else if (phiend_type == EAST) {
										if (thetaend_type == SOUTH) {
											olp_type = BGN;
											pp2_check = EAST + SOUTH;
										} else if (thetaend_type == IN) {
											olp_type = BGN;
											pp2_check = EAST;
										} else if (thetaend_type == NORTH) {
											olp_type = BGN;
											pp2_check = EAST + NORTH;
										};
									};
								} else if (thetabgn_type == NORTH) {
									if (phiend_type == WEST) {
										if (thetaend_type == SOUTH) {
											pp1_check = NORTH;
											pp2_check = WEST + SOUTH;
										} else if (thetaend_type == IN) {
											pp1_check = NORTH;
											pp2_check = WEST;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									} else if (phiend_type == IN) {
										if (thetaend_type == SOUTH) {
											olp_type = OLP;
											pp1_check = NORTH;
											pp2_check = SOUTH;
										} else if (thetaend_type == IN) {
											olp_type = END;
											pp1_check = NORTH;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									} else if (phiend_type == EAST) {
										if (thetaend_type == SOUTH) {
											pp1_check = NORTH;
											pp2_check = EAST;
										} else if (thetaend_type == IN) {
											pp1_check = NORTH;
											pp2_check = EAST + SOUTH;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									};
								};
							} else if (phibgn_type == EAST) {
								if (thetabgn_type == SOUTH) {
									if (phiend_type == WEST) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											pp1_check = EAST + SOUTH;
											pp2_check = WEST;
										} else if (thetaend_type == NORTH) {
											pp1_check = EAST + SOUTH;
											pp2_check = WEST + NORTH;
										};
									} else if (phiend_type == IN) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											olp_type = END;
											pp1_check = EAST + SOUTH;
										} else if (thetaend_type == NORTH) {
											pp1_check = EAST + SOUTH;
											pp2_check = NORTH;
										};
									} else if (phiend_type == EAST) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											olp_type = DJ;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									};
								} else if (thetabgn_type == IN) {
									if (phiend_type == WEST) {
										if (thetaend_type == SOUTH) {
											pp1_check = EAST;
											pp2_check = WEST + SOUTH;
										} else if (thetaend_type == IN) {
											olp_type = OLP;
											pp1_check = EAST;
											pp2_check = WEST;
										} else if (thetaend_type == NORTH) {
											pp1_check = EAST;
											pp2_check = WEST + NORTH;
										};
									} else if (phiend_type == IN) {
										if (thetaend_type == SOUTH) {
											pp1_check = EAST;
											pp2_check = SOUTH;
										} else if (thetaend_type == IN) {
											olp_type = END;
											pp1_check = EAST;
										} else if (thetaend_type == NORTH) {
											pp1_check = EAST;
											pp2_check = NORTH;
										};
									} else if (phiend_type == EAST) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											olp_type = DJ;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									};
								} else if (thetabgn_type == NORTH) {
									if (phiend_type == WEST) {
										if (thetaend_type == SOUTH) {
											pp1_check = EAST + NORTH;
											pp2_check = WEST + SOUTH;
										} else if (thetaend_type == IN) {
											pp1_check = EAST + NORTH;
											pp2_check = WEST;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									} else if (phiend_type == IN) {
										if (thetaend_type == SOUTH) {
											pp1_check = EAST + NORTH;
											pp2_check = SOUTH;
										} else if (thetaend_type == IN) {
											olp_type = END;
											pp1_check = EAST + NORTH;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									} else if (phiend_type == EAST) {
										if (thetaend_type == SOUTH) {
											olp_type = DJ;
										} else if (thetaend_type == IN) {
											olp_type = DJ;
										} else if (thetaend_type == NORTH) {
											olp_type = DJ;
										};
									};
								};
							};
						};

						if (olp_type != DJ) {
							// note that pp1_phi and pp2_phi are in origin leg coordinates

							// -- fill in known pierce point phi's
							if ((olp_type == BGN) || (olp_type == CNT)) pp1_phi = 0.0;
							if ((olp_type == END) || (olp_type == CNT)) pp2_phi = orgleg->deltaphi;

							// -- determine unknown pierce points
							if (olp_type == END) {
								// -- perform calculation for pp1_phi (range 0.0 .. orgleg->deltaphi ; start at orgleg->deltaphi)
								found = false;

								if (pp1_check & WEST) found = xsecDstphi(org2dstrmat, 0.0, orgleg->deltaphi, orgleg->deltaphi, 0.0, dstleg->alpha, 1.0e-6, &pp1_phi);
								if (!found && (pp1_check & EAST)) found = xsecDstphi(org2dstrmat, 0.0, orgleg->deltaphi, orgleg->deltaphi, dstleg->deltaphi, dstleg->alpha, 1.0e-6, &pp1_phi);
								if (!found && (pp1_check & SOUTH)) found = xsecDsttheta(org2dstrmat, 0.0, orgleg->deltaphi, orgleg->deltaphi, -dstleg->alpha, dstleg->deltaphi, 1.0e-6, &pp1_phi);
								if (!found && (pp1_check & NORTH)) found = xsecDsttheta(org2dstrmat, 0.0, orgleg->deltaphi, orgleg->deltaphi, dstleg->alpha, dstleg->deltaphi, 1.0e-6, &pp1_phi);
							};

							if (olp_type == BGN) {
								// -- perform calculation for pp2_phi (range pp1_phi .. orgleg->deltaphi ; start at 0.0)
								found = false;
							
								if (pp2_check & WEST) found = xsecDstphi(org2dstrmat, pp1_phi, orgleg->deltaphi, 0.0, 0.0, dstleg->alpha, 1.0e-6, &pp2_phi);
								if (!found && (pp2_check & EAST)) found = xsecDstphi(org2dstrmat, pp1_phi, orgleg->deltaphi, 0.0, dstleg->deltaphi, dstleg->alpha, 1.0e-6, &pp2_phi);
								if (!found && (pp2_check & SOUTH)) found = xsecDsttheta(org2dstrmat, pp1_phi, orgleg->deltaphi, 0.0, -dstleg->alpha, dstleg->deltaphi, 1.0e-6, &pp2_phi);
								if (!found && (pp2_check & NORTH)) found = xsecDsttheta(org2dstrmat, pp1_phi, orgleg->deltaphi, 0.0, dstleg->alpha, dstleg->deltaphi, 1.0e-6, &pp2_phi);
							};

							if ((olp_type == OLP) || (olp_type == POLP)) {
								// -- perform calculations fpr pp1_phi and pp2_phi (will turn olp_type into either DJ or OLP)

								// - perform calculation for pp1_phi (range 0.0 .. orgleg->deltaphi ; start at center of orgleg - gives Newton a better chance for intercontinental/long routes)
								found = false;

								if (pp1_check & WEST) found = xsecDstphi(org2dstrmat, 0.0, orgleg->deltaphi, 0.5*orgleg->deltaphi, 0.0, dstleg->alpha, 1.0e-6, &pp1_phi);
								if (!found && (pp1_check & EAST)) found = xsecDstphi(org2dstrmat, 0.0, orgleg->deltaphi, 0.5*orgleg->deltaphi, dstleg->deltaphi, dstleg->alpha, 1.0e-6, &pp1_phi);
								if (!found && (pp1_check & SOUTH)) found = xsecDsttheta(org2dstrmat, 0.0, orgleg->deltaphi, 0.5*orgleg->deltaphi, -dstleg->alpha, dstleg->deltaphi, 1.0e-6, &pp1_phi);
								if (!found && (pp1_check & NORTH)) found = xsecDsttheta(org2dstrmat, 0.0, orgleg->deltaphi, 0.5*orgleg->deltaphi, dstleg->alpha, dstleg->deltaphi, 1.0e-6, &pp1_phi);

								if (found) {
									// - perform calculation for pp2_phi (range pp1_phi .. orgleg->deltaphi ; start at pp1_phi)
									found = false;

									if (pp2_check & WEST) found = xsecDstphi(org2dstrmat, pp1_phi, orgleg->deltaphi, pp1_phi, 0.0, dstleg->alpha, 1.0e-6, &pp2_phi);
									if (!found && (pp2_check & EAST)) found = xsecDstphi(org2dstrmat, pp1_phi, orgleg->deltaphi, pp1_phi, dstleg->deltaphi, dstleg->alpha, 1.0e-6, &pp2_phi);
									if (!found && (pp2_check & SOUTH)) found = xsecDsttheta(org2dstrmat, pp1_phi, orgleg->deltaphi, pp1_phi, -dstleg->alpha, dstleg->deltaphi, 1.0e-6, &pp2_phi);
									if (!found && (pp2_check & NORTH)) found = xsecDsttheta(org2dstrmat, pp1_phi, orgleg->deltaphi, pp1_phi, dstleg->alpha, dstleg->deltaphi, 1.0e-6, &pp2_phi);
								};
								
								if (found) olp_type = OLP; else olp_type = DJ;
							};
						};
					};

					if (olp_type != DJ) {
						// -- finish up record
						if ((olp_type == EQV) || (olp_type == INV)) {
							lrlprep.x1VisDstLegphi0 = 0.0;
							lrlprep.x1VisDstLegphi1 = dstleg->deltaphi;

							if (olp_type == EQV) {
								lrlprep.VisOrgLegphi0 = lrlprep.x1VisDstLegphi0;
								lrlprep.VisOrgLegphi1 = lrlprep.x1VisDstLegphi1;
							} else {
								lrlprep.VisOrgLegphi0 = lrlprep.x1VisDstLegphi1;
								lrlprep.VisOrgLegphi1 = lrlprep.x1VisDstLegphi0;
							};

						} else {
							// rotate pp1_phi and pp2_phi out of orgleg and into dstleg coordinates
							org2dst(org2dstrmat, pp1_phi, &a, &lrlprep.x1VisDstLegphi0);
							if (fabs(lrlprep.x1VisDstLegphi0) < 1.0e-5) lrlprep.x1VisDstLegphi0 = 0.0;
							org2dst(org2dstrmat, pp2_phi, &a, &lrlprep.x1VisDstLegphi1);
							if (fabs(lrlprep.x1VisDstLegphi1) < 1.0e-5) lrlprep.x1VisDstLegphi1 = 0.0;

							// swap phis such that smaller phi in dstleg coordinates comes first
							if (lrlprep.x1VisDstLegphi1 > lrlprep.x1VisDstLegphi0) {
								lrlprep.VisOrgLegphi0 = pp1_phi;
								lrlprep.VisOrgLegphi1 = pp2_phi;

							} else {
								a = lrlprep.x1VisDstLegphi0;
								lrlprep.x1VisDstLegphi0 = lrlprep.x1VisDstLegphi1;
								lrlprep.x1VisDstLegphi1 = a;

								lrlprep.VisOrgLegphi0 = pp2_phi;
								lrlprep.VisOrgLegphi1 = pp1_phi;
							};
						};

						lrls.nodes.push_back(new BrlyRMLegMLeg(lrlprep));
					};
				};
			};
		};
	};

	// --- cleanup leg data / variables
	for (unsigned int i=0;i<dstlegbgnlocs.size();i++) if (dstlegbgnlocs[i]) delete dstlegbgnlocs[i];
	for (unsigned int i=0;i<dstlegendlocs.size();i++) if (dstlegendlocs[i]) delete dstlegendlocs[i];

	for (unsigned int i=0;i<dstlegnorms.size();i++) if (dstlegnorms[i]) delete[] dstlegnorms[i];
	for (unsigned int i=0;i<dstlegrmats.size();i++) if (dstlegrmats[i]) delete[] dstlegrmats[i];

	for (unsigned int i=0;i<orglegnorms.size();i++) if (orglegnorms[i]) delete[] orglegnorms[i];
	for (unsigned int i=0;i<orglegrmats.size();i++) if (orglegrmats[i]) delete[] orglegrmats[i];

	if (bgnloccart) delete[] bgnloccart;
	if (endloccart) delete[] endloccart;

	if (orglegrmatT) delete[] orglegrmatT;
	if (org2dstrmat) delete[] org2dstrmat;

	// --- insert all lrl's at a time
	for (unsigned int i=0;i<lrls.nodes.size();i++) legRelLegToDeg(lrls.nodes[i]);
	dbsbrly->tblbrlyrmlegmleg->insertRst(lrls, true);
};

inline void BrlyBaseLegleg::org2dst(
			double* org2dstrmat
			, const double orgphi
			, double* dsttheta
			, double* dstphi
		) {
	double a, b, c;

	a = org2dstrmat[0]*cos(orgphi) + org2dstrmat[1]*sin(orgphi);
	b = org2dstrmat[3]*cos(orgphi) + org2dstrmat[4]*sin(orgphi);
	c = org2dstrmat[6]*cos(orgphi) + org2dstrmat[7]*sin(orgphi);

	*dsttheta = asin(c);
	*dstphi = atan2(b, a);
};

inline double BrlyBaseLegleg::orgphi2dstphi(
			double* org2dstrmat
			, const double orgphi
		) {
	double theta, phi;

	org2dst(org2dstrmat, orgphi, &theta, &phi);

	return phi;
};

inline double BrlyBaseLegleg::orgphi2dsttheta(
			double* org2dstrmat
			, const double orgphi
		) {
	double theta, phi;

	org2dst(org2dstrmat, orgphi, &theta, &phi);

	return theta;
};

inline bool BrlyBaseLegleg::xsecDstphi(
			double* org2dstrmat
			, const double orgphimin
			, const double orgphimax
			, const double orgphi0
			, const double dstphi
			, const double dstalpha
			, const double tol
			, double* orgphi
		) {
	bool retval = false;

	double testphi = orgphi0;

	// dst coordinates
	double phi, phinew, dphi, residual;

	phi = orgphi2dstphi(org2dstrmat, testphi);
	residual = fabs(phi-dstphi);

	while (residual > tol) {
		// change testphi using Newton method
		dphi = (orgphi2dstphi(org2dstrmat, testphi+1.0e-6) - orgphi2dstphi(org2dstrmat, testphi-1.0e-6)) / (2.0e-6);
		testphi = testphi - ((phi-dstphi)/dphi);

		// re-evaluate
		phinew = orgphi2dstphi(org2dstrmat, testphi);
		if (fabs(phinew-phi) < 1.0e-6) break;
		phi = phinew;
		
		// require that residual becomes smaller on each iteration
		if (fabs(phi-dstphi) >= residual) break;
		residual = fabs(phi-dstphi);
	};

	if (residual <= tol) {
		// check if corresponding dsttheta is in range
		if (fabs(orgphi2dsttheta(org2dstrmat, testphi)) <= dstalpha) {
			// check if testphi is in orgphi range
			if ((testphi >= orgphimin) && (testphi <= orgphimax)) retval = true;
		};
	};

	*orgphi = testphi;

	return retval;
};

inline bool BrlyBaseLegleg::xsecDsttheta(
			double* org2dstrmat
			, const double orgphimin
			, const double orgphimax
			, const double orgphi0
			, const double dsttheta
			, const double dstdeltaphi
			, const double tol
			, double* orgphi
		) {
	bool retval = false;

	double testphi = orgphi0;

	// dst coordinates
	double theta, thetanew, dtheta, residual;

	theta = orgphi2dsttheta(org2dstrmat, testphi);
	residual = fabs(theta-dsttheta);

	while (residual > tol) {
		// change testphi using Newton method
		dtheta = (orgphi2dsttheta(org2dstrmat, testphi+1.0e-6) - orgphi2dsttheta(org2dstrmat, testphi-1.0e-6)) / (2.0e-6);
		testphi = testphi - ((theta-dsttheta)/dtheta);

		// re-evaluate
		thetanew = orgphi2dsttheta(org2dstrmat, testphi);
		if (fabs(thetanew-theta) < 1.0e-6) break;
		theta = thetanew;

		// require that residual becomes smaller on each iteration
		if (fabs(theta-dsttheta) >= residual) break;
		residual = fabs(theta-dsttheta);
	};

	if (residual <= tol) {
		// need to check if corresponding dstphi is in range
		if ((orgphi2dstphi(org2dstrmat, testphi) >= 0.0) && (orgphi2dstphi(org2dstrmat, testphi) <= dstdeltaphi)) {
			// check if testphi is in orgphi range
			if ((testphi >= orgphimin) && (testphi <= orgphimax)) retval = true;
		};
	};

	*orgphi = testphi;

	return retval;
};
// IP cust --- IEND


