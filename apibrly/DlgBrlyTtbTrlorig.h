/**
  * \file DlgBrlyTtbTrlorig.h
  * API code for job DlgBrlyTtbTrlorig (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef DLGBRLYTTBTRLORIG_H
#define DLGBRLYTTBTRLORIG_H

#include "ApiBrly_blks.h"

#define VecVDlgBrlyTtbTrlorigDit DlgBrlyTtbTrlorig::VecVDit
#define VecVDlgBrlyTtbTrlorigDo DlgBrlyTtbTrlorig::VecVDo
#define VecVDlgBrlyTtbTrlorigDoTrl DlgBrlyTtbTrlorig::VecVDoTrl
#define VecVDlgBrlyTtbTrlorigSge DlgBrlyTtbTrlorig::VecVSge
#define VecVDlgBrlyTtbTrlorigSrc DlgBrlyTtbTrlorig::VecVSrc

#define ContIacDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::ContIac
#define ContIacDlgBrlyTtbTrlorigDet DlgBrlyTtbTrlorig::ContIacDet
#define ContInfDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::ContInf
#define ContInfDlgBrlyTtbTrlorigTrl DlgBrlyTtbTrlorig::ContInfTrl
#define StatAppDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::StatApp
#define StatShrDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::StatShr
#define StatShrDlgBrlyTtbTrlorigRfi DlgBrlyTtbTrlorig::StatShrRfi
#define StatShrDlgBrlyTtbTrlorigTfi DlgBrlyTtbTrlorig::StatShrTfi
#define StatShrDlgBrlyTtbTrlorigTrl DlgBrlyTtbTrlorig::StatShrTrl
#define TagDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::Tag
#define TagDlgBrlyTtbTrlorigDet DlgBrlyTtbTrlorig::TagDet
#define TagDlgBrlyTtbTrlorigRfi DlgBrlyTtbTrlorig::TagRfi
#define TagDlgBrlyTtbTrlorigTfi DlgBrlyTtbTrlorig::TagTfi
#define TagDlgBrlyTtbTrlorigTrl DlgBrlyTtbTrlorig::TagTrl

#define DpchAppDlgBrlyTtbTrlorigData DlgBrlyTtbTrlorig::DpchAppData
#define DpchAppDlgBrlyTtbTrlorigDo DlgBrlyTtbTrlorig::DpchAppDo
#define DpchEngDlgBrlyTtbTrlorigData DlgBrlyTtbTrlorig::DpchEngData

/**
  * DlgBrlyTtbTrlorig
  */
namespace DlgBrlyTtbTrlorig {
	/**
		* VecVDit (full: VecVDlgBrlyTtbTrlorigDit)
		*/
	class VecVDit {

	public:
		static const uint DET = 1;
		static const uint RFI = 2;
		static const uint TRL = 3;
		static const uint TFI = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDo (full: VecVDlgBrlyTtbTrlorigDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoTrl (full: VecVDlgBrlyTtbTrlorigDoTrl)
		*/
	class VecVDoTrl {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyTtbTrlorigSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ULDDONE = 2;
		static const uint TRANSLATE = 3;
		static const uint DONE = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSrc (full: VecVDlgBrlyTtbTrlorigSrc)
		*/
	class VecVSrc {

	public:
		static const uint STAR = 1;
		static const uint OW = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyTtbTrlorig)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDSE = 1;

	public:
		ContIac(const uint numFDse = 1);

	public:
		uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacDet (full: ContIacDlgBrlyTtbTrlorigDet)
	  */
	class ContIacDet : public Block {

	public:
		static const uint NUMFPUPSRC = 1;

	public:
		ContIacDet(const uint numFPupSrc = 1);

	public:
		uint numFPupSrc;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacDet* comp);
		set<uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyTtbTrlorig)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;

	public:
		ContInf(const uint numFSge = 1);

	public:
		uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfTrl (full: ContInfDlgBrlyTtbTrlorigTrl)
	  */
	class ContInfTrl : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfTrl(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInfTrl* comp);
		set<uint> diff(const ContInfTrl* comp);
	};

	/**
	  * StatApp (full: StatAppDlgBrlyTtbTrlorig)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONE = 1;
		static const uint SHORTMENU = 2;

	public:
		StatApp(const bool initdone = false, const string& shortMenu = "");

	public:
		bool initdone;
		string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgBrlyTtbTrlorig)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrRfi (full: StatShrDlgBrlyTtbTrlorigRfi)
	  */
	class StatShrRfi : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrRfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrRfi* comp);
		set<uint> diff(const StatShrRfi* comp);
	};

	/**
	  * StatShrTfi (full: StatShrDlgBrlyTtbTrlorigTfi)
	  */
	class StatShrTfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrTfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrTfi* comp);
		set<uint> diff(const StatShrTfi* comp);
	};

	/**
	  * StatShrTrl (full: StatShrDlgBrlyTtbTrlorigTrl)
	  */
	class StatShrTrl : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrTrl(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrTrl* comp);
		set<uint> diff(const StatShrTrl* comp);
	};

	/**
	  * Tag (full: TagDlgBrlyTtbTrlorig)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint BUTDNE = 2;

	public:
		Tag(const string& Cpt = "", const string& ButDne = "");

	public:
		string Cpt;
		string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagDet (full: TagDlgBrlyTtbTrlorigDet)
	  */
	class TagDet : public Block {

	public:
		static const uint CPTSRC = 1;

	public:
		TagDet(const string& CptSrc = "");

	public:
		string CptSrc;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagRfi (full: TagDlgBrlyTtbTrlorigRfi)
	  */
	class TagRfi : public Block {

	public:
		static const uint ULD = 1;
		static const uint CPT = 2;

	public:
		TagRfi(const string& Uld = "", const string& Cpt = "");

	public:
		string Uld;
		string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagTfi (full: TagDlgBrlyTtbTrlorigTfi)
	  */
	class TagTfi : public Block {

	public:
		static const uint DLD = 1;

	public:
		TagTfi(const string& Dld = "");

	public:
		string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagTrl (full: TagDlgBrlyTtbTrlorigTrl)
	  */
	class TagTrl : public Block {

	public:
		static const uint CPTPRG = 1;
		static const uint BUTRUN = 2;
		static const uint BUTSTO = 3;

	public:
		TagTrl(const string& CptPrg = "", const string& ButRun = "", const string& ButSto = "");

	public:
		string CptPrg;
		string ButRun;
		string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyTtbTrlorigData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACDET = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppDlgBrlyTtbTrlorigDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOTRL = 3;
		static const uint ALL = 4;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const uint ixVDoTrl = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;
		uint ixVDoTrl;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyTtbTrlorigData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACDET = 3;
		static const uint CONTINF = 4;
		static const uint CONTINFTRL = 5;
		static const uint FEEDFDETPUPSRC = 6;
		static const uint FEEDFDSE = 7;
		static const uint FEEDFSGE = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint STATSHRRFI = 11;
		static const uint STATSHRTFI = 12;
		static const uint STATSHRTRL = 13;
		static const uint TAG = 14;
		static const uint TAGDET = 15;
		static const uint TAGRFI = 16;
		static const uint TAGTFI = 17;
		static const uint TAGTRL = 18;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfTrl continftrl;
		Feed feedFDetPupSrc;
		Feed feedFDse;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrRfi statshrrfi;
		StatShrTfi statshrtfi;
		StatShrTrl statshrtrl;
		Tag tag;
		TagDet tagdet;
		TagRfi tagrfi;
		TagTfi tagtfi;
		TagTrl tagtrl;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

