/**
  * \file PnlBrlyConRec.h
  * job handler for job PnlBrlyConRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYCONREC_H
#define PNLBRLYCONREC_H

// IP custInclude --- INSERT

#include "PnlBrlyConPre.h"
#include "PnlBrlyConDetail.h"
#include "PnlBrlyConMap.h"
#include "PnlBrlyCon1NRelay.h"
#include "PnlBrlyConRef1NSegment.h"
#include "PnlBrlyConMNSegment.h"
#include "PnlBrlyConMNFlight.h"
#include "PnlBrlyConConMNEquipment.h"

#define VecVBrlyConRecDo PnlBrlyConRec::VecVDo

#define ContInfBrlyConRec PnlBrlyConRec::ContInf
#define StatAppBrlyConRec PnlBrlyConRec::StatApp
#define StatShrBrlyConRec PnlBrlyConRec::StatShr
#define TagBrlyConRec PnlBrlyConRec::Tag

#define DpchAppBrlyConRecDo PnlBrlyConRec::DpchAppDo
#define DpchEngBrlyConRecData PnlBrlyConRec::DpchEngData

/**
  * PnlBrlyConRec
  */
class PnlBrlyConRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyConRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyConRec)
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
		* StatApp (full: StatAppBrlyConRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneMap = false, const bool initdone1NRelay = false, const bool initdoneRef1NSegment = false, const bool initdoneMNSegment = false, const bool initdoneMNFlight = false, const bool initdoneConMNEquipment = false);
	};

	/**
		* StatShr (full: StatShrBrlyConRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint JREFPRE = 2;
		static const uint JREFDETAIL = 3;
		static const uint JREFMAP = 4;
		static const uint JREF1NRELAY = 5;
		static const uint JREFREF1NSEGMENT = 6;
		static const uint JREFMNSEGMENT = 7;
		static const uint JREFMNFLIGHT = 8;
		static const uint JREFCONMNEQUIPMENT = 9;
		static const uint BUTREGULARIZEACTIVE = 10;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const ubigint jrefPre = 0, const ubigint jrefDetail = 0, const ubigint jrefMap = 0, const ubigint jref1NRelay = 0, const ubigint jrefRef1NSegment = 0, const ubigint jrefMNSegment = 0, const ubigint jrefMNFlight = 0, const ubigint jrefConMNEquipment = 0, const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		ubigint jrefPre;
		ubigint jrefDetail;
		ubigint jrefMap;
		ubigint jref1NRelay;
		ubigint jrefRef1NSegment;
		ubigint jrefMNSegment;
		ubigint jrefMNFlight;
		ubigint jrefConMNEquipment;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyConRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyConRecDo)
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
		* DpchEngData (full: DpchEngBrlyConRecData)
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
	PnlBrlyConRec(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyConRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlyConPre* pnlpre;
	PnlBrlyConDetail* pnldetail;
	PnlBrlyConMap* pnlmap;
	PnlBrlyCon1NRelay* pnl1nrelay;
	PnlBrlyConRef1NSegment* pnlref1nsegment;
	PnlBrlyConMNSegment* pnlmnsegment;
	PnlBrlyConMNFlight* pnlmnflight;
	PnlBrlyConConMNEquipment* pnlconmnequipment;

	BrlyMConnection recCon;

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

	bool handleCallBrlyConUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

