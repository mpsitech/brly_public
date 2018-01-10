/**
  * \file PnlBrlyConMap.h
  * job handler for job PnlBrlyConMap (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYCONMAP_H
#define PNLBRLYCONMAP_H

// IP custInclude --- INSERT

#include "QryBrlyConMapFlight.h"
#include "QryBrlyConMapLeg.h"
#include "QryBrlyConMapLocation.h"
#include "QryBrlyConMapNode.h"
#include "QryBrlyConMapRelay.h"

#define VecVBrlyConMapDo PnlBrlyConMap::VecVDo
#define VecVBrlyConMapSge PnlBrlyConMap::VecVSge

#define ContIacBrlyConMap PnlBrlyConMap::ContIac
#define ContInfBrlyConMap PnlBrlyConMap::ContInf
#define StatShrBrlyConMap PnlBrlyConMap::StatShr
#define StgIacBrlyConMap PnlBrlyConMap::StgIac
#define TagBrlyConMap PnlBrlyConMap::Tag

#define DpchAppBrlyConMapData PnlBrlyConMap::DpchAppData
#define DpchAppBrlyConMapDo PnlBrlyConMap::DpchAppDo
#define DpchEngBrlyConMapData PnlBrlyConMap::DpchEngData
#define DpchEngBrlyConMapImage PnlBrlyConMap::DpchEngImage

/**
  * PnlBrlyConMap
  */
