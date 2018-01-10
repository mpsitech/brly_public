/**
  * \file BrlyBase_blks.h
  * invocation / return data blocks for operation pack BrlyBase (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYBASE_BLKS_H
#define BRLYBASE_BLKS_H

#include "Brly.h"

/**
	* DpchInvBrlyBaseLegleg
	*/
class DpchInvBrlyBaseLegleg : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint NUMFIRST = 3;
	static const uint NUMLAST = 4;
	static const uint REFSBRLYMLEG = 5;
	static const uint APPEND = 6;
	static const uint INTERMIX = 7;

public:
	DpchInvBrlyBaseLegleg(const ubigint oref = 0, const ubigint jref = 0, const uint numFirst = 0, const uint numLast = 0, const vector<ubigint>& refsBrlyMLeg = {}, const bool append = false, const bool intermix = false);

public:
	uint numFirst;
	uint numLast;
	vector<ubigint> refsBrlyMLeg;
	bool append;
	bool intermix;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvBrlyBaseLegloc
	*/
class DpchInvBrlyBaseLegloc : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint NUMFIRST = 3;
	static const uint NUMLAST = 4;
	static const uint REFSBRLYMLEG = 5;
	static const uint REFSBRLYMLOCATION = 6;
	static const uint APPEND = 7;
	static const uint APPENDLOC = 8;

public:
	DpchInvBrlyBaseLegloc(const ubigint oref = 0, const ubigint jref = 0, const uint numFirst = 0, const uint numLast = 0, const vector<ubigint>& refsBrlyMLeg = {}, const vector<ubigint>& refsBrlyMLocation = {}, const bool append = false, const bool appendloc = false);

public:
	uint numFirst;
	uint numLast;
	vector<ubigint> refsBrlyMLeg;
	vector<ubigint> refsBrlyMLocation;
	bool append;
	bool appendloc;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvBrlyBaseLocloc
	*/
class DpchInvBrlyBaseLocloc : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint NUMFIRST = 3;
	static const uint NUMLAST = 4;
	static const uint REFSBRLYMLOCATION = 5;
	static const uint APPEND = 6;
	static const uint INTERMIX = 7;

public:
	DpchInvBrlyBaseLocloc(const ubigint oref = 0, const ubigint jref = 0, const uint numFirst = 0, const uint numLast = 0, const vector<ubigint>& refsBrlyMLocation = {}, const bool append = false, const bool intermix = false);

public:
	uint numFirst;
	uint numLast;
	vector<ubigint> refsBrlyMLocation;
	bool append;
	bool intermix;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

