/**
  * \file PnlBrlyPtyRec_evals.cpp
  * job handler for job PnlBrlyPtyRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyPtyRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refPty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFPTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

