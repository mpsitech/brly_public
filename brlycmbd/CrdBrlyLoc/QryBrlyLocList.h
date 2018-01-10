/**
  * \file QryBrlyLocList.h
  * job handler for job QryBrlyLocList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYLOCLIST_H
#define QRYBRLYLOCLIST_H

// IP custInclude --- INSERT

#define VecVQryBrlyLocListOrd QryBrlyLocList::VecVOrd

#define StatAppQryBrlyLocList QryBrlyLocList::StatApp
#define StatShrQryBrlyLocList QryBrlyLocList::StatShr
#define StgIacQryBrlyLocList QryBrlyLocList::StgIac

/**
  * QryBrlyLocList
  */
class QryBrlyLocList : public JobBrly {

public:
	/**
		* VecVOrd (full: VecVQryBrlyLocListOrd)
		*/
	class VecVOrd {

	public:
		static const uint SRF = 1;
		static const uint ICA = 2;
		static const uint TIT = 3;
		static const uint TYP = 4;
		static const uint REG = 5;
		static const uint EQP = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryBrlyLocList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 10, const uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryBrlyLocList)
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
		* StgIac (full: StgIacQryBrlyLocList)
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
	QryBrlyLocList(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~QryBrlyLocList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQLocList rst;

	uint ixBrlyVQrystate;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsBrly* dbsbrly, const bool call = false);
	void rerun_filtSQL(string& sqlstr, const string& preSrf, const string& preIca, const string& preTit, const uint preTyp, const ubigint preReg, const ubigint preEqp, const bool addwhere);
	void rerun_filtSQL_append(string& sqlstr, bool& first);
	void rerun_orderSQL(string& sqlstr, const uint preIxOrd);

	void fetch(DbsBrly* dbsbrly);

	uint getJnumByRef(const ubigint ref);
	ubigint getRefByJnum(const uint jnum);
	BrlyQLocList* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStubChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyLocMod(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyLocUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

