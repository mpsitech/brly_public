/**
  * \file PnlBrlySegRec.h
  * job handler for job PnlBrlySegRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYSEGREC_H
#define PNLBRLYSEGREC_H

// IP custInclude --- INSERT

#include "PnlBrlySegPre.h"
#include "PnlBrlySegDetail.h"
#include "PnlBrlySegMNConnection.h"
#include "PnlBrlySegMNLocation.h"
#include "PnlBrlySegOrgMNSegment.h"

#define VecVBrlySegRecDo PnlBrlySegRec::VecVDo

#define ContInfBrlySegRec PnlBrlySegRec::ContInf
#define StatAppBrlySegRec PnlBrlySegRec::StatApp
#define StatShrBrlySegRec PnlBrlySegRec::StatShr
#define TagBrlySegRec PnlBrlySegRec::Tag

#define DpchAppBrlySegRecDo PnlBrlySegRec::DpchAppDo
#define DpchEngBrlySegRecData PnlBrlySegRec::DpchEngData

/**
  * PnlBrlySegRec
  */
class PnlBrlySegRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlySegRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlySegRec)
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
		* StatApp (full: StatAppBrlySegRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneMNConnection = false, const bool initdoneMNLocation = false, const bool initdoneOrgMNSegment = false);
	};

	/**
		* StatShr (full: StatShrBrlySegRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint JREFPRE = 2;
		static const uint JREFDETAIL = 3;
		static const uint JREFMNCONNECTION = 4;
		static const uint JREFMNLOCATION = 5;
		static const uint JREFORGMNSEGMENT = 6;
		static const uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const ubigint jrefPre = 0, const ubigint jrefDetail = 0, const ubigint jrefMNConnection = 0, const ubigint jrefMNLocation = 0, const ubigint jrefOrgMNSegment = 0, const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		ubigint jrefPre;
		ubigint jrefDetail;
		ubigint jrefMNConnection;
		ubigint jrefMNLocation;
		ubigint jrefOrgMNSegment;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlySegRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlySegRecDo)
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
		* DpchEngData (full: DpchEngBrlySegRecData)
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

	bool evalButRegularizeActive(DbsBrly* dbsbrly);

public:
	PnlBrlySegRec(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlySegRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlySegPre* pnlpre;
	PnlBrlySegDetail* pnldetail;
	PnlBrlySegMNConnection* pnlmnconnection;
	PnlBrlySegMNLocation* pnlmnlocation;
	PnlBrlySegOrgMNSegment* pnlorgmnsegment;

	BrlyMSegment recSeg;

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

	bool handleCallBrlySegUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

