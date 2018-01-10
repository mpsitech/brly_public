/**
  * \file Brlyd.h
  * inter-thread exchange object for Brly daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYD_H
#define BRLYD_H

#ifdef __CYGWIN__
	#include <sys/select.h>
#endif

#include <unistd.h>

#ifndef _WIN32
	#include <sys/socket.h>
#endif
#ifdef _WIN32
	#include <windows.h>
	#include <winsock.h>
	typedef int socklen_t;
#endif

#include <sys/stat.h>

#include <microhttpd.h>

#include <curl/curl.h>

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>
#include <sbecore/DbsMon.h>

#include "Brly.h"

#include "SqkBrlyBase.h"
#include "SqkBrlyDnsmap.h"
#include "SqkBrlyDyn.h"
#include "SqkBrlyMapgen.h"
#include "SqkBrlyTtimp.h"

// IP incl --- INSERT

class XchgBrlyd;
typedef XchgBrlyd XchgBrly;

/**
  * DpchBrlydAck (written by dOpengconsrv, identified by opd_exe)
  */
namespace DpchBrlydAck {
	void writeXML(xmlTextWriter* wr);
};

/**
  * DpchBrlydQuit (written by d_exe, identified by opdEngsrv)
  */
namespace DpchBrlydQuit {
	void writeXML(xmlTextWriter* wr);
};

/**
  * DpchBrlydReg (written by dOpengconsrv, read by opd_exe)
  */
namespace DpchBrlydReg {
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, const ubigint nref = 0);
};

/**
  * DpchBrlyopdReg (written by opd_exe, read by dOpengconsrv)
  */
class DpchBrlyopdReg : public DpchBrly {

public:
	static const uint PORT = 1;
	static const uint IXBRLYVOPENGTYPE = 2;
	static const uint OPPRCN = 3;

public:
	DpchBrlyopdReg();

public:
	usmallint port;
	uint ixBrlyVOpengtype;
	usmallint opprcn;

public:
	static bool all(const set<uint>& items);

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchBrlyopdUnreg (written by opd_exe, read by dOpengconsrv)
  */
class DpchBrlyopdUnreg : public DpchBrly {

public:
	static const uint NREF = 1;

public:
	DpchBrlyopdUnreg();

public:
	ubigint nref;

public:
	static bool all(const set<uint>& items);

	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppBrly
	*/
class DpchAppBrly : public DpchBrly {

public:
	static const uint JREF = 1;

public:
	DpchAppBrly(const uint ixBrlyVDpch = 0);
	virtual ~DpchAppBrly();

public:
	ubigint jref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();

	virtual void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchAppBrlyAlert
  */
class DpchAppBrlyAlert : public DpchAppBrly {

public:
	static const uint JREF = 1;
	static const uint NUMFMCB = 2;

public:
	DpchAppBrlyAlert();

public:
	uint numFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchAppBrlyInit
  */
class DpchAppBrlyInit : public DpchAppBrly {

public:
	DpchAppBrlyInit();
};

/**
  * DpchAppBrlyResume
  */
class DpchAppBrlyResume : public DpchAppBrly {

public:
	DpchAppBrlyResume();
};

/**
	* DpchEngBrly
	*/
class DpchEngBrly : public DpchBrly {

public:
	static const uint JREF = 1;

public:
	DpchEngBrly(const uint ixBrlyVDpch = 0, const ubigint jref = 0);
	virtual ~DpchEngBrly();

public:
	ubigint jref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();
	virtual void merge(DpchEngBrly* dpcheng);

	virtual void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
  * DpchEngBrlyAck
  */
class DpchEngBrlyAck : public DpchEngBrly {

public:
	DpchEngBrlyAck(const ubigint jref = 0);
};

/**
  * DpchEngBrlyAlert
  */
class DpchEngBrlyAlert : public DpchEngBrly {

public:
	static const uint JREF = 1;
	static const uint CONTINF = 2;
	static const uint FEEDFMCB = 3;
	static const uint ALL = 4;

public:
	DpchEngBrlyAlert(const ubigint jref = 0, ContInfBrlyAlert* continf = NULL, Feed* feedFMcb = NULL, const set<uint>& mask = {NONE});

public:
	ContInfBrlyAlert continf;
	Feed feedFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();
	void merge(DpchEngBrly* dpcheng);

