/**
  * \file PnlBrlyUsrDetail.h
  * job handler for job PnlBrlyUsrDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYUSRDETAIL_H
#define PNLBRLYUSRDETAIL_H

// IP custInclude --- INSERT

#define VecVBrlyUsrDetailDo PnlBrlyUsrDetail::VecVDo

#define ContIacBrlyUsrDetail PnlBrlyUsrDetail::ContIac
#define ContInfBrlyUsrDetail PnlBrlyUsrDetail::ContInf
#define StatAppBrlyUsrDetail PnlBrlyUsrDetail::StatApp
#define StatShrBrlyUsrDetail PnlBrlyUsrDetail::StatShr
#define TagBrlyUsrDetail PnlBrlyUsrDetail::Tag

#define DpchAppBrlyUsrDetailData PnlBrlyUsrDetail::DpchAppData
#define DpchAppBrlyUsrDetailDo PnlBrlyUsrDetail::DpchAppDo
#define DpchEngBrlyUsrDetailData PnlBrlyUsrDetail::DpchEngData

/**
  * PnlBrlyUsrDetail
  */
class PnlBrlyUsrDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyUsrDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTPRSVIEWCLICK = 2;
		static const uint BUTUSGVIEWCLICK = 3;
		static const uint BUTJSTEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyUsrDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPJST = 1;
		static const uint NUMFPUPSTE = 2;
		static const uint NUMFPUPLCL = 3;
		static const uint NUMFPUPULV = 4;
		static const uint TXFPWD = 5;

	public:
		ContIac(const uint numFPupJst = 1, const uint numFPupSte = 1, const uint numFPupLcl = 1, const uint numFPupUlv = 1, const string& TxfPwd = "");

	public:
		uint numFPupJst;
		uint numFPupSte;
		uint numFPupLcl;
		uint numFPupUlv;
		string TxfPwd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyUsrDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTPRS = 1;
		static const uint TXTSRF = 2;
		static const uint TXTUSG = 3;

	public:
		ContInf(const string& TxtPrs = "", const string& TxtSrf = "", const string& TxtUsg = "");

	public:
		string TxtPrs;
		string TxtSrf;
		string TxtUsg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyUsrDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyUsrDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTPRSACTIVE = 3;
		static const uint BUTPRSVIEWAVAIL = 4;
		static const uint BUTPRSVIEWACTIVE = 5;
		static const uint TXTSRFACTIVE = 6;
		static const uint TXTUSGACTIVE = 7;
		static const uint BUTUSGVIEWAVAIL = 8;
		static const uint BUTUSGVIEWACTIVE = 9;
		static const uint PUPJSTACTIVE = 10;
		static const uint BUTJSTEDITAVAIL = 11;
		static const uint PUPSTEACTIVE = 12;
		static const uint PUPLCLACTIVE = 13;
		static const uint PUPULVACTIVE = 14;
		static const uint TXFPWDACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrsActive = true, const bool ButPrsViewAvail = true, const bool ButPrsViewActive = true, const bool TxtSrfActive = true, const bool TxtUsgActive = true, const bool ButUsgViewAvail = true, const bool ButUsgViewActive = true, const bool PupJstActive = true, const bool ButJstEditAvail = true, const bool PupSteActive = true, const bool PupLclActive = true, const bool PupUlvActive = true, const bool TxfPwdActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrsActive;
		bool ButPrsViewAvail;
		bool ButPrsViewActive;
		bool TxtSrfActive;
		bool TxtUsgActive;
		bool ButUsgViewAvail;
		bool ButUsgViewActive;
		bool PupJstActive;
		bool ButJstEditAvail;
		bool PupSteActive;
		bool PupLclActive;
		bool PupUlvActive;
		bool TxfPwdActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyUsrDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyUsrDetailData)
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
		* DpchAppDo (full: DpchAppBrlyUsrDetailDo)
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
		* DpchEngData (full: DpchEngBrlyUsrDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPJST = 4;
		static const uint FEEDFPUPLCL = 5;
		static const uint FEEDFPUPSTE = 6;
		static const uint FEEDFPUPULV = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint TAG = 10;
		static const uint ALL = 11;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupJst = NULL, Feed* feedFPupLcl = NULL, Feed* feedFPupSte = NULL, Feed* feedFPupUlv = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupJst;
		Feed feedFPupLcl;
		Feed feedFPupSte;
		Feed feedFPupUlv;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtPrsActive(DbsBrly* dbsbrly);
	bool evalButPrsViewAvail(DbsBrly* dbsbrly);
	bool evalButPrsViewActive(DbsBrly* dbsbrly);
	bool evalTxtSrfActive(DbsBrly* dbsbrly);
	bool evalTxtUsgActive(DbsBrly* dbsbrly);
	bool evalButUsgViewAvail(DbsBrly* dbsbrly);
	bool evalButUsgViewActive(DbsBrly* dbsbrly);
	bool evalPupJstActive(DbsBrly* dbsbrly);
	bool evalButJstEditAvail(DbsBrly* dbsbrly);
	bool evalPupSteActive(DbsBrly* dbsbrly);
	bool evalPupLclActive(DbsBrly* dbsbrly);
	bool evalPupUlvActive(DbsBrly* dbsbrly);
	bool evalTxfPwdActive(DbsBrly* dbsbrly);

public:
	PnlBrlyUsrDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyUsrDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupJst;
	Feed feedFPupLcl;
	Feed feedFPupSte;
	Feed feedFPupUlv;

	BrlyMUser recUsr;

	BrlyJMUserState recUsrJste;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshJst(DbsBrly* dbsbrly, set<uint>& moditems);

	void refreshRecUsr(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshRecUsrJste(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButUsgViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButJstEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyUsr_prsEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyUsr_usgEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyUsrUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyUsrJsteMod_usrEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

