/**
  * \file PnlBrlyLegMap.h
  * job handler for job PnlBrlyLegMap (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLEGMAP_H
#define PNLBRLYLEGMAP_H

// IP custInclude --- INSERT

#include "QryBrlyLegMapLeg.h"
#include "QryBrlyLegMapLocation.h"

#define VecVBrlyLegMapDo PnlBrlyLegMap::VecVDo
#define VecVBrlyLegMapSge PnlBrlyLegMap::VecVSge

#define ContIacBrlyLegMap PnlBrlyLegMap::ContIac
#define ContInfBrlyLegMap PnlBrlyLegMap::ContInf
#define StatShrBrlyLegMap PnlBrlyLegMap::StatShr
#define StgIacBrlyLegMap PnlBrlyLegMap::StgIac
#define TagBrlyLegMap PnlBrlyLegMap::Tag

#define DpchAppBrlyLegMapData PnlBrlyLegMap::DpchAppData
#define DpchAppBrlyLegMapDo PnlBrlyLegMap::DpchAppDo
#define DpchEngBrlyLegMapData PnlBrlyLegMap::DpchEngData
#define DpchEngBrlyLegMapImage PnlBrlyLegMap::DpchEngImage

/**
  * PnlBrlyLegMap
  */
class PnlBrlyLegMap : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLegMapDo)
		*/
	class VecVDo {

	public:
		static const uint BUTREGULARIZECLICK = 1;
		static const uint BUTMINIMIZECLICK = 2;
		static const uint BUTHOMECLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyLegMapSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint MAPGEN = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacBrlyLegMap)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDH = 1;
		static const uint SLDV = 2;
		static const uint SLDSCL = 3;

	public:
		ContIac(const double SldH = 0.0, const double SldV = 0.0, const double SldScl = 1);

	public:
		double SldH;
		double SldV;
		double SldScl;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyLegMap)
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
		* StatShr (full: StatShrBrlyLegMap)
		*/
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint SLDHMIN = 2;
		static const uint SLDHMAX = 3;
		static const uint SLDVMIN = 4;
		static const uint SLDVMAX = 5;
		static const uint SLDSCLMIN = 6;
		static const uint SLDSCLMAX = 7;
		static const uint SLDSCLRAST = 8;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const double SldHMin = -1.0, const double SldHMax = 1.0, const double SldVMin = -1.0, const double SldVMax = 1.0, const double SldSclMin = 1, const double SldSclMax = 10, const double SldSclRast = 0.1);

	public:
		uint ixBrlyVExpstate;
		double SldHMin;
		double SldHMax;
		double SldVMin;
		double SldVMax;
		double SldSclMin;
		double SldSclMax;
		double SldSclRast;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacBrlyLegMap)
		*/
	class StgIac : public Block {

	public:
		static const uint WIDTH = 1;
		static const uint HEIGHT = 2;

	public:
		StgIac(const uint width = 400, const uint height = 300);

	public:
		uint width;
		uint height;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagBrlyLegMap)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLegMapData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIACQRYLEG = 3;
		static const uint STGIACQRYLOCATION = 4;
		static const uint STGIAC = 5;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		QryBrlyLegMapLeg::StgIac stgiacqryleg;
		QryBrlyLegMapLocation::StgIac stgiacqrylocation;
		StgIac stgiac;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLegMapDo)
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
		* DpchEngData (full: DpchEngBrlyLegMapData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFSGE = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;
		static const uint RSTLEG = 7;
		static const uint RSTLOCATION = 8;
		static const uint STATSHRQRYLEG = 9;
		static const uint STATSHRQRYLOCATION = 10;
		static const uint STGIACQRYLEG = 11;
		static const uint STGIACQRYLOCATION = 12;
		static const uint STGIAC = 13;
		static const uint ALL = 14;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, ListBrlyQLegMapLeg* rstleg = NULL, ListBrlyQLegMapLocation* rstlocation = NULL, QryBrlyLegMapLeg::StatShr* statshrqryleg = NULL, QryBrlyLegMapLocation::StatShr* statshrqrylocation = NULL, QryBrlyLegMapLeg::StgIac* stgiacqryleg = NULL, QryBrlyLegMapLocation::StgIac* stgiacqrylocation = NULL, StgIac* stgiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;
		ListBrlyQLegMapLeg rstleg;
		ListBrlyQLegMapLocation rstlocation;
		QryBrlyLegMapLeg::StatShr statshrqryleg;
		QryBrlyLegMapLocation::StatShr statshrqrylocation;
		QryBrlyLegMapLeg::StgIac stgiacqryleg;
		QryBrlyLegMapLocation::StgIac stgiacqrylocation;
		StgIac stgiac;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	/**
		* DpchEngImage (full: DpchEngBrlyLegMapImage)
		*/
	class DpchEngImage : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint RSTLEG = 2;
		static const uint RSTLOCATION = 3;
		static const uint STATSHRQRYLEG = 4;
		static const uint STATSHRQRYLOCATION = 5;
		static const uint ALL = 6;

	public:
		DpchEngImage(const ubigint jref = 0, ListBrlyQLegMapLeg* rstleg = NULL, ListBrlyQLegMapLocation* rstlocation = NULL, QryBrlyLegMapLeg::StatShr* statshrqryleg = NULL, QryBrlyLegMapLocation::StatShr* statshrqrylocation = NULL, const set<uint>& mask = {NONE});

	public:
		ListBrlyQLegMapLeg rstleg;
		ListBrlyQLegMapLocation rstlocation;
		QryBrlyLegMapLeg::StatShr statshrqryleg;
		QryBrlyLegMapLocation::StatShr statshrqrylocation;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	PnlBrlyLegMap(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyLegMap();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFSge;

	QryBrlyLegMapLeg* qryleg;
	QryBrlyLegMapLocation* qrylocation;

	// IP custVar --- IBEGIN
	uint wkm;
	uint hkm;

	bool standalone;

	string srcfile;
	string tgzfile;
	// IP custVar --- IEND

public:
	// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	void calcDist(DbsBrly* dbsbrly);
	// IP cust --- IEND

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:
	void changeStage(DbsBrly* dbsbrly, uint _ixVSge, DpchEngBrly** dpcheng = NULL);

	uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	uint enterSgeMapgen(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeMapgen(DbsBrly* dbsbrly);

	string getSquawk(DbsBrly* dbsbrly);

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleMapgen(DbsBrly* dbsbrly);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqryleg(DbsBrly* dbsbrly, QryBrlyLegMapLeg::StgIac* _stgiacqryleg, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqrylocation(DbsBrly* dbsbrly, QryBrlyLegMapLocation::StgIac* _stgiacqrylocation, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiac(DbsBrly* dbsbrly, StgIac* _stgiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButHomeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	string handleDownload(DbsBrly* dbsbrly);
	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
};

#endif