	void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
  * DpchEngBrlyConfirm
  */
class DpchEngBrlyConfirm : public DpchEngBrly {

public:
	static const uint ACCEPTED = 1;
	static const uint JREF = 2;
	static const uint SREF = 3;
	static const uint ALL = 4;

public:
	DpchEngBrlyConfirm(const bool accepted = false, const ubigint jref = 0, const string& sref = "", const set<uint>& mask = {ALL});

public:
	bool accepted;
	string sref;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();
	void merge(DpchEngBrly* dpcheng);

	void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
  * DpchEngBrlySuspend
  */
class DpchEngBrlySuspend : public DpchEngBrly {

public:
	DpchEngBrlySuspend(const ubigint jref = 0);
};

/**
	* StgBrlyd
	*/
class StgBrlyd : public Block {

public:
	static const uint JOBPRCN = 1;
	static const uint OPENGSRVPORT = 2;
	static const uint APPSRVPORT = 3;
	static const uint HTTPS = 4;
	static const uint HISTLENGTH = 5;

public:
	StgBrlyd(const usmallint jobprcn = 1, const usmallint opengsrvport = 0, const usmallint appsrvport = 0, const bool https = false, const usmallint histlength = 20);

public:
	usmallint jobprcn;
	usmallint opengsrvport;
	usmallint appsrvport;
	bool https;
	usmallint histlength;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgBrlyd* comp);
	set<uint> diff(const StgBrlyd* comp);
};

/**
	* StgBrlyDatabase
	*/
class StgBrlyDatabase : public Block {

public:
	static const uint IXDBSVDBSTYPE = 1;
	static const uint DBSPATH = 2;
	static const uint DBSNAME = 3;
	static const uint USERNAME = 4;
	static const uint PASSWORD = 5;
	static const uint IP = 6;
	static const uint PORT = 7;

public:
	StgBrlyDatabase(const uint ixDbsVDbstype = 0, const string& dbspath = "", const string& dbsname = "", const string& username = "mpsitech", const string& password = "f9w8feeh", const string& ip = "", const usmallint port = 0);

public:
	uint ixDbsVDbstype;
	string dbspath;
	string dbsname;
	string username;
	string password;
	string ip;
	usmallint port;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgBrlyDatabase* comp);
	set<uint> diff(const StgBrlyDatabase* comp);
};

/**
	* StgBrlyFlightaware
	*/
class StgBrlyFlightaware : public Block {

public:
	static const uint IP = 1;
	static const uint KEY = 2;

public:
	StgBrlyFlightaware(const string& ip = "flightxml.flightaware.com/json/FlightXML2", const string& key = "YXdpcnRobToyMjY5NzU4ZmI0NGIxODQxNjBlZTk2NWU4ZTAyZjk3OTZkZTJmMzE0");

public:
	string ip;
	string key;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgBrlyFlightaware* comp);
	set<uint> diff(const StgBrlyFlightaware* comp);
};

/**
	* StgBrlyGeometry
	*/
class StgBrlyGeometry : public Block {

public:
	static const uint ACRALTITUDE = 1;
	static const uint CORRWIDTH1 = 2;
	static const uint CORRWIDTH2 = 3;
	static const uint EARTHRADIUS = 4;
	static const uint HRZNALTITUDE = 5;

public:
	StgBrlyGeometry(const double acraltitude = 10500, const double corrwidth1 = 100000, const double corrwidth2 = 500000, const double earthradius = 6371000, const double hrznaltitude = 2000);

public:
	double acraltitude;
	double corrwidth1;
	double corrwidth2;
	double earthradius;
	double hrznaltitude;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgBrlyGeometry* comp);
	set<uint> diff(const StgBrlyGeometry* comp);
};

/**
	* StgBrlyMonitor
	*/
class StgBrlyMonitor : public Block {

public:
	static const uint USERNAME = 1;
	static const uint PASSWORD = 2;
	static const uint IP = 3;
	static const uint PORT = 4;
	static const uint IXDBSVDBSTYPE = 5;
	static const uint DBSPATH = 6;
	static const uint DBSNAME = 7;
	static const uint DBSUSERNAME = 8;
	static const uint DBSPASSWORD = 9;

public:
	StgBrlyMonitor(const string& username = "", const string& password = "", const string& ip = "", const usmallint port = 0, const uint ixDbsVDbstype = 0, const string& dbspath = "", const string& dbsname = "", const string& dbsusername = "", const string& dbspassword = "");

public:
	string username;
	string password;
	string ip;
	usmallint port;
	uint ixDbsVDbstype;
	string dbspath;
	string dbsname;
	string dbsusername;
	string dbspassword;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgBrlyMonitor* comp);
	set<uint> diff(const StgBrlyMonitor* comp);
};

/**
	* StgBrlyPath
	*/
class StgBrlyPath : public Block {

public:
	static const uint ACVPATH = 1;
	static const uint KEYPATH = 2;
	static const uint MONPATH = 3;
	static const uint TMPPATH = 4;
	static const uint WEBPATH = 5;
	static const uint HELPURL = 6;

public:
	StgBrlyPath(const string& acvpath = "", const string& keypath = "", const string& monpath = "", const string& tmppath = "", const string& webpath = "", const string& helpurl = "");

public:
	string acvpath;
	string keypath;
	string monpath;
	string tmppath;
	string webpath;
	string helpurl;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgBrlyPath* comp);
	set<uint> diff(const StgBrlyPath* comp);
};

/**
  * AlrBrly
  */
namespace AlrBrly {
	DpchEngBrlyAlert* prepareAlrAbt(const ubigint jref, const uint ixBrlyVLocale, Feed& feedFMcbAlert);
	DpchEngBrlyAlert* prepareAlrPer(const ubigint jref, const uint ixBrlyVLocale, const string& lineno, Feed& feedFMcbAlert);
	DpchEngBrlyAlert* prepareAlrSav(const ubigint jref, const uint ixBrlyVLocale, Feed& feedFMcbAlert);
};

/**
  * ReqBrly
  */
class ReqBrly {

public:
	/**
		* VecVBasetype
		*/
	class VecVBasetype {

