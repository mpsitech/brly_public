/**
  * \file PnlBrlyLegDetail.h
  * job handler for job PnlBrlyLegDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLEGDETAIL_H
#define PNLBRLYLEGDETAIL_H

// IP custInclude --- INSERT

#define VecVBrlyLegDetailDo PnlBrlyLegDetail::VecVDo

#define ContIacBrlyLegDetail PnlBrlyLegDetail::ContIac
#define ContInfBrlyLegDetail PnlBrlyLegDetail::ContInf
#define StatAppBrlyLegDetail PnlBrlyLegDetail::StatApp
#define StatShrBrlyLegDetail PnlBrlyLegDetail::StatShr
#define TagBrlyLegDetail PnlBrlyLegDetail::Tag

#define DpchAppBrlyLegDetailData PnlBrlyLegDetail::DpchAppData
#define DpchAppBrlyLegDetailDo PnlBrlyLegDetail::DpchAppDo
#define DpchEngBrlyLegDetailData PnlBrlyLegDetail::DpchEngData

/**
  * PnlBrlyLegDetail
  */
class PnlBrlyLegDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLegDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTCLUVIEWCLICK = 2;
		static const uint BUTCLUCLUSTERCLICK = 3;
		static const uint BUTCLUUNCLUSTERCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyLegDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint NUMFLSTCLU = 2;
		static const uint TXFALT = 3;
		static const uint TXFDPH = 4;
		static const uint TXFAPH = 5;
		static const uint TXFXAL = 6;
		static const uint TXFXP0 = 7;
		static const uint TXFXP1 = 8;
		static const uint TXFXAP = 9;
		static const uint CHKCDN = 10;

	public:
		ContIac(const uint numFPupTyp = 1, const uint numFLstClu = 1, const string& TxfAlt = "", const string& TxfDph = "", const string& TxfAph = "", const string& TxfXal = "", const string& TxfXp0 = "", const string& TxfXp1 = "", const string& TxfXap = "", const bool ChkCdn = false);

	public:
		uint numFPupTyp;
		uint numFLstClu;
		string TxfAlt;
		string TxfDph;
		string TxfAph;
		string TxfXal;
		string TxfXp0;
		string TxfXp1;
		string TxfXap;
		bool ChkCdn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyLegDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTBLO = 1;
		static const uint TXTELO = 2;
		static const uint TXTCLU = 3;

	public:
		ContInf(const string& TxtBlo = "", const string& TxtElo = "", const string& TxtClu = "");

	public:
		string TxtBlo;
		string TxtElo;
		string TxtClu;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyLegDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstCluAlt = true, const uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyLegDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTBLOACTIVE = 3;
		static const uint TXTELOACTIVE = 4;
		static const uint PUPTYPACTIVE = 5;
		static const uint LSTCLUACTIVE = 6;
		static const uint BUTCLUVIEWACTIVE = 7;
		static const uint BUTCLUCLUSTERAVAIL = 8;
		static const uint BUTCLUUNCLUSTERAVAIL = 9;
		static const uint TXFALTACTIVE = 10;
		static const uint TXFDPHACTIVE = 11;
		static const uint TXFAPHACTIVE = 12;
		static const uint TXFXALACTIVE = 13;
		static const uint TXFXP0ACTIVE = 14;
		static const uint TXFXP1ACTIVE = 15;
		static const uint TXFXAPACTIVE = 16;
		static const uint CHKCDNACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtBloActive = true, const bool TxtEloActive = true, const bool PupTypActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxfAltActive = true, const bool TxfDphActive = true, const bool TxfAphActive = true, const bool TxfXalActive = true, const bool TxfXp0Active = true, const bool TxfXp1Active = true, const bool TxfXapActive = true, const bool ChkCdnActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtBloActive;
		bool TxtEloActive;
		bool PupTypActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxfAltActive;
		bool TxfDphActive;
		bool TxfAphActive;
		bool TxfXalActive;
		bool TxfXp0Active;
		bool TxfXp1Active;
		bool TxfXapActive;
		bool ChkCdnActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyLegDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLegDetailData)
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
		* DpchAppDo (full: DpchAppBrlyLegDetailDo)
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
		* DpchEngData (full: DpchEngBrlyLegDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTCLU = 4;
		static const uint FEEDFPUPTYP = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstClu = NULL, Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstClu;
		Feed feedFPupTyp;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtBloActive(DbsBrly* dbsbrly);
	bool evalTxtEloActive(DbsBrly* dbsbrly);
	bool evalPupTypActive(DbsBrly* dbsbrly);
	bool evalLstCluActive(DbsBrly* dbsbrly);
	bool evalButCluViewActive(DbsBrly* dbsbrly);
	bool evalButCluClusterAvail(DbsBrly* dbsbrly);
	bool evalButCluUnclusterAvail(DbsBrly* dbsbrly);
	bool evalTxfAltActive(DbsBrly* dbsbrly);
	bool evalTxfDphActive(DbsBrly* dbsbrly);
	bool evalTxfAphActive(DbsBrly* dbsbrly);
	bool evalTxfXalActive(DbsBrly* dbsbrly);
	bool evalTxfXp0Active(DbsBrly* dbsbrly);
	bool evalTxfXp1Active(DbsBrly* dbsbrly);
	bool evalTxfXapActive(DbsBrly* dbsbrly);
	bool evalChkCdnActive(DbsBrly* dbsbrly);

public:
	PnlBrlyLegDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyLegDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstClu;
	Feed feedFPupTyp;

	BrlyMLeg recLeg;
	uint ixWSubsetLeg;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshLstClu(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshClu(DbsBrly* dbsbrly, set<uint>& moditems);

	void refreshRecLeg(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButCluViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButCluClusterClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButCluUnclusterClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyLeg_cluEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyLeg_inSbs(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, bool& boolvalRet);
	bool handleCallBrlyLeg_typEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, bool& boolvalRet);
	bool handleCallBrlyLegUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyLegMod_cluEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

