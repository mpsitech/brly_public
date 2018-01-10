/**
  * \file PnlBrlyRegRec_evals.cpp
  * job handler for job PnlBrlyRegRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyRegRec::evalPnl1nlocationAvail(
			DbsBrly* dbsbrly
		) {
	// reg.inSbs(rip)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetReg & VecBrlyWMRegionSubset::SBSBRLYBMREGIONRIP) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refReg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFREG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

