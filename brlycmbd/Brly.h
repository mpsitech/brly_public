/**
  * \file Brly.h
  * Brly global functionality (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLY_H
#define BRLY_H

#define BRLY_VERSION "0.2.2"
#define BRLY_VERSION_MAJOR 0
#define BRLY_VERSION_MINOR 2
#define BRLY_VERSION_SUB 2

// IP incl --- IBEGIN
#include <netcdf.h>
// IP incl --- IEND

#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#include "VecBrlyVCall.h"
#include "VecBrlyVDpch.h"
#include "VecBrlyVExpstate.h"
#include "VecBrlyVIop.h"
#include "VecBrlyVJob.h"
#include "VecBrlyVLop.h"
#include "VecBrlyVMimetype.h"
#include "VecBrlyVOpengtype.h"
#include "VecBrlyVOppack.h"
#include "VecBrlyVQrystate.h"
#include "VecBrlyVReqitmode.h"
#include "VecBrlyVStub.h"
#include "VecBrlyVTag.h"

#include <DbsBrly.h>

#include <sbecore/Stub.h>

/**
  * Acv
  */
namespace Acv {
	ubigint addfile(DbsBrly* dbsbrly, const string& acvpath, const string& path, const uint refIxVTbl, const ubigint refUref, const string& osrefKContent, const string& Filename, const string& srefKMimetype, const string& Comment);
	void alterfile(DbsBrly* dbsbrly, const string& acvpath, const string& path, const ubigint ref);
	string getfile(DbsBrly* dbsbrly, const ubigint refBrlyMFile);
};

/**
  * Lop
  */
namespace Lop {
	void apply(const uint ixBrlyVLop, vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);

