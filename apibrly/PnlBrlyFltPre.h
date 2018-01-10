/**
  * \file PnlBrlyFltPre.h
  * API code for job PnlBrlyFltPre (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFLTPRE_H
#define PNLBRLYFLTPRE_H

#include "ApiBrly_blks.h"

#define ContIacBrlyFltPre PnlBrlyFltPre::ContIac
#define StatAppBrlyFltPre PnlBrlyFltPre::StatApp
#define StatShrBrlyFltPre PnlBrlyFltPre::StatShr
#define TagBrlyFltPre PnlBrlyFltPre::Tag

#define DpchAppBrlyFltPreData PnlBrlyFltPre::DpchAppData
#define DpchEngBrlyFltPreData PnlBrlyFltPre::DpchEngData

/**
  * PnlBrlyFltPre
  */
namespace PnlBrlyFltPre {
	/**
	  * ContIac (full: ContIacBrlyFltPre)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDTME = 1;

	public:
		ContIac(const double SldTme = 0.0);

	public:
		double SldTme;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyFltPre)
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
	  * StatShr (full: StatShrBrlyFltPre)
	  */
	class StatShr : public Block {

	public:
		static const uint SLDTMEMIN = 1;
		static const uint SLDTMEMAX = 2;

	public:
		StatShr(const double SldTmeMin = 0.0, const double SldTmeMax = 1.0);

	public:
		double SldTmeMin;
		double SldTmeMax;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyFltPre)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTME = 2;

	public:
		Tag(const string& Cpt = "", const string& CptTme = "");

	public:
		string Cpt;
		string CptTme;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFltPreData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint ALL = 3;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngBrlyFltPreData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

