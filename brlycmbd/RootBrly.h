/**
  * \file RootBrly.h
  * job handler for job RootBrly (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef ROOTBRLY_H
#define ROOTBRLY_H

// IP custInclude --- INSERT

#include "SessBrly.h"

#define DpchAppRootBrlyLogin RootBrly::DpchAppLogin

/**
  * RootBrly
  */
class RootBrly : public JobBrly {

public:
	/**
		* DpchAppLogin (full: DpchAppRootBrlyLogin)
		*/
	class DpchAppLogin : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint PASSWORD = 2;
		static const uint USERNAME = 3;

	public:
		DpchAppLogin();

	public:
		string password;
		string username;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

public:
	RootBrly(XchgBrly* xchg, DbsBrly* dbsbrly, const bool _clearAll);
	~RootBrly();

public:

	list<SessBrly*> sesss;

	// IP specVar --- INSERT

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void clearAll(DbsBrly* dbsbrly);
	void clearQtb(DbsBrly* dbsbrly);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	bool handleClearAll(DbsBrly* dbsbrly);
	bool handleCreateSess(DbsBrly* dbsbrly);
	bool handleEraseSess(DbsBrly* dbsbrly);

	void handleDpchAppLogin(DbsBrly* dbsbrly, DpchAppLogin* dpchapplogin, const string ip, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyLogout(DbsBrly* dbsbrly, const ubigint jrefTrig);
};

#endif

