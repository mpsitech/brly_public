/**
  * \file ApiBrly_blks.h
  * Brly API library global data blocks (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef APIBRLY_BLKS_H
#define APIBRLY_BLKS_H

#include "VecBrlyVDpch.h"
#include "VecBrlyVExpstate.h"
#include "VecBrlyVQrystate.h"
#include "VecBrlyVReqitmode.h"

/**
	* ContInfBrlyAlert
	*/
class ContInfBrlyAlert : public Block {

public:
	static const uint TXTCPT = 1;
	static const uint TXTMSG1 = 2;
	static const uint TXTMSG2 = 3;
	static const uint TXTMSG3 = 4;
	static const uint TXTMSG4 = 5;
	static const uint TXTMSG5 = 6;
	static const uint TXTMSG6 = 7;
	static const uint TXTMSG7 = 8;
	static const uint TXTMSG8 = 9;
	static const uint TXTMSG9 = 10;
	static const uint TXTMSG10 = 11;
	static const uint TXTMSG11 = 12;
	static const uint TXTMSG12 = 13;

public:
	ContInfBrlyAlert(const string& TxtCpt = "", const string& TxtMsg1 = "", const string& TxtMsg2 = "", const string& TxtMsg3 = "", const string& TxtMsg4 = "", const string& TxtMsg5 = "", const string& TxtMsg6 = "", const string& TxtMsg7 = "", const string& TxtMsg8 = "", const string& TxtMsg9 = "", const string& TxtMsg10 = "", const string& TxtMsg11 = "", const string& TxtMsg12 = "");

public:
	string TxtCpt;
	string TxtMsg1;
	string TxtMsg2;
	string TxtMsg3;
	string TxtMsg4;
	string TxtMsg5;
	string TxtMsg6;
	string TxtMsg7;
	string TxtMsg8;
	string TxtMsg9;
	string TxtMsg10;
	string TxtMsg11;
	string TxtMsg12;

public:
	static bool all(const set<uint>& items);
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	set<uint> compare(const ContInfBrlyAlert* comp);
};

/**
	* DpchBrly
	*/
class DpchBrly : public Block {

public:
	DpchBrly(const uint ixBrlyVDpch = 0);
	virtual ~DpchBrly();

public:
	uint ixBrlyVDpch;
};

/**
	* DpchAppBrly
	*/
class DpchAppBrly : public DpchBrly {

public:
	static const uint SCRJREF = 1;

public:
	DpchAppBrly(const uint ixBrlyVDpch = 0, const string& scrJref = "");
	virtual ~DpchAppBrly();

public:
	string scrJref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();

	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppBrlyAlert
	*/
class DpchAppBrlyAlert : public DpchAppBrly {

public:
	static const uint SCRJREF = 1;
	static const uint NUMFMCB = 2;
	static const uint ALL = 3;

public:
	DpchAppBrlyAlert(const string& scrJref = "", const uint numFMcb = 0, const set<uint>& mask = {NONE});

public:
	uint numFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppBrlyInit
	*/
class DpchAppBrlyInit : public DpchAppBrly {

public:
	DpchAppBrlyInit(const string& scrJref = "");
};

/**
	* DpchAppBrlyResume
	*/
class DpchAppBrlyResume : public DpchAppBrly {

public:
	DpchAppBrlyResume(const string& scrJref = "");
};

/**
	* DpchEngBrly
	*/
class DpchEngBrly : public DpchBrly {

public:
	static const uint SCRJREF = 1;

public:
	DpchEngBrly(const uint ixBrlyVDpch = 0);
	virtual ~DpchEngBrly();

public:
	string scrJref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();

	virtual void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngBrlyAck
	*/
class DpchEngBrlyAck : public DpchEngBrly {

public:
	DpchEngBrlyAck();
};

/**
	* DpchEngBrlyAlert
	*/
class DpchEngBrlyAlert : public DpchEngBrly {

public:
	static const uint SCRJREF = 1;
	static const uint CONTINF = 2;
	static const uint FEEDFMCB = 3;

public:
	DpchEngBrlyAlert();

public:
	ContInfBrlyAlert continf;
	Feed feedFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngBrlyConfirm
	*/
class DpchEngBrlyConfirm : public DpchEngBrly {

public:
	static const uint ACCEPTED = 1;
	static const uint SCRJREF = 2;
	static const uint SREF = 3;

public:
	DpchEngBrlyConfirm();

public:
	bool accepted;
	string sref;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngBrlySuspend
	*/
class DpchEngBrlySuspend : public DpchEngBrly {

public:
	DpchEngBrlySuspend();
};

#endif

