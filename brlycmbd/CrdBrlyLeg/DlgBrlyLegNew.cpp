/**
  * \file DlgBrlyLegNew.cpp
  * job handler for job DlgBrlyLegNew (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "DlgBrlyLegNew.h"

#include "DlgBrlyLegNew_blks.cpp"
#include "DlgBrlyLegNew_evals.cpp"

/******************************************************************************
 class DlgBrlyLegNew
 ******************************************************************************/

DlgBrlyLegNew::DlgBrlyLegNew(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::DLGBRLYLEGNEW, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFDetPupTyp.tag = "FeedFDetPupTyp";
	VecBrlyVMLegBasetype::fillFeed(ixBrlyVLocale, feedFDetPupTyp);
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixBrlyVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::DET;

	valid = false;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgBrlyLegNew::~DlgBrlyLegNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void DlgBrlyLegNew::sphrToCart(
			double _r																						// radius
			, double _theta																			// angle from equatorial (x-y) plane
			, double _phi																				// angle from x-axis
			, double** _vec																			// pointer to carterian result vector (double[3]) ; created if NULL
		) {
	if (*_vec == NULL) *_vec = new double[3];
	
	(*_vec)[0] = _r*cos(_theta)*cos(_phi);
	(*_vec)[1] = _r*cos(_theta)*sin(_phi);
	(*_vec)[2] = _r*sin(_theta);
};

double DlgBrlyLegNew::degToRad(
			double _deg																					//! angle in degrees (0¡ .. 360¡)
		) {
	return(pi*_deg/180.0);
};

double DlgBrlyLegNew::radToDeg(
			double _rad																					//! angle in degrees (0¡ .. 360¡)
		) {
	return(180.0*_rad/pi);
};
// IP cust --- IEND
DpchEngBrly* DlgBrlyLegNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &continfinc, &feedFDetPupTyp, &feedFDse, &feedFSge, &statshr, &statshrdet, &statshrinc, items);
	};

	return dpcheng;
};

void DlgBrlyLegNew::refreshDet(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIacDet oldContiacdet(contiacdet);
	StatShrDet oldStatshrdet(statshrdet);

	// IP refreshDet --- BEGIN
	// contiacdet

	// statshrdet
	statshrdet.ButCreActive = evalDetButCreActive(dbsbrly);

	// IP refreshDet --- END
	if (contiacdet.diff(&oldContiacdet).size() != 0) insert(moditems, DpchEngData::CONTIACDET);
	if (statshrdet.diff(&oldStatshrdet).size() != 0) insert(moditems, DpchEngData::STATSHRDET);
};

void DlgBrlyLegNew::refreshInc(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInfInc oldContinfinc(continfinc);
	StatShrInc oldStatshrinc(statshrinc);

	// IP refreshInc --- RBEGIN
	// continfinc
	continfinc.TxtPrg = getSquawk(dbsbrly);

	// statshrinc
	statshrinc.ButRunActive = evalIncButRunActive(dbsbrly);
	statshrinc.ButStoActive = evalIncButStoActive(dbsbrly);

	// IP refreshInc --- REND
	if (continfinc.diff(&oldContinfinc).size() != 0) insert(moditems, DpchEngData::CONTINFINC);
	if (statshrinc.diff(&oldStatshrinc).size() != 0) insert(moditems, DpchEngData::STATSHRINC);
};

void DlgBrlyLegNew::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// statshr
	statshr.ButDneActive = evalButDneActive(dbsbrly);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshDet(dbsbrly, moditems);
	refreshInc(dbsbrly, moditems);
};

