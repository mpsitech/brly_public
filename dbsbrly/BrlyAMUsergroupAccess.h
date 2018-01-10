/**
  * \file BrlyAMUsergroupAccess.h
  * database access for table TblBrlyAMUsergroupAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYAMUSERGROUPACCESS_H
#define BRLYAMUSERGROUPACCESS_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyAMUsergroupAccess: record of TblBrlyAMUsergroupAccess
  */
class BrlyAMUsergroupAccess {

public:
	BrlyAMUsergroupAccess(const ubigint ref = 0, const ubigint refBrlyMUsergroup = 0, const uint x1IxBrlyVCard = 0, const uint ixBrlyWUiaccess = 0);

public:
	ubigint ref;
	ubigint refBrlyMUsergroup;
	uint x1IxBrlyVCard;
	uint ixBrlyWUiaccess;

public:
	bool operator==(const BrlyAMUsergroupAccess& comp);
	bool operator!=(const BrlyAMUsergroupAccess& comp);
};

/**
  * ListBrlyAMUsergroupAccess: recordset of TblBrlyAMUsergroupAccess
  */
class ListBrlyAMUsergroupAccess {

public:
	ListBrlyAMUsergroupAccess();
	ListBrlyAMUsergroupAccess(const ListBrlyAMUsergroupAccess& src);
	~ListBrlyAMUsergroupAccess();

	void clear();
	unsigned int size() const;
	void append(BrlyAMUsergroupAccess* rec);

	BrlyAMUsergroupAccess* operator[](const uint ix);
	ListBrlyAMUsergroupAccess& operator=(const ListBrlyAMUsergroupAccess& src);
	bool operator==(const ListBrlyAMUsergroupAccess& comp);
	bool operator!=(const ListBrlyAMUsergroupAccess& comp);

public:
	vector<BrlyAMUsergroupAccess*> nodes;
};

/**
  * TblBrlyAMUsergroupAccess: C++ wrapper for table TblBrlyAMUsergroupAccess
  */
class TblBrlyAMUsergroupAccess {

public:

public:
	TblBrlyAMUsergroupAccess();
	virtual ~TblBrlyAMUsergroupAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyAMUsergroupAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMUsergroupAccess& rst);

	virtual void insertRec(BrlyAMUsergroupAccess* rec);
	ubigint insertNewRec(BrlyAMUsergroupAccess** rec = NULL, const ubigint refBrlyMUsergroup = 0, const uint x1IxBrlyVCard = 0, const uint ixBrlyWUiaccess = 0);
	ubigint appendNewRecToRst(ListBrlyAMUsergroupAccess& rst, BrlyAMUsergroupAccess** rec = NULL, const ubigint refBrlyMUsergroup = 0, const uint x1IxBrlyVCard = 0, const uint ixBrlyWUiaccess = 0);
	virtual void insertRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	virtual void updateRec(BrlyAMUsergroupAccess* rec);
	virtual void updateRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyAMUsergroupAccess** rec);
	virtual bool loadRecByUsgCrd(ubigint refBrlyMUsergroup, uint x1IxBrlyVCard, BrlyAMUsergroupAccess** rec);
	virtual ubigint loadRefsByUsg(ubigint refBrlyMUsergroup, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByUsg(ubigint refBrlyMUsergroup, const bool append, ListBrlyAMUsergroupAccess& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyAMUsergroupAccess& rst);
};

/**
  * MyBrlyAMUsergroupAccess: C++ wrapper for table TblBrlyAMUsergroupAccess (MySQL database)
  */
class MyTblBrlyAMUsergroupAccess : public TblBrlyAMUsergroupAccess, public MyTable {

public:
	MyTblBrlyAMUsergroupAccess();
	~MyTblBrlyAMUsergroupAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAMUsergroupAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMUsergroupAccess& rst);

	void insertRec(BrlyAMUsergroupAccess* rec);
	void insertRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	void updateRec(BrlyAMUsergroupAccess* rec);
	void updateRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAMUsergroupAccess** rec);
	bool loadRecByUsgCrd(ubigint refBrlyMUsergroup, uint x1IxBrlyVCard, BrlyAMUsergroupAccess** rec);
	ubigint loadRefsByUsg(ubigint refBrlyMUsergroup, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsg(ubigint refBrlyMUsergroup, const bool append, ListBrlyAMUsergroupAccess& rst);
};

/**
  * PgBrlyAMUsergroupAccess: C++ wrapper for table TblBrlyAMUsergroupAccess (PgSQL database)
  */
class PgTblBrlyAMUsergroupAccess : public TblBrlyAMUsergroupAccess, public PgTable {

public:
	PgTblBrlyAMUsergroupAccess();
	~PgTblBrlyAMUsergroupAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAMUsergroupAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyAMUsergroupAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAMUsergroupAccess** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAMUsergroupAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAMUsergroupAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMUsergroupAccess& rst);

	void insertRec(BrlyAMUsergroupAccess* rec);
	void insertRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	void updateRec(BrlyAMUsergroupAccess* rec);
	void updateRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAMUsergroupAccess** rec);
	bool loadRecByUsgCrd(ubigint refBrlyMUsergroup, uint x1IxBrlyVCard, BrlyAMUsergroupAccess** rec);
	ubigint loadRefsByUsg(ubigint refBrlyMUsergroup, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsg(ubigint refBrlyMUsergroup, const bool append, ListBrlyAMUsergroupAccess& rst);
};

#endif

