/**
  * \file Brlycmbd_exe.h
  * Brly combined daemon main (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYCMBD_EXE_H
#define BRLYCMBD_EXE_H

#include <string>
#include <vector>

using namespace std;

#include <signal.h>

#include "BrlycmbdAppsrv.h"
#include "BrlycmbdJobprc.h"
#include "BrlycmbdOpprc.h"

/**
  * PrefBrlycmbd
  */
class PrefBrlycmbd : public Block {

public:
	static const uint STGBRLYCMBD = 1;
	static const uint STGBRLYDATABASE = 2;
	static const uint STGBRLYFLIGHTAWARE = 3;
	static const uint STGBRLYGEOMETRY = 4;
	static const uint STGBRLYMONITOR = 5;
	static const uint STGBRLYPATH = 6;
	static const uint ALL = 7;

public:
	PrefBrlycmbd(StgBrlycmbd* stgbrlycmbd = NULL, StgBrlyDatabase* stgbrlydatabase = NULL, StgBrlyFlightaware* stgbrlyflightaware = NULL, StgBrlyGeometry* stgbrlygeometry = NULL, StgBrlyMonitor* stgbrlymonitor = NULL, StgBrlyPath* stgbrlypath = NULL, const set<uint>& mask = {ALL});

public:
	StgBrlycmbd stgbrlycmbd;
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
  * Brlycmbd
  */
class Brlycmbd {

public:
	Brlycmbd(const string& exedir, const bool clearAll, const bool startMon);
	~Brlycmbd();

	void init(const string& exedir, const bool clearAll, const bool startMon);
	bool initdone;
	void term();

public:
	string exedir;

	DbsBrly dbsbrly;

	XchgBrlycmbd* xchg;
	
	RootBrly* root;

	MHD_Daemon* appsrv;

	vector<pthread_t> jobprcs;

	vector<pthread_t> opprcs;

public:
	void loadPref();
	void storePref();

	void initXchgdataJobprc();
	void termXchgdataJobprc();

	void initXchgdataOpprc();
	void termXchgdataOpprc();
};

Brlycmbd* brlycmbd;

#endif

