/**
  * \file PnlBrlyConMap.h
  * API code for job PnlBrlyConMap (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYCONMAP_H
#define PNLBRLYCONMAP_H

#include "ApiBrly_blks.h"

#include "BrlyQConMapFlight.h"
#include "BrlyQConMapLeg.h"
#include "BrlyQConMapLocation.h"
#include "BrlyQConMapNode.h"
#include "BrlyQConMapRelay.h"

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
namespace PnlBrlyConMap {
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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
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
		* DpchAppData (full: DpchAppBrlyConMapData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIACQRYFLIGHT = 3;
		static const uint STGIACQRYLEG = 4;
		static const uint STGIACQRYLOCATION = 5;
		static const uint STGIACQRYNODE = 6;
		static const uint STGIACQRYRELAY = 7;
		static const uint STGIAC = 8;
		static const uint ALL = 9;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, QryBrlyConMapFlight::StgIac* stgiacqryflight = NULL, QryBrlyConMapLeg::StgIac* stgiacqryleg = NULL, QryBrlyConMapLocation::StgIac* stgiacqrylocation = NULL, QryBrlyConMapNode::StgIac* stgiacqrynode = NULL, QryBrlyConMapRelay::StgIac* stgiacqryrelay = NULL, StgIac* stgiac = NULL, const set<uint>& mask = {NONE});

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

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyConMapDo)
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
		* DpchEngData (full: DpchEngBrlyConMapData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
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

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;
		Tag tag;
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

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngImage (full: DpchEngBrlyConMapImage)
		*/
	class DpchEngImage : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
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

	public:
		DpchEngImage();

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

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

