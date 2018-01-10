/**
  * \file IexBrlyTtb.h
  * import/export handler for database DbsBrly (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef IEXBRLYTTB_H
#define IEXBRLYTTB_H

#define VecVIexBrlyTtbIme IexBrlyTtb::VecVIme

#define ImeitemIBrlyTtbMFlight IexBrlyTtb::ImeitemIMFlight
#define ImeIBrlyTtbMFlight IexBrlyTtb::ImeIMFlight
#define VecWImeIBrlyTtbMFlightIel IexBrlyTtb::ImeIMFlight::VecWIel

#define ImeitemIBrlyTtbMLeg IexBrlyTtb::ImeitemIMLeg
#define ImeIBrlyTtbMLeg IexBrlyTtb::ImeIMLeg
#define VecWImeIBrlyTtbMLegIel IexBrlyTtb::ImeIMLeg::VecWIel

/**
	* IexBrlyTtb
	*/
class IexBrlyTtb : public JobBrly {

public:
	/**
		* VecVIme (full: VecVIexBrlyTtbIme)
		*/
	class VecVIme {

	public:
		static const uint IMEIMFLIGHT = 1;
		static const uint IMEIMLEG = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

public:
	/**
		* ImeitemIMFlight (full: ImeitemIBrlyTtbMFlight)
		*/
	class ImeitemIMFlight : public BrlyMFlight {

	public:
		ImeitemIMFlight(const string& hintRefBrlyMEquipment = "", const ubigint irefRefBrlyMLeg = 0, const string& sref = "", const string& hintStart = "", const string& hintStop = "", const string& iDate = "", const string& iWeekday = "");
		ImeitemIMFlight(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hintRefBrlyMEquipment;
		ubigint irefRefBrlyMLeg;
		string hintStart;
		string hintStop;
		string iDate;
		string iWeekday;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFlight (full: ImeIBrlyTtbMFlight)
		*/
	class ImeIMFlight {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyTtbMFlightIel)
			*/
		class VecWIel {

		public:
			static const uint HINTREFBRLYMEQUIPMENT = 1;
			static const uint IREFREFBRLYMLEG = 2;
			static const uint SREF = 4;
			static const uint HINTSTART = 8;
			static const uint HINTSTOP = 16;
			static const uint IDATE = 32;
			static const uint IWEEKDAY = 64;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMFlight();
		~ImeIMFlight();

	public:
		vector<ImeitemIMFlight*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMLeg (full: ImeitemIBrlyTtbMLeg)
		*/
	class ImeitemIMLeg : public BrlyMLeg {

	public:
		ImeitemIMLeg(const ubigint iref = 0, const string& srefBgnRefBrlyMLocation = "", const string& srefEndRefBrlyMLocation = "");
		ImeitemIMLeg(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint iref;
		string srefBgnRefBrlyMLocation;
		string srefEndRefBrlyMLocation;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMLeg (full: ImeIBrlyTtbMLeg)
		*/
	class ImeIMLeg {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyTtbMLegIel)
			*/
		class VecWIel {

		public:
			static const uint IREF = 1;
			static const uint SREFBGNREFBRLYMLOCATION = 2;
			static const uint SREFENDREFBRLYMLOCATION = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMLeg();
		~ImeIMLeg();

	public:
		vector<ImeitemIMLeg*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

public:
	IexBrlyTtb(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~IexBrlyTtb();

public:
	uint lineno;
	uint impcnt;

	ImeIMFlight imeimflight;
	ImeIMLeg imeimleg;

public:
	// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	long dayToDate(int day, int month, int year);
	void dateToDay(long date, int* day, int* month, int* year);
	long dayToIndex(long startd, int day, int month);
	void parseMonthDay(string s, int* month, int* day);
	void sphrToCart(double _r, double _theta, double _phi, double** _vec);
	double degToRad(double _deg);
	double radToDeg(double _rad);
	void locToRad(BrlyMLocation* loc);
	void legToDeg(BrlyMLeg* leg);

	/**
		* IexBrlyTtb::Tofs
		*/
	class Tofs {

	public:
		Tofs(DbsBrly* dbsbrly, BrlyMRegion* reg, const uint startd, const uint stopd, const bool ndstini, const uint dstswd);
		void init(DbsBrly* dbsbrly, vector<Tofs*>& tofss, const uint startd, const uint stopd, const int tm_year, const bool janjun);

		int getTofs(const uint lclt);

	public:
		ubigint ref;
		ubigint supRefBrlyMRegion;
		uint ixVDst;
		int toffset; // double value in database

		bool dstini;
		uint dstswd;
		uint dstswt;
		uint dstsw;

		bool initdone;
	};
	// IP cust --- IEND

public:
	void reset();

	void import(DbsBrly* dbsbrly);

	void collect(DbsBrly* dbsbrly, const map<uint,uint>& icsBrlyVIop = icsBrlyVIopInsAll());

public:
	bool readTxt(Txtrd& txtrd);
	void readXML(xmlXPathContext* docctx, string basexpath);

	bool readTxtFile(const string& fullpath);
	bool readXMLFile(const string& fullpath);

	void writeTxt(fstream& outfile);
	void writeXML(xmlTextWriter* wr, const bool shorttags);

	void writeTxtFile(const string& fullpath);
	void writeXMLFile(const string& fullpath, const bool shorttags);

	static map<uint,uint> icsBrlyVIopInsAll();
	uint getIxBrlyVIop(const map<uint,uint>& icsBrlyVIop, const uint ixVIme, uint& ixBrlyVIop);

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleCall(DbsBrly* dbsbrly, Call* call);
};

#endif


