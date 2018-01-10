/**
  * \file PnlBrlyLegMap.h
  * API code for job PnlBrlyLegMap (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLEGMAP_H
#define PNLBRLYLEGMAP_H

#include "ApiBrly_blks.h"

#include "BrlyQLegMapLeg.h"
#include "BrlyQLegMapLocation.h"

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
namespace PnlBrlyLegMap {
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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
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
		* DpchAppData (full: DpchAppBrlyLegMapData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIACQRYLEG = 3;
		static const uint STGIACQRYLOCATION = 4;
		static const uint STGIAC = 5;
		static const uint ALL = 6;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, QryBrlyLegMapLeg::StgIac* stgiacqryleg = NULL, QryBrlyLegMapLocation::StgIac* stgiacqrylocation = NULL, StgIac* stgiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		QryBrlyLegMapLeg::StgIac stgiacqryleg;
		QryBrlyLegMapLocation::StgIac stgiacqrylocation;
		StgIac stgiac;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLegMapDo)
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
		* DpchEngData (full: DpchEngBrlyLegMapData)
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
		static const uint RSTLOCATION = 8;
		static const uint STATSHRQRYLEG = 9;
		static const uint STATSHRQRYLOCATION = 10;
		static const uint STGIACQRYLEG = 11;
		static const uint STGIACQRYLOCATION = 12;
		static const uint STGIAC = 13;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;
		Tag tag;
		ListBrlyQLegMapLeg rstleg;
		ListBrlyQLegMapLocation rstlocation;
		QryBrlyLegMapLeg::StatShr statshrqryleg;
		QryBrlyLegMapLocation::StatShr statshrqrylocation;
		QryBrlyLegMapLeg::StgIac stgiacqryleg;
		QryBrlyLegMapLocation::StgIac stgiacqrylocation;
		StgIac stgiac;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngImage (full: DpchEngBrlyLegMapImage)
		*/
	class DpchEngImage : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint RSTLEG = 2;
		static const uint RSTLOCATION = 3;
		static const uint STATSHRQRYLEG = 4;
		static const uint STATSHRQRYLOCATION = 5;

	public:
		DpchEngImage();

	public:
		ListBrlyQLegMapLeg rstleg;
		ListBrlyQLegMapLocation rstlocation;
		QryBrlyLegMapLeg::StatShr statshrqryleg;
		QryBrlyLegMapLocation::StatShr statshrqrylocation;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

