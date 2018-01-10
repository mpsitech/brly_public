/**
  * \file DlgBrlyConNew.cpp
  * job handler for job DlgBrlyConNew (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "DlgBrlyConNew.h"

#include "DlgBrlyConNew_blks.cpp"
#include "DlgBrlyConNew_evals.cpp"

/******************************************************************************
 class DlgBrlyConNew
 ******************************************************************************/

DlgBrlyConNew::DlgBrlyConNew(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::DLGBRLYCONNEW, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	feedFDetPupMdl.tag = "FeedFDetPupMdl";
	VecBrlyVMConnectionModel::fillFeed(ixBrlyVLocale, feedFDetPupMdl);
	feedFDetPupTtb.tag = "FeedFDetPupTtb";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixBrlyVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	ListBrlyMTimetable ttbs;
	BrlyMTimetable* ttb = NULL;

	dbsbrly->tblbrlymtimetable->loadRstBySQL("SELECT * FROM TblBrlyMTimetable ORDER BY Title ASC", false, ttbs);
	for (unsigned int i=0;i<ttbs.nodes.size();i++) {
		ttb = ttbs.nodes[i];
		feedFDetPupTtb.appendRefTitles(ttb->ref, StubBrly::getStubTtbStd(dbsbrly, ttb->ref, ixBrlyVLocale, Stub::VecVNonetype::DASH));
	};
	// IP constructor.cust1 --- IEND

	ixVDit = VecVDit::DET;

	valid = false;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgBrlyConNew::~DlgBrlyConNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngBrly* DlgBrlyConNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &continfcal, &feedFDetPupMdl, &feedFDetPupTtb, &feedFDse, &feedFSge, &statshr, &statshrcal, &statshrdet, items);
	};

	return dpcheng;
};

void DlgBrlyConNew::refreshDet(
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

void DlgBrlyConNew::refreshCal(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInfCal oldContinfcal(continfcal);
	StatShrCal oldStatshrcal(statshrcal);

	// IP refreshCal --- RBEGIN
	// continfcal
	continfcal.TxtPrg = getSquawk(dbsbrly);

	// statshrcal
	statshrcal.ButRunActive = evalCalButRunActive(dbsbrly);
	statshrcal.ButStoActive = evalCalButStoActive(dbsbrly);

	// IP refreshCal --- REND
	if (continfcal.diff(&oldContinfcal).size() != 0) insert(moditems, DpchEngData::CONTINFCAL);
	if (statshrcal.diff(&oldStatshrcal).size() != 0) insert(moditems, DpchEngData::STATSHRCAL);
};

void DlgBrlyConNew::refresh(
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
	refreshCal(dbsbrly, moditems);
};

void DlgBrlyConNew::changeStage(
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
				case VecVSge::CALC1: leaveSgeCalc1(dbsbrly); break;
				case VecVSge::CALC2: leaveSgeCalc2(dbsbrly); break;
				case VecVSge::CALC3: leaveSgeCalc3(dbsbrly); break;
				case VecVSge::CALC4: leaveSgeCalc4(dbsbrly); break;
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
			case VecVSge::CALC1: _ixVSge = enterSgeCalc1(dbsbrly, reenter); break;
			case VecVSge::CALC2: _ixVSge = enterSgeCalc2(dbsbrly, reenter); break;
			case VecVSge::CALC3: _ixVSge = enterSgeCalc3(dbsbrly, reenter); break;
			case VecVSge::CALC4: _ixVSge = enterSgeCalc4(dbsbrly, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint DlgBrlyConNew::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
	// IP enterSgeIdle --- IEND
	return retval;
};

void DlgBrlyConNew::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgBrlyConNew::enterSgeCreate(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CREATE;
	nextIxVSge = VecVSge::CREDONE;
	// IP enterSgeCreate --- IBEGIN

	BrlyMConnection con;

	BrlyMFlight* flt = NULL;
	BrlyMLeg* leg = NULL;

	Feeditem* fi = NULL;

	dbsbrly->tblbrlymflight->loadRecBySQL("SELECT * FROM TblBrlyMFlight WHERE sref = '" + contiacdet.TxfFlt + "'", &flt);
	con.refBrlyMFlight = flt->ref;

	// find communication corridor
	dbsbrly->tblbrlymleg->loadRecBySQL("SELECT * FROM TblBrlyMLeg WHERE ref = " + to_string(flt->refBrlyMLeg), &leg);

	dbsbrly->loadRefBySQL("SELECT ref FROM TblBrlyMLeg WHERE ixVBasetype = " + to_string(VecBrlyVMLegBasetype::CORR) + " AND bgnRefBrlyMLocation = "
				+ to_string(leg->bgnRefBrlyMLocation) + " AND endRefBrlyMLocation = " + to_string(leg->endRefBrlyMLocation), con.corRefBrlyMLeg);

	delete leg;

	con.start = flt->start;
	con.stop = flt->stop;

	con.ixVModel = feedFDetPupMdl.getByNum(contiacdet.numFPupMdl)->ix;

	fi = feedFDetPupTtb.getByNum(contiacdet.numFPupTtb);
	if (fi) con.refBrlyMTimetable = fi->ref; else con.refBrlyMTimetable = 0;

	con.srefsBrlyKEqptype = contiacdet.TxfEty;

	delete flt;

	dbsbrly->tblbrlymconnection->insertRec(&con);

	xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYCONMOD, jref);
	xchg->triggerIxRefCall(dbsbrly, VecBrlyVCall::CALLBRLYREFPRESET, jref, VecBrlyVPreset::PREBRLYREFCON, con.ref);

	// IP enterSgeCreate --- IEND
	retval = nextIxVSge;
	return retval;
};

void DlgBrlyConNew::leaveSgeCreate(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgBrlyConNew::enterSgeCredone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CREDONE;
	nextIxVSge = retval;
	// IP enterSgeCredone --- INSERT
	return retval;
};

void DlgBrlyConNew::leaveSgeCredone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCredone --- INSERT
};

