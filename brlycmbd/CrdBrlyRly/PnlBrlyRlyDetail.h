/**
  * \file PnlBrlyRlyDetail.h
  * job handler for job PnlBrlyRlyDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYRLYDETAIL_H
#define PNLBRLYRLYDETAIL_H

// IP custInclude --- INSERT

#define VecVBrlyRlyDetailDo PnlBrlyRlyDetail::VecVDo

#define ContIacBrlyRlyDetail PnlBrlyRlyDetail::ContIac
#define ContInfBrlyRlyDetail PnlBrlyRlyDetail::ContInf
#define StatAppBrlyRlyDetail PnlBrlyRlyDetail::StatApp
#define StatShrBrlyRlyDetail PnlBrlyRlyDetail::StatShr
#define TagBrlyRlyDetail PnlBrlyRlyDetail::Tag

#define DpchAppBrlyRlyDetailData PnlBrlyRlyDetail::DpchAppData
#define DpchAppBrlyRlyDetailDo PnlBrlyRlyDetail::DpchAppDo
#define DpchEngBrlyRlyDetailData PnlBrlyRlyDetail::DpchEngData

/**
  * PnlBrlyRlyDetail
  */
class PnlBrlyRlyDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyRlyDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTCONVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyRlyDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFSTA = 1;
		static const uint TXFSTO = 2;
		static const uint NUMFPUPDIR = 3;
		static const uint CHKCTD = 4;
		static const uint TXFNHP = 5;

	public:
		ContIac(const string& TxfSta = "", const string& TxfSto = "", const uint numFPupDir = 1, const bool ChkCtd = false, const string& TxfNhp = "");

	public:
		string TxfSta;
		string TxfSto;
		uint numFPupDir;
		bool ChkCtd;
		string TxfNhp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyRlyDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTCON = 1;

	public:
		ContInf(const string& TxtCon = "");

	public:
		string TxtCon;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyRlyDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyRlyDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXFSTAACTIVE = 3;
		static const uint TXFSTOACTIVE = 4;
		static const uint TXTCONACTIVE = 5;
		static const uint BUTCONVIEWAVAIL = 6;
		static const uint BUTCONVIEWACTIVE = 7;
		static const uint PUPDIRACTIVE = 8;
		static const uint CHKCTDACTIVE = 9;
		static const uint TXFNHPACTIVE = 10;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxtConActive = true, const bool ButConViewAvail = true, const bool ButConViewActive = true, const bool PupDirActive = true, const bool ChkCtdActive = true, const bool TxfNhpActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxtConActive;
		bool ButConViewAvail;
		bool ButConViewActive;
		bool PupDirActive;
		bool ChkCtdActive;
		bool TxfNhpActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyRlyDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyRlyDetailData)
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
		* DpchAppDo (full: DpchAppBrlyRlyDetailDo)
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
		* DpchEngData (full: DpchEngBrlyRlyDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPDIR = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;
		static const uint ALL = 8;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupDir = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupDir;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxfStaActive(DbsBrly* dbsbrly);
	bool evalTxfStoActive(DbsBrly* dbsbrly);
	bool evalTxtConActive(DbsBrly* dbsbrly);
	bool evalButConViewAvail(DbsBrly* dbsbrly);
	bool evalButConViewActive(DbsBrly* dbsbrly);
	bool evalPupDirActive(DbsBrly* dbsbrly);
	bool evalChkCtdActive(DbsBrly* dbsbrly);
	bool evalTxfNhpActive(DbsBrly* dbsbrly);

public:
	PnlBrlyRlyDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyRlyDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupDir;

	BrlyMRelay recRly;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshRecRly(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButConViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyRly_conEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyRlyUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

