/**
  * \file QryBrlyLocMapProxLocation.h
  * API code for job QryBrlyLocMapProxLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYLOCMAPPROXLOCATION_H
#define QRYBRLYLOCMAPPROXLOCATION_H

#include "ApiBrly_blks.h"

#define StatShrQryBrlyLocMapProxLocation QryBrlyLocMapProxLocation::StatShr
#define StgIacQryBrlyLocMapProxLocation QryBrlyLocMapProxLocation::StgIac

/**
  * QryBrlyLocMapProxLocation
  */
namespace QryBrlyLocMapProxLocation {
	/**
	  * StatShr (full: StatShrQryBrlyLocMapProxLocation)
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
	  * StgIac (full: StgIacQryBrlyLocMapProxLocation)
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

