/**
  * \file Brlyd_exe.h
  * Brly daemon main (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYD_EXE_H
#define BRLYD_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

using namespace std;

#include <signal.h>

#include "BrlydAppsrv.h"
#include "BrlydJobprc.h"
#include "BrlydOpengcli.h"
#include "BrlydOpengconsrv.h"

/**
  * PrefBrlyd
  */
class PrefBrlyd : public Block {

public:
	static const uint STGBRLYD = 1;
	static const uint STGBRLYDATABASE = 2;
	static const uint STGBRLYFLIGHTAWARE = 3;
	static const uint STGBRLYGEOMETRY = 4;
	static const uint STGBRLYMONITOR = 5;
	static const uint STGBRLYPATH = 6;
	static const uint ALL = 7;

public:
	PrefBrlyd(StgBrlyd* stgbrlyd = NULL, StgBrlyDatabase* stgbrlydatabase = NULL, StgBrlyFlightaware* stgbrlyflightaware = NULL, StgBrlyGeometry* stgbrlygeometry = NULL, StgBrlyMonitor* stgbrlymonitor = NULL, StgBrlyPath* stgbrlypath = NULL, const set<uint>& mask = {ALL});

public:
	StgBrlyd stgbrlyd;
	StgBrlyDatabase stgbrlydatabase;
	StgBrlyFlightaware stgbrlyflightaware;
	StgBrlyGeometry stgbrlygeometry;
	StgBrlyMonitor stgbrlymonitor;
	StgBrlyPath stgbrlypath;

public:
	static bool all(const set<uint>& items);

	void readXMLFromFile(const string& fullpath);
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXMLToFile(const string& fullpath);
	void writeXML(xmlTextWriter* wr);
};

/**
  * Brlyd
  */
class Brlyd {

public:
	Brlyd(const string& exedir, const bool clearAll, const bool startMon);
	~Brlyd();

	void init(const string& exedir, const bool clearAll, const bool startMon);
	bool initdone;
	void term();

public:
	string exedir;

	DbsBrly dbsbrly;

	XchgBrlyd* xchg;
	
	RootBrly* root;

	MHD_Daemon* opengconsrv;
	MHD_Daemon* appsrv;

	pthread_t opengcli;

	vector<pthread_t> jobprcs;

public:
	void loadPref();
	void storePref();

	void initXchgdataJobprc();
	void termXchgdataJobprc();
};

Brlyd* brlyd;

#endif

