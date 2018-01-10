/**
  * \file PnlBrlyPty1NEquipment.h
  * API code for job PnlBrlyPty1NEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYPTY1NEQUIPMENT_H
#define PNLBRLYPTY1NEQUIPMENT_H

#include "ApiBrly_blks.h"

#include "BrlyQPty1NEquipment.h"

#include "QryBrlyPty1NEquipment.h"

#define VecVBrlyPty1NEquipmentDo PnlBrlyPty1NEquipment::VecVDo

#define ContInfBrlyPty1NEquipment PnlBrlyPty1NEquipment::ContInf
#define StatAppBrlyPty1NEquipment PnlBrlyPty1NEquipment::StatApp
#define StgIacBrlyPty1NEquipment PnlBrlyPty1NEquipment::StgIac
#define TagBrlyPty1NEquipment PnlBrlyPty1NEquipment::Tag

#define DpchAppBrlyPty1NEquipmentData PnlBrlyPty1NEquipment::DpchAppData
#define DpchAppBrlyPty1NEquipmentDo PnlBrlyPty1NEquipment::DpchAppDo
#define DpchEngBrlyPty1NEquipmentData PnlBrlyPty1NEquipment::DpchEngData

/**
  * PnlBrlyPty1NEquipment
  */
namespace PnlBrlyPty1NEquipment {
	/**
		* VecVDo (full: VecVBrlyPty1NEquipmentDo)
		*/
	class VecVDo {

	public:
		static const uint BUTREFRESHCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyPty1NEquipment)
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
	  * StatApp (full: StatAppBrlyPty1NEquipment)
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
	  * StgIac (full: StgIacBrlyPty1NEquipment)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOREFWIDTH = 1;

	public:
		StgIac(const uint TcoRefWidth = 100);

	public:
		uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyPty1NEquipment)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOREF = 5;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoRef = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyPty1NEquipmentData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlyPty1NEquipment::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlyPty1NEquipment::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyPty1NEquipmentDo)
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
		* DpchEngData (full: DpchEngBrlyPty1NEquipmentData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STGIAC = 5;
		static const uint TAG = 6;
		static const uint RST = 7;
		static const uint STATAPPQRY = 8;
		static const uint STATSHRQRY = 9;
		static const uint STGIACQRY = 10;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StgIac stgiac;
		Tag tag;
		ListBrlyQPty1NEquipment rst;
		QryBrlyPty1NEquipment::StatApp statappqry;
		QryBrlyPty1NEquipment::StatShr statshrqry;
		QryBrlyPty1NEquipment::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

