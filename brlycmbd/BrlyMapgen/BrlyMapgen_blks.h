/**
  * \file BrlyMapgen_blks.h
  * invocation / return data blocks for operation pack BrlyMapgen (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMAPGEN_BLKS_H
#define BRLYMAPGEN_BLKS_H

#include "Brly.h"

/**
	* DpchInvBrlyMapgenConmap
	*/
class DpchInvBrlyMapgenConmap : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFBRLYMCONNECTION = 3;
	static const uint JREFLEG = 4;
	static const uint JREFLOC = 5;
	static const uint JREFFLT = 6;
	static const uint JREFRLY = 7;
	static const uint JREFNDE = 8;
	static const uint SCALE = 9;
	static const uint WIDTH = 10;
	static const uint HEIGHT = 11;
	static const uint XOFFSET = 12;
	static const uint YOFFSET = 13;
	static const uint WRTREE = 14;
	static const uint FILENAME = 15;

public:
	DpchInvBrlyMapgenConmap(const ubigint oref = 0, const ubigint jref = 0, const ubigint refBrlyMConnection = 0, const ubigint jrefLeg = 0, const ubigint jrefLoc = 0, const ubigint jrefFlt = 0, const ubigint jrefRly = 0, const ubigint jrefNde = 0, const uint scale = 1, const uint width = 300, const uint height = 300, const int xoffset = 0, const int yoffset = 0, const bool wrtree = false, const string& filename = "");

public:
	ubigint refBrlyMConnection;
	ubigint jrefLeg;
	ubigint jrefLoc;
	ubigint jrefFlt;
	ubigint jrefRly;
	ubigint jrefNde;
	uint scale;
	uint width;
	uint height;
	int xoffset;
	int yoffset;
	bool wrtree;
	string filename;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvBrlyMapgenLegmap
	*/
class DpchInvBrlyMapgenLegmap : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFBRLYMLEG = 3;
	static const uint JREFLEG = 4;
	static const uint JREFLOC = 5;
	static const uint SCALE = 6;
	static const uint WIDTH = 7;
	static const uint HEIGHT = 8;
	static const uint XOFFSET = 9;
	static const uint YOFFSET = 10;
	static const uint FILENAME = 11;

public:
	DpchInvBrlyMapgenLegmap(const ubigint oref = 0, const ubigint jref = 0, const ubigint refBrlyMLeg = 0, const ubigint jrefLeg = 0, const ubigint jrefLoc = 0, const uint scale = 1, const uint width = 300, const uint height = 300, const int xoffset = 0, const int yoffset = 0, const string& filename = "");

public:
	ubigint refBrlyMLeg;
	ubigint jrefLeg;
	ubigint jrefLoc;
	uint scale;
	uint width;
	uint height;
	int xoffset;
	int yoffset;
	string filename;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvBrlyMapgenLocmap
	*/
class DpchInvBrlyMapgenLocmap : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFBRLYMLOCATION = 3;
	static const uint JREFLEG = 4;
	static const uint JREFPROXLOC = 5;
	static const uint JREFVISLOC = 6;
	static const uint SCALE = 7;
	static const uint WIDTH = 8;
	static const uint HEIGHT = 9;
	static const uint XOFFSET = 10;
	static const uint YOFFSET = 11;
	static const uint FILENAME = 12;

public:
	DpchInvBrlyMapgenLocmap(const ubigint oref = 0, const ubigint jref = 0, const ubigint refBrlyMLocation = 0, const ubigint jrefLeg = 0, const ubigint jrefProxloc = 0, const ubigint jrefVisloc = 0, const uint scale = 1, const uint width = 300, const uint height = 300, const int xoffset = 0, const int yoffset = 0, const string& filename = "");

public:
	ubigint refBrlyMLocation;
	ubigint jrefLeg;
	ubigint jrefProxloc;
	ubigint jrefVisloc;
	uint scale;
	uint width;
	uint height;
	int xoffset;
	int yoffset;
	string filename;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

