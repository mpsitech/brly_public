/**
  * \file PnlBrlyUsrHeadbar.h
  * job handler for job PnlBrlyUsrHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYUSRHEADBAR_H
#define PNLBRLYUSRHEADBAR_H

// IP custInclude --- INSERT

#define StgInfBrlyUsrHeadbar PnlBrlyUsrHeadbar::StgInf
#define TagBrlyUsrHeadbar PnlBrlyUsrHeadbar::Tag

#define DpchEngBrlyUsrHeadbarData PnlBrlyUsrHeadbar::DpchEngData

/**
  * PnlBrlyUsrHeadbar
  */
class PnlBrlyUsrHeadbar : public JobBrly {

public:
	/**
		* StgInf (full: StgInfBrlyUsrHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagBrlyUsrHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngBrlyUsrHeadbarData)
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
	PnlBrlyUsrHeadbar(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyUsrHeadbar();

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

