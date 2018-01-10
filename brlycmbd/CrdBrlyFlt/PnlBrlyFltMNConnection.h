/**
  * \file PnlBrlyFltMNConnection.h
  * job handler for job PnlBrlyFltMNConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFLTMNCONNECTION_H
#define PNLBRLYFLTMNCONNECTION_H

// IP custInclude --- INSERT

#include "QryBrlyFltMNConnection.h"

#define VecVBrlyFltMNConnectionDo PnlBrlyFltMNConnection::VecVDo

#define ContInfBrlyFltMNConnection PnlBrlyFltMNConnection::ContInf
#define StatAppBrlyFltMNConnection PnlBrlyFltMNConnection::StatApp
#define StatShrBrlyFltMNConnection PnlBrlyFltMNConnection::StatShr
#define StgIacBrlyFltMNConnection PnlBrlyFltMNConnection::StgIac
#define TagBrlyFltMNConnection PnlBrlyFltMNConnection::Tag

#define DpchAppBrlyFltMNConnectionData PnlBrlyFltMNConnection::DpchAppData
#define DpchAppBrlyFltMNConnectionDo PnlBrlyFltMNConnection::DpchAppDo
#define DpchEngBrlyFltMNConnectionData PnlBrlyFltMNConnection::DpchEngData

/**
  * PnlBrlyFltMNConnection
  */
class PnlBrlyFltMNConnection : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyFltMNConnectionDo)
		*/
	class VecVDo {

	public:
		static const uint BUTVIEWCLICK = 1;
		static const uint BUTADDCLICK = 2;
		static const uint BUTSUBCLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyFltMNConnection)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyFltMNConnection)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyFltMNConnection)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTVIEWAVAIL = 1;
		static const uint BUTVIEWACTIVE = 2;
		static const uint BUTADDAVAIL = 3;
		static const uint BUTSUBAVAIL = 4;
		static const uint BUTSUBACTIVE = 5;

	public:
		StatShr(const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButViewAvail;
		bool ButViewActive;
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacBrlyFltMNConnection)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOMREFWIDTH = 1;
		static const uint TCOSTAWIDTH = 2;
		static const uint TCOSTOWIDTH = 3;
		static const uint TCOLP0WIDTH = 4;
		static const uint TCOLP1WIDTH = 5;

	public:
		StgIac(const uint TcoMrefWidth = 100, const uint TcoStaWidth = 100, const uint TcoStoWidth = 100, const uint TcoLp0Width = 100, const uint TcoLp1Width = 100);

	public:
		uint TcoMrefWidth;
		uint TcoStaWidth;
		uint TcoStoWidth;
		uint TcoLp0Width;
		uint TcoLp1Width;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagBrlyFltMNConnection)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFltMNConnectionData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryBrlyFltMNConnection::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFltMNConnectionDo)
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
		* DpchEngData (full: DpchEngBrlyFltMNConnectionData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListBrlyQFltMNConnection* rst = NULL, QryBrlyFltMNConnection::StatShr* statshrqry = NULL, QryBrlyFltMNConnection::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListBrlyQFltMNConnection rst;
		QryBrlyFltMNConnection::StatShr statshrqry;
		QryBrlyFltMNConnection::StgIac stgiacqry;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButViewAvail(DbsBrly* dbsbrly);
	bool evalButViewActive(DbsBrly* dbsbrly);
	bool evalButAddAvail(DbsBrly* dbsbrly);
	bool evalButSubAvail(DbsBrly* dbsbrly);
	bool evalButSubActive(DbsBrly* dbsbrly);

public:
	PnlBrlyFltMNConnection(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyFltMNConnection();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;

	QryBrlyFltMNConnection* qry;

	BrlyRMConnectionMFlight recConRflt;

	BrlyMConnection recCon;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiac(DbsBrly* dbsbrly, StgIac* _stgiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqry(DbsBrly* dbsbrly, QryBrlyFltMNConnection::StgIac* _stgiacqry, DpchEngBrly** dpcheng);

	void handleDpchAppDoButViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButAddClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButSubClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
};

#endif

