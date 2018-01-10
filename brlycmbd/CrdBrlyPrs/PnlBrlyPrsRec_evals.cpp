/**
  * \file PnlBrlyPrsRec_evals.cpp
  * job handler for job PnlBrlyPrsRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyPrsRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

