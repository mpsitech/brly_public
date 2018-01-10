/**
  * \file QryBrlyConMapNode.cpp
  * job handler for job QryBrlyConMapNode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "QryBrlyConMapNode.h"

#include "QryBrlyConMapNode_blks.cpp"

/******************************************************************************
 class QryBrlyConMapNode
 ******************************************************************************/

QryBrlyConMapNode::QryBrlyConMapNode(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::QRYBRLYCONMAPNODE, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyConMapNode::~QryBrlyConMapNode() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryBrlyConMapNode::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyConMapNode::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	ubigint preRefCon = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqconmapnode->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblBrlyQConMapNode(qwr, jref, jnum, ref, refBrlyMRelay, supRefBrlyMNode, refBrlyMEquipment)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblBrlyMNode.ref, TblBrlyMNode.refBrlyMRelay, TblBrlyMNode.supRefBrlyMNode, TblBrlyMNode.refBrlyMEquipment";
	sqlstr += " FROM TblBrlyMNode, TblBrlyMRelay";
	sqlstr += " WHERE TblBrlyMRelay.refBrlyMConnection = " + to_string(preRefCon) + "";
	sqlstr += " AND TblBrlyMNode.refBrlyMRelay = TblBrlyMRelay.ref";
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQConMapNode SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyConMapNode::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQConMapNode* rec = NULL;

	dbsbrly->tblbrlyqconmapnode->loadRstByJref(jref, false, rst);

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = i+1;
			rec->stubRef = StubBrly::getStubNdeStd(dbsbrly, rec->ref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyConMapNode", "fetch");
	};

	refreshJnum();
};

uint QryBrlyConMapNode::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQConMapNode* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyConMapNode::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQConMapNode* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQConMapNode* QryBrlyConMapNode::getRecByJnum(
			const uint jnum
		) {
	BrlyQConMapNode* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyConMapNode::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\trerun" << endl;
			cout << "\tshow" << endl;
		} else if (req->cmd == "rerun") {
			req->retain = handleRerun(dbsbrly);

		} else if (req->cmd == "show") {
			req->retain = handleShow(dbsbrly);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
	};
};

bool QryBrlyConMapNode::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	rerun(dbsbrly);
	return retval;
};

bool QryBrlyConMapNode::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQConMapNode* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << "\trefBrlyMRelay";
	cout << "\tsupRefBrlyMNode";
	cout << "\trefBrlyMEquipment";
	cout << "\tjnumRly";
	cout << "\tx0";
	cout << "\ty0";
	cout << "\tu0";
	cout << "\tv0";
	cout << "\tt0";
	cout << "\tdx";
	cout << "\tdy";
	cout << "\tdu";
	cout << "\tdv";
	cout << "\tdt";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->qwr;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << "\t" << rec->refBrlyMRelay;
		cout << "\t" << rec->supRefBrlyMNode;
		cout << "\t" << rec->refBrlyMEquipment;
		cout << "\t" << rec->jnumRly;
		cout << "\t" << rec->x0;
		cout << "\t" << rec->y0;
		cout << "\t" << rec->u0;
		cout << "\t" << rec->v0;
		cout << "\t" << rec->t0;
		cout << "\t" << rec->dx;
		cout << "\t" << rec->dy;
		cout << "\t" << rec->du;
		cout << "\t" << rec->dv;
		cout << "\t" << rec->dt;
		cout << endl;
	};
	return retval;
};

void QryBrlyConMapNode::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) {
		call->abort = handleCallBrlyStubChg(dbsbrly, call->jref);
	};
};

bool QryBrlyConMapNode::handleCallBrlyStubChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (ixBrlyVQrystate == VecBrlyVQrystate::UTD) {
		ixBrlyVQrystate = VecBrlyVQrystate::SLM;
		xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);
	};

	return retval;
};

