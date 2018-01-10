/**
  * \file BrlyAVKeylistKey.h
  * database access for table TblBrlyAVKeylistKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYAVKEYLISTKEY_H
#define BRLYAVKEYLISTKEY_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyAVKeylistKey: record of TblBrlyAVKeylistKey
  */
class BrlyAVKeylistKey {

public:
	BrlyAVKeylistKey(const ubigint ref = 0, const uint klsIxBrlyVKeylist = 0, const uint klsNum = 0, const uint x1IxBrlyVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint ref;
	uint klsIxBrlyVKeylist;
	uint klsNum;
	uint x1IxBrlyVMaintable;
	ubigint x1Uref;
	bool Fixed;
	string sref;
	string Avail;
	string Implied;
	ubigint refJ;
	string Title;
	string Comment;

public:
	bool operator==(const BrlyAVKeylistKey& comp);
	bool operator!=(const BrlyAVKeylistKey& comp);
};

/**
  * ListBrlyAVKeylistKey: recordset of TblBrlyAVKeylistKey
  */
class ListBrlyAVKeylistKey {

public:
	ListBrlyAVKeylistKey();
	ListBrlyAVKeylistKey(const ListBrlyAVKeylistKey& src);
	~ListBrlyAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(BrlyAVKeylistKey* rec);

	BrlyAVKeylistKey* operator[](const uint ix);
	ListBrlyAVKeylistKey& operator=(const ListBrlyAVKeylistKey& src);
	bool operator==(const ListBrlyAVKeylistKey& comp);
	bool operator!=(const ListBrlyAVKeylistKey& comp);

public:
	vector<BrlyAVKeylistKey*> nodes;
};

/**
  * TblBrlyAVKeylistKey: C++ wrapper for table TblBrlyAVKeylistKey
  */
class TblBrlyAVKeylistKey {

public:

public:
	TblBrlyAVKeylistKey();
	virtual ~TblBrlyAVKeylistKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyAVKeylistKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAVKeylistKey& rst);

	virtual void insertRec(BrlyAVKeylistKey* rec);
	ubigint insertNewRec(BrlyAVKeylistKey** rec = NULL, const uint klsIxBrlyVKeylist = 0, const uint klsNum = 0, const uint x1IxBrlyVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListBrlyAVKeylistKey& rst, BrlyAVKeylistKey** rec = NULL, const uint klsIxBrlyVKeylist = 0, const uint klsNum = 0, const uint x1IxBrlyVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(BrlyAVKeylistKey* rec);
	virtual void updateRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyAVKeylistKey** rec);
	virtual bool loadRefByKlsMtbUrfSrf(uint klsIxBrlyVKeylist, uint x1IxBrlyVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	virtual bool loadRefByKlsSrf(uint klsIxBrlyVKeylist, string sref, ubigint& ref);
	virtual ubigint loadRstByKls(uint klsIxBrlyVKeylist, const bool append, ListBrlyAVKeylistKey& rst);
	virtual ubigint loadRstByKlsMtbUrf(uint klsIxBrlyVKeylist, uint x1IxBrlyVMaintable, ubigint x1Uref, const bool append, ListBrlyAVKeylistKey& rst);
	virtual bool loadTitByRef(ubigint ref, string& Title);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyAVKeylistKey& rst);
};

/**
  * MyBrlyAVKeylistKey: C++ wrapper for table TblBrlyAVKeylistKey (MySQL database)
  */
class MyTblBrlyAVKeylistKey : public TblBrlyAVKeylistKey, public MyTable {

public:
	MyTblBrlyAVKeylistKey();
	~MyTblBrlyAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAVKeylistKey& rst);

	void insertRec(BrlyAVKeylistKey* rec);
	void insertRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	void updateRec(BrlyAVKeylistKey* rec);
	void updateRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(uint klsIxBrlyVKeylist, uint x1IxBrlyVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	bool loadRefByKlsSrf(uint klsIxBrlyVKeylist, string sref, ubigint& ref);
	ubigint loadRstByKls(uint klsIxBrlyVKeylist, const bool append, ListBrlyAVKeylistKey& rst);
	ubigint loadRstByKlsMtbUrf(uint klsIxBrlyVKeylist, uint x1IxBrlyVMaintable, ubigint x1Uref, const bool append, ListBrlyAVKeylistKey& rst);
	bool loadTitByRef(ubigint ref, string& Title);
};

/**
  * PgBrlyAVKeylistKey: C++ wrapper for table TblBrlyAVKeylistKey (PgSQL database)
  */
class PgTblBrlyAVKeylistKey : public TblBrlyAVKeylistKey, public PgTable {

public:
	PgTblBrlyAVKeylistKey();
	~PgTblBrlyAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAVKeylistKey** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyAVKeylistKey& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAVKeylistKey** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAVKeylistKey& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAVKeylistKey& rst);

	void insertRec(BrlyAVKeylistKey* rec);
	void insertRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	void updateRec(BrlyAVKeylistKey* rec);
	void updateRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(uint klsIxBrlyVKeylist, uint x1IxBrlyVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	bool loadRefByKlsSrf(uint klsIxBrlyVKeylist, string sref, ubigint& ref);
	ubigint loadRstByKls(uint klsIxBrlyVKeylist, const bool append, ListBrlyAVKeylistKey& rst);
	ubigint loadRstByKlsMtbUrf(uint klsIxBrlyVKeylist, uint x1IxBrlyVMaintable, ubigint x1Uref, const bool append, ListBrlyAVKeylistKey& rst);
	bool loadTitByRef(ubigint ref, string& Title);
};

#endif

