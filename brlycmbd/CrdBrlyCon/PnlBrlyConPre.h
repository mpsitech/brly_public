/**
  * \file PnlBrlyConPre.h
  * job handler for job PnlBrlyConPre (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYCONPRE_H
#define PNLBRLYCONPRE_H

// IP custInclude --- INSERT

#define ContIacBrlyConPre PnlBrlyConPre::ContIac
#define StatAppBrlyConPre PnlBrlyConPre::StatApp
#define StatShrBrlyConPre PnlBrlyConPre::StatShr
#define TagBrlyConPre PnlBrlyConPre::Tag

#define DpchAppBrlyConPreData PnlBrlyConPre::DpchAppData
#define DpchEngBrlyConPreData PnlBrlyConPre::DpchEngData

/**
  * PnlBrlyConPre
  */
class PnlBrlyConPre : public JobBrly {

public:
	/**
	  * ContIac (full: ContIacBrlyConPre)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDTME = 1;
		static const uint SLDPHI = 2;

	public:
		ContIac(const double SldTme = 0.0, const double SldPhi = 0.0);

	public:
		double SldTme;
		double SldPhi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppBrlyConPre)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyConPre)
		*/
	class StatShr : public Block {

	public:
		static const uint SLDTMEMIN = 1;
		static const uint SLDTMEMAX = 2;
		static const uint SLDPHIMIN = 3;
		static const uint SLDPHIMAX = 4;

	public:
		StatShr(const double SldTmeMin = 0.0, const double SldTmeMax = 1.0, const double SldPhiMin = 0.0, const double SldPhiMax = 1.0);

	public:
		double SldTmeMin;
		double SldTmeMax;
		double SldPhiMin;
		double SldPhiMax;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyConPre)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixBrlyVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyConPreData)
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
		* DpchEngData (full: DpchEngBrlyConPreData)
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
	PnlBrlyConPre(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~PnlBrlyConPre();

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

