/**
  * \file PnlBrlyNavConnect_evals.cpp
  * job handler for job PnlBrlyNavConnect (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyNavConnect::evalLstConAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavConnect::evalButConViewActive(
			DbsBrly* dbsbrly
		) {
	// LstCon.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCon != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavConnect::evalLstRlyAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacRly()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACRLY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavConnect::evalButRlyViewActive(
			DbsBrly* dbsbrly
		) {
	// LstRly.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstRly != 0);
	args.push_back(a);

	return(args.back());
};

