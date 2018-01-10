/**
  * \file BrlyTtimp_blks.h
  * invocation / return data blocks for operation pack BrlyTtimp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYTTIMP_BLKS_H
#define BRLYTTIMP_BLKS_H

#include "Brly.h"

/**
	* DpchInvBrlyTtimpRawstar
	*/
class DpchInvBrlyTtimpRawstar : public DpchInvBrly {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint INFILE = 3;
	static const uint OUTFILE = 4;

public:
	DpchInvBrlyTtimpRawstar(const ubigint oref = 0, const ubigint jref = 0, const string& infile = "", const string& outfile = "");

public:
	string infile;
	string outfile;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

