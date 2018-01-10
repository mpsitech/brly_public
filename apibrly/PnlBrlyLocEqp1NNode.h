/**
  * \file PnlBrlyLocEqp1NNode.h
  * API code for job PnlBrlyLocEqp1NNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLOCEQP1NNODE_H
#define PNLBRLYLOCEQP1NNODE_H

#include "ApiBrly_blks.h"

#include "BrlyQLocEqp1NNode.h"

#include "QryBrlyLocEqp1NNode.h"

#define VecVBrlyLocEqp1NNodeDo PnlBrlyLocEqp1NNode::VecVDo

#define ContInfBrlyLocEqp1NNode PnlBrlyLocEqp1NNode::ContInf
#define StatAppBrlyLocEqp1NNode PnlBrlyLocEqp1NNode::StatApp
#define StgIacBrlyLocEqp1NNode PnlBrlyLocEqp1NNode::StgIac
#define TagBrlyLocEqp1NNode PnlBrlyLocEqp1NNode::Tag

#define DpchAppBrlyLocEqp1NNodeData PnlBrlyLocEqp1NNode::DpchAppData
#define DpchAppBrlyLocEqp1NNodeDo PnlBrlyLocEqp1NNode::DpchAppDo
#define DpchEngBrlyLocEqp1NNodeData PnlBrlyLocEqp1NNode::DpchEngData

/**
  * PnlBrlyLocEqp1NNode
  */
namespace PnlBrlyLocEqp1NNode {
	/**
		* VecVDo (full: VecVBrlyLocEqp1NNodeDo)
		*/
	class VecVDo {

	public:
		static const uint BUTREFRESHCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLocEqp1NNode)
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
	  * StatApp (full: StatAppBrlyLocEqp1NNode)
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
	  * StgIac (full: StgIacBrlyLocEqp1NNode)
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
	  * Tag (full: TagBrlyLocEqp1NNode)
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
		* DpchAppData (full: DpchAppBrlyLocEqp1NNodeData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlyLocEqp1NNode::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlyLocEqp1NNode::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocEqp1NNodeDo)
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
		* DpchEngData (full: DpchEngBrlyLocEqp1NNodeData)
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
		ListBrlyQLocEqp1NNode rst;
		QryBrlyLocEqp1NNode::StatApp statappqry;
		QryBrlyLocEqp1NNode::StatShr statshrqry;
		QryBrlyLocEqp1NNode::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

