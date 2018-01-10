/**
  * \file PnlBrlyLegDetail.h
  * API code for job PnlBrlyLegDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLEGDETAIL_H
#define PNLBRLYLEGDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyLegDetailDo PnlBrlyLegDetail::VecVDo

#define ContIacBrlyLegDetail PnlBrlyLegDetail::ContIac
#define ContInfBrlyLegDetail PnlBrlyLegDetail::ContInf
#define StatAppBrlyLegDetail PnlBrlyLegDetail::StatApp
#define StatShrBrlyLegDetail PnlBrlyLegDetail::StatShr
#define TagBrlyLegDetail PnlBrlyLegDetail::Tag

#define DpchAppBrlyLegDetailData PnlBrlyLegDetail::DpchAppData
#define DpchAppBrlyLegDetailDo PnlBrlyLegDetail::DpchAppDo
#define DpchEngBrlyLegDetailData PnlBrlyLegDetail::DpchEngData

/**
  * PnlBrlyLegDetail
  */
namespace PnlBrlyLegDetail {
	/**
		* VecVDo (full: VecVBrlyLegDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTCLUVIEWCLICK = 2;
		static const uint BUTCLUCLUSTERCLICK = 3;
		static const uint BUTCLUUNCLUSTERCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyLegDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint NUMFLSTCLU = 2;
		static const uint TXFALT = 3;
		static const uint TXFDPH = 4;
		static const uint TXFAPH = 5;
		static const uint TXFXAL = 6;
		static const uint TXFXP0 = 7;
		static const uint TXFXP1 = 8;
		static const uint TXFXAP = 9;
		static const uint CHKCDN = 10;

	public:
		ContIac(const uint numFPupTyp = 1, const uint numFLstClu = 1, const string& TxfAlt = "", const string& TxfDph = "", const string& TxfAph = "", const string& TxfXal = "", const string& TxfXp0 = "", const string& TxfXp1 = "", const string& TxfXap = "", const bool ChkCdn = false);

	public:
		uint numFPupTyp;
		uint numFLstClu;
		string TxfAlt;
		string TxfDph;
		string TxfAph;
		string TxfXal;
		string TxfXp0;
		string TxfXp1;
		string TxfXap;
		bool ChkCdn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyLegDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTBLO = 1;
		static const uint TXTELO = 2;
		static const uint TXTCLU = 3;

	public:
		ContInf(const string& TxtBlo = "", const string& TxtElo = "", const string& TxtClu = "");

	public:
		string TxtBlo;
		string TxtElo;
		string TxtClu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyLegDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint LSTCLUALT = 2;
		static const uint LSTCLUNUMFIRSTDISP = 3;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstCluAlt = true, const uint LstCluNumFirstdisp = 1);

	public:
		uint ixBrlyVExpstate;
		bool LstCluAlt;
		uint LstCluNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyLegDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTBLOACTIVE = 3;
		static const uint TXTELOACTIVE = 4;
		static const uint PUPTYPACTIVE = 5;
		static const uint LSTCLUACTIVE = 6;
		static const uint BUTCLUVIEWACTIVE = 7;
		static const uint BUTCLUCLUSTERAVAIL = 8;
		static const uint BUTCLUUNCLUSTERAVAIL = 9;
		static const uint TXFALTACTIVE = 10;
		static const uint TXFDPHACTIVE = 11;
		static const uint TXFAPHACTIVE = 12;
		static const uint TXFXALACTIVE = 13;
		static const uint TXFXP0ACTIVE = 14;
		static const uint TXFXP1ACTIVE = 15;
		static const uint TXFXAPACTIVE = 16;
		static const uint CHKCDNACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtBloActive = true, const bool TxtEloActive = true, const bool PupTypActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxfAltActive = true, const bool TxfDphActive = true, const bool TxfAphActive = true, const bool TxfXalActive = true, const bool TxfXp0Active = true, const bool TxfXp1Active = true, const bool TxfXapActive = true, const bool ChkCdnActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtBloActive;
		bool TxtEloActive;
		bool PupTypActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxfAltActive;
		bool TxfDphActive;
		bool TxfAphActive;
		bool TxfXalActive;
		bool TxfXp0Active;
		bool TxfXp1Active;
		bool TxfXapActive;
		bool ChkCdnActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyLegDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTBLO = 2;
		static const uint CPTELO = 3;
		static const uint CPTTYP = 4;
		static const uint CPTCLU = 5;
		static const uint CPTALT = 6;
		static const uint CPTDPH = 7;
		static const uint CPTAPH = 8;
		static const uint CPTXAL = 9;
		static const uint CPTXP0 = 10;
		static const uint CPTXP1 = 11;
		static const uint CPTXAP = 12;
		static const uint CPTCDN = 13;

	public:
		Tag(const string& Cpt = "", const string& CptBlo = "", const string& CptElo = "", const string& CptTyp = "", const string& CptClu = "", const string& CptAlt = "", const string& CptDph = "", const string& CptAph = "", const string& CptXal = "", const string& CptXp0 = "", const string& CptXp1 = "", const string& CptXap = "", const string& CptCdn = "");

	public:
		string Cpt;
		string CptBlo;
		string CptElo;
		string CptTyp;
		string CptClu;
		string CptAlt;
		string CptDph;
		string CptAph;
		string CptXal;
		string CptXp0;
		string CptXp1;
		string CptXap;
		string CptCdn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLegDetailData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint ALL = 3;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLegDetailDo)
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
		* DpchEngData (full: DpchEngBrlyLegDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTCLU = 4;
		static const uint FEEDFPUPTYP = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstClu;
		Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

