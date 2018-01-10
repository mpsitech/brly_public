/**
  * \file BrlyMFaflight.h
  * database access for table TblBrlyMFaflight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMFAFLIGHT_H
#define BRLYMFAFLIGHT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyMFaflight: record of TblBrlyMFaflight
  */
class BrlyMFaflight {

public:
	BrlyMFaflight(const ubigint ref = 0, const ubigint refBrlyMFlight = 0, const string faFlightID = "", const string ident = "", const string aircrafttype = "", const string filed_ete = "", const uint filed_time = 0, const uint filed_departuretime = 0, const usmallint filed_airspeed_kts = 0, const double filed_airspeed_mach = 0.0, const usmallint filed_altitude = 0, const string route = "", const uint actualdeparturetime = 0, const uint estimatedarrivaltime = 0, const uint actualarrivaltime = 0, const string diverted = "", const string origin = "", const string destination = "", const string originName = "", const string originCity = "", const string destinationName = "", const string destinationCity = "");

public:
	ubigint ref;
	ubigint refBrlyMFlight;
	string faFlightID;
	string ident;
	string aircrafttype;
	string filed_ete;
	uint filed_time;
	uint filed_departuretime;
	usmallint filed_airspeed_kts;
	double filed_airspeed_mach;
	usmallint filed_altitude;
	string route;
	uint actualdeparturetime;
	uint estimatedarrivaltime;
	uint actualarrivaltime;
	string diverted;
	string origin;
	string destination;
	string originName;
	string originCity;
	string destinationName;
	string destinationCity;

public:
	bool operator==(const BrlyMFaflight& comp);
	bool operator!=(const BrlyMFaflight& comp);
};

/**
  * ListBrlyMFaflight: recordset of TblBrlyMFaflight
  */
class ListBrlyMFaflight {

public:
	ListBrlyMFaflight();
	ListBrlyMFaflight(const ListBrlyMFaflight& src);
	~ListBrlyMFaflight();

	void clear();
	unsigned int size() const;
	void append(BrlyMFaflight* rec);

	BrlyMFaflight* operator[](const uint ix);
	ListBrlyMFaflight& operator=(const ListBrlyMFaflight& src);
	bool operator==(const ListBrlyMFaflight& comp);
	bool operator!=(const ListBrlyMFaflight& comp);

public:
	vector<BrlyMFaflight*> nodes;
};

/**
  * TblBrlyMFaflight: C++ wrapper for table TblBrlyMFaflight
  */
class TblBrlyMFaflight {

public:

public:
	TblBrlyMFaflight();
	virtual ~TblBrlyMFaflight();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMFaflight** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMFaflight& rst);

	virtual void insertRec(BrlyMFaflight* rec);
	ubigint insertNewRec(BrlyMFaflight** rec = NULL, const ubigint refBrlyMFlight = 0, const string faFlightID = "", const string ident = "", const string aircrafttype = "", const string filed_ete = "", const uint filed_time = 0, const uint filed_departuretime = 0, const usmallint filed_airspeed_kts = 0, const double filed_airspeed_mach = 0.0, const usmallint filed_altitude = 0, const string route = "", const uint actualdeparturetime = 0, const uint estimatedarrivaltime = 0, const uint actualarrivaltime = 0, const string diverted = "", const string origin = "", const string destination = "", const string originName = "", const string originCity = "", const string destinationName = "", const string destinationCity = "");
	ubigint appendNewRecToRst(ListBrlyMFaflight& rst, BrlyMFaflight** rec = NULL, const ubigint refBrlyMFlight = 0, const string faFlightID = "", const string ident = "", const string aircrafttype = "", const string filed_ete = "", const uint filed_time = 0, const uint filed_departuretime = 0, const usmallint filed_airspeed_kts = 0, const double filed_airspeed_mach = 0.0, const usmallint filed_altitude = 0, const string route = "", const uint actualdeparturetime = 0, const uint estimatedarrivaltime = 0, const uint actualarrivaltime = 0, const string diverted = "", const string origin = "", const string destination = "", const string originName = "", const string originCity = "", const string destinationName = "", const string destinationCity = "");
	virtual void insertRst(ListBrlyMFaflight& rst, bool transact = false);
	virtual void updateRec(BrlyMFaflight* rec);
	virtual void updateRst(ListBrlyMFaflight& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMFaflight** rec);
	virtual bool loadFidByRef(ubigint ref, string& faFlightID);
	virtual bool loadRecByFlt(ubigint refBrlyMFlight, BrlyMFaflight** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMFaflight& rst);
};

/**
  * MyBrlyMFaflight: C++ wrapper for table TblBrlyMFaflight (MySQL database)
  */
class MyTblBrlyMFaflight : public TblBrlyMFaflight, public MyTable {

public:
	MyTblBrlyMFaflight();
	~MyTblBrlyMFaflight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMFaflight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMFaflight& rst);

	void insertRec(BrlyMFaflight* rec);
	void insertRst(ListBrlyMFaflight& rst, bool transact = false);
	void updateRec(BrlyMFaflight* rec);
	void updateRst(ListBrlyMFaflight& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMFaflight** rec);
	bool loadFidByRef(ubigint ref, string& faFlightID);
	bool loadRecByFlt(ubigint refBrlyMFlight, BrlyMFaflight** rec);
};

/**
  * PgBrlyMFaflight: C++ wrapper for table TblBrlyMFaflight (PgSQL database)
  */
class PgTblBrlyMFaflight : public TblBrlyMFaflight, public PgTable {

public:
	PgTblBrlyMFaflight();
	~PgTblBrlyMFaflight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMFaflight** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMFaflight& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMFaflight** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMFaflight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMFaflight& rst);

	void insertRec(BrlyMFaflight* rec);
	void insertRst(ListBrlyMFaflight& rst, bool transact = false);
	void updateRec(BrlyMFaflight* rec);
	void updateRst(ListBrlyMFaflight& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMFaflight** rec);
	bool loadFidByRef(ubigint ref, string& faFlightID);
	bool loadRecByFlt(ubigint refBrlyMFlight, BrlyMFaflight** rec);
};

#endif

