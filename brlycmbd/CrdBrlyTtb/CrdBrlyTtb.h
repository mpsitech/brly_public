/**
  * \file CrdBrlyTtb.h
  * job handler for job CrdBrlyTtb (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef CRDBRLYTTB_H
#define CRDBRLYTTB_H

// IP custInclude --- IBEGIN
#include <sys/types.h>
#include <dirent.h>
// IP custInclude --- IEND

#include "DlgBrlyTtbImpflt.h"
#include "DlgBrlyTtbNew.h"
#include "DlgBrlyTtbTrlorig.h"
#include "PnlBrlyTtbRec.h"
#include "PnlBrlyTtbHeadbar.h"
#include "PnlBrlyTtbList.h"
#include "IexBrlyFlt.h"

#define VecVBrlyTtbDo CrdBrlyTtb::VecVDo
#define VecVBrlyTtbSge CrdBrlyTtb::VecVSge

#define ContInfBrlyTtb CrdBrlyTtb::ContInf
#define StatAppBrlyTtb CrdBrlyTtb::StatApp
#define StatShrBrlyTtb CrdBrlyTtb::StatShr
#define TagBrlyTtb CrdBrlyTtb::Tag

#define DpchAppBrlyTtbDo CrdBrlyTtb::DpchAppDo
#define DpchEngBrlyTtbData CrdBrlyTtb::DpchEngData

/**
  * CrdBrlyTtb
  */
class CrdBrlyTtb : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyTtbDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITCRDNEWCLICK = 3;
		static const uint MITCRDTRLCLICK = 4;
		static const uint MITCRDIFLCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyTtbSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRBRLYABT = 2;
		static const uint CLOSE = 3;
		static const uint IMPIDLE = 4;
		static const uint IMPORT = 5;
		static const uint IMPDONE = 6;
		static const uint SEGMENT = 7;
		static const uint SEGDONE = 8;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContInf (full: ContInfBrlyTtb)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDTTB = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdTtb = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdTtb;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyTtb)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrBrlyTtb)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFDLGIMPFLT = 1;
		static const uint JREFDLGNEW = 2;
		static const uint JREFDLGTRLORIG = 3;
		static const uint JREFHEADBAR = 4;
		static const uint JREFLIST = 5;
		static const uint JREFREC = 6;
		static const uint MSPCRD1AVAIL = 7;
		static const uint MITCRDNEWAVAIL = 8;
		static const uint MITCRDTRLAVAIL = 9;
		static const uint MITCRDIFLAVAIL = 10;
		static const uint MITCRDIFLACTIVE = 11;

	public:
		StatShr(const ubigint jrefDlgimpflt = 0, const ubigint jrefDlgnew = 0, const ubigint jrefDlgtrlorig = 0, const ubigint jrefHeadbar = 0, const ubigint jrefList = 0, const ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdTrlAvail = true, const bool MitCrdIflAvail = true, const bool MitCrdIflActive = true);

	public:
		ubigint jrefDlgimpflt;
		ubigint jrefDlgnew;
		ubigint jrefDlgtrlorig;
		ubigint jrefHeadbar;
		ubigint jrefList;
		ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdTrlAvail;
		bool MitCrdIflAvail;
		bool MitCrdIflActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyTtb)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyTtbDo)
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
		* DpchEngData (full: DpchEngBrlyTtbData)
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

	bool evalMspCrd1Avail(DbsBrly* dbsbrly);
	bool evalMitCrdNewAvail(DbsBrly* dbsbrly);
	bool evalMitCrdTrlAvail(DbsBrly* dbsbrly);
	bool evalMitCrdIflAvail(DbsBrly* dbsbrly);
	bool evalMitCrdIflActive(DbsBrly* dbsbrly);

public:
	CrdBrlyTtb(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale, const ubigint ref = 0);
	~CrdBrlyTtb();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	DlgBrlyTtbImpflt* dlgimpflt;
	DlgBrlyTtbNew* dlgnew;
	DlgBrlyTtbTrlorig* dlgtrlorig;
	PnlBrlyTtbRec* pnlrec;
	PnlBrlyTtbHeadbar* pnlheadbar;
	PnlBrlyTtbList* pnllist;
	IexBrlyFlt* iex;

	// IP custVar --- IBEGIN
	string infolder;
	unsigned int fltcnt;

	uint start;
	uint stop;
	// IP custVar --- IEND

public:
	// IP cust --- IBEGIN
	void stats1_dump(DbsBrly* dbsbrly, const vector<ubigint>& refsLeg1, const vector<ubigint>& refsLeg2);
	// IP cust --- IEND

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
	uint enterSgeImpidle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImpidle(DbsBrly* dbsbrly);
	uint enterSgeImport(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImport(DbsBrly* dbsbrly);
	uint enterSgeImpdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImpdone(DbsBrly* dbsbrly);
	uint enterSgeSegment(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeSegment(DbsBrly* dbsbrly);
	uint enterSgeSegdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeSegdone(DbsBrly* dbsbrly);

	string getSquawk(DbsBrly* dbsbrly);

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleImportFA(DbsBrly* dbsbrly);
	bool handleSegment(DbsBrly* dbsbrly);
	bool handleStats1(DbsBrly* dbsbrly);
	bool handleValidate(DbsBrly* dbsbrly);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleDpchAppDoClose(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdNewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdTrlClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdIflClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

	void handleTimer(DbsBrly* dbsbrly, const string& sref);
	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyDlgClose(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyRefPreSet(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


