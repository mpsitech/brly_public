/**
  * \file PnlBrlyTtbDetail.h
  * API code for job PnlBrlyTtbDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYTTBDETAIL_H
#define PNLBRLYTTBDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyTtbDetailDo PnlBrlyTtbDetail::VecVDo

#define ContIacBrlyTtbDetail PnlBrlyTtbDetail::ContIac
#define ContInfBrlyTtbDetail PnlBrlyTtbDetail::ContInf
#define StatAppBrlyTtbDetail PnlBrlyTtbDetail::StatApp
#define StatShrBrlyTtbDetail PnlBrlyTtbDetail::StatShr
#define TagBrlyTtbDetail PnlBrlyTtbDetail::Tag

#define DpchAppBrlyTtbDetailData PnlBrlyTtbDetail::DpchAppData
#define DpchAppBrlyTtbDetailDo PnlBrlyTtbDetail::DpchAppDo
#define DpchEngBrlyTtbDetailData PnlBrlyTtbDetail::DpchEngData

/**
  * PnlBrlyTtbDetail
  */
namespace PnlBrlyTtbDetail {
	/**
		* VecVDo (full: VecVBrlyTtbDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTFILVIEWCLICK = 2;
		static const uint BUTALIEDITCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyTtbDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPALI = 2;
		static const uint TXFALI = 3;
		static const uint TXFSTA = 4;
		static const uint TXFSTO = 5;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupAli = 1, const string& TxfAli = "", const string& TxfSta = "", const string& TxfSto = "");

	public:
		string TxfTit;
		uint numFPupAli;
		string TxfAli;
		string TxfSta;
		string TxfSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyTtbDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTFIL = 1;

	public:
		ContInf(const string& TxtFil = "");

	public:
		string TxtFil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyTtbDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint PUPALIALT = 2;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool PupAliAlt = false);

	public:
		uint ixBrlyVExpstate;
		bool PupAliAlt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyTtbDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFALIVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint TXFTITACTIVE = 4;
		static const uint TXTFILACTIVE = 5;
		static const uint BUTFILVIEWAVAIL = 6;
		static const uint BUTFILVIEWACTIVE = 7;
		static const uint PUPALIACTIVE = 8;
		static const uint BUTALIEDITAVAIL = 9;
		static const uint TXFSTAACTIVE = 10;
		static const uint TXFSTOACTIVE = 11;

	public:
		StatShr(const bool TxfAliValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxtFilActive = true, const bool ButFilViewAvail = true, const bool ButFilViewActive = true, const bool PupAliActive = true, const bool ButAliEditAvail = true, const bool TxfStaActive = true, const bool TxfStoActive = true);

	public:
		bool TxfAliValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxtFilActive;
		bool ButFilViewAvail;
		bool ButFilViewActive;
		bool PupAliActive;
		bool ButAliEditAvail;
		bool TxfStaActive;
		bool TxfStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyTtbDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTIT = 2;
		static const uint CPTFIL = 3;
		static const uint CPTALI = 4;
		static const uint CPTSTA = 5;
		static const uint CPTSTO = 6;

	public:
		Tag(const string& Cpt = "", const string& CptTit = "", const string& CptFil = "", const string& CptAli = "", const string& CptSta = "", const string& CptSto = "");

	public:
		string Cpt;
		string CptTit;
		string CptFil;
		string CptAli;
		string CptSta;
		string CptSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyTtbDetailData)
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
		* DpchAppDo (full: DpchAppBrlyTtbDetailDo)
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
		* DpchEngData (full: DpchEngBrlyTtbDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPALI = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupAli;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

