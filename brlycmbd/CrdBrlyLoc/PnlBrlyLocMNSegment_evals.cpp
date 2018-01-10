/**
  * \file PnlBrlyLocMNSegment_evals.cpp
  * job handler for job PnlBrlyLocMNSegment (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyLocMNSegment::evalButAddAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocMNSegment::evalButSubAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocMNSegment::evalButSubActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

