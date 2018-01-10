/**
  * \file PnlBrlyRlyDetail_evals.cpp
  * job handler for job PnlBrlyRlyDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyRlyDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacRlyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACRLY, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRlyDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRlyDetail::evalTxfStaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacRlyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACRLY, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRlyDetail::evalTxfStoActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacRlyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACRLY, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRlyDetail::evalTxtConActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacRlyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACRLY, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRlyDetail::evalButConViewAvail(
			DbsBrly* dbsbrly
		) {
	// rly.conEq(0)|(pre.ixUacCon())

	vector<bool> args;
	bool a, b;

	a = false; a = (recRly.refBrlyMConnection == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyRlyDetail::evalButConViewActive(
			DbsBrly* dbsbrly
		) {
	// !rly.conEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recRly.refBrlyMConnection == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyRlyDetail::evalPupDirActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacRlyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACRLY, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRlyDetail::evalChkCtdActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacRlyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACRLY, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRlyDetail::evalTxfNhpActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacRlyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACRLY, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

