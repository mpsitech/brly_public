/**
  * \file DlgBrlyNavLoaini.h
  * job handler for job DlgBrlyNavLoaini (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef DLGBRLYNAVLOAINI_H
#define DLGBRLYNAVLOAINI_H

// IP custInclude --- INSERT

#include "IexBrlyIni.h"

#define VecVDlgBrlyNavLoainiDit DlgBrlyNavLoaini::VecVDit
#define VecVDlgBrlyNavLoainiDo DlgBrlyNavLoaini::VecVDo
#define VecVDlgBrlyNavLoainiDoImp DlgBrlyNavLoaini::VecVDoImp
#define VecVDlgBrlyNavLoainiDoPpr DlgBrlyNavLoaini::VecVDoPpr
#define VecVDlgBrlyNavLoainiSge DlgBrlyNavLoaini::VecVSge

#define ContIacDlgBrlyNavLoaini DlgBrlyNavLoaini::ContIac
#define ContInfDlgBrlyNavLoaini DlgBrlyNavLoaini::ContInf
#define ContInfDlgBrlyNavLoainiImp DlgBrlyNavLoaini::ContInfImp
#define ContInfDlgBrlyNavLoainiPpr DlgBrlyNavLoaini::ContInfPpr
#define StatAppDlgBrlyNavLoaini DlgBrlyNavLoaini::StatApp
#define StatShrDlgBrlyNavLoaini DlgBrlyNavLoaini::StatShr
#define StatShrDlgBrlyNavLoainiIfi DlgBrlyNavLoaini::StatShrIfi
#define StatShrDlgBrlyNavLoainiImp DlgBrlyNavLoaini::StatShrImp
#define StatShrDlgBrlyNavLoainiLfi DlgBrlyNavLoaini::StatShrLfi
#define StatShrDlgBrlyNavLoainiPpr DlgBrlyNavLoaini::StatShrPpr
#define TagDlgBrlyNavLoaini DlgBrlyNavLoaini::Tag
#define TagDlgBrlyNavLoainiIfi DlgBrlyNavLoaini::TagIfi
#define TagDlgBrlyNavLoainiImp DlgBrlyNavLoaini::TagImp
#define TagDlgBrlyNavLoainiLfi DlgBrlyNavLoaini::TagLfi
#define TagDlgBrlyNavLoainiPpr DlgBrlyNavLoaini::TagPpr

#define DpchAppDlgBrlyNavLoainiData DlgBrlyNavLoaini::DpchAppData
#define DpchAppDlgBrlyNavLoainiDo DlgBrlyNavLoaini::DpchAppDo
#define DpchEngDlgBrlyNavLoainiData DlgBrlyNavLoaini::DpchEngData

/**
  * DlgBrlyNavLoaini
  */
class DlgBrlyNavLoaini : public JobBrly {

public:
	/**
		* VecVDit (full: VecVDlgBrlyNavLoainiDit)
		*/
	class VecVDit {

	public:
		static const uint IFI = 1;
		static const uint IMP = 2;
		static const uint PPR = 3;
		static const uint LFI = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgBrlyNavLoainiDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgBrlyNavLoainiDoImp)
		*/
	class VecVDoImp {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoPpr (full: VecVDlgBrlyNavLoainiDoPpr)
		*/
	class VecVDoPpr {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyNavLoainiSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint PRSIDLE = 2;
		static const uint PARSE = 3;
		static const uint ALRBRLYPER = 4;
		static const uint PRSDONE = 5;
		static const uint IMPIDLE = 6;
		static const uint IMPORT = 7;
		static const uint IMPDONE = 8;
		static const uint POSTPRC = 9;
		static const uint DONE = 10;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyNavLoaini)
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
	  * ContInf (full: ContInfDlgBrlyNavLoaini)
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
	  * ContInfImp (full: ContInfDlgBrlyNavLoainiImp)
	  */
	class ContInfImp : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfImp(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfImp* comp);
		set<uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfPpr (full: ContInfDlgBrlyNavLoainiPpr)
	  */
	class ContInfPpr : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfPpr(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfPpr* comp);
		set<uint> diff(const ContInfPpr* comp);
	};

