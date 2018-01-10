/**
  * \file PnlBrlyFltEqp1NNode.h
  * job handler for job PnlBrlyFltEqp1NNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFLTEQP1NNODE_H
#define PNLBRLYFLTEQP1NNODE_H

// IP custInclude --- INSERT

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
class PnlBrlyFltEqp1NNode : public JobBrly {

public:
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
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyFltEqp1NNode)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
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
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFltEqp1NNodeData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryBrlyFltEqp1NNode::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFltEqp1NNodeDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngBrlyFltEqp1NNodeData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STGIAC = 5;
		static const uint TAG = 6;
		static const uint RST = 7;
		static const uint STATAPPQRY = 8;
		static const uint STATSHRQRY = 9;
		static const uint STGIACQRY = 10;
		static const uint ALL = 11;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, StgIac* stgiac = NULL, ListBrlyQFltEqp1NNode* rst = NULL, QryBrlyFltEqp1NNode::StatShr* statshrqry = NULL, QryBrlyFltEqp1NNode::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StgIac stgiac;
		ListBrlyQFltEqp1NNode rst;
		QryBrlyFltEqp1NNode::StatShr statshrqry;
		QryBrlyFltEqp1NNode::StgIac stgiacqry;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	PnlBrlyFltEqp1NNode(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyFltEqp1NNode();

public:
	ContInf continf;
	StgIac stgiac;

	Feed feedFCsiQst;

	QryBrlyFltEqp1NNode* qry;

	BrlyMNode recNde;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiac(DbsBrly* dbsbrly, StgIac* _stgiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqry(DbsBrly* dbsbrly, QryBrlyFltEqp1NNode::StgIac* _stgiacqry, DpchEngBrly** dpcheng);

	void handleDpchAppDoButRefreshClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
};

#endif

