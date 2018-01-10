/**
  * \file PnlBrlyRlyDetail.h
  * API code for job PnlBrlyRlyDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYRLYDETAIL_H
#define PNLBRLYRLYDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyRlyDetailDo PnlBrlyRlyDetail::VecVDo

#define ContIacBrlyRlyDetail PnlBrlyRlyDetail::ContIac
#define ContInfBrlyRlyDetail PnlBrlyRlyDetail::ContInf
#define StatAppBrlyRlyDetail PnlBrlyRlyDetail::StatApp
#define StatShrBrlyRlyDetail PnlBrlyRlyDetail::StatShr
#define TagBrlyRlyDetail PnlBrlyRlyDetail::Tag

#define DpchAppBrlyRlyDetailData PnlBrlyRlyDetail::DpchAppData
#define DpchAppBrlyRlyDetailDo PnlBrlyRlyDetail::DpchAppDo
#define DpchEngBrlyRlyDetailData PnlBrlyRlyDetail::DpchEngData

/**
  * PnlBrlyRlyDetail
  */
namespace PnlBrlyRlyDetail {
	/**
		* VecVDo (full: VecVBrlyRlyDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTCONVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyRlyDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFSTA = 1;
		static const uint TXFSTO = 2;
		static const uint NUMFPUPDIR = 3;
		static const uint CHKCTD = 4;
		static const uint TXFNHP = 5;

	public:
		ContIac(const string& TxfSta = "", const string& TxfSto = "", const uint numFPupDir = 1, const bool ChkCtd = false, const string& TxfNhp = "");

	public:
		string TxfSta;
		string TxfSto;
		uint numFPupDir;
		bool ChkCtd;
		string TxfNhp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyRlyDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTCON = 1;

	public:
		ContInf(const string& TxtCon = "");

	public:
		string TxtCon;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyRlyDetail)
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
	  * StatShr (full: StatShrBrlyRlyDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXFSTAACTIVE = 3;
		static const uint TXFSTOACTIVE = 4;
		static const uint TXTCONACTIVE = 5;
		static const uint BUTCONVIEWAVAIL = 6;
		static const uint BUTCONVIEWACTIVE = 7;
		static const uint PUPDIRACTIVE = 8;
		static const uint CHKCTDACTIVE = 9;
		static const uint TXFNHPACTIVE = 10;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxtConActive = true, const bool ButConViewAvail = true, const bool ButConViewActive = true, const bool PupDirActive = true, const bool ChkCtdActive = true, const bool TxfNhpActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxtConActive;
		bool ButConViewAvail;
		bool ButConViewActive;
		bool PupDirActive;
		bool ChkCtdActive;
		bool TxfNhpActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyRlyDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSTA = 2;
		static const uint CPTSTO = 3;
		static const uint CPTCON = 4;
		static const uint CPTDIR = 5;
		static const uint CPTCTD = 6;
		static const uint CPTNHP = 7;

	public:
		Tag(const string& Cpt = "", const string& CptSta = "", const string& CptSto = "", const string& CptCon = "", const string& CptDir = "", const string& CptCtd = "", const string& CptNhp = "");

	public:
		string Cpt;
		string CptSta;
		string CptSto;
		string CptCon;
		string CptDir;
		string CptCtd;
		string CptNhp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyRlyDetailData)
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
		* DpchAppDo (full: DpchAppBrlyRlyDetailDo)
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
		* DpchEngData (full: DpchEngBrlyRlyDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPDIR = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupDir;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