	void insert(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
	void remove(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
};

/**
  * Oolop
  */
namespace Oolop {
	void apply(const uint ixBrlyVOolop, vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);

	void insertBefore(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);
	void insertAfter(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);
	void remove(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
	void toBefore(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
	void toAfter(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
	void swap(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
};

/**
  * Tmp
  */
namespace Tmp {
	string newfile(const string& tmppath, const string& ext);
	string newfolder(const string& tmppath);
	string random();
};

// IP cust --- IBEGIN
/**
  * Cdf
  */
namespace Cdf {
	void putBoolVec(const int ncid, const int varid, const vector<bool>& vec);
	void putUintVec(const int ncid, const int varid, const vector<uint>& vec);
	void putUbigintVec(const int ncid, const int varid, const vector<ubigint>& vec);
	void putDoubleVec(const int ncid, const int varid, const vector<double>& vec);

	bool getGroup(const int ncid, const string& path, int& pathid);

	bool getBoolVec(const int ncid, const string& path, const string& varsref, vector<bool>& vec);
	bool getUintVec(const int ncid, const string& path, const string& varsref, vector<uint>& vec);
	bool getUbigintVec(const int ncid, const string& path, const string& varsref, vector<ubigint>& vec);
	bool getDoubleVec(const int ncid, const string& path, const string& varsref, vector<double>& vec);

	bool getDoubleVecSlc(const int ncid, const string& path, const string& varsref, const vector<string>& slcDims, const vector<int>& slcIcs, const unsigned int Ntarget, vector<double>& vec);

	bool getUint(const int ncid, const string& path, const string& varsref, uint& val);
	bool getDouble(const int ncid, const string& path, const string& varsref, double& val);

	bool getDim(const int ncid, const string& path, const string& dimsref, int& dimid, unsigned int& dim);

	bool getAttr(const int ncid, const string& path, const string& varsref, const string& attrsref, string& attr);
};

/**
  * Rlychunk
  */
class Rlychunk {

public:
	unsigned int start;
	unsigned int stop;

	ubigint refRlyBwd;
	ubigint refRlyFwd;

	bool bwd;

	bool ctdBwd;
	bool ctdFwd;

	unsigned int Nhop;

public:
	Rlychunk();
	Rlychunk(BrlyMRelay* rly);

	void dump();
};

/**
  * Rlystat
  */
class Rlystat {

public:
	unsigned int start;
	unsigned int stop;

	ListBrlyMRelay rlys;
	list<Rlychunk> listRly;

	double pCtdBwd;
	double pCtdFwd;

	double avgNhopBwd;
	double avgNhopFwd;

	double pCtd;
	double pCtdBoth;

	double avgNhop;

	list<Rlychunk>::iterator itLast;

public:
	Rlystat(DbsBrly* dbsbrly, BrlyMConnection* con);

	void boilDown();
	void statsBwdFwd();
	void statsCombined();

	bool getCtd(const unsigned int t);
};

/**
  * Bgmode
  */
namespace Bgmode {
	const unsigned int CTDBWD = 1;
	const unsigned int CTDFWD = 2;
	const unsigned int CTDBOTH = 3;
	const unsigned int NCTD = 4;
	const unsigned int ALONE = 5;
};
// IP cust --- IEND

/**
  * Brly
  */
namespace Brly {
	// IP gbl --- IBEGIN
	void loadLegsByArena(DbsBrly* dbsbrly, const string arena, const bool go, const bool back, const bool corr, vector<ubigint>& refsLeg1, vector<ubigint>& refsLeg2);
	bool isInArena(const vector<ubigint>& refsLeg, const ubigint refLeg);

	void initEqplineup(DbsBrly* dbsbrly, const ubigint refBrlyMConnection,	list<ubigint>& lineup, ListBrlyORMConnectionMEquipment& ops);
	ubigint advanceEqplineup(list<ubigint>& lineup, ListBrlyORMConnectionMEquipment& ops, ubigint opix, uint t);
	// IP gbl --- IEND
};

/**
  * OpengBrly
  */
namespace OpengBrly {
	void getIcsBrlyVOppackByIxBrlyVOpengtype(const uint ixBrlyVOpengtype, vector<uint>& icsBrlyVOppack);
	void getIcsBrlyVDpchByIxBrlyVOppack(const uint ixBrlyVOppack, set<uint>& icsBrlyVDpch);
};

/**
  * StubBrly
  */
namespace StubBrly {
	string getStub(DbsBrly* dbsbrly, const uint ixBrlyVStub, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);

	string getStubConStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubEqpShort(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubEqpStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubFafStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubFilStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubFltSref(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubFltStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubGrp(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubLegShort(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubLegStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubLocSref(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubLocStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubLocTitle(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubNdeLong(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubNdeStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubOprSref(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubOprStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubOwn(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubPrsStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubPtySref(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubPtyStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubRegHsref(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubRegLong(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubRegStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubRlyLong(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubRlyStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubSegStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubSesMenu(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubSesStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubTtbStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubTtbTitle(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubUsgStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubUsrStd(DbsBrly* dbsbrly, const ubigint ref, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
};

/**
  * BrlyException
  */
struct BrlyException {
	string err;

	BrlyException(string err) {
		this->err = err;
	};
};

/**
	* ContInfBrlyAlert
	*/
class ContInfBrlyAlert : public Block {

public:
	static const uint TXTCPT = 1;
	static const uint TXTMSG1 = 2;
	static const uint TXTMSG2 = 3;
	static const uint TXTMSG3 = 4;
	static const uint TXTMSG4 = 5;
	static const uint TXTMSG5 = 6;
	static const uint TXTMSG6 = 7;
	static const uint TXTMSG7 = 8;
	static const uint TXTMSG8 = 9;
	static const uint TXTMSG9 = 10;
	static const uint TXTMSG10 = 11;
	static const uint TXTMSG11 = 12;
	static const uint TXTMSG12 = 13;

public:
	ContInfBrlyAlert(const string& TxtCpt = "", const string& TxtMsg1 = "", const string& TxtMsg2 = "", const string& TxtMsg3 = "", const string& TxtMsg4 = "", const string& TxtMsg5 = "", const string& TxtMsg6 = "", const string& TxtMsg7 = "", const string& TxtMsg8 = "", const string& TxtMsg9 = "", const string& TxtMsg10 = "", const string& TxtMsg11 = "", const string& TxtMsg12 = "");

public:
	string TxtCpt;
	string TxtMsg1;
	string TxtMsg2;
	string TxtMsg3;
	string TxtMsg4;
	string TxtMsg5;
	string TxtMsg6;
	string TxtMsg7;
	string TxtMsg8;
	string TxtMsg9;
	string TxtMsg10;
	string TxtMsg11;
	string TxtMsg12;

public:
	static bool all(const set<uint>& items);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> compare(const ContInfBrlyAlert* comp);
};

/**
  * DpchBrly
  */
class DpchBrly : public Block {

public:
	DpchBrly(const uint ixBrlyVDpch = 0);
	virtual ~DpchBrly();

public:
	uint ixBrlyVDpch;
};

/**
  * DpchInvBrly
  */
class DpchInvBrly : public DpchBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ALL = 3;

public:
	DpchInvBrly(const uint ixBrlyVDpch = VecBrlyVDpch::DPCHINVBRLY, const ubigint oref = 0, const ubigint jref = 0, const set<uint>& mask = {ALL});
	virtual ~DpchInvBrly();

public:
	string scrOref;
	ubigint oref;
	string scrJref;
	ubigint jref;

public:
	static bool all(const set<uint>& items);

	virtual void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	virtual void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetBrly
  */
class DpchRetBrly : public DpchBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint ALL = 4;

public:
	DpchRetBrly(const uint ixBrlyVDpch = VecBrlyVDpch::DPCHRETBRLY, const string& scrOref = "", const string& scrJref = "", const bool success = false, const set<uint>& mask = {ALL});
	virtual ~DpchRetBrly();

public:
	string scrOref;
	ubigint oref;
	string scrJref;
	ubigint jref;
	bool success;

public:
	static bool all(const set<uint>& items);

	virtual void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

#endif


