/**
  * \file BrlyDyn_blks.h
  * invocation / return data blocks for operation pack BrlyDyn (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDYN_BLKS_H
#define BRLYDYN_BLKS_H

#include "Brly.h"

/**
	* DpchInvBrlyDynConflt
	*/
class DpchInvBrlyDynConflt : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFBRLYMCONNECTION = 3;

public:
	DpchInvBrlyDynConflt(const ubigint oref = 0, const ubigint jref = 0, const ubigint refBrlyMConnection = 0);

public:
	ubigint refBrlyMConnection;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynConseg
	*/
class DpchInvBrlyDynConseg : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFBRLYMCONNECTION = 3;

public:
	DpchInvBrlyDynConseg(const ubigint oref = 0, const ubigint jref = 0, const ubigint refBrlyMConnection = 0);

public:
	ubigint refBrlyMConnection;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynEqplist
	*/
class DpchInvBrlyDynEqplist : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFBRLYMCONNECTION = 3;

public:
	DpchInvBrlyDynEqplist(const ubigint oref = 0, const ubigint jref = 0, const ubigint refBrlyMConnection = 0);

public:
	ubigint refBrlyMConnection;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynFltfltloc
	*/
class DpchInvBrlyDynFltfltloc : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFSBRLYMFLIGHT = 3;

public:
	DpchInvBrlyDynFltfltloc(const ubigint oref = 0, const ubigint jref = 0, const vector<ubigint>& refsBrlyMFlight = {});

public:
	vector<ubigint> refsBrlyMFlight;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynFltseg
	*/
class DpchInvBrlyDynFltseg : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint NUMFIRST = 3;
	static const uint NUMLAST = 4;
	static const uint REFSBRLYMFLIGHT = 5;
	static const uint START = 6;
	static const uint STOP = 7;

public:
	DpchInvBrlyDynFltseg(const ubigint oref = 0, const ubigint jref = 0, const uint numFirst = 0, const uint numLast = 0, const vector<ubigint>& refsBrlyMFlight = {}, const uint start = 0, const uint stop = 0);

public:
	uint numFirst;
	uint numLast;
	vector<ubigint> refsBrlyMFlight;
	uint start;
	uint stop;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynRly
	*/
class DpchInvBrlyDynRly : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFBRLYMCONNECTION = 3;

public:
	DpchInvBrlyDynRly(const ubigint oref = 0, const ubigint jref = 0, const ubigint refBrlyMConnection = 0);

public:
	ubigint refBrlyMConnection;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynSeglocseg
	*/
class DpchInvBrlyDynSeglocseg : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFSBRLYMFLIGHT = 3;

public:
	DpchInvBrlyDynSeglocseg(const ubigint oref = 0, const ubigint jref = 0, const vector<ubigint>& refsBrlyMFlight = {});

public:
	vector<ubigint> refsBrlyMFlight;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

