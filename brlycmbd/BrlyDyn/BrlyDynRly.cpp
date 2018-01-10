/**
  * \file BrlyDynRly.cpp
  * Brly operation processor -  (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyopd.h>
#endif

#include "BrlyDynRly.h"

DpchRetBrly* BrlyDynRly::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDynRly* dpchinv
		) {
	ubigint refBrlyMConnection = dpchinv->refBrlyMConnection;

	bool success;

	// IP run --- IBEGIN
	BrlyMConnection* con = NULL;

	ubigint eqprefEnd;

	ListBrlyMEquipment eqps;
	BrlyMEquipment* eqp = NULL;

	map<ubigint, ubigint> eqprefsConLoc; // key: refLoc, value: refEqp

	ListBrlyRMConnectionMFlight conRflts;
	BrlyRMConnectionMFlight* conRflt = NULL;

	BrlyMFlight* flt = NULL;

	map<ubigint, ubigint> eqprefsConFlt; // key: refFlt, value: refEqp
	map<ubigint, unsigned int> startsConFlt;
	map<ubigint, unsigned int> stopsConFlt;

	ListBrlyLRMConnectionMEquipment conLReqps;
	BrlyLRMConnectionMEquipment* conLReqp = NULL;

	ListBrlyORMConnectionMEquipment ops;

	map<ubigint, Node*> nodes; // key: refEqp
	Node* node = NULL;

	list<ubigint> lineup; // concerns refEqp

	list<ubigint>::iterator pivotit;
	Node* pivotnode = NULL;

	unsigned int t;
	bool connected;
	unsigned int Nhop;
	unsigned int opix;

	ListBrlyMRelay rlys;
	BrlyMRelay* rly = NULL;

	ListBrlyMNode ndes;
	BrlyMNode* nde = NULL;

	dbsbrly->tblbrlymconnection->loadRecByRef(refBrlyMConnection, &con);

	// find connection flight's equipment
	dbsbrly->loadRefBySQL("SELECT refBrlyMEquipment FROM TblBrlyMFlight WHERE ref = " + to_string(con->refBrlyMFlight), eqprefEnd);

	// --- based on TblBrlyLRMConnectionMEquipment and TblBrlyRMConnectionMFlight, set up the allowable locations and flights as well as the initial node vector and list

	// - allowable location equipment
	dbsbrly->tblbrlymequipment->loadRstBySQL("SELECT TblBrlyMEquipment.* FROM TblBrlyMEquipment, TblBrlyLRMConnectionMEquipment WHERE TblBrlyLRMConnectionMEquipment.conRefBrlyMConnection = "
				+ to_string(refBrlyMConnection) + " AND TblBrlyMEquipment.ref = TblBrlyLRMConnectionMEquipment.refBrlyMEquipment AND TblBrlyMEquipment.hkIxVTbl = " + to_string(VecBrlyVMEquipmentHkTbl::LOC), false, eqps);

	for (unsigned int i=0;i<eqps.nodes.size();i++) {
		eqp = eqps.nodes[i];
		eqprefsConLoc[eqp->hkUref] = eqp->ref;
	};

	// - allowable flight equipment
	dbsbrly->tblbrlyrmconnectionmflight->loadRstByCon(refBrlyMConnection, false, conRflts);
	for (unsigned int i=0;i<conRflts.nodes.size();i++) {
		conRflt = conRflts.nodes[i];

		if (dbsbrly->tblbrlymflight->loadRecByRef(conRflt->refBrlyMFlight, &flt)) {
			eqprefsConFlt[flt->ref] = flt->refBrlyMEquipment;
			startsConFlt[flt->ref] = conRflt->x1Start;
			stopsConFlt[flt->ref] = conRflt->x1Stop;

			delete flt;
		};
	};

	// - initial line-up
	Brly::initEqplineup(dbsbrly, refBrlyMConnection, lineup, ops);

	// - one node per equipment
	dbsbrly->tblbrlylrmconnectionmequipment->loadRstByCon(refBrlyMConnection, false, conLReqps);
	for (unsigned int i=0;i<conLReqps.nodes.size();i++) {
		conLReqp = conLReqps.nodes[i];

		node = new Node(dbsbrly, con, eqprefsConLoc, eqprefsConFlt, startsConFlt, stopsConFlt, conLReqp->refBrlyMEquipment);
		nodes[conLReqp->refBrlyMEquipment] = node;
	};

/*
// dump node information
for (map<ubigint,Node*>::iterator it=nodes.begin() ; it!=nodes.end() ; it++) {
	node = it->second;

	cout << "node '" << StubBrly::getStubEqpShort(dbsbrly, node->eqpref) << "' visibility information:" << endl;
	for (map<ubigint,unsigned int>::iterator it2=node->eqprefsVstart.begin() ; it2!=node->eqprefsVstart.end() ; it2++) {
		cout << "\t" << StubBrly::getStubEqpShort(dbsbrly, it2->first) << "\t" << it2->second << "\t" << node->eqprefsVstop[it2->first] << endl;
	};
};
*/

	// --- determine possible relays starting from pivot node (corresponds to connection end point flight)
	if (findInList(lineup, eqprefEnd, pivotit)) {
		pivotnode = nodes[*pivotit];

		// -- evaluate forward
		t = con->start;
		opix = 0;

		while (t < con->stop) {
			// advance lineup to next t
			opix = Brly::advanceEqplineup(lineup, ops, opix, t);
			findInList(lineup, eqprefEnd, pivotit);

			pivotnode->resetTree(nodes, con->stop);
			connected = pivotnode->evalTree(nodes, lineup, pivotit, t, true);

///
//pivotnode->dump(dbsbrly, nodes, 0);
///

			// store linear path or tree in database
			dbsbrly->tblbrlymrelay->appendNewRecToRst(rlys, &rly, t, 0, con->ref, VecBrlyVMRelayDir::FWD, connected, 0);

			ndes.clear();
			t = con->stop;
			Nhop = 0;

			pivotnode->insertInDbs(dbsbrly, nodes, rly->ref, 0, 0, 1, ndes, t);

			// determine tree depth
			for (unsigned int i=0;i<ndes.nodes.size();i++) {
				nde = ndes.nodes[i];
				if (nde->supLvl > Nhop) Nhop = nde->supLvl;
			};

			rly->x1Stop = t-1;
			rly->Nhop = Nhop;
			dbsbrly->tblbrlymrelay->updateRec(rly);

			if (rly->x1Stop < rly->x1Start) {
				cout << "error: no advancement in forward calculation" << endl;
				break;
			};

			// t is not checked against operator x1Start's ; it is assumed that the relevant time stamps are included in the visibility evaluation
		};

		// -- re-init line-up and evaluate backward (same as forward except for direction)
		Brly::initEqplineup(dbsbrly, refBrlyMConnection, lineup, ops);

		t = con->start;
		opix = 0;

		while (t < con->stop) {
			// advance lineup to next t
			opix = Brly::advanceEqplineup(lineup, ops, opix, t);
			findInList(lineup, eqprefEnd, pivotit);

			pivotnode->resetTree(nodes, con->stop);
			connected = pivotnode->evalTree(nodes, lineup, pivotit, t, false);
			
			// store linear path or tree in database
			dbsbrly->tblbrlymrelay->appendNewRecToRst(rlys, &rly, t, 0, con->ref, VecBrlyVMRelayDir::BWD, connected, 0);

			ndes.clear();
			t = con->stop;
			Nhop = 0;

			pivotnode->insertInDbs(dbsbrly, nodes, rly->ref, 0, 0, 1, ndes, t);

			// determine tree depth
			for (unsigned int i=0;i<ndes.nodes.size();i++) {
				nde = ndes.nodes[i];
				if (nde->supLvl > Nhop) Nhop = nde->supLvl;
			};

			rly->x1Stop = t-1;
			rly->Nhop = Nhop;
			dbsbrly->tblbrlymrelay->updateRec(rly);

			if (rly->x1Stop < rly->x1Start) {
				cout << "error: no advancement in backward calculation" << endl;
				break;
			};

			// t is not checked against operator x1Start's ; it is assumed that the relevant time stamps are included in the visibility evaluation
		};
	};

	// --- clean up
	delete con;

	for (map<ubigint,Node*>::iterator it=nodes.begin() ; it!=nodes.end() ; it++) delete(it->second);
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
BrlyDynRly::Node::Node(
			DbsBrly* dbsbrly
			, const BrlyMConnection* con
			, map<ubigint, ubigint>& eqprefsConLoc
			, map<ubigint, ubigint>& eqprefsConFlt
			, map<ubigint, unsigned int>& startsConFlt
			, map<ubigint, unsigned int>& stopsConFlt
			, const ubigint refBrlyMEquipment
		) {
	vector<ubigint> refs;

	BrlyMEquipment* eqp = NULL;

	ListBrlyRMFlightMFlight fltRflts;
	BrlyRMFlightMFlight* fltRflt = NULL;

	ListBrlyRMFlightMLocation fltRlocs;
	BrlyRMFlightMLocation* fltRloc = NULL;

	unsigned int start, stop;

	eqpref = 0;
	fiber = false;

	relay = false;
	tNext = con->stop;

	eqprefUp = 0;
	eqprefDown = 0;

	if (dbsbrly->tblbrlymequipment->loadRecByRef(refBrlyMEquipment, &eqp)) {
		eqpref = eqp->ref;
		fiber = eqp->Fiber;

		// compile visibility information
		if (eqp->hkIxVTbl == VecBrlyVMEquipmentHkTbl::LOC) {
			// location: evaluate visloc and locflt ; add locations and flights which are part of the connection only, within their respective availability time span for the connection

			dbsbrly->tblbrlyvisrmlocationmlocation->loadOlosByDlo(eqp->hkUref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) {
				if (eqprefsConLoc.find(refs[i]) != eqprefsConLoc.end()) {
					eqprefsVstart[eqprefsConLoc[refs[i]]] = con->start;
					eqprefsVstop[eqprefsConLoc[refs[i]]] = con->stop;
				};
			};

			dbsbrly->tblbrlyrmflightmlocation->loadRstByLoc(eqp->hkUref, false, fltRlocs);
			for (unsigned int i=0;i<fltRlocs.nodes.size();i++) {
				fltRloc = fltRlocs.nodes[i];

				if (eqprefsConFlt.find(fltRloc->refBrlyMFlight) != eqprefsConFlt.end()) {
					start = startsConFlt[fltRloc->refBrlyMFlight];
					stop = stopsConFlt[fltRloc->refBrlyMFlight];

					if ((fltRloc->x1VisStop > start) && (fltRloc->x1VisStart < stop)) {
						eqprefsVstart[eqprefsConFlt[fltRloc->refBrlyMFlight]] = (fltRloc->x1VisStart < start) ? start : fltRloc->x1VisStart;
						eqprefsVstop[eqprefsConFlt[fltRloc->refBrlyMFlight]] = (fltRloc->x1VisStop < stop) ? fltRloc->x1VisStop : stop;
					};
				};
			};

		} else if (eqp->hkIxVTbl == VecBrlyVMEquipmentHkTbl::FLT) {
			// flight: evaluate locflt and fltflt ; add locations and flights which are part of the connection only, within their respective availability time span for the connection

			dbsbrly->tblbrlyrmflightmlocation->loadRstByFlt(eqp->hkUref, false, fltRlocs);
			for (unsigned int i=0;i<fltRlocs.nodes.size();i++) {
				fltRloc = fltRlocs.nodes[i];

				if (eqprefsConLoc.find(fltRloc->refBrlyMLocation) != eqprefsConLoc.end()) {
					start = startsConFlt[fltRloc->refBrlyMFlight];
					stop = stopsConFlt[fltRloc->refBrlyMFlight];

					if ((fltRloc->x1VisStop > con->start) && (fltRloc->x1VisStart < con->stop)) {
						eqprefsVstart[eqprefsConLoc[fltRloc->refBrlyMLocation]] = (fltRloc->x1VisStart < start) ? start : fltRloc->x1VisStart;
						eqprefsVstop[eqprefsConLoc[fltRloc->refBrlyMLocation]] = (fltRloc->x1VisStop < stop) ? fltRloc->x1VisStop : stop;
					};
				};
			};

			dbsbrly->tblbrlyrmflightmflight->loadRstByDfl(eqp->hkUref, false, fltRflts);
			for (unsigned int i=0;i<fltRflts.nodes.size();i++) {
				fltRflt = fltRflts.nodes[i];

				if (eqprefsConFlt.find(fltRflt->orgRefBrlyMFlight) != eqprefsConFlt.end()) {
					start = startsConFlt[fltRflt->orgRefBrlyMFlight];
					stop = stopsConFlt[fltRflt->orgRefBrlyMFlight];

					if ((fltRflt->x1VisStop > con->start) && (fltRflt->x1VisStart < con->stop)) {
						eqprefsVstart[eqprefsConFlt[fltRflt->orgRefBrlyMFlight]] = (fltRflt->x1VisStart < start) ? start : fltRflt->x1VisStart;
						eqprefsVstop[eqprefsConFlt[fltRflt->orgRefBrlyMFlight]] = (fltRflt->x1VisStop < stop) ? fltRflt->x1VisStop : stop;
					};
				};
			};
		};

		delete eqp;

	} else {
		eqpref = 0;
	};
};

