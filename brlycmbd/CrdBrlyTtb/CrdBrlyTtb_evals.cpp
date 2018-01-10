/**
  * \file CrdBrlyTtb_evals.cpp
  * job handler for job CrdBrlyTtb (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool CrdBrlyTtb::evalMspCrd1Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbsbrly);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyTtb::evalMitCrdNewAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyTtb::evalMitCrdTrlAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtbIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) & VecBrlyWUiaccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyTtb::evalMitCrdIflAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtbIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) & VecBrlyWUiaccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdBrlyTtb::evalMitCrdIflActive(
			DbsBrly* dbsbrly
		) {
	// pre.refTtb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFTTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

