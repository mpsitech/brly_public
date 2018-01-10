/**
  * \file PnlBrlyOprDetail_evals.cpp
  * job handler for job PnlBrlyOprDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyOprDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacOprIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACOPR, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyOprDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyOprDetail::evalTxtSrfActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacOprIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACOPR, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyOprDetail::evalTxfIcaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacOprIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACOPR, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyOprDetail::evalTxfTitActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacOprIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACOPR, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

