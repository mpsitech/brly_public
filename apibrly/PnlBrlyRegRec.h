/**
  * \file PnlBrlyRegRec.h
  * API code for job PnlBrlyRegRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYREGREC_H
#define PNLBRLYREGREC_H

#include "ApiBrly_blks.h"

#define VecVBrlyRegRecDo PnlBrlyRegRec::VecVDo

#define ContInfBrlyRegRec PnlBrlyRegRec::ContInf
#define StatAppBrlyRegRec PnlBrlyRegRec::StatApp
#define StatShrBrlyRegRec PnlBrlyRegRec::StatShr
#define TagBrlyRegRec PnlBrlyRegRec::Tag

#define DpchAppBrlyRegRecDo PnlBrlyRegRec::DpchAppDo
#define DpchEngBrlyRegRecData PnlBrlyRegRec::DpchEngData

/**
  * PnlBrlyRegRec
  */
namespace PnlBrlyRegRec {
	/**
		* VecVDo (full: VecVBrlyRegRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyRegRec)
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
	  * StatApp (full: StatAppBrlyRegRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEADSTSWITCH = 2;
		static const uint INITDONE1NLOCATION = 3;
		static const uint INITDONESUP1NREGION = 4;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneADstswitch = false, const bool initdone1NLocation = false, const bool initdoneSup1NRegion = false);

	public:
		bool initdoneDetail;
		bool initdoneADstswitch;
		bool initdone1NLocation;
		bool initdoneSup1NRegion;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyRegRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFADSTSWITCH = 3;
		static const uint SCRJREF1NLOCATION = 4;
		static const uint PNL1NLOCATIONAVAIL = 5;
		static const uint SCRJREFSUP1NREGION = 6;
		static const uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefADstswitch = "", const string& scrJref1NLocation = "", const bool pnl1nlocationAvail = false, const string& scrJrefSup1NRegion = "", const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		string scrJrefDetail;
		string scrJrefADstswitch;
		string scrJref1NLocation;
		bool pnl1nlocationAvail;
		string scrJrefSup1NRegion;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyRegRec)
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
		* DpchAppDo (full: DpchAppBrlyRegRecDo)
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
		* DpchEngData (full: DpchEngBrlyRegRecData)
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

