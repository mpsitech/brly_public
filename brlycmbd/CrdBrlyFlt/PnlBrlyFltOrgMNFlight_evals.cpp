/**
  * \file PnlBrlyFltOrgMNFlight_evals.cpp
  * job handler for job PnlBrlyFltOrgMNFlight (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyFltOrgMNFlight::evalButViewAvail(
			DbsBrly* dbsbrly
		) {
	// !sel()|(pre.ixUacFlt())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyFltOrgMNFlight::evalButViewActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltOrgMNFlight::evalButAddAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltOrgMNFlight::evalButSubAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltOrgMNFlight::evalButSubActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

