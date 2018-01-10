/**
  * \file PnlBrlyFltFafAWaypoint.h
  * API code for job PnlBrlyFltFafAWaypoint (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFLTFAFAWAYPOINT_H
#define PNLBRLYFLTFAFAWAYPOINT_H

#include "ApiBrly_blks.h"

#include "BrlyQFltFafAWaypoint.h"

#include "QryBrlyFltFafAWaypoint.h"

#define VecVBrlyFltFafAWaypointDo PnlBrlyFltFafAWaypoint::VecVDo

#define ContInfBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::ContInf
#define StatAppBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::StatApp
#define StatShrBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::StatShr
#define StgIacBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::StgIac
#define TagBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::Tag

#define DpchAppBrlyFltFafAWaypointData PnlBrlyFltFafAWaypoint::DpchAppData
#define DpchAppBrlyFltFafAWaypointDo PnlBrlyFltFafAWaypoint::DpchAppDo
#define DpchEngBrlyFltFafAWaypointData PnlBrlyFltFafAWaypoint::DpchEngData

/**
  * PnlBrlyFltFafAWaypoint
  */
namespace PnlBrlyFltFafAWaypoint {
	/**
		* VecVDo (full: VecVBrlyFltFafAWaypointDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUPCLICK = 1;
		static const uint BUTDOWNCLICK = 2;
		static const uint BUTNEWCLICK = 3;
		static const uint BUTDUPLICATECLICK = 4;
		static const uint BUTDELETECLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyFltFafAWaypoint)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyFltFafAWaypoint)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);

	public:
		uint ixBrlyVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyFltFafAWaypoint)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTUPAVAIL = 1;
		static const uint BUTUPACTIVE = 2;
		static const uint BUTDOWNAVAIL = 3;
		static const uint BUTDOWNACTIVE = 4;
		static const uint BUTNEWAVAIL = 5;
		static const uint BUTDUPLICATEAVAIL = 6;
		static const uint BUTDUPLICATEACTIVE = 7;
		static const uint BUTDELETEAVAIL = 8;
		static const uint BUTDELETEACTIVE = 9;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacBrlyFltFafAWaypoint)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOTMSWIDTH = 1;
		static const uint TCOLATWIDTH = 2;
		static const uint TCOLONWIDTH = 3;
		static const uint TCOGSPWIDTH = 4;
		static const uint TCOALTWIDTH = 5;
		static const uint TCOASTWIDTH = 6;
		static const uint TCOUTYWIDTH = 7;
		static const uint TCOACHWIDTH = 8;

	public:
		StgIac(const uint TcoTmsWidth = 100, const uint TcoLatWidth = 100, const uint TcoLonWidth = 100, const uint TcoGspWidth = 100, const uint TcoAltWidth = 100, const uint TcoAstWidth = 100, const uint TcoUtyWidth = 100, const uint TcoAchWidth = 100);

	public:
		uint TcoTmsWidth;
		uint TcoLatWidth;
		uint TcoLonWidth;
		uint TcoGspWidth;
		uint TcoAltWidth;
		uint TcoAstWidth;
		uint TcoUtyWidth;
		uint TcoAchWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyFltFafAWaypoint)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOTMS = 5;
		static const uint TCOLAT = 6;
		static const uint TCOLON = 7;
		static const uint TCOGSP = 8;
		static const uint TCOALT = 9;
		static const uint TCOAST = 10;
		static const uint TCOUTY = 11;
		static const uint TCOACH = 12;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoTms = "", const string& TcoLat = "", const string& TcoLon = "", const string& TcoGsp = "", const string& TcoAlt = "", const string& TcoAst = "", const string& TcoUty = "", const string& TcoAch = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoTms;
		string TcoLat;
		string TcoLon;
		string TcoGsp;
		string TcoAlt;
		string TcoAst;
		string TcoUty;
		string TcoAch;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFltFafAWaypointData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlyFltFafAWaypoint::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlyFltFafAWaypoint::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFltFafAWaypointDo)
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
		* DpchEngData (full: DpchEngBrlyFltFafAWaypointData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListBrlyQFltFafAWaypoint rst;
		QryBrlyFltFafAWaypoint::StatApp statappqry;
		QryBrlyFltFafAWaypoint::StatShr statshrqry;
		QryBrlyFltFafAWaypoint::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

