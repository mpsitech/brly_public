/**
  * \file Brlyopd_exe.h
  * Brly operation daemon brlyopd main (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYOPD_EXE_H
#define BRLYOPD_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

using namespace std;

#include <signal.h>

#include "BrlyopdEngsrv.h"
#include "BrlyopdOpprc.h"

/**
  * PrefBrlyopd
  */
class PrefBrlyopd : public Block {

public:
	static const uint STGBRLYDATABASE = 1;
	static const uint STGBRLYFLIGHTAWARE = 2;
	static const uint STGBRLYGEOMETRY = 3;
	static const uint STGBRLYMONITOR = 4;
	static const uint STGBRLYOPD = 5;
	static const uint STGBRLYPATH = 6;
	static const uint ALL = 7;

public:
	PrefBrlyopd(StgBrlyDatabase* stgbrlydatabase = NULL, StgBrlyFlightaware* stgbrlyflightaware = NULL, StgBrlyGeometry* stgbrlygeometry = NULL, StgBrlyMonitor* stgbrlymonitor = NULL, StgBrlyopd* stgbrlyopd = NULL, StgBrlyPath* stgbrlypath = NULL, const set<uint>& mask = {ALL});

public:
	StgBrlyDatabase stgbrlydatabase;
	StgBrlyFlightaware stgbrlyflightaware;
	StgBrlyGeometry stgbrlygeometry;
	StgBrlyMonitor stgbrlymonitor;
	StgBrlyopd stgbrlyopd;
	StgBrlyPath stgbrlypath;

public:
	static bool all(const set<uint>& items);

	void readXMLFromFile(const string& fullpath);
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXMLToFile(const string& fullpath);
	void writeXML(xmlTextWriter* wr);
};

/**
  * Brlyopd
  */
class Brlyopd {

public:
	Brlyopd(const string& exedir, const usmallint engsrvportofs);
	~Brlyopd();

	void init(const string& exedir, const usmallint engsrvportofs);
	bool initdone;
	void term();

public:
	string exedir;

	XchgBrlyopd* xchg;

	MHD_Daemon* engsrv;

	vector<pthread_t> opprcs;

public:
	char* curlrecv;
	size_t curlrecvlen;

	static uint CurlPostrecv(void* data, uint size, uint blocksize, void* _inst);
	bool CurlPostDpch(const string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, string& rplydpch);

public:
	void loadPref();
	void storePref();

	void initXchgdataOpprc();
	void termXchgdataOpprc();
};

Brlyopd* brlyopd;

#endif

