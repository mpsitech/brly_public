/**
  * \file BrlyMSession.h
  * database access for table TblBrlyMSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMSESSION_H
#define BRLYMSESSION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyMSession: record of TblBrlyMSession
  */
class BrlyMSession {

public:
	BrlyMSession(const ubigint ref = 0, const ubigint refBrlyMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");

public:
	ubigint ref;
	ubigint refBrlyMUser;
	uint start;
	uint stop;
	string Ip;

public:
	bool operator==(const BrlyMSession& comp);
	bool operator!=(const BrlyMSession& comp);
};

/**
  * ListBrlyMSession: recordset of TblBrlyMSession
  */
class ListBrlyMSession {

public:
	ListBrlyMSession();
	ListBrlyMSession(const ListBrlyMSession& src);
	~ListBrlyMSession();

	void clear();
	unsigned int size() const;
	void append(BrlyMSession* rec);

	BrlyMSession* operator[](const uint ix);
	ListBrlyMSession& operator=(const ListBrlyMSession& src);
	bool operator==(const ListBrlyMSession& comp);
	bool operator!=(const ListBrlyMSession& comp);

public:
	vector<BrlyMSession*> nodes;
};

/**
  * TblBrlyMSession: C++ wrapper for table TblBrlyMSession
  */
class TblBrlyMSession {

public:

public:
	TblBrlyMSession();
	virtual ~TblBrlyMSession();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMSession** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMSession& rst);

	virtual void insertRec(BrlyMSession* rec);
	ubigint insertNewRec(BrlyMSession** rec = NULL, const ubigint refBrlyMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");
	ubigint appendNewRecToRst(ListBrlyMSession& rst, BrlyMSession** rec = NULL, const ubigint refBrlyMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");
	virtual void insertRst(ListBrlyMSession& rst, bool transact = false);
	virtual void updateRec(BrlyMSession* rec);
	virtual void updateRst(ListBrlyMSession& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMSession** rec);
	virtual ubigint loadRefsByUsr(ubigint refBrlyMUser, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyMSession& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMSession& rst);
};

/**
  * MyBrlyMSession: C++ wrapper for table TblBrlyMSession (MySQL database)
  */
class MyTblBrlyMSession : public TblBrlyMSession, public MyTable {

public:
	MyTblBrlyMSession();
	~MyTblBrlyMSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMSession& rst);

	void insertRec(BrlyMSession* rec);
	void insertRst(ListBrlyMSession& rst, bool transact = false);
	void updateRec(BrlyMSession* rec);
	void updateRst(ListBrlyMSession& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMSession** rec);
	ubigint loadRefsByUsr(ubigint refBrlyMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyMSession& rst);
};

/**
  * PgBrlyMSession: C++ wrapper for table TblBrlyMSession (PgSQL database)
  */
class PgTblBrlyMSession : public TblBrlyMSession, public PgTable {

public:
	PgTblBrlyMSession();
	~PgTblBrlyMSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMSession** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMSession& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMSession** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMSession& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMSession& rst);

	void insertRec(BrlyMSession* rec);
	void insertRst(ListBrlyMSession& rst, bool transact = false);
	void updateRec(BrlyMSession* rec);
	void updateRst(ListBrlyMSession& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMSession** rec);
	ubigint loadRefsByUsr(ubigint refBrlyMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyMSession& rst);
};

#endif

