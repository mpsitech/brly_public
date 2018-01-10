/**
  * \file PnlBrlyConConMNEquipment.h
  * job handler for job PnlBrlyConConMNEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYCONCONMNEQUIPMENT_H
#define PNLBRLYCONCONMNEQUIPMENT_H

// IP custInclude --- INSERT

#include "QryBrlyConConMNEquipment.h"

#define VecVBrlyConConMNEquipmentDo PnlBrlyConConMNEquipment::VecVDo

#define ContInfBrlyConConMNEquipment PnlBrlyConConMNEquipment::ContInf
#define StatAppBrlyConConMNEquipment PnlBrlyConConMNEquipment::StatApp
#define StatShrBrlyConConMNEquipment PnlBrlyConConMNEquipment::StatShr
#define StgIacBrlyConConMNEquipment PnlBrlyConConMNEquipment::StgIac
#define TagBrlyConConMNEquipment PnlBrlyConConMNEquipment::Tag

#define DpchAppBrlyConConMNEquipmentData PnlBrlyConConMNEquipment::DpchAppData
#define DpchAppBrlyConConMNEquipmentDo PnlBrlyConConMNEquipment::DpchAppDo
#define DpchEngBrlyConConMNEquipmentData PnlBrlyConConMNEquipment::DpchEngData

/**
  * PnlBrlyConConMNEquipment
  */
class PnlBrlyConConMNEquipment : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyConConMNEquipmentDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUPCLICK = 1;
		static const uint BUTDOWNCLICK = 2;
		static const uint BUTVIEWCLICK = 3;
		static const uint BUTADDCLICK = 4;
		static const uint BUTSUBCLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyConConMNEquipment)
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
		* StatApp (full: StatAppBrlyConConMNEquipment)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyConConMNEquipment)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTUPAVAIL = 1;
		static const uint BUTUPACTIVE = 2;
		static const uint BUTDOWNAVAIL = 3;
		static const uint BUTDOWNACTIVE = 4;
		static const uint BUTVIEWAVAIL = 5;
		static const uint BUTVIEWACTIVE = 6;
		static const uint BUTADDAVAIL = 7;
		static const uint BUTSUBAVAIL = 8;
		static const uint BUTSUBACTIVE = 9;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
		bool ButViewAvail;
		bool ButViewActive;
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacBrlyConConMNEquipment)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOMREFWIDTH = 1;

	public:
		StgIac(const uint TcoMrefWidth = 100);

	public:
		uint TcoMrefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagBrlyConConMNEquipment)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyConConMNEquipmentData)
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
		QryBrlyConConMNEquipment::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyConConMNEquipmentDo)
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
		* DpchEngData (full: DpchEngBrlyConConMNEquipmentData)
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
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListBrlyQConConMNEquipment* rst = NULL, QryBrlyConConMNEquipment::StatShr* statshrqry = NULL, QryBrlyConConMNEquipment::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListBrlyQConConMNEquipment rst;
		QryBrlyConConMNEquipment::StatShr statshrqry;
		QryBrlyConConMNEquipment::StgIac stgiacqry;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButUpAvail(DbsBrly* dbsbrly);
	bool evalButUpActive(DbsBrly* dbsbrly);
	bool evalButDownAvail(DbsBrly* dbsbrly);
	bool evalButDownActive(DbsBrly* dbsbrly);
	bool evalButViewAvail(DbsBrly* dbsbrly);
	bool evalButViewActive(DbsBrly* dbsbrly);
	bool evalButAddAvail(DbsBrly* dbsbrly);
	bool evalButSubAvail(DbsBrly* dbsbrly);
	bool evalButSubActive(DbsBrly* dbsbrly);

public:
	PnlBrlyConConMNEquipment(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyConConMNEquipment();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;

	QryBrlyConConMNEquipment* qry;

	BrlyLRMConnectionMEquipment recConReqp;

	BrlyMEquipment recEqp;
	uint ixWSubsetEqp;

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
	void handleDpchAppDataStgiacqry(DbsBrly* dbsbrly, QryBrlyConConMNEquipment::StgIac* _stgiacqry, DpchEngBrly** dpcheng);

	void handleDpchAppDoButUpClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButDownClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButAddClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButSubClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleCall(DbsBrly* dbsbrly, Call* call);

	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const ubigint jrefTrig);
};

#endif

