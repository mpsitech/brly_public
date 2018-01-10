/**
  * \file SessBrly.h
  * API code for job SessBrly (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef SESSBRLY_H
#define SESSBRLY_H

#include "ApiBrly_blks.h"

#define StatShrSessBrly SessBrly::StatShr

#define DpchEngSessBrlyData SessBrly::DpchEngData

/**
  * SessBrly
  */
namespace SessBrly {
	/**
	  * StatShr (full: StatShrSessBrly)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFCRDNAV = 1;

	public:
		StatShr(const string& scrJrefCrdnav = "");

	public:
		string scrJrefCrdnav;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessBrlyData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STATSHR = 2;

	public:
		DpchEngData();

	public:
		StatShr statshr;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

