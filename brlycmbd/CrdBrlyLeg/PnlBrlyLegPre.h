/**
  * \file PnlBrlyLegPre.h
  * job handler for job PnlBrlyLegPre (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLEGPRE_H
#define PNLBRLYLEGPRE_H

// IP custInclude --- INSERT

#define ContIacBrlyLegPre PnlBrlyLegPre::ContIac
#define StatAppBrlyLegPre PnlBrlyLegPre::StatApp
#define StatShrBrlyLegPre PnlBrlyLegPre::StatShr
#define TagBrlyLegPre PnlBrlyLegPre::Tag

#define DpchAppBrlyLegPreData PnlBrlyLegPre::DpchAppData
#define DpchEngBrlyLegPreData PnlBrlyLegPre::DpchEngData

/**
  * PnlBrlyLegPre
  */
class PnlBrlyLegPre : public JobBrly {

public:
	/**
	  * ContIac (full: ContIacBrlyLegPre)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDPHI = 1;

	public:
		ContIac(const double SldPhi = 0.0);

	public:
		double SldPhi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppBrlyLegPre)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyLegPre)
		*/
	class StatShr : public Block {

	public:
		static const uint SLDPHIMIN = 1;
		static const uint SLDPHIMAX = 2;

	public:
		StatShr(const double SldPhiMin = 0.0, const double SldPhiMax = 1.0);

	public:
		double SldPhiMin;
		double SldPhiMax;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyLegPre)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLegPreData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngBrlyLegPreData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;
		static const uint ALL = 6;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const uint ixBrlyVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	PnlBrlyLegPre(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyLegPre();

public:
	ContIac contiac;
	StatShr statshr;

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
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

};

#endif

