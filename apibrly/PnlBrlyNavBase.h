/**
  * \file PnlBrlyNavBase.h
  * API code for job PnlBrlyNavBase (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYNAVBASE_H
#define PNLBRLYNAVBASE_H

#include "ApiBrly_blks.h"

#define VecVBrlyNavBaseDo PnlBrlyNavBase::VecVDo

#define ContIacBrlyNavBase PnlBrlyNavBase::ContIac
#define StatAppBrlyNavBase PnlBrlyNavBase::StatApp
#define StatShrBrlyNavBase PnlBrlyNavBase::StatShr
#define TagBrlyNavBase PnlBrlyNavBase::Tag

#define DpchAppBrlyNavBaseData PnlBrlyNavBase::DpchAppData
#define DpchAppBrlyNavBaseDo PnlBrlyNavBase::DpchAppDo
#define DpchEngBrlyNavBaseData PnlBrlyNavBase::DpchEngData

/**
  * PnlBrlyNavBase
  */
namespace PnlBrlyNavBase {
	/**
		* VecVDo (full: VecVBrlyNavBaseDo)
		*/
	class VecVDo {

	public:
		static const uint BUTREGVIEWCLICK = 1;
		static const uint BUTREGNEWCRDCLICK = 2;
		static const uint BUTLOCVIEWCLICK = 3;
		static const uint BUTLOCNEWCRDCLICK = 4;
		static const uint BUTLEGVIEWCLICK = 5;
		static const uint BUTLEGNEWCRDCLICK = 6;
		static const uint BUTTTBVIEWCLICK = 7;
		static const uint BUTTTBNEWCRDCLICK = 8;
		static const uint BUTFLTVIEWCLICK = 9;
		static const uint BUTFLTNEWCRDCLICK = 10;
		static const uint BUTSEGVIEWCLICK = 11;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyNavBase)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTREG = 1;
		static const uint NUMFLSTLOC = 2;
		static const uint NUMFLSTLEG = 3;
		static const uint NUMFLSTTTB = 4;
		static const uint NUMFLSTFLT = 5;
		static const uint NUMFLSTSEG = 6;

	public:
		ContIac(const uint numFLstReg = 1, const uint numFLstLoc = 1, const uint numFLstLeg = 1, const uint numFLstTtb = 1, const uint numFLstFlt = 1, const uint numFLstSeg = 1);

	public:
		uint numFLstReg;
		uint numFLstLoc;
		uint numFLstLeg;
		uint numFLstTtb;
		uint numFLstFlt;
		uint numFLstSeg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyNavBase)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint LSTREGALT = 2;
		static const uint LSTLOCALT = 3;
		static const uint LSTLEGALT = 4;
		static const uint LSTTTBALT = 5;
		static const uint LSTFLTALT = 6;
		static const uint LSTSEGALT = 7;
		static const uint LSTREGNUMFIRSTDISP = 8;
		static const uint LSTLOCNUMFIRSTDISP = 9;
		static const uint LSTLEGNUMFIRSTDISP = 10;
		static const uint LSTTTBNUMFIRSTDISP = 11;
		static const uint LSTFLTNUMFIRSTDISP = 12;
		static const uint LSTSEGNUMFIRSTDISP = 13;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstRegAlt = true, const bool LstLocAlt = true, const bool LstLegAlt = true, const bool LstTtbAlt = true, const bool LstFltAlt = true, const bool LstSegAlt = true, const uint LstRegNumFirstdisp = 1, const uint LstLocNumFirstdisp = 1, const uint LstLegNumFirstdisp = 1, const uint LstTtbNumFirstdisp = 1, const uint LstFltNumFirstdisp = 1, const uint LstSegNumFirstdisp = 1);

	public:
		uint ixBrlyVExpstate;
		bool LstRegAlt;
		bool LstLocAlt;
		bool LstLegAlt;
		bool LstTtbAlt;
		bool LstFltAlt;
		bool LstSegAlt;
		uint LstRegNumFirstdisp;
		uint LstLocNumFirstdisp;
		uint LstLegNumFirstdisp;
		uint LstTtbNumFirstdisp;
		uint LstFltNumFirstdisp;
		uint LstSegNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyNavBase)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTREGAVAIL = 1;
		static const uint BUTREGVIEWACTIVE = 2;
		static const uint LSTLOCAVAIL = 3;
		static const uint BUTLOCVIEWACTIVE = 4;
		static const uint LSTLEGAVAIL = 5;
		static const uint BUTLEGVIEWACTIVE = 6;
		static const uint LSTTTBAVAIL = 7;
		static const uint BUTTTBVIEWACTIVE = 8;
		static const uint LSTFLTAVAIL = 9;
		static const uint BUTFLTVIEWACTIVE = 10;
		static const uint LSTSEGAVAIL = 11;
		static const uint BUTSEGVIEWACTIVE = 12;

	public:
		StatShr(const bool LstRegAvail = true, const bool ButRegViewActive = true, const bool LstLocAvail = true, const bool ButLocViewActive = true, const bool LstLegAvail = true, const bool ButLegViewActive = true, const bool LstTtbAvail = true, const bool ButTtbViewActive = true, const bool LstFltAvail = true, const bool ButFltViewActive = true, const bool LstSegAvail = true, const bool ButSegViewActive = true);

	public:
		bool LstRegAvail;
		bool ButRegViewActive;
		bool LstLocAvail;
		bool ButLocViewActive;
		bool LstLegAvail;
		bool ButLegViewActive;
		bool LstTtbAvail;
		bool ButTtbViewActive;
		bool LstFltAvail;
		bool ButFltViewActive;
		bool LstSegAvail;
		bool ButSegViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyNavBase)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTREG = 2;
		static const uint CPTLOC = 3;
		static const uint CPTLEG = 4;
		static const uint CPTTTB = 5;
		static const uint CPTFLT = 6;
		static const uint CPTSEG = 7;

	public:
		Tag(const string& Cpt = "", const string& CptReg = "", const string& CptLoc = "", const string& CptLeg = "", const string& CptTtb = "", const string& CptFlt = "", const string& CptSeg = "");

	public:
		string Cpt;
		string CptReg;
		string CptLoc;
		string CptLeg;
		string CptTtb;
		string CptFlt;
		string CptSeg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyNavBaseData)
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
		* DpchAppDo (full: DpchAppBrlyNavBaseDo)
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
		* DpchEngData (full: DpchEngBrlyNavBaseData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTFLT = 3;
		static const uint FEEDFLSTLEG = 4;
		static const uint FEEDFLSTLOC = 5;
		static const uint FEEDFLSTREG = 6;
		static const uint FEEDFLSTSEG = 7;
		static const uint FEEDFLSTTTB = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstFlt;
		Feed feedFLstLeg;
		Feed feedFLstLoc;
		Feed feedFLstReg;
		Feed feedFLstSeg;
		Feed feedFLstTtb;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

