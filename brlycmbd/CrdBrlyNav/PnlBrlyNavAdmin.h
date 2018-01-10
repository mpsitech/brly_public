/**
  * \file PnlBrlyNavAdmin.h
  * job handler for job PnlBrlyNavAdmin (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYNAVADMIN_H
#define PNLBRLYNAVADMIN_H

// IP custInclude --- INSERT

#define VecVBrlyNavAdminDo PnlBrlyNavAdmin::VecVDo

#define ContIacBrlyNavAdmin PnlBrlyNavAdmin::ContIac
#define StatAppBrlyNavAdmin PnlBrlyNavAdmin::StatApp
#define StatShrBrlyNavAdmin PnlBrlyNavAdmin::StatShr
#define TagBrlyNavAdmin PnlBrlyNavAdmin::Tag

#define DpchAppBrlyNavAdminData PnlBrlyNavAdmin::DpchAppData
#define DpchAppBrlyNavAdminDo PnlBrlyNavAdmin::DpchAppDo
#define DpchEngBrlyNavAdminData PnlBrlyNavAdmin::DpchEngData

/**
  * PnlBrlyNavAdmin
  */
class PnlBrlyNavAdmin : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyNavAdminDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUSGVIEWCLICK = 1;
		static const uint BUTUSGNEWCRDCLICK = 2;
		static const uint BUTUSRVIEWCLICK = 3;
		static const uint BUTUSRNEWCRDCLICK = 4;
		static const uint BUTPRSVIEWCLICK = 5;
		static const uint BUTPRSNEWCRDCLICK = 6;
		static const uint BUTFILVIEWCLICK = 7;
		static const uint BUTFILNEWCRDCLICK = 8;
		static const uint BUTOPRVIEWCLICK = 9;
		static const uint BUTOPRNEWCRDCLICK = 10;
		static const uint BUTPTYVIEWCLICK = 11;
		static const uint BUTPTYNEWCRDCLICK = 12;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyNavAdmin)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTUSG = 1;
		static const uint NUMFLSTUSR = 2;
		static const uint NUMFLSTPRS = 3;
		static const uint NUMFLSTFIL = 4;
		static const uint NUMFLSTOPR = 5;
		static const uint NUMFLSTPTY = 6;

	public:
		ContIac(const uint numFLstUsg = 1, const uint numFLstUsr = 1, const uint numFLstPrs = 1, const uint numFLstFil = 1, const uint numFLstOpr = 1, const uint numFLstPty = 1);

	public:
		uint numFLstUsg;
		uint numFLstUsr;
		uint numFLstPrs;
		uint numFLstFil;
		uint numFLstOpr;
		uint numFLstPty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppBrlyNavAdmin)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const bool LstFilAlt = true, const bool LstOprAlt = true, const bool LstPtyAlt = true, const uint LstUsgNumFirstdisp = 1, const uint LstUsrNumFirstdisp = 1, const uint LstPrsNumFirstdisp = 1, const uint LstFilNumFirstdisp = 1, const uint LstOprNumFirstdisp = 1, const uint LstPtyNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyNavAdmin)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTUSGAVAIL = 1;
		static const uint BUTUSGVIEWACTIVE = 2;
		static const uint LSTUSRAVAIL = 3;
		static const uint BUTUSRVIEWACTIVE = 4;
		static const uint LSTPRSAVAIL = 5;
		static const uint BUTPRSVIEWACTIVE = 6;
		static const uint LSTFILAVAIL = 7;
		static const uint BUTFILVIEWACTIVE = 8;
		static const uint LSTOPRAVAIL = 9;
		static const uint BUTOPRVIEWACTIVE = 10;
		static const uint LSTPTYAVAIL = 11;
		static const uint BUTPTYVIEWACTIVE = 12;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true, const bool LstOprAvail = true, const bool ButOprViewActive = true, const bool LstPtyAvail = true, const bool ButPtyViewActive = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;
		bool LstOprAvail;
		bool ButOprViewActive;
		bool LstPtyAvail;
		bool ButPtyViewActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyNavAdmin)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyNavAdminData)
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
		* DpchAppDo (full: DpchAppBrlyNavAdminDo)
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
		* DpchEngData (full: DpchEngBrlyNavAdminData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTFIL = 3;
		static const uint FEEDFLSTOPR = 4;
		static const uint FEEDFLSTPRS = 5;
		static const uint FEEDFLSTPTY = 6;
		static const uint FEEDFLSTUSG = 7;
		static const uint FEEDFLSTUSR = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstFil = NULL, Feed* feedFLstOpr = NULL, Feed* feedFLstPrs = NULL, Feed* feedFLstPty = NULL, Feed* feedFLstUsg = NULL, Feed* feedFLstUsr = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstFil;
		Feed feedFLstOpr;
		Feed feedFLstPrs;
		Feed feedFLstPty;
		Feed feedFLstUsg;
		Feed feedFLstUsr;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstUsgAvail(DbsBrly* dbsbrly);
	bool evalButUsgViewActive(DbsBrly* dbsbrly);
	bool evalLstUsrAvail(DbsBrly* dbsbrly);
	bool evalButUsrViewActive(DbsBrly* dbsbrly);
	bool evalLstPrsAvail(DbsBrly* dbsbrly);
	bool evalButPrsViewActive(DbsBrly* dbsbrly);
	bool evalLstFilAvail(DbsBrly* dbsbrly);
	bool evalButFilViewActive(DbsBrly* dbsbrly);
	bool evalLstOprAvail(DbsBrly* dbsbrly);
	bool evalButOprViewActive(DbsBrly* dbsbrly);
	bool evalLstPtyAvail(DbsBrly* dbsbrly);
	bool evalButPtyViewActive(DbsBrly* dbsbrly);

public:
	PnlBrlyNavAdmin(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyNavAdmin();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstFil;
	Feed feedFLstOpr;
	Feed feedFLstPrs;
	Feed feedFLstPty;
	Feed feedFLstUsg;
	Feed feedFLstUsr;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshLstUsg(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshUsg(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstUsr(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshUsr(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstPrs(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshPrs(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstFil(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshFil(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstOpr(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshOpr(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstPty(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshPty(DbsBrly* dbsbrly, set<uint>& moditems);
	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButUsgViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButUsgNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButUsrViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButUsrNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButPrsNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFilViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFilNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButOprViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButOprNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButPtyViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButPtyNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyHusrRunvMod_crdUsrEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif

