/**
  * \file BrlyRMFlightMLocation.h
  * database access for table TblBrlyRMFlightMLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYRMFLIGHTMLOCATION_H
#define BRLYRMFLIGHTMLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyRMFlightMLocation: record of TblBrlyRMFlightMLocation
  */
class BrlyRMFlightMLocation {

public:
	BrlyRMFlightMLocation(const ubigint ref = 0, const uint x1VisStart = 0, const uint x1VisStop = 0, const ubigint refBrlyMFlight = 0, const ubigint refBrlyMLocation = 0, const uint xVisStart = 0, const uint xVisStop = 0);

public:
	ubigint ref;
	uint x1VisStart;
	uint x1VisStop;
	ubigint refBrlyMFlight;
	ubigint refBrlyMLocation;
	uint xVisStart;
	uint xVisStop;

public:
	bool operator==(const BrlyRMFlightMLocation& comp);
	bool operator!=(const BrlyRMFlightMLocation& comp);
};

/**
  * ListBrlyRMFlightMLocation: recordset of TblBrlyRMFlightMLocation
  */
class ListBrlyRMFlightMLocation {

public:
	ListBrlyRMFlightMLocation();
	ListBrlyRMFlightMLocation(const ListBrlyRMFlightMLocation& src);
	~ListBrlyRMFlightMLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyRMFlightMLocation* rec);

	BrlyRMFlightMLocation* operator[](const uint ix);
	ListBrlyRMFlightMLocation& operator=(const ListBrlyRMFlightMLocation& src);
	bool operator==(const ListBrlyRMFlightMLocation& comp);
	bool operator!=(const ListBrlyRMFlightMLocation& comp);

public:
	vector<BrlyRMFlightMLocation*> nodes;
};

/**
  * TblBrlyRMFlightMLocation: C++ wrapper for table TblBrlyRMFlightMLocation
  */
class TblBrlyRMFlightMLocation {

public:

public:
	TblBrlyRMFlightMLocation();
	virtual ~TblBrlyRMFlightMLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyRMFlightMLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMFlightMLocation& rst);

	virtual void insertRec(BrlyRMFlightMLocation* rec);
	ubigint insertNewRec(BrlyRMFlightMLocation** rec = NULL, const uint x1VisStart = 0, const uint x1VisStop = 0, const ubigint refBrlyMFlight = 0, const ubigint refBrlyMLocation = 0, const uint xVisStart = 0, const uint xVisStop = 0);
	ubigint appendNewRecToRst(ListBrlyRMFlightMLocation& rst, BrlyRMFlightMLocation** rec = NULL, const uint x1VisStart = 0, const uint x1VisStop = 0, const ubigint refBrlyMFlight = 0, const ubigint refBrlyMLocation = 0, const uint xVisStart = 0, const uint xVisStop = 0);
	virtual void insertRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	virtual void updateRec(BrlyRMFlightMLocation* rec);
	virtual void updateRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyRMFlightMLocation** rec);
	virtual ubigint loadRstByFlt(ubigint refBrlyMFlight, const bool append, ListBrlyRMFlightMLocation& rst);
	virtual ubigint loadRstByLoc(ubigint refBrlyMLocation, const bool append, ListBrlyRMFlightMLocation& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyRMFlightMLocation& rst);
};

/**
  * MyBrlyRMFlightMLocation: C++ wrapper for table TblBrlyRMFlightMLocation (MySQL database)
  */
class MyTblBrlyRMFlightMLocation : public TblBrlyRMFlightMLocation, public MyTable {

public:
	MyTblBrlyRMFlightMLocation();
	~MyTblBrlyRMFlightMLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMFlightMLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMFlightMLocation& rst);

	void insertRec(BrlyRMFlightMLocation* rec);
	void insertRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	void updateRec(BrlyRMFlightMLocation* rec);
	void updateRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMFlightMLocation** rec);
	ubigint loadRstByFlt(ubigint refBrlyMFlight, const bool append, ListBrlyRMFlightMLocation& rst);
	ubigint loadRstByLoc(ubigint refBrlyMLocation, const bool append, ListBrlyRMFlightMLocation& rst);
};

/**
  * PgBrlyRMFlightMLocation: C++ wrapper for table TblBrlyRMFlightMLocation (PgSQL database)
  */
class PgTblBrlyRMFlightMLocation : public TblBrlyRMFlightMLocation, public PgTable {

public:
	PgTblBrlyRMFlightMLocation();
	~PgTblBrlyRMFlightMLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMFlightMLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyRMFlightMLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMFlightMLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMFlightMLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMFlightMLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMFlightMLocation& rst);

	void insertRec(BrlyRMFlightMLocation* rec);
	void insertRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	void updateRec(BrlyRMFlightMLocation* rec);
	void updateRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMFlightMLocation** rec);
	ubigint loadRstByFlt(ubigint refBrlyMFlight, const bool append, ListBrlyRMFlightMLocation& rst);
	ubigint loadRstByLoc(ubigint refBrlyMLocation, const bool append, ListBrlyRMFlightMLocation& rst);
};

#endif

