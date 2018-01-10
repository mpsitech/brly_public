/**
  * \file BrlyMPlntype.h
  * database access for table TblBrlyMPlntype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMPLNTYPE_H
#define BRLYMPLNTYPE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyMPlntype: record of TblBrlyMPlntype
  */
class BrlyMPlntype {

public:
	BrlyMPlntype(const ubigint ref = 0, const string sref = "", const string Title = "", const string srefBrlyKEqptype = "", const usmallint Capacity = 0);

public:
	ubigint ref;
	string sref;
	string Title;
	string srefBrlyKEqptype;
	usmallint Capacity;

public:
	bool operator==(const BrlyMPlntype& comp);
	bool operator!=(const BrlyMPlntype& comp);
};

/**
  * ListBrlyMPlntype: recordset of TblBrlyMPlntype
  */
class ListBrlyMPlntype {

public:
	ListBrlyMPlntype();
	ListBrlyMPlntype(const ListBrlyMPlntype& src);
	~ListBrlyMPlntype();

	void clear();
	unsigned int size() const;
	void append(BrlyMPlntype* rec);

	BrlyMPlntype* operator[](const uint ix);
	ListBrlyMPlntype& operator=(const ListBrlyMPlntype& src);
	bool operator==(const ListBrlyMPlntype& comp);
	bool operator!=(const ListBrlyMPlntype& comp);

public:
	vector<BrlyMPlntype*> nodes;
};

/**
  * TblBrlyMPlntype: C++ wrapper for table TblBrlyMPlntype
  */
class TblBrlyMPlntype {

public:

public:
	TblBrlyMPlntype();
	virtual ~TblBrlyMPlntype();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMPlntype** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMPlntype& rst);

	virtual void insertRec(BrlyMPlntype* rec);
	ubigint insertNewRec(BrlyMPlntype** rec = NULL, const string sref = "", const string Title = "", const string srefBrlyKEqptype = "", const usmallint Capacity = 0);
	ubigint appendNewRecToRst(ListBrlyMPlntype& rst, BrlyMPlntype** rec = NULL, const string sref = "", const string Title = "", const string srefBrlyKEqptype = "", const usmallint Capacity = 0);
	virtual void insertRst(ListBrlyMPlntype& rst, bool transact = false);
	virtual void updateRec(BrlyMPlntype* rec);
	virtual void updateRst(ListBrlyMPlntype& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMPlntype** rec);
	virtual bool loadSrfByRef(ubigint ref, string& sref);
	virtual bool loadTitByRef(ubigint ref, string& Title);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMPlntype& rst);
};

/**
  * MyBrlyMPlntype: C++ wrapper for table TblBrlyMPlntype (MySQL database)
  */
class MyTblBrlyMPlntype : public TblBrlyMPlntype, public MyTable {

public:
	MyTblBrlyMPlntype();
	~MyTblBrlyMPlntype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMPlntype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMPlntype& rst);

	void insertRec(BrlyMPlntype* rec);
	void insertRst(ListBrlyMPlntype& rst, bool transact = false);
	void updateRec(BrlyMPlntype* rec);
	void updateRst(ListBrlyMPlntype& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMPlntype** rec);
	bool loadSrfByRef(ubigint ref, string& sref);
	bool loadTitByRef(ubigint ref, string& Title);
};

/**
  * PgBrlyMPlntype: C++ wrapper for table TblBrlyMPlntype (PgSQL database)
  */
class PgTblBrlyMPlntype : public TblBrlyMPlntype, public PgTable {

public:
	PgTblBrlyMPlntype();
	~PgTblBrlyMPlntype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMPlntype** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMPlntype& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMPlntype** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMPlntype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMPlntype& rst);

	void insertRec(BrlyMPlntype* rec);
	void insertRst(ListBrlyMPlntype& rst, bool transact = false);
	void updateRec(BrlyMPlntype* rec);
	void updateRst(ListBrlyMPlntype& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMPlntype** rec);
	bool loadSrfByRef(ubigint ref, string& sref);
	bool loadTitByRef(ubigint ref, string& Title);
};

#endif

