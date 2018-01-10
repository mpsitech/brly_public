/**
  * \file PnlBrlyTtbDetail.h
  * job handler for job PnlBrlyTtbDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYTTBDETAIL_H
#define PNLBRLYTTBDETAIL_H

// IP custInclude --- INSERT

#define VecVBrlyTtbDetailDo PnlBrlyTtbDetail::VecVDo

#define ContIacBrlyTtbDetail PnlBrlyTtbDetail::ContIac
#define ContInfBrlyTtbDetail PnlBrlyTtbDetail::ContInf
#define StatAppBrlyTtbDetail PnlBrlyTtbDetail::StatApp
#define StatShrBrlyTtbDetail PnlBrlyTtbDetail::StatShr
#define TagBrlyTtbDetail PnlBrlyTtbDetail::Tag

#define DpchAppBrlyTtbDetailData PnlBrlyTtbDetail::DpchAppData
#define DpchAppBrlyTtbDetailDo PnlBrlyTtbDetail::DpchAppDo
#define DpchEngBrlyTtbDetailData PnlBrlyTtbDetail::DpchEngData

/**
  * PnlBrlyTtbDetail
  */
class PnlBrlyTtbDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyTtbDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTFILVIEWCLICK = 2;
		static const uint BUTALIEDITCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyTtbDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPALI = 2;
		static const uint TXFALI = 3;
		static const uint TXFSTA = 4;
		static const uint TXFSTO = 5;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupAli = 1, const string& TxfAli = "", const string& TxfSta = "", const string& TxfSto = "");

	public:
		string TxfTit;
		uint numFPupAli;
		string TxfAli;
		string TxfSta;
		string TxfSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyTtbDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTFIL = 1;

	public:
		ContInf(const string& TxtFil = "");

	public:
		string TxtFil;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyTtbDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool PupAliAlt = false);
	};

	/**
		* StatShr (full: StatShrBrlyTtbDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFALIVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint TXFTITACTIVE = 4;
		static const uint TXTFILACTIVE = 5;
		static const uint BUTFILVIEWAVAIL = 6;
		static const uint BUTFILVIEWACTIVE = 7;
		static const uint PUPALIACTIVE = 8;
		static const uint BUTALIEDITAVAIL = 9;
		static const uint TXFSTAACTIVE = 10;
		static const uint TXFSTOACTIVE = 11;

	public:
		StatShr(const bool TxfAliValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxtFilActive = true, const bool ButFilViewAvail = true, const bool ButFilViewActive = true, const bool PupAliActive = true, const bool ButAliEditAvail = true, const bool TxfStaActive = true, const bool TxfStoActive = true);

	public:
		bool TxfAliValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxtFilActive;
		bool ButFilViewAvail;
		bool ButFilViewActive;
		bool PupAliActive;
		bool ButAliEditAvail;
		bool TxfStaActive;
		bool TxfStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyTtbDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyTtbDetailData)
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
		* DpchAppDo (full: DpchAppBrlyTtbDetailDo)
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
		* DpchEngData (full: DpchEngBrlyTtbDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPALI = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;
		static const uint ALL = 8;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupAli = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupAli;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxfTitActive(DbsBrly* dbsbrly);
	bool evalTxtFilActive(DbsBrly* dbsbrly);
	bool evalButFilViewAvail(DbsBrly* dbsbrly);
	bool evalButFilViewActive(DbsBrly* dbsbrly);
	bool evalPupAliActive(DbsBrly* dbsbrly);
	bool evalButAliEditAvail(DbsBrly* dbsbrly);
	bool evalTxfStaActive(DbsBrly* dbsbrly);
	bool evalTxfStoActive(DbsBrly* dbsbrly);

public:
	PnlBrlyTtbDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyTtbDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupAli;

	BrlyMTimetable recTtb;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshPupAli(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshTxfAli(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshAli(DbsBrly* dbsbrly, set<uint>& moditems);

	void refreshRecTtb(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFilViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButAliEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyTtb_filEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyTtbUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyKlsAkeyMod_klsEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv);
};

#endif

