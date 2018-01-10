/**
  * \file PnlBrlyOprDetail.h
  * API code for job PnlBrlyOprDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYOPRDETAIL_H
#define PNLBRLYOPRDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyOprDetailDo PnlBrlyOprDetail::VecVDo

#define ContIacBrlyOprDetail PnlBrlyOprDetail::ContIac
#define ContInfBrlyOprDetail PnlBrlyOprDetail::ContInf
#define StatAppBrlyOprDetail PnlBrlyOprDetail::StatApp
#define StatShrBrlyOprDetail PnlBrlyOprDetail::StatShr
#define TagBrlyOprDetail PnlBrlyOprDetail::Tag

#define DpchAppBrlyOprDetailData PnlBrlyOprDetail::DpchAppData
#define DpchAppBrlyOprDetailDo PnlBrlyOprDetail::DpchAppDo
#define DpchEngBrlyOprDetailData PnlBrlyOprDetail::DpchEngData

/**
  * PnlBrlyOprDetail
  */
namespace PnlBrlyOprDetail {
	/**
		* VecVDo (full: VecVBrlyOprDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyOprDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFICA = 1;
		static const uint TXFTIT = 2;

	public:
		ContIac(const string& TxfIca = "", const string& TxfTit = "");

	public:
		string TxfIca;
		string TxfTit;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyOprDetail)
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
	  * StatApp (full: StatAppBrlyOprDetail)
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
	  * StatShr (full: StatShrBrlyOprDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTSRFACTIVE = 3;
		static const uint TXFICAACTIVE = 4;
		static const uint TXFTITACTIVE = 5;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfIcaActive = true, const bool TxfTitActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfIcaActive;
		bool TxfTitActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyOprDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTICA = 3;
		static const uint CPTTIT = 4;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptIca = "", const string& CptTit = "");

	public:
		string Cpt;
		string CptSrf;
		string CptIca;
		string CptTit;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyOprDetailData)
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
		* DpchAppDo (full: DpchAppBrlyOprDetailDo)
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
		* DpchEngData (full: DpchEngBrlyOprDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

