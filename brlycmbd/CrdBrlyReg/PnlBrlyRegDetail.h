/**
  * \file PnlBrlyRegDetail.h
  * job handler for job PnlBrlyRegDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYREGDETAIL_H
#define PNLBRLYREGDETAIL_H

// IP custInclude --- INSERT

#define VecVBrlyRegDetailDo PnlBrlyRegDetail::VecVDo

#define ContIacBrlyRegDetail PnlBrlyRegDetail::ContIac
#define ContInfBrlyRegDetail PnlBrlyRegDetail::ContInf
#define StatAppBrlyRegDetail PnlBrlyRegDetail::StatApp
#define StatShrBrlyRegDetail PnlBrlyRegDetail::StatShr
#define TagBrlyRegDetail PnlBrlyRegDetail::Tag

#define DpchAppBrlyRegDetailData PnlBrlyRegDetail::DpchAppData
#define DpchAppBrlyRegDetailDo PnlBrlyRegDetail::DpchAppDo
#define DpchEngBrlyRegDetailData PnlBrlyRegDetail::DpchEngData

/**
  * PnlBrlyRegDetail
  */
class PnlBrlyRegDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyRegDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJTIEDITCLICK = 2;
		static const uint BUTSUPVIEWCLICK = 3;
		static const uint BUTJEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyRegDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPJTI = 1;
		static const uint NUMFPUPJ = 2;
		static const uint NUMFPUPDST = 3;

	public:
		ContIac(const uint numFPupJti = 1, const uint numFPupJ = 1, const uint numFPupDst = 1);

	public:
		uint numFPupJti;
		uint numFPupJ;
		uint numFPupDst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyRegDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTTIT = 2;
		static const uint TXTSUP = 3;
		static const uint TXTTOF = 4;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtTit = "", const string& TxtSup = "", const string& TxtTof = "");

	public:
		string TxtSrf;
		string TxtTit;
		string TxtSup;
		string TxtTof;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyRegDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyRegDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTSRFACTIVE = 3;
		static const uint PUPJTIACTIVE = 4;
		static const uint BUTJTIEDITAVAIL = 5;
		static const uint TXTTITACTIVE = 6;
		static const uint TXTSUPACTIVE = 7;
		static const uint BUTSUPVIEWAVAIL = 8;
		static const uint BUTSUPVIEWACTIVE = 9;
		static const uint PUPJACTIVE = 10;
		static const uint BUTJEDITAVAIL = 11;
		static const uint PUPDSTACTIVE = 12;
		static const uint TXTTOFACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool PupDstActive = true, const bool TxtTofActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool PupDstActive;
		bool TxtTofActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyRegDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyRegDetailData)
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
		* DpchAppDo (full: DpchAppBrlyRegDetailDo)
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
		* DpchEngData (full: DpchEngBrlyRegDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPDST = 4;
		static const uint FEEDFPUPJ = 5;
		static const uint FEEDFPUPJTI = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;
		static const uint ALL = 10;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupDst = NULL, Feed* feedFPupJ = NULL, Feed* feedFPupJti = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupDst;
		Feed feedFPupJ;
		Feed feedFPupJti;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtSrfActive(DbsBrly* dbsbrly);
	bool evalPupJtiActive(DbsBrly* dbsbrly);
	bool evalButJtiEditAvail(DbsBrly* dbsbrly);
	bool evalTxtTitActive(DbsBrly* dbsbrly);
	bool evalTxtSupActive(DbsBrly* dbsbrly);
	bool evalButSupViewAvail(DbsBrly* dbsbrly);
	bool evalButSupViewActive(DbsBrly* dbsbrly);
	bool evalPupJActive(DbsBrly* dbsbrly);
	bool evalButJEditAvail(DbsBrly* dbsbrly);
	bool evalPupDstActive(DbsBrly* dbsbrly);
	bool evalTxtTofActive(DbsBrly* dbsbrly);

public:
	PnlBrlyRegDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyRegDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupDst;
	Feed feedFPupJ;
	Feed feedFPupJti;

	BrlyMRegion recReg;
	uint ixWSubsetReg;

	BrlyJMRegionTitle recRegJtit;

	BrlyJMRegion recRegJ;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshJti(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshJ(DbsBrly* dbsbrly, set<uint>& moditems);

	void refreshRecReg(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshRecRegJtit(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshRecRegJ(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButJtiEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButSupViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButJEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyReg_inSbs(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, bool& boolvalRet);
	bool handleCallBrlyReg_isLeaf(DbsBrly* dbsbrly, const ubigint jrefTrig, bool& boolvalRet);
	bool handleCallBrlyReg_supEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyRegUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyRegJtitMod_regEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyRegJMod_regEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

