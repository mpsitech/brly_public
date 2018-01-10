/**
  * \file DlgBrlyTtbNew.h
  * API code for job DlgBrlyTtbNew (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef DLGBRLYTTBNEW_H
#define DLGBRLYTTBNEW_H

#include "ApiBrly_blks.h"

#define VecVDlgBrlyTtbNewDo DlgBrlyTtbNew::VecVDo
#define VecVDlgBrlyTtbNewSge DlgBrlyTtbNew::VecVSge

#define ContIacDlgBrlyTtbNew DlgBrlyTtbNew::ContIac
#define ContInfDlgBrlyTtbNew DlgBrlyTtbNew::ContInf
#define StatAppDlgBrlyTtbNew DlgBrlyTtbNew::StatApp
#define StatShrDlgBrlyTtbNew DlgBrlyTtbNew::StatShr
#define TagDlgBrlyTtbNew DlgBrlyTtbNew::Tag

#define DpchAppDlgBrlyTtbNewData DlgBrlyTtbNew::DpchAppData
#define DpchAppDlgBrlyTtbNewDo DlgBrlyTtbNew::DpchAppDo
#define DpchEngDlgBrlyTtbNewData DlgBrlyTtbNew::DpchEngData

/**
  * DlgBrlyTtbNew
  */
namespace DlgBrlyTtbNew {
	/**
		* VecVDo (full: VecVDlgBrlyTtbNewDo)
		*/
	class VecVDo {

	public:
		static const uint BUTCNCCLICK = 1;
		static const uint BUTCRECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyTtbNewSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint CREATE = 2;
		static const uint DONE = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyTtbNew)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDETPUPALI = 1;
		static const uint DETTXFTIT = 2;
		static const uint DETTXFSTA = 3;
		static const uint DETTXFSTO = 4;

	public:
		ContIac(const uint numFDetPupAli = 1, const string& DetTxfTit = "", const string& DetTxfSta = "", const string& DetTxfSto = "");

	public:
		uint numFDetPupAli;
		string DetTxfTit;
		string DetTxfSta;
		string DetTxfSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyTtbNew)
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
	  * StatApp (full: StatAppDlgBrlyTtbNew)
	  */
	class StatApp : public Block {

	public:
		static const uint SHORTMENU = 1;

	public:
		StatApp(const string& shortMenu = "");

	public:
		string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgBrlyTtbNew)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTCNCACTIVE = 1;
		static const uint BUTCREACTIVE = 2;

	public:
		StatShr(const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool ButCncActive;
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgBrlyTtbNew)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint DETCPTALI = 2;
		static const uint DETCPTTIT = 3;
		static const uint DETCPTSTA = 4;
		static const uint DETCPTSTO = 5;
		static const uint BUTCNC = 6;
		static const uint BUTCRE = 7;

	public:
		Tag(const string& Cpt = "", const string& DetCptAli = "", const string& DetCptTit = "", const string& DetCptSta = "", const string& DetCptSto = "", const string& ButCnc = "", const string& ButCre = "");

	public:
		string Cpt;
		string DetCptAli;
		string DetCptTit;
		string DetCptSta;
		string DetCptSto;
		string ButCnc;
		string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyTtbNewData)
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
		* DpchAppDo (full: DpchAppDlgBrlyTtbNewDo)
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
		* DpchEngData (full: DpchEngDlgBrlyTtbNewData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFDETPUPALI = 4;
		static const uint FEEDFSGE = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFDetPupAli;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

