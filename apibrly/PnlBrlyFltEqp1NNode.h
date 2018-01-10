/**
  * \file PnlBrlyFltEqp1NNode.h
  * API code for job PnlBrlyFltEqp1NNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFLTEQP1NNODE_H
#define PNLBRLYFLTEQP1NNODE_H

#include "ApiBrly_blks.h"

#include "BrlyQFltEqp1NNode.h"

#include "QryBrlyFltEqp1NNode.h"

#define VecVBrlyFltEqp1NNodeDo PnlBrlyFltEqp1NNode::VecVDo

#define ContInfBrlyFltEqp1NNode PnlBrlyFltEqp1NNode::ContInf
#define StatAppBrlyFltEqp1NNode PnlBrlyFltEqp1NNode::StatApp
#define StgIacBrlyFltEqp1NNode PnlBrlyFltEqp1NNode::StgIac
#define TagBrlyFltEqp1NNode PnlBrlyFltEqp1NNode::Tag

#define DpchAppBrlyFltEqp1NNodeData PnlBrlyFltEqp1NNode::DpchAppData
#define DpchAppBrlyFltEqp1NNodeDo PnlBrlyFltEqp1NNode::DpchAppDo
#define DpchEngBrlyFltEqp1NNodeData PnlBrlyFltEqp1NNode::DpchEngData

/**
  * PnlBrlyFltEqp1NNode
  */
namespace PnlBrlyFltEqp1NNode {
	/**
		* VecVDo (full: VecVBrlyFltEqp1NNodeDo)
		*/
	class VecVDo {

	public:
		static const uint BUTREFRESHCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyFltEqp1NNode)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyFltEqp1NNode)
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
	  * StgIac (full: StgIacBrlyFltEqp1NNode)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOREFWIDTH = 1;

	public:
		StgIac(const uint TcoRefWidth = 100);

	public:
		uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyFltEqp1NNode)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOREF = 5;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoRef = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFltEqp1NNodeData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlyFltEqp1NNode::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlyFltEqp1NNode::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFltEqp1NNodeDo)
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
		* DpchEngData (full: DpchEngBrlyFltEqp1NNodeData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STGIAC = 5;
		static const uint TAG = 6;
		static const uint RST = 7;
		static const uint STATAPPQRY = 8;
		static const uint STATSHRQRY = 9;
		static const uint STGIACQRY = 10;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StgIac stgiac;
		Tag tag;
		ListBrlyQFltEqp1NNode rst;
		QryBrlyFltEqp1NNode::StatApp statappqry;
		QryBrlyFltEqp1NNode::StatShr statshrqry;
		QryBrlyFltEqp1NNode::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