uint DlgBrlyConNew::enterSgeCalc1(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CALC1;
	nextIxVSge = VecVSge::CALC2;

	clearInvs();
	// IP enterSgeCalc1 --- IBEGIN
	addInv(new DpchInvBrlyDynConflt(0, 0, xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref)));
	// IP enterSgeCalc1 --- IEND
	submitInvs(dbsbrly, VecVSge::CREDONE, retval);
	return retval;
};

void DlgBrlyConNew::leaveSgeCalc1(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCalc1 --- IBEGIN
	invalidateWakeups();
	// IP leaveSgeCalc1 --- IEND
};

uint DlgBrlyConNew::enterSgeCalc2(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CALC2;
	nextIxVSge = VecVSge::CALC3;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeCalc2 --- IBEGIN

	// invoke BrlyDynFltfltloc for each flight not yet calculated
	ListBrlyRMConnectionMFlight crfs;
	BrlyRMConnectionMFlight* crf = NULL;

	BrlyMFlight* flt = NULL;

	vector<ubigint> refs;

	dbsbrly->tblbrlyrmconnectionmflight->loadRstByCon(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref), false, crfs);
	for (unsigned int i=0;i<crfs.nodes.size();i++) {
		crf = crfs.nodes[i];

		// block size: 256
		if (dbsbrly->tblbrlymflight->loadRecByRef(crf->refBrlyMFlight, &flt)) {
			if (flt->Calcdone == false) refs.push_back(flt->ref);

			if (refs.size() == 256) {
				addInv(new DpchInvBrlyDynFltfltloc(0, 0, refs));
				refs.resize(0);
			};

			delete flt;
		};
	};

	if (refs.size() != 0) addInv(new DpchInvBrlyDynFltfltloc(0, 0, refs));

	// IP enterSgeCalc2 --- IEND
	submitInvs(dbsbrly, VecVSge::CALC3, retval);
	return retval;
};

void DlgBrlyConNew::leaveSgeCalc2(
			DbsBrly* dbsbrly
		) {
	invalidateWakeups();
	// IP leaveSgeCalc2 --- IBEGIN
	ListBrlyRMConnectionMFlight crfs;
	BrlyRMConnectionMFlight* crf = NULL;

	BrlyMFlight* flt = NULL;

	dbsbrly->tblbrlyrmconnectionmflight->loadRstByCon(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref), false, crfs);
	for (unsigned int i=0;i<crfs.nodes.size();i++) {
		crf = crfs.nodes[i];

		if (dbsbrly->tblbrlymflight->loadRecByRef(crf->refBrlyMFlight, &flt)) {
			if (flt->Calcdone == false) {
				flt->Calcdone = true;
				dbsbrly->tblbrlymflight->updateRec(flt);
			};
			delete flt;
		};
	};
	// IP leaveSgeCalc2 --- IEND
};

uint DlgBrlyConNew::enterSgeCalc3(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CALC3;
	nextIxVSge = VecVSge::CALC4;

	clearInvs();
	// IP enterSgeCalc3 --- IBEGIN
	addInv(new DpchInvBrlyDynEqplist(0, 0, xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref)));
	// IP enterSgeCalc3 --- IEND
	submitInvs(dbsbrly, retval, retval);
	return retval;
};

void DlgBrlyConNew::leaveSgeCalc3(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCalc3 --- INSERT
};

uint DlgBrlyConNew::enterSgeCalc4(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CALC4;
	nextIxVSge = VecVSge::DONE;

	clearInvs();
	// IP enterSgeCalc4 --- IBEGIN
	addInv(new DpchInvBrlyDynRly(0, 0, xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref)));
	// IP enterSgeCalc4 --- IEND
	submitInvs(dbsbrly, retval, retval);
	return retval;
};

void DlgBrlyConNew::leaveSgeCalc4(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCalc4 --- INSERT
};