	/**
		* StatApp (full: StatAppDlgBrlyNavLoaini)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgBrlyNavLoaini)
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
		* StatShrIfi (full: StatShrDlgBrlyNavLoainiIfi)
		*/
	class StatShrIfi : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrIfi* comp);
		set<uint> diff(const StatShrIfi* comp);
	};

	/**
		* StatShrImp (full: StatShrDlgBrlyNavLoainiImp)
		*/
	class StatShrImp : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrImp* comp);
		set<uint> diff(const StatShrImp* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgBrlyNavLoainiLfi)
		*/
	class StatShrLfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrLfi* comp);
		set<uint> diff(const StatShrLfi* comp);
	};

	/**
		* StatShrPpr (full: StatShrDlgBrlyNavLoainiPpr)
		*/
	class StatShrPpr : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrPpr(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrPpr* comp);
		set<uint> diff(const StatShrPpr* comp);
	};

	/**
		* Tag (full: TagDlgBrlyNavLoaini)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagIfi (full: TagDlgBrlyNavLoainiIfi)
		*/
	class TagIfi {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagImp (full: TagDlgBrlyNavLoainiImp)
		*/
	class TagImp {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgBrlyNavLoainiLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagPpr (full: TagDlgBrlyNavLoainiPpr)
		*/
	class TagPpr {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyNavLoainiData)
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
		* DpchAppDo (full: DpchAppDlgBrlyNavLoainiDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOIMP = 3;
		static const uint IXVDOPPR = 4;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoImp;
		uint ixVDoPpr;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyNavLoainiData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint CONTINFIMP = 4;
		static const uint CONTINFPPR = 5;
		static const uint FEEDFDSE = 6;
		static const uint FEEDFSGE = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint STATSHRIFI = 10;
		static const uint STATSHRIMP = 11;
		static const uint STATSHRLFI = 12;
		static const uint STATSHRPPR = 13;
		static const uint TAG = 14;
		static const uint TAGIFI = 15;
		static const uint TAGIMP = 16;
		static const uint TAGLFI = 17;
		static const uint TAGPPR = 18;
		static const uint ALL = 19;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfImp* continfimp = NULL, ContInfPpr* continfppr = NULL, Feed* feedFDse = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrIfi* statshrifi = NULL, StatShrImp* statshrimp = NULL, StatShrLfi* statshrlfi = NULL, StatShrPpr* statshrppr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfPpr continfppr;
		Feed feedFDse;
		Feed feedFSge;
		StatShr statshr;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;
		StatShrPpr statshrppr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalIfiUldActive(DbsBrly* dbsbrly);
	bool evalImpButRunActive(DbsBrly* dbsbrly);
	bool evalImpButStoActive(DbsBrly* dbsbrly);
	bool evalPprButRunActive(DbsBrly* dbsbrly);
	bool evalPprButStoActive(DbsBrly* dbsbrly);
	bool evalLfiDldActive(DbsBrly* dbsbrly);
	bool evalButDneActive(DbsBrly* dbsbrly);

public:
	DlgBrlyNavLoaini(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~DlgBrlyNavLoaini();

public:
	ContIac contiac;
	ContInf continf;
	ContInfImp continfimp;
	ContInfPpr continfppr;
	StatShr statshr;
	StatShrIfi statshrifi;
	StatShrImp statshrimp;
	StatShrLfi statshrlfi;
	StatShrPpr statshrppr;

	Feed feedFMcbAlert;
	Feed feedFDse;
	Feed feedFSge;

	IexBrlyIni* iex;

	uint ixVDit;

	// IP custVar --- IBEGIN
	string infilename;
	// IP custVar --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshIfi(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshImp(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshPpr(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshLfi(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

public:
	void changeStage(DbsBrly* dbsbrly, uint _ixVSge, DpchEngBrly** dpcheng = NULL);

	uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	uint enterSgePrsidle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgePrsidle(DbsBrly* dbsbrly);
	uint enterSgeParse(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeParse(DbsBrly* dbsbrly);
	uint enterSgeAlrbrlyper(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeAlrbrlyper(DbsBrly* dbsbrly);
	uint enterSgePrsdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgePrsdone(DbsBrly* dbsbrly);
	uint enterSgeImpidle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImpidle(DbsBrly* dbsbrly);
	uint enterSgeImport(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImport(DbsBrly* dbsbrly);
	uint enterSgeImpdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImpdone(DbsBrly* dbsbrly);
	uint enterSgePostprc(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgePostprc(DbsBrly* dbsbrly);
	uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

	string getSquawk(DbsBrly* dbsbrly);

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButDneClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoImpButRunClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoImpButStoClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoPprButRunClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoPprButStoClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

	void handleUpload(DbsBrly* dbsbrly, const string& filename);
	string handleDownload(DbsBrly* dbsbrly);
	void handleTimer(DbsBrly* dbsbrly, const string& sref);

};

#endif


