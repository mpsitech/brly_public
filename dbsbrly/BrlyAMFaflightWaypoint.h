/**
  * \file BrlyAMFaflightWaypoint.h
  * database access for table TblBrlyAMFaflightWaypoint (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYAMFAFLIGHTWAYPOINT_H
#define BRLYAMFAFLIGHTWAYPOINT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyAMFaflightWaypoint: record of TblBrlyAMFaflightWaypoint
  */
class BrlyAMFaflightWaypoint {

public:
	BrlyAMFaflightWaypoint(const ubigint ref = 0, const ubigint fafRefBrlyMFaflight = 0, const uint fafNum = 0, const uint timestamp = 0, const double latitude = 0.0, const double longitude = 0.0, const usmallint groundspeed = 0, const usmallint altitude = 0, const string altitudeStatus = "", const string updateType = "", const string altitudeChange = "");

public:
	ubigint ref;
	ubigint fafRefBrlyMFaflight;
	uint fafNum;
	uint timestamp;
	double latitude;
	double longitude;
	usmallint groundspeed;
	usmallint altitude;
	string altitudeStatus;
	string updateType;
	string altitudeChange;

public:
	bool operator==(const BrlyAMFaflightWaypoint& comp);
	bool operator!=(const BrlyAMFaflightWaypoint& comp);
};

/**
  * ListBrlyAMFaflightWaypoint: recordset of TblBrlyAMFaflightWaypoint
  */
class ListBrlyAMFaflightWaypoint {

public:
	ListBrlyAMFaflightWaypoint();
	ListBrlyAMFaflightWaypoint(const ListBrlyAMFaflightWaypoint& src);
	~ListBrlyAMFaflightWaypoint();

	void clear();
	unsigned int size() const;
	void append(BrlyAMFaflightWaypoint* rec);

	BrlyAMFaflightWaypoint* operator[](const uint ix);
	ListBrlyAMFaflightWaypoint& operator=(const ListBrlyAMFaflightWaypoint& src);
	bool operator==(const ListBrlyAMFaflightWaypoint& comp);
	bool operator!=(const ListBrlyAMFaflightWaypoint& comp);

public:
	vector<BrlyAMFaflightWaypoint*> nodes;
};

/**
  * TblBrlyAMFaflightWaypoint: C++ wrapper for table TblBrlyAMFaflightWaypoint
  */
class TblBrlyAMFaflightWaypoint {

public:

public:
	TblBrlyAMFaflightWaypoint();
	virtual ~TblBrlyAMFaflightWaypoint();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyAMFaflightWaypoint** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMFaflightWaypoint& rst);

	virtual void insertRec(BrlyAMFaflightWaypoint* rec);
	ubigint insertNewRec(BrlyAMFaflightWaypoint** rec = NULL, const ubigint fafRefBrlyMFaflight = 0, const uint fafNum = 0, const uint timestamp = 0, const double latitude = 0.0, const double longitude = 0.0, const usmallint groundspeed = 0, const usmallint altitude = 0, const string altitudeStatus = "", const string updateType = "", const string altitudeChange = "");
	ubigint appendNewRecToRst(ListBrlyAMFaflightWaypoint& rst, BrlyAMFaflightWaypoint** rec = NULL, const ubigint fafRefBrlyMFaflight = 0, const uint fafNum = 0, const uint timestamp = 0, const double latitude = 0.0, const double longitude = 0.0, const usmallint groundspeed = 0, const usmallint altitude = 0, const string altitudeStatus = "", const string updateType = "", const string altitudeChange = "");
	virtual void insertRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	virtual void updateRec(BrlyAMFaflightWaypoint* rec);
	virtual void updateRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyAMFaflightWaypoint** rec);
	virtual ubigint loadRefsByFaf(ubigint fafRefBrlyMFaflight, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByFaf(ubigint fafRefBrlyMFaflight, const bool append, ListBrlyAMFaflightWaypoint& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyAMFaflightWaypoint& rst);
};

/**
  * MyBrlyAMFaflightWaypoint: C++ wrapper for table TblBrlyAMFaflightWaypoint (MySQL database)
  */
class MyTblBrlyAMFaflightWaypoint : public TblBrlyAMFaflightWaypoint, public MyTable {

public:
	MyTblBrlyAMFaflightWaypoint();
	~MyTblBrlyAMFaflightWaypoint();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAMFaflightWaypoint** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMFaflightWaypoint& rst);

	void insertRec(BrlyAMFaflightWaypoint* rec);
	void insertRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	void updateRec(BrlyAMFaflightWaypoint* rec);
	void updateRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAMFaflightWaypoint** rec);
	ubigint loadRefsByFaf(ubigint fafRefBrlyMFaflight, const bool append, vector<ubigint>& refs);
	ubigint loadRstByFaf(ubigint fafRefBrlyMFaflight, const bool append, ListBrlyAMFaflightWaypoint& rst);
};

/**
  * PgBrlyAMFaflightWaypoint: C++ wrapper for table TblBrlyAMFaflightWaypoint (PgSQL database)
  */
class PgTblBrlyAMFaflightWaypoint : public TblBrlyAMFaflightWaypoint, public PgTable {

public:
	PgTblBrlyAMFaflightWaypoint();
	~PgTblBrlyAMFaflightWaypoint();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAMFaflightWaypoint** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyAMFaflightWaypoint& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAMFaflightWaypoint** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAMFaflightWaypoint& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAMFaflightWaypoint** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMFaflightWaypoint& rst);

	void insertRec(BrlyAMFaflightWaypoint* rec);
	void insertRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	void updateRec(BrlyAMFaflightWaypoint* rec);
	void updateRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAMFaflightWaypoint** rec);
	ubigint loadRefsByFaf(ubigint fafRefBrlyMFaflight, const bool append, vector<ubigint>& refs);
	ubigint loadRstByFaf(ubigint fafRefBrlyMFaflight, const bool append, ListBrlyAMFaflightWaypoint& rst);
};

#endif

