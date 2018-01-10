/**
  * \file BrlyQPtyList.h
  * Dbs and XML wrapper for table TblBrlyQPtyList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQPTYLIST_H
#define BRLYQPTYLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQPtyList: record of TblBrlyQPtyList
  */
class BrlyQPtyList {

public:
	BrlyQPtyList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const string srefBrlyKEqptype = "", const string titSrefBrlyKEqptype = "", const usmallint Capacity = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	string Title;
	string srefBrlyKEqptype;
	string titSrefBrlyKEqptype;
	usmallint Capacity;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQPtyList: recordset of TblBrlyQPtyList
  */
class ListBrlyQPtyList {

public:
	ListBrlyQPtyList();
	ListBrlyQPtyList(const ListBrlyQPtyList& src);
	~ListBrlyQPtyList();

	void clear();
	unsigned int size() const;
	void append(BrlyQPtyList* rec);

	ListBrlyQPtyList& operator=(const ListBrlyQPtyList& src);

public:
	vector<BrlyQPtyList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQPtyList: C++ wrapper for table TblBrlyQPtyList
  */
class TblBrlyQPtyList {

public:
	TblBrlyQPtyList();
	virtual ~TblBrlyQPtyList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQPtyList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPtyList& rst);

	virtual void insertRec(BrlyQPtyList* rec);
	ubigint insertNewRec(BrlyQPtyList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const string srefBrlyKEqptype = "", const string titSrefBrlyKEqptype = "", const usmallint Capacity = 0);
	ubigint appendNewRecToRst(ListBrlyQPtyList& rst, BrlyQPtyList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const string srefBrlyKEqptype = "", const string titSrefBrlyKEqptype = "", const usmallint Capacity = 0);
	virtual void insertRst(ListBrlyQPtyList& rst);
	virtual void updateRec(BrlyQPtyList* rec);
	virtual void updateRst(ListBrlyQPtyList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQPtyList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPtyList& rst);
};

/**
  * MyBrlyQPtyList: C++ wrapper for table TblBrlyQPtyList (MySQL database)
  */
class MyTblBrlyQPtyList : public TblBrlyQPtyList, public MyTable {

public:
	MyTblBrlyQPtyList();
	~MyTblBrlyQPtyList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQPtyList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPtyList& rst);

	void insertRec(BrlyQPtyList* rec);
	void insertRst(ListBrlyQPtyList& rst);
	void updateRec(BrlyQPtyList* rec);
	void updateRst(ListBrlyQPtyList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQPtyList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPtyList& rst);
};

/**
  * PgBrlyQPtyList: C++ wrapper for table TblBrlyQPtyList (PgSQL database)
  */
class PgTblBrlyQPtyList : public TblBrlyQPtyList, public PgTable {

public:
	PgTblBrlyQPtyList();
	~PgTblBrlyQPtyList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQPtyList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQPtyList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQPtyList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQPtyList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQPtyList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPtyList& rst);

	void insertRec(BrlyQPtyList* rec);
	void insertRst(ListBrlyQPtyList& rst);
	void updateRec(BrlyQPtyList* rec);
	void updateRst(ListBrlyQPtyList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQPtyList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPtyList& rst);
};

#endif

