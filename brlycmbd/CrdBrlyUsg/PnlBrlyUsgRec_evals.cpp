/**
  * \file PnlBrlyUsgRec_evals.cpp
  * job handler for job PnlBrlyUsgRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyUsgRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

