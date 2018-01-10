/**
  * \file PnlBrlyPtyDetail.h
  * API code for job PnlBrlyPtyDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYPTYDETAIL_H
#define PNLBRLYPTYDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyPtyDetailDo PnlBrlyPtyDetail::VecVDo

#define ContIacBrlyPtyDetail PnlBrlyPtyDetail::ContIac
#define ContInfBrlyPtyDetail PnlBrlyPtyDetail::ContInf
#define StatAppBrlyPtyDetail PnlBrlyPtyDetail::StatApp
#define StatShrBrlyPtyDetail PnlBrlyPtyDetail::StatShr
#define TagBrlyPtyDetail PnlBrlyPtyDetail::Tag

#define DpchAppBrlyPtyDetailData PnlBrlyPtyDetail::DpchAppData
#define DpchAppBrlyPtyDetailDo PnlBrlyPtyDetail::DpchAppDo
#define DpchEngBrlyPtyDetailData PnlBrlyPtyDetail::DpchEngData

/**
  * PnlBrlyPtyDetail
  */
namespace PnlBrlyPtyDetail {
	/**
		* VecVDo (full: VecVBrlyPtyDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTETYEDITCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyPtyDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPETY = 2;
		static const uint TXFETY = 3;
		static const uint TXFCAP = 4;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupEty = 1, const string& TxfEty = "", const string& TxfCap = "");

	public:
		string TxfTit;
		uint numFPupEty;
		string TxfEty;
		string TxfCap;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyPtyDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;

	public:
		ContInf(const string& TxtSrf = "");

	public:
		string TxtSrf;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyPtyDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint PUPETYALT = 2;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool PupEtyAlt = false);

	public:
		uint ixBrlyVExpstate;
		bool PupEtyAlt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyPtyDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFETYVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint TXTSRFACTIVE = 4;
		static const uint TXFTITACTIVE = 5;
		static const uint PUPETYACTIVE = 6;
		static const uint BUTETYEDITAVAIL = 7;
		static const uint TXFCAPACTIVE = 8;

	public:
		StatShr(const bool TxfEtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool PupEtyActive = true, const bool ButEtyEditAvail = true, const bool TxfCapActive = true);

	public:
		bool TxfEtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool PupEtyActive;
		bool ButEtyEditAvail;
		bool TxfCapActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyPtyDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTIT = 3;
		static const uint CPTETY = 4;
		static const uint CPTCAP = 5;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTit = "", const string& CptEty = "", const string& CptCap = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTit;
		string CptEty;
		string CptCap;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyPtyDetailData)
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
		* DpchAppDo (full: DpchAppBrlyPtyDetailDo)
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
		* DpchEngData (full: DpchEngBrlyPtyDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPETY = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupEty;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

