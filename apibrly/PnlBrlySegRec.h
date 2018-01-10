/**
  * \file PnlBrlySegRec.h
  * API code for job PnlBrlySegRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYSEGREC_H
#define PNLBRLYSEGREC_H

#include "ApiBrly_blks.h"

#define VecVBrlySegRecDo PnlBrlySegRec::VecVDo

#define ContInfBrlySegRec PnlBrlySegRec::ContInf
#define StatAppBrlySegRec PnlBrlySegRec::StatApp
#define StatShrBrlySegRec PnlBrlySegRec::StatShr
#define TagBrlySegRec PnlBrlySegRec::Tag

#define DpchAppBrlySegRecDo PnlBrlySegRec::DpchAppDo
#define DpchEngBrlySegRecData PnlBrlySegRec::DpchEngData

/**
  * PnlBrlySegRec
  */
namespace PnlBrlySegRec {
	/**
		* VecVDo (full: VecVBrlySegRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlySegRec)
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
	  * StatApp (full: StatAppBrlySegRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEPRE = 1;
		static const uint INITDONEDETAIL = 2;
		static const uint INITDONEMNCONNECTION = 3;
		static const uint INITDONEMNLOCATION = 4;
		static const uint INITDONEORGMNSEGMENT = 5;

	public:
		StatApp(const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneMNConnection = false, const bool initdoneMNLocation = false, const bool initdoneOrgMNSegment = false);

	public:
		bool initdonePre;
		bool initdoneDetail;
		bool initdoneMNConnection;
		bool initdoneMNLocation;
		bool initdoneOrgMNSegment;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlySegRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint SCRJREFPRE = 2;
		static const uint SCRJREFDETAIL = 3;
		static const uint SCRJREFMNCONNECTION = 4;
		static const uint SCRJREFMNLOCATION = 5;
		static const uint SCRJREFORGMNSEGMENT = 6;
		static const uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const string& scrJrefPre = "", const string& scrJrefDetail = "", const string& scrJrefMNConnection = "", const string& scrJrefMNLocation = "", const string& scrJrefOrgMNSegment = "", const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		string scrJrefPre;
		string scrJrefDetail;
		string scrJrefMNConnection;
		string scrJrefMNLocation;
		string scrJrefOrgMNSegment;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlySegRec)
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
		* DpchAppDo (full: DpchAppBrlySegRecDo)
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
		* DpchEngData (full: DpchEngBrlySegRecData)
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

