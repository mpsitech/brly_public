/**
  * \file QryBrlyConMapRelay.h
  * API code for job QryBrlyConMapRelay (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYCONMAPRELAY_H
#define QRYBRLYCONMAPRELAY_H

#include "ApiBrly_blks.h"

#define StatShrQryBrlyConMapRelay QryBrlyConMapRelay::StatShr
#define StgIacQryBrlyConMapRelay QryBrlyConMapRelay::StgIac

/**
  * QryBrlyConMapRelay
  */
namespace QryBrlyConMapRelay {
	/**
	  * StatShr (full: StatShrQryBrlyConMapRelay)
	  */
	class StatShr : public Block {

	public:
		static const uint NTOT = 1;

	public:
		StatShr(const uint ntot = 0);

	public:
		uint ntot;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacQryBrlyConMapRelay)
	  */
	class StgIac : public Block {

	public:
		static const uint JNUM = 1;

	public:
		StgIac(const uint jnum = 0);

	public:
		uint jnum;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

};

#endif