bool BrlyDynRly::Node::evalTree(
			map<ubigint, Node*>& nodes
			, list<ubigint>& lineup
			, const list<ubigint>::iterator pivotit
			, const unsigned int t
			, const bool forward
		) {
	Node* node = NULL;

	list<ubigint>::iterator meit;
	list<ubigint>::iterator listit;

	bool mepassed;

	unsigned int vstart, vstop;

	// tree is assumed to be reset at this stage

	if (fiber) {
		relay = true;

	} else {
		// - set up down vector based on phi order at time t
		findInList(lineup, eqpref, meit);
		mepassed = false;

		if (forward) {
			for (listit=lineup.end() ; listit!=pivotit ; listit--) {
				// traverse and match to visibility information, most distant first
				if (listit == meit) {
					mepassed = true;

				} else {
					if (eqprefsVstart.find(*listit) != eqprefsVstart.end()) {
						vstart = eqprefsVstart[*listit];
						vstop = eqprefsVstop[*listit];

						if ((vstart <= t) && (vstop > t)) {
							node = nodes[*listit];

							if (!mepassed || node->fiber) {
								if (node->eqprefUp == 0) {
									node->eqprefUp = eqpref;
									eqprefsDown.push_back(*listit);
								} else {
									// down node already in reach of node with phi closer to the pivot node
								};
							};
						};
					};
				};
			};

		} else {
			// same as forward except for traverse order of lineup
			for (listit=lineup.begin() ; listit!=pivotit ; listit++) {
				// traverse and match to visibility information, most distant first
				if (listit == meit) {
					mepassed = true;

				} else {
					if (eqprefsVstart.find(*listit) != eqprefsVstart.end()) {
						vstart = eqprefsVstart[*listit];
						vstop = eqprefsVstop[*listit];

						if ((vstart <= t) && (vstop > t)) {
							node = nodes[*listit];

							if (!mepassed || node->fiber) {
								if (node->eqprefUp == 0) {
									node->eqprefUp = eqpref;
									eqprefsDown.push_back(*listit);
								} else {
									// down node already in reach of node with phi closer to the pivot node
								};
							};
						};
					};
				};
			};
		};

		// - recursively traverse down vector ; done when equipment with fiber access can be reached
		
		// first try: find closest equipment with fiber access in down vector
		for (unsigned int i=eqprefsDown.size();i>0;i--) {
			node = nodes[eqprefsDown[i-1]];

			if (node->fiber == true) {
				eqprefDown = eqprefsDown[i-1];
				relay = true;

				break;
			};
		};

		if (!relay) {
			// no success: run recursion
			for (unsigned int i=0;i<eqprefsDown.size();i++) {
				relay = nodes[eqprefsDown[i]]->evalTree(nodes, lineup, pivotit, t, forward);

				if (relay == true) {
					eqprefDown = eqprefsDown[i];
					break;
				};
			};
		};

		if (relay) {
			// determine time at which connection to next node breaks up
			tNext = eqprefsVstop[eqprefDown]+1;

		} else {
			// determine time when one of the down nodes loses visibility
			for (unsigned int i=0;i<eqprefsDown.size();i++) {
				vstop = eqprefsVstop[eqprefsDown[i]];
				if ((vstop+1) < tNext) tNext = vstop+1;
			};

			// determine time when next new node comes into visibility ; this includes the possibility that the concerned node is not part of lineup then
			for (map<ubigint,unsigned int>::iterator it=eqprefsVstart.begin() ; it!=eqprefsVstart.end() ; it++) {
				vstart = it->second;
				if ((vstart > t) && (vstart < tNext)) tNext = vstart;
			};
		};
	};

	return relay;
};

