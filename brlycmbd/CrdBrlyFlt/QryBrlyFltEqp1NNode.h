/**
  * \file QryBrlyFltEqp1NNode.h
  * job handler for job QryBrlyFltEqp1NNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYFLTEQP1NNODE_H
#define QRYBRLYFLTEQP1NNODE_H

// IP custInclude --- INSERT

#define StatAppQryBrlyFltEqp1NNode QryBrlyFltEqp1NNode::StatApp
#define StatShrQryBrlyFltEqp1NNode QryBrlyFltEqp1NNode::StatShr
#define StgIacQryBrlyFltEqp1NNode QryBrlyFltEqp1NNode::StgIac

/**
  * QryBrlyFltEqp1NNode
  */
class QryBrlyFltEqp1NNode : public JobBrly {

public:
	/**
		* StatApp (full: StatAppQryBrlyFltEqp1NNode)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 1, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryBrlyFltEqp1NNode)
		*/
	class StatShr : public Block {

	public:
		static const uint NTOT = 1;
		static const uint JNUMFIRSTLOAD = 2;
		static const uint NLOAD = 3;

	public:
		StatShr(const uint ntot = 0, const uint jnumFirstload = 0, const uint nload = 0);

	public:
		uint ntot;
		uint jnumFirstload;
		uint nload;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryBrlyFltEqp1NNode)
		*/
	class StgIac : public Block {

	public:
		static const uint JNUM = 1;
		static const uint JNUMFIRSTLOAD = 2;
		static const uint NLOAD = 3;

	public:
		StgIac(const uint jnum = 0, const uint jnumFirstload = 1, const uint nload = 100);

	public:
		uint jnum;
		uint jnumFirstload;
		uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

public:
	QryBrlyFltEqp1NNode(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~QryBrlyFltEqp1NNode();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQFltEqp1NNode rst;

	uint ixBrlyVQrystate;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsBrly* dbsbrly, const bool call = false);

	void fetch(DbsBrly* dbsbrly);

	uint getJnumByRef(const ubigint ref);
	ubigint getRefByJnum(const uint jnum);
	BrlyQFltEqp1NNode* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStubChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyNdeMod_eqpEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

