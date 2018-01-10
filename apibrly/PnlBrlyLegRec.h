/**
  * \file PnlBrlyLegRec.h
  * API code for job PnlBrlyLegRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLEGREC_H
#define PNLBRLYLEGREC_H

#include "ApiBrly_blks.h"

#define VecVBrlyLegRecDo PnlBrlyLegRec::VecVDo

#define ContInfBrlyLegRec PnlBrlyLegRec::ContInf
#define StatAppBrlyLegRec PnlBrlyLegRec::StatApp
#define StatShrBrlyLegRec PnlBrlyLegRec::StatShr
#define TagBrlyLegRec PnlBrlyLegRec::Tag

#define DpchAppBrlyLegRecDo PnlBrlyLegRec::DpchAppDo
#define DpchEngBrlyLegRecData PnlBrlyLegRec::DpchEngData

/**
  * PnlBrlyLegRec
  */
namespace PnlBrlyLegRec {
	/**
		* VecVDo (full: VecVBrlyLegRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLegRec)
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
	  * StatApp (full: StatAppBrlyLegRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEPRE = 1;
		static const uint INITDONEDETAIL = 2;
		static const uint INITDONEMAP = 3;
		static const uint INITDONECOR1NCONNECTION = 4;
		static const uint INITDONE1NFLIGHT = 5;
		static const uint INITDONEMNLOCATION = 6;
		static const uint INITDONEORGMNLEG = 7;

	public:
		StatApp(const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneMap = false, const bool initdoneCor1NConnection = false, const bool initdone1NFlight = false, const bool initdoneMNLocation = false, const bool initdoneOrgMNLeg = false);

	public:
		bool initdonePre;
		bool initdoneDetail;
		bool initdoneMap;
		bool initdoneCor1NConnection;
		bool initdone1NFlight;
		bool initdoneMNLocation;
		bool initdoneOrgMNLeg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyLegRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint SCRJREFPRE = 2;
		static const uint SCRJREFDETAIL = 3;
		static const uint SCRJREFMAP = 4;
		static const uint SCRJREFCOR1NCONNECTION = 5;
		static const uint PNLCOR1NCONNECTIONAVAIL = 6;
		static const uint SCRJREF1NFLIGHT = 7;
		static const uint PNL1NFLIGHTAVAIL = 8;
		static const uint SCRJREFMNLOCATION = 9;
		static const uint SCRJREFORGMNLEG = 10;
		static const uint BUTREGULARIZEACTIVE = 11;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const string& scrJrefPre = "", const string& scrJrefDetail = "", const string& scrJrefMap = "", const string& scrJrefCor1NConnection = "", const bool pnlcor1nconnectionAvail = false, const string& scrJref1NFlight = "", const bool pnl1nflightAvail = false, const string& scrJrefMNLocation = "", const string& scrJrefOrgMNLeg = "", const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		string scrJrefPre;
		string scrJrefDetail;
		string scrJrefMap;
		string scrJrefCor1NConnection;
		bool pnlcor1nconnectionAvail;
		string scrJref1NFlight;
		bool pnl1nflightAvail;
		string scrJrefMNLocation;
		string scrJrefOrgMNLeg;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyLegRec)
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
		* DpchAppDo (full: DpchAppBrlyLegRecDo)
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
		* DpchEngData (full: DpchEngBrlyLegRecData)
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

