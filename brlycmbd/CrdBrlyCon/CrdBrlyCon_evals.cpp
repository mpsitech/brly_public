/**
  * \file CrdBrlyCon_evals.cpp
  * job handler for job CrdBrlyCon (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool CrdBrlyCon::evalMspCrd1Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbsbrly);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyCon::evalMitCrdNewAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacConIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) & VecBrlyWUiaccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

