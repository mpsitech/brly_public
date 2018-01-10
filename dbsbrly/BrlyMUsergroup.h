/**
  * \file BrlyMUsergroup.h
  * database access for table TblBrlyMUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMUSERGROUP_H
#define BRLYMUSERGROUP_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyMUsergroup: record of TblBrlyMUsergroup
  */
class BrlyMUsergroup {

public:
	BrlyMUsergroup(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	string sref;
	string Comment;

public:
	bool operator==(const BrlyMUsergroup& comp);
	bool operator!=(const BrlyMUsergroup& comp);
};

/**
  * ListBrlyMUsergroup: recordset of TblBrlyMUsergroup
  */
class ListBrlyMUsergroup {

public:
	ListBrlyMUsergroup();
	ListBrlyMUsergroup(const ListBrlyMUsergroup& src);
	~ListBrlyMUsergroup();

	void clear();
	unsigned int size() const;
	void append(BrlyMUsergroup* rec);

	BrlyMUsergroup* operator[](const uint ix);
	ListBrlyMUsergroup& operator=(const ListBrlyMUsergroup& src);
	bool operator==(const ListBrlyMUsergroup& comp);
	bool operator!=(const ListBrlyMUsergroup& comp);

public:
	vector<BrlyMUsergroup*> nodes;
};

/**
  * TblBrlyMUsergroup: C++ wrapper for table TblBrlyMUsergroup
  */
class TblBrlyMUsergroup {

public:

public:
	TblBrlyMUsergroup();
	virtual ~TblBrlyMUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMUsergroup& rst);

	virtual void insertRec(BrlyMUsergroup* rec);
	ubigint insertNewRec(BrlyMUsergroup** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");
	ubigint appendNewRecToRst(ListBrlyMUsergroup& rst, BrlyMUsergroup** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");
	virtual void insertRst(ListBrlyMUsergroup& rst, bool transact = false);
	virtual void updateRec(BrlyMUsergroup* rec);
	virtual void updateRst(ListBrlyMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMUsergroup** rec);
	virtual bool loadRecBySrf(string sref, BrlyMUsergroup** rec);
	virtual bool loadRefBySrf(string sref, ubigint& ref);
	virtual bool loadSrfByRef(ubigint ref, string& sref);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMUsergroup& rst);
};

/**
  * MyBrlyMUsergroup: C++ wrapper for table TblBrlyMUsergroup (MySQL database)
  */
class MyTblBrlyMUsergroup : public TblBrlyMUsergroup, public MyTable {

public:
	MyTblBrlyMUsergroup();
	~MyTblBrlyMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMUsergroup& rst);

	void insertRec(BrlyMUsergroup* rec);
	void insertRst(ListBrlyMUsergroup& rst, bool transact = false);
	void updateRec(BrlyMUsergroup* rec);
	void updateRst(ListBrlyMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMUsergroup** rec);
	bool loadRecBySrf(string sref, BrlyMUsergroup** rec);
	bool loadRefBySrf(string sref, ubigint& ref);
	bool loadSrfByRef(ubigint ref, string& sref);
};

/**
  * PgBrlyMUsergroup: C++ wrapper for table TblBrlyMUsergroup (PgSQL database)
  */
class PgTblBrlyMUsergroup : public TblBrlyMUsergroup, public PgTable {

public:
	PgTblBrlyMUsergroup();
	~PgTblBrlyMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMUsergroup** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMUsergroup& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMUsergroup** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMUsergroup& rst);

	void insertRec(BrlyMUsergroup* rec);
	void insertRst(ListBrlyMUsergroup& rst, bool transact = false);
	void updateRec(BrlyMUsergroup* rec);
	void updateRst(ListBrlyMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMUsergroup** rec);
	bool loadRecBySrf(string sref, BrlyMUsergroup** rec);
	bool loadRefBySrf(string sref, ubigint& ref);
	bool loadSrfByRef(ubigint ref, string& sref);
};

#endif

