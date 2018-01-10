/**
  * \file DlgBrlyTtbTrlorig.h
  * job handler for job DlgBrlyTtbTrlorig (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef DLGBRLYTTBTRLORIG_H
#define DLGBRLYTTBTRLORIG_H

// IP custInclude --- INSERT

#define VecVDlgBrlyTtbTrlorigDit DlgBrlyTtbTrlorig::VecVDit
#define VecVDlgBrlyTtbTrlorigDo DlgBrlyTtbTrlorig::VecVDo
#define VecVDlgBrlyTtbTrlorigDoTrl DlgBrlyTtbTrlorig::VecVDoTrl
#define VecVDlgBrlyTtbTrlorigSge DlgBrlyTtbTrlorig::VecVSge
#define VecVDlgBrlyTtbTrlorigSrc DlgBrlyTtbTrlorig::VecVSrc

#define ContIacDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::ContIac
#define ContIacDlgBrlyTtbTrlorigDet DlgBrlyTtbTrlorig::ContIacDet
#define ContInfDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::ContInf
#define ContInfDlgBrlyTtbTrlorigTrl DlgBrlyTtbTrlorig::ContInfTrl
#define StatAppDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::StatApp
#define StatShrDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::StatShr
#define StatShrDlgBrlyTtbTrlorigRfi DlgBrlyTtbTrlorig::StatShrRfi
#define StatShrDlgBrlyTtbTrlorigTfi DlgBrlyTtbTrlorig::StatShrTfi
#define StatShrDlgBrlyTtbTrlorigTrl DlgBrlyTtbTrlorig::StatShrTrl
#define TagDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::Tag
#define TagDlgBrlyTtbTrlorigDet DlgBrlyTtbTrlorig::TagDet
#define TagDlgBrlyTtbTrlorigRfi DlgBrlyTtbTrlorig::TagRfi
#define TagDlgBrlyTtbTrlorigTfi DlgBrlyTtbTrlorig::TagTfi
#define TagDlgBrlyTtbTrlorigTrl DlgBrlyTtbTrlorig::TagTrl

#define DpchAppDlgBrlyTtbTrlorigData DlgBrlyTtbTrlorig::DpchAppData
#define DpchAppDlgBrlyTtbTrlorigDo DlgBrlyTtbTrlorig::DpchAppDo
#define DpchEngDlgBrlyTtbTrlorigData DlgBrlyTtbTrlorig::DpchEngData

/**
  * DlgBrlyTtbTrlorig
  */
class DlgBrlyTtbTrlorig : public JobBrly {

public:
	/**
		* VecVDit (full: VecVDlgBrlyTtbTrlorigDit)
		*/
	class VecVDit {

	public:
		static const uint DET = 1;
		static const uint RFI = 2;
		static const uint TRL = 3;
		static const uint TFI = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgBrlyTtbTrlorigDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoTrl (full: VecVDlgBrlyTtbTrlorigDoTrl)
		*/
	class VecVDoTrl {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyTtbTrlorigSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ULDDONE = 2;
		static const uint TRANSLATE = 3;
		static const uint DONE = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* VecVSrc (full: VecVDlgBrlyTtbTrlorigSrc)
		*/
	class VecVSrc {

	public:
		static const uint STAR = 1;
		static const uint OW = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyTtbTrlorig)
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
	  * ContIacDet (full: ContIacDlgBrlyTtbTrlorigDet)
	  */
	class ContIacDet : public Block {

	public:
		static const uint NUMFPUPSRC = 1;

	public:
		ContIacDet(const uint numFPupSrc = 1);

	public:
		uint numFPupSrc;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacDet* comp);
		set<uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyTtbTrlorig)
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
	  * ContInfTrl (full: ContInfDlgBrlyTtbTrlorigTrl)
	  */
	class ContInfTrl : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfTrl(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfTrl* comp);
		set<uint> diff(const ContInfTrl* comp);
	};

