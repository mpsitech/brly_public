/**
  * \file BrlyQUsr1NSession.h
  * Dbs and XML wrapper for table TblBrlyQUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSR1NSESSION_H
#define BRLYQUSR1NSESSION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsr1NSession: record of TblBrlyQUsr1NSession
  */
class BrlyQUsr1NSession {

public:
	BrlyQUsr1NSession(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQUsr1NSession: recordset of TblBrlyQUsr1NSession
  */
class ListBrlyQUsr1NSession {

public:
	ListBrlyQUsr1NSession();
	ListBrlyQUsr1NSession(const ListBrlyQUsr1NSession& src);
	~ListBrlyQUsr1NSession();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsr1NSession* rec);

	ListBrlyQUsr1NSession& operator=(const ListBrlyQUsr1NSession& src);

public:
	vector<BrlyQUsr1NSession*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQUsr1NSession: C++ wrapper for table TblBrlyQUsr1NSession
  */
class TblBrlyQUsr1NSession {

public:
	TblBrlyQUsr1NSession();
	virtual ~TblBrlyQUsr1NSession();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQUsr1NSession** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsr1NSession& rst);

	virtual void insertRec(BrlyQUsr1NSession* rec);
	ubigint insertNewRec(BrlyQUsr1NSession** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQUsr1NSession& rst, BrlyQUsr1NSession** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQUsr1NSession& rst);
	virtual void updateRec(BrlyQUsr1NSession* rec);
	virtual void updateRst(ListBrlyQUsr1NSession& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQUsr1NSession** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsr1NSession& rst);
};

/**
  * MyBrlyQUsr1NSession: C++ wrapper for table TblBrlyQUsr1NSession (MySQL database)
  */
class MyTblBrlyQUsr1NSession : public TblBrlyQUsr1NSession, public MyTable {

public:
	MyTblBrlyQUsr1NSession();
	~MyTblBrlyQUsr1NSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsr1NSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsr1NSession& rst);

	void insertRec(BrlyQUsr1NSession* rec);
	void insertRst(ListBrlyQUsr1NSession& rst);
	void updateRec(BrlyQUsr1NSession* rec);
	void updateRst(ListBrlyQUsr1NSession& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsr1NSession** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsr1NSession& rst);
};

/**
  * PgBrlyQUsr1NSession: C++ wrapper for table TblBrlyQUsr1NSession (PgSQL database)
  */
class PgTblBrlyQUsr1NSession : public TblBrlyQUsr1NSession, public PgTable {

public:
	PgTblBrlyQUsr1NSession();
	~PgTblBrlyQUsr1NSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsr1NSession** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsr1NSession& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsr1NSession** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsr1NSession& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsr1NSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsr1NSession& rst);

	void insertRec(BrlyQUsr1NSession* rec);
	void insertRst(ListBrlyQUsr1NSession& rst);
	void updateRec(BrlyQUsr1NSession* rec);
	void updateRst(ListBrlyQUsr1NSession& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsr1NSession** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsr1NSession& rst);
};

#endif

