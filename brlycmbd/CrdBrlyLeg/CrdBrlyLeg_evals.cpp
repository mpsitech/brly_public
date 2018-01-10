/**
  * \file CrdBrlyLeg_evals.cpp
  * job handler for job CrdBrlyLeg (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool CrdBrlyLeg::evalMspCrd1Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbsbrly);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyLeg::evalMitCrdNewAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLegIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLEG, jref) & VecBrlyWUiaccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

