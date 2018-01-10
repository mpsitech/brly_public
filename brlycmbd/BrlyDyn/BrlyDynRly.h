/**
  * \file BrlyDynRly.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDYNRLY_H
#define BRLYDYNRLY_H

#include "BrlyDyn.h"

using namespace BrlyDyn;

// IP incl --- INSERT

namespace BrlyDynRly {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynRly* dpchinv);
	// IP cust --- IBEGIN

	/**
		* BrlyDynRly::Node
		*/
	class Node {

	public:
		// time-invariant properties
		ubigint eqpref;
		bool fiber;

		// time-varying properties
		bool relay; // true: node is part of established relay
		unsigned int tNext; // concerns start / stop of visibility only

		// connection tree
		ubigint eqprefUp;
		vector<ubigint> eqprefsDown;
		ubigint eqprefDown;

		// connectivity information (known upfront)
		map<ubigint, unsigned int> eqprefsVstart;
		map<ubigint, unsigned int> eqprefsVstop;

	public:
		Node(DbsBrly* dbsbrly, const BrlyMConnection* con, map<ubigint, ubigint>& eqprefsConLoc, map<ubigint, ubigint>& eqprefsConFlt, map<ubigint, unsigned int>& startsConFlt, map<ubigint, unsigned int>& stopsConFlt, const ubigint refBrlyMEquipment);

		// recursion method for establishing the connection tree
		bool evalTree(map<ubigint, Node*>& nodes, list<ubigint>& lineup, const list<ubigint>::iterator pivotit, const unsigned int t, const bool forward);
		void resetTree(map<ubigint, Node*>& nodes, const unsigned int stop);
		void insertInDbs(DbsBrly* dbsbrly, map<ubigint, Node*>& nodes, const ubigint refBrlyMRelay, const ubigint supRefBrlyMNode, const uint supLvl, const uint supNum, ListBrlyMNode& ndes, unsigned int& _tNext);

		void dump(DbsBrly* dbsbrly, map<ubigint, Node*>& nodes, const unsigned int il);
	};

	bool findInList(list<ubigint>& l, const ubigint v, list<ubigint>::iterator& it);
	void insertInDbs(DbsBrly* dbsbrly, map<ubigint, Node*>& nodes, const ubigint refBrlyMRelay, const ubigint supRefBrlyMNode, const uint supLvl, const uint supNum, ListBrlyMNode& ndes, unsigned int& _tNext);
	// IP cust --- IEND
};

#endif