	public:
		static const uint NONE = 0; // invalid
		static const uint WEB = 1; // web-client triggered ui file request (GET)
		static const uint CMD = 2; // command-line request
		static const uint REGULAR = 3; // web-client triggered Dpch request (POST+Dpch)
		static const uint NOTIFY = 4; // web-client triggered notify-on-Dpch request (POST/empty)
		static const uint POLL = 5; // web-client triggered Dpch poll request (POST/empty)
		static const uint UPLOAD = 6; // web-client triggered file upload request (POST)
		static const uint DOWNLOAD = 7; // web-client triggered file download request (GET)
		static const uint RET = 8; // op-engine or opprc triggered op return (DpchRet)
		static const uint TIMER = 9; // timer triggered request
		static const uint EXTCALL = 10; // externally triggered call request
	};

	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const uint NONE = 0; // invalid
		static const uint RECEIVE = 1; // during data reception - appsrv internal
		static const uint WAITPRC = 2; // before caught by job processor that is idle - in reqs list
		static const uint PRC = 3; // while being processesd by job processor - still in reqs list ; appsrv thread waiting on cReply
		static const uint REPLY = 4; // while reply being transmitted by appsrv - appsrv internal
	};

public:
	ReqBrly(const uint ixVBasetype = VecVBasetype::NONE, const uint ixVState = VecVState::RECEIVE, const string& ip = "");
	~ReqBrly();

public:
	uint ixVBasetype;
	uint ixVState;

	// specific data for base type CMD
	string cmd;

	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD, DOWNLOAD
	string ip;

	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD
	MHD_PostProcessor* pp;

	// specific data for base types CMD, REGULAR, NOTIFY, UPLOAD, DOWNLOAD
	bool retain;
	pthread_mutex_t mcReady; // also protects compare/set of ixVState to REPLY
	pthread_cond_t cReady;

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	string filename; // full path
	fstream* file;
	size_t filelen;

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	char* request;
	size_t requestlen;

