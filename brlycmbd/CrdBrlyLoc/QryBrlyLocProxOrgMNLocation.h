/**
  * \file QryBrlyLocProxOrgMNLocation.h
  * job handler for job QryBrlyLocProxOrgMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYLOCPROXORGMNLOCATION_H
#define QRYBRLYLOCPROXORGMNLOCATION_H

// IP custInclude --- INSERT

#define StatAppQryBrlyLocProxOrgMNLocation QryBrlyLocProxOrgMNLocation::StatApp
#define StatShrQryBrlyLocProxOrgMNLocation QryBrlyLocProxOrgMNLocation::StatShr
#define StgIacQryBrlyLocProxOrgMNLocation QryBrlyLocProxOrgMNLocation::StgIac

/**
  * QryBrlyLocProxOrgMNLocation
  */
class QryBrlyLocProxOrgMNLocation : public JobBrly {

public:
	/**
		* StatApp (full: StatAppQryBrlyLocProxOrgMNLocation)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 2, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryBrlyLocProxOrgMNLocation)
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
		* StgIac (full: StgIacQryBrlyLocProxOrgMNLocation)
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
	QryBrlyLocProxOrgMNLocation(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~QryBrlyLocProxOrgMNLocation();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQLocProxOrgMNLocation rst;

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
	BrlyQLocProxOrgMNLocation* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStubChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyPlocRlocMod_oloEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

