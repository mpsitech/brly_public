/**
  * \file PnlBrlySegDetail.h
  * API code for job PnlBrlySegDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYSEGDETAIL_H
#define PNLBRLYSEGDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlySegDetailDo PnlBrlySegDetail::VecVDo

#define ContIacBrlySegDetail PnlBrlySegDetail::ContIac
#define ContInfBrlySegDetail PnlBrlySegDetail::ContInf
#define StatAppBrlySegDetail PnlBrlySegDetail::StatApp
#define StatShrBrlySegDetail PnlBrlySegDetail::StatShr
#define TagBrlySegDetail PnlBrlySegDetail::Tag

#define DpchAppBrlySegDetailData PnlBrlySegDetail::DpchAppData
#define DpchAppBrlySegDetailDo PnlBrlySegDetail::DpchAppDo
#define DpchEngBrlySegDetailData PnlBrlySegDetail::DpchEngData

/**
  * PnlBrlySegDetail
  */
namespace PnlBrlySegDetail {
	/**
		* VecVDo (full: VecVBrlySegDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTREUVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlySegDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPRET = 1;
		static const uint TXFDPH = 2;
		static const uint TXFAL0 = 3;
		static const uint TXFAL1 = 4;
		static const uint TXFTH0 = 5;
		static const uint TXFTH1 = 6;
		static const uint TXFPH0 = 7;
		static const uint TXFPH1 = 8;
		static const uint TXFSTA = 9;
		static const uint TXFSTO = 10;
		static const uint CHKCDN = 11;

	public:
		ContIac(const uint numFPupRet = 1, const string& TxfDph = "", const string& TxfAl0 = "", const string& TxfAl1 = "", const string& TxfTh0 = "", const string& TxfTh1 = "", const string& TxfPh0 = "", const string& TxfPh1 = "", const string& TxfSta = "", const string& TxfSto = "", const bool ChkCdn = false);

	public:
		uint numFPupRet;
		string TxfDph;
		string TxfAl0;
		string TxfAl1;
		string TxfTh0;
		string TxfTh1;
		string TxfPh0;
		string TxfPh1;
		string TxfSta;
		string TxfSto;
		bool ChkCdn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlySegDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREU = 1;

	public:
		ContInf(const string& TxtReu = "");

	public:
		string TxtReu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlySegDetail)
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
	  * StatShr (full: StatShrBrlySegDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTREUACTIVE = 3;
		static const uint BUTREUVIEWAVAIL = 4;
		static const uint BUTREUVIEWACTIVE = 5;
		static const uint TXFDPHACTIVE = 6;
		static const uint TXFAL0ACTIVE = 7;
		static const uint TXFAL1ACTIVE = 8;
		static const uint TXFTH0ACTIVE = 9;
		static const uint TXFTH1ACTIVE = 10;
		static const uint TXFPH0ACTIVE = 11;
		static const uint TXFPH1ACTIVE = 12;
		static const uint TXFSTAACTIVE = 13;
		static const uint TXFSTOACTIVE = 14;
		static const uint CHKCDNACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxfDphActive = true, const bool TxfAl0Active = true, const bool TxfAl1Active = true, const bool TxfTh0Active = true, const bool TxfTh1Active = true, const bool TxfPh0Active = true, const bool TxfPh1Active = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool ChkCdnActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxfDphActive;
		bool TxfAl0Active;
		bool TxfAl1Active;
		bool TxfTh0Active;
		bool TxfTh1Active;
		bool TxfPh0Active;
		bool TxfPh1Active;
		bool TxfStaActive;
		bool TxfStoActive;
		bool ChkCdnActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlySegDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTREU = 2;
		static const uint CPTDPH = 3;
		static const uint CPTAL0 = 4;
		static const uint CPTAL1 = 5;
		static const uint CPTTH0 = 6;
		static const uint CPTTH1 = 7;
		static const uint CPTPH0 = 8;
		static const uint CPTPH1 = 9;
		static const uint CPTSTA = 10;
		static const uint CPTSTO = 11;
		static const uint CPTCDN = 12;

	public:
		Tag(const string& Cpt = "", const string& CptReu = "", const string& CptDph = "", const string& CptAl0 = "", const string& CptAl1 = "", const string& CptTh0 = "", const string& CptTh1 = "", const string& CptPh0 = "", const string& CptPh1 = "", const string& CptSta = "", const string& CptSto = "", const string& CptCdn = "");

	public:
		string Cpt;
		string CptReu;
		string CptDph;
		string CptAl0;
		string CptAl1;
		string CptTh0;
		string CptTh1;
		string CptPh0;
		string CptPh1;
		string CptSta;
		string CptSto;
		string CptCdn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlySegDetailData)
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
		* DpchAppDo (full: DpchAppBrlySegDetailDo)
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
		* DpchEngData (full: DpchEngBrlySegDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPRET = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupRet;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

