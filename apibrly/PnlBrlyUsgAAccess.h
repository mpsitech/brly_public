/**
  * \file PnlBrlyUsgAAccess.h
  * API code for job PnlBrlyUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYUSGAACCESS_H
#define PNLBRLYUSGAACCESS_H

#include "ApiBrly_blks.h"

#include "BrlyQUsgAAccess.h"

#include "QryBrlyUsgAAccess.h"

#define VecVBrlyUsgAAccessDo PnlBrlyUsgAAccess::VecVDo

#define ContInfBrlyUsgAAccess PnlBrlyUsgAAccess::ContInf
#define StatAppBrlyUsgAAccess PnlBrlyUsgAAccess::StatApp
#define StatShrBrlyUsgAAccess PnlBrlyUsgAAccess::StatShr
#define StgIacBrlyUsgAAccess PnlBrlyUsgAAccess::StgIac
#define TagBrlyUsgAAccess PnlBrlyUsgAAccess::Tag

#define DpchAppBrlyUsgAAccessData PnlBrlyUsgAAccess::DpchAppData
#define DpchAppBrlyUsgAAccessDo PnlBrlyUsgAAccess::DpchAppDo
#define DpchEngBrlyUsgAAccessData PnlBrlyUsgAAccess::DpchEngData

/**
  * PnlBrlyUsgAAccess
  */
namespace PnlBrlyUsgAAccess {
	/**
		* VecVDo (full: VecVBrlyUsgAAccessDo)
		*/
	class VecVDo {

	public:
		static const uint BUTNEWCLICK = 1;
		static const uint BUTDUPLICATECLICK = 2;
		static const uint BUTDELETECLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyUsgAAccess)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyUsgAAccess)
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
	  * StatShr (full: StatShrBrlyUsgAAccess)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTNEWAVAIL = 1;
		static const uint BUTDUPLICATEAVAIL = 2;
		static const uint BUTDUPLICATEACTIVE = 3;
		static const uint BUTDELETEAVAIL = 4;
		static const uint BUTDELETEACTIVE = 5;

	public:
		StatShr(const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacBrlyUsgAAccess)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOCRDWIDTH = 1;
		static const uint TCOUACWIDTH = 2;

	public:
		StgIac(const uint TcoCrdWidth = 100, const uint TcoUacWidth = 100);

	public:
		uint TcoCrdWidth;
		uint TcoUacWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyUsgAAccess)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOCRD = 5;
		static const uint TCOUAC = 6;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoCrd = "", const string& TcoUac = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoCrd;
		string TcoUac;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyUsgAAccessData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlyUsgAAccess::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlyUsgAAccess::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyUsgAAccessDo)
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
		* DpchEngData (full: DpchEngBrlyUsgAAccessData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListBrlyQUsgAAccess rst;
		QryBrlyUsgAAccess::StatApp statappqry;
		QryBrlyUsgAAccess::StatShr statshrqry;
		QryBrlyUsgAAccess::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

