/**
  * \file BrlyMTimetable.h
  * database access for table TblBrlyMTimetable (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMTIMETABLE_H
#define BRLYMTIMETABLE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyMTimetable: record of TblBrlyMTimetable
  */
class BrlyMTimetable {

public:
	BrlyMTimetable(const ubigint ref = 0, const ubigint refBrlyMFile = 0, const string srefBrlyKAlliance = "", const string Title = "", const uint startd = 0, const uint stopd = 0);

public:
	ubigint ref;
	ubigint refBrlyMFile;
	string srefBrlyKAlliance;
	string Title;
	uint startd;
	uint stopd;

public:
	bool operator==(const BrlyMTimetable& comp);
	bool operator!=(const BrlyMTimetable& comp);
};

/**
  * ListBrlyMTimetable: recordset of TblBrlyMTimetable
  */
class ListBrlyMTimetable {

public:
	ListBrlyMTimetable();
	ListBrlyMTimetable(const ListBrlyMTimetable& src);
	~ListBrlyMTimetable();

	void clear();
	unsigned int size() const;
	void append(BrlyMTimetable* rec);

	BrlyMTimetable* operator[](const uint ix);
	ListBrlyMTimetable& operator=(const ListBrlyMTimetable& src);
	bool operator==(const ListBrlyMTimetable& comp);
	bool operator!=(const ListBrlyMTimetable& comp);

public:
	vector<BrlyMTimetable*> nodes;
};

/**
  * TblBrlyMTimetable: C++ wrapper for table TblBrlyMTimetable
  */
class TblBrlyMTimetable {

public:

public:
	TblBrlyMTimetable();
	virtual ~TblBrlyMTimetable();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMTimetable** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMTimetable& rst);

	virtual void insertRec(BrlyMTimetable* rec);
	ubigint insertNewRec(BrlyMTimetable** rec = NULL, const ubigint refBrlyMFile = 0, const string srefBrlyKAlliance = "", const string Title = "", const uint startd = 0, const uint stopd = 0);
	ubigint appendNewRecToRst(ListBrlyMTimetable& rst, BrlyMTimetable** rec = NULL, const ubigint refBrlyMFile = 0, const string srefBrlyKAlliance = "", const string Title = "", const uint startd = 0, const uint stopd = 0);
	virtual void insertRst(ListBrlyMTimetable& rst, bool transact = false);
	virtual void updateRec(BrlyMTimetable* rec);
	virtual void updateRst(ListBrlyMTimetable& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMTimetable** rec);
	virtual bool loadTitByRef(ubigint ref, string& Title);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMTimetable& rst);
};

/**
  * MyBrlyMTimetable: C++ wrapper for table TblBrlyMTimetable (MySQL database)
  */
class MyTblBrlyMTimetable : public TblBrlyMTimetable, public MyTable {

public:
	MyTblBrlyMTimetable();
	~MyTblBrlyMTimetable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMTimetable** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMTimetable& rst);

	void insertRec(BrlyMTimetable* rec);
	void insertRst(ListBrlyMTimetable& rst, bool transact = false);
	void updateRec(BrlyMTimetable* rec);
	void updateRst(ListBrlyMTimetable& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMTimetable** rec);
	bool loadTitByRef(ubigint ref, string& Title);
};

/**
  * PgBrlyMTimetable: C++ wrapper for table TblBrlyMTimetable (PgSQL database)
  */
class PgTblBrlyMTimetable : public TblBrlyMTimetable, public PgTable {

public:
	PgTblBrlyMTimetable();
	~PgTblBrlyMTimetable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMTimetable** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMTimetable& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMTimetable** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMTimetable** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMTimetable& rst);

	void insertRec(BrlyMTimetable* rec);
	void insertRst(ListBrlyMTimetable& rst, bool transact = false);
	void updateRec(BrlyMTimetable* rec);
	void updateRst(ListBrlyMTimetable& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMTimetable** rec);
	bool loadTitByRef(ubigint ref, string& Title);
};

#endif

