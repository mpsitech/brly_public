/**
  * \file Brlyopd.h
  * inter-thread exchange object for Brly operation daemon brlyopd (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYOPD_H
#define BRLYOPD_H

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

#ifdef _WIN32
	#include <pthread.h>
#endif

#include <microhttpd.h>

#include <curl/curl.h>

#include "Brly.h"

class XchgBrlyopd;
typedef XchgBrlyopd XchgBrly;

/**
  * DpchBrlydReg (written by dOpengconsrv, read by opd_exe)
  */
class DpchBrlydReg : public DpchBrly {

public:
	static const uint SCRNREF = 1;

public:
	DpchBrlydReg();

public:
	string scrNref;

public:
	static bool all(const set<uint>& items);

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchBrlyopdAck (written by opd_exe, identified by d_exe)
  */
namespace DpchBrlyopdAck {
	void writeXML(xmlTextWriter* wr);
};

/**
  * DpchBrlyopdReg (written by opd_exe, read by dOpengconsrv)
  */
namespace DpchBrlyopdReg {
	void writeXML(xmlTextWriter* wr, const usmallint port = 0, const uint ixBrlyVOpengtype = 0, const usmallint opprcn = 0);
};

/**
  * DpchBrlyopdUnreg (written by opd_exe, read by dOpengconsrv)
  */
namespace DpchBrlyopdUnreg {
	void writeXML(xmlTextWriter* wr, const string& scrNref = "");
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
	* StgBrlyopd
	*/
class StgBrlyopd : public Block {

public:
	static const uint ENGCLIIP = 1;
	static const uint ENGCLIPORT = 2;
	static const uint ENGSRVPORTBASE = 3;
	static const uint ENGSRVPORTOFS = 4;
	static const uint OPPRCN = 5;

public:
	StgBrlyopd(const string& engcliip = "", const usmallint engcliport = 0, const usmallint engsrvportbase = 0, const usmallint engsrvportofs = 0, const usmallint opprcn = 1);

public:
	string engcliip;
	usmallint engcliport;
	usmallint engsrvportbase;
	usmallint engsrvportofs;
	usmallint opprcn;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgBrlyopd* comp);
	set<uint> diff(const StgBrlyopd* comp);
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
  * ReqopBrly
  */
class ReqopBrly {

public:
	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const uint RECEIVE = 0; // during data reception - engsrv internal
		static const uint WAITPRC = 1; // before caught by op processor that is idle - in reqs list
		static const uint PRC = 2; // while being processesd by op processor - still in reqs list ; engsrv thread waiting on cReply
		static const uint REPLY = 3; // while reply being transmitted by engsrv - engsrv internal
	};

public:
	ReqopBrly(const uint ixVState = VecVState::RECEIVE);
	~ReqopBrly();

public:
	uint ixVState;

	MHD_PostProcessor* pp;

	pthread_mutex_t mcReady;
	pthread_cond_t cReady;

	char* request;
	size_t requestlen;

	DpchInvBrly* dpchinv;

	DpchRetBrly* dpchret;

	char* reply;
	size_t replylen;
};

/**
  * XchgdataBrlyOpprc
  */
class XchgdataBrlyOpprc {

public:
	// IP dataopprc.subs --- INSERT

public:
	XchgdataBrlyOpprc();

public:
	// IP dataopprc --- INSERT
};

/**
	* XchgdataBrlyMapgen
	*/
class XchgdataBrlyMapgen {

public:
	// IP XchgdataBrlyMapgen.subs --- INSERT

public:
	XchgdataBrlyMapgen();

public:
	// IP XchgdataBrlyMapgen --- IBEGIN
	short* etopo;

	// color map look-up tables
	vector<utinyint> RvsZ;
	vector<utinyint> GvsZ;
	vector<utinyint> BvsZ;
	// IP XchgdataBrlyMapgen --- IEND
};

/**
  * XchgBrlyopd
  */
class XchgBrlyopd {

public:
	XchgBrlyopd();
	~XchgBrlyopd();

public:
	StgBrlyDatabase stgbrlydatabase;
	StgBrlyFlightaware stgbrlyflightaware;
	StgBrlyGeometry stgbrlygeometry;
	StgBrlyMonitor stgbrlymonitor;
	StgBrlyopd stgbrlyopd;
	StgBrlyPath stgbrlypath;

	XchgdataBrlyOpprc dataopprc;
	XchgdataBrlyMapgen databrlymapgen;

public:
	// IP cust --- INSERT

public:
	// executable/archive/temporary folder paths and help URL
	string exedir;
	string acvpath;
	string tmppath;
	string helpurl;

	// node reference as assigned by engine
	string scrNref;

	// mutex for log file
	pthread_mutex_t mLogfile;

	// condition for termination
	pthread_mutex_t mcTerm;
	pthread_cond_t cTerm;

	// condition for op processors
	pthread_mutex_t mcOpprcs;
	pthread_cond_t cOpprcs;

	// request list
	pthread_mutex_t mReqs;
	list<ReqopBrly*> reqs;

public:
	// log file methods
	void appendToLogfile(const string& str);

	// request list methods
	void addReq(ReqopBrly* req);
	ReqopBrly* pullFirstReq();
};

#endif


