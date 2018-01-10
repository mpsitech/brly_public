/**
  * \file PnlBrlySegDetail_evals.cpp
  * job handler for job PnlBrlySegDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlySegDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxtReuActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalButReuViewAvail(
			DbsBrly* dbsbrly
		) {
	// seg.reuEq(0)|((pre.ixUacCon()&seg.retEq(con))|(pre.ixUacFlt()&seg.retEq(flt)))

	vector<bool> args;
	bool a, b;

	a = false; a = (recSeg.refUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) != 0);
	args.push_back(a);
	a = false; a = (recSeg.refIxVTbl == VecBrlyVMSegmentRefTbl::CON);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) != 0);
	args.push_back(a);
	a = false; a = (recSeg.refIxVTbl == VecBrlyVMSegmentRefTbl::FLT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlySegDetail::evalButReuViewActive(
			DbsBrly* dbsbrly
		) {
	// !seg.reuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSeg.refUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfDphActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfAl0Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfAl1Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfTh0Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfTh1Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfPh0Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfPh1Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfStaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfStoActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalChkCdnActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

