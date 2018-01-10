/**
  * \file BrlyJMUserState.h
  * database access for table TblBrlyJMUserState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYJMUSERSTATE_H
#define BRLYJMUSERSTATE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyJMUserState: record of TblBrlyJMUserState
  */
class BrlyJMUserState {

public:
	BrlyJMUserState(const ubigint ref = 0, const ubigint refBrlyMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refBrlyMUser;
	uint x1Startd;
	uint ixVState;

public:
	bool operator==(const BrlyJMUserState& comp);
	bool operator!=(const BrlyJMUserState& comp);
};

/**
  * ListBrlyJMUserState: recordset of TblBrlyJMUserState
  */
class ListBrlyJMUserState {

public:
	ListBrlyJMUserState();
	ListBrlyJMUserState(const ListBrlyJMUserState& src);
	~ListBrlyJMUserState();

	void clear();
	unsigned int size() const;
	void append(BrlyJMUserState* rec);

	BrlyJMUserState* operator[](const uint ix);
	ListBrlyJMUserState& operator=(const ListBrlyJMUserState& src);
	bool operator==(const ListBrlyJMUserState& comp);
	bool operator!=(const ListBrlyJMUserState& comp);

public:
	vector<BrlyJMUserState*> nodes;
};

/**
  * TblBrlyJMUserState: C++ wrapper for table TblBrlyJMUserState
  */
class TblBrlyJMUserState {

public:

public:
	TblBrlyJMUserState();
	virtual ~TblBrlyJMUserState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyJMUserState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMUserState& rst);

	virtual void insertRec(BrlyJMUserState* rec);
	ubigint insertNewRec(BrlyJMUserState** rec = NULL, const ubigint refBrlyMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListBrlyJMUserState& rst, BrlyJMUserState** rec = NULL, const ubigint refBrlyMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);
	virtual void insertRst(ListBrlyJMUserState& rst, bool transact = false);
	virtual void updateRec(BrlyJMUserState* rec);
	virtual void updateRst(ListBrlyJMUserState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyJMUserState** rec);
	virtual bool loadRecByUsrSta(ubigint refBrlyMUser, uint x1Startd, BrlyJMUserState** rec);
	virtual ubigint loadRefsByUsr(ubigint refBrlyMUser, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyJMUserState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyJMUserState& rst);
};

/**
  * MyBrlyJMUserState: C++ wrapper for table TblBrlyJMUserState (MySQL database)
  */
class MyTblBrlyJMUserState : public TblBrlyJMUserState, public MyTable {

public:
	MyTblBrlyJMUserState();
	~MyTblBrlyJMUserState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyJMUserState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMUserState& rst);

	void insertRec(BrlyJMUserState* rec);
	void insertRst(ListBrlyJMUserState& rst, bool transact = false);
	void updateRec(BrlyJMUserState* rec);
	void updateRst(ListBrlyJMUserState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyJMUserState** rec);
	bool loadRecByUsrSta(ubigint refBrlyMUser, uint x1Startd, BrlyJMUserState** rec);
	ubigint loadRefsByUsr(ubigint refBrlyMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyJMUserState& rst);
};

/**
  * PgBrlyJMUserState: C++ wrapper for table TblBrlyJMUserState (PgSQL database)
  */
class PgTblBrlyJMUserState : public TblBrlyJMUserState, public PgTable {

public:
	PgTblBrlyJMUserState();
	~PgTblBrlyJMUserState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyJMUserState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyJMUserState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyJMUserState** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyJMUserState& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyJMUserState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMUserState& rst);

	void insertRec(BrlyJMUserState* rec);
	void insertRst(ListBrlyJMUserState& rst, bool transact = false);
	void updateRec(BrlyJMUserState* rec);
	void updateRst(ListBrlyJMUserState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyJMUserState** rec);
	bool loadRecByUsrSta(ubigint refBrlyMUser, uint x1Startd, BrlyJMUserState** rec);
	ubigint loadRefsByUsr(ubigint refBrlyMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyJMUserState& rst);
};

#endif