	// specific data for base types CMD, REGULAR, NOTIFY, POLL, UPLOAD, DOWNLOAD, RET, TIMER
	ubigint jref;

	// specific data for base type TIMER
	ubigint wref;
	string sref;

	// specific data for base type EXTCALL
	Call* call;

	// specific data for base types CMD, REGULAR, UPLOAD, DOWNLOAD, RET, TIMER
	bool weak;

	// specific data for base type REGULAR
	DpchAppBrly* dpchapp;

	// specific data for base types REGULAR, NOTIFY, POLL
	DpchEngBrly* dpcheng;
	uint ixBrlyVLocale;

	// specific data for base type RET
	DpchInvBrly* dpchinv;
	DpchRetBrly* dpchret;

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	char* reply;
	size_t replylen;

public:
	void setStateReply();
};

/**
  * ReqopengconBrly
  */
class ReqopengconBrly {

public:
	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const uint RECEIVE = 0; // during data reception - opengconsrv internal
		static const uint REPLY = 1; // while reply being transmitted by opengconsrv - opengconsrv internal
	};

public:
	ReqopengconBrly(const uint ixVState = VecVState::RECEIVE, const string& ip = "");
	~ReqopengconBrly();

public:
	uint ixVState;
	string ip;

	MHD_PostProcessor* pp;

	char* request;
	size_t requestlen;

	DpchBrly* dpchopd;

	char* reply;
	size_t replylen;
};

/**
	* DcolBrly
	*/
class DcolBrly {

public:
	DcolBrly(const ubigint jref = 0, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS);
	~DcolBrly();

public:
	ubigint jref;

	uint ixBrlyVLocale;

	pthread_mutex_t mAccess;

	bool hot;

	list<DpchEngBrly*> dpchs;

	ReqBrly* req;

public:
	int lockAccess(const string& srefObject = "", const string& srefMember = "");
	int unlockAccess(const string& srefObject = "", const string& srefMember = "");
};

/**
  * JobBrly
  */
class JobBrly {

public:
	JobBrly(XchgBrly* xchg, const uint ixBrlyVJob = 0, const ubigint jrefSup = 0, const uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const bool prefmast = false);
	virtual ~JobBrly();

public:
	XchgBrly* xchg;

	ubigint jref;

	uint ixBrlyVJob;

	ubigint jrefSup;
	set<ubigint> jrefsSub;

	uint ixBrlyVLocale;

	ubigint jrefMast;
	list<ubigint> jrefsSlv;

	bool prefmast;

	pthread_mutex_t mAccess;

	bool muteRefresh;

	uint ixVSge;
	uint nextIxVSge;

	uint opNdone;
	uint opN;

	vector<DpchInvBrly*> invs;

	pthread_mutex_t mOps;
	list<Op*> ops;
	string opsqkLast;

	ubigint wrefLast;
	ubigint wrefMin;

	ReqBrly* reqCmd;

public:
	virtual DpchEngBrly* getNewDpchEng(set<uint> items);

	virtual void refresh(DbsBrly* dbsbrly, set<uint>& moditems);
	void refreshWithDpchEng(DbsBrly* dbsbrly, DpchEngBrly** dpcheng = NULL);

	virtual string getSquawk(DbsBrly* dbsbrly);

	virtual void giveupMaster(DbsBrly* dbsbrly);
	virtual void giveupSlave(DbsBrly* dbsbrly);
	virtual void becomeMaster(DbsBrly* dbsbrly);
	virtual void becomeSlave(DbsBrly* dbsbrly);

	virtual bool handleClaimMaster(DbsBrly* dbsbrly);
	virtual void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);
	virtual void handleCall(DbsBrly* dbsbrly, Call* call);

	int lockAccess(const string& srefObject, const string& srefMember);
	int trylockAccess(const string& srefObject, const string& srefMember);
	int unlockAccess(const string& srefObject, const string& srefMember);
	int lockAccess(const string& srefMember);
	int unlockAccess(const string& srefMember);

	void clearInvs();
	ubigint addInv(DpchInvBrly* inv);
	void addInvs(vector<DpchInvBrly*>& _invs);
	void submitInvs(DbsBrly* dbsbrly, const uint emptyIxVSge, uint& _ixVSge);

	void clearOps();
	void addOp(DbsBrly* dbsbrly, DpchInvBrly* inv);
	void removeOp(const ubigint oref);
	string getOpsqkLast();

	void callback(const uint _nextIxVSge);
	void invalidateWakeups();
};