void DlgBrlyLegNew::changeStage(
			DbsBrly* dbsbrly
			, uint _ixVSge
			, DpchEngBrly** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsbrly); break;
				case VecVSge::CREATE: leaveSgeCreate(dbsbrly); break;
				case VecVSge::CREDONE: leaveSgeCredone(dbsbrly); break;
				case VecVSge::INCO: leaveSgeInco(dbsbrly); break;
				case VecVSge::DONE: leaveSgeDone(dbsbrly); break;
			};

			ixVSge = _ixVSge;
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbsbrly, reenter); break;
			case VecVSge::CREDONE: _ixVSge = enterSgeCredone(dbsbrly, reenter); break;
			case VecVSge::INCO: _ixVSge = enterSgeInco(dbsbrly, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint DlgBrlyLegNew::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgBrlyLegNew::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgBrlyLegNew::enterSgeCreate(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CREATE;
	nextIxVSge = VecVSge::CREDONE;
	// IP enterSgeCreate --- IBEGIN
	ubigint ref;

	BrlyMLeg leg;

	BrlyMLocation* bgnloc = NULL;
	BrlyMLocation* endloc = NULL;

	double acraltitude = xchg->stgbrlygeometry.acraltitude;
	double corrwidth1 = xchg->stgbrlygeometry.corrwidth1;
	double corrwidth2 = xchg->stgbrlygeometry.corrwidth2;
	double earthradius = xchg->stgbrlygeometry.earthradius;
	double hrznaltitude = xchg->stgbrlygeometry.hrznaltitude;

	double* bgncart = NULL;
	double* endcart = NULL;
	double delta;

	leg.ixVBasetype = feedFDetPupTyp.getByNum(contiacdet.numFPupTyp)->ix;

	dbsbrly->tblbrlymlocation->loadRecBySrf(contiacdet.TxfBgn, &bgnloc);
	dbsbrly->tblbrlymlocation->loadRecBySrf(contiacdet.TxfEnd, &endloc);

	leg.bgnRefBrlyMLocation = bgnloc->ref;
	leg.endRefBrlyMLocation = endloc->ref;
	
	if (dbsbrly->loadRefBySQL("SELECT ref FROM TblBrlyMLeg WHERE ixVBasetype = " + to_string(leg.ixVBasetype) + " AND bgnRefBrlyMLocation = " + to_string(leg.endRefBrlyMLocation)
					+ " AND endRefBrlyMLocation = " + to_string(leg.bgnRefBrlyMLocation), ref)) {

		leg.refBrlyCLeg = dbsbrly->tblbrlycleg->getNewRef();
		dbsbrly->executeQuery("UPDATE TblBrlyMLeg SET refBrlyCLeg = " + to_string(leg.refBrlyCLeg) + " WHERE ref = " + to_string(ref));
	};

	leg.alt = acraltitude;

	sphrToCart(1.0, degToRad(bgnloc->theta), degToRad(bgnloc->phi), &bgncart);
	sphrToCart(1.0, degToRad(endloc->theta), degToRad(endloc->phi), &endcart);
	delta = acos(bgncart[0]*endcart[0] + bgncart[1]*endcart[1] + bgncart[2]*endcart[2]);
	leg.deltaphi = radToDeg(delta);

	if (leg.ixVBasetype == VecBrlyVMLegBasetype::RTE) {
		leg.alpha = radToDeg(acos((earthradius + hrznaltitude) / (earthradius + acraltitude)));

	} else if (leg.ixVBasetype == VecBrlyVMLegBasetype::CORR) {
		if ((delta * earthradius) < 2000e3) {
			leg.alpha = radToDeg(0.5*corrwidth1 / earthradius);
		} else {
			leg.alpha = radToDeg(0.5*corrwidth2 / earthradius);
		};
	};

	dbsbrly->tblbrlymleg->insertRec(&leg);

	xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYLEGMOD, jref);
	xchg->triggerIxRefCall(dbsbrly, VecBrlyVCall::CALLBRLYREFPRESET, jref, VecBrlyVPreset::PREBRLYREFLEG, leg.ref);

	delete bgnloc;
	delete endloc;

	if (bgncart) delete[] bgncart;
	if (endcart) delete[] endcart;

	// IP enterSgeCreate --- IEND
	retval = nextIxVSge;
	return retval;
};

void DlgBrlyLegNew::leaveSgeCreate(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgBrlyLegNew::enterSgeCredone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CREDONE;
	nextIxVSge = retval;
	// IP enterSgeCredone --- INSERT
	return retval;
};

void DlgBrlyLegNew::leaveSgeCredone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCredone --- INSERT
};

uint DlgBrlyLegNew::enterSgeInco(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::INCO;
	nextIxVSge = VecVSge::DONE;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeInco --- IBEGIN
	// invoke BrlyBaseLegloc and BrlyBaseLegleg

	ubigint refBrlyMLeg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLEG, jref);

	// leg-loc
	addInv(new DpchInvBrlyBaseLegloc(0, 0, true, false, 0, 0, {refBrlyMLeg}, {}));

	// leg-leg
	addInv(new DpchInvBrlyBaseLegleg(0, 0, true, false, 0, 0, {refBrlyMLeg}));
	addInv(new DpchInvBrlyBaseLegleg(0, 0, false, true, 0, 0, {refBrlyMLeg}));
	// IP enterSgeInco --- IEND
	submitInvs(dbsbrly, retval, retval);
	return retval;
};

