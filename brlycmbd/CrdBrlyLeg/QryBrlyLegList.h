/**
  * \file QryBrlyLegList.h
  * job handler for job QryBrlyLegList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYLEGLIST_H
#define QRYBRLYLEGLIST_H

// IP custInclude --- INSERT

#define VecVQryBrlyLegListOrd QryBrlyLegList::VecVOrd

#define StatAppQryBrlyLegList QryBrlyLegList::StatApp
#define StatShrQryBrlyLegList QryBrlyLegList::StatShr
#define StgIacQryBrlyLegList QryBrlyLegList::StgIac

/**
  * QryBrlyLegList
  */
class QryBrlyLegList : public JobBrly {

public:
	/**
		* VecVOrd (full: VecVQryBrlyLegListOrd)
		*/
	class VecVOrd {

	public:
		static const uint BLO = 1;
		static const uint ELO = 2;
		static const uint TYP = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryBrlyLegList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 5, const uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryBrlyLegList)
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
		* StgIac (full: StgIacQryBrlyLegList)
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
	QryBrlyLegList(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~QryBrlyLegList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQLegList rst;

	uint ixBrlyVQrystate;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsBrly* dbsbrly, const bool call = false);
	void rerun_filtSQL(string& sqlstr, const ubigint preBlo, const ubigint preElo, const uint preTyp, const bool addwhere);
	void rerun_filtSQL_append(string& sqlstr, bool& first);
	void rerun_orderSQL(string& sqlstr, const uint preIxOrd);

	void fetch(DbsBrly* dbsbrly);

	uint getJnumByRef(const ubigint ref);
	ubigint getRefByJnum(const uint jnum);
	BrlyQLegList* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStubChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyLegMod(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyLegUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