void BrlyDynRly::Node::resetTree(
			map<ubigint, Node*>& nodes
			, const unsigned int stop
		) {
	Node* node;

	for (unsigned int i=0;i<eqprefsDown.size();i++) {
		node = nodes[eqprefsDown[i]];
		node->resetTree(nodes, stop);
	};

	relay = false;
	tNext = stop;

	eqprefUp = 0;
	eqprefsDown.resize(0);
	eqprefDown = 0;
};

void BrlyDynRly::Node::insertInDbs(
			DbsBrly* dbsbrly
			, map<ubigint, Node*>& nodes
			, const ubigint refBrlyMRelay
			, const ubigint supRefBrlyMNode
			, const uint supLvl
			, const uint supNum
			, ListBrlyMNode& ndes
			, unsigned int& _tNext
		) {
	ubigint refNde;
	Node* node = NULL;

	refNde = dbsbrly->tblbrlymnode->appendNewRecToRst(ndes, NULL, refBrlyMRelay, supRefBrlyMNode, supLvl, supNum, eqpref);

	if (tNext != 0) if (tNext < _tNext) _tNext = tNext;

	if (eqprefDown != 0) {
		node = nodes[eqprefDown];
		node->insertInDbs(dbsbrly, nodes, refBrlyMRelay, refNde, supLvl+1, 1, ndes, _tNext);

	} else {
		// tree
		for (unsigned int i=0;i<eqprefsDown.size();i++) {
			node = nodes[eqprefsDown[i]];
			node->insertInDbs(dbsbrly, nodes, refBrlyMRelay, refNde, supLvl+1, (i+1), ndes, _tNext);
		};
	};
};

void BrlyDynRly::Node::dump(
			DbsBrly* dbsbrly
			, map<ubigint, Node*>& nodes
			, const unsigned int il
		) {
	for (unsigned int i=0;i<il;i++) cout << "\t";
	cout << StubBrly::getStubEqpShort(dbsbrly, eqpref) << "\t" << tNext << endl;
	for (unsigned int i=0;i<eqprefsDown.size();i++) nodes[eqprefsDown[i]]->dump(dbsbrly, nodes, il+1);
};

bool BrlyDynRly::findInList(
			list<ubigint>& l
			, const ubigint v
			, list<ubigint>::iterator& it
		) {
	for (it=l.begin() ; it!=l.end() ; it++) if (*it == v) break;

	if ( (it == l.end()) && (*it != v) ) return false;

	return true;
};
// IP cust --- IEND


