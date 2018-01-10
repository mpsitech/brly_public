/**
  * \file PnlBrlyFilList.h
  * API code for job PnlBrlyFilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFILLIST_H
#define PNLBRLYFILLIST_H

#include "ApiBrly_blks.h"

#include "BrlyQFilList.h"

#include "QryBrlyFilList.h"

#define VecVBrlyFilListDo PnlBrlyFilList::VecVDo

#define ContIacBrlyFilList PnlBrlyFilList::ContIac
#define ContInfBrlyFilList PnlBrlyFilList::ContInf
#define StatShrBrlyFilList PnlBrlyFilList::StatShr
#define StgIacBrlyFilList PnlBrlyFilList::StgIac
#define TagBrlyFilList PnlBrlyFilList::Tag

#define DpchAppBrlyFilListData PnlBrlyFilList::DpchAppData
#define DpchAppBrlyFilListDo PnlBrlyFilList::DpchAppDo
#define DpchEngBrlyFilListData PnlBrlyFilList::DpchEngData

/**
  * PnlBrlyFilList
  */
namespace PnlBrlyFilList {
	/**
		* VecVDo (full: VecVBrlyFilListDo)
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
	  * ContIac (full: ContIacBrlyFilList)
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
	  * ContInf (full: ContInfBrlyFilList)
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
	  * StatShr (full: StatShrBrlyFilList)
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
	  * StgIac (full: StgIacBrlyFilList)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOFNMWIDTH = 1;
		static const uint TCORETWIDTH = 2;
		static const uint TCOREUWIDTH = 3;
		static const uint TCOCNTWIDTH = 4;
		static const uint TCOMIMWIDTH = 5;
		static const uint TCOSIZWIDTH = 6;

	public:
		StgIac(const uint TcoFnmWidth = 100, const uint TcoRetWidth = 100, const uint TcoReuWidth = 100, const uint TcoCntWidth = 100, const uint TcoMimWidth = 100, const uint TcoSizWidth = 100);

	public:
		uint TcoFnmWidth;
		uint TcoRetWidth;
		uint TcoReuWidth;
		uint TcoCntWidth;
		uint TcoMimWidth;
		uint TcoSizWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyFilList)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOFNM = 5;
		static const uint TCORET = 6;
		static const uint TCOREU = 7;
		static const uint TCOCNT = 8;
		static const uint TCOMIM = 9;
		static const uint TCOSIZ = 10;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoFnm = "", const string& TcoRet = "", const string& TcoReu = "", const string& TcoCnt = "", const string& TcoMim = "", const string& TcoSiz = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoFnm;
		string TcoRet;
		string TcoReu;
		string TcoCnt;
		string TcoMim;
		string TcoSiz;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFilListData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;
		static const uint ALL = 5;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryBrlyFilList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryBrlyFilList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFilListDo)
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
		* DpchEngData (full: DpchEngBrlyFilListData)
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
		ListBrlyQFilList rst;
		QryBrlyFilList::StatApp statappqry;
		QryBrlyFilList::StatShr statshrqry;
		QryBrlyFilList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

