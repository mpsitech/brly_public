/**
  * \file QryBrlyConMapLocation.h
  * job handler for job QryBrlyConMapLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYCONMAPLOCATION_H
#define QRYBRLYCONMAPLOCATION_H

// IP custInclude --- INSERT

#define StatShrQryBrlyConMapLocation QryBrlyConMapLocation::StatShr
#define StgIacQryBrlyConMapLocation QryBrlyConMapLocation::StgIac

/**
  * QryBrlyConMapLocation
  */
class QryBrlyConMapLocation : public JobBrly {

public:
	/**
		* StatShr (full: StatShrQryBrlyConMapLocation)
		*/
	class StatShr : public Block {

	public:
		static const uint NTOT = 1;

	public:
		StatShr(const uint ntot = 0);

	public:
		uint ntot;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryBrlyConMapLocation)
		*/
	class StgIac : public Block {

	public:
		static const uint JNUM = 1;

	public:
		StgIac(const uint jnum = 0);

	public:
		uint jnum;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

public:
	QryBrlyConMapLocation(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~QryBrlyConMapLocation();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQConMapLocation rst;

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
	BrlyQConMapLocation* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStubChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
};

#endif

