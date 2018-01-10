/**
  * \file PnlBrlyNavHeadbar.h
  * job handler for job PnlBrlyNavHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYNAVHEADBAR_H
#define PNLBRLYNAVHEADBAR_H

// IP custInclude --- INSERT

#define StatShrBrlyNavHeadbar PnlBrlyNavHeadbar::StatShr
#define StgInfBrlyNavHeadbar PnlBrlyNavHeadbar::StgInf
#define TagBrlyNavHeadbar PnlBrlyNavHeadbar::Tag

#define DpchEngBrlyNavHeadbarData PnlBrlyNavHeadbar::DpchEngData

/**
  * PnlBrlyNavHeadbar
  */
class PnlBrlyNavHeadbar : public JobBrly {

public:
	/**
		* StatShr (full: StatShrBrlyNavHeadbar)
		*/
	class StatShr : public Block {

	public:
		static const uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgInf (full: StgInfBrlyNavHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagBrlyNavHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngBrlyNavHeadbarData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint STATSHR = 2;
		static const uint STGINF = 3;
		static const uint TAG = 4;
		static const uint ALL = 5;

	public:
		DpchEngData(const ubigint jref = 0, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalMenCrdAvail(DbsBrly* dbsbrly);
	bool evalMspCrd1Avail(DbsBrly* dbsbrly);
	bool evalMitCrdUsgAvail(DbsBrly* dbsbrly);
	bool evalMitCrdUsrAvail(DbsBrly* dbsbrly);
	bool evalMitCrdPrsAvail(DbsBrly* dbsbrly);
	bool evalMitCrdFilAvail(DbsBrly* dbsbrly);
	bool evalMitCrdOprAvail(DbsBrly* dbsbrly);
	bool evalMitCrdPtyAvail(DbsBrly* dbsbrly);
	bool evalMspCrd2Avail(DbsBrly* dbsbrly);
	bool evalMitCrdRegAvail(DbsBrly* dbsbrly);
	bool evalMitCrdLocAvail(DbsBrly* dbsbrly);
	bool evalMitCrdLegAvail(DbsBrly* dbsbrly);
	bool evalMitCrdTtbAvail(DbsBrly* dbsbrly);
	bool evalMitCrdFltAvail(DbsBrly* dbsbrly);
	bool evalMspCrd3Avail(DbsBrly* dbsbrly);
	bool evalMitCrdConAvail(DbsBrly* dbsbrly);

public:
	PnlBrlyNavHeadbar(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyNavHeadbar();

public:
	StatShr statshr;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

};

#endif