uint DlgBrlyConNew::enterSgeDone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
	// IP enterSgeDone --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
	// IP enterSgeDone --- IEND
	return retval;
};

void DlgBrlyConNew::leaveSgeDone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeDone --- INSERT
};

string DlgBrlyConNew::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::CREDONE) || (ixVSge == VecVSge::CALC1) || (ixVSge == VecVSge::CALC2) || (ixVSge == VecVSge::CALC3) || (ixVSge == VecVSge::CALC4) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::CREDONE) retval = "new connection created";
			else if (ixVSge == VecVSge::CALC1) retval = "determining relevant flights";
			else if (ixVSge == VecVSge::CALC2) retval = "calculating flight visibility (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC3) retval = "calculating equipment line-up";
			else if (ixVSge == VecVSge::CALC4) retval = "calculating relays";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::CREDONE) retval = "neue Verbindung erstellt";
			else if (ixVSge == VecVSge::CALC1) retval = "bestimme relevante Fl\\u00fcge";
			else if (ixVSge == VecVSge::CALC2) retval = "berechne Sichtbarkeit von Fl\\u00fcgen (" + to_string(opNdone) + "/" + to_string(opN) + " Operationen ausgef\\u00fchrt, letzte: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC3) retval = "berechne Aufreihung von Ger\\u00e4t";
			else if (ixVSge == VecVSge::CALC4) retval = "berechne Verbindungsketten";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

void DlgBrlyConNew::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYCONNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbsbrly, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYCONNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsbrly, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoCal != 0) {
				if (dpchappdo->ixVDoCal == VecVDoCal::BUTRUNCLICK) {
					handleDpchAppDoCalButRunClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDoCal == VecVDoCal::BUTSTOCLICK) {
					handleDpchAppDoCalButStoClick(dbsbrly, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoDet != 0) {
				if (dpchappdo->ixVDoDet == VecVDoDet::BUTCRECLICK) {
					handleDpchAppDoDetButCreClick(dbsbrly, &(req->dpcheng));
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

void DlgBrlyConNew::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgBrlyConNew::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::CAL)) ixVDit = _contiac->numFDse;
		refresh(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgBrlyConNew::handleDpchAppDataContiacdet(
			DbsBrly* dbsbrly
			, ContIacDet* _contiacdet
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- IBEGIN

	ubigint ref;

	vector<string> ss;

	if (ixVSge == VecVSge::IDLE) {
		// validate TxfFlt
		valid = (_contiacdet->TxfFlt.length() != 0);
		if (valid) valid = dbsbrly->loadRefBySQL("SELECT ref FROM TblBrlyMFlight WHERE sref = '" + _contiacdet->TxfFlt + "'", ref);

		if (valid) contiacdet.TxfFlt = _contiacdet->TxfFlt;
		else contiacdet.TxfFlt = "";

		if (valid) {
			// validate numFPupMdl
			valid = (feedFDetPupMdl.getIxByNum(_contiacdet->numFPupMdl) != 0);
			if (valid) contiacdet.numFPupMdl = _contiacdet->numFPupMdl;
			else contiacdet.numFPupMdl = 0;
		};
		
		if (valid) {
			// validate numFPupTtb
			valid = (feedFDetPupTtb.getRefByNum(_contiacdet->numFPupTtb) != 0);
			if (valid) contiacdet.numFPupTtb = _contiacdet->numFPupTtb;
			else contiacdet.numFPupTtb = 0;
		};

		if (valid) {
			// validate TxfEty
			StrMod::stringToVector(_contiacdet->TxfEty, ss);

			for (unsigned int i=0;i<ss.size();i++) {
				valid = dbsbrly->loadRefBySQL("SELECT ref FROM TblBrlyAVKeylistKey WHERE klsIxBrlyVKeylist = " + to_string(VecBrlyVKeylist::KLSTBRLYKEQPTYPE) + " AND sref = '" + ss[i] + "'", ref);
				if (!valid) break;
			};

			if (valid) contiacdet.TxfEty = _contiacdet->TxfEty;
			else contiacdet.TxfEty = "";
		};
	};

	refresh(dbsbrly, moditems);

	// IP handleDpchAppDataContiacdet --- IEND
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgBrlyConNew::handleDpchAppDoButDneClick(
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

void DlgBrlyConNew::handleDpchAppDoCalButRunClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoCalButRunClick --- BEGIN
	if (statshrcal.ButRunActive) {
		if (ixVSge == VecVSge::CREDONE) {
			changeStage(dbsbrly, VecVSge::CALC1, dpcheng);
		};
	};
	// IP handleDpchAppDoCalButRunClick --- END
};

void DlgBrlyConNew::handleDpchAppDoCalButStoClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoCalButStoClick --- INSERT
};

void DlgBrlyConNew::handleDpchAppDoDetButCreClick(
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

void DlgBrlyConNew::handleTimer(
			DbsBrly* dbsbrly
			, const string& sref
		) {
	if ((ixVSge == VecVSge::CALC2) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.calc2.mon --- INSERT
	};
};


