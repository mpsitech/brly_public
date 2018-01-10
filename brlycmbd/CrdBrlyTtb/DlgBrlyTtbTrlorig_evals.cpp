/**
  * \file DlgBrlyTtbTrlorig_evals.cpp
  * job handler for job DlgBrlyTtbTrlorig (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool DlgBrlyTtbTrlorig::evalRfiUldActive(
			DbsBrly* dbsbrly
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyTtbTrlorig::evalTrlButRunActive(
			DbsBrly* dbsbrly
		) {
	// sge(ulddone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::ULDDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyTtbTrlorig::evalTrlButStoActive(
			DbsBrly* dbsbrly
		) {
	// sge(translate)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::TRANSLATE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyTtbTrlorig::evalTfiDldActive(
			DbsBrly* dbsbrly
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyTtbTrlorig::evalButDneActive(
			DbsBrly* dbsbrly
		) {
	// sge(idle|done)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

