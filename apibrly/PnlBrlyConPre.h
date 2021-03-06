/**
  * \file PnlBrlyConPre.h
  * API code for job PnlBrlyConPre (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYCONPRE_H
#define PNLBRLYCONPRE_H

#include "ApiBrly_blks.h"

#define ContIacBrlyConPre PnlBrlyConPre::ContIac
#define StatAppBrlyConPre PnlBrlyConPre::StatApp
#define StatShrBrlyConPre PnlBrlyConPre::StatShr
#define TagBrlyConPre PnlBrlyConPre::Tag

#define DpchAppBrlyConPreData PnlBrlyConPre::DpchAppData
#define DpchEngBrlyConPreData PnlBrlyConPre::DpchEngData

/**
  * PnlBrlyConPre
  */
namespace PnlBrlyConPre {
	/**
	  * ContIac (full: ContIacBrlyConPre)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDTME = 1;
		static const uint SLDPHI = 2;

	public:
		ContIac(const double SldTme = 0.0, const double SldPhi = 0.0);

	public:
		double SldTme;
		double SldPhi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyConPre)
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
	  * StatShr (full: StatShrBrlyConPre)
	  */
	class StatShr : public Block {

	public:
		static const uint SLDTMEMIN = 1;
		static const uint SLDTMEMAX = 2;
		static const uint SLDPHIMIN = 3;
		static const uint SLDPHIMAX = 4;

	public:
		StatShr(const double SldTmeMin = 0.0, const double SldTmeMax = 1.0, const double SldPhiMin = 0.0, const double SldPhiMax = 1.0);

	public:
		double SldTmeMin;
		double SldTmeMax;
		double SldPhiMin;
		double SldPhiMax;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyConPre)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTME = 2;
		static const uint CPTPHI = 3;

	public:
		Tag(const string& Cpt = "", const string& CptTme = "", const string& CptPhi = "");

	public:
		string Cpt;
		string CptTme;
		string CptPhi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyConPreData)
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
		* DpchEngData (full: DpchEngBrlyConPreData)
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

