/**
  * \file DlgBrlyLegNew.h
  * job handler for job DlgBrlyLegNew (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef DLGBRLYLEGNEW_H
#define DLGBRLYLEGNEW_H

// IP custInclude --- INSERT

#define VecVDlgBrlyLegNewDit DlgBrlyLegNew::VecVDit
#define VecVDlgBrlyLegNewDo DlgBrlyLegNew::VecVDo
#define VecVDlgBrlyLegNewDoDet DlgBrlyLegNew::VecVDoDet
#define VecVDlgBrlyLegNewDoInc DlgBrlyLegNew::VecVDoInc
#define VecVDlgBrlyLegNewSge DlgBrlyLegNew::VecVSge

#define ContIacDlgBrlyLegNew DlgBrlyLegNew::ContIac
#define ContIacDlgBrlyLegNewDet DlgBrlyLegNew::ContIacDet
#define ContInfDlgBrlyLegNew DlgBrlyLegNew::ContInf
#define ContInfDlgBrlyLegNewInc DlgBrlyLegNew::ContInfInc
#define StatAppDlgBrlyLegNew DlgBrlyLegNew::StatApp
#define StatShrDlgBrlyLegNew DlgBrlyLegNew::StatShr
#define StatShrDlgBrlyLegNewDet DlgBrlyLegNew::StatShrDet
#define StatShrDlgBrlyLegNewInc DlgBrlyLegNew::StatShrInc
#define TagDlgBrlyLegNew DlgBrlyLegNew::Tag
#define TagDlgBrlyLegNewDet DlgBrlyLegNew::TagDet
#define TagDlgBrlyLegNewInc DlgBrlyLegNew::TagInc

#define DpchAppDlgBrlyLegNewData DlgBrlyLegNew::DpchAppData
#define DpchAppDlgBrlyLegNewDo DlgBrlyLegNew::DpchAppDo
#define DpchEngDlgBrlyLegNewData DlgBrlyLegNew::DpchEngData

/**
  * DlgBrlyLegNew
  */
class DlgBrlyLegNew : public JobBrly {

public:
	/**
		* VecVDit (full: VecVDlgBrlyLegNewDit)
		*/
	class VecVDit {

	public:
		static const uint DET = 1;
		static const uint INC = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgBrlyLegNewDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgBrlyLegNewDoDet)
		*/
	class VecVDoDet {

	public:
		static const uint BUTCRECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoInc (full: VecVDlgBrlyLegNewDoInc)
		*/
	class VecVDoInc {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyLegNewSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint CREATE = 2;
		static const uint CREDONE = 3;
		static const uint INCO = 4;
		static const uint DONE = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyLegNew)
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
	  * ContIacDet (full: ContIacDlgBrlyLegNewDet)
	  */
	class ContIacDet : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint TXFBGN = 2;
		static const uint TXFEND = 3;

	public:
		ContIacDet(const uint numFPupTyp = 1, const string& TxfBgn = "", const string& TxfEnd = "");

	public:
		uint numFPupTyp;
		string TxfBgn;
		string TxfEnd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacDet* comp);
		set<uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyLegNew)
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
	  * ContInfInc (full: ContInfDlgBrlyLegNewInc)
	  */
	class ContInfInc : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfInc(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfInc* comp);
		set<uint> diff(const ContInfInc* comp);
	};

	/**
		* StatApp (full: StatAppDlgBrlyLegNew)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgBrlyLegNew)
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
		* StatShrDet (full: StatShrDlgBrlyLegNewDet)
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
		* StatShrInc (full: StatShrDlgBrlyLegNewInc)
		*/
	class StatShrInc : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrInc(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrInc* comp);
		set<uint> diff(const StatShrInc* comp);
	};

	/**
		* Tag (full: TagDlgBrlyLegNew)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgBrlyLegNewDet)
		*/
	class TagDet {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagInc (full: TagDlgBrlyLegNewInc)
		*/
	class TagInc {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyLegNewData)
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
		* DpchAppDo (full: DpchAppDlgBrlyLegNewDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDODET = 3;
		static const uint IXVDOINC = 4;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoDet;
		uint ixVDoInc;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyLegNewData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACDET = 3;
		static const uint CONTINF = 4;
		static const uint CONTINFINC = 5;
		static const uint FEEDFDETPUPTYP = 6;
		static const uint FEEDFDSE = 7;
		static const uint FEEDFSGE = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint STATSHRDET = 11;
		static const uint STATSHRINC = 12;
		static const uint TAG = 13;
		static const uint TAGDET = 14;
		static const uint TAGINC = 15;
		static const uint ALL = 16;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, ContInfInc* continfinc = NULL, Feed* feedFDetPupTyp = NULL, Feed* feedFDse = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrDet* statshrdet = NULL, StatShrInc* statshrinc = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfInc continfinc;
		Feed feedFDetPupTyp;
		Feed feedFDse;
		Feed feedFSge;
		StatShr statshr;
		StatShrDet statshrdet;
		StatShrInc statshrinc;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalDetButCreActive(DbsBrly* dbsbrly);
	bool evalIncButRunActive(DbsBrly* dbsbrly);
	bool evalIncButStoActive(DbsBrly* dbsbrly);
	bool evalButDneActive(DbsBrly* dbsbrly);

public:
	DlgBrlyLegNew(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~DlgBrlyLegNew();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	ContInfInc continfinc;
	StatShr statshr;
	StatShrDet statshrdet;
	StatShrInc statshrinc;

	Feed feedFDetPupTyp;
	Feed feedFDse;
	Feed feedFSge;

	uint ixVDit;

	bool valid;

	// IP custVar --- INSERT

public:
// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	void sphrToCart(double _r, double _theta, double _phi, double** _vec);
	double degToRad(double _deg);
	double radToDeg(double _rad);
// IP cust --- IEND

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshDet(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshInc(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

public:
	void changeStage(DbsBrly* dbsbrly, uint _ixVSge, DpchEngBrly** dpcheng = NULL);

	uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	uint enterSgeCreate(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCreate(DbsBrly* dbsbrly);
	uint enterSgeCredone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCredone(DbsBrly* dbsbrly);
	uint enterSgeInco(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeInco(DbsBrly* dbsbrly);
	uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

	string getSquawk(DbsBrly* dbsbrly);

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiacdet(DbsBrly* dbsbrly, ContIacDet* _contiacdet, DpchEngBrly** dpcheng);

	void handleDpchAppDoButDneClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoDetButCreClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoIncButRunClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoIncButStoClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleTimer(DbsBrly* dbsbrly, const string& sref);

};

#endif


