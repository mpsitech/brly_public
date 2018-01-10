/**
  * \file BrlyRMUsergroupUniversal.h
  * database access for table TblBrlyRMUsergroupUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYRMUSERGROUPUNIVERSAL_H
#define BRLYRMUSERGROUPUNIVERSAL_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyRMUsergroupUniversal: record of TblBrlyRMUsergroupUniversal
  */
class BrlyRMUsergroupUniversal {

public:
	BrlyRMUsergroupUniversal(const ubigint ref = 0, const ubigint refBrlyMUsergroup = 0, const uint unvIxBrlyVMaintable = 0, const ubigint unvUref = 0, const uint ixBrlyVAccess = 0);

public:
	ubigint ref;
	ubigint refBrlyMUsergroup;
	uint unvIxBrlyVMaintable;
	ubigint unvUref;
	uint ixBrlyVAccess;

public:
	bool operator==(const BrlyRMUsergroupUniversal& comp);
	bool operator!=(const BrlyRMUsergroupUniversal& comp);
};

/**
  * ListBrlyRMUsergroupUniversal: recordset of TblBrlyRMUsergroupUniversal
  */
class ListBrlyRMUsergroupUniversal {

public:
	ListBrlyRMUsergroupUniversal();
	ListBrlyRMUsergroupUniversal(const ListBrlyRMUsergroupUniversal& src);
	~ListBrlyRMUsergroupUniversal();

	void clear();
	unsigned int size() const;
	void append(BrlyRMUsergroupUniversal* rec);

	BrlyRMUsergroupUniversal* operator[](const uint ix);
	ListBrlyRMUsergroupUniversal& operator=(const ListBrlyRMUsergroupUniversal& src);
	bool operator==(const ListBrlyRMUsergroupUniversal& comp);
	bool operator!=(const ListBrlyRMUsergroupUniversal& comp);

public:
	vector<BrlyRMUsergroupUniversal*> nodes;
};

/**
  * TblBrlyRMUsergroupUniversal: C++ wrapper for table TblBrlyRMUsergroupUniversal
  */
class TblBrlyRMUsergroupUniversal {

public:

public:
	TblBrlyRMUsergroupUniversal();
	virtual ~TblBrlyRMUsergroupUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyRMUsergroupUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMUsergroupUniversal& rst);

	virtual void insertRec(BrlyRMUsergroupUniversal* rec);
	ubigint insertNewRec(BrlyRMUsergroupUniversal** rec = NULL, const ubigint refBrlyMUsergroup = 0, const uint unvIxBrlyVMaintable = 0, const ubigint unvUref = 0, const uint ixBrlyVAccess = 0);
	ubigint appendNewRecToRst(ListBrlyRMUsergroupUniversal& rst, BrlyRMUsergroupUniversal** rec = NULL, const ubigint refBrlyMUsergroup = 0, const uint unvIxBrlyVMaintable = 0, const ubigint unvUref = 0, const uint ixBrlyVAccess = 0);
	virtual void insertRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	virtual void updateRec(BrlyRMUsergroupUniversal* rec);
	virtual void updateRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyRMUsergroupUniversal** rec);
	virtual bool loadRecByUsgMtbUnv(ubigint refBrlyMUsergroup, uint unvIxBrlyVMaintable, ubigint unvUref, BrlyRMUsergroupUniversal** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyRMUsergroupUniversal& rst);
};

/**
  * MyBrlyRMUsergroupUniversal: C++ wrapper for table TblBrlyRMUsergroupUniversal (MySQL database)
  */
class MyTblBrlyRMUsergroupUniversal : public TblBrlyRMUsergroupUniversal, public MyTable {

public:
	MyTblBrlyRMUsergroupUniversal();
	~MyTblBrlyRMUsergroupUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMUsergroupUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMUsergroupUniversal& rst);

	void insertRec(BrlyRMUsergroupUniversal* rec);
	void insertRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(BrlyRMUsergroupUniversal* rec);
	void updateRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(ubigint refBrlyMUsergroup, uint unvIxBrlyVMaintable, ubigint unvUref, BrlyRMUsergroupUniversal** rec);
};

/**
  * PgBrlyRMUsergroupUniversal: C++ wrapper for table TblBrlyRMUsergroupUniversal (PgSQL database)
  */
class PgTblBrlyRMUsergroupUniversal : public TblBrlyRMUsergroupUniversal, public PgTable {

public:
	PgTblBrlyRMUsergroupUniversal();
	~PgTblBrlyRMUsergroupUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMUsergroupUniversal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyRMUsergroupUniversal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMUsergroupUniversal** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMUsergroupUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMUsergroupUniversal& rst);

	void insertRec(BrlyRMUsergroupUniversal* rec);
	void insertRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(BrlyRMUsergroupUniversal* rec);
	void updateRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(ubigint refBrlyMUsergroup, uint unvIxBrlyVMaintable, ubigint unvUref, BrlyRMUsergroupUniversal** rec);
};

#endif