	/**
		* StatApp (full: StatAppDlgBrlyTtbTrlorig)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgBrlyTtbTrlorig)
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
		* StatShrRfi (full: StatShrDlgBrlyTtbTrlorigRfi)
		*/
	class StatShrRfi : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrRfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrRfi* comp);
		set<uint> diff(const StatShrRfi* comp);
	};

	/**
		* StatShrTfi (full: StatShrDlgBrlyTtbTrlorigTfi)
		*/
	class StatShrTfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrTfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrTfi* comp);
		set<uint> diff(const StatShrTfi* comp);
	};

	/**
		* StatShrTrl (full: StatShrDlgBrlyTtbTrlorigTrl)
		*/
	class StatShrTrl : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrTrl(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrTrl* comp);
		set<uint> diff(const StatShrTrl* comp);
	};

	/**
		* Tag (full: TagDlgBrlyTtbTrlorig)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgBrlyTtbTrlorigDet)
		*/
	class TagDet {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagRfi (full: TagDlgBrlyTtbTrlorigRfi)
		*/
	class TagRfi {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagTfi (full: TagDlgBrlyTtbTrlorigTfi)
		*/
	class TagTfi {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagTrl (full: TagDlgBrlyTtbTrlorigTrl)
		*/
	class TagTrl {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyTtbTrlorigData)
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
		* DpchAppDo (full: DpchAppDlgBrlyTtbTrlorigDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOTRL = 3;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoTrl;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyTtbTrlorigData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACDET = 3;
		static const uint CONTINF = 4;
		static const uint CONTINFTRL = 5;
		static const uint FEEDFDETPUPSRC = 6;
		static const uint FEEDFDSE = 7;
		static const uint FEEDFSGE = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint STATSHRRFI = 11;
		static const uint STATSHRTFI = 12;
		static const uint STATSHRTRL = 13;
		static const uint TAG = 14;
		static const uint TAGDET = 15;
		static const uint TAGRFI = 16;
		static const uint TAGTFI = 17;
		static const uint TAGTRL = 18;
		static const uint ALL = 19;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, ContInfTrl* continftrl = NULL, Feed* feedFDetPupSrc = NULL, Feed* feedFDse = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrRfi* statshrrfi = NULL, StatShrTfi* statshrtfi = NULL, StatShrTrl* statshrtrl = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfTrl continftrl;
		Feed feedFDetPupSrc;
		Feed feedFDse;
		Feed feedFSge;
		StatShr statshr;
		StatShrRfi statshrrfi;
		StatShrTfi statshrtfi;
		StatShrTrl statshrtrl;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalRfiUldActive(DbsBrly* dbsbrly);
	bool evalTrlButRunActive(DbsBrly* dbsbrly);
	bool evalTrlButStoActive(DbsBrly* dbsbrly);
	bool evalTfiDldActive(DbsBrly* dbsbrly);
	bool evalButDneActive(DbsBrly* dbsbrly);

public:
	DlgBrlyTtbTrlorig(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~DlgBrlyTtbTrlorig();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	ContInfTrl continftrl;
	StatShr statshr;
	StatShrRfi statshrrfi;
	StatShrTfi statshrtfi;
	StatShrTrl statshrtrl;

	Feed feedFDetPupSrc;
	Feed feedFDse;
	Feed feedFSge;

	uint ixVDit;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refreshDet(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshRfi(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshTrl(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshTfi(DbsBrly* dbsbrly, set<uint>& moditems);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

public:
	void changeStage(DbsBrly* dbsbrly, uint _ixVSge, DpchEngBrly** dpcheng = NULL);

	uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	uint enterSgeUlddone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeUlddone(DbsBrly* dbsbrly);
	uint enterSgeTranslate(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeTranslate(DbsBrly* dbsbrly);
	uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

	string getSquawk(DbsBrly* dbsbrly);

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiacdet(DbsBrly* dbsbrly, ContIacDet* _contiacdet, DpchEngBrly** dpcheng);

	void handleDpchAppDoButDneClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoTrlButRunClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoTrlButStoClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleUpload(DbsBrly* dbsbrly, const string& filename);
	string handleDownload(DbsBrly* dbsbrly);

};

#endif

