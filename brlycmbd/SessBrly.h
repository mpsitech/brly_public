/**
  * \file SessBrly.h
  * job handler for job SessBrly (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef SESSBRLY_H
#define SESSBRLY_H

// IP custInclude --- INSERT

#include "CrdBrlyNav.h"
#include "CrdBrlyUsg.h"
#include "CrdBrlyUsr.h"
#include "CrdBrlyPrs.h"
#include "CrdBrlyFil.h"
#include "CrdBrlyOpr.h"
#include "CrdBrlyPty.h"
#include "CrdBrlyReg.h"
#include "CrdBrlyLoc.h"
#include "CrdBrlyLeg.h"
#include "CrdBrlyTtb.h"
#include "CrdBrlyFlt.h"
#include "CrdBrlySeg.h"
#include "CrdBrlyCon.h"
#include "CrdBrlyRly.h"

#define StatShrSessBrly SessBrly::StatShr

#define DpchEngSessBrlyData SessBrly::DpchEngData

/**
  * SessBrly
  */
class SessBrly : public JobBrly {

public:
	/**
		* StatShr (full: StatShrSessBrly)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFCRDNAV = 1;

	public:
		StatShr(const ubigint jrefCrdnav = 0);

	public:
		ubigint jrefCrdnav;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessBrlyData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint STATSHR = 2;
		static const uint ALL = 3;

	public:
		DpchEngData(const ubigint jref = 0, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	SessBrly(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const ubigint refBrlyMUser, const string& ip);
	~SessBrly();

public:
	StatShr statshr;

	CrdBrlyNav* crdnav;
	list<CrdBrlyUsg*> crdusgs;
	list<CrdBrlyUsr*> crdusrs;
	list<CrdBrlyPrs*> crdprss;
	list<CrdBrlyFil*> crdfils;
	list<CrdBrlyOpr*> crdoprs;
	list<CrdBrlyPty*> crdptys;
	list<CrdBrlyReg*> crdregs;
	list<CrdBrlyLoc*> crdlocs;
	list<CrdBrlyLeg*> crdlegs;
	list<CrdBrlyTtb*> crdttbs;
	list<CrdBrlyFlt*> crdflts;
	list<CrdBrlySeg*> crdsegs;
	list<CrdBrlyCon*> crdcons;
	list<CrdBrlyRly*> crdrlys;

	map<ubigint, uint> usgaccs;

	map<ubigint,string> scr;
	map<string,ubigint> descr;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	uint checkCrdActive(const uint ixBrlyVCard);
	uint evalCrdsegActive();
	uint evalCrdrlyActive();

	uint checkUiaccess(const uint ixBrlyVCard);
	uint getIxUac(DbsBrly* dbsbrly, const uint ixBrlyVCard, const bool adm, ListBrlyRMUserMUsergroup& urus, const ubigint refBrlyMUser);

	uint checkAccess(DbsBrly* dbsbrly, const uint ixBrlyVCard, const ubigint ref);
	void logAccess(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint preUref, const uint ixBrlyVCard, const ubigint unvUref);

	uint crdToMtb(const uint ixBrlyVCard);
	uint preToMtb(const uint ixBrlyVPreset);
	bool hasActive(const uint ixBrlyVCard);
	bool hasGrpown(const uint ixBrlyVMaintable);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleCreateCrdcon(DbsBrly* dbsbrly);
	bool handleCreateCrdfil(DbsBrly* dbsbrly);
	bool handleCreateCrdflt(DbsBrly* dbsbrly);
	bool handleCreateCrdleg(DbsBrly* dbsbrly);
	bool handleCreateCrdloc(DbsBrly* dbsbrly);
	bool handleCreateCrdopr(DbsBrly* dbsbrly);
	bool handleCreateCrdprs(DbsBrly* dbsbrly);
	bool handleCreateCrdpty(DbsBrly* dbsbrly);
	bool handleCreateCrdreg(DbsBrly* dbsbrly);
	bool handleCreateCrdrly(DbsBrly* dbsbrly);
	bool handleCreateCrdseg(DbsBrly* dbsbrly);
	bool handleCreateCrdttb(DbsBrly* dbsbrly);
	bool handleCreateCrdusg(DbsBrly* dbsbrly);
	bool handleCreateCrdusr(DbsBrly* dbsbrly);
	bool handleEraseCrdcon(DbsBrly* dbsbrly);
	bool handleEraseCrdfil(DbsBrly* dbsbrly);
	bool handleEraseCrdflt(DbsBrly* dbsbrly);
	bool handleEraseCrdleg(DbsBrly* dbsbrly);
	bool handleEraseCrdloc(DbsBrly* dbsbrly);
	bool handleEraseCrdopr(DbsBrly* dbsbrly);
	bool handleEraseCrdprs(DbsBrly* dbsbrly);
	bool handleEraseCrdpty(DbsBrly* dbsbrly);
	bool handleEraseCrdreg(DbsBrly* dbsbrly);
	bool handleEraseCrdrly(DbsBrly* dbsbrly);
	bool handleEraseCrdseg(DbsBrly* dbsbrly);
	bool handleEraseCrdttb(DbsBrly* dbsbrly);
	bool handleEraseCrdusg(DbsBrly* dbsbrly);
	bool handleEraseCrdusr(DbsBrly* dbsbrly);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyAccess(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, uint& ixRet);
	bool handleCallBrlyCrdActive(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, uint& ixRet);
	bool handleCallBrlyCrdClose(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv);
	bool handleCallBrlyCrdOpen(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv, ubigint& refRet);
	bool handleCallBrlyDescr(DbsBrly* dbsbrly, const ubigint jrefTrig, const string& srefInv, ubigint& refRet);
	bool handleCallBrlyLog(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv);
	bool handleCallBrlyScr(DbsBrly* dbsbrly, const ubigint jrefTrig, const ubigint refInv, string& srefRet);
	bool handleCallBrlyRefPreSet(DbsBrly* dbsbrly, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif

