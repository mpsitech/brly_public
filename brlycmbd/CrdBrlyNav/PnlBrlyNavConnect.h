/**
  * \file PnlBrlyNavConnect.h
  * job handler for job PnlBrlyNavConnect (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYNAVCONNECT_H
#define PNLBRLYNAVCONNECT_H

// IP custInclude --- INSERT

#define VecVBrlyNavConnectDo PnlBrlyNavConnect::VecVDo

#define ContIacBrlyNavConnect PnlBrlyNavConnect::ContIac
#define StatAppBrlyNavConnect PnlBrlyNavConnect::StatApp
#define StatShrBrlyNavConnect PnlBrlyNavConnect::StatShr
#define TagBrlyNavConnect PnlBrlyNavConnect::Tag

#define DpchAppBrlyNavConnectData PnlBrlyNavConnect::DpchAppData
#define DpchAppBrlyNavConnectDo PnlBrlyNavConnect::DpchAppDo
#define DpchEngBrlyNavConnectData PnlBrlyNavConnect::DpchEngData

/**
  * PnlBrlyNavConnect
  */
class PnlBrlyNavConnect : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyNavConnectDo)
		*/
	class VecVDo {

	public:
		static const uint BUTCONVIEWCLICK = 1;
		static const uint BUTCONNEWCRDCLICK = 2;
		static const uint BUTRLYVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyNavConnect)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTCON = 1;
		static const uint NUMFLSTRLY = 2;

	public:
		ContIac(const uint numFLstCon = 1, const uint numFLstRly = 1);

	public:
		uint numFLstCon;
		uint numFLstRly;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppBrlyNavConnect)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstConAlt = true, const bool LstRlyAlt = true, const uint LstConNumFirstdisp = 1, const uint LstRlyNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyNavConnect)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTCONAVAIL = 1;
		static const uint BUTCONVIEWACTIVE = 2;
		static const uint LSTRLYAVAIL = 3;
		static const uint BUTRLYVIEWACTIVE = 4;

	public:
		StatShr(const bool LstConAvail = true, const bool ButConViewActive = true, const bool LstRlyAvail = true, const bool ButRlyViewActive = true);

	public:
		bool LstConAvail;
		bool ButConViewActive;
		bool LstRlyAvail;
		bool ButRlyViewActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyNavConnect)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyNavConnectData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyNavConnectDo)
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
		* DpchEngData (full: DpchEngBrlyNavConnectData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTCON = 3;
		static const uint FEEDFLSTRLY = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;
		static const uint ALL = 8;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstCon = NULL, Feed* feedFLstRly = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstCon;
		Feed feedFLstRly;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstConAvail(DbsBrly* dbsbrly);
	bool evalButConViewActive(DbsBrly* dbsbrly);
	bool evalLstRlyAvail(DbsBrly* dbsbrly);
	bool evalButRlyViewActive(DbsBrly* dbsbrly);

public:
	PnlBrlyNavConnect(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyNavConnect();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstCon;
	Feed feedFLstRly;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshLstCon(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshCon(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstRly(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshRly(DbsBrly* dbsbrly, set<uint>& moditems);
	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButConViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButConNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRlyViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyHusrRunvMod_crdUsrEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif

