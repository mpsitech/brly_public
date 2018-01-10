/**
  * \file PnlBrlyFilDetail.h
  * job handler for job PnlBrlyFilDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFILDETAIL_H
#define PNLBRLYFILDETAIL_H

// IP custInclude --- INSERT

#define VecVBrlyFilDetailDo PnlBrlyFilDetail::VecVDo

#define ContIacBrlyFilDetail PnlBrlyFilDetail::ContIac
#define ContInfBrlyFilDetail PnlBrlyFilDetail::ContInf
#define StatAppBrlyFilDetail PnlBrlyFilDetail::StatApp
#define StatShrBrlyFilDetail PnlBrlyFilDetail::StatShr
#define TagBrlyFilDetail PnlBrlyFilDetail::Tag

#define DpchAppBrlyFilDetailData PnlBrlyFilDetail::DpchAppData
#define DpchAppBrlyFilDetailDo PnlBrlyFilDetail::DpchAppDo
#define DpchEngBrlyFilDetailData PnlBrlyFilDetail::DpchEngData

/**
  * PnlBrlyFilDetail
  */
class PnlBrlyFilDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyFilDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTCLUVIEWCLICK = 2;
		static const uint BUTCLUCLUSTERCLICK = 3;
		static const uint BUTCLUUNCLUSTERCLICK = 4;
		static const uint BUTREUVIEWCLICK = 5;
		static const uint BUTCNTEDITCLICK = 6;
		static const uint BUTMIMEDITCLICK = 7;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyFilDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFFNM = 1;
		static const uint NUMFLSTCLU = 2;
		static const uint NUMFPUPRET = 3;
		static const uint NUMFPUPCNT = 4;
		static const uint TXFCNT = 5;
		static const uint TXFACV = 6;
		static const uint TXFANM = 7;
		static const uint NUMFPUPMIM = 8;
		static const uint TXFMIM = 9;
		static const uint TXFSIZ = 10;
		static const uint TXFCMT = 11;

	public:
		ContIac(const string& TxfFnm = "", const uint numFLstClu = 1, const uint numFPupRet = 1, const uint numFPupCnt = 1, const string& TxfCnt = "", const string& TxfAcv = "", const string& TxfAnm = "", const uint numFPupMim = 1, const string& TxfMim = "", const string& TxfSiz = "", const string& TxfCmt = "");

	public:
		string TxfFnm;
		uint numFLstClu;
		uint numFPupRet;
		uint numFPupCnt;
		string TxfCnt;
		string TxfAcv;
		string TxfAnm;
		uint numFPupMim;
		string TxfMim;
		string TxfSiz;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyFilDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTCLU = 1;
		static const uint TXTREU = 2;

	public:
		ContInf(const string& TxtClu = "", const string& TxtReu = "");

	public:
		string TxtClu;
		string TxtReu;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyFilDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstCluAlt = true, const bool PupCntAlt = false, const bool PupMimAlt = false, const uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyFilDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFCNTVALID = 1;
		static const uint TXFMIMVALID = 2;
		static const uint BUTSAVEAVAIL = 3;
		static const uint BUTSAVEACTIVE = 4;
		static const uint TXFFNMACTIVE = 5;
		static const uint LSTCLUACTIVE = 6;
		static const uint BUTCLUVIEWACTIVE = 7;
		static const uint BUTCLUCLUSTERAVAIL = 8;
		static const uint BUTCLUUNCLUSTERAVAIL = 9;
		static const uint TXTREUACTIVE = 10;
		static const uint BUTREUVIEWAVAIL = 11;
		static const uint BUTREUVIEWACTIVE = 12;
		static const uint PUPCNTACTIVE = 13;
		static const uint BUTCNTEDITAVAIL = 14;
		static const uint TXFACVACTIVE = 15;
		static const uint TXFANMACTIVE = 16;
		static const uint PUPMIMACTIVE = 17;
		static const uint BUTMIMEDITAVAIL = 18;
		static const uint TXFSIZACTIVE = 19;
		static const uint TXFCMTACTIVE = 20;

	public:
		StatShr(const bool TxfCntValid = false, const bool TxfMimValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfFnmActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool PupCntActive = true, const bool ButCntEditAvail = true, const bool TxfAcvActive = true, const bool TxfAnmActive = true, const bool PupMimActive = true, const bool ButMimEditAvail = true, const bool TxfSizActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfCntValid;
		bool TxfMimValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfFnmActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool PupCntActive;
		bool ButCntEditAvail;
		bool TxfAcvActive;
		bool TxfAnmActive;
		bool PupMimActive;
		bool ButMimEditAvail;
		bool TxfSizActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyFilDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFilDetailData)
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
		* DpchAppDo (full: DpchAppBrlyFilDetailDo)
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
		* DpchEngData (full: DpchEngBrlyFilDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTCLU = 4;
		static const uint FEEDFPUPCNT = 5;
		static const uint FEEDFPUPMIM = 6;
		static const uint FEEDFPUPRET = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint TAG = 10;
		static const uint ALL = 11;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstClu = NULL, Feed* feedFPupCnt = NULL, Feed* feedFPupMim = NULL, Feed* feedFPupRet = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstClu;
		Feed feedFPupCnt;
		Feed feedFPupMim;
		Feed feedFPupRet;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxfFnmActive(DbsBrly* dbsbrly);
	bool evalLstCluActive(DbsBrly* dbsbrly);
	bool evalButCluViewActive(DbsBrly* dbsbrly);
	bool evalButCluClusterAvail(DbsBrly* dbsbrly);
	bool evalButCluUnclusterAvail(DbsBrly* dbsbrly);
	bool evalTxtReuActive(DbsBrly* dbsbrly);
	bool evalButReuViewAvail(DbsBrly* dbsbrly);
	bool evalButReuViewActive(DbsBrly* dbsbrly);
	bool evalPupCntActive(DbsBrly* dbsbrly);
	bool evalButCntEditAvail(DbsBrly* dbsbrly);
	bool evalTxfAcvActive(DbsBrly* dbsbrly);
	bool evalTxfAnmActive(DbsBrly* dbsbrly);
	bool evalPupMimActive(DbsBrly* dbsbrly);
	bool evalButMimEditAvail(DbsBrly* dbsbrly);
	bool evalTxfSizActive(DbsBrly* dbsbrly);
	bool evalTxfCmtActive(DbsBrly* dbsbrly);

public:
	PnlBrlyFilDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyFilDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstClu;
	Feed feedFPupCnt;
	Feed feedFPupMim;
	Feed feedFPupRet;

	BrlyMFile recFil;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshLstClu(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshClu(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshPupCnt(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshTxfCnt(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshCnt(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshPupMim(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshTxfMim(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshMim(DbsBrly* dbsbrly, set<uint>& moditems);

	void refreshRecFil(DbsBrly* dbsbrly, set<uint>& moditems);

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
	void handleDpchAppDoButReuViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButCntEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButMimEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyFil_cluEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyFil_retEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, bool& boolvalRet);
	bool handleCallBrlyFil_reuEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyFilUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyKlsAkeyMod_klsEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv);
	bool handleCallBrlyFilMod_cluEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

