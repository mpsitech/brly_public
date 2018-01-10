/**
  * \file CrdBrlyNav_evals.cpp
  * job handler for job CrdBrlyNav (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool CrdBrlyNav::evalPnladminAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacUsg()|pre.ixUacUsr()|pre.ixUacPrs()|pre.ixUacFil()|pre.ixUacOpr()|pre.ixUacPty()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACUSG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACUSR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFIL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACOPR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPTY, jref) != 0);
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

bool CrdBrlyNav::evalPnlbaseAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacReg()|pre.ixUacLoc()|pre.ixUacLeg()|pre.ixUacTtb()|pre.ixUacFlt()|pre.ixUacSeg()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACREG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLEG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) != 0);
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

bool CrdBrlyNav::evalPnlconnectAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacCon()|pre.ixUacRly()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACRLY, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdBrlyNav::evalMspCrd1Avail(
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

bool CrdBrlyNav::evalMitCrdUsgAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdUsrAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdPrsAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdFilAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdOprAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacOpr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACOPR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdPtyAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacPty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACPTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMspCrd2Avail(
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

bool CrdBrlyNav::evalMitCrdRegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacReg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACREG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdLocAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLoc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLOC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdLegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacLeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACLEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdTtbAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacTtb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACTTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdFltAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacFlt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACFLT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMspCrd3Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdConAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdConAvail(dbsbrly);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdConAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMspApp2Avail(
			DbsBrly* dbsbrly
		) {
	// MitAppLoiAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitAppLoiAvail(dbsbrly);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitAppLoiAvail(
			DbsBrly* dbsbrly
		) {
	// virgin()

	vector<bool> args;
	bool a;

	a = false; {uint cnt = 0; dbsbrly->loadUintBySQL("SELECT COUNT(ref) FROM TblBrlyMUser WHERE sref <> 'temp'", cnt); a = (cnt == 0);};
	args.push_back(a);

	return(args.back());
};

