/**
  * \file PnlBrlyNavBase.h
  * job handler for job PnlBrlyNavBase (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYNAVBASE_H
#define PNLBRLYNAVBASE_H

// IP custInclude --- INSERT

#define VecVBrlyNavBaseDo PnlBrlyNavBase::VecVDo

#define ContIacBrlyNavBase PnlBrlyNavBase::ContIac
#define StatAppBrlyNavBase PnlBrlyNavBase::StatApp
#define StatShrBrlyNavBase PnlBrlyNavBase::StatShr
#define TagBrlyNavBase PnlBrlyNavBase::Tag

#define DpchAppBrlyNavBaseData PnlBrlyNavBase::DpchAppData
#define DpchAppBrlyNavBaseDo PnlBrlyNavBase::DpchAppDo
#define DpchEngBrlyNavBaseData PnlBrlyNavBase::DpchEngData

/**
  * PnlBrlyNavBase
  */
class PnlBrlyNavBase : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyNavBaseDo)
		*/
	class VecVDo {

	public:
		static const uint BUTREGVIEWCLICK = 1;
		static const uint BUTREGNEWCRDCLICK = 2;
		static const uint BUTLOCVIEWCLICK = 3;
		static const uint BUTLOCNEWCRDCLICK = 4;
		static const uint BUTLEGVIEWCLICK = 5;
		static const uint BUTLEGNEWCRDCLICK = 6;
		static const uint BUTTTBVIEWCLICK = 7;
		static const uint BUTTTBNEWCRDCLICK = 8;
		static const uint BUTFLTVIEWCLICK = 9;
		static const uint BUTFLTNEWCRDCLICK = 10;
		static const uint BUTSEGVIEWCLICK = 11;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyNavBase)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTREG = 1;
		static const uint NUMFLSTLOC = 2;
		static const uint NUMFLSTLEG = 3;
		static const uint NUMFLSTTTB = 4;
		static const uint NUMFLSTFLT = 5;
		static const uint NUMFLSTSEG = 6;

	public:
		ContIac(const uint numFLstReg = 1, const uint numFLstLoc = 1, const uint numFLstLeg = 1, const uint numFLstTtb = 1, const uint numFLstFlt = 1, const uint numFLstSeg = 1);

	public:
		uint numFLstReg;
		uint numFLstLoc;
		uint numFLstLeg;
		uint numFLstTtb;
		uint numFLstFlt;
		uint numFLstSeg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppBrlyNavBase)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstRegAlt = true, const bool LstLocAlt = true, const bool LstLegAlt = true, const bool LstTtbAlt = true, const bool LstFltAlt = true, const bool LstSegAlt = true, const uint LstRegNumFirstdisp = 1, const uint LstLocNumFirstdisp = 1, const uint LstLegNumFirstdisp = 1, const uint LstTtbNumFirstdisp = 1, const uint LstFltNumFirstdisp = 1, const uint LstSegNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyNavBase)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTREGAVAIL = 1;
		static const uint BUTREGVIEWACTIVE = 2;
		static const uint LSTLOCAVAIL = 3;
		static const uint BUTLOCVIEWACTIVE = 4;
		static const uint LSTLEGAVAIL = 5;
		static const uint BUTLEGVIEWACTIVE = 6;
		static const uint LSTTTBAVAIL = 7;
		static const uint BUTTTBVIEWACTIVE = 8;
		static const uint LSTFLTAVAIL = 9;
		static const uint BUTFLTVIEWACTIVE = 10;
		static const uint LSTSEGAVAIL = 11;
		static const uint BUTSEGVIEWACTIVE = 12;

	public:
		StatShr(const bool LstRegAvail = true, const bool ButRegViewActive = true, const bool LstLocAvail = true, const bool ButLocViewActive = true, const bool LstLegAvail = true, const bool ButLegViewActive = true, const bool LstTtbAvail = true, const bool ButTtbViewActive = true, const bool LstFltAvail = true, const bool ButFltViewActive = true, const bool LstSegAvail = true, const bool ButSegViewActive = true);

	public:
		bool LstRegAvail;
		bool ButRegViewActive;
		bool LstLocAvail;
		bool ButLocViewActive;
		bool LstLegAvail;
		bool ButLegViewActive;
		bool LstTtbAvail;
		bool ButTtbViewActive;
		bool LstFltAvail;
		bool ButFltViewActive;
		bool LstSegAvail;
		bool ButSegViewActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyNavBase)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyNavBaseData)
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
		* DpchAppDo (full: DpchAppBrlyNavBaseDo)
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
		* DpchEngData (full: DpchEngBrlyNavBaseData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTFLT = 3;
		static const uint FEEDFLSTLEG = 4;
		static const uint FEEDFLSTLOC = 5;
		static const uint FEEDFLSTREG = 6;
		static const uint FEEDFLSTSEG = 7;
		static const uint FEEDFLSTTTB = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstFlt = NULL, Feed* feedFLstLeg = NULL, Feed* feedFLstLoc = NULL, Feed* feedFLstReg = NULL, Feed* feedFLstSeg = NULL, Feed* feedFLstTtb = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstFlt;
		Feed feedFLstLeg;
		Feed feedFLstLoc;
		Feed feedFLstReg;
		Feed feedFLstSeg;
		Feed feedFLstTtb;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstRegAvail(DbsBrly* dbsbrly);
	bool evalButRegViewActive(DbsBrly* dbsbrly);
	bool evalLstLocAvail(DbsBrly* dbsbrly);
	bool evalButLocViewActive(DbsBrly* dbsbrly);
	bool evalLstLegAvail(DbsBrly* dbsbrly);
	bool evalButLegViewActive(DbsBrly* dbsbrly);
	bool evalLstTtbAvail(DbsBrly* dbsbrly);
	bool evalButTtbViewActive(DbsBrly* dbsbrly);
	bool evalLstFltAvail(DbsBrly* dbsbrly);
	bool evalButFltViewActive(DbsBrly* dbsbrly);
	bool evalLstSegAvail(DbsBrly* dbsbrly);
	bool evalButSegViewActive(DbsBrly* dbsbrly);

public:
	PnlBrlyNavBase(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyNavBase();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstFlt;
	Feed feedFLstLeg;
	Feed feedFLstLoc;
	Feed feedFLstReg;
	Feed feedFLstSeg;
	Feed feedFLstTtb;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshLstReg(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshReg(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstLoc(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLoc(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstLeg(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLeg(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstTtb(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshTtb(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstFlt(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshFlt(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLstSeg(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshSeg(DbsBrly* dbsbrly, set<uint>& moditems);
	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButRegViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRegNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButLocViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButLocNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButLegViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButLegNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButTtbViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButTtbNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFltViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFltNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButSegViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyHusrRunvMod_crdUsrEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif

