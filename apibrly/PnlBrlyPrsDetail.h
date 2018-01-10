/**
  * \file PnlBrlyPrsDetail.h
  * API code for job PnlBrlyPrsDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYPRSDETAIL_H
#define PNLBRLYPRSDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyPrsDetailDo PnlBrlyPrsDetail::VecVDo

#define ContIacBrlyPrsDetail PnlBrlyPrsDetail::ContIac
#define ContInfBrlyPrsDetail PnlBrlyPrsDetail::ContInf
#define StatAppBrlyPrsDetail PnlBrlyPrsDetail::StatApp
#define StatShrBrlyPrsDetail PnlBrlyPrsDetail::StatShr
#define TagBrlyPrsDetail PnlBrlyPrsDetail::Tag

#define DpchAppBrlyPrsDetailData PnlBrlyPrsDetail::DpchAppData
#define DpchAppBrlyPrsDetailDo PnlBrlyPrsDetail::DpchAppDo
#define DpchEngBrlyPrsDetailData PnlBrlyPrsDetail::DpchEngData

/**
  * PnlBrlyPrsDetail
  */
namespace PnlBrlyPrsDetail {
	/**
		* VecVDo (full: VecVBrlyPrsDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJLNEDITCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyPrsDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint TXFFNM = 2;
		static const uint NUMFPUPJLN = 3;
		static const uint NUMSFLSTDRV = 4;
		static const uint NUMFPUPSEX = 5;
		static const uint TXFTEL = 6;
		static const uint TXFEML = 7;
		static const uint TXFSAL = 8;

	public:
		ContIac(const string& TxfTit = "", const string& TxfFnm = "", const uint numFPupJln = 1, const vector<uint>& numsFLstDrv = {}, const uint numFPupSex = 1, const string& TxfTel = "", const string& TxfEml = "", const string& TxfSal = "");

	public:
		string TxfTit;
		string TxfFnm;
		uint numFPupJln;
		vector<uint> numsFLstDrv;
		uint numFPupSex;
		string TxfTel;
		string TxfEml;
		string TxfSal;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyPrsDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTLNM = 1;
		static const uint TXTDRV = 2;

	public:
		ContInf(const string& TxtLnm = "", const string& TxtDrv = "");

	public:
		string TxtLnm;
		string TxtDrv;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyPrsDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint LSTDRVALT = 2;
		static const uint LSTDRVNUMFIRSTDISP = 3;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstDrvAlt = true, const uint LstDrvNumFirstdisp = 1);

	public:
		uint ixBrlyVExpstate;
		bool LstDrvAlt;
		uint LstDrvNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyPrsDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXFTITACTIVE = 3;
		static const uint TXFFNMACTIVE = 4;
		static const uint PUPJLNACTIVE = 5;
		static const uint BUTJLNEDITAVAIL = 6;
		static const uint TXTLNMACTIVE = 7;
		static const uint LSTDRVACTIVE = 8;
		static const uint PUPSEXACTIVE = 9;
		static const uint TXFTELACTIVE = 10;
		static const uint TXFEMLACTIVE = 11;
		static const uint TXFSALACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxfFnmActive = true, const bool PupJlnActive = true, const bool ButJlnEditAvail = true, const bool TxtLnmActive = true, const bool LstDrvActive = true, const bool PupSexActive = true, const bool TxfTelActive = true, const bool TxfEmlActive = true, const bool TxfSalActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxfFnmActive;
		bool PupJlnActive;
		bool ButJlnEditAvail;
		bool TxtLnmActive;
		bool LstDrvActive;
		bool PupSexActive;
		bool TxfTelActive;
		bool TxfEmlActive;
		bool TxfSalActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyPrsDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTIT = 2;
		static const uint CPTFNM = 3;
		static const uint CPTLNM = 4;
		static const uint CPTDRV = 5;
		static const uint CPTSEX = 6;
		static const uint CPTTEL = 7;
		static const uint CPTEML = 8;
		static const uint CPTSAL = 9;

	public:
		Tag(const string& Cpt = "", const string& CptTit = "", const string& CptFnm = "", const string& CptLnm = "", const string& CptDrv = "", const string& CptSex = "", const string& CptTel = "", const string& CptEml = "", const string& CptSal = "");

	public:
		string Cpt;
		string CptTit;
		string CptFnm;
		string CptLnm;
		string CptDrv;
		string CptSex;
		string CptTel;
		string CptEml;
		string CptSal;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyPrsDetailData)
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
		* DpchAppDo (full: DpchAppBrlyPrsDetailDo)
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
		* DpchEngData (full: DpchEngBrlyPrsDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTDRV = 4;
		static const uint FEEDFPUPJLN = 5;
		static const uint FEEDFPUPSEX = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstDrv;
		Feed feedFPupJln;
		Feed feedFPupSex;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

