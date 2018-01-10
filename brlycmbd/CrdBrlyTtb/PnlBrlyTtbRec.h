/**
  * \file PnlBrlyTtbRec.h
  * job handler for job PnlBrlyTtbRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYTTBREC_H
#define PNLBRLYTTBREC_H

// IP custInclude --- INSERT

#include "PnlBrlyTtbDetail.h"
#include "PnlBrlyTtb1NFlight.h"
#include "PnlBrlyTtbRef1NFile.h"

#define VecVBrlyTtbRecDo PnlBrlyTtbRec::VecVDo

#define ContInfBrlyTtbRec PnlBrlyTtbRec::ContInf
#define StatAppBrlyTtbRec PnlBrlyTtbRec::StatApp
#define StatShrBrlyTtbRec PnlBrlyTtbRec::StatShr
#define TagBrlyTtbRec PnlBrlyTtbRec::Tag

#define DpchAppBrlyTtbRecDo PnlBrlyTtbRec::DpchAppDo
#define DpchEngBrlyTtbRecData PnlBrlyTtbRec::DpchEngData

/**
  * PnlBrlyTtbRec
  */
class PnlBrlyTtbRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyTtbRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyTtbRec)
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
		* StatApp (full: StatAppBrlyTtbRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdone1NFlight = false, const bool initdoneRef1NFile = false);
	};

	/**
		* StatShr (full: StatShrBrlyTtbRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREF1NFLIGHT = 3;
		static const uint JREFREF1NFILE = 4;
		static const uint BUTREGULARIZEACTIVE = 5;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jref1NFlight = 0, const ubigint jrefRef1NFile = 0, const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		ubigint jrefDetail;
		ubigint jref1NFlight;
		ubigint jrefRef1NFile;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyTtbRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyTtbRecDo)
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
		* DpchEngData (full: DpchEngBrlyTtbRecData)
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
	PnlBrlyTtbRec(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyTtbRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlyTtbDetail* pnldetail;
	PnlBrlyTtb1NFlight* pnl1nflight;
	PnlBrlyTtbRef1NFile* pnlref1nfile;

	BrlyMTimetable recTtb;

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

	bool handleCallBrlyTtbUpd_refEq(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv);
};

#endif

