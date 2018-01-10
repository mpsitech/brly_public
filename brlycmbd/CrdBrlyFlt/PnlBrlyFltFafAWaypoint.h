/**
  * \file PnlBrlyFltFafAWaypoint.h
  * job handler for job PnlBrlyFltFafAWaypoint (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFLTFAFAWAYPOINT_H
#define PNLBRLYFLTFAFAWAYPOINT_H

// IP custInclude --- INSERT

#include "QryBrlyFltFafAWaypoint.h"

#define VecVBrlyFltFafAWaypointDo PnlBrlyFltFafAWaypoint::VecVDo

#define ContInfBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::ContInf
#define StatAppBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::StatApp
#define StatShrBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::StatShr
#define StgIacBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::StgIac
#define TagBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::Tag

#define DpchAppBrlyFltFafAWaypointData PnlBrlyFltFafAWaypoint::DpchAppData
#define DpchAppBrlyFltFafAWaypointDo PnlBrlyFltFafAWaypoint::DpchAppDo
#define DpchEngBrlyFltFafAWaypointData PnlBrlyFltFafAWaypoint::DpchEngData

/**
  * PnlBrlyFltFafAWaypoint
  */
class PnlBrlyFltFafAWaypoint : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyFltFafAWaypointDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUPCLICK = 1;
		static const uint BUTDOWNCLICK = 2;
		static const uint BUTNEWCLICK = 3;
		static const uint BUTDUPLICATECLICK = 4;
		static const uint BUTDELETECLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyFltFafAWaypoint)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyFltFafAWaypoint)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyFltFafAWaypoint)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTUPAVAIL = 1;
		static const uint BUTUPACTIVE = 2;
		static const uint BUTDOWNAVAIL = 3;
		static const uint BUTDOWNACTIVE = 4;
		static const uint BUTNEWAVAIL = 5;
		static const uint BUTDUPLICATEAVAIL = 6;
		static const uint BUTDUPLICATEACTIVE = 7;
		static const uint BUTDELETEAVAIL = 8;
		static const uint BUTDELETEACTIVE = 9;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacBrlyFltFafAWaypoint)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOTMSWIDTH = 1;
		static const uint TCOLATWIDTH = 2;
		static const uint TCOLONWIDTH = 3;
		static const uint TCOGSPWIDTH = 4;
		static const uint TCOALTWIDTH = 5;
		static const uint TCOASTWIDTH = 6;
		static const uint TCOUTYWIDTH = 7;
		static const uint TCOACHWIDTH = 8;

	public:
		StgIac(const uint TcoTmsWidth = 100, const uint TcoLatWidth = 100, const uint TcoLonWidth = 100, const uint TcoGspWidth = 100, const uint TcoAltWidth = 100, const uint TcoAstWidth = 100, const uint TcoUtyWidth = 100, const uint TcoAchWidth = 100);

	public:
		uint TcoTmsWidth;
		uint TcoLatWidth;
		uint TcoLonWidth;
		uint TcoGspWidth;
		uint TcoAltWidth;
		uint TcoAstWidth;
		uint TcoUtyWidth;
		uint TcoAchWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagBrlyFltFafAWaypoint)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFltFafAWaypointData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryBrlyFltFafAWaypoint::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFltFafAWaypointDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngBrlyFltFafAWaypointData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListBrlyQFltFafAWaypoint* rst = NULL, QryBrlyFltFafAWaypoint::StatShr* statshrqry = NULL, QryBrlyFltFafAWaypoint::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListBrlyQFltFafAWaypoint rst;
		QryBrlyFltFafAWaypoint::StatShr statshrqry;
		QryBrlyFltFafAWaypoint::StgIac stgiacqry;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButUpAvail(DbsBrly* dbsbrly);
	bool evalButUpActive(DbsBrly* dbsbrly);
	bool evalButDownAvail(DbsBrly* dbsbrly);
	bool evalButDownActive(DbsBrly* dbsbrly);
	bool evalButNewAvail(DbsBrly* dbsbrly);
	bool evalButDuplicateAvail(DbsBrly* dbsbrly);
	bool evalButDuplicateActive(DbsBrly* dbsbrly);
	bool evalButDeleteAvail(DbsBrly* dbsbrly);
	bool evalButDeleteActive(DbsBrly* dbsbrly);

public:
	PnlBrlyFltFafAWaypoint(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyFltFafAWaypoint();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;

	QryBrlyFltFafAWaypoint* qry;

	BrlyAMFaflightWaypoint recFafAwpt;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(set<uint> items);

	void refresh(DbsBrly* dbsbrly, set<uint>& moditems);

	void updatePreset(DbsBrly* dbsbrly, const uint ixBrlyVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiac(DbsBrly* dbsbrly, StgIac* _stgiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqry(DbsBrly* dbsbrly, QryBrlyFltFafAWaypoint::StgIac* _stgiacqry, DpchEngBrly** dpcheng);

	void handleDpchAppDoButUpClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButDownClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButNewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButDuplicateClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
};

#endif

