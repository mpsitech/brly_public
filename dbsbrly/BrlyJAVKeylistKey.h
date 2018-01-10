/**
  * \file BrlyJAVKeylistKey.h
  * database access for table TblBrlyJAVKeylistKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYJAVKEYLISTKEY_H
#define BRLYJAVKEYLISTKEY_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyJAVKeylistKey: record of TblBrlyJAVKeylistKey
  */
class BrlyJAVKeylistKey {

public:
	BrlyJAVKeylistKey(const ubigint ref = 0, const ubigint refBrlyAVKeylistKey = 0, const uint x1IxBrlyVLocale = 0, const string Title = "", const string Comment = "");

public:
	ubigint ref;
	ubigint refBrlyAVKeylistKey;
	uint x1IxBrlyVLocale;
	string Title;
	string Comment;

public:
	bool operator==(const BrlyJAVKeylistKey& comp);
	bool operator!=(const BrlyJAVKeylistKey& comp);
};

/**
  * ListBrlyJAVKeylistKey: recordset of TblBrlyJAVKeylistKey
  */
class ListBrlyJAVKeylistKey {

public:
	ListBrlyJAVKeylistKey();
	ListBrlyJAVKeylistKey(const ListBrlyJAVKeylistKey& src);
	~ListBrlyJAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(BrlyJAVKeylistKey* rec);

	BrlyJAVKeylistKey* operator[](const uint ix);
	ListBrlyJAVKeylistKey& operator=(const ListBrlyJAVKeylistKey& src);
	bool operator==(const ListBrlyJAVKeylistKey& comp);
	bool operator!=(const ListBrlyJAVKeylistKey& comp);

public:
	vector<BrlyJAVKeylistKey*> nodes;
};

/**
  * TblBrlyJAVKeylistKey: C++ wrapper for table TblBrlyJAVKeylistKey
  */
class TblBrlyJAVKeylistKey {

public:

public:
	TblBrlyJAVKeylistKey();
	virtual ~TblBrlyJAVKeylistKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyJAVKeylistKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJAVKeylistKey& rst);

	virtual void insertRec(BrlyJAVKeylistKey* rec);
	ubigint insertNewRec(BrlyJAVKeylistKey** rec = NULL, const ubigint refBrlyAVKeylistKey = 0, const uint x1IxBrlyVLocale = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListBrlyJAVKeylistKey& rst, BrlyJAVKeylistKey** rec = NULL, const ubigint refBrlyAVKeylistKey = 0, const uint x1IxBrlyVLocale = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(BrlyJAVKeylistKey* rec);
	virtual void updateRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyJAVKeylistKey** rec);
	virtual bool loadRecByKlkLcl(ubigint refBrlyAVKeylistKey, uint x1IxBrlyVLocale, BrlyJAVKeylistKey** rec);
	virtual ubigint loadRefsByKlk(ubigint refBrlyAVKeylistKey, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByKlk(ubigint refBrlyAVKeylistKey, const bool append, ListBrlyJAVKeylistKey& rst);
	virtual bool loadTitByKlkLcl(ubigint refBrlyAVKeylistKey, uint x1IxBrlyVLocale, string& Title);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyJAVKeylistKey& rst);
};

/**
  * MyBrlyJAVKeylistKey: C++ wrapper for table TblBrlyJAVKeylistKey (MySQL database)
  */
class MyTblBrlyJAVKeylistKey : public TblBrlyJAVKeylistKey, public MyTable {

public:
	MyTblBrlyJAVKeylistKey();
	~MyTblBrlyJAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyJAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJAVKeylistKey& rst);

	void insertRec(BrlyJAVKeylistKey* rec);
	void insertRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	void updateRec(BrlyJAVKeylistKey* rec);
	void updateRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyJAVKeylistKey** rec);
	bool loadRecByKlkLcl(ubigint refBrlyAVKeylistKey, uint x1IxBrlyVLocale, BrlyJAVKeylistKey** rec);
	ubigint loadRefsByKlk(ubigint refBrlyAVKeylistKey, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKlk(ubigint refBrlyAVKeylistKey, const bool append, ListBrlyJAVKeylistKey& rst);
	bool loadTitByKlkLcl(ubigint refBrlyAVKeylistKey, uint x1IxBrlyVLocale, string& Title);
};

/**
  * PgBrlyJAVKeylistKey: C++ wrapper for table TblBrlyJAVKeylistKey (PgSQL database)
  */
class PgTblBrlyJAVKeylistKey : public TblBrlyJAVKeylistKey, public PgTable {

public:
	PgTblBrlyJAVKeylistKey();
	~PgTblBrlyJAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyJAVKeylistKey** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyJAVKeylistKey& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyJAVKeylistKey** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyJAVKeylistKey& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyJAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJAVKeylistKey& rst);

	void insertRec(BrlyJAVKeylistKey* rec);
	void insertRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	void updateRec(BrlyJAVKeylistKey* rec);
	void updateRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyJAVKeylistKey** rec);
	bool loadRecByKlkLcl(ubigint refBrlyAVKeylistKey, uint x1IxBrlyVLocale, BrlyJAVKeylistKey** rec);
	ubigint loadRefsByKlk(ubigint refBrlyAVKeylistKey, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKlk(ubigint refBrlyAVKeylistKey, const bool append, ListBrlyJAVKeylistKey& rst);
	bool loadTitByKlkLcl(ubigint refBrlyAVKeylistKey, uint x1IxBrlyVLocale, string& Title);
};

#endif

