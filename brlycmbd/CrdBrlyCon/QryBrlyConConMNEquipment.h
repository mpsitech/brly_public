/**
  * \file QryBrlyConConMNEquipment.h
  * job handler for job QryBrlyConConMNEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYCONCONMNEQUIPMENT_H
#define QRYBRLYCONCONMNEQUIPMENT_H

// IP custInclude --- INSERT

#define StatAppQryBrlyConConMNEquipment QryBrlyConConMNEquipment::StatApp
#define StatShrQryBrlyConConMNEquipment QryBrlyConConMNEquipment::StatShr
#define StgIacQryBrlyConConMNEquipment QryBrlyConConMNEquipment::StgIac

/**
  * QryBrlyConConMNEquipment
  */
class QryBrlyConConMNEquipment : public JobBrly {

public:
	/**
		* StatApp (full: StatAppQryBrlyConConMNEquipment)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 2, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryBrlyConConMNEquipment)
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
		* StgIac (full: StgIacQryBrlyConConMNEquipment)
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
	QryBrlyConConMNEquipment(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~QryBrlyConConMNEquipment();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQConConMNEquipment rst;

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
	BrlyQConConMNEquipment* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStubChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyConReqpMod_conEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

