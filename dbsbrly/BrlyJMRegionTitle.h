/**
  * \file BrlyJMRegionTitle.h
  * database access for table TblBrlyJMRegionTitle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYJMREGIONTITLE_H
#define BRLYJMREGIONTITLE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyJMRegionTitle: record of TblBrlyJMRegionTitle
  */
class BrlyJMRegionTitle {

public:
	BrlyJMRegionTitle(const ubigint ref = 0, const ubigint refBrlyMRegion = 0, const uint x1IxBrlyVLocale = 0, const string Title = "");

public:
	ubigint ref;
	ubigint refBrlyMRegion;
	uint x1IxBrlyVLocale;
	string Title;

public:
	bool operator==(const BrlyJMRegionTitle& comp);
	bool operator!=(const BrlyJMRegionTitle& comp);
};

/**
  * ListBrlyJMRegionTitle: recordset of TblBrlyJMRegionTitle
  */
class ListBrlyJMRegionTitle {

public:
	ListBrlyJMRegionTitle();
	ListBrlyJMRegionTitle(const ListBrlyJMRegionTitle& src);
	~ListBrlyJMRegionTitle();

	void clear();
	unsigned int size() const;
	void append(BrlyJMRegionTitle* rec);

	BrlyJMRegionTitle* operator[](const uint ix);
	ListBrlyJMRegionTitle& operator=(const ListBrlyJMRegionTitle& src);
	bool operator==(const ListBrlyJMRegionTitle& comp);
	bool operator!=(const ListBrlyJMRegionTitle& comp);

public:
	vector<BrlyJMRegionTitle*> nodes;
};

/**
  * TblBrlyJMRegionTitle: C++ wrapper for table TblBrlyJMRegionTitle
  */
class TblBrlyJMRegionTitle {

public:

public:
	TblBrlyJMRegionTitle();
	virtual ~TblBrlyJMRegionTitle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyJMRegionTitle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMRegionTitle& rst);

	virtual void insertRec(BrlyJMRegionTitle* rec);
	ubigint insertNewRec(BrlyJMRegionTitle** rec = NULL, const ubigint refBrlyMRegion = 0, const uint x1IxBrlyVLocale = 0, const string Title = "");
	ubigint appendNewRecToRst(ListBrlyJMRegionTitle& rst, BrlyJMRegionTitle** rec = NULL, const ubigint refBrlyMRegion = 0, const uint x1IxBrlyVLocale = 0, const string Title = "");
	virtual void insertRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	virtual void updateRec(BrlyJMRegionTitle* rec);
	virtual void updateRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyJMRegionTitle** rec);
	virtual bool loadRecByRegLcl(ubigint refBrlyMRegion, uint x1IxBrlyVLocale, BrlyJMRegionTitle** rec);
	virtual ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyJMRegionTitle& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyJMRegionTitle& rst);
};

/**
  * MyBrlyJMRegionTitle: C++ wrapper for table TblBrlyJMRegionTitle (MySQL database)
  */
class MyTblBrlyJMRegionTitle : public TblBrlyJMRegionTitle, public MyTable {

public:
	MyTblBrlyJMRegionTitle();
	~MyTblBrlyJMRegionTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyJMRegionTitle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMRegionTitle& rst);

	void insertRec(BrlyJMRegionTitle* rec);
	void insertRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	void updateRec(BrlyJMRegionTitle* rec);
	void updateRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyJMRegionTitle** rec);
	bool loadRecByRegLcl(ubigint refBrlyMRegion, uint x1IxBrlyVLocale, BrlyJMRegionTitle** rec);
	ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyJMRegionTitle& rst);
};

/**
  * PgBrlyJMRegionTitle: C++ wrapper for table TblBrlyJMRegionTitle (PgSQL database)
  */
class PgTblBrlyJMRegionTitle : public TblBrlyJMRegionTitle, public PgTable {

public:
	PgTblBrlyJMRegionTitle();
	~PgTblBrlyJMRegionTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyJMRegionTitle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyJMRegionTitle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyJMRegionTitle** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyJMRegionTitle& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyJMRegionTitle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMRegionTitle& rst);

	void insertRec(BrlyJMRegionTitle* rec);
	void insertRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	void updateRec(BrlyJMRegionTitle* rec);
	void updateRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyJMRegionTitle** rec);
	bool loadRecByRegLcl(ubigint refBrlyMRegion, uint x1IxBrlyVLocale, BrlyJMRegionTitle** rec);
	ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyJMRegionTitle& rst);
};

#endif

