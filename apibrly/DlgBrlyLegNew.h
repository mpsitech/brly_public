/**
  * \file DlgBrlyLegNew.h
  * API code for job DlgBrlyLegNew (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef DLGBRLYLEGNEW_H
#define DLGBRLYLEGNEW_H

#include "ApiBrly_blks.h"

#define VecVDlgBrlyLegNewDit DlgBrlyLegNew::VecVDit
#define VecVDlgBrlyLegNewDo DlgBrlyLegNew::VecVDo
#define VecVDlgBrlyLegNewDoDet DlgBrlyLegNew::VecVDoDet
#define VecVDlgBrlyLegNewDoInc DlgBrlyLegNew::VecVDoInc
#define VecVDlgBrlyLegNewSge DlgBrlyLegNew::VecVSge

#define ContIacDlgBrlyLegNew DlgBrlyLegNew::ContIac
#define ContIacDlgBrlyLegNewDet DlgBrlyLegNew::ContIacDet
#define ContInfDlgBrlyLegNew DlgBrlyLegNew::ContInf
#define ContInfDlgBrlyLegNewInc DlgBrlyLegNew::ContInfInc
#define StatAppDlgBrlyLegNew DlgBrlyLegNew::StatApp
#define StatShrDlgBrlyLegNew DlgBrlyLegNew::StatShr
#define StatShrDlgBrlyLegNewDet DlgBrlyLegNew::StatShrDet
#define StatShrDlgBrlyLegNewInc DlgBrlyLegNew::StatShrInc
#define TagDlgBrlyLegNew DlgBrlyLegNew::Tag
#define TagDlgBrlyLegNewDet DlgBrlyLegNew::TagDet
#define TagDlgBrlyLegNewInc DlgBrlyLegNew::TagInc

#define DpchAppDlgBrlyLegNewData DlgBrlyLegNew::DpchAppData
#define DpchAppDlgBrlyLegNewDo DlgBrlyLegNew::DpchAppDo
#define DpchEngDlgBrlyLegNewData DlgBrlyLegNew::DpchEngData

/**
  * DlgBrlyLegNew
  */
namespace DlgBrlyLegNew {
	/**
		* VecVDit (full: VecVDlgBrlyLegNewDit)
		*/
	class VecVDit {

	public:
		static const uint DET = 1;
		static const uint INC = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDo (full: VecVDlgBrlyLegNewDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgBrlyLegNewDoDet)
		*/
	class VecVDoDet {

	public:
		static const uint BUTCRECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoInc (full: VecVDlgBrlyLegNewDoInc)
		*/
	class VecVDoInc {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyLegNewSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint CREATE = 2;
		static const uint CREDONE = 3;
		static const uint INCO = 4;
		static const uint DONE = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyLegNew)
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
	  * ContIacDet (full: ContIacDlgBrlyLegNewDet)
	  */
	class ContIacDet : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint TXFBGN = 2;
		static const uint TXFEND = 3;

	public:
		ContIacDet(const uint numFPupTyp = 1, const string& TxfBgn = "", const string& TxfEnd = "");

	public:
		uint numFPupTyp;
		string TxfBgn;
		string TxfEnd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacDet* comp);
		set<uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyLegNew)
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
	  * ContInfInc (full: ContInfDlgBrlyLegNewInc)
	  */
	class ContInfInc : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfInc(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInfInc* comp);
		set<uint> diff(const ContInfInc* comp);
	};

	/**
	  * StatApp (full: StatAppDlgBrlyLegNew)
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
	  * StatShr (full: StatShrDlgBrlyLegNew)
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
	  * StatShrDet (full: StatShrDlgBrlyLegNewDet)
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
	  * StatShrInc (full: StatShrDlgBrlyLegNewInc)
	  */
	class StatShrInc : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrInc(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrInc* comp);
		set<uint> diff(const StatShrInc* comp);
	};

	/**
	  * Tag (full: TagDlgBrlyLegNew)
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
	  * TagDet (full: TagDlgBrlyLegNewDet)
	  */
	class TagDet : public Block {

	public:
		static const uint CPTTYP = 1;
		static const uint CPTBGN = 2;
		static const uint CPTEND = 3;
		static const uint BUTCRE = 4;

	public:
		TagDet(const string& CptTyp = "", const string& CptBgn = "", const string& CptEnd = "", const string& ButCre = "");

	public:
		string CptTyp;
		string CptBgn;
		string CptEnd;
		string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagInc (full: TagDlgBrlyLegNewInc)
	  */
	class TagInc : public Block {

	public:
		static const uint CPTPRG = 1;
		static const uint BUTRUN = 2;
		static const uint BUTSTO = 3;

	public:
		TagInc(const string& CptPrg = "", const string& ButRun = "", const string& ButSto = "");

	public:
		string CptPrg;
		string ButRun;
		string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyLegNewData)
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
		* DpchAppDo (full: DpchAppDlgBrlyLegNewDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDODET = 3;
		static const uint IXVDOINC = 4;
		static const uint ALL = 5;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const uint ixVDoDet = 0, const uint ixVDoInc = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;
		uint ixVDoDet;
		uint ixVDoInc;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyLegNewData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACDET = 3;
		static const uint CONTINF = 4;
		static const uint CONTINFINC = 5;
		static const uint FEEDFDETPUPTYP = 6;
		static const uint FEEDFDSE = 7;
		static const uint FEEDFSGE = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint STATSHRDET = 11;
		static const uint STATSHRINC = 12;
		static const uint TAG = 13;
		static const uint TAGDET = 14;
		static const uint TAGINC = 15;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfInc continfinc;
		Feed feedFDetPupTyp;
		Feed feedFDse;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrDet statshrdet;
		StatShrInc statshrinc;
		Tag tag;
		TagDet tagdet;
		TagInc taginc;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

