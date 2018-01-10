/**
  * \file PnlBrlyLocRec_evals.cpp
  * job handler for job PnlBrlyLocRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlyLocRec::evalPnlbgn1nlegAvail(
			DbsBrly* dbsbrly
		) {
	// loc.inSbs(apt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetLoc & VecBrlyWMLocationSubset::SBSBRLYBMLOCATIONAPT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocRec::evalPnlend1nlegAvail(
			DbsBrly* dbsbrly
		) {
	// loc.inSbs(apt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetLoc & VecBrlyWMLocationSubset::SBSBRLYBMLOCATIONAPT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocRec::evalPnleqp1nnodeAvail(
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

bool PnlBrlyLocRec::evalPnleqpmnconnectionAvail(
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

bool PnlBrlyLocRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refLoc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLOC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

