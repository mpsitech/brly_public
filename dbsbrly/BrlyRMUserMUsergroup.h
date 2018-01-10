/**
  * \file BrlyRMUserMUsergroup.h
  * database access for table TblBrlyRMUserMUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYRMUSERMUSERGROUP_H
#define BRLYRMUSERMUSERGROUP_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyRMUserMUsergroup: record of TblBrlyRMUserMUsergroup
  */
class BrlyRMUserMUsergroup {

public:
	BrlyRMUserMUsergroup(const ubigint ref = 0, const ubigint refBrlyMUser = 0, const ubigint refBrlyMUsergroup = 0, const uint ixBrlyVUserlevel = 0);

public:
	ubigint ref;
	ubigint refBrlyMUser;
	ubigint refBrlyMUsergroup;
	uint ixBrlyVUserlevel;

public:
	bool operator==(const BrlyRMUserMUsergroup& comp);
	bool operator!=(const BrlyRMUserMUsergroup& comp);
};

/**
  * ListBrlyRMUserMUsergroup: recordset of TblBrlyRMUserMUsergroup
  */
class ListBrlyRMUserMUsergroup {

public:
	ListBrlyRMUserMUsergroup();
	ListBrlyRMUserMUsergroup(const ListBrlyRMUserMUsergroup& src);
	~ListBrlyRMUserMUsergroup();

	void clear();
	unsigned int size() const;
	void append(BrlyRMUserMUsergroup* rec);

	BrlyRMUserMUsergroup* operator[](const uint ix);
	ListBrlyRMUserMUsergroup& operator=(const ListBrlyRMUserMUsergroup& src);
	bool operator==(const ListBrlyRMUserMUsergroup& comp);
	bool operator!=(const ListBrlyRMUserMUsergroup& comp);

public:
	vector<BrlyRMUserMUsergroup*> nodes;
};

/**
  * TblBrlyRMUserMUsergroup: C++ wrapper for table TblBrlyRMUserMUsergroup
  */
class TblBrlyRMUserMUsergroup {

public:

public:
	TblBrlyRMUserMUsergroup();
	virtual ~TblBrlyRMUserMUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyRMUserMUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMUserMUsergroup& rst);

	virtual void insertRec(BrlyRMUserMUsergroup* rec);
	ubigint insertNewRec(BrlyRMUserMUsergroup** rec = NULL, const ubigint refBrlyMUser = 0, const ubigint refBrlyMUsergroup = 0, const uint ixBrlyVUserlevel = 0);
	ubigint appendNewRecToRst(ListBrlyRMUserMUsergroup& rst, BrlyRMUserMUsergroup** rec = NULL, const ubigint refBrlyMUser = 0, const ubigint refBrlyMUsergroup = 0, const uint ixBrlyVUserlevel = 0);
	virtual void insertRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	virtual void updateRec(BrlyRMUserMUsergroup* rec);
	virtual void updateRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyRMUserMUsergroup** rec);
	virtual ubigint loadRstByUsg(ubigint refBrlyMUsergroup, const bool append, ListBrlyRMUserMUsergroup& rst);
	virtual ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyRMUserMUsergroup& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyRMUserMUsergroup& rst);
};

/**
  * MyBrlyRMUserMUsergroup: C++ wrapper for table TblBrlyRMUserMUsergroup (MySQL database)
  */
class MyTblBrlyRMUserMUsergroup : public TblBrlyRMUserMUsergroup, public MyTable {

public:
	MyTblBrlyRMUserMUsergroup();
	~MyTblBrlyRMUserMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMUserMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMUserMUsergroup& rst);

	void insertRec(BrlyRMUserMUsergroup* rec);
	void insertRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	void updateRec(BrlyRMUserMUsergroup* rec);
	void updateRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMUserMUsergroup** rec);
	ubigint loadRstByUsg(ubigint refBrlyMUsergroup, const bool append, ListBrlyRMUserMUsergroup& rst);
	ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyRMUserMUsergroup& rst);
};

/**
  * PgBrlyRMUserMUsergroup: C++ wrapper for table TblBrlyRMUserMUsergroup (PgSQL database)
  */
class PgTblBrlyRMUserMUsergroup : public TblBrlyRMUserMUsergroup, public PgTable {

public:
	PgTblBrlyRMUserMUsergroup();
	~PgTblBrlyRMUserMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMUserMUsergroup** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyRMUserMUsergroup& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMUserMUsergroup** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMUserMUsergroup& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMUserMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMUserMUsergroup& rst);

	void insertRec(BrlyRMUserMUsergroup* rec);
	void insertRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	void updateRec(BrlyRMUserMUsergroup* rec);
	void updateRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMUserMUsergroup** rec);
	ubigint loadRstByUsg(ubigint refBrlyMUsergroup, const bool append, ListBrlyRMUserMUsergroup& rst);
	ubigint loadRstByUsr(ubigint refBrlyMUser, const bool append, ListBrlyRMUserMUsergroup& rst);
};

#endif

