/**
  * \file PnlBrlyConDetail.h
  * API code for job PnlBrlyConDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYCONDETAIL_H
#define PNLBRLYCONDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyConDetailDo PnlBrlyConDetail::VecVDo

#define ContIacBrlyConDetail PnlBrlyConDetail::ContIac
#define ContInfBrlyConDetail PnlBrlyConDetail::ContInf
#define StatAppBrlyConDetail PnlBrlyConDetail::StatApp
#define StatShrBrlyConDetail PnlBrlyConDetail::StatShr
#define TagBrlyConDetail PnlBrlyConDetail::Tag

#define DpchAppBrlyConDetailData PnlBrlyConDetail::DpchAppData
#define DpchAppBrlyConDetailDo PnlBrlyConDetail::DpchAppDo
#define DpchEngBrlyConDetailData PnlBrlyConDetail::DpchEngData

/**
  * PnlBrlyConDetail
  */
namespace PnlBrlyConDetail {
	/**
		* VecVDo (full: VecVBrlyConDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTFLTVIEWCLICK = 2;
		static const uint BUTTTBVIEWCLICK = 3;
		static const uint BUTETYEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyConDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFSTA = 1;
		static const uint TXFSTO = 2;
		static const uint NUMFPUPMOD = 3;
		static const uint NUMSFLSTETY = 4;
		static const uint TXFETY = 5;

	public:
		ContIac(const string& TxfSta = "", const string& TxfSto = "", const uint numFPupMod = 1, const vector<uint>& numsFLstEty = {}, const string& TxfEty = "");

	public:
		string TxfSta;
		string TxfSto;
		uint numFPupMod;
		vector<uint> numsFLstEty;
		string TxfEty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyConDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTFLT = 1;
		static const uint TXTCOR = 2;
		static const uint TXTTTB = 3;

	public:
		ContInf(const string& TxtFlt = "", const string& TxtCor = "", const string& TxtTtb = "");

	public:
		string TxtFlt;
		string TxtCor;
		string TxtTtb;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyConDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint LSTETYALT = 2;
		static const uint LSTETYNUMFIRSTDISP = 3;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstEtyAlt = true, const uint LstEtyNumFirstdisp = 1);

	public:
		uint ixBrlyVExpstate;
		bool LstEtyAlt;
		uint LstEtyNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyConDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFETYVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint TXTFLTACTIVE = 4;
		static const uint BUTFLTVIEWAVAIL = 5;
		static const uint BUTFLTVIEWACTIVE = 6;
		static const uint TXTCORACTIVE = 7;
		static const uint TXFSTAACTIVE = 8;
		static const uint TXFSTOACTIVE = 9;
		static const uint PUPMODACTIVE = 10;
		static const uint TXTTTBACTIVE = 11;
		static const uint BUTTTBVIEWAVAIL = 12;
		static const uint BUTTTBVIEWACTIVE = 13;
		static const uint LSTETYACTIVE = 14;
		static const uint BUTETYEDITAVAIL = 15;

	public:
		StatShr(const bool TxfEtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtFltActive = true, const bool ButFltViewAvail = true, const bool ButFltViewActive = true, const bool TxtCorActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool PupModActive = true, const bool TxtTtbActive = true, const bool ButTtbViewAvail = true, const bool ButTtbViewActive = true, const bool LstEtyActive = true, const bool ButEtyEditAvail = true);

	public:
		bool TxfEtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtFltActive;
		bool ButFltViewAvail;
		bool ButFltViewActive;
		bool TxtCorActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool PupModActive;
		bool TxtTtbActive;
		bool ButTtbViewAvail;
		bool ButTtbViewActive;
		bool LstEtyActive;
		bool ButEtyEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyConDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTFLT = 2;
		static const uint CPTCOR = 3;
		static const uint CPTSTA = 4;
		static const uint CPTSTO = 5;
		static const uint CPTMOD = 6;
		static const uint CPTTTB = 7;
		static const uint CPTETY = 8;

	public:
		Tag(const string& Cpt = "", const string& CptFlt = "", const string& CptCor = "", const string& CptSta = "", const string& CptSto = "", const string& CptMod = "", const string& CptTtb = "", const string& CptEty = "");

	public:
		string Cpt;
		string CptFlt;
		string CptCor;
		string CptSta;
		string CptSto;
		string CptMod;
		string CptTtb;
		string CptEty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyConDetailData)
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
		* DpchAppDo (full: DpchAppBrlyConDetailDo)
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
		* DpchEngData (full: DpchEngBrlyConDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTETY = 4;
		static const uint FEEDFPUPMOD = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstEty;
		Feed feedFPupMod;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

