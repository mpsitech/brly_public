/**
  * \file PnlBrlyLegRec.h
  * job handler for job PnlBrlyLegRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLEGREC_H
#define PNLBRLYLEGREC_H

// IP custInclude --- INSERT

#include "PnlBrlyLegPre.h"
#include "PnlBrlyLegDetail.h"
#include "PnlBrlyLegMap.h"
#include "PnlBrlyLegCor1NConnection.h"
#include "PnlBrlyLeg1NFlight.h"
#include "PnlBrlyLegMNLocation.h"
#include "PnlBrlyLegOrgMNLeg.h"

#define VecVBrlyLegRecDo PnlBrlyLegRec::VecVDo

#define ContInfBrlyLegRec PnlBrlyLegRec::ContInf
#define StatAppBrlyLegRec PnlBrlyLegRec::StatApp
#define StatShrBrlyLegRec PnlBrlyLegRec::StatShr
#define TagBrlyLegRec PnlBrlyLegRec::Tag

#define DpchAppBrlyLegRecDo PnlBrlyLegRec::DpchAppDo
#define DpchEngBrlyLegRecData PnlBrlyLegRec::DpchEngData

/**
  * PnlBrlyLegRec
  */
class PnlBrlyLegRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLegRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLegRec)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREF = 1;

	public:
		ContInf(const string& TxtRef = "");

	public:
		string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyLegRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneMap = false, const bool initdoneCor1NConnection = false, const bool initdone1NFlight = false, const bool initdoneMNLocation = false, const bool initdoneOrgMNLeg = false);
	};

	/**
		* StatShr (full: StatShrBrlyLegRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint JREFPRE = 2;
		static const uint JREFDETAIL = 3;
		static const uint JREFMAP = 4;
		static const uint JREFCOR1NCONNECTION = 5;
		static const uint PNLCOR1NCONNECTIONAVAIL = 6;
		static const uint JREF1NFLIGHT = 7;
		static const uint PNL1NFLIGHTAVAIL = 8;
		static const uint JREFMNLOCATION = 9;
		static const uint JREFORGMNLEG = 10;
		static const uint BUTREGULARIZEACTIVE = 11;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const ubigint jrefPre = 0, const ubigint jrefDetail = 0, const ubigint jrefMap = 0, const ubigint jrefCor1NConnection = 0, const bool pnlcor1nconnectionAvail = false, const ubigint jref1NFlight = 0, const bool pnl1nflightAvail = false, const ubigint jrefMNLocation = 0, const ubigint jrefOrgMNLeg = 0, const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		ubigint jrefPre;
		ubigint jrefDetail;
		ubigint jrefMap;
		ubigint jrefCor1NConnection;
		bool pnlcor1nconnectionAvail;
		ubigint jref1NFlight;
		bool pnl1nflightAvail;
		ubigint jrefMNLocation;
		ubigint jrefOrgMNLeg;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyLegRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLegRecDo)
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
		* DpchEngData (full: DpchEngBrlyLegRecData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;
		static const uint ALL = 6;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalPnlcor1nconnectionAvail(DbsBrly* dbsbrly);
	bool evalPnl1nflightAvail(DbsBrly* dbsbrly);
	bool evalButRegularizeActive(DbsBrly* dbsbrly);

public:
	PnlBrlyLegRec(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyLegRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlyLegPre* pnlpre;
	PnlBrlyLegDetail* pnldetail;
	PnlBrlyLegMap* pnlmap;
	PnlBrlyLegCor1NConnection* pnlcor1nconnection;
	PnlBrlyLeg1NFlight* pnl1nflight;
	PnlBrlyLegMNLocation* pnlmnlocation;
	PnlBrlyLegOrgMNLeg* pnlorgmnleg;

	BrlyMLeg recLeg;
	uint ixWSubsetLeg;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);
	void minimize(DbsBrly* dbsbrly, const bool notif = false, DpchEngBrly** dpcheng = NULL);
	void regularize(DbsBrly* dbsbrly, const bool notif = false, DpchEngBrly** dpcheng = NULL);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyLegUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

