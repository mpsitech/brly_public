/**
  * \file PnlBrlySegOrgMNSegment.h
  * API code for job PnlBrlySegOrgMNSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYSEGORGMNSEGMENT_H
#define PNLBRLYSEGORGMNSEGMENT_H

#include "ApiBrly_blks.h"

#include "BrlyQSegOrgMNSegment.h"

#include "QryBrlySegOrgMNSegment.h"

#define VecVBrlySegOrgMNSegmentDo PnlBrlySegOrgMNSegment::VecVDo

#define ContInfBrlySegOrgMNSegment PnlBrlySegOrgMNSegment::ContInf
#define StatAppBrlySegOrgMNSegment PnlBrlySegOrgMNSegment::StatApp
#define StatShrBrlySegOrgMNSegment PnlBrlySegOrgMNSegment::StatShr
#define StgIacBrlySegOrgMNSegment PnlBrlySegOrgMNSegment::StgIac
#define TagBrlySegOrgMNSegment PnlBrlySegOrgMNSegment::Tag

#define DpchAppBrlySegOrgMNSegmentData PnlBrlySegOrgMNSegment::DpchAppData
#define DpchAppBrlySegOrgMNSegmentDo PnlBrlySegOrgMNSegment::DpchAppDo
#define DpchEngBrlySegOrgMNSegmentData PnlBrlySegOrgMNSegment::DpchEngData

/**
  * PnlBrlySegOrgMNSegment
  */
namespace PnlBrlySegOrgMNSegment {
	/**
		* VecVDo (full: VecVBrlySegOrgMNSegmentDo)
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
	  * ContInf (full: ContInfBrlySegOrgMNSegment)
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
	  * StatApp (full: StatAppBrlySegOrgMNSegment)
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
	  * StatShr (full: StatShrBrlySegOrgMNSegment)
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
	  * StgIac (full: StgIacBrlySegOrgMNSegment)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOMREFWIDTH = 1;
		static const uint TCOSTAWIDTH = 2;
		static const uint TCOSTOWIDTH = 3;
		static const uint TCODP0WIDTH = 4;
		static const uint TCODP1WIDTH = 5;
		static const uint TCOOP0WIDTH = 6;
		static const uint TCOOP1WIDTH = 7;

	public:
		StgIac(const uint TcoMrefWidth = 100, const uint TcoStaWidth = 100, const uint TcoStoWidth = 100, const uint TcoDp0Width = 100, const uint TcoDp1Width = 100, const uint TcoOp0Width = 100, const uint TcoOp1Width = 100);

	public:
		uint TcoMrefWidth;
		uint TcoStaWidth;
		uint TcoStoWidth;
		uint TcoDp0Width;
		uint TcoDp1Width;
		uint TcoOp0Width;
		uint TcoOp1Width;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlySegOrgMNSegment)
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
		static const uint TCODP0 = 8;
		static const uint TCODP1 = 9;
		static const uint TCOOP0 = 10;
		static const uint TCOOP1 = 11;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoMref = "", const string& TcoSta = "", const string& TcoSto = "", const string& TcoDp0 = "", const string& TcoDp1 = "", const string& TcoOp0 = "", const string& TcoOp1 = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoMref;
		string TcoSta;
		string TcoSto;
		string TcoDp0;
		string TcoDp1;
		string TcoOp0;
		string TcoOp1;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlySegOrgMNSegmentData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlySegOrgMNSegment::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlySegOrgMNSegment::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlySegOrgMNSegmentDo)
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
		* DpchEngData (full: DpchEngBrlySegOrgMNSegmentData)
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
		ListBrlyQSegOrgMNSegment rst;
		QryBrlySegOrgMNSegment::StatApp statappqry;
		QryBrlySegOrgMNSegment::StatShr statshrqry;
		QryBrlySegOrgMNSegment::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

