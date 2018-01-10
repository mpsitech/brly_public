/**
  * \file PnlBrlyLocRec.h
  * job handler for job PnlBrlyLocRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLOCREC_H
#define PNLBRLYLOCREC_H

// IP custInclude --- INSERT

#include "PnlBrlyLocDetail.h"
#include "PnlBrlyLocMap.h"
#include "PnlBrlyLocBgn1NLeg.h"
#include "PnlBrlyLocEnd1NLeg.h"
#include "PnlBrlyLocEqp1NNode.h"
#include "PnlBrlyLocMNSegment.h"
#include "PnlBrlyLocProxOrgMNLocation.h"
#include "PnlBrlyLocVisOrgMNLocation.h"
#include "PnlBrlyLocMNLeg.h"
#include "PnlBrlyLocMNFlight.h"
#include "PnlBrlyLocEqpMNConnection.h"

#define VecVBrlyLocRecDo PnlBrlyLocRec::VecVDo

#define ContInfBrlyLocRec PnlBrlyLocRec::ContInf
#define StatAppBrlyLocRec PnlBrlyLocRec::StatApp
#define StatShrBrlyLocRec PnlBrlyLocRec::StatShr
#define TagBrlyLocRec PnlBrlyLocRec::Tag

#define DpchAppBrlyLocRecDo PnlBrlyLocRec::DpchAppDo
#define DpchEngBrlyLocRecData PnlBrlyLocRec::DpchEngData

/**
  * PnlBrlyLocRec
  */
class PnlBrlyLocRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLocRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLocRec)
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
		* StatApp (full: StatAppBrlyLocRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneMap = false, const bool initdoneBgn1NLeg = false, const bool initdoneEnd1NLeg = false, const bool initdoneEqp1NNode = false, const bool initdoneMNSegment = false, const bool initdoneProxOrgMNLocation = false, const bool initdoneVisOrgMNLocation = false, const bool initdoneMNLeg = false, const bool initdoneMNFlight = false, const bool initdoneEqpMNConnection = false);
	};

	/**
		* StatShr (full: StatShrBrlyLocRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREFMAP = 3;
		static const uint JREFBGN1NLEG = 4;
		static const uint PNLBGN1NLEGAVAIL = 5;
		static const uint JREFEND1NLEG = 6;
		static const uint PNLEND1NLEGAVAIL = 7;
		static const uint JREFEQP1NNODE = 8;
		static const uint PNLEQP1NNODEAVAIL = 9;
		static const uint JREFMNSEGMENT = 10;
		static const uint JREFPROXORGMNLOCATION = 11;
		static const uint JREFVISORGMNLOCATION = 12;
		static const uint JREFMNLEG = 13;
		static const uint JREFMNFLIGHT = 14;
		static const uint JREFEQPMNCONNECTION = 15;
		static const uint PNLEQPMNCONNECTIONAVAIL = 16;
		static const uint BUTREGULARIZEACTIVE = 17;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jrefMap = 0, const ubigint jrefBgn1NLeg = 0, const bool pnlbgn1nlegAvail = false, const ubigint jrefEnd1NLeg = 0, const bool pnlend1nlegAvail = false, const ubigint jrefEqp1NNode = 0, const bool pnleqp1nnodeAvail = false, const ubigint jrefMNSegment = 0, const ubigint jrefProxOrgMNLocation = 0, const ubigint jrefVisOrgMNLocation = 0, const ubigint jrefMNLeg = 0, const ubigint jrefMNFlight = 0, const ubigint jrefEqpMNConnection = 0, const bool pnleqpmnconnectionAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		ubigint jrefDetail;
		ubigint jrefMap;
		ubigint jrefBgn1NLeg;
		bool pnlbgn1nlegAvail;
		ubigint jrefEnd1NLeg;
		bool pnlend1nlegAvail;
		ubigint jrefEqp1NNode;
		bool pnleqp1nnodeAvail;
		ubigint jrefMNSegment;
		ubigint jrefProxOrgMNLocation;
		ubigint jrefVisOrgMNLocation;
		ubigint jrefMNLeg;
		ubigint jrefMNFlight;
		ubigint jrefEqpMNConnection;
		bool pnleqpmnconnectionAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyLocRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocRecDo)
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
		* DpchEngData (full: DpchEngBrlyLocRecData)
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

	bool evalPnlbgn1nlegAvail(DbsBrly* dbsbrly);
	bool evalPnlend1nlegAvail(DbsBrly* dbsbrly);
	bool evalPnleqp1nnodeAvail(DbsBrly* dbsbrly);
	bool evalPnleqpmnconnectionAvail(DbsBrly* dbsbrly);
	bool evalButRegularizeActive(DbsBrly* dbsbrly);

public:
	PnlBrlyLocRec(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyLocRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlyLocDetail* pnldetail;
	PnlBrlyLocMap* pnlmap;
	PnlBrlyLocBgn1NLeg* pnlbgn1nleg;
	PnlBrlyLocEnd1NLeg* pnlend1nleg;
	PnlBrlyLocEqp1NNode* pnleqp1nnode;
	PnlBrlyLocMNSegment* pnlmnsegment;
	PnlBrlyLocProxOrgMNLocation* pnlproxorgmnlocation;
	PnlBrlyLocVisOrgMNLocation* pnlvisorgmnlocation;
	PnlBrlyLocMNLeg* pnlmnleg;
	PnlBrlyLocMNFlight* pnlmnflight;
	PnlBrlyLocEqpMNConnection* pnleqpmnconnection;

	BrlyMLocation recLoc;
	uint ixWSubsetLoc;

	BrlyMEquipment recEqp;
	uint ixWSubsetEqp;

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

	bool handleCallBrlyEqpUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyLocUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

