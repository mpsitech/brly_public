/**
  * \file PnlBrlyPrsDetail_evals.cpp
  * job handler for job PnlBrlyPrsDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyPrsDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalTxfTitActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalTxfFnmActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalPupJlnActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalButJlnEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalTxtLnmActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalLstDrvActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalPupSexActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalTxfTelActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalTxfEmlActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPrsDetail::evalTxfSalActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

