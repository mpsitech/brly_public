/**
  * \file BrlyDnsmap_blks.h
  * invocation / return data blocks for operation pack BrlyDnsmap (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDNSMAP_BLKS_H
#define BRLYDNSMAP_BLKS_H

#include "Brly.h"

/**
	* DpchInvBrlyDnsmapCollect
	*/
class DpchInvBrlyDnsmapCollect : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint CAPACITY = 3;
	static const uint CON = 4;
	static const uint DT = 5;
	static const uint FLT = 6;
	static const uint FULLHEIGHT = 7;
	static const uint FULLWIDTH = 8;
	static const uint LEG = 9;
	static const uint PACCTR = 10;
	static const uint PHI0 = 11;
	static const uint PHI1 = 12;
	static const uint PREACH = 13;
	static const uint SEG = 14;
	static const uint SREFARENA = 15;
	static const uint SREFSBRLYKEQPTYPE = 16;
	static const uint START = 17;
	static const uint STOP = 18;
	static const uint THETA0 = 19;
	static const uint THETA1 = 20;

public:
	DpchInvBrlyDnsmapCollect(const ubigint oref = 0, const ubigint jref = 0, const bool capacity = false, const bool con = false, const uint dt = 0, const bool flt = false, const uint fullheight = 0, const uint fullwidth = 0, const bool leg = false, const bool pacctr = false, const double phi0 = 0.0, const double phi1 = 0.0, const bool pReach = false, const bool seg = false, const string& srefArena = "", const string& srefsBrlyKEqptype = "", const uint start = 0, const uint stop = 0, const double theta0 = 0.0, const double theta1 = 0.0);

public:
	bool capacity;
	bool con;
	uint dt;
	bool flt;
	uint fullheight;
	uint fullwidth;
	bool leg;
	bool pacctr;
	double phi0;
	double phi1;
	bool pReach;
	bool seg;
	string srefArena;
	string srefsBrlyKEqptype;
	uint start;
	uint stop;
	double theta0;
	double theta1;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetBrlyDnsmapCollect
	*/
class DpchRetBrlyDnsmapCollect : public DpchRetBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint REFBRLYMFILE = 4;

public:
	DpchRetBrlyDnsmapCollect(const string& scrOref = "", const string& scrJref = "", const bool success = false, const ubigint refBrlyMFile = 0);

public:
	bool success;

	ubigint refBrlyMFile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDnsmapFrame
	*/
class DpchInvBrlyDnsmapFrame : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFBRLYMFILE = 3;
	static const uint FULLSIZE = 4;
	static const uint GRAYSCALE = 5;
	static const uint ALTZMAX = 6;
	static const uint TIX = 7;

public:
	DpchInvBrlyDnsmapFrame(const ubigint oref = 0, const ubigint jref = 0, const ubigint refBrlyMFile = 0, const bool fullsize = false, const bool grayscale = false, const double altzmax = 0.0, const uint tIx = 0);

public:
	ubigint refBrlyMFile;
	bool fullsize;
	bool grayscale;
	double altzmax;
	uint tIx;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetBrlyDnsmapFrame
	*/
class DpchRetBrlyDnsmapFrame : public DpchRetBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint FILENAME = 4;

public:
	DpchRetBrlyDnsmapFrame(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& filename = "");

public:
	bool success;

	string filename;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDnsmapVideo
	*/
class DpchInvBrlyDnsmapVideo : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ALTZMAX = 3;
	static const uint FRMRATE = 4;
	static const uint FULLSIZE = 5;
	static const uint GRAYSCALE = 6;
	static const uint REFBRLYMFILE = 7;

public:
	DpchInvBrlyDnsmapVideo(const ubigint oref = 0, const ubigint jref = 0, const double altzmax = 0.0, const uint frmrate = 0, const bool fullsize = false, const bool grayscale = false, const ubigint refBrlyMFile = 0);

public:
	double altzmax;
	uint frmrate;
	bool fullsize;
	bool grayscale;
	ubigint refBrlyMFile;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetBrlyDnsmapVideo
	*/
class DpchRetBrlyDnsmapVideo : public DpchRetBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint FOLDER = 4;

public:
	DpchRetBrlyDnsmapVideo(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& folder = "");

public:
	bool success;

	string folder;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

