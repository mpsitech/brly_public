/**
  * \file PnlBrlyTtbDetail_evals.cpp
  * job handler for job PnlBrlyTtbDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyTtbDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyTtbDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyTtbDetail::evalTxfTitActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyTtbDetail::evalTxtFilActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyTtbDetail::evalButFilViewAvail(
			DbsBrly* dbsbrly
		) {
	// ttb.filEq(0)|(pre.ixUacFil())

	vector<bool> args;
	bool a, b;

	a = false; a = (recTtb.refBrlyMFile == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFIL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyTtbDetail::evalButFilViewActive(
			DbsBrly* dbsbrly
		) {
	// !ttb.filEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTtb.refBrlyMFile == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyTtbDetail::evalPupAliActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyTtbDetail::evalButAliEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYADM, jref));
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyTtbDetail::evalTxfStaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyTtbDetail::evalTxfStoActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