class PnlBrlyConMap : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyConMapDo)
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
		* VecVSge (full: VecVBrlyConMapSge)
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
	  * ContIac (full: ContIacBrlyConMap)
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
	  * ContInf (full: ContInfBrlyConMap)
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
		* StatShr (full: StatShrBrlyConMap)
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
		* StgIac (full: StgIacBrlyConMap)
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
		* Tag (full: TagBrlyConMap)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyConMapData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIACQRYFLIGHT = 3;
		static const uint STGIACQRYLEG = 4;
		static const uint STGIACQRYLOCATION = 5;
		static const uint STGIACQRYNODE = 6;
		static const uint STGIACQRYRELAY = 7;
		static const uint STGIAC = 8;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		QryBrlyConMapFlight::StgIac stgiacqryflight;
		QryBrlyConMapLeg::StgIac stgiacqryleg;
		QryBrlyConMapLocation::StgIac stgiacqrylocation;
		QryBrlyConMapNode::StgIac stgiacqrynode;
		QryBrlyConMapRelay::StgIac stgiacqryrelay;
		StgIac stgiac;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyConMapDo)
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
		* DpchEngData (full: DpchEngBrlyConMapData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFSGE = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;
		static const uint RSTFLIGHT = 7;
		static const uint RSTLEG = 8;
		static const uint RSTLOCATION = 9;
		static const uint RSTNODE = 10;
		static const uint RSTRELAY = 11;
		static const uint STATSHRQRYFLIGHT = 12;
		static const uint STATSHRQRYLEG = 13;
		static const uint STATSHRQRYLOCATION = 14;
		static const uint STATSHRQRYNODE = 15;
		static const uint STATSHRQRYRELAY = 16;
		static const uint STGIACQRYFLIGHT = 17;
		static const uint STGIACQRYLEG = 18;
		static const uint STGIACQRYLOCATION = 19;
		static const uint STGIACQRYNODE = 20;
		static const uint STGIACQRYRELAY = 21;
		static const uint STGIAC = 22;
		static const uint ALL = 23;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, ListBrlyQConMapFlight* rstflight = NULL, ListBrlyQConMapLeg* rstleg = NULL, ListBrlyQConMapLocation* rstlocation = NULL, ListBrlyQConMapNode* rstnode = NULL, ListBrlyQConMapRelay* rstrelay = NULL, QryBrlyConMapFlight::StatShr* statshrqryflight = NULL, QryBrlyConMapLeg::StatShr* statshrqryleg = NULL, QryBrlyConMapLocation::StatShr* statshrqrylocation = NULL, QryBrlyConMapNode::StatShr* statshrqrynode = NULL, QryBrlyConMapRelay::StatShr* statshrqryrelay = NULL, QryBrlyConMapFlight::StgIac* stgiacqryflight = NULL, QryBrlyConMapLeg::StgIac* stgiacqryleg = NULL, QryBrlyConMapLocation::StgIac* stgiacqrylocation = NULL, QryBrlyConMapNode::StgIac* stgiacqrynode = NULL, QryBrlyConMapRelay::StgIac* stgiacqryrelay = NULL, StgIac* stgiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;
		ListBrlyQConMapFlight rstflight;
		ListBrlyQConMapLeg rstleg;
		ListBrlyQConMapLocation rstlocation;
		ListBrlyQConMapNode rstnode;
		ListBrlyQConMapRelay rstrelay;
		QryBrlyConMapFlight::StatShr statshrqryflight;
		QryBrlyConMapLeg::StatShr statshrqryleg;
		QryBrlyConMapLocation::StatShr statshrqrylocation;
		QryBrlyConMapNode::StatShr statshrqrynode;
		QryBrlyConMapRelay::StatShr statshrqryrelay;
		QryBrlyConMapFlight::StgIac stgiacqryflight;
		QryBrlyConMapLeg::StgIac stgiacqryleg;
		QryBrlyConMapLocation::StgIac stgiacqrylocation;
		QryBrlyConMapNode::StgIac stgiacqrynode;
		QryBrlyConMapRelay::StgIac stgiacqryrelay;
		StgIac stgiac;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	/**
		* DpchEngImage (full: DpchEngBrlyConMapImage)
		*/
	class DpchEngImage : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint RSTLEG = 2;
		static const uint RSTLOCATION = 3;
		static const uint RSTFLIGHT = 4;
		static const uint RSTRELAY = 5;
		static const uint RSTNODE = 6;
		static const uint STATSHRQRYLEG = 7;
		static const uint STATSHRQRYLOCATION = 8;
		static const uint STATSHRQRYFLIGHT = 9;
		static const uint STATSHRQRYRELAY = 10;
		static const uint STATSHRQRYNODE = 11;
		static const uint ALL = 12;

	public:
		DpchEngImage(const ubigint jref = 0, ListBrlyQConMapLeg* rstleg = NULL, ListBrlyQConMapLocation* rstlocation = NULL, ListBrlyQConMapFlight* rstflight = NULL, ListBrlyQConMapRelay* rstrelay = NULL, ListBrlyQConMapNode* rstnode = NULL, QryBrlyConMapLeg::StatShr* statshrqryleg = NULL, QryBrlyConMapLocation::StatShr* statshrqrylocation = NULL, QryBrlyConMapFlight::StatShr* statshrqryflight = NULL, QryBrlyConMapRelay::StatShr* statshrqryrelay = NULL, QryBrlyConMapNode::StatShr* statshrqrynode = NULL, const set<uint>& mask = {NONE});

	public:
		ListBrlyQConMapLeg rstleg;
		ListBrlyQConMapLocation rstlocation;
		ListBrlyQConMapFlight rstflight;
		ListBrlyQConMapRelay rstrelay;
		ListBrlyQConMapNode rstnode;
		QryBrlyConMapLeg::StatShr statshrqryleg;
		QryBrlyConMapLocation::StatShr statshrqrylocation;
		QryBrlyConMapFlight::StatShr statshrqryflight;
		QryBrlyConMapRelay::StatShr statshrqryrelay;
		QryBrlyConMapNode::StatShr statshrqrynode;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	PnlBrlyConMap(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyConMap();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFSge;

	QryBrlyConMapFlight* qryflight;
	QryBrlyConMapLeg* qryleg;
	QryBrlyConMapLocation* qrylocation;
	QryBrlyConMapNode* qrynode;
	QryBrlyConMapRelay* qryrelay;

	// IP custVar --- IBEGIN
	uint wkm;
	uint hkm;

	bool standalone;
	bool wrtree;

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
	void handleDpchAppDataStgiacqryflight(DbsBrly* dbsbrly, QryBrlyConMapFlight::StgIac* _stgiacqryflight, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqryleg(DbsBrly* dbsbrly, QryBrlyConMapLeg::StgIac* _stgiacqryleg, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqrylocation(DbsBrly* dbsbrly, QryBrlyConMapLocation::StgIac* _stgiacqrylocation, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqrynode(DbsBrly* dbsbrly, QryBrlyConMapNode::StgIac* _stgiacqrynode, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqryrelay(DbsBrly* dbsbrly, QryBrlyConMapRelay::StgIac* _stgiacqryrelay, DpchEngBrly** dpcheng);
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


