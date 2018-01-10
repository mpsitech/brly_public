/**
  * \file PnlBrlyFltDetail_evals.cpp
  * job handler for job PnlBrlyFltDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyFltDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxtSrfActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxtTtbActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButTtbViewAvail(
			DbsBrly* dbsbrly
		) {
	// flt.ttbEq(0)|(pre.ixUacTtb())

	vector<bool> args;
	bool a, b;

	a = false; a = (recFlt.refBrlyMTimetable == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButTtbViewActive(
			DbsBrly* dbsbrly
		) {
	// !flt.ttbEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMTimetable == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxtLegActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfStaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfStoActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfXsaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfXsoActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalChkCdnActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalChkSdnActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButFafNewAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)&flt.fafEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButFafDeleteAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)&!flt.fafEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFidAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFidActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafIdtAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafIdtActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafActAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafActActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFetAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFetActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFtiAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFtiActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFdtAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFdtActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFskAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFskActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFsmAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFsmActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFatAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafFatActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafRteAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafRteActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafAdtAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafAdtActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafEatAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafEatActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafAatAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafAatActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafDvtAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafDvtActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafOrgAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafOrgActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafDstAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafDstActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafOnmAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafOnmActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafOctAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafOctActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafDnmAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafDnmActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafDctAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxfFafDctActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButEqpNewAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)&flt.eqpEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (recFlt.refBrlyMEquipment == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButEqpDeleteAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)&!flt.eqpEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (recFlt.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxtEqpOprAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxtEqpOprActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButEqpOprViewAvail(
			DbsBrly* dbsbrly
		) {
	// eqp.oprEq(0)|(pre.ixUacOpr())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEqp.refBrlyMOperator == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACOPR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButEqpOprViewActive(
			DbsBrly* dbsbrly
		) {
	// !eqp.oprEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEqp.refBrlyMOperator == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxtEqpPtyAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.eqpEq(0)&eqp.inSbs(pln)

	vector<bool> args;
	bool a, b;

	a = false; a = (recFlt.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = ((ixWSubsetEqp & VecBrlyWMEquipmentSubset::SBSBRLYBMEQUIPMENTPLN) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyFltDetail::evalTxtEqpPtyActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButEqpPtyViewAvail(
			DbsBrly* dbsbrly
		) {
	// eqp.ptyEq(0)|(pre.ixUacPty())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEqp.refBrlyMPlntype == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPTY, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButEqpPtyViewActive(
			DbsBrly* dbsbrly
		) {
	// !eqp.ptyEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEqp.refBrlyMPlntype == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalPupEqpEtyAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalPupEqpEtyActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalButEqpEtyEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYADM, jref));
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalChkEqpFibAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltDetail::evalChkEqpFibActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

