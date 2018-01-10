/**
  * \file PnlBrlyRegDetail.h
  * API code for job PnlBrlyRegDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYREGDETAIL_H
#define PNLBRLYREGDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyRegDetailDo PnlBrlyRegDetail::VecVDo

#define ContIacBrlyRegDetail PnlBrlyRegDetail::ContIac
#define ContInfBrlyRegDetail PnlBrlyRegDetail::ContInf
#define StatAppBrlyRegDetail PnlBrlyRegDetail::StatApp
#define StatShrBrlyRegDetail PnlBrlyRegDetail::StatShr
#define TagBrlyRegDetail PnlBrlyRegDetail::Tag

#define DpchAppBrlyRegDetailData PnlBrlyRegDetail::DpchAppData
#define DpchAppBrlyRegDetailDo PnlBrlyRegDetail::DpchAppDo
#define DpchEngBrlyRegDetailData PnlBrlyRegDetail::DpchEngData

/**
  * PnlBrlyRegDetail
  */
namespace PnlBrlyRegDetail {
	/**
		* VecVDo (full: VecVBrlyRegDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJTIEDITCLICK = 2;
		static const uint BUTSUPVIEWCLICK = 3;
		static const uint BUTJEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyRegDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPJTI = 1;
		static const uint NUMFPUPJ = 2;
		static const uint NUMFPUPDST = 3;

	public:
		ContIac(const uint numFPupJti = 1, const uint numFPupJ = 1, const uint numFPupDst = 1);

	public:
		uint numFPupJti;
		uint numFPupJ;
		uint numFPupDst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyRegDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTTIT = 2;
		static const uint TXTSUP = 3;
		static const uint TXTTOF = 4;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtTit = "", const string& TxtSup = "", const string& TxtTof = "");

	public:
		string TxtSrf;
		string TxtTit;
		string TxtSup;
		string TxtTof;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyRegDetail)
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
	  * StatShr (full: StatShrBrlyRegDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTSRFACTIVE = 3;
		static const uint PUPJTIACTIVE = 4;
		static const uint BUTJTIEDITAVAIL = 5;
		static const uint TXTTITACTIVE = 6;
		static const uint TXTSUPACTIVE = 7;
		static const uint BUTSUPVIEWAVAIL = 8;
		static const uint BUTSUPVIEWACTIVE = 9;
		static const uint PUPJACTIVE = 10;
		static const uint BUTJEDITAVAIL = 11;
		static const uint PUPDSTACTIVE = 12;
		static const uint TXTTOFACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool PupDstActive = true, const bool TxtTofActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool PupDstActive;
		bool TxtTofActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyRegDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTIT = 3;
		static const uint CPTSUP = 4;
		static const uint CPTDST = 5;
		static const uint CPTTOF = 6;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTit = "", const string& CptSup = "", const string& CptDst = "", const string& CptTof = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTit;
		string CptSup;
		string CptDst;
		string CptTof;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyRegDetailData)
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
		* DpchAppDo (full: DpchAppBrlyRegDetailDo)
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
		* DpchEngData (full: DpchEngBrlyRegDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPDST = 4;
		static const uint FEEDFPUPJ = 5;
		static const uint FEEDFPUPJTI = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupDst;
		Feed feedFPupJ;
		Feed feedFPupJti;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

