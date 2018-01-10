/**
  * \file BrlyAVValuelistVal.h
  * database access for table TblBrlyAVValuelistVal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYAVVALUELISTVAL_H
#define BRLYAVVALUELISTVAL_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyAVValuelistVal: record of TblBrlyAVValuelistVal
  */
class BrlyAVValuelistVal {

public:
	BrlyAVValuelistVal(const ubigint ref = 0, const uint vlsIxBrlyVValuelist = 0, const uint vlsNum = 0, const uint x1IxBrlyVLocale = 0, const string Val = "");

public:
	ubigint ref;
	uint vlsIxBrlyVValuelist;
	uint vlsNum;
	uint x1IxBrlyVLocale;
	string Val;

public:
	bool operator==(const BrlyAVValuelistVal& comp);
	bool operator!=(const BrlyAVValuelistVal& comp);
};

/**
  * ListBrlyAVValuelistVal: recordset of TblBrlyAVValuelistVal
  */
class ListBrlyAVValuelistVal {

public:
	ListBrlyAVValuelistVal();
	ListBrlyAVValuelistVal(const ListBrlyAVValuelistVal& src);
	~ListBrlyAVValuelistVal();

	void clear();
	unsigned int size() const;
	void append(BrlyAVValuelistVal* rec);

	BrlyAVValuelistVal* operator[](const uint ix);
	ListBrlyAVValuelistVal& operator=(const ListBrlyAVValuelistVal& src);
	bool operator==(const ListBrlyAVValuelistVal& comp);
	bool operator!=(const ListBrlyAVValuelistVal& comp);

public:
	vector<BrlyAVValuelistVal*> nodes;
};

/**
  * TblBrlyAVValuelistVal: C++ wrapper for table TblBrlyAVValuelistVal
  */
class TblBrlyAVValuelistVal {

public:

public:
	TblBrlyAVValuelistVal();
	virtual ~TblBrlyAVValuelistVal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyAVValuelistVal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAVValuelistVal& rst);

	virtual void insertRec(BrlyAVValuelistVal* rec);
	ubigint insertNewRec(BrlyAVValuelistVal** rec = NULL, const uint vlsIxBrlyVValuelist = 0, const uint vlsNum = 0, const uint x1IxBrlyVLocale = 0, const string Val = "");
	ubigint appendNewRecToRst(ListBrlyAVValuelistVal& rst, BrlyAVValuelistVal** rec = NULL, const uint vlsIxBrlyVValuelist = 0, const uint vlsNum = 0, const uint x1IxBrlyVLocale = 0, const string Val = "");
	virtual void insertRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	virtual void updateRec(BrlyAVValuelistVal* rec);
	virtual void updateRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyAVValuelistVal** rec);
	virtual ubigint loadRstByVlsLcl(uint vlsIxBrlyVValuelist, uint x1IxBrlyVLocale, const bool append, ListBrlyAVValuelistVal& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyAVValuelistVal& rst);
};

/**
  * MyBrlyAVValuelistVal: C++ wrapper for table TblBrlyAVValuelistVal (MySQL database)
  */
class MyTblBrlyAVValuelistVal : public TblBrlyAVValuelistVal, public MyTable {

public:
	MyTblBrlyAVValuelistVal();
	~MyTblBrlyAVValuelistVal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAVValuelistVal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAVValuelistVal& rst);

	void insertRec(BrlyAVValuelistVal* rec);
	void insertRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	void updateRec(BrlyAVValuelistVal* rec);
	void updateRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAVValuelistVal** rec);
	ubigint loadRstByVlsLcl(uint vlsIxBrlyVValuelist, uint x1IxBrlyVLocale, const bool append, ListBrlyAVValuelistVal& rst);
};

/**
  * PgBrlyAVValuelistVal: C++ wrapper for table TblBrlyAVValuelistVal (PgSQL database)
  */
class PgTblBrlyAVValuelistVal : public TblBrlyAVValuelistVal, public PgTable {

public:
	PgTblBrlyAVValuelistVal();
	~PgTblBrlyAVValuelistVal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAVValuelistVal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyAVValuelistVal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAVValuelistVal** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAVValuelistVal& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAVValuelistVal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAVValuelistVal& rst);

	void insertRec(BrlyAVValuelistVal* rec);
	void insertRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	void updateRec(BrlyAVValuelistVal* rec);
	void updateRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAVValuelistVal** rec);
	ubigint loadRstByVlsLcl(uint vlsIxBrlyVValuelist, uint x1IxBrlyVLocale, const bool append, ListBrlyAVValuelistVal& rst);
};

#endif

