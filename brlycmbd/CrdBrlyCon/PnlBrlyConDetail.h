/**
  * \file PnlBrlyConDetail.h
  * job handler for job PnlBrlyConDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYCONDETAIL_H
#define PNLBRLYCONDETAIL_H

// IP custInclude --- INSERT

#define VecVBrlyConDetailDo PnlBrlyConDetail::VecVDo

#define ContIacBrlyConDetail PnlBrlyConDetail::ContIac
#define ContInfBrlyConDetail PnlBrlyConDetail::ContInf
#define StatAppBrlyConDetail PnlBrlyConDetail::StatApp
#define StatShrBrlyConDetail PnlBrlyConDetail::StatShr
#define TagBrlyConDetail PnlBrlyConDetail::Tag

#define DpchAppBrlyConDetailData PnlBrlyConDetail::DpchAppData
#define DpchAppBrlyConDetailDo PnlBrlyConDetail::DpchAppDo
#define DpchEngBrlyConDetailData PnlBrlyConDetail::DpchEngData

/**
  * PnlBrlyConDetail
  */
class PnlBrlyConDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyConDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTFLTVIEWCLICK = 2;
		static const uint BUTTTBVIEWCLICK = 3;
		static const uint BUTETYEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyConDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFSTA = 1;
		static const uint TXFSTO = 2;
		static const uint NUMFPUPMOD = 3;
		static const uint NUMSFLSTETY = 4;
		static const uint TXFETY = 5;

	public:
		ContIac(const string& TxfSta = "", const string& TxfSto = "", const uint numFPupMod = 1, const vector<uint>& numsFLstEty = {}, const string& TxfEty = "");

	public:
		string TxfSta;
		string TxfSto;
		uint numFPupMod;
		vector<uint> numsFLstEty;
		string TxfEty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyConDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTFLT = 1;
		static const uint TXTCOR = 2;
		static const uint TXTTTB = 3;

	public:
		ContInf(const string& TxtFlt = "", const string& TxtCor = "", const string& TxtTtb = "");

	public:
		string TxtFlt;
		string TxtCor;
		string TxtTtb;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyConDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstEtyAlt = true, const uint LstEtyNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyConDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFETYVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint TXTFLTACTIVE = 4;
		static const uint BUTFLTVIEWAVAIL = 5;
		static const uint BUTFLTVIEWACTIVE = 6;
		static const uint TXTCORACTIVE = 7;
		static const uint TXFSTAACTIVE = 8;
		static const uint TXFSTOACTIVE = 9;
		static const uint PUPMODACTIVE = 10;
		static const uint TXTTTBACTIVE = 11;
		static const uint BUTTTBVIEWAVAIL = 12;
		static const uint BUTTTBVIEWACTIVE = 13;
		static const uint LSTETYACTIVE = 14;
		static const uint BUTETYEDITAVAIL = 15;

	public:
		StatShr(const bool TxfEtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtFltActive = true, const bool ButFltViewAvail = true, const bool ButFltViewActive = true, const bool TxtCorActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool PupModActive = true, const bool TxtTtbActive = true, const bool ButTtbViewAvail = true, const bool ButTtbViewActive = true, const bool LstEtyActive = true, const bool ButEtyEditAvail = true);

	public:
		bool TxfEtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtFltActive;
		bool ButFltViewAvail;
		bool ButFltViewActive;
		bool TxtCorActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool PupModActive;
		bool TxtTtbActive;
		bool ButTtbViewAvail;
		bool ButTtbViewActive;
		bool LstEtyActive;
		bool ButEtyEditAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyConDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyConDetailData)
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
		* DpchAppDo (full: DpchAppBrlyConDetailDo)
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
		* DpchEngData (full: DpchEngBrlyConDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTETY = 4;
		static const uint FEEDFPUPMOD = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstEty = NULL, Feed* feedFPupMod = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstEty;
		Feed feedFPupMod;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtFltActive(DbsBrly* dbsbrly);
	bool evalButFltViewAvail(DbsBrly* dbsbrly);
	bool evalButFltViewActive(DbsBrly* dbsbrly);
	bool evalTxtCorActive(DbsBrly* dbsbrly);
	bool evalTxfStaActive(DbsBrly* dbsbrly);
	bool evalTxfStoActive(DbsBrly* dbsbrly);
	bool evalPupModActive(DbsBrly* dbsbrly);
	bool evalTxtTtbActive(DbsBrly* dbsbrly);
	bool evalButTtbViewAvail(DbsBrly* dbsbrly);
	bool evalButTtbViewActive(DbsBrly* dbsbrly);
	bool evalLstEtyActive(DbsBrly* dbsbrly);
	bool evalButEtyEditAvail(DbsBrly* dbsbrly);

public:
	PnlBrlyConDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyConDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstEty;
	Feed feedFPupMod;

	BrlyMConnection recCon;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshLstEty(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshTxfEty(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshEty(DbsBrly* dbsbrly, set<uint>& moditems);

	void refreshRecCon(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFltViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButTtbViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEtyEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyCon_fltEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyCon_ttbEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyConUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyKlsAkeyMod_klsEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv);
};

#endif