/**
  * StmgrBrly
  */
class StmgrBrly {

public:
	StmgrBrly(XchgBrly* xchg, const ubigint jref, const uint ixVNonetype);
	~StmgrBrly();

public:
	XchgBrly* xchg;

	ubigint jref;
	uint ixVNonetype;

	Stcch* stcch;

	pthread_mutex_t mAccess;

public:
	void handleCall(DbsBrly* dbsbrly, Call* call);
	bool refresh(DbsBrly* dbsbrly, Stcchitem* stit);

	void begin();
	void commit();

	int lockAccess(const string& srefObject = "", const string& srefMember = "");
	int unlockAccess(const string& srefObject = "", const string& srefMember = "");
};

/**
  * WakeupBrly
  */
class WakeupBrly {

public:
	WakeupBrly(XchgBrly* xchg, const ubigint wref, const ubigint jref, const string sref, const unsigned int deltat = 0, const bool weak = false);

public:
	XchgBrly* xchg;

	ubigint wref;

	ubigint jref;
	string sref;
	unsigned int deltat;
	bool weak;
};

/**
  * ExtcallBrly
  */
class ExtcallBrly {

public:
	ExtcallBrly(XchgBrly* xchg, Call* call);

public:
	XchgBrly* xchg;
	Call* call;
};

/**
  * ConopengBrly
  */
class ConopengBrly {

public:
	ConopengBrly(const string& ip = "", const uint port = 0);
	~ConopengBrly();

public:
	CURL* curl;

	bool busy;
};

/**
  * NodeBrly
  */
class NodeBrly {

public:
	NodeBrly(const ubigint nref, const string& ip, const uint port, const uint opprcn, const uint ixBrlyVOpengtype);
	~NodeBrly();

public:
	ubigint nref;

	string ip;
	uint port;
	uint opprcn;
	uint ixBrlyVOpengtype;

	set<uint> icsBrlyVDpch;

	uint opprcbusy;

	bool err;

	pthread_mutex_t mCons;
	vector<ConopengBrly*> cons;

public:
	ConopengBrly* getCon();
};

/**
  * XchgdataBrlyJobprc
  */
class XchgdataBrlyJobprc {

public:
	// IP datajobprc.subs --- INSERT

public:
	XchgdataBrlyJobprc();

public:
	// IP datajobprc --- INSERT
};

/**
  * XchgBrlyd
  */
class XchgBrlyd {

public:
	XchgBrlyd();
	~XchgBrlyd();

public:
	StgBrlyd stgbrlyd;
	StgBrlyDatabase stgbrlydatabase;
	StgBrlyFlightaware stgbrlyflightaware;
	StgBrlyGeometry stgbrlygeometry;
	StgBrlyMonitor stgbrlymonitor;
	StgBrlyPath stgbrlypath;

	XchgdataBrlyJobprc datajobprc;

public:
	// IP cust --- INSERT

public:
	// executable/archive/temporary folder paths and help URL
	string exedir;
	string acvpath;
	string tmppath;
	string helpurl;

	// root job
	ubigint jrefRoot;

	// job receiving commands
	ubigint jrefCmd;

	// scrambled ref codes
	pthread_mutex_t mScr;
	map<ubigint,string> scr;
	map<string,ubigint> descr;

	// monitor object
	DbsMon mon;

	// log file
	pthread_mutex_t mLogfile;

	// condition for op engine client
	pthread_mutex_t mcOpengcli;
	pthread_cond_t cOpengcli;

	// condition for job processors
	pthread_mutex_t mcJobprcs;
	pthread_cond_t cJobprcs;

	// request list
	pthread_mutex_t mReqs;
	list<ReqBrly*> reqs;

