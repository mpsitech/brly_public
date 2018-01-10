/**
  * \file PnlBrlyLocMNSegment.h
  * API code for job PnlBrlyLocMNSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLOCMNSEGMENT_H
#define PNLBRLYLOCMNSEGMENT_H

#include "ApiBrly_blks.h"

#include "BrlyQLocMNSegment.h"

#include "QryBrlyLocMNSegment.h"

#define VecVBrlyLocMNSegmentDo PnlBrlyLocMNSegment::VecVDo

#define ContInfBrlyLocMNSegment PnlBrlyLocMNSegment::ContInf
#define StatAppBrlyLocMNSegment PnlBrlyLocMNSegment::StatApp
#define StatShrBrlyLocMNSegment PnlBrlyLocMNSegment::StatShr
#define StgIacBrlyLocMNSegment PnlBrlyLocMNSegment::StgIac
#define TagBrlyLocMNSegment PnlBrlyLocMNSegment::Tag

#define DpchAppBrlyLocMNSegmentData PnlBrlyLocMNSegment::DpchAppData
#define DpchAppBrlyLocMNSegmentDo PnlBrlyLocMNSegment::DpchAppDo
#define DpchEngBrlyLocMNSegmentData PnlBrlyLocMNSegment::DpchEngData

/**
  * PnlBrlyLocMNSegment
  */
namespace PnlBrlyLocMNSegment {
	/**
		* VecVDo (full: VecVBrlyLocMNSegmentDo)
		*/
	class VecVDo {

	public:
		static const uint BUTADDCLICK = 1;
		static const uint BUTSUBCLICK = 2;
		static const uint BUTREFRESHCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLocMNSegment)
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
	  * StatApp (full: StatAppBrlyLocMNSegment)
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
	  * StatShr (full: StatShrBrlyLocMNSegment)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTADDAVAIL = 1;
		static const uint BUTSUBAVAIL = 2;
		static const uint BUTSUBACTIVE = 3;

	public:
		StatShr(const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacBrlyLocMNSegment)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOMREFWIDTH = 1;
		static const uint TCOSTAWIDTH = 2;
		static const uint TCOSTOWIDTH = 3;
		static const uint TCOSP0WIDTH = 4;
		static const uint TCOSP1WIDTH = 5;
		static const uint TCOSPHWIDTH = 6;
		static const uint TCOSTHWIDTH = 7;

	public:
		StgIac(const uint TcoMrefWidth = 100, const uint TcoStaWidth = 100, const uint TcoStoWidth = 100, const uint TcoSp0Width = 100, const uint TcoSp1Width = 100, const uint TcoSphWidth = 100, const uint TcoSthWidth = 100);

	public:
		uint TcoMrefWidth;
		uint TcoStaWidth;
		uint TcoStoWidth;
		uint TcoSp0Width;
		uint TcoSp1Width;
		uint TcoSphWidth;
		uint TcoSthWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyLocMNSegment)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOMREF = 5;
		static const uint TCOSTA = 6;
		static const uint TCOSTO = 7;
		static const uint TCOSP0 = 8;
		static const uint TCOSP1 = 9;
		static const uint TCOSPH = 10;
		static const uint TCOSTH = 11;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoMref = "", const string& TcoSta = "", const string& TcoSto = "", const string& TcoSp0 = "", const string& TcoSp1 = "", const string& TcoSph = "", const string& TcoSth = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoMref;
		string TcoSta;
		string TcoSto;
		string TcoSp0;
		string TcoSp1;
		string TcoSph;
		string TcoSth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLocMNSegmentData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlyLocMNSegment::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlyLocMNSegment::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocMNSegmentDo)
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
		* DpchEngData (full: DpchEngBrlyLocMNSegmentData)
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
		ListBrlyQLocMNSegment rst;
		QryBrlyLocMNSegment::StatApp statappqry;
		QryBrlyLocMNSegment::StatShr statshrqry;
		QryBrlyLocMNSegment::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

