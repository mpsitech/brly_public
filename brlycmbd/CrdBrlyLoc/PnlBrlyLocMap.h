/**
  * \file PnlBrlyLocMap.h
  * job handler for job PnlBrlyLocMap (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLOCMAP_H
#define PNLBRLYLOCMAP_H

// IP custInclude --- INSERT

#include "QryBrlyLocMapLeg.h"
#include "QryBrlyLocMapProxLocation.h"
#include "QryBrlyLocMapVisLocation.h"

#define VecVBrlyLocMapDo PnlBrlyLocMap::VecVDo
#define VecVBrlyLocMapSge PnlBrlyLocMap::VecVSge

#define ContIacBrlyLocMap PnlBrlyLocMap::ContIac
#define ContInfBrlyLocMap PnlBrlyLocMap::ContInf
#define StatShrBrlyLocMap PnlBrlyLocMap::StatShr
#define StgIacBrlyLocMap PnlBrlyLocMap::StgIac
#define TagBrlyLocMap PnlBrlyLocMap::Tag

#define DpchAppBrlyLocMapData PnlBrlyLocMap::DpchAppData
#define DpchAppBrlyLocMapDo PnlBrlyLocMap::DpchAppDo
#define DpchEngBrlyLocMapData PnlBrlyLocMap::DpchEngData
#define DpchEngBrlyLocMapImage PnlBrlyLocMap::DpchEngImage

/**
  * PnlBrlyLocMap
  */
class PnlBrlyLocMap : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLocMapDo)
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
		* VecVSge (full: VecVBrlyLocMapSge)
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
	  * ContIac (full: ContIacBrlyLocMap)
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
	  * ContInf (full: ContInfBrlyLocMap)
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
		* StatShr (full: StatShrBrlyLocMap)
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
		* StgIac (full: StgIacBrlyLocMap)
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
		* Tag (full: TagBrlyLocMap)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLocMapData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIACQRYLEG = 3;
		static const uint STGIACQRYPROXLOCATION = 4;
		static const uint STGIACQRYVISLOCATION = 5;
		static const uint STGIAC = 6;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		QryBrlyLocMapLeg::StgIac stgiacqryleg;
		QryBrlyLocMapProxLocation::StgIac stgiacqryproxlocation;
		QryBrlyLocMapVisLocation::StgIac stgiacqryvislocation;
		StgIac stgiac;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocMapDo)
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
		* DpchEngData (full: DpchEngBrlyLocMapData)
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
		static const uint RSTPROXLOCATION = 8;
		static const uint RSTVISLOCATION = 9;
		static const uint STATSHRQRYLEG = 10;
		static const uint STATSHRQRYPROXLOCATION = 11;
		static const uint STATSHRQRYVISLOCATION = 12;
		static const uint STGIACQRYLEG = 13;
		static const uint STGIACQRYPROXLOCATION = 14;
		static const uint STGIACQRYVISLOCATION = 15;
		static const uint STGIAC = 16;
		static const uint ALL = 17;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, ListBrlyQLocMapLeg* rstleg = NULL, ListBrlyQLocMapProxLocation* rstproxlocation = NULL, ListBrlyQLocMapVisLocation* rstvislocation = NULL, QryBrlyLocMapLeg::StatShr* statshrqryleg = NULL, QryBrlyLocMapProxLocation::StatShr* statshrqryproxlocation = NULL, QryBrlyLocMapVisLocation::StatShr* statshrqryvislocation = NULL, QryBrlyLocMapLeg::StgIac* stgiacqryleg = NULL, QryBrlyLocMapProxLocation::StgIac* stgiacqryproxlocation = NULL, QryBrlyLocMapVisLocation::StgIac* stgiacqryvislocation = NULL, StgIac* stgiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;
		ListBrlyQLocMapLeg rstleg;
		ListBrlyQLocMapProxLocation rstproxlocation;
		ListBrlyQLocMapVisLocation rstvislocation;
		QryBrlyLocMapLeg::StatShr statshrqryleg;
		QryBrlyLocMapProxLocation::StatShr statshrqryproxlocation;
		QryBrlyLocMapVisLocation::StatShr statshrqryvislocation;
		QryBrlyLocMapLeg::StgIac stgiacqryleg;
		QryBrlyLocMapProxLocation::StgIac stgiacqryproxlocation;
		QryBrlyLocMapVisLocation::StgIac stgiacqryvislocation;
		StgIac stgiac;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	/**
		* DpchEngImage (full: DpchEngBrlyLocMapImage)
		*/
	class DpchEngImage : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint RSTLEG = 2;
		static const uint RSTPROXLOCATION = 3;
		static const uint RSTVISLOCATION = 4;
		static const uint STATSHRQRYLEG = 5;
		static const uint STATSHRQRYPROXLOCATION = 6;
		static const uint STATSHRQRYVISLOCATION = 7;
		static const uint ALL = 8;

	public:
		DpchEngImage(const ubigint jref = 0, ListBrlyQLocMapLeg* rstleg = NULL, ListBrlyQLocMapProxLocation* rstproxlocation = NULL, ListBrlyQLocMapVisLocation* rstvislocation = NULL, QryBrlyLocMapLeg::StatShr* statshrqryleg = NULL, QryBrlyLocMapProxLocation::StatShr* statshrqryproxlocation = NULL, QryBrlyLocMapVisLocation::StatShr* statshrqryvislocation = NULL, const set<uint>& mask = {NONE});

	public:
		ListBrlyQLocMapLeg rstleg;
		ListBrlyQLocMapProxLocation rstproxlocation;
		ListBrlyQLocMapVisLocation rstvislocation;
		QryBrlyLocMapLeg::StatShr statshrqryleg;
		QryBrlyLocMapProxLocation::StatShr statshrqryproxlocation;
		QryBrlyLocMapVisLocation::StatShr statshrqryvislocation;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	PnlBrlyLocMap(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyLocMap();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFSge;

	QryBrlyLocMapLeg* qryleg;
	QryBrlyLocMapProxLocation* qryproxlocation;
	QryBrlyLocMapVisLocation* qryvislocation;

	// IP custVar --- IBEGIN
	bool standalone;

	string srcfile;
	string tgzfile;
	// IP custVar --- IEND

public:
	// IP cust --- INSERT

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
	void handleDpchAppDataStgiacqryleg(DbsBrly* dbsbrly, QryBrlyLocMapLeg::StgIac* _stgiacqryleg, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqryproxlocation(DbsBrly* dbsbrly, QryBrlyLocMapProxLocation::StgIac* _stgiacqryproxlocation, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqryvislocation(DbsBrly* dbsbrly, QryBrlyLocMapVisLocation::StgIac* _stgiacqryvislocation, DpchEngBrly** dpcheng);
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


