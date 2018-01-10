/**
  * \file PnlBrlyPrsDetail.h
  * job handler for job PnlBrlyPrsDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYPRSDETAIL_H
#define PNLBRLYPRSDETAIL_H

// IP custInclude --- INSERT

#define VecVBrlyPrsDetailDo PnlBrlyPrsDetail::VecVDo

#define ContIacBrlyPrsDetail PnlBrlyPrsDetail::ContIac
#define ContInfBrlyPrsDetail PnlBrlyPrsDetail::ContInf
#define StatAppBrlyPrsDetail PnlBrlyPrsDetail::StatApp
#define StatShrBrlyPrsDetail PnlBrlyPrsDetail::StatShr
#define TagBrlyPrsDetail PnlBrlyPrsDetail::Tag

#define DpchAppBrlyPrsDetailData PnlBrlyPrsDetail::DpchAppData
#define DpchAppBrlyPrsDetailDo PnlBrlyPrsDetail::DpchAppDo
#define DpchEngBrlyPrsDetailData PnlBrlyPrsDetail::DpchEngData

/**
  * PnlBrlyPrsDetail
  */
class PnlBrlyPrsDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyPrsDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJLNEDITCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyPrsDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint TXFFNM = 2;
		static const uint NUMFPUPJLN = 3;
		static const uint NUMSFLSTDRV = 4;
		static const uint NUMFPUPSEX = 5;
		static const uint TXFTEL = 6;
		static const uint TXFEML = 7;
		static const uint TXFSAL = 8;

	public:
		ContIac(const string& TxfTit = "", const string& TxfFnm = "", const uint numFPupJln = 1, const vector<uint>& numsFLstDrv = {}, const uint numFPupSex = 1, const string& TxfTel = "", const string& TxfEml = "", const string& TxfSal = "");

	public:
		string TxfTit;
		string TxfFnm;
		uint numFPupJln;
		vector<uint> numsFLstDrv;
		uint numFPupSex;
		string TxfTel;
		string TxfEml;
		string TxfSal;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyPrsDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTLNM = 1;
		static const uint TXTDRV = 2;

	public:
		ContInf(const string& TxtLnm = "", const string& TxtDrv = "");

	public:
		string TxtLnm;
		string TxtDrv;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyPrsDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstDrvAlt = true, const uint LstDrvNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyPrsDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXFTITACTIVE = 3;
		static const uint TXFFNMACTIVE = 4;
		static const uint PUPJLNACTIVE = 5;
		static const uint BUTJLNEDITAVAIL = 6;
		static const uint TXTLNMACTIVE = 7;
		static const uint LSTDRVACTIVE = 8;
		static const uint PUPSEXACTIVE = 9;
		static const uint TXFTELACTIVE = 10;
		static const uint TXFEMLACTIVE = 11;
		static const uint TXFSALACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxfFnmActive = true, const bool PupJlnActive = true, const bool ButJlnEditAvail = true, const bool TxtLnmActive = true, const bool LstDrvActive = true, const bool PupSexActive = true, const bool TxfTelActive = true, const bool TxfEmlActive = true, const bool TxfSalActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxfFnmActive;
		bool PupJlnActive;
		bool ButJlnEditAvail;
		bool TxtLnmActive;
		bool LstDrvActive;
		bool PupSexActive;
		bool TxfTelActive;
		bool TxfEmlActive;
		bool TxfSalActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyPrsDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyPrsDetailData)
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
		* DpchAppDo (full: DpchAppBrlyPrsDetailDo)
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
		* DpchEngData (full: DpchEngBrlyPrsDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTDRV = 4;
		static const uint FEEDFPUPJLN = 5;
		static const uint FEEDFPUPSEX = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;
		static const uint ALL = 10;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstDrv = NULL, Feed* feedFPupJln = NULL, Feed* feedFPupSex = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstDrv;
		Feed feedFPupJln;
		Feed feedFPupSex;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxfTitActive(DbsBrly* dbsbrly);
	bool evalTxfFnmActive(DbsBrly* dbsbrly);
	bool evalPupJlnActive(DbsBrly* dbsbrly);
	bool evalButJlnEditAvail(DbsBrly* dbsbrly);
	bool evalTxtLnmActive(DbsBrly* dbsbrly);
	bool evalLstDrvActive(DbsBrly* dbsbrly);
	bool evalPupSexActive(DbsBrly* dbsbrly);
	bool evalTxfTelActive(DbsBrly* dbsbrly);
	bool evalTxfEmlActive(DbsBrly* dbsbrly);
	bool evalTxfSalActive(DbsBrly* dbsbrly);

public:
	PnlBrlyPrsDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyPrsDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstDrv;
	Feed feedFPupJln;
	Feed feedFPupSex;

	BrlyMPerson recPrs;

	BrlyJMPersonLastname recPrsJlnm;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshJln(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshTxtDrv(DbsBrly* dbsbrly, set<uint>& moditems);

	void refreshRecPrs(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshRecPrsJlnm(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButJlnEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyPrsUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyPrsJlnmMod_prsEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

