/**
  * \file BrlyAMUserAccess.h
  * database access for table TblBrlyAMUserAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYAMUSERACCESS_H
#define BRLYAMUSERACCESS_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyAMUserAccess: record of TblBrlyAMUserAccess
  */
class BrlyAMUserAccess {

public:
	BrlyAMUserAccess(const ubigint ref = 0, const ubigint refBrlyMUser = 0, const uint x1IxBrlyVCard = 0, const uint ixBrlyWUiaccess = 0);

public:
	ubigint ref;
	ubigint refBrlyMUser;
	uint x1IxBrlyVCard;
	uint ixBrlyWUiaccess;

public:
	bool operator==(const BrlyAMUserAccess& comp);
	bool operator!=(const BrlyAMUserAccess& comp);
};

/**
  * ListBrlyAMUserAccess: recordset of TblBrlyAMUserAccess
  */
class ListBrlyAMUserAccess {

public:
	ListBrlyAMUserAccess();
	ListBrlyAMUserAccess(const ListBrlyAMUserAccess& src);
	~ListBrlyAMUserAccess();

	void clear();
	unsigned int size() const;
	void append(BrlyAMUserAccess* rec);

	BrlyAMUserAccess* operator[](const uint ix);
	ListBrlyAMUserAccess& operator=(const ListBrlyAMUserAccess& src);
	bool operator==(const ListBrlyAMUserAccess& comp);
	bool operator!=(const ListBrlyAMUserAccess& comp);

public:
	vector<BrlyAMUserAccess*> nodes;
};

/**
  * TblBrlyAMUserAccess: C++ wrapper for table TblBrlyAMUserAccess
  */
class TblBrlyAMUserAccess {

public:

public:
	TblBrlyAMUserAccess();
	virtual ~TblBrlyAMUserAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyAMUserAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMUserAccess& rst);

	virtual void insertRec(BrlyAMUserAccess* rec);
	ubigint insertNewRec(BrlyAMUserAccess** rec = NULL, const ubigint refBrlyMUser = 0, const uint x1IxBrlyVCard = 0, const uint ixBrlyWUiaccess = 0);
	ubigint appendNewRecToRst(ListBrlyAMUserAccess& rst, BrlyAMUserAccess** rec = NULL, const ubigint refBrlyMUser = 0, const uint x1IxBrlyVCard = 0, const uint ixBrlyWUiaccess = 0);
	virtual void insertRst(ListBrlyAMUserAccess& rst, bool transact = false);
	virtual void updateRec(BrlyAMUserAccess* rec);
	virtual void updateRst(ListBrlyAMUserAccess& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyAMUserAccess** rec);
	virtual bool loadRecByUsrCrd(ubigint refBrlyMUser, uint x1IxBrlyVCard, BrlyAMUserAccess** rec);
	virtual ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyAMUserAccess& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyAMUserAccess& rst);
};

/**
  * MyBrlyAMUserAccess: C++ wrapper for table TblBrlyAMUserAccess (MySQL database)
  */
class MyTblBrlyAMUserAccess : public TblBrlyAMUserAccess, public MyTable {

public:
	MyTblBrlyAMUserAccess();
	~MyTblBrlyAMUserAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAMUserAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMUserAccess& rst);

	void insertRec(BrlyAMUserAccess* rec);
	void insertRst(ListBrlyAMUserAccess& rst, bool transact = false);
	void updateRec(BrlyAMUserAccess* rec);
	void updateRst(ListBrlyAMUserAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAMUserAccess** rec);
	bool loadRecByUsrCrd(ubigint refBrlyMUser, uint x1IxBrlyVCard, BrlyAMUserAccess** rec);
	ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyAMUserAccess& rst);
};

/**
  * PgBrlyAMUserAccess: C++ wrapper for table TblBrlyAMUserAccess (PgSQL database)
  */
class PgTblBrlyAMUserAccess : public TblBrlyAMUserAccess, public PgTable {

public:
	PgTblBrlyAMUserAccess();
	~PgTblBrlyAMUserAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAMUserAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyAMUserAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAMUserAccess** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAMUserAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAMUserAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMUserAccess& rst);

	void insertRec(BrlyAMUserAccess* rec);
	void insertRst(ListBrlyAMUserAccess& rst, bool transact = false);
	void updateRec(BrlyAMUserAccess* rec);
	void updateRst(ListBrlyAMUserAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAMUserAccess** rec);
	bool loadRecByUsrCrd(ubigint refBrlyMUser, uint x1IxBrlyVCard, BrlyAMUserAccess** rec);
	ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyAMUserAccess& rst);
};

#endif

