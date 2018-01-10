/**
  * \file PnlBrlySegRec_evals.cpp
  * job handler for job PnlBrlySegRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlySegRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refSeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

