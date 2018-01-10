/**
  * \file BrlyQFltFafAWaypoint.h
  * Dbs and XML wrapper for table TblBrlyQFltFafAWaypoint (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTFAFAWAYPOINT_H
#define BRLYQFLTFAFAWAYPOINT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltFafAWaypoint: record of TblBrlyQFltFafAWaypoint
  */
class BrlyQFltFafAWaypoint {

public:
	BrlyQFltFafAWaypoint(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint fafNum = 0, const uint timestamp = 0, const string ftmTimestamp = "", const double latitude = 0.0, const double longitude = 0.0, const usmallint groundspeed = 0, const usmallint altitude = 0, const string altitudeStatus = "", const string updateType = "", const string altitudeChange = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint fafNum;
	uint timestamp;
	string ftmTimestamp;
	double latitude;
	double longitude;
	usmallint groundspeed;
	usmallint altitude;
	string altitudeStatus;
	string updateType;
	string altitudeChange;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQFltFafAWaypoint: recordset of TblBrlyQFltFafAWaypoint
  */
class ListBrlyQFltFafAWaypoint {

public:
	ListBrlyQFltFafAWaypoint();
	ListBrlyQFltFafAWaypoint(const ListBrlyQFltFafAWaypoint& src);
	~ListBrlyQFltFafAWaypoint();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltFafAWaypoint* rec);

	ListBrlyQFltFafAWaypoint& operator=(const ListBrlyQFltFafAWaypoint& src);

public:
	vector<BrlyQFltFafAWaypoint*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQFltFafAWaypoint: C++ wrapper for table TblBrlyQFltFafAWaypoint
  */
class TblBrlyQFltFafAWaypoint {

public:
	TblBrlyQFltFafAWaypoint();
	virtual ~TblBrlyQFltFafAWaypoint();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQFltFafAWaypoint** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltFafAWaypoint& rst);

	virtual void insertRec(BrlyQFltFafAWaypoint* rec);
	ubigint insertNewRec(BrlyQFltFafAWaypoint** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint fafNum = 0, const uint timestamp = 0, const string ftmTimestamp = "", const double latitude = 0.0, const double longitude = 0.0, const usmallint groundspeed = 0, const usmallint altitude = 0, const string altitudeStatus = "", const string updateType = "", const string altitudeChange = "");
	ubigint appendNewRecToRst(ListBrlyQFltFafAWaypoint& rst, BrlyQFltFafAWaypoint** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint fafNum = 0, const uint timestamp = 0, const string ftmTimestamp = "", const double latitude = 0.0, const double longitude = 0.0, const usmallint groundspeed = 0, const usmallint altitude = 0, const string altitudeStatus = "", const string updateType = "", const string altitudeChange = "");
	virtual void insertRst(ListBrlyQFltFafAWaypoint& rst);
	virtual void updateRec(BrlyQFltFafAWaypoint* rec);
	virtual void updateRst(ListBrlyQFltFafAWaypoint& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQFltFafAWaypoint** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltFafAWaypoint& rst);
};

/**
  * MyBrlyQFltFafAWaypoint: C++ wrapper for table TblBrlyQFltFafAWaypoint (MySQL database)
  */
class MyTblBrlyQFltFafAWaypoint : public TblBrlyQFltFafAWaypoint, public MyTable {

public:
	MyTblBrlyQFltFafAWaypoint();
	~MyTblBrlyQFltFafAWaypoint();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltFafAWaypoint** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltFafAWaypoint& rst);

	void insertRec(BrlyQFltFafAWaypoint* rec);
	void insertRst(ListBrlyQFltFafAWaypoint& rst);
	void updateRec(BrlyQFltFafAWaypoint* rec);
	void updateRst(ListBrlyQFltFafAWaypoint& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltFafAWaypoint** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltFafAWaypoint& rst);
};

/**
  * PgBrlyQFltFafAWaypoint: C++ wrapper for table TblBrlyQFltFafAWaypoint (PgSQL database)
  */
class PgTblBrlyQFltFafAWaypoint : public TblBrlyQFltFafAWaypoint, public PgTable {

public:
	PgTblBrlyQFltFafAWaypoint();
	~PgTblBrlyQFltFafAWaypoint();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltFafAWaypoint** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltFafAWaypoint& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltFafAWaypoint** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltFafAWaypoint& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltFafAWaypoint** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltFafAWaypoint& rst);

	void insertRec(BrlyQFltFafAWaypoint* rec);
	void insertRst(ListBrlyQFltFafAWaypoint& rst);
	void updateRec(BrlyQFltFafAWaypoint* rec);
	void updateRst(ListBrlyQFltFafAWaypoint& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltFafAWaypoint** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltFafAWaypoint& rst);
};

#endif

