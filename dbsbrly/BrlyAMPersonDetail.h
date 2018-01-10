/**
  * \file BrlyAMPersonDetail.h
  * database access for table TblBrlyAMPersonDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYAMPERSONDETAIL_H
#define BRLYAMPERSONDETAIL_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyAMPersonDetail: record of TblBrlyAMPersonDetail
  */
class BrlyAMPersonDetail {

public:
	BrlyAMPersonDetail(const ubigint ref = 0, const ubigint refBrlyMPerson = 0, const string x1SrefKType = "", const string Val = "");

public:
	ubigint ref;
	ubigint refBrlyMPerson;
	string x1SrefKType;
	string Val;

public:
	bool operator==(const BrlyAMPersonDetail& comp);
	bool operator!=(const BrlyAMPersonDetail& comp);
};

/**
  * ListBrlyAMPersonDetail: recordset of TblBrlyAMPersonDetail
  */
class ListBrlyAMPersonDetail {

public:
	ListBrlyAMPersonDetail();
	ListBrlyAMPersonDetail(const ListBrlyAMPersonDetail& src);
	~ListBrlyAMPersonDetail();

	void clear();
	unsigned int size() const;
	void append(BrlyAMPersonDetail* rec);

	BrlyAMPersonDetail* operator[](const uint ix);
	ListBrlyAMPersonDetail& operator=(const ListBrlyAMPersonDetail& src);
	bool operator==(const ListBrlyAMPersonDetail& comp);
	bool operator!=(const ListBrlyAMPersonDetail& comp);

public:
	vector<BrlyAMPersonDetail*> nodes;
};

/**
  * TblBrlyAMPersonDetail: C++ wrapper for table TblBrlyAMPersonDetail
  */
class TblBrlyAMPersonDetail {

public:

public:
	TblBrlyAMPersonDetail();
	virtual ~TblBrlyAMPersonDetail();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyAMPersonDetail** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMPersonDetail& rst);

	virtual void insertRec(BrlyAMPersonDetail* rec);
	ubigint insertNewRec(BrlyAMPersonDetail** rec = NULL, const ubigint refBrlyMPerson = 0, const string x1SrefKType = "", const string Val = "");
	ubigint appendNewRecToRst(ListBrlyAMPersonDetail& rst, BrlyAMPersonDetail** rec = NULL, const ubigint refBrlyMPerson = 0, const string x1SrefKType = "", const string Val = "");
	virtual void insertRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	virtual void updateRec(BrlyAMPersonDetail* rec);
	virtual void updateRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyAMPersonDetail** rec);
	virtual bool loadRecByPrsTyp(ubigint refBrlyMPerson, string x1SrefKType, BrlyAMPersonDetail** rec);
	virtual ubigint loadRstByPrs(ubigint refBrlyMPerson, const bool append, ListBrlyAMPersonDetail& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyAMPersonDetail& rst);
};

/**
  * MyBrlyAMPersonDetail: C++ wrapper for table TblBrlyAMPersonDetail (MySQL database)
  */
class MyTblBrlyAMPersonDetail : public TblBrlyAMPersonDetail, public MyTable {

public:
	MyTblBrlyAMPersonDetail();
	~MyTblBrlyAMPersonDetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAMPersonDetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMPersonDetail& rst);

	void insertRec(BrlyAMPersonDetail* rec);
	void insertRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	void updateRec(BrlyAMPersonDetail* rec);
	void updateRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAMPersonDetail** rec);
	bool loadRecByPrsTyp(ubigint refBrlyMPerson, string x1SrefKType, BrlyAMPersonDetail** rec);
	ubigint loadRstByPrs(ubigint refBrlyMPerson, const bool append, ListBrlyAMPersonDetail& rst);
};

/**
  * PgBrlyAMPersonDetail: C++ wrapper for table TblBrlyAMPersonDetail (PgSQL database)
  */
class PgTblBrlyAMPersonDetail : public TblBrlyAMPersonDetail, public PgTable {

public:
	PgTblBrlyAMPersonDetail();
	~PgTblBrlyAMPersonDetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAMPersonDetail** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyAMPersonDetail& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAMPersonDetail** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAMPersonDetail& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAMPersonDetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMPersonDetail& rst);

	void insertRec(BrlyAMPersonDetail* rec);
	void insertRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	void updateRec(BrlyAMPersonDetail* rec);
	void updateRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAMPersonDetail** rec);
	bool loadRecByPrsTyp(ubigint refBrlyMPerson, string x1SrefKType, BrlyAMPersonDetail** rec);
	ubigint loadRstByPrs(ubigint refBrlyMPerson, const bool append, ListBrlyAMPersonDetail& rst);
};

#endif

