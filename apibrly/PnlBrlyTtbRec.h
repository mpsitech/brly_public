/**
  * \file PnlBrlyTtbRec.h
  * API code for job PnlBrlyTtbRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYTTBREC_H
#define PNLBRLYTTBREC_H

#include "ApiBrly_blks.h"

#define VecVBrlyTtbRecDo PnlBrlyTtbRec::VecVDo

#define ContInfBrlyTtbRec PnlBrlyTtbRec::ContInf
#define StatAppBrlyTtbRec PnlBrlyTtbRec::StatApp
#define StatShrBrlyTtbRec PnlBrlyTtbRec::StatShr
#define TagBrlyTtbRec PnlBrlyTtbRec::Tag

#define DpchAppBrlyTtbRecDo PnlBrlyTtbRec::DpchAppDo
#define DpchEngBrlyTtbRecData PnlBrlyTtbRec::DpchEngData

/**
  * PnlBrlyTtbRec
  */
namespace PnlBrlyTtbRec {
	/**
		* VecVDo (full: VecVBrlyTtbRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyTtbRec)
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
	  * StatApp (full: StatAppBrlyTtbRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONE1NFLIGHT = 2;
		static const uint INITDONEREF1NFILE = 3;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NFlight = false, const bool initdoneRef1NFile = false);

	public:
		bool initdoneDetail;
		bool initdone1NFlight;
		bool initdoneRef1NFile;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyTtbRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREF1NFLIGHT = 3;
		static const uint SCRJREFREF1NFILE = 4;
		static const uint BUTREGULARIZEACTIVE = 5;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJref1NFlight = "", const string& scrJrefRef1NFile = "", const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		string scrJrefDetail;
		string scrJref1NFlight;
		string scrJrefRef1NFile;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyTtbRec)
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
		* DpchAppDo (full: DpchAppBrlyTtbRecDo)
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
		* DpchEngData (full: DpchEngBrlyTtbRecData)
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

