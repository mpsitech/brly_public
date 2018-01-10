/**
  * \file PnlBrlyTtbRec_evals.cpp
  * job handler for job PnlBrlyTtbRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyTtbRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refTtb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFTTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

