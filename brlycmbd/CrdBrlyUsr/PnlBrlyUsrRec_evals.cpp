/**
  * \file PnlBrlyUsrRec_evals.cpp
  * job handler for job PnlBrlyUsrRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyUsrRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

