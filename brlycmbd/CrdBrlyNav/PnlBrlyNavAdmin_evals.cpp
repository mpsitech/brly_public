/**
  * \file PnlBrlyNavAdmin_evals.cpp
  * job handler for job PnlBrlyNavAdmin (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyNavAdmin::evalLstUsgAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButUsgViewActive(
			DbsBrly* dbsbrly
		) {
	// LstUsg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalLstUsrAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButUsrViewActive(
			DbsBrly* dbsbrly
		) {
	// LstUsr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalLstPrsAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButPrsViewActive(
			DbsBrly* dbsbrly
		) {
	// LstPrs.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrs != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalLstFilAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButFilViewActive(
			DbsBrly* dbsbrly
		) {
	// LstFil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFil != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalLstOprAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacOpr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACOPR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButOprViewActive(
			DbsBrly* dbsbrly
		) {
	// LstOpr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstOpr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalLstPtyAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButPtyViewActive(
			DbsBrly* dbsbrly
		) {
	// LstPty.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPty != 0);
	args.push_back(a);

	return(args.back());
};

