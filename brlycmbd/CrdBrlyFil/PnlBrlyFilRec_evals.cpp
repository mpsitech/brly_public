/**
  * \file PnlBrlyFilRec_evals.cpp
  * job handler for job PnlBrlyFilRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyFilRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

