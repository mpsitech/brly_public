/**
  * \file BrlyJMPersonLastname.h
  * database access for table TblBrlyJMPersonLastname (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYJMPERSONLASTNAME_H
#define BRLYJMPERSONLASTNAME_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyJMPersonLastname: record of TblBrlyJMPersonLastname
  */
class BrlyJMPersonLastname {

public:
	BrlyJMPersonLastname(const ubigint ref = 0, const ubigint refBrlyMPerson = 0, const uint x1Startd = 0, const string Lastname = "");

public:
	ubigint ref;
	ubigint refBrlyMPerson;
	uint x1Startd;
	string Lastname;

public:
	bool operator==(const BrlyJMPersonLastname& comp);
	bool operator!=(const BrlyJMPersonLastname& comp);
};

/**
  * ListBrlyJMPersonLastname: recordset of TblBrlyJMPersonLastname
  */
class ListBrlyJMPersonLastname {

public:
	ListBrlyJMPersonLastname();
	ListBrlyJMPersonLastname(const ListBrlyJMPersonLastname& src);
	~ListBrlyJMPersonLastname();

	void clear();
	unsigned int size() const;
	void append(BrlyJMPersonLastname* rec);

	BrlyJMPersonLastname* operator[](const uint ix);
	ListBrlyJMPersonLastname& operator=(const ListBrlyJMPersonLastname& src);
	bool operator==(const ListBrlyJMPersonLastname& comp);
	bool operator!=(const ListBrlyJMPersonLastname& comp);

public:
	vector<BrlyJMPersonLastname*> nodes;
};

/**
  * TblBrlyJMPersonLastname: C++ wrapper for table TblBrlyJMPersonLastname
  */
class TblBrlyJMPersonLastname {

public:

public:
	TblBrlyJMPersonLastname();
	virtual ~TblBrlyJMPersonLastname();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyJMPersonLastname** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMPersonLastname& rst);

	virtual void insertRec(BrlyJMPersonLastname* rec);
	ubigint insertNewRec(BrlyJMPersonLastname** rec = NULL, const ubigint refBrlyMPerson = 0, const uint x1Startd = 0, const string Lastname = "");
	ubigint appendNewRecToRst(ListBrlyJMPersonLastname& rst, BrlyJMPersonLastname** rec = NULL, const ubigint refBrlyMPerson = 0, const uint x1Startd = 0, const string Lastname = "");
	virtual void insertRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	virtual void updateRec(BrlyJMPersonLastname* rec);
	virtual void updateRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyJMPersonLastname** rec);
	virtual bool loadRecByPrsSta(ubigint refBrlyMPerson, uint x1Startd, BrlyJMPersonLastname** rec);
	virtual ubigint loadRefsByPrs(ubigint refBrlyMPerson, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByPrs(ubigint refBrlyMPerson, const bool append, ListBrlyJMPersonLastname& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyJMPersonLastname& rst);
};

/**
  * MyBrlyJMPersonLastname: C++ wrapper for table TblBrlyJMPersonLastname (MySQL database)
  */
class MyTblBrlyJMPersonLastname : public TblBrlyJMPersonLastname, public MyTable {

public:
	MyTblBrlyJMPersonLastname();
	~MyTblBrlyJMPersonLastname();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyJMPersonLastname** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMPersonLastname& rst);

	void insertRec(BrlyJMPersonLastname* rec);
	void insertRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	void updateRec(BrlyJMPersonLastname* rec);
	void updateRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyJMPersonLastname** rec);
	bool loadRecByPrsSta(ubigint refBrlyMPerson, uint x1Startd, BrlyJMPersonLastname** rec);
	ubigint loadRefsByPrs(ubigint refBrlyMPerson, const bool append, vector<ubigint>& refs);
	ubigint loadRstByPrs(ubigint refBrlyMPerson, const bool append, ListBrlyJMPersonLastname& rst);
};

/**
  * PgBrlyJMPersonLastname: C++ wrapper for table TblBrlyJMPersonLastname (PgSQL database)
  */
class PgTblBrlyJMPersonLastname : public TblBrlyJMPersonLastname, public PgTable {

public:
	PgTblBrlyJMPersonLastname();
	~PgTblBrlyJMPersonLastname();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyJMPersonLastname** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyJMPersonLastname& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyJMPersonLastname** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyJMPersonLastname& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyJMPersonLastname** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMPersonLastname& rst);

	void insertRec(BrlyJMPersonLastname* rec);
	void insertRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	void updateRec(BrlyJMPersonLastname* rec);
	void updateRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyJMPersonLastname** rec);
	bool loadRecByPrsSta(ubigint refBrlyMPerson, uint x1Startd, BrlyJMPersonLastname** rec);
	ubigint loadRefsByPrs(ubigint refBrlyMPerson, const bool append, vector<ubigint>& refs);
	ubigint loadRstByPrs(ubigint refBrlyMPerson, const bool append, ListBrlyJMPersonLastname& rst);
};

#endif

