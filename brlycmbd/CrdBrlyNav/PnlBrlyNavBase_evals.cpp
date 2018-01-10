/**
  * \file PnlBrlyNavBase_evals.cpp
  * job handler for job PnlBrlyNavBase (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyNavBase::evalLstRegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacReg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACREG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButRegViewActive(
			DbsBrly* dbsbrly
		) {
	// LstReg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstReg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalLstLocAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLoc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButLocViewActive(
			DbsBrly* dbsbrly
		) {
	// LstLoc.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstLoc != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalLstLegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButLegViewActive(
			DbsBrly* dbsbrly
		) {
	// LstLeg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstLeg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalLstTtbAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButTtbViewActive(
			DbsBrly* dbsbrly
		) {
	// LstTtb.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstTtb != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalLstFltAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFlt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButFltViewActive(
			DbsBrly* dbsbrly
		) {
	// LstFlt.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFlt != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalLstSegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButSegViewActive(
			DbsBrly* dbsbrly
		) {
	// LstSeg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSeg != 0);
	args.push_back(a);

	return(args.back());
};

