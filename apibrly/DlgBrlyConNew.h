/**
  * \file DlgBrlyConNew.h
  * API code for job DlgBrlyConNew (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef DLGBRLYCONNEW_H
#define DLGBRLYCONNEW_H

#include "ApiBrly_blks.h"

#define VecVDlgBrlyConNewDit DlgBrlyConNew::VecVDit
#define VecVDlgBrlyConNewDo DlgBrlyConNew::VecVDo
#define VecVDlgBrlyConNewDoCal DlgBrlyConNew::VecVDoCal
#define VecVDlgBrlyConNewDoDet DlgBrlyConNew::VecVDoDet
#define VecVDlgBrlyConNewSge DlgBrlyConNew::VecVSge

#define ContIacDlgBrlyConNew DlgBrlyConNew::ContIac
#define ContIacDlgBrlyConNewDet DlgBrlyConNew::ContIacDet
#define ContInfDlgBrlyConNew DlgBrlyConNew::ContInf
#define ContInfDlgBrlyConNewCal DlgBrlyConNew::ContInfCal
#define StatAppDlgBrlyConNew DlgBrlyConNew::StatApp
#define StatShrDlgBrlyConNew DlgBrlyConNew::StatShr
#define StatShrDlgBrlyConNewCal DlgBrlyConNew::StatShrCal
#define StatShrDlgBrlyConNewDet DlgBrlyConNew::StatShrDet
#define TagDlgBrlyConNew DlgBrlyConNew::Tag
#define TagDlgBrlyConNewCal DlgBrlyConNew::TagCal
#define TagDlgBrlyConNewDet DlgBrlyConNew::TagDet

#define DpchAppDlgBrlyConNewData DlgBrlyConNew::DpchAppData
#define DpchAppDlgBrlyConNewDo DlgBrlyConNew::DpchAppDo
#define DpchEngDlgBrlyConNewData DlgBrlyConNew::DpchEngData

/**
  * DlgBrlyConNew
  */
namespace DlgBrlyConNew {
	/**
		* VecVDit (full: VecVDlgBrlyConNewDit)
		*/
	class VecVDit {

	public:
		static const uint DET = 1;
		static const uint CAL = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDo (full: VecVDlgBrlyConNewDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoCal (full: VecVDlgBrlyConNewDoCal)
		*/
	class VecVDoCal {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgBrlyConNewDoDet)
		*/
	class VecVDoDet {

	public:
		static const uint BUTCRECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyConNewSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint CREATE = 2;
		static const uint CREDONE = 3;
		static const uint CALC1 = 4;
		static const uint CALC2 = 5;
		static const uint CALC3 = 6;
		static const uint CALC4 = 7;
		static const uint DONE = 8;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyConNew)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDSE = 1;

	public:
		ContIac(const uint numFDse = 1);

	public:
		uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacDet (full: ContIacDlgBrlyConNewDet)
	  */
	class ContIacDet : public Block {

	public:
		static const uint TXFFLT = 1;
		static const uint NUMFPUPMDL = 2;
		static const uint NUMFPUPTTB = 3;
		static const uint TXFETY = 4;

	public:
		ContIacDet(const string& TxfFlt = "", const uint numFPupMdl = 1, const uint numFPupTtb = 1, const string& TxfEty = "");

	public:
		string TxfFlt;
		uint numFPupMdl;
		uint numFPupTtb;
		string TxfEty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacDet* comp);
		set<uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyConNew)
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
	  * ContInfCal (full: ContInfDlgBrlyConNewCal)
	  */
	class ContInfCal : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfCal(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInfCal* comp);
		set<uint> diff(const ContInfCal* comp);
	};

	/**
	  * StatApp (full: StatAppDlgBrlyConNew)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONE = 1;
		static const uint SHORTMENU = 2;

	public:
		StatApp(const bool initdone = false, const string& shortMenu = "");

	public:
		bool initdone;
		string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgBrlyConNew)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrCal (full: StatShrDlgBrlyConNewCal)
	  */
	class StatShrCal : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrCal(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrCal* comp);
		set<uint> diff(const StatShrCal* comp);
	};

	/**
	  * StatShrDet (full: StatShrDlgBrlyConNewDet)
	  */
	class StatShrDet : public Block {

	public:
		static const uint BUTCREACTIVE = 1;

	public:
		StatShrDet(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrDet* comp);
		set<uint> diff(const StatShrDet* comp);
	};

	/**
	  * Tag (full: TagDlgBrlyConNew)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint BUTDNE = 2;

	public:
		Tag(const string& Cpt = "", const string& ButDne = "");

	public:
		string Cpt;
		string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagCal (full: TagDlgBrlyConNewCal)
	  */
	class TagCal : public Block {

	public:
		static const uint CPTPRG = 1;
		static const uint BUTRUN = 2;
		static const uint BUTSTO = 3;

	public:
		TagCal(const string& CptPrg = "", const string& ButRun = "", const string& ButSto = "");

	public:
		string CptPrg;
		string ButRun;
		string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagDet (full: TagDlgBrlyConNewDet)
	  */
	class TagDet : public Block {

	public:
		static const uint CPTFLT = 1;
		static const uint CPTMDL = 2;
		static const uint CPTTTB = 3;
		static const uint CPTETY = 4;
		static const uint BUTCRE = 5;

	public:
		TagDet(const string& CptFlt = "", const string& CptMdl = "", const string& CptTtb = "", const string& CptEty = "", const string& ButCre = "");

	public:
		string CptFlt;
		string CptMdl;
		string CptTtb;
		string CptEty;
		string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyConNewData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACDET = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppDlgBrlyConNewDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOCAL = 3;
		static const uint IXVDODET = 4;
		static const uint ALL = 5;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const uint ixVDoCal = 0, const uint ixVDoDet = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;
		uint ixVDoCal;
		uint ixVDoDet;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyConNewData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACDET = 3;
		static const uint CONTINF = 4;
		static const uint CONTINFCAL = 5;
		static const uint FEEDFDETPUPMDL = 6;
		static const uint FEEDFDETPUPTTB = 7;
		static const uint FEEDFDSE = 8;
		static const uint FEEDFSGE = 9;
		static const uint STATAPP = 10;
		static const uint STATSHR = 11;
		static const uint STATSHRCAL = 12;
		static const uint STATSHRDET = 13;
		static const uint TAG = 14;
		static const uint TAGCAL = 15;
		static const uint TAGDET = 16;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfCal continfcal;
		Feed feedFDetPupMdl;
		Feed feedFDetPupTtb;
		Feed feedFDse;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrCal statshrcal;
		StatShrDet statshrdet;
		Tag tag;
		TagCal tagcal;
		TagDet tagdet;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

