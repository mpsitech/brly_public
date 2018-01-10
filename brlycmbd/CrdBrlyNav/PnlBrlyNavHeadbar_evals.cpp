/**
  * \file PnlBrlyNavHeadbar_evals.cpp
  * job handler for job PnlBrlyNavHeadbar (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyNavHeadbar::evalMenCrdAvail(
			DbsBrly* dbsbrly
		) {
	// MspCrd1Avail()|MspCrd2Avail()|MspCrd3Avail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMspCrd1Avail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMspCrd2Avail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMspCrd3Avail(dbsbrly);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMspCrd1Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdUsgAvail()|MitCrdUsrAvail()|MitCrdPrsAvail()|MitCrdFilAvail()|MitCrdOprAvail()|MitCrdPtyAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdUsgAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdUsrAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdPrsAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdFilAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdOprAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdPtyAvail(dbsbrly);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdUsgAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdUsrAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdPrsAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdFilAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdOprAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacOpr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACOPR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdPtyAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMspCrd2Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdRegAvail()|MitCrdLocAvail()|MitCrdLegAvail()|MitCrdTtbAvail()|MitCrdFltAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdRegAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdLocAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdLegAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdTtbAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdFltAvail(dbsbrly);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdRegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacReg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACREG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdLocAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLoc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdLegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdTtbAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdFltAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFlt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMspCrd3Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdConAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdConAvail(dbsbrly);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdConAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};

