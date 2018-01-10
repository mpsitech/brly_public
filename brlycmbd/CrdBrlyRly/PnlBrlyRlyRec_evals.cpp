/**
  * \file PnlBrlyRlyRec_evals.cpp
  * job handler for job PnlBrlyRlyRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyRlyRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refRly()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFRLY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