	// operation invocation list
	Refseq* orefseq;
	pthread_mutex_t mInvs;
	list<DpchInvBrly*> invs;

	// presetting list
	pthread_mutex_t mPresets;
	multimap<presetref_t,Preset*> presets;

	// stub manager list
	pthread_mutex_t mStmgrs;
	map<ubigint,StmgrBrly*> stmgrs;

	// sequence for call listener references
	pthread_mutex_t mCrefseq;
	ubigint crefseq;

	// call listener list
	pthread_mutex_t mClstns;
	multimap<clstnref_t,Clstn*> clstns;
	multimap<clstnref2_t,clstnref_t> cref2sClstns;

	// dispatch collector list
	pthread_mutex_t mDcols;
	map<ubigint,DcolBrly*> dcols;

	// job list
	Refseq* jrefseq;
	pthread_mutex_t mJobs;
	map<ubigint,JobBrly*> jobs;

	// sequence for wakeup references
	Refseq* wrefseq;

	// node list
	Refseq* nrefseq;
	pthread_mutex_t mNodes;
	map<ubigint,NodeBrly*> nodes;

	char* curlrecv;
	size_t curlrecvlen;

public:
	// monitor object methods
	void startMon();
	void stopMon();

	// log file methods
	void appendToLogfile(const string& str);

	// request list methods
	void addReq(ReqBrly* req);
	ReqBrly* pullFirstReq();

	// operation invocation list methods
	void addInvs(DbsBrly* dbsbrly, const ubigint jref, vector<DpchInvBrly*>& dpchinvs);
	bool pullFirstInv(DpchInvBrly** dpchinv, NodeBrly** node);
	void returnInv(DpchInvBrly* dpchinv);

	// presetting methods
	Preset* addPreset(const uint ixBrlyVPreset, const ubigint jref, const Arg& arg);

	Preset* addIxPreset(const uint ixBrlyVPreset, const ubigint jref, const uint ix);
	Preset* addRefPreset(const uint ixBrlyVPreset, const ubigint jref, const ubigint ref);
	Preset* addRefsPreset(const uint ixBrlyVPreset, const ubigint jref, const vector<ubigint>& refs);
	Preset* addSrefPreset(const uint ixBrlyVPreset, const ubigint jref, const string& sref);
	Preset* addIntvalPreset(const uint ixBrlyVPreset, const ubigint jref, const int intval);
	Preset* addDblvalPreset(const uint ixBrlyVPreset, const ubigint jref, const double dblval);
	Preset* addBoolvalPreset(const uint ixBrlyVPreset, const ubigint jref, const bool boolval);
	Preset* addTxtvalPreset(const uint ixBrlyVPreset, const ubigint jref, const string& txtval);

	Preset* getPresetByPref(const presetref_t& pref);

	Arg getPreset(const uint ixBrlyVPreset, const ubigint jref);

	uint getIxPreset(const uint ixBrlyVPreset, const ubigint jref);
	ubigint getRefPreset(const uint ixBrlyVPreset, const ubigint jref);
	vector<ubigint> getRefsPreset(const uint ixBrlyVPreset, const ubigint jref);
	string getSrefPreset(const uint ixBrlyVPreset, const ubigint jref);
	int getIntvalPreset(const uint ixBrlyVPreset, const ubigint jref);
	double getDblvalPreset(const uint ixBrlyVPreset, const ubigint jref);
	bool getBoolvalPreset(const uint ixBrlyVPreset, const ubigint jref);
	string getTxtvalPreset(const uint ixBrlyVPreset, const ubigint jref);

	void getPresetsByJref(const ubigint jref, vector<uint>& icsBrlyVPreset, vector<Arg>& args);

	void removePreset(const uint ixBrlyVPreset, const ubigint jref);
	void removePresetsByJref(const ubigint jref);

	// stub manager methods
	StmgrBrly* addStmgr(const ubigint jref, const uint ixVNonetype);
	StmgrBrly* getStmgrByJref(const ubigint jref);
	void removeStmgrByJref(const ubigint jref);

	// call listener list methods
	Clstn* addClstn(const uint ixBrlyVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const Arg& argMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);

