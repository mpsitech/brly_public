/**
  * \file CrdBrlyPrs.h
  * job handler for job CrdBrlyPrs (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef CRDBRLYPRS_H
#define CRDBRLYPRS_H

// IP custInclude --- INSERT

#include "PnlBrlyPrsRec.h"
#include "PnlBrlyPrsHeadbar.h"
#include "PnlBrlyPrsList.h"

#define VecVBrlyPrsDo CrdBrlyPrs::VecVDo
#define VecVBrlyPrsSge CrdBrlyPrs::VecVSge

#define ContInfBrlyPrs CrdBrlyPrs::ContInf
#define StatAppBrlyPrs CrdBrlyPrs::StatApp
#define StatShrBrlyPrs CrdBrlyPrs::StatShr
#define TagBrlyPrs CrdBrlyPrs::Tag

#define DpchAppBrlyPrsDo CrdBrlyPrs::DpchAppDo
#define DpchEngBrlyPrsData CrdBrlyPrs::DpchEngData

/**
  * CrdBrlyPrs
  */
class CrdBrlyPrs : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyPrsDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyPrsSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRBRLYABT = 2;
		static const uint CLOSE = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContInf (full: ContInfBrlyPrs)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDPRS = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdPrs = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdPrs;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyPrs)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrBrlyPrs)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFHEADBAR = 1;
		static const uint JREFLIST = 2;
		static const uint JREFREC = 3;

	public:
		StatShr(const ubigint jrefHeadbar = 0, const ubigint jrefList = 0, const ubigint jrefRec = 0);

	public:
		ubigint jrefHeadbar;
		ubigint jrefList;
		ubigint jrefRec;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyPrs)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyPrsDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngBrlyPrsData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFSGE = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;
		static const uint ALL = 7;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	CrdBrlyPrs(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale, const ubigint ref = 0);
	~CrdBrlyPrs();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	PnlBrlyPrsRec* pnlrec;
	PnlBrlyPrsHeadbar* pnlheadbar;
	PnlBrlyPrsList* pnllist;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);
	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);
	void changeRef(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint ref, const bool notif = false);
	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:
	void changeStage(DbsBrly* dbsbrly, uint _ixVSge, DpchEngBrly** dpcheng = NULL);

	uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	uint enterSgeAlrbrlyabt(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeAlrbrlyabt(DbsBrly* dbsbrly);
	uint enterSgeClose(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeClose(DbsBrly* dbsbrly);

	string getSquawk(DbsBrly* dbsbrly);

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleDpchAppDoClose(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyDlgClose(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyRefPreSet(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif

