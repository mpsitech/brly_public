/**
  * \file PnlBrlyLegOrgMNLeg.h
  * API code for job PnlBrlyLegOrgMNLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLEGORGMNLEG_H
#define PNLBRLYLEGORGMNLEG_H

#include "ApiBrly_blks.h"

#include "BrlyQLegOrgMNLeg.h"

#include "QryBrlyLegOrgMNLeg.h"

#define VecVBrlyLegOrgMNLegDo PnlBrlyLegOrgMNLeg::VecVDo

#define ContInfBrlyLegOrgMNLeg PnlBrlyLegOrgMNLeg::ContInf
#define StatAppBrlyLegOrgMNLeg PnlBrlyLegOrgMNLeg::StatApp
#define StatShrBrlyLegOrgMNLeg PnlBrlyLegOrgMNLeg::StatShr
#define StgIacBrlyLegOrgMNLeg PnlBrlyLegOrgMNLeg::StgIac
#define TagBrlyLegOrgMNLeg PnlBrlyLegOrgMNLeg::Tag

#define DpchAppBrlyLegOrgMNLegData PnlBrlyLegOrgMNLeg::DpchAppData
#define DpchAppBrlyLegOrgMNLegDo PnlBrlyLegOrgMNLeg::DpchAppDo
#define DpchEngBrlyLegOrgMNLegData PnlBrlyLegOrgMNLeg::DpchEngData

/**
  * PnlBrlyLegOrgMNLeg
  */
namespace PnlBrlyLegOrgMNLeg {
	/**
		* VecVDo (full: VecVBrlyLegOrgMNLegDo)
		*/
	class VecVDo {

	public:
		static const uint BUTVIEWCLICK = 1;
		static const uint BUTADDCLICK = 2;
		static const uint BUTSUBCLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLegOrgMNLeg)
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
	  * StatApp (full: StatAppBrlyLegOrgMNLeg)
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
	  * StatShr (full: StatShrBrlyLegOrgMNLeg)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTVIEWAVAIL = 1;
		static const uint BUTVIEWACTIVE = 2;
		static const uint BUTADDAVAIL = 3;
		static const uint BUTSUBAVAIL = 4;
		static const uint BUTSUBACTIVE = 5;

	public:
		StatShr(const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButViewAvail;
		bool ButViewActive;
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacBrlyLegOrgMNLeg)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOMREFWIDTH = 1;
		static const uint TCODP0WIDTH = 2;
		static const uint TCODP1WIDTH = 3;
		static const uint TCOOP0WIDTH = 4;
		static const uint TCOOP1WIDTH = 5;
		static const uint TCOXD0WIDTH = 6;
		static const uint TCOXD1WIDTH = 7;
		static const uint TCOXO0WIDTH = 8;
		static const uint TCOXO1WIDTH = 9;

	public:
		StgIac(const uint TcoMrefWidth = 100, const uint TcoDp0Width = 100, const uint TcoDp1Width = 100, const uint TcoOp0Width = 100, const uint TcoOp1Width = 100, const uint TcoXd0Width = 100, const uint TcoXd1Width = 100, const uint TcoXo0Width = 100, const uint TcoXo1Width = 100);

	public:
		uint TcoMrefWidth;
		uint TcoDp0Width;
		uint TcoDp1Width;
		uint TcoOp0Width;
		uint TcoOp1Width;
		uint TcoXd0Width;
		uint TcoXd1Width;
		uint TcoXo0Width;
		uint TcoXo1Width;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyLegOrgMNLeg)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOMREF = 5;
		static const uint TCODP0 = 6;
		static const uint TCODP1 = 7;
		static const uint TCOOP0 = 8;
		static const uint TCOOP1 = 9;
		static const uint TCOXD0 = 10;
		static const uint TCOXD1 = 11;
		static const uint TCOXO0 = 12;
		static const uint TCOXO1 = 13;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoMref = "", const string& TcoDp0 = "", const string& TcoDp1 = "", const string& TcoOp0 = "", const string& TcoOp1 = "", const string& TcoXd0 = "", const string& TcoXd1 = "", const string& TcoXo0 = "", const string& TcoXo1 = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoMref;
		string TcoDp0;
		string TcoDp1;
		string TcoOp0;
		string TcoOp1;
		string TcoXd0;
		string TcoXd1;
		string TcoXo0;
		string TcoXo1;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLegOrgMNLegData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlyLegOrgMNLeg::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlyLegOrgMNLeg::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLegOrgMNLegDo)
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
		* DpchEngData (full: DpchEngBrlyLegOrgMNLegData)
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
		ListBrlyQLegOrgMNLeg rst;
		QryBrlyLegOrgMNLeg::StatApp statappqry;
		QryBrlyLegOrgMNLeg::StatShr statshrqry;
		QryBrlyLegOrgMNLeg::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

