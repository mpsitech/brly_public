/**
  * \file BrlyMOperator.h
  * database access for table TblBrlyMOperator (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMOPERATOR_H
#define BRLYMOPERATOR_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyMOperator: record of TblBrlyMOperator
  */
class BrlyMOperator {

public:
	BrlyMOperator(const ubigint ref = 0, const string sref = "", const string srefICAO = "", const string Title = "");

public:
	ubigint ref;
	string sref;
	string srefICAO;
	string Title;

public:
	bool operator==(const BrlyMOperator& comp);
	bool operator!=(const BrlyMOperator& comp);
};

/**
  * ListBrlyMOperator: recordset of TblBrlyMOperator
  */
class ListBrlyMOperator {

public:
	ListBrlyMOperator();
	ListBrlyMOperator(const ListBrlyMOperator& src);
	~ListBrlyMOperator();

	void clear();
	unsigned int size() const;
	void append(BrlyMOperator* rec);

	BrlyMOperator* operator[](const uint ix);
	ListBrlyMOperator& operator=(const ListBrlyMOperator& src);
	bool operator==(const ListBrlyMOperator& comp);
	bool operator!=(const ListBrlyMOperator& comp);

public:
	vector<BrlyMOperator*> nodes;
};

/**
  * TblBrlyMOperator: C++ wrapper for table TblBrlyMOperator
  */
class TblBrlyMOperator {

public:

public:
	TblBrlyMOperator();
	virtual ~TblBrlyMOperator();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMOperator** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMOperator& rst);

	virtual void insertRec(BrlyMOperator* rec);
	ubigint insertNewRec(BrlyMOperator** rec = NULL, const string sref = "", const string srefICAO = "", const string Title = "");
	ubigint appendNewRecToRst(ListBrlyMOperator& rst, BrlyMOperator** rec = NULL, const string sref = "", const string srefICAO = "", const string Title = "");
	virtual void insertRst(ListBrlyMOperator& rst, bool transact = false);
	virtual void updateRec(BrlyMOperator* rec);
	virtual void updateRst(ListBrlyMOperator& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMOperator** rec);
	virtual bool loadSrfByRef(ubigint ref, string& sref);
	virtual bool loadTitByRef(ubigint ref, string& Title);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMOperator& rst);
};

/**
  * MyBrlyMOperator: C++ wrapper for table TblBrlyMOperator (MySQL database)
  */
class MyTblBrlyMOperator : public TblBrlyMOperator, public MyTable {

public:
	MyTblBrlyMOperator();
	~MyTblBrlyMOperator();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMOperator** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMOperator& rst);

	void insertRec(BrlyMOperator* rec);
	void insertRst(ListBrlyMOperator& rst, bool transact = false);
	void updateRec(BrlyMOperator* rec);
	void updateRst(ListBrlyMOperator& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMOperator** rec);
	bool loadSrfByRef(ubigint ref, string& sref);
	bool loadTitByRef(ubigint ref, string& Title);
};

/**
  * PgBrlyMOperator: C++ wrapper for table TblBrlyMOperator (PgSQL database)
  */
class PgTblBrlyMOperator : public TblBrlyMOperator, public PgTable {

public:
	PgTblBrlyMOperator();
	~PgTblBrlyMOperator();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMOperator** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMOperator& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMOperator** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMOperator** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMOperator& rst);

	void insertRec(BrlyMOperator* rec);
	void insertRst(ListBrlyMOperator& rst, bool transact = false);
	void updateRec(BrlyMOperator* rec);
	void updateRst(ListBrlyMOperator& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMOperator** rec);
	bool loadSrfByRef(ubigint ref, string& sref);
	bool loadTitByRef(ubigint ref, string& Title);
};

#endif

