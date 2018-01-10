/**
  * \file PnlBrlyOprRec_evals.cpp
  * job handler for job PnlBrlyOprRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyOprRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refOpr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFOPR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

