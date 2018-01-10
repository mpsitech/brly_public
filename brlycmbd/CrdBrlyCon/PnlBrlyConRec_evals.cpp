/**
  * \file PnlBrlyConRec_evals.cpp
  * job handler for job PnlBrlyConRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyConRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};

