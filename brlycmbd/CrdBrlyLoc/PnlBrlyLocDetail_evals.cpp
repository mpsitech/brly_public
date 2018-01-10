/**
  * \file PnlBrlyLocDetail_evals.cpp
  * job handler for job PnlBrlyLocDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyLocDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxtSrfActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfIcaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfTitActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalPupTypActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxtRegActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfAltActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfTheActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfPhiActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfTzActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfAphActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalChkCdnActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpNewAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)&loc.eqpEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpDeleteAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)&!loc.eqpEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxtEqpOprAvail(
			DbsBrly* dbsbrly
		) {
	// !loc.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxtEqpOprActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpOprViewAvail(
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

bool PnlBrlyLocDetail::evalButEqpOprViewActive(
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

bool PnlBrlyLocDetail::evalTxtEqpPtyAvail(
			DbsBrly* dbsbrly
		) {
	// !loc.eqpEq(0)&eqp.inSbs(pln)

	vector<bool> args;
	bool a, b;

	a = false; a = (recLoc.refBrlyMEquipment == 0);
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

bool PnlBrlyLocDetail::evalTxtEqpPtyActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpPtyViewAvail(
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

bool PnlBrlyLocDetail::evalButEqpPtyViewActive(
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

bool PnlBrlyLocDetail::evalPupEqpEtyAvail(
			DbsBrly* dbsbrly
		) {
	// !loc.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalPupEqpEtyActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpEtyEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYADM, jref));
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalChkEqpFibAvail(
			DbsBrly* dbsbrly
		) {
	// !loc.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalChkEqpFibActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

