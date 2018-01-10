/**
  * \file PnlBrlySegDetail.h
  * job handler for job PnlBrlySegDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYSEGDETAIL_H
#define PNLBRLYSEGDETAIL_H

// IP custInclude --- INSERT

#define VecVBrlySegDetailDo PnlBrlySegDetail::VecVDo

#define ContIacBrlySegDetail PnlBrlySegDetail::ContIac
#define ContInfBrlySegDetail PnlBrlySegDetail::ContInf
#define StatAppBrlySegDetail PnlBrlySegDetail::StatApp
#define StatShrBrlySegDetail PnlBrlySegDetail::StatShr
#define TagBrlySegDetail PnlBrlySegDetail::Tag

#define DpchAppBrlySegDetailData PnlBrlySegDetail::DpchAppData
#define DpchAppBrlySegDetailDo PnlBrlySegDetail::DpchAppDo
#define DpchEngBrlySegDetailData PnlBrlySegDetail::DpchEngData

/**
  * PnlBrlySegDetail
  */
class PnlBrlySegDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlySegDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTREUVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlySegDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPRET = 1;
		static const uint TXFDPH = 2;
		static const uint TXFAL0 = 3;
		static const uint TXFAL1 = 4;
		static const uint TXFTH0 = 5;
		static const uint TXFTH1 = 6;
		static const uint TXFPH0 = 7;
		static const uint TXFPH1 = 8;
		static const uint TXFSTA = 9;
		static const uint TXFSTO = 10;
		static const uint CHKCDN = 11;

	public:
		ContIac(const uint numFPupRet = 1, const string& TxfDph = "", const string& TxfAl0 = "", const string& TxfAl1 = "", const string& TxfTh0 = "", const string& TxfTh1 = "", const string& TxfPh0 = "", const string& TxfPh1 = "", const string& TxfSta = "", const string& TxfSto = "", const bool ChkCdn = false);

	public:
		uint numFPupRet;
		string TxfDph;
		string TxfAl0;
		string TxfAl1;
		string TxfTh0;
		string TxfTh1;
		string TxfPh0;
		string TxfPh1;
		string TxfSta;
		string TxfSto;
		bool ChkCdn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlySegDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREU = 1;

	public:
		ContInf(const string& TxtReu = "");

	public:
		string TxtReu;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlySegDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlySegDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTREUACTIVE = 3;
		static const uint BUTREUVIEWAVAIL = 4;
		static const uint BUTREUVIEWACTIVE = 5;
		static const uint TXFDPHACTIVE = 6;
		static const uint TXFAL0ACTIVE = 7;
		static const uint TXFAL1ACTIVE = 8;
		static const uint TXFTH0ACTIVE = 9;
		static const uint TXFTH1ACTIVE = 10;
		static const uint TXFPH0ACTIVE = 11;
		static const uint TXFPH1ACTIVE = 12;
		static const uint TXFSTAACTIVE = 13;
		static const uint TXFSTOACTIVE = 14;
		static const uint CHKCDNACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxfDphActive = true, const bool TxfAl0Active = true, const bool TxfAl1Active = true, const bool TxfTh0Active = true, const bool TxfTh1Active = true, const bool TxfPh0Active = true, const bool TxfPh1Active = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool ChkCdnActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxfDphActive;
		bool TxfAl0Active;
		bool TxfAl1Active;
		bool TxfTh0Active;
		bool TxfTh1Active;
		bool TxfPh0Active;
		bool TxfPh1Active;
		bool TxfStaActive;
		bool TxfStoActive;
		bool ChkCdnActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlySegDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlySegDetailData)
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
		* DpchAppDo (full: DpchAppBrlySegDetailDo)
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
		* DpchEngData (full: DpchEngBrlySegDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPRET = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;
		static const uint ALL = 8;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupRet = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupRet;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtReuActive(DbsBrly* dbsbrly);
	bool evalButReuViewAvail(DbsBrly* dbsbrly);
	bool evalButReuViewActive(DbsBrly* dbsbrly);
	bool evalTxfDphActive(DbsBrly* dbsbrly);
	bool evalTxfAl0Active(DbsBrly* dbsbrly);
	bool evalTxfAl1Active(DbsBrly* dbsbrly);
	bool evalTxfTh0Active(DbsBrly* dbsbrly);
	bool evalTxfTh1Active(DbsBrly* dbsbrly);
	bool evalTxfPh0Active(DbsBrly* dbsbrly);
	bool evalTxfPh1Active(DbsBrly* dbsbrly);
	bool evalTxfStaActive(DbsBrly* dbsbrly);
	bool evalTxfStoActive(DbsBrly* dbsbrly);
	bool evalChkCdnActive(DbsBrly* dbsbrly);

public:
	PnlBrlySegDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlySegDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupRet;

	BrlyMSegment recSeg;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshRecSeg(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlySeg_retEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, bool& boolvalRet);
	bool handleCallBrlySeg_reuEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlySegUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

