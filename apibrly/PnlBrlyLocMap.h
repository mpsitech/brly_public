/**
  * \file PnlBrlyLocMap.h
  * API code for job PnlBrlyLocMap (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLOCMAP_H
#define PNLBRLYLOCMAP_H

#include "ApiBrly_blks.h"

#include "BrlyQLocMapLeg.h"
#include "BrlyQLocMapProxLocation.h"
#include "BrlyQLocMapVisLocation.h"

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
namespace PnlBrlyLocMap {
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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
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
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint BUTDETACH = 2;
		static const uint BUTATTACH = 3;
		static const uint BUTHOME = 4;
		static const uint CPTSCL = 5;
		static const uint BUTREFRESH = 6;
		static const uint DLD = 7;

	public:
		Tag(const string& Cpt = "", const string& ButDetach = "", const string& ButAttach = "", const string& ButHome = "", const string& CptScl = "", const string& ButRefresh = "", const string& Dld = "");

	public:
		string Cpt;
		string ButDetach;
		string ButAttach;
		string ButHome;
		string CptScl;
		string ButRefresh;
		string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLocMapData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIACQRYLEG = 3;
		static const uint STGIACQRYPROXLOCATION = 4;
		static const uint STGIACQRYVISLOCATION = 5;
		static const uint STGIAC = 6;
		static const uint ALL = 7;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, QryBrlyLocMapLeg::StgIac* stgiacqryleg = NULL, QryBrlyLocMapProxLocation::StgIac* stgiacqryproxlocation = NULL, QryBrlyLocMapVisLocation::StgIac* stgiacqryvislocation = NULL, StgIac* stgiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		QryBrlyLocMapLeg::StgIac stgiacqryleg;
		QryBrlyLocMapProxLocation::StgIac stgiacqryproxlocation;
		QryBrlyLocMapVisLocation::StgIac stgiacqryvislocation;
		StgIac stgiac;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocMapDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint ALL = 3;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngBrlyLocMapData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
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

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;
		Tag tag;
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

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngImage (full: DpchEngBrlyLocMapImage)
		*/
	class DpchEngImage : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint RSTLEG = 2;
		static const uint RSTPROXLOCATION = 3;
		static const uint RSTVISLOCATION = 4;
		static const uint STATSHRQRYLEG = 5;
		static const uint STATSHRQRYPROXLOCATION = 6;
		static const uint STATSHRQRYVISLOCATION = 7;

	public:
		DpchEngImage();

	public:
		ListBrlyQLocMapLeg rstleg;
		ListBrlyQLocMapProxLocation rstproxlocation;
		ListBrlyQLocMapVisLocation rstvislocation;
		QryBrlyLocMapLeg::StatShr statshrqryleg;
		QryBrlyLocMapProxLocation::StatShr statshrqryproxlocation;
		QryBrlyLocMapVisLocation::StatShr statshrqryvislocation;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

