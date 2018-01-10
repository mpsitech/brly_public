/**
  * \file QryBrlySegOrgMNSegment.h
  * job handler for job QryBrlySegOrgMNSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYSEGORGMNSEGMENT_H
#define QRYBRLYSEGORGMNSEGMENT_H

// IP custInclude --- INSERT

#define StatAppQryBrlySegOrgMNSegment QryBrlySegOrgMNSegment::StatApp
#define StatShrQryBrlySegOrgMNSegment QryBrlySegOrgMNSegment::StatShr
#define StgIacQryBrlySegOrgMNSegment QryBrlySegOrgMNSegment::StgIac

/**
  * QryBrlySegOrgMNSegment
  */
class QryBrlySegOrgMNSegment : public JobBrly {

public:
	/**
		* StatApp (full: StatAppQryBrlySegOrgMNSegment)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 7, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryBrlySegOrgMNSegment)
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
		* StgIac (full: StgIacQryBrlySegOrgMNSegment)
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
	QryBrlySegOrgMNSegment(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~QryBrlySegOrgMNSegment();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQSegOrgMNSegment rst;

	uint ixBrlyVQrystate;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsBrly* dbsbrly, const bool call = false);
	void rerun_filtSQL(string& sqlstr, const int preTime, const double prePhi, const bool addwhere);
	void rerun_filtSQL_append(string& sqlstr, bool& first);

	void fetch(DbsBrly* dbsbrly);

	uint getJnumByRef(const ubigint ref);
	ubigint getRefByJnum(const uint jnum);
	BrlyQSegOrgMNSegment* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStubChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlySegRsegMod_osgEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

