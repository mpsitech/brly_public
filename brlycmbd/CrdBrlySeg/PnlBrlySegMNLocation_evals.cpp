/**
  * \file PnlBrlySegMNLocation_evals.cpp
  * job handler for job PnlBrlySegMNLocation (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlySegMNLocation::evalButViewAvail(
			DbsBrly* dbsbrly
		) {
	// !sel()|(pre.ixUacLoc())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlySegMNLocation::evalButViewActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegMNLocation::evalButAddAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegMNLocation::evalButSubAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegMNLocation::evalButSubActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

