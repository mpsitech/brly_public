/**
  * \file PnlBrlyConDetail_evals.cpp
  * job handler for job PnlBrlyConDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyConDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConDetail::evalTxtFltActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConDetail::evalButFltViewAvail(
			DbsBrly* dbsbrly
		) {
	// con.fltEq(0)|(pre.ixUacFlt())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCon.refBrlyMFlight == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyConDetail::evalButFltViewActive(
			DbsBrly* dbsbrly
		) {
	// !con.fltEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.refBrlyMFlight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyConDetail::evalTxtCorActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConDetail::evalTxfStaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConDetail::evalTxfStoActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConDetail::evalPupModActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConDetail::evalTxtTtbActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConDetail::evalButTtbViewAvail(
			DbsBrly* dbsbrly
		) {
	// con.ttbEq(0)|(pre.ixUacTtb())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCon.refBrlyMTimetable == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyConDetail::evalButTtbViewActive(
			DbsBrly* dbsbrly
		) {
	// !con.ttbEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.refBrlyMTimetable == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyConDetail::evalLstEtyActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConDetail::evalButEtyEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYADM, jref));
	args.push_back(a);

	return(args.back());
};

