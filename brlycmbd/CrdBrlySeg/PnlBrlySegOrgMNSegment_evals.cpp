/**
  * \file PnlBrlySegOrgMNSegment_evals.cpp
  * job handler for job PnlBrlySegOrgMNSegment (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

bool PnlBrlySegOrgMNSegment::evalButViewAvail(
			DbsBrly* dbsbrly
		) {
	// !sel()|((pre.ixUacSeg()&pre.refFlt())|(pre.ixUacSeg()&pre.refCon()))

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFFLT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref) != 0);
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

bool PnlBrlySegOrgMNSegment::evalButViewActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegOrgMNSegment::evalButAddAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegOrgMNSegment::evalButSubAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixUacSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXUACSEG, jref) & VecBrlyWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegOrgMNSegment::evalButSubActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

