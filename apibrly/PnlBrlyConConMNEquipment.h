/**
  * \file PnlBrlyConConMNEquipment.h
  * API code for job PnlBrlyConConMNEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYCONCONMNEQUIPMENT_H
#define PNLBRLYCONCONMNEQUIPMENT_H

#include "ApiBrly_blks.h"

#include "BrlyQConConMNEquipment.h"

#include "QryBrlyConConMNEquipment.h"

#define VecVBrlyConConMNEquipmentDo PnlBrlyConConMNEquipment::VecVDo

#define ContInfBrlyConConMNEquipment PnlBrlyConConMNEquipment::ContInf
#define StatAppBrlyConConMNEquipment PnlBrlyConConMNEquipment::StatApp
#define StatShrBrlyConConMNEquipment PnlBrlyConConMNEquipment::StatShr
#define StgIacBrlyConConMNEquipment PnlBrlyConConMNEquipment::StgIac
#define TagBrlyConConMNEquipment PnlBrlyConConMNEquipment::Tag

#define DpchAppBrlyConConMNEquipmentData PnlBrlyConConMNEquipment::DpchAppData
#define DpchAppBrlyConConMNEquipmentDo PnlBrlyConConMNEquipment::DpchAppDo
#define DpchEngBrlyConConMNEquipmentData PnlBrlyConConMNEquipment::DpchEngData

/**
  * PnlBrlyConConMNEquipment
  */
namespace PnlBrlyConConMNEquipment {
	/**
		* VecVDo (full: VecVBrlyConConMNEquipmentDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUPCLICK = 1;
		static const uint BUTDOWNCLICK = 2;
		static const uint BUTVIEWCLICK = 3;
		static const uint BUTADDCLICK = 4;
		static const uint BUTSUBCLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyConConMNEquipment)
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
	  * StatApp (full: StatAppBrlyConConMNEquipment)
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
	  * StatShr (full: StatShrBrlyConConMNEquipment)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTUPAVAIL = 1;
		static const uint BUTUPACTIVE = 2;
		static const uint BUTDOWNAVAIL = 3;
		static const uint BUTDOWNACTIVE = 4;
		static const uint BUTVIEWAVAIL = 5;
		static const uint BUTVIEWACTIVE = 6;
		static const uint BUTADDAVAIL = 7;
		static const uint BUTSUBAVAIL = 8;
		static const uint BUTSUBACTIVE = 9;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
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
	  * StgIac (full: StgIacBrlyConConMNEquipment)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOMREFWIDTH = 1;

	public:
		StgIac(const uint TcoMrefWidth = 100);

	public:
		uint TcoMrefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyConConMNEquipment)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOMREF = 5;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoMref = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoMref;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyConConMNEquipmentData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlyConConMNEquipment::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlyConConMNEquipment::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyConConMNEquipmentDo)
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
		* DpchEngData (full: DpchEngBrlyConConMNEquipmentData)
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
		ListBrlyQConConMNEquipment rst;
		QryBrlyConConMNEquipment::StatApp statappqry;
		QryBrlyConConMNEquipment::StatShr statshrqry;
		QryBrlyConConMNEquipment::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

