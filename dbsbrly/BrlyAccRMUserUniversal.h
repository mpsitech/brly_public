/**
  * \file BrlyAccRMUserUniversal.h
  * database access for table TblBrlyAccRMUserUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYACCRMUSERUNIVERSAL_H
#define BRLYACCRMUSERUNIVERSAL_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyAccRMUserUniversal: record of TblBrlyAccRMUserUniversal
  */
class BrlyAccRMUserUniversal {

public:
	BrlyAccRMUserUniversal(const ubigint ref = 0, const ubigint refBrlyMUser = 0, const uint unvIxBrlyVMaintable = 0, const ubigint unvUref = 0, const uint ixBrlyVAccess = 0);

public:
	ubigint ref;
	ubigint refBrlyMUser;
	uint unvIxBrlyVMaintable;
	ubigint unvUref;
	uint ixBrlyVAccess;

public:
	bool operator==(const BrlyAccRMUserUniversal& comp);
	bool operator!=(const BrlyAccRMUserUniversal& comp);
};

/**
  * ListBrlyAccRMUserUniversal: recordset of TblBrlyAccRMUserUniversal
  */
class ListBrlyAccRMUserUniversal {

public:
	ListBrlyAccRMUserUniversal();
	ListBrlyAccRMUserUniversal(const ListBrlyAccRMUserUniversal& src);
	~ListBrlyAccRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(BrlyAccRMUserUniversal* rec);

	BrlyAccRMUserUniversal* operator[](const uint ix);
	ListBrlyAccRMUserUniversal& operator=(const ListBrlyAccRMUserUniversal& src);
	bool operator==(const ListBrlyAccRMUserUniversal& comp);
	bool operator!=(const ListBrlyAccRMUserUniversal& comp);

public:
	vector<BrlyAccRMUserUniversal*> nodes;
};

/**
  * TblBrlyAccRMUserUniversal: C++ wrapper for table TblBrlyAccRMUserUniversal
  */
class TblBrlyAccRMUserUniversal {

public:

public:
	TblBrlyAccRMUserUniversal();
	virtual ~TblBrlyAccRMUserUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyAccRMUserUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAccRMUserUniversal& rst);

	virtual void insertRec(BrlyAccRMUserUniversal* rec);
	ubigint insertNewRec(BrlyAccRMUserUniversal** rec = NULL, const ubigint refBrlyMUser = 0, const uint unvIxBrlyVMaintable = 0, const ubigint unvUref = 0, const uint ixBrlyVAccess = 0);
	ubigint appendNewRecToRst(ListBrlyAccRMUserUniversal& rst, BrlyAccRMUserUniversal** rec = NULL, const ubigint refBrlyMUser = 0, const uint unvIxBrlyVMaintable = 0, const ubigint unvUref = 0, const uint ixBrlyVAccess = 0);
	virtual void insertRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(BrlyAccRMUserUniversal* rec);
	virtual void updateRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyAccRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnv(ubigint refBrlyMUser, uint unvIxBrlyVMaintable, ubigint unvUref, BrlyAccRMUserUniversal** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyAccRMUserUniversal& rst);
};

/**
  * MyBrlyAccRMUserUniversal: C++ wrapper for table TblBrlyAccRMUserUniversal (MySQL database)
  */
class MyTblBrlyAccRMUserUniversal : public TblBrlyAccRMUserUniversal, public MyTable {

public:
	MyTblBrlyAccRMUserUniversal();
	~MyTblBrlyAccRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAccRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAccRMUserUniversal& rst);

	void insertRec(BrlyAccRMUserUniversal* rec);
	void insertRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	void updateRec(BrlyAccRMUserUniversal* rec);
	void updateRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(ubigint refBrlyMUser, uint unvIxBrlyVMaintable, ubigint unvUref, BrlyAccRMUserUniversal** rec);
};

/**
  * PgBrlyAccRMUserUniversal: C++ wrapper for table TblBrlyAccRMUserUniversal (PgSQL database)
  */
class PgTblBrlyAccRMUserUniversal : public TblBrlyAccRMUserUniversal, public PgTable {

public:
	PgTblBrlyAccRMUserUniversal();
	~PgTblBrlyAccRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAccRMUserUniversal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyAccRMUserUniversal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAccRMUserUniversal** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAccRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAccRMUserUniversal& rst);

	void insertRec(BrlyAccRMUserUniversal* rec);
	void insertRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	void updateRec(BrlyAccRMUserUniversal* rec);
	void updateRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(ubigint refBrlyMUser, uint unvIxBrlyVMaintable, ubigint unvUref, BrlyAccRMUserUniversal** rec);
};

#endif

