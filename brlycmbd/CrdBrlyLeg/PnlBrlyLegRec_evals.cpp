/**
  * \file PnlBrlyLegRec_evals.cpp
  * job handler for job PnlBrlyLegRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyLegRec::evalPnlcor1nconnectionAvail(
			DbsBrly* dbsbrly
		) {
	// leg.inSbs(cor)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetLeg & VecBrlyWMLegSubset::SBSBRLYBMLEGCOR) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegRec::evalPnl1nflightAvail(
			DbsBrly* dbsbrly
		) {
	// leg.inSbs(rte)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetLeg & VecBrlyWMLegSubset::SBSBRLYBMLEGRTE) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refLeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

