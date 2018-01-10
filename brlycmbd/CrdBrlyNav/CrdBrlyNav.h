/**
  * \file CrdBrlyNav.h
  * job handler for job CrdBrlyNav (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef CRDBRLYNAV_H
#define CRDBRLYNAV_H

// IP custInclude --- INSERT

#include "DlgBrlyNavLoaini.h"
#include "PnlBrlyNavHeadbar.h"
#include "PnlBrlyNavAdmin.h"
#include "PnlBrlyNavBase.h"
#include "PnlBrlyNavConnect.h"

#define VecVBrlyNavDo CrdBrlyNav::VecVDo
#define VecVBrlyNavSge CrdBrlyNav::VecVSge

#define ContInfBrlyNav CrdBrlyNav::ContInf
#define StatAppBrlyNav CrdBrlyNav::StatApp
#define StatShrBrlyNav CrdBrlyNav::StatShr
#define TagBrlyNav CrdBrlyNav::Tag

#define DpchAppBrlyNavDo CrdBrlyNav::DpchAppDo
#define DpchEngBrlyNavData CrdBrlyNav::DpchEngData

/**
  * CrdBrlyNav
  */
class CrdBrlyNav : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyNavDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITSESTRMCLICK = 3;
		static const uint MITCRDUSGCLICK = 4;
		static const uint MITCRDUSRCLICK = 5;
		static const uint MITCRDPRSCLICK = 6;
		static const uint MITCRDFILCLICK = 7;
		static const uint MITCRDOPRCLICK = 8;
		static const uint MITCRDPTYCLICK = 9;
		static const uint MITCRDREGCLICK = 10;
		static const uint MITCRDLOCCLICK = 11;
		static const uint MITCRDLEGCLICK = 12;
		static const uint MITCRDTTBCLICK = 13;
		static const uint MITCRDFLTCLICK = 14;
		static const uint MITCRDCONCLICK = 15;
		static const uint MITAPPLOICLICK = 16;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyNavSge)
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
	  * ContInf (full: ContInfBrlyNav)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXSESSES1 = 3;
		static const uint MTXSESSES2 = 4;
		static const uint MTXSESSES3 = 5;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxSesSes1 = "", const string& MtxSesSes2 = "", const string& MtxSesSes3 = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxSesSes1;
		string MtxSesSes2;
		string MtxSesSes3;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyNav)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneAdmin = false, const bool initdoneBase = false, const bool initdoneConnect = false);
	};

	/**
		* StatShr (full: StatShrBrlyNav)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFDLGLOAINI = 1;
		static const uint JREFHEADBAR = 2;
		static const uint JREFADMIN = 3;
		static const uint PNLADMINAVAIL = 4;
		static const uint JREFBASE = 5;
		static const uint PNLBASEAVAIL = 6;
		static const uint JREFCONNECT = 7;
		static const uint PNLCONNECTAVAIL = 8;
		static const uint MSPCRD1AVAIL = 9;
		static const uint MITCRDUSGAVAIL = 10;
		static const uint MITCRDUSRAVAIL = 11;
		static const uint MITCRDPRSAVAIL = 12;
		static const uint MITCRDFILAVAIL = 13;
		static const uint MITCRDOPRAVAIL = 14;
		static const uint MITCRDPTYAVAIL = 15;
		static const uint MSPCRD2AVAIL = 16;
		static const uint MITCRDREGAVAIL = 17;
		static const uint MITCRDLOCAVAIL = 18;
		static const uint MITCRDLEGAVAIL = 19;
		static const uint MITCRDTTBAVAIL = 20;
		static const uint MITCRDFLTAVAIL = 21;
		static const uint MSPCRD3AVAIL = 22;
		static const uint MITCRDCONAVAIL = 23;
		static const uint MSPAPP2AVAIL = 24;
		static const uint MITAPPLOIAVAIL = 25;

	public:
		StatShr(const ubigint jrefDlgloaini = 0, const ubigint jrefHeadbar = 0, const ubigint jrefAdmin = 0, const bool pnladminAvail = false, const ubigint jrefBase = 0, const bool pnlbaseAvail = false, const ubigint jrefConnect = 0, const bool pnlconnectAvail = false, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdFilAvail = true, const bool MitCrdOprAvail = true, const bool MitCrdPtyAvail = true, const bool MspCrd2Avail = true, const bool MitCrdRegAvail = true, const bool MitCrdLocAvail = true, const bool MitCrdLegAvail = true, const bool MitCrdTtbAvail = true, const bool MitCrdFltAvail = true, const bool MspCrd3Avail = true, const bool MitCrdConAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		ubigint jrefDlgloaini;
		ubigint jrefHeadbar;
		ubigint jrefAdmin;
		bool pnladminAvail;
		ubigint jrefBase;
		bool pnlbaseAvail;
		ubigint jrefConnect;
		bool pnlconnectAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdFilAvail;
		bool MitCrdOprAvail;
		bool MitCrdPtyAvail;
		bool MspCrd2Avail;
		bool MitCrdRegAvail;
		bool MitCrdLocAvail;
		bool MitCrdLegAvail;
		bool MitCrdTtbAvail;
		bool MitCrdFltAvail;
		bool MspCrd3Avail;
		bool MitCrdConAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyNav)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyNavDo)
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
		* DpchEngData (full: DpchEngBrlyNavData)
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

	bool evalPnladminAvail(DbsBrly* dbsbrly);
	bool evalPnlbaseAvail(DbsBrly* dbsbrly);
	bool evalPnlconnectAvail(DbsBrly* dbsbrly);
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
	bool evalMspApp2Avail(DbsBrly* dbsbrly);
	bool evalMitAppLoiAvail(DbsBrly* dbsbrly);

public:
	CrdBrlyNav(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~CrdBrlyNav();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	DlgBrlyNavLoaini* dlgloaini;
	PnlBrlyNavHeadbar* pnlheadbar;
	PnlBrlyNavAdmin* pnladmin;
	PnlBrlyNavBase* pnlbase;
	PnlBrlyNavConnect* pnlconnect;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);
	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);
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
	void handleDpchAppDoMitSesTrmClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdUsgClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdUsrClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdPrsClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdFilClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdOprClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdPtyClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdRegClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdLocClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdLegClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdTtbClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdFltClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdConClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitAppLoiClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyDlgClose(DbsBrly* dbsbrly, const ubigint jrefTrig);
};

#endif