	Clstn* addIxClstn(const uint ixBrlyVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addRefClstn(const uint ixBrlyVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const ubigint refMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addIxRefClstn(const uint ixBrlyVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const ubigint refMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addIxRefSrefClstn(const uint ixBrlyVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const ubigint refMask, const string& srefMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);

	Clstn* addClstnStmgr(const uint ixBrlyVCall, const ubigint jref);

	Clstn* getClstnByCref(const clstnref_t& cref);
	void getClstnsByJref(const ubigint jref, const bool stmgr, vector<uint>& icsBrlyVCall, vector<uint>& icsVJobmask);

	void removeClstns(const uint ixBrlyVCall, const ubigint jref, const bool stmgr = false);
	void removeClstnsByJref(const ubigint jref, const bool stmgr = false);

	// call methods
	void findJrefsByCall(Call* call, vector<ubigint>& jrefs, vector<bool>& stmgrs, vector<uint>& icsVJactype);

	void triggerCall(DbsBrly* dbsbrly, Call* call);

	bool triggerArgToArgCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const Arg& argInv, Arg& argRet);
	bool triggerCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref);
	bool triggerIxCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv);
	bool triggerRefCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const ubigint refInv);
	bool triggerIntvalCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const int intvalInv);
	bool triggerBoolvalCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const bool boolvalInv);
	bool triggerIxRefCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, const ubigint refInv);
	bool triggerIxSrefCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, const string& srefInv);
	bool triggerIxIntvalCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, const int intvalInv);
	bool triggerIxDblvalCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, const double dblvalInv);
	bool triggerIxTxtvalCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, const string& txtvalInv);
	bool triggerToBoolvalCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, bool& boolvalRet);
	bool triggerIxToBoolvalCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, bool& boolvalRet);
	bool triggerRefToSrefCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const ubigint refInv, string& srefRet);
	bool triggerRefToBoolvalCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const ubigint refInv, bool& boolvalRet);
	bool triggerIxRefToIxCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, const ubigint refInv, uint& ixRet);
	bool triggerIxRefToRefCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, const ubigint refInv, ubigint& refRet);
	bool triggerIxRefSrefCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv);
	bool triggerIxRefSrefIntvalCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv);
	bool triggerIxRefSrefIntvalToRefCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv, ubigint& refRet);
	bool triggerRefToIxCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const ubigint refInv, uint& ixRet);
	bool triggerSrefToRefCall(DbsBrly* dbsbrly, const uint ixBrlyVCall, const ubigint jref, const string& srefInv, ubigint& refRet);

	// dispatch collector list methods
	DcolBrly* addDcol(const ubigint jref);
	DcolBrly* getDcolByJref(const ubigint jref, const bool tree = true);
	void removeDcolByJref(const ubigint jref);

	void submitDpch(DpchEngBrly* dpcheng);
	DpchEngBrly* pullFirstDpch(DcolBrly* dcol);

	// job list methods
	ubigint addJob(JobBrly* job);
	ubigint addJob(DbsBrly* dbsbrly, JobBrly* job);

	JobBrly* getJobByJref(const ubigint jref);

	void removeJobByJref(const ubigint jref);

	void transferMaster(DbsBrly* dbsbrly, JobBrly* fromjob, JobBrly* tojob);
	void offerMaster(DbsBrly* dbsbrly, const ubigint jref);
	bool claimMaster(DbsBrly* dbsbrly, const ubigint jref);

	// timer methods
	ubigint addWakeup(const ubigint jref, const string sref, const unsigned int deltat = 0, const bool weak = false);
	static void* runWakeup(void* arg);

	// external call methods
	static void runExtcall(void* arg);

	// node methods
	NodeBrly* addNode(const string& ip, const uint port, const uint opprcn, const uint ixBrlyVOpengtype);
	NodeBrly* getNodeByNref(const ubigint nref);

	void quitNodes();
	void quitNodeByNref(const ubigint nref);

	void removeNodeByNref(const ubigint nref);

	static uint CurlPostrecv(void* data, uint size, uint blocksize, void* _inst);
	bool CurlPostDpch(const string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, string& rplydpch);
};
#endif


