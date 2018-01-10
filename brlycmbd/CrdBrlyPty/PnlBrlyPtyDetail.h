/**
  * \file PnlBrlyPtyDetail.h
  * job handler for job PnlBrlyPtyDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYPTYDETAIL_H
#define PNLBRLYPTYDETAIL_H

// IP custInclude --- INSERT

#define VecVBrlyPtyDetailDo PnlBrlyPtyDetail::VecVDo

#define ContIacBrlyPtyDetail PnlBrlyPtyDetail::ContIac
#define ContInfBrlyPtyDetail PnlBrlyPtyDetail::ContInf
#define StatAppBrlyPtyDetail PnlBrlyPtyDetail::StatApp
#define StatShrBrlyPtyDetail PnlBrlyPtyDetail::StatShr
#define TagBrlyPtyDetail PnlBrlyPtyDetail::Tag

#define DpchAppBrlyPtyDetailData PnlBrlyPtyDetail::DpchAppData
#define DpchAppBrlyPtyDetailDo PnlBrlyPtyDetail::DpchAppDo
#define DpchEngBrlyPtyDetailData PnlBrlyPtyDetail::DpchEngData

/**
  * PnlBrlyPtyDetail
  */
class PnlBrlyPtyDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyPtyDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTETYEDITCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyPtyDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPETY = 2;
		static const uint TXFETY = 3;
		static const uint TXFCAP = 4;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupEty = 1, const string& TxfEty = "", const string& TxfCap = "");

	public:
		string TxfTit;
		uint numFPupEty;
		string TxfEty;
		string TxfCap;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyPtyDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;

	public:
		ContInf(const string& TxtSrf = "");

	public:
		string TxtSrf;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyPtyDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool PupEtyAlt = false);
	};

	/**
		* StatShr (full: StatShrBrlyPtyDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFETYVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint TXTSRFACTIVE = 4;
		static const uint TXFTITACTIVE = 5;
		static const uint PUPETYACTIVE = 6;
		static const uint BUTETYEDITAVAIL = 7;
		static const uint TXFCAPACTIVE = 8;

	public:
		StatShr(const bool TxfEtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool PupEtyActive = true, const bool ButEtyEditAvail = true, const bool TxfCapActive = true);

	public:
		bool TxfEtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool PupEtyActive;
		bool ButEtyEditAvail;
		bool TxfCapActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyPtyDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyPtyDetailData)
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
		* DpchAppDo (full: DpchAppBrlyPtyDetailDo)
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
		* DpchEngData (full: DpchEngBrlyPtyDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPETY = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;
		static const uint ALL = 8;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupEty = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupEty;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtSrfActive(DbsBrly* dbsbrly);
	bool evalTxfTitActive(DbsBrly* dbsbrly);
	bool evalPupEtyActive(DbsBrly* dbsbrly);
	bool evalButEtyEditAvail(DbsBrly* dbsbrly);
	bool evalTxfCapActive(DbsBrly* dbsbrly);

public:
	PnlBrlyPtyDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyPtyDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupEty;

	BrlyMPlntype recPty;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshPupEty(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshTxfEty(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshEty(DbsBrly* dbsbrly, set<uint>& moditems);

	void refreshRecPty(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEtyEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyPtyUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyKlsAkeyMod_klsEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv);
};

#endif

