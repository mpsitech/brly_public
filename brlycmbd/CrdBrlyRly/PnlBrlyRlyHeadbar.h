/**
  * \file PnlBrlyRlyHeadbar.h
  * job handler for job PnlBrlyRlyHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYRLYHEADBAR_H
#define PNLBRLYRLYHEADBAR_H

// IP custInclude --- INSERT

#define StgInfBrlyRlyHeadbar PnlBrlyRlyHeadbar::StgInf
#define TagBrlyRlyHeadbar PnlBrlyRlyHeadbar::Tag

#define DpchEngBrlyRlyHeadbarData PnlBrlyRlyHeadbar::DpchEngData

/**
  * PnlBrlyRlyHeadbar
  */
class PnlBrlyRlyHeadbar : public JobBrly {

public:
	/**
		* StgInf (full: StgInfBrlyRlyHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagBrlyRlyHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngBrlyRlyHeadbarData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint STGINF = 2;
		static const uint TAG = 3;
		static const uint ALL = 4;

	public:
		DpchEngData(const ubigint jref = 0, const set<uint>& mask = {NONE});

	public:

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	PnlBrlyRlyHeadbar(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyRlyHeadbar();

public:

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

