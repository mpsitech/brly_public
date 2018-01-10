/**
  * \file BrlyHistRMUserUniversal.h
  * database access for table TblBrlyHistRMUserUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYHISTRMUSERUNIVERSAL_H
#define BRLYHISTRMUSERUNIVERSAL_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyHistRMUserUniversal: record of TblBrlyHistRMUserUniversal
  */
class BrlyHistRMUserUniversal {

public:
	BrlyHistRMUserUniversal(const ubigint ref = 0, const ubigint refBrlyMUser = 0, const uint unvIxBrlyVMaintable = 0, const ubigint unvUref = 0, const uint ixBrlyVCard = 0, const uint ixBrlyVPreset = 0, const uint preIxBrlyVMaintable = 0, const ubigint preUref = 0, const uint start = 0);

public:
	ubigint ref;
	ubigint refBrlyMUser;
	uint unvIxBrlyVMaintable;
	ubigint unvUref;
	uint ixBrlyVCard;
	uint ixBrlyVPreset;
	uint preIxBrlyVMaintable;
	ubigint preUref;
	uint start;

public:
	bool operator==(const BrlyHistRMUserUniversal& comp);
	bool operator!=(const BrlyHistRMUserUniversal& comp);
};

/**
  * ListBrlyHistRMUserUniversal: recordset of TblBrlyHistRMUserUniversal
  */
class ListBrlyHistRMUserUniversal {

public:
	ListBrlyHistRMUserUniversal();
	ListBrlyHistRMUserUniversal(const ListBrlyHistRMUserUniversal& src);
	~ListBrlyHistRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(BrlyHistRMUserUniversal* rec);

	BrlyHistRMUserUniversal* operator[](const uint ix);
	ListBrlyHistRMUserUniversal& operator=(const ListBrlyHistRMUserUniversal& src);
	bool operator==(const ListBrlyHistRMUserUniversal& comp);
	bool operator!=(const ListBrlyHistRMUserUniversal& comp);

public:
	vector<BrlyHistRMUserUniversal*> nodes;
};

/**
  * TblBrlyHistRMUserUniversal: C++ wrapper for table TblBrlyHistRMUserUniversal
  */
class TblBrlyHistRMUserUniversal {

public:

public:
	TblBrlyHistRMUserUniversal();
	virtual ~TblBrlyHistRMUserUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyHistRMUserUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyHistRMUserUniversal& rst);

	virtual void insertRec(BrlyHistRMUserUniversal* rec);
	ubigint insertNewRec(BrlyHistRMUserUniversal** rec = NULL, const ubigint refBrlyMUser = 0, const uint unvIxBrlyVMaintable = 0, const ubigint unvUref = 0, const uint ixBrlyVCard = 0, const uint ixBrlyVPreset = 0, const uint preIxBrlyVMaintable = 0, const ubigint preUref = 0, const uint start = 0);
	ubigint appendNewRecToRst(ListBrlyHistRMUserUniversal& rst, BrlyHistRMUserUniversal** rec = NULL, const ubigint refBrlyMUser = 0, const uint unvIxBrlyVMaintable = 0, const ubigint unvUref = 0, const uint ixBrlyVCard = 0, const uint ixBrlyVPreset = 0, const uint preIxBrlyVMaintable = 0, const ubigint preUref = 0, const uint start = 0);
	virtual void insertRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(BrlyHistRMUserUniversal* rec);
	virtual void updateRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyHistRMUserUniversal** rec);
	virtual ubigint loadRstByUsrCrd(ubigint refBrlyMUser, uint ixBrlyVCard, const bool append, ListBrlyHistRMUserUniversal& rst);
	virtual bool loadUnuByRef(ubigint ref, ubigint& unvUref);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyHistRMUserUniversal& rst);
};

/**
  * MyBrlyHistRMUserUniversal: C++ wrapper for table TblBrlyHistRMUserUniversal (MySQL database)
  */
class MyTblBrlyHistRMUserUniversal : public TblBrlyHistRMUserUniversal, public MyTable {

public:
	MyTblBrlyHistRMUserUniversal();
	~MyTblBrlyHistRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyHistRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyHistRMUserUniversal& rst);

	void insertRec(BrlyHistRMUserUniversal* rec);
	void insertRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	void updateRec(BrlyHistRMUserUniversal* rec);
	void updateRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyHistRMUserUniversal** rec);
	ubigint loadRstByUsrCrd(ubigint refBrlyMUser, uint ixBrlyVCard, const bool append, ListBrlyHistRMUserUniversal& rst);
	bool loadUnuByRef(ubigint ref, ubigint& unvUref);
};

/**
  * PgBrlyHistRMUserUniversal: C++ wrapper for table TblBrlyHistRMUserUniversal (PgSQL database)
  */
class PgTblBrlyHistRMUserUniversal : public TblBrlyHistRMUserUniversal, public PgTable {

public:
	PgTblBrlyHistRMUserUniversal();
	~PgTblBrlyHistRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyHistRMUserUniversal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyHistRMUserUniversal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyHistRMUserUniversal** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyHistRMUserUniversal& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyHistRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyHistRMUserUniversal& rst);

	void insertRec(BrlyHistRMUserUniversal* rec);
	void insertRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	void updateRec(BrlyHistRMUserUniversal* rec);
	void updateRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyHistRMUserUniversal** rec);
	ubigint loadRstByUsrCrd(ubigint refBrlyMUser, uint ixBrlyVCard, const bool append, ListBrlyHistRMUserUniversal& rst);
	bool loadUnuByRef(ubigint ref, ubigint& unvUref);
};

#endif

