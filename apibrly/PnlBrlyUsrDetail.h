/**
  * \file PnlBrlyUsrDetail.h
  * API code for job PnlBrlyUsrDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYUSRDETAIL_H
#define PNLBRLYUSRDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyUsrDetailDo PnlBrlyUsrDetail::VecVDo

#define ContIacBrlyUsrDetail PnlBrlyUsrDetail::ContIac
#define ContInfBrlyUsrDetail PnlBrlyUsrDetail::ContInf
#define StatAppBrlyUsrDetail PnlBrlyUsrDetail::StatApp
#define StatShrBrlyUsrDetail PnlBrlyUsrDetail::StatShr
#define TagBrlyUsrDetail PnlBrlyUsrDetail::Tag

#define DpchAppBrlyUsrDetailData PnlBrlyUsrDetail::DpchAppData
#define DpchAppBrlyUsrDetailDo PnlBrlyUsrDetail::DpchAppDo
#define DpchEngBrlyUsrDetailData PnlBrlyUsrDetail::DpchEngData

/**
  * PnlBrlyUsrDetail
  */
namespace PnlBrlyUsrDetail {
	/**
		* VecVDo (full: VecVBrlyUsrDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTPRSVIEWCLICK = 2;
		static const uint BUTUSGVIEWCLICK = 3;
		static const uint BUTJSTEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyUsrDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPJST = 1;
		static const uint NUMFPUPSTE = 2;
		static const uint NUMFPUPLCL = 3;
		static const uint NUMFPUPULV = 4;
		static const uint TXFPWD = 5;

	public:
		ContIac(const uint numFPupJst = 1, const uint numFPupSte = 1, const uint numFPupLcl = 1, const uint numFPupUlv = 1, const string& TxfPwd = "");

	public:
		uint numFPupJst;
		uint numFPupSte;
		uint numFPupLcl;
		uint numFPupUlv;
		string TxfPwd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyUsrDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTPRS = 1;
		static const uint TXTSRF = 2;
		static const uint TXTUSG = 3;

	public:
		ContInf(const string& TxtPrs = "", const string& TxtSrf = "", const string& TxtUsg = "");

	public:
		string TxtPrs;
		string TxtSrf;
		string TxtUsg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyUsrDetail)
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
	  * StatShr (full: StatShrBrlyUsrDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTPRSACTIVE = 3;
		static const uint BUTPRSVIEWAVAIL = 4;
		static const uint BUTPRSVIEWACTIVE = 5;
		static const uint TXTSRFACTIVE = 6;
		static const uint TXTUSGACTIVE = 7;
		static const uint BUTUSGVIEWAVAIL = 8;
		static const uint BUTUSGVIEWACTIVE = 9;
		static const uint PUPJSTACTIVE = 10;
		static const uint BUTJSTEDITAVAIL = 11;
		static const uint PUPSTEACTIVE = 12;
		static const uint PUPLCLACTIVE = 13;
		static const uint PUPULVACTIVE = 14;
		static const uint TXFPWDACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrsActive = true, const bool ButPrsViewAvail = true, const bool ButPrsViewActive = true, const bool TxtSrfActive = true, const bool TxtUsgActive = true, const bool ButUsgViewAvail = true, const bool ButUsgViewActive = true, const bool PupJstActive = true, const bool ButJstEditAvail = true, const bool PupSteActive = true, const bool PupLclActive = true, const bool PupUlvActive = true, const bool TxfPwdActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrsActive;
		bool ButPrsViewAvail;
		bool ButPrsViewActive;
		bool TxtSrfActive;
		bool TxtUsgActive;
		bool ButUsgViewAvail;
		bool ButUsgViewActive;
		bool PupJstActive;
		bool ButJstEditAvail;
		bool PupSteActive;
		bool PupLclActive;
		bool PupUlvActive;
		bool TxfPwdActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyUsrDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTPRS = 2;
		static const uint CPTSRF = 3;
		static const uint CPTUSG = 4;
		static const uint CPTSTE = 5;
		static const uint CPTLCL = 6;
		static const uint CPTULV = 7;
		static const uint CPTPWD = 8;

	public:
		Tag(const string& Cpt = "", const string& CptPrs = "", const string& CptSrf = "", const string& CptUsg = "", const string& CptSte = "", const string& CptLcl = "", const string& CptUlv = "", const string& CptPwd = "");

	public:
		string Cpt;
		string CptPrs;
		string CptSrf;
		string CptUsg;
		string CptSte;
		string CptLcl;
		string CptUlv;
		string CptPwd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyUsrDetailData)
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
		* DpchAppDo (full: DpchAppBrlyUsrDetailDo)
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
		* DpchEngData (full: DpchEngBrlyUsrDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPJST = 4;
		static const uint FEEDFPUPLCL = 5;
		static const uint FEEDFPUPSTE = 6;
		static const uint FEEDFPUPULV = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupJst;
		Feed feedFPupLcl;
		Feed feedFPupSte;
		Feed feedFPupUlv;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

