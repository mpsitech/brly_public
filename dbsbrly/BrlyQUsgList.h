/**
  * \file BrlyQUsgList.h
  * Dbs and XML wrapper for table TblBrlyQUsgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSGLIST_H
#define BRLYQUSGLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsgList: record of TblBrlyQUsgList
  */
class BrlyQUsgList {

public:
	BrlyQUsgList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQUsgList: recordset of TblBrlyQUsgList
  */
class ListBrlyQUsgList {

public:
	ListBrlyQUsgList();
	ListBrlyQUsgList(const ListBrlyQUsgList& src);
	~ListBrlyQUsgList();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsgList* rec);

	ListBrlyQUsgList& operator=(const ListBrlyQUsgList& src);

public:
	vector<BrlyQUsgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQUsgList: C++ wrapper for table TblBrlyQUsgList
  */
class TblBrlyQUsgList {

public:
	TblBrlyQUsgList();
	virtual ~TblBrlyQUsgList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQUsgList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsgList& rst);

	virtual void insertRec(BrlyQUsgList* rec);
	ubigint insertNewRec(BrlyQUsgList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");
	ubigint appendNewRecToRst(ListBrlyQUsgList& rst, BrlyQUsgList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");
	virtual void insertRst(ListBrlyQUsgList& rst);
	virtual void updateRec(BrlyQUsgList* rec);
	virtual void updateRst(ListBrlyQUsgList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQUsgList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsgList& rst);
};

/**
  * MyBrlyQUsgList: C++ wrapper for table TblBrlyQUsgList (MySQL database)
  */
class MyTblBrlyQUsgList : public TblBrlyQUsgList, public MyTable {

public:
	MyTblBrlyQUsgList();
	~MyTblBrlyQUsgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsgList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsgList& rst);

	void insertRec(BrlyQUsgList* rec);
	void insertRst(ListBrlyQUsgList& rst);
	void updateRec(BrlyQUsgList* rec);
	void updateRst(ListBrlyQUsgList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsgList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsgList& rst);
};

/**
  * PgBrlyQUsgList: C++ wrapper for table TblBrlyQUsgList (PgSQL database)
  */
class PgTblBrlyQUsgList : public TblBrlyQUsgList, public PgTable {

public:
	PgTblBrlyQUsgList();
	~PgTblBrlyQUsgList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsgList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsgList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsgList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsgList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsgList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsgList& rst);

	void insertRec(BrlyQUsgList* rec);
	void insertRst(ListBrlyQUsgList& rst);
	void updateRec(BrlyQUsgList* rec);
	void updateRst(ListBrlyQUsgList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsgList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsgList& rst);
};

#endif

