/**
  * \file PnlBrlyPtyRec.h
  * API code for job PnlBrlyPtyRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYPTYREC_H
#define PNLBRLYPTYREC_H

#include "ApiBrly_blks.h"

#define VecVBrlyPtyRecDo PnlBrlyPtyRec::VecVDo

#define ContInfBrlyPtyRec PnlBrlyPtyRec::ContInf
#define StatAppBrlyPtyRec PnlBrlyPtyRec::StatApp
#define StatShrBrlyPtyRec PnlBrlyPtyRec::StatShr
#define TagBrlyPtyRec PnlBrlyPtyRec::Tag

#define DpchAppBrlyPtyRecDo PnlBrlyPtyRec::DpchAppDo
#define DpchEngBrlyPtyRecData PnlBrlyPtyRec::DpchEngData

/**
  * PnlBrlyPtyRec
  */
namespace PnlBrlyPtyRec {
	/**
		* VecVDo (full: VecVBrlyPtyRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyPtyRec)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREF = 1;

	public:
		ContInf(const string& TxtRef = "");

	public:
		string TxtRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyPtyRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONE1NEQUIPMENT = 2;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NEquipment = false);

	public:
		bool initdoneDetail;
		bool initdone1NEquipment;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyPtyRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREF1NEQUIPMENT = 3;
		static const uint BUTREGULARIZEACTIVE = 4;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJref1NEquipment = "", const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		string scrJrefDetail;
		string scrJref1NEquipment;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyPtyRec)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;

	public:
		Tag(const string& Cpt = "");

	public:
		string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyPtyRecDo)
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
		* DpchEngData (full: DpchEngBrlyPtyRecData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

