/**
  * \file CrdBrlyCon.h
  * job handler for job CrdBrlyCon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef CRDBRLYCON_H
#define CRDBRLYCON_H

// IP custInclude --- INSERT

#include "DlgBrlyConNew.h"
#include "PnlBrlyConRec.h"
#include "PnlBrlyConHeadbar.h"
#include "PnlBrlyConList.h"

#define VecVBrlyConDo CrdBrlyCon::VecVDo
#define VecVBrlyConSge CrdBrlyCon::VecVSge

#define ContInfBrlyCon CrdBrlyCon::ContInf
#define StatAppBrlyCon CrdBrlyCon::StatApp
#define StatShrBrlyCon CrdBrlyCon::StatShr
#define TagBrlyCon CrdBrlyCon::Tag

#define DpchAppBrlyConDo CrdBrlyCon::DpchAppDo
#define DpchEngBrlyConData CrdBrlyCon::DpchEngData

/**
  * CrdBrlyCon
  */
class CrdBrlyCon : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyConDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITCRDNEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyConSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRBRLYABT = 2;
		static const uint CLOSE = 3;
		static const uint CRGIDLE = 4;
		static const uint CORRGEN = 5;
		static const uint CORRCALC = 6;
		static const uint CRGDONE = 7;
		static const uint CONGEN = 8;
		static const uint CNGDONE = 9;
		static const uint CALC1 = 10;
		static const uint CALC2 = 11;
		static const uint CALC3 = 12;
		static const uint CALC4 = 13;
		static const uint DONE = 14;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContInf (full: ContInfBrlyCon)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDCON = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdCon = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdCon;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyCon)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrBrlyCon)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFDLGNEW = 1;
		static const uint JREFHEADBAR = 2;
		static const uint JREFLIST = 3;
		static const uint JREFREC = 4;
		static const uint MSPCRD1AVAIL = 5;
		static const uint MITCRDNEWAVAIL = 6;

	public:
		StatShr(const ubigint jrefDlgnew = 0, const ubigint jrefHeadbar = 0, const ubigint jrefList = 0, const ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true);

	public:
		ubigint jrefDlgnew;
		ubigint jrefHeadbar;
		ubigint jrefList;
		ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyCon)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyConDo)
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
		* DpchEngData (full: DpchEngBrlyConData)
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

public:
	CrdBrlyCon(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale, const ubigint ref = 0);
	~CrdBrlyCon();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	DlgBrlyConNew* dlgnew;
	PnlBrlyConRec* pnlrec;
	PnlBrlyConHeadbar* pnlheadbar;
	PnlBrlyConList* pnllist;

	// IP custVar --- IBEGIN
	string arena;
	unsigned int date;

	ListBrlyMLeg rts;
	ListBrlyMLeg corrs;
	ListBrlyMConnection cons;
	ListBrlyMFlight flts;

	string svgfile;
	// IP custVar --- IEND

public:
	// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	void wrBgseg(fstream& outfile, const unsigned int start, const unsigned int mode, double x, const double y, double width, const double height);

	double radToDeg(double _rad);
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
	uint enterSgeCrgidle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCrgidle(DbsBrly* dbsbrly);
	uint enterSgeCorrgen(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCorrgen(DbsBrly* dbsbrly);
	uint enterSgeCorrcalc(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCorrcalc(DbsBrly* dbsbrly);
	uint enterSgeCrgdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCrgdone(DbsBrly* dbsbrly);
	uint enterSgeCongen(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCongen(DbsBrly* dbsbrly);
	uint enterSgeCngdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCngdone(DbsBrly* dbsbrly);
	uint enterSgeCalc1(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc1(DbsBrly* dbsbrly);
	uint enterSgeCalc2(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc2(DbsBrly* dbsbrly);
	uint enterSgeCalc3(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc3(DbsBrly* dbsbrly);
	uint enterSgeCalc4(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc4(DbsBrly* dbsbrly);
	uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

	string getSquawk(DbsBrly* dbsbrly);

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleBargraph(DbsBrly* dbsbrly);
	bool handleCalc(DbsBrly* dbsbrly);
	bool handleCleanup1(DbsBrly* dbsbrly);
	bool handleCleanup2(DbsBrly* dbsbrly);
	bool handleCongen(DbsBrly* dbsbrly);
	bool handleCorrgen(DbsBrly* dbsbrly);
	bool handleLineup(DbsBrly* dbsbrly);
	bool handlePickup(DbsBrly* dbsbrly);
	bool handleStats2(DbsBrly* dbsbrly);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleDpchAppDoClose(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdNewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

	void handleTimer(DbsBrly* dbsbrly, const string& sref);
	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyDlgClose(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
	bool handleCallBrlyRefPreSet(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


