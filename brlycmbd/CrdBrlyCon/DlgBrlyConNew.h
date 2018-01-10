/**
  * \file DlgBrlyConNew.h
  * job handler for job DlgBrlyConNew (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef DLGBRLYCONNEW_H
#define DLGBRLYCONNEW_H

// IP custInclude --- INSERT

#define VecVDlgBrlyConNewDit DlgBrlyConNew::VecVDit
#define VecVDlgBrlyConNewDo DlgBrlyConNew::VecVDo
#define VecVDlgBrlyConNewDoCal DlgBrlyConNew::VecVDoCal
#define VecVDlgBrlyConNewDoDet DlgBrlyConNew::VecVDoDet
#define VecVDlgBrlyConNewSge DlgBrlyConNew::VecVSge

#define ContIacDlgBrlyConNew DlgBrlyConNew::ContIac
#define ContIacDlgBrlyConNewDet DlgBrlyConNew::ContIacDet
#define ContInfDlgBrlyConNew DlgBrlyConNew::ContInf
#define ContInfDlgBrlyConNewCal DlgBrlyConNew::ContInfCal
#define StatAppDlgBrlyConNew DlgBrlyConNew::StatApp
#define StatShrDlgBrlyConNew DlgBrlyConNew::StatShr
#define StatShrDlgBrlyConNewCal DlgBrlyConNew::StatShrCal
#define StatShrDlgBrlyConNewDet DlgBrlyConNew::StatShrDet
#define TagDlgBrlyConNew DlgBrlyConNew::Tag
#define TagDlgBrlyConNewCal DlgBrlyConNew::TagCal
#define TagDlgBrlyConNewDet DlgBrlyConNew::TagDet

#define DpchAppDlgBrlyConNewData DlgBrlyConNew::DpchAppData
#define DpchAppDlgBrlyConNewDo DlgBrlyConNew::DpchAppDo
#define DpchEngDlgBrlyConNewData DlgBrlyConNew::DpchEngData

/**
  * DlgBrlyConNew
  */
class DlgBrlyConNew : public JobBrly {

public:
	/**
		* VecVDit (full: VecVDlgBrlyConNewDit)
		*/
	class VecVDit {

	public:
		static const uint DET = 1;
		static const uint CAL = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgBrlyConNewDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoCal (full: VecVDlgBrlyConNewDoCal)
		*/
	class VecVDoCal {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgBrlyConNewDoDet)
		*/
	class VecVDoDet {

	public:
		static const uint BUTCRECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyConNewSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint CREATE = 2;
		static const uint CREDONE = 3;
		static const uint CALC1 = 4;
		static const uint CALC2 = 5;
		static const uint CALC3 = 6;
		static const uint CALC4 = 7;
		static const uint DONE = 8;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyConNew)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDSE = 1;

	public:
		ContIac(const uint numFDse = 1);

	public:
		uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacDet (full: ContIacDlgBrlyConNewDet)
	  */
	class ContIacDet : public Block {

	public:
		static const uint TXFFLT = 1;
		static const uint NUMFPUPMDL = 2;
		static const uint NUMFPUPTTB = 3;
		static const uint TXFETY = 4;

	public:
		ContIacDet(const string& TxfFlt = "", const uint numFPupMdl = 1, const uint numFPupTtb = 1, const string& TxfEty = "");

	public:
		string TxfFlt;
		uint numFPupMdl;
		uint numFPupTtb;
		string TxfEty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacDet* comp);
		set<uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyConNew)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;

	public:
		ContInf(const uint numFSge = 1);

	public:
		uint numFSge;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfCal (full: ContInfDlgBrlyConNewCal)
	  */
	class ContInfCal : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfCal(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfCal* comp);
		set<uint> diff(const ContInfCal* comp);
	};

	/**
		* StatApp (full: StatAppDlgBrlyConNew)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgBrlyConNew)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StatShrCal (full: StatShrDlgBrlyConNewCal)
		*/
	class StatShrCal : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrCal(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrCal* comp);
		set<uint> diff(const StatShrCal* comp);
	};

	/**
		* StatShrDet (full: StatShrDlgBrlyConNewDet)
		*/
	class StatShrDet : public Block {

	public:
		static const uint BUTCREACTIVE = 1;

	public:
		StatShrDet(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrDet* comp);
		set<uint> diff(const StatShrDet* comp);
	};

	/**
		* Tag (full: TagDlgBrlyConNew)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagCal (full: TagDlgBrlyConNewCal)
		*/
	class TagCal {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgBrlyConNewDet)
		*/
	class TagDet {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyConNewData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACDET = 3;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgBrlyConNewDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOCAL = 3;
		static const uint IXVDODET = 4;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoCal;
		uint ixVDoDet;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyConNewData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACDET = 3;
		static const uint CONTINF = 4;
		static const uint CONTINFCAL = 5;
		static const uint FEEDFDETPUPMDL = 6;
		static const uint FEEDFDETPUPTTB = 7;
		static const uint FEEDFDSE = 8;
		static const uint FEEDFSGE = 9;
		static const uint STATAPP = 10;
		static const uint STATSHR = 11;
		static const uint STATSHRCAL = 12;
		static const uint STATSHRDET = 13;
		static const uint TAG = 14;
		static const uint TAGCAL = 15;
		static const uint TAGDET = 16;
		static const uint ALL = 17;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, ContInfCal* continfcal = NULL, Feed* feedFDetPupMdl = NULL, Feed* feedFDetPupTtb = NULL, Feed* feedFDse = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrCal* statshrcal = NULL, StatShrDet* statshrdet = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfCal continfcal;
		Feed feedFDetPupMdl;
		Feed feedFDetPupTtb;
		Feed feedFDse;
		Feed feedFSge;
		StatShr statshr;
		StatShrCal statshrcal;
		StatShrDet statshrdet;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalDetButCreActive(DbsBrly* dbsbrly);
	bool evalCalButRunActive(DbsBrly* dbsbrly);
	bool evalCalButStoActive(DbsBrly* dbsbrly);
	bool evalButDneActive(DbsBrly* dbsbrly);

public:
	DlgBrlyConNew(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~DlgBrlyConNew();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	ContInfCal continfcal;
	StatShr statshr;
	StatShrCal statshrcal;
	StatShrDet statshrdet;

	Feed feedFDetPupMdl;
	Feed feedFDetPupTtb;
	Feed feedFDse;
	Feed feedFSge;

	uint ixVDit;

	bool valid;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshDet(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshCal(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

public:
	void changeStage(DbsBrly* dbsbrly, uint _ixVSge, DpchEngBrly** dpcheng = NULL);

	uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	uint enterSgeCreate(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCreate(DbsBrly* dbsbrly);
	uint enterSgeCredone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCredone(DbsBrly* dbsbrly);
	uint enterSgeCalc1(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc1(DbsBrly* dbsbrly);
	uint enterSgeCalc2(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc2(DbsBrly* dbsbrly);
	uint enterSgeCalc3(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc3(DbsBrly* dbsbrly);
	uint enterSgeCalc4(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc4(DbsBrly* dbsbrly);
	uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

	string getSquawk(DbsBrly* dbsbrly);

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiacdet(DbsBrly* dbsbrly, ContIacDet* _contiacdet, DpchEngBrly** dpcheng);

	void handleDpchAppDoButDneClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoCalButRunClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoCalButStoClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoDetButCreClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleTimer(DbsBrly* dbsbrly, const string& sref);

};

#endif

