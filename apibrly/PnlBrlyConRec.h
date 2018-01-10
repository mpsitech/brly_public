/**
  * \file PnlBrlyConRec.h
  * API code for job PnlBrlyConRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYCONREC_H
#define PNLBRLYCONREC_H

#include "ApiBrly_blks.h"

#define VecVBrlyConRecDo PnlBrlyConRec::VecVDo

#define ContInfBrlyConRec PnlBrlyConRec::ContInf
#define StatAppBrlyConRec PnlBrlyConRec::StatApp
#define StatShrBrlyConRec PnlBrlyConRec::StatShr
#define TagBrlyConRec PnlBrlyConRec::Tag

#define DpchAppBrlyConRecDo PnlBrlyConRec::DpchAppDo
#define DpchEngBrlyConRecData PnlBrlyConRec::DpchEngData

/**
  * PnlBrlyConRec
  */
namespace PnlBrlyConRec {
	/**
		* VecVDo (full: VecVBrlyConRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyConRec)
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
	  * StatApp (full: StatAppBrlyConRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEPRE = 1;
		static const uint INITDONEDETAIL = 2;
		static const uint INITDONEMAP = 3;
		static const uint INITDONE1NRELAY = 4;
		static const uint INITDONEREF1NSEGMENT = 5;
		static const uint INITDONEMNSEGMENT = 6;
		static const uint INITDONEMNFLIGHT = 7;
		static const uint INITDONECONMNEQUIPMENT = 8;

	public:
		StatApp(const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneMap = false, const bool initdone1NRelay = false, const bool initdoneRef1NSegment = false, const bool initdoneMNSegment = false, const bool initdoneMNFlight = false, const bool initdoneConMNEquipment = false);

	public:
		bool initdonePre;
		bool initdoneDetail;
		bool initdoneMap;
		bool initdone1NRelay;
		bool initdoneRef1NSegment;
		bool initdoneMNSegment;
		bool initdoneMNFlight;
		bool initdoneConMNEquipment;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyConRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint SCRJREFPRE = 2;
		static const uint SCRJREFDETAIL = 3;
		static const uint SCRJREFMAP = 4;
		static const uint SCRJREF1NRELAY = 5;
		static const uint SCRJREFREF1NSEGMENT = 6;
		static const uint SCRJREFMNSEGMENT = 7;
		static const uint SCRJREFMNFLIGHT = 8;
		static const uint SCRJREFCONMNEQUIPMENT = 9;
		static const uint BUTREGULARIZEACTIVE = 10;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const string& scrJrefPre = "", const string& scrJrefDetail = "", const string& scrJrefMap = "", const string& scrJref1NRelay = "", const string& scrJrefRef1NSegment = "", const string& scrJrefMNSegment = "", const string& scrJrefMNFlight = "", const string& scrJrefConMNEquipment = "", const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		string scrJrefPre;
		string scrJrefDetail;
		string scrJrefMap;
		string scrJref1NRelay;
		string scrJrefRef1NSegment;
		string scrJrefMNSegment;
		string scrJrefMNFlight;
		string scrJrefConMNEquipment;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyConRec)
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
		* DpchAppDo (full: DpchAppBrlyConRecDo)
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
		* DpchEngData (full: DpchEngBrlyConRecData)
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

