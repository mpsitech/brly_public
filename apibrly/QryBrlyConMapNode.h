/**
  * \file QryBrlyConMapNode.h
  * API code for job QryBrlyConMapNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef QRYBRLYCONMAPNODE_H
#define QRYBRLYCONMAPNODE_H

#include "ApiBrly_blks.h"

#define StatShrQryBrlyConMapNode QryBrlyConMapNode::StatShr
#define StgIacQryBrlyConMapNode QryBrlyConMapNode::StgIac

/**
  * QryBrlyConMapNode
  */
namespace QryBrlyConMapNode {
	/**
	  * StatShr (full: StatShrQryBrlyConMapNode)
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
	  * StgIac (full: StgIacQryBrlyConMapNode)
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

