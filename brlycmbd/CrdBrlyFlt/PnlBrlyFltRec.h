/**
  * \file PnlBrlyFltRec.h
  * job handler for job PnlBrlyFltRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFLTREC_H
#define PNLBRLYFLTREC_H

// IP custInclude --- INSERT

#include "PnlBrlyFltPre.h"
#include "PnlBrlyFltDetail.h"
#include "PnlBrlyFltFafAWaypoint.h"
#include "PnlBrlyFlt1NConnection.h"
#include "PnlBrlyFltRef1NSegment.h"
#include "PnlBrlyFltEqp1NNode.h"
#include "PnlBrlyFltMNLocation.h"
#include "PnlBrlyFltMNConnection.h"
#include "PnlBrlyFltOrgMNFlight.h"
#include "PnlBrlyFltEqpMNConnection.h"

#define VecVBrlyFltRecDo PnlBrlyFltRec::VecVDo

#define ContInfBrlyFltRec PnlBrlyFltRec::ContInf
#define StatAppBrlyFltRec PnlBrlyFltRec::StatApp
#define StatShrBrlyFltRec PnlBrlyFltRec::StatShr
#define TagBrlyFltRec PnlBrlyFltRec::Tag

#define DpchAppBrlyFltRecDo PnlBrlyFltRec::DpchAppDo
#define DpchEngBrlyFltRecData PnlBrlyFltRec::DpchEngData

/**
  * PnlBrlyFltRec
  */
class PnlBrlyFltRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyFltRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyFltRec)
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
		* StatApp (full: StatAppBrlyFltRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneFafAWaypoint = false, const bool initdone1NConnection = false, const bool initdoneRef1NSegment = false, const bool initdoneEqp1NNode = false, const bool initdoneMNLocation = false, const bool initdoneMNConnection = false, const bool initdoneOrgMNFlight = false, const bool initdoneEqpMNConnection = false);
	};

	/**
		* StatShr (full: StatShrBrlyFltRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint JREFPRE = 2;
		static const uint JREFDETAIL = 3;
		static const uint JREFFAFAWAYPOINT = 4;
		static const uint PNLFAFAWAYPOINTAVAIL = 5;
		static const uint JREF1NCONNECTION = 6;
		static const uint JREFREF1NSEGMENT = 7;
		static const uint JREFEQP1NNODE = 8;
		static const uint PNLEQP1NNODEAVAIL = 9;
		static const uint JREFMNLOCATION = 10;
		static const uint JREFMNCONNECTION = 11;
		static const uint JREFORGMNFLIGHT = 12;
		static const uint JREFEQPMNCONNECTION = 13;
		static const uint PNLEQPMNCONNECTIONAVAIL = 14;
		static const uint BUTREGULARIZEACTIVE = 15;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const ubigint jrefPre = 0, const ubigint jrefDetail = 0, const ubigint jrefFafAWaypoint = 0, const bool pnlfafawaypointAvail = false, const ubigint jref1NConnection = 0, const ubigint jrefRef1NSegment = 0, const ubigint jrefEqp1NNode = 0, const bool pnleqp1nnodeAvail = false, const ubigint jrefMNLocation = 0, const ubigint jrefMNConnection = 0, const ubigint jrefOrgMNFlight = 0, const ubigint jrefEqpMNConnection = 0, const bool pnleqpmnconnectionAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		ubigint jrefPre;
		ubigint jrefDetail;
		ubigint jrefFafAWaypoint;
		bool pnlfafawaypointAvail;
		ubigint jref1NConnection;
		ubigint jrefRef1NSegment;
		ubigint jrefEqp1NNode;
		bool pnleqp1nnodeAvail;
		ubigint jrefMNLocation;
		ubigint jrefMNConnection;
		ubigint jrefOrgMNFlight;
		ubigint jrefEqpMNConnection;
		bool pnleqpmnconnectionAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyFltRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFltRecDo)
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
		* DpchEngData (full: DpchEngBrlyFltRecData)
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

	bool evalPnlfafawaypointAvail(DbsBrly* dbsbrly);
	bool evalPnleqp1nnodeAvail(DbsBrly* dbsbrly);
	bool evalPnleqpmnconnectionAvail(DbsBrly* dbsbrly);
	bool evalButRegularizeActive(DbsBrly* dbsbrly);

public:
	PnlBrlyFltRec(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyFltRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlyFltPre* pnlpre;
	PnlBrlyFltDetail* pnldetail;
	PnlBrlyFltFafAWaypoint* pnlfafawaypoint;
	PnlBrlyFlt1NConnection* pnl1nconnection;
	PnlBrlyFltRef1NSegment* pnlref1nsegment;
	PnlBrlyFltEqp1NNode* pnleqp1nnode;
	PnlBrlyFltMNLocation* pnlmnlocation;
	PnlBrlyFltMNConnection* pnlmnconnection;
	PnlBrlyFltOrgMNFlight* pnlorgmnflight;
	PnlBrlyFltEqpMNConnection* pnleqpmnconnection;

	BrlyMFlight recFlt;

	BrlyMFaflight recFaf;

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
	bool handleCallBrlyFafUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallBrlyFltUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

