/**
  * \file PnlBrlySegList.h
  * API code for job PnlBrlySegList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYSEGLIST_H
#define PNLBRLYSEGLIST_H

#include "ApiBrly_blks.h"

#include "BrlyQSegList.h"

#include "QryBrlySegList.h"

#define VecVBrlySegListDo PnlBrlySegList::VecVDo

#define ContIacBrlySegList PnlBrlySegList::ContIac
#define ContInfBrlySegList PnlBrlySegList::ContInf
#define StatShrBrlySegList PnlBrlySegList::StatShr
#define StgIacBrlySegList PnlBrlySegList::StgIac
#define TagBrlySegList PnlBrlySegList::Tag

#define DpchAppBrlySegListData PnlBrlySegList::DpchAppData
#define DpchAppBrlySegListDo PnlBrlySegList::DpchAppDo
#define DpchEngBrlySegListData PnlBrlySegList::DpchEngData

/**
  * PnlBrlySegList
  */
namespace PnlBrlySegList {
	/**
		* VecVDo (full: VecVBrlySegListDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;
		static const uint BUTNEWCLICK = 3;
		static const uint BUTDELETECLICK = 4;
		static const uint BUTFILTERCLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlySegList)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFTOS = 1;

	public:
		ContIac(const uint numFTos = 1);

	public:
		uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlySegList)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTFOR = 1;
		static const uint TXTPRE = 2;
		static const uint BUTFILTERON = 3;
		static const uint NUMFCSIQST = 4;

	public:
		ContInf(const string& TxtFor = "", const string& TxtPre = "", const bool ButFilterOn = false, const uint numFCsiQst = 1);

	public:
		string TxtFor;
		string TxtPre;
		bool ButFilterOn;
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrBrlySegList)
	  */
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		uint ixBrlyVExpstate;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacBrlySegList)
	  */
	class StgIac : public Block {

	public:
		static const uint TCORETWIDTH = 1;
		static const uint TCOREUWIDTH = 2;
		static const uint TCOAL0WIDTH = 3;
		static const uint TCOAL1WIDTH = 4;
		static const uint TCOTH0WIDTH = 5;
		static const uint TCOTH1WIDTH = 6;
		static const uint TCOPH0WIDTH = 7;
		static const uint TCOPH1WIDTH = 8;
		static const uint TCOSTAWIDTH = 9;
		static const uint TCOSTOWIDTH = 10;

	public:
		StgIac(const uint TcoRetWidth = 100, const uint TcoReuWidth = 100, const uint TcoAl0Width = 100, const uint TcoAl1Width = 100, const uint TcoTh0Width = 100, const uint TcoTh1Width = 100, const uint TcoPh0Width = 100, const uint TcoPh1Width = 100, const uint TcoStaWidth = 100, const uint TcoStoWidth = 100);

	public:
		uint TcoRetWidth;
		uint TcoReuWidth;
		uint TcoAl0Width;
		uint TcoAl1Width;
		uint TcoTh0Width;
		uint TcoTh1Width;
		uint TcoPh0Width;
		uint TcoPh1Width;
		uint TcoStaWidth;
		uint TcoStoWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlySegList)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TXTFOR = 2;
		static const uint TRS = 3;
		static const uint TXTSHOWING1 = 4;
		static const uint TXTSHOWING2 = 5;
		static const uint TCORET = 6;
		static const uint TCOREU = 7;
		static const uint TCOAL0 = 8;
		static const uint TCOAL1 = 9;
		static const uint TCOTH0 = 10;
		static const uint TCOTH1 = 11;
		static const uint TCOPH0 = 12;
		static const uint TCOPH1 = 13;
		static const uint TCOSTA = 14;
		static const uint TCOSTO = 15;

	public:
		Tag(const string& Cpt = "", const string& TxtFor = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoRet = "", const string& TcoReu = "", const string& TcoAl0 = "", const string& TcoAl1 = "", const string& TcoTh0 = "", const string& TcoTh1 = "", const string& TcoPh0 = "", const string& TcoPh1 = "", const string& TcoSta = "", const string& TcoSto = "");

	public:
		string Cpt;
		string TxtFor;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoRet;
		string TcoReu;
		string TcoAl0;
		string TcoAl1;
		string TcoTh0;
		string TcoTh1;
		string TcoPh0;
		string TcoPh1;
		string TcoSta;
		string TcoSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlySegListData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;
		static const uint ALL = 5;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryBrlySegList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryBrlySegList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlySegListDo)
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
		* DpchEngData (full: DpchEngBrlySegListData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFCSIQST = 4;
		static const uint FEEDFTOS = 5;
		static const uint STATSHR = 6;
		static const uint STGIAC = 7;
		static const uint TAG = 8;
		static const uint RST = 9;
		static const uint STATAPPQRY = 10;
		static const uint STATSHRQRY = 11;
		static const uint STGIACQRY = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFCsiQst;
		Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListBrlyQSegList rst;
		QryBrlySegList::StatApp statappqry;
		QryBrlySegList::StatShr statshrqry;
		QryBrlySegList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

