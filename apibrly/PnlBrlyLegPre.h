/**
  * \file PnlBrlyLegPre.h
  * API code for job PnlBrlyLegPre (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLEGPRE_H
#define PNLBRLYLEGPRE_H

#include "ApiBrly_blks.h"

#define ContIacBrlyLegPre PnlBrlyLegPre::ContIac
#define StatAppBrlyLegPre PnlBrlyLegPre::StatApp
#define StatShrBrlyLegPre PnlBrlyLegPre::StatShr
#define TagBrlyLegPre PnlBrlyLegPre::Tag

#define DpchAppBrlyLegPreData PnlBrlyLegPre::DpchAppData
#define DpchEngBrlyLegPreData PnlBrlyLegPre::DpchEngData

/**
  * PnlBrlyLegPre
  */
namespace PnlBrlyLegPre {
	/**
	  * ContIac (full: ContIacBrlyLegPre)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDPHI = 1;

	public:
		ContIac(const double SldPhi = 0.0);

	public:
		double SldPhi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyLegPre)
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
	  * StatShr (full: StatShrBrlyLegPre)
	  */
	class StatShr : public Block {

	public:
		static const uint SLDPHIMIN = 1;
		static const uint SLDPHIMAX = 2;

	public:
		StatShr(const double SldPhiMin = 0.0, const double SldPhiMax = 1.0);

	public:
		double SldPhiMin;
		double SldPhiMax;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyLegPre)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTPHI = 2;

	public:
		Tag(const string& Cpt = "", const string& CptPhi = "");

	public:
		string Cpt;
		string CptPhi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLegPreData)
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
		* DpchEngData (full: DpchEngBrlyLegPreData)
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

