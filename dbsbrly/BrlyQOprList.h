/**
  * \file BrlyQOprList.h
  * Dbs and XML wrapper for table TblBrlyQOprList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQOPRLIST_H
#define BRLYQOPRLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQOprList: record of TblBrlyQOprList
  */
class BrlyQOprList {

public:
	BrlyQOprList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string srefICAO = "", const string Title = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	string srefICAO;
	string Title;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQOprList: recordset of TblBrlyQOprList
  */
class ListBrlyQOprList {

public:
	ListBrlyQOprList();
	ListBrlyQOprList(const ListBrlyQOprList& src);
	~ListBrlyQOprList();

	void clear();
	unsigned int size() const;
	void append(BrlyQOprList* rec);

	ListBrlyQOprList& operator=(const ListBrlyQOprList& src);

public:
	vector<BrlyQOprList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQOprList: C++ wrapper for table TblBrlyQOprList
  */
class TblBrlyQOprList {

public:
	TblBrlyQOprList();
	virtual ~TblBrlyQOprList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQOprList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQOprList& rst);

	virtual void insertRec(BrlyQOprList* rec);
	ubigint insertNewRec(BrlyQOprList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string srefICAO = "", const string Title = "");
	ubigint appendNewRecToRst(ListBrlyQOprList& rst, BrlyQOprList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string srefICAO = "", const string Title = "");
	virtual void insertRst(ListBrlyQOprList& rst);
	virtual void updateRec(BrlyQOprList* rec);
	virtual void updateRst(ListBrlyQOprList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQOprList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQOprList& rst);
};

/**
  * MyBrlyQOprList: C++ wrapper for table TblBrlyQOprList (MySQL database)
  */
class MyTblBrlyQOprList : public TblBrlyQOprList, public MyTable {

public:
	MyTblBrlyQOprList();
	~MyTblBrlyQOprList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQOprList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQOprList& rst);

	void insertRec(BrlyQOprList* rec);
	void insertRst(ListBrlyQOprList& rst);
	void updateRec(BrlyQOprList* rec);
	void updateRst(ListBrlyQOprList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQOprList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQOprList& rst);
};

/**
  * PgBrlyQOprList: C++ wrapper for table TblBrlyQOprList (PgSQL database)
  */
class PgTblBrlyQOprList : public TblBrlyQOprList, public PgTable {

public:
	PgTblBrlyQOprList();
	~PgTblBrlyQOprList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQOprList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQOprList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQOprList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQOprList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQOprList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQOprList& rst);

	void insertRec(BrlyQOprList* rec);
	void insertRst(ListBrlyQOprList& rst);
	void updateRec(BrlyQOprList* rec);
	void updateRst(ListBrlyQOprList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQOprList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQOprList& rst);
};

#endif

