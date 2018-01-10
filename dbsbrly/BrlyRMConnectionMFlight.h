/**
  * \file BrlyRMConnectionMFlight.h
  * database access for table TblBrlyRMConnectionMFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYRMCONNECTIONMFLIGHT_H
#define BRLYRMCONNECTIONMFLIGHT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyRMConnectionMFlight: record of TblBrlyRMConnectionMFlight
  */
class BrlyRMConnectionMFlight {

public:
	BrlyRMConnectionMFlight(const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const ubigint refBrlyMConnection = 0, const ubigint refBrlyMFlight = 0);

public:
	ubigint ref;
	uint x1Start;
	uint x1Stop;
	double x2Legphi0;
	double x2Legphi1;
	ubigint refBrlyMConnection;
	ubigint refBrlyMFlight;

public:
	bool operator==(const BrlyRMConnectionMFlight& comp);
	bool operator!=(const BrlyRMConnectionMFlight& comp);
};

/**
  * ListBrlyRMConnectionMFlight: recordset of TblBrlyRMConnectionMFlight
  */
class ListBrlyRMConnectionMFlight {

public:
	ListBrlyRMConnectionMFlight();
	ListBrlyRMConnectionMFlight(const ListBrlyRMConnectionMFlight& src);
	~ListBrlyRMConnectionMFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyRMConnectionMFlight* rec);

	BrlyRMConnectionMFlight* operator[](const uint ix);
	ListBrlyRMConnectionMFlight& operator=(const ListBrlyRMConnectionMFlight& src);
	bool operator==(const ListBrlyRMConnectionMFlight& comp);
	bool operator!=(const ListBrlyRMConnectionMFlight& comp);

public:
	vector<BrlyRMConnectionMFlight*> nodes;
};

/**
  * TblBrlyRMConnectionMFlight: C++ wrapper for table TblBrlyRMConnectionMFlight
  */
class TblBrlyRMConnectionMFlight {

public:

public:
	TblBrlyRMConnectionMFlight();
	virtual ~TblBrlyRMConnectionMFlight();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyRMConnectionMFlight** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMConnectionMFlight& rst);

	virtual void insertRec(BrlyRMConnectionMFlight* rec);
	ubigint insertNewRec(BrlyRMConnectionMFlight** rec = NULL, const uint x1Start = 0, const uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const ubigint refBrlyMConnection = 0, const ubigint refBrlyMFlight = 0);
	ubigint appendNewRecToRst(ListBrlyRMConnectionMFlight& rst, BrlyRMConnectionMFlight** rec = NULL, const uint x1Start = 0, const uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const ubigint refBrlyMConnection = 0, const ubigint refBrlyMFlight = 0);
	virtual void insertRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	virtual void updateRec(BrlyRMConnectionMFlight* rec);
	virtual void updateRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyRMConnectionMFlight** rec);
	virtual ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMFlight& rst);
	virtual ubigint loadRstByFlt(ubigint refBrlyMFlight, const bool append, ListBrlyRMConnectionMFlight& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyRMConnectionMFlight& rst);
};

/**
  * MyBrlyRMConnectionMFlight: C++ wrapper for table TblBrlyRMConnectionMFlight (MySQL database)
  */
class MyTblBrlyRMConnectionMFlight : public TblBrlyRMConnectionMFlight, public MyTable {

public:
	MyTblBrlyRMConnectionMFlight();
	~MyTblBrlyRMConnectionMFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMConnectionMFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMConnectionMFlight& rst);

	void insertRec(BrlyRMConnectionMFlight* rec);
	void insertRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	void updateRec(BrlyRMConnectionMFlight* rec);
	void updateRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMConnectionMFlight** rec);
	ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMFlight& rst);
	ubigint loadRstByFlt(ubigint refBrlyMFlight, const bool append, ListBrlyRMConnectionMFlight& rst);
};

/**
  * PgBrlyRMConnectionMFlight: C++ wrapper for table TblBrlyRMConnectionMFlight (PgSQL database)
  */
class PgTblBrlyRMConnectionMFlight : public TblBrlyRMConnectionMFlight, public PgTable {

public:
	PgTblBrlyRMConnectionMFlight();
	~PgTblBrlyRMConnectionMFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMConnectionMFlight** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyRMConnectionMFlight& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMConnectionMFlight** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMConnectionMFlight& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMConnectionMFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMConnectionMFlight& rst);

	void insertRec(BrlyRMConnectionMFlight* rec);
	void insertRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	void updateRec(BrlyRMConnectionMFlight* rec);
	void updateRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMConnectionMFlight** rec);
	ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMFlight& rst);
	ubigint loadRstByFlt(ubigint refBrlyMFlight, const bool append, ListBrlyRMConnectionMFlight& rst);
};

#endif

