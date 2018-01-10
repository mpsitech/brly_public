/**
  * \file IexBrlyFlt.h
  * import/export handler for database DbsBrly (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef IEXBRLYFLT_H
#define IEXBRLYFLT_H

#define VecVIexBrlyFltIme IexBrlyFlt::VecVIme

#define ImeitemIBrlyFltAMFaflightWaypoint IexBrlyFlt::ImeitemIAMFaflightWaypoint
#define ImeIBrlyFltAMFaflightWaypoint IexBrlyFlt::ImeIAMFaflightWaypoint
#define VecWImeIBrlyFltAMFaflightWaypointIel IexBrlyFlt::ImeIAMFaflightWaypoint::VecWIel

#define ImeitemIBrlyFltMFaflight IexBrlyFlt::ImeitemIMFaflight
#define ImeIBrlyFltMFaflight IexBrlyFlt::ImeIMFaflight
#define VecWImeIBrlyFltMFaflightIel IexBrlyFlt::ImeIMFaflight::VecWIel

/**
	* IexBrlyFlt
	*/
class IexBrlyFlt : public JobBrly {

public:
	/**
		* VecVIme (full: VecVIexBrlyFltIme)
		*/
	class VecVIme {

	public:
		static const uint IMEIMFAFLIGHT = 1;
		static const uint IMEIAMFAFLIGHTWAYPOINT = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

public:
	/**
		* ImeitemIAMFaflightWaypoint (full: ImeitemIBrlyFltAMFaflightWaypoint)
		*/
	class ImeitemIAMFaflightWaypoint : public BrlyAMFaflightWaypoint {

	public:
		ImeitemIAMFaflightWaypoint(const uint timestamp = 0, const double latitude = 0.0, const double longitude = 0.0, const usmallint groundspeed = 0, const usmallint altitude = 0, const string& altitudeStatus = "", const string& updateType = "", const string& altitudeChange = "");
		ImeitemIAMFaflightWaypoint(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMFaflightWaypoint (full: ImeIBrlyFltAMFaflightWaypoint)
		*/
	class ImeIAMFaflightWaypoint {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyFltAMFaflightWaypointIel)
			*/
		class VecWIel {

		public:
			static const uint TIMESTAMP = 1;
			static const uint LATITUDE = 2;
			static const uint LONGITUDE = 4;
			static const uint GROUNDSPEED = 8;
			static const uint ALTITUDE = 16;
			static const uint ALTITUDESTATUS = 32;
			static const uint UPDATETYPE = 64;
			static const uint ALTITUDECHANGE = 128;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMFaflightWaypoint();
		~ImeIAMFaflightWaypoint();

	public:
		vector<ImeitemIAMFaflightWaypoint*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFaflight (full: ImeitemIBrlyFltMFaflight)
		*/
	class ImeitemIMFaflight : public BrlyMFaflight {

	public:
		ImeitemIMFaflight(const uint ixBrlyVIop = 0, const string& iLeg = "", const string& hintRefBrlyMFlight = "", const string& faFlightID = "", const string& ident = "", const string& aircrafttype = "", const string& filed_ete = "", const uint filed_time = 0, const uint filed_departuretime = 0, const usmallint filed_airspeed_kts = 0, const double filed_airspeed_mach = 0.0, const usmallint filed_altitude = 0, const string& route = "", const uint actualdeparturetime = 0, const uint estimatedarrivaltime = 0, const uint actualarrivaltime = 0, const string& diverted = "", const string& origin = "", const string& destination = "", const string& originName = "", const string& originCity = "", const string& destinationName = "", const string& destinationCity = "");
		ImeitemIMFaflight(DbsBrly* dbsbrly, const uint ixBrlyVIop, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		uint ixBrlyVIop;
		string iLeg;
		string hintRefBrlyMFlight;

		ImeIAMFaflightWaypoint imeiamfaflightwaypoint;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFaflight (full: ImeIBrlyFltMFaflight)
		*/
	class ImeIMFaflight {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyFltMFaflightIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXBRLYVIOP = 1;
			static const uint ILEG = 2;
			static const uint HINTREFBRLYMFLIGHT = 4;
			static const uint FAFLIGHTID = 8;
			static const uint IDENT = 16;
			static const uint AIRCRAFTTYPE = 32;
			static const uint FILED_ETE = 64;
			static const uint FILED_TIME = 128;
			static const uint FILED_DEPARTURETIME = 256;
			static const uint FILED_AIRSPEED_KTS = 512;
			static const uint FILED_AIRSPEED_MACH = 1024;
			static const uint FILED_ALTITUDE = 2048;
			static const uint ROUTE = 4096;
			static const uint ACTUALDEPARTURETIME = 8192;
			static const uint ESTIMATEDARRIVALTIME = 16384;
			static const uint ACTUALARRIVALTIME = 32768;
			static const uint DIVERTED = 65536;
			static const uint ORIGIN = 131072;
			static const uint DESTINATION = 262144;
			static const uint ORIGINNAME = 524288;
			static const uint ORIGINCITY = 1048576;
			static const uint DESTINATIONNAME = 2097152;
			static const uint DESTINATIONCITY = 4194304;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMFaflight();
		~ImeIMFaflight();

	public:
		vector<ImeitemIMFaflight*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

public:
	IexBrlyFlt(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~IexBrlyFlt();

public:
	uint lineno;
	uint impcnt;

	ImeIMFaflight imeimfaflight;

public:
	// IP cust --- INSERT

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

