/**
  * \file PnlBrlyLocList.h
  * API code for job PnlBrlyLocList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLOCLIST_H
#define PNLBRLYLOCLIST_H

#include "ApiBrly_blks.h"

#include "BrlyQLocList.h"

#include "QryBrlyLocList.h"

#define VecVBrlyLocListDo PnlBrlyLocList::VecVDo

#define ContIacBrlyLocList PnlBrlyLocList::ContIac
#define ContInfBrlyLocList PnlBrlyLocList::ContInf
#define StatShrBrlyLocList PnlBrlyLocList::StatShr
#define StgIacBrlyLocList PnlBrlyLocList::StgIac
#define TagBrlyLocList PnlBrlyLocList::Tag

#define DpchAppBrlyLocListData PnlBrlyLocList::DpchAppData
#define DpchAppBrlyLocListDo PnlBrlyLocList::DpchAppDo
#define DpchEngBrlyLocListData PnlBrlyLocList::DpchEngData

/**
  * PnlBrlyLocList
  */
namespace PnlBrlyLocList {
	/**
		* VecVDo (full: VecVBrlyLocListDo)
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
	  * ContIac (full: ContIacBrlyLocList)
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
	  * ContInf (full: ContInfBrlyLocList)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTFILTERON = 1;
		static const uint NUMFCSIQST = 2;

	public:
		ContInf(const bool ButFilterOn = false, const uint numFCsiQst = 1);

	public:
		bool ButFilterOn;
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyLocList)
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
	  * StgIac (full: StgIacBrlyLocList)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOSRFWIDTH = 1;
		static const uint TCOICAWIDTH = 2;
		static const uint TCOTITWIDTH = 3;
		static const uint TCOTYPWIDTH = 4;
		static const uint TCOREGWIDTH = 5;
		static const uint TCOEQPWIDTH = 6;
		static const uint TCOALTWIDTH = 7;
		static const uint TCOTHEWIDTH = 8;
		static const uint TCOPHIWIDTH = 9;

	public:
		StgIac(const uint TcoSrfWidth = 100, const uint TcoIcaWidth = 100, const uint TcoTitWidth = 100, const uint TcoTypWidth = 100, const uint TcoRegWidth = 100, const uint TcoEqpWidth = 100, const uint TcoAltWidth = 100, const uint TcoTheWidth = 100, const uint TcoPhiWidth = 100);

	public:
		uint TcoSrfWidth;
		uint TcoIcaWidth;
		uint TcoTitWidth;
		uint TcoTypWidth;
		uint TcoRegWidth;
		uint TcoEqpWidth;
		uint TcoAltWidth;
		uint TcoTheWidth;
		uint TcoPhiWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyLocList)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOSRF = 5;
		static const uint TCOICA = 6;
		static const uint TCOTIT = 7;
		static const uint TCOTYP = 8;
		static const uint TCOREG = 9;
		static const uint TCOEQP = 10;
		static const uint TCOALT = 11;
		static const uint TCOTHE = 12;
		static const uint TCOPHI = 13;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoSrf = "", const string& TcoIca = "", const string& TcoTit = "", const string& TcoTyp = "", const string& TcoReg = "", const string& TcoEqp = "", const string& TcoAlt = "", const string& TcoThe = "", const string& TcoPhi = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoSrf;
		string TcoIca;
		string TcoTit;
		string TcoTyp;
		string TcoReg;
		string TcoEqp;
		string TcoAlt;
		string TcoThe;
		string TcoPhi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLocListData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;
		static const uint ALL = 5;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryBrlyLocList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryBrlyLocList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocListDo)
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
		* DpchEngData (full: DpchEngBrlyLocListData)
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
		ListBrlyQLocList rst;
		QryBrlyLocList::StatApp statappqry;
		QryBrlyLocList::StatShr statshrqry;
		QryBrlyLocList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

