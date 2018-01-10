/**
  * \file PnlBrlyLegMNLocation.h
  * API code for job PnlBrlyLegMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLEGMNLOCATION_H
#define PNLBRLYLEGMNLOCATION_H

#include "ApiBrly_blks.h"

#include "BrlyQLegMNLocation.h"

#include "QryBrlyLegMNLocation.h"

#define VecVBrlyLegMNLocationDo PnlBrlyLegMNLocation::VecVDo

#define ContInfBrlyLegMNLocation PnlBrlyLegMNLocation::ContInf
#define StatAppBrlyLegMNLocation PnlBrlyLegMNLocation::StatApp
#define StatShrBrlyLegMNLocation PnlBrlyLegMNLocation::StatShr
#define StgIacBrlyLegMNLocation PnlBrlyLegMNLocation::StgIac
#define TagBrlyLegMNLocation PnlBrlyLegMNLocation::Tag

#define DpchAppBrlyLegMNLocationData PnlBrlyLegMNLocation::DpchAppData
#define DpchAppBrlyLegMNLocationDo PnlBrlyLegMNLocation::DpchAppDo
#define DpchEngBrlyLegMNLocationData PnlBrlyLegMNLocation::DpchEngData

/**
  * PnlBrlyLegMNLocation
  */
namespace PnlBrlyLegMNLocation {
	/**
		* VecVDo (full: VecVBrlyLegMNLocationDo)
		*/
	class VecVDo {

	public:
		static const uint BUTVIEWCLICK = 1;
		static const uint BUTADDCLICK = 2;
		static const uint BUTSUBCLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLegMNLocation)
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
	  * StatApp (full: StatAppBrlyLegMNLocation)
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
	  * StatShr (full: StatShrBrlyLegMNLocation)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTVIEWAVAIL = 1;
		static const uint BUTVIEWACTIVE = 2;
		static const uint BUTADDAVAIL = 3;
		static const uint BUTSUBAVAIL = 4;
		static const uint BUTSUBACTIVE = 5;

	public:
		StatShr(const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButViewAvail;
		bool ButViewActive;
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacBrlyLegMNLocation)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOMREFWIDTH = 1;
		static const uint TCOLP0WIDTH = 2;
		static const uint TCOLP1WIDTH = 3;
		static const uint TCOLPHWIDTH = 4;
		static const uint TCOLTHWIDTH = 5;
		static const uint TCOXP0WIDTH = 6;
		static const uint TCOXP1WIDTH = 7;

	public:
		StgIac(const uint TcoMrefWidth = 100, const uint TcoLp0Width = 100, const uint TcoLp1Width = 100, const uint TcoLphWidth = 100, const uint TcoLthWidth = 100, const uint TcoXp0Width = 100, const uint TcoXp1Width = 100);

	public:
		uint TcoMrefWidth;
		uint TcoLp0Width;
		uint TcoLp1Width;
		uint TcoLphWidth;
		uint TcoLthWidth;
		uint TcoXp0Width;
		uint TcoXp1Width;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyLegMNLocation)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOMREF = 5;
		static const uint TCOLP0 = 6;
		static const uint TCOLP1 = 7;
		static const uint TCOLPH = 8;
		static const uint TCOLTH = 9;
		static const uint TCOXP0 = 10;
		static const uint TCOXP1 = 11;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoMref = "", const string& TcoLp0 = "", const string& TcoLp1 = "", const string& TcoLph = "", const string& TcoLth = "", const string& TcoXp0 = "", const string& TcoXp1 = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoMref;
		string TcoLp0;
		string TcoLp1;
		string TcoLph;
		string TcoLth;
		string TcoXp0;
		string TcoXp1;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLegMNLocationData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlyLegMNLocation::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlyLegMNLocation::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLegMNLocationDo)
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
		* DpchEngData (full: DpchEngBrlyLegMNLocationData)
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
		ListBrlyQLegMNLocation rst;
		QryBrlyLegMNLocation::StatApp statappqry;
		QryBrlyLegMNLocation::StatShr statshrqry;
		QryBrlyLegMNLocation::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