void DlgBrlyLegNew::leaveSgeInco(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeInco --- IBEGIN
	dbsbrly->executeQuery("UPDATE TblBrlyMLeg SET Calcdone = 1 WHERE ref = " + to_string(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLEG, jref)));
	// IP leaveSgeInco --- IEND
};

uint DlgBrlyLegNew::enterSgeDone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
	// IP enterSgeDone --- INSERT
	return retval;
};

void DlgBrlyLegNew::leaveSgeDone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeDone --- INSERT
};

string DlgBrlyLegNew::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::CREDONE) || (ixVSge == VecVSge::INCO) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::CREDONE) retval = "new leg created";
			else if (ixVSge == VecVSge::INCO) retval = "incorporating leg (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed)";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::CREDONE) retval = "neue Strecke erstellt";
			else if (ixVSge == VecVSge::INCO) retval = "gliedere Strecke ein (" + to_string(opNdone) + "/" + to_string(opN) + " Operationen ausgef\\u00fchrt)";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

void DlgBrlyLegNew::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYINIT) {
			handleDpchAppBrlyInit(dbsbrly, (DpchAppBrlyInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYLEGNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbsbrly, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYLEGNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsbrly, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoDet != 0) {
				if (dpchappdo->ixVDoDet == VecVDoDet::BUTCRECLICK) {
					handleDpchAppDoDetButCreClick(dbsbrly, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoInc != 0) {
				if (dpchappdo->ixVDoInc == VecVDoInc::BUTRUNCLICK) {
					handleDpchAppDoIncButRunClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDoInc == VecVDoInc::BUTSTOCLICK) {
					handleDpchAppDoIncButStoClick(dbsbrly, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::RET) {
		opNdone++;

		if (opNdone == opN) {
			clearOps();

			opNdone = 0;
			opN = 0;

			changeStage(dbsbrly, nextIxVSge);
		};

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::TIMER) {
		handleTimer(dbsbrly, req->sref);
	};
};

void DlgBrlyLegNew::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgBrlyLegNew::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::INC)) ixVDit = _contiac->numFDse;
		refresh(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgBrlyLegNew::handleDpchAppDataContiacdet(
			DbsBrly* dbsbrly
			, ContIacDet* _contiacdet
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- IBEGIN

	ubigint ref;

	if (ixVSge == VecVSge::IDLE) {
		// validate numFPupTyp
		valid = (feedFDetPupTyp.getIxByNum(_contiacdet->numFPupTyp) != 0);
		if (valid) contiacdet.numFPupTyp = _contiacdet->numFPupTyp;
		else contiacdet.numFPupTyp = 0;

		if (valid) {
			// validate TxfBgn
			valid = dbsbrly->tblbrlymlocation->loadRefBySrf(_contiacdet->TxfBgn, ref);

			if (valid) contiacdet.TxfBgn = _contiacdet->TxfBgn;
			else contiacdet.TxfBgn = "";
		};

		if (valid) {
			// validate TxfEnd
			valid = dbsbrly->tblbrlymlocation->loadRefBySrf(_contiacdet->TxfEnd, ref);

			if (valid) contiacdet.TxfEnd = _contiacdet->TxfEnd;
			else contiacdet.TxfEnd = "";
		};

		refreshDet(dbsbrly, moditems);
	};

	// IP handleDpchAppDataContiacdet --- IEND
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgBrlyLegNew::handleDpchAppDoButDneClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
		xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButDneClick --- IEND
};

void DlgBrlyLegNew::handleDpchAppDoDetButCreClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoDetButCreClick --- BEGIN
	if (statshrdet.ButCreActive) {
		if (ixVSge == VecVSge::IDLE) {
			changeStage(dbsbrly, VecVSge::CREATE, dpcheng);
		};
	};
	// IP handleDpchAppDoDetButCreClick --- END
};

void DlgBrlyLegNew::handleDpchAppDoIncButRunClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoIncButRunClick --- BEGIN
	if (statshrinc.ButRunActive) {
		if (ixVSge == VecVSge::CREDONE) {
			changeStage(dbsbrly, VecVSge::INCO, dpcheng);
		};
	};
	// IP handleDpchAppDoIncButRunClick --- END
};

void DlgBrlyLegNew::handleDpchAppDoIncButStoClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoIncButStoClick --- INSERT
};

void DlgBrlyLegNew::handleTimer(
			DbsBrly* dbsbrly
			, const string& sref
		) {
	if ((ixVSge == VecVSge::INCO) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.inco.mon --- INSERT
	};
};


