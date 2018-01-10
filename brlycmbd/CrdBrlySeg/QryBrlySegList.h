/**
  * \file QryBrlySegList.h
  * job handler for job QryBrlySegList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYSEGLIST_H
#define QRYBRLYSEGLIST_H

// IP custInclude --- INSERT

#define VecVQryBrlySegListOrd QryBrlySegList::VecVOrd

#define StatAppQryBrlySegList QryBrlySegList::StatApp
#define StatShrQryBrlySegList QryBrlySegList::StatShr
#define StgIacQryBrlySegList QryBrlySegList::StgIac

/**
  * QryBrlySegList
  */
class QryBrlySegList : public JobBrly {

public:
	/**
		* VecVOrd (full: VecVQryBrlySegListOrd)
		*/
	class VecVOrd {

	public:
		static const uint RET = 1;
		static const uint REU = 2;
		static const uint STA = 3;
		static const uint STO = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryBrlySegList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 11, const uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryBrlySegList)
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
		* StgIac (full: StgIacQryBrlySegList)
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
	QryBrlySegList(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~QryBrlySegList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQSegList rst;

	uint ixBrlyVQrystate;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsBrly* dbsbrly, const bool call = false);
	void rerun_baseSQL(string& sqlstr);
	void rerun_filtSQL(string& sqlstr, const uint preRet, const ubigint preReu, const int preSta, const int preSto, const bool addwhere);
	void rerun_filtSQL_append(string& sqlstr, bool& first);
	void rerun_orderSQL(string& sqlstr, const uint preIxOrd);

	void fetch(DbsBrly* dbsbrly);

	uint getJnumByRef(const ubigint ref);
	ubigint getRefByJnum(const uint jnum);
	BrlyQSegList* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStubChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlySegMod(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlySegUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

