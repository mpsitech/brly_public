/**
  * \file BrlyRMConnectionMSegment.h
  * database access for table TblBrlyRMConnectionMSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYRMCONNECTIONMSEGMENT_H
#define BRLYRMCONNECTIONMSEGMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyRMConnectionMSegment: record of TblBrlyRMConnectionMSegment
  */
class BrlyRMConnectionMSegment {

public:
	BrlyRMConnectionMSegment(const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const ubigint refBrlyMConnection = 0, const ubigint refBrlyMSegment = 0);

public:
	ubigint ref;
	uint x1Start;
	uint x1Stop;
	double x2Legphi0;
	double x2Legphi1;
	ubigint refBrlyMConnection;
	ubigint refBrlyMSegment;

public:
	bool operator==(const BrlyRMConnectionMSegment& comp);
	bool operator!=(const BrlyRMConnectionMSegment& comp);
};

/**
  * ListBrlyRMConnectionMSegment: recordset of TblBrlyRMConnectionMSegment
  */
class ListBrlyRMConnectionMSegment {

public:
	ListBrlyRMConnectionMSegment();
	ListBrlyRMConnectionMSegment(const ListBrlyRMConnectionMSegment& src);
	~ListBrlyRMConnectionMSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyRMConnectionMSegment* rec);

	BrlyRMConnectionMSegment* operator[](const uint ix);
	ListBrlyRMConnectionMSegment& operator=(const ListBrlyRMConnectionMSegment& src);
	bool operator==(const ListBrlyRMConnectionMSegment& comp);
	bool operator!=(const ListBrlyRMConnectionMSegment& comp);

public:
	vector<BrlyRMConnectionMSegment*> nodes;
};

/**
  * TblBrlyRMConnectionMSegment: C++ wrapper for table TblBrlyRMConnectionMSegment
  */
class TblBrlyRMConnectionMSegment {

public:

public:
	TblBrlyRMConnectionMSegment();
	virtual ~TblBrlyRMConnectionMSegment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyRMConnectionMSegment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMConnectionMSegment& rst);

	virtual void insertRec(BrlyRMConnectionMSegment* rec);
	ubigint insertNewRec(BrlyRMConnectionMSegment** rec = NULL, const uint x1Start = 0, const uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const ubigint refBrlyMConnection = 0, const ubigint refBrlyMSegment = 0);
	ubigint appendNewRecToRst(ListBrlyRMConnectionMSegment& rst, BrlyRMConnectionMSegment** rec = NULL, const uint x1Start = 0, const uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const ubigint refBrlyMConnection = 0, const ubigint refBrlyMSegment = 0);
	virtual void insertRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	virtual void updateRec(BrlyRMConnectionMSegment* rec);
	virtual void updateRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyRMConnectionMSegment** rec);
	virtual ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMSegment& rst);
	virtual ubigint loadRstBySeg(ubigint refBrlyMSegment, const bool append, ListBrlyRMConnectionMSegment& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyRMConnectionMSegment& rst);
};

/**
  * MyBrlyRMConnectionMSegment: C++ wrapper for table TblBrlyRMConnectionMSegment (MySQL database)
  */
class MyTblBrlyRMConnectionMSegment : public TblBrlyRMConnectionMSegment, public MyTable {

public:
	MyTblBrlyRMConnectionMSegment();
	~MyTblBrlyRMConnectionMSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMConnectionMSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMConnectionMSegment& rst);

	void insertRec(BrlyRMConnectionMSegment* rec);
	void insertRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	void updateRec(BrlyRMConnectionMSegment* rec);
	void updateRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMConnectionMSegment** rec);
	ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMSegment& rst);
	ubigint loadRstBySeg(ubigint refBrlyMSegment, const bool append, ListBrlyRMConnectionMSegment& rst);
};

/**
  * PgBrlyRMConnectionMSegment: C++ wrapper for table TblBrlyRMConnectionMSegment (PgSQL database)
  */
class PgTblBrlyRMConnectionMSegment : public TblBrlyRMConnectionMSegment, public PgTable {

public:
	PgTblBrlyRMConnectionMSegment();
	~PgTblBrlyRMConnectionMSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMConnectionMSegment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyRMConnectionMSegment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMConnectionMSegment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMConnectionMSegment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMConnectionMSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMConnectionMSegment& rst);

	void insertRec(BrlyRMConnectionMSegment* rec);
	void insertRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	void updateRec(BrlyRMConnectionMSegment* rec);
	void updateRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMConnectionMSegment** rec);
	ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMSegment& rst);
	ubigint loadRstBySeg(ubigint refBrlyMSegment, const bool append, ListBrlyRMConnectionMSegment& rst);
};

#endif

