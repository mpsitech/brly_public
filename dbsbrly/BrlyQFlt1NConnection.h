/**
  * \file BrlyQFlt1NConnection.h
  * Dbs and XML wrapper for table TblBrlyQFlt1NConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLT1NCONNECTION_H
#define BRLYQFLT1NCONNECTION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFlt1NConnection: record of TblBrlyQFlt1NConnection
  */
class BrlyQFlt1NConnection {

public:
	BrlyQFlt1NConnection(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQFlt1NConnection: recordset of TblBrlyQFlt1NConnection
  */
class ListBrlyQFlt1NConnection {

public:
	ListBrlyQFlt1NConnection();
	ListBrlyQFlt1NConnection(const ListBrlyQFlt1NConnection& src);
	~ListBrlyQFlt1NConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQFlt1NConnection* rec);

	ListBrlyQFlt1NConnection& operator=(const ListBrlyQFlt1NConnection& src);

public:
	vector<BrlyQFlt1NConnection*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQFlt1NConnection: C++ wrapper for table TblBrlyQFlt1NConnection
  */
class TblBrlyQFlt1NConnection {

public:
	TblBrlyQFlt1NConnection();
	virtual ~TblBrlyQFlt1NConnection();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQFlt1NConnection** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFlt1NConnection& rst);

	virtual void insertRec(BrlyQFlt1NConnection* rec);
	ubigint insertNewRec(BrlyQFlt1NConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQFlt1NConnection& rst, BrlyQFlt1NConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQFlt1NConnection& rst);
	virtual void updateRec(BrlyQFlt1NConnection* rec);
	virtual void updateRst(ListBrlyQFlt1NConnection& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQFlt1NConnection** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFlt1NConnection& rst);
};

/**
  * MyBrlyQFlt1NConnection: C++ wrapper for table TblBrlyQFlt1NConnection (MySQL database)
  */
class MyTblBrlyQFlt1NConnection : public TblBrlyQFlt1NConnection, public MyTable {

public:
	MyTblBrlyQFlt1NConnection();
	~MyTblBrlyQFlt1NConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFlt1NConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFlt1NConnection& rst);

	void insertRec(BrlyQFlt1NConnection* rec);
	void insertRst(ListBrlyQFlt1NConnection& rst);
	void updateRec(BrlyQFlt1NConnection* rec);
	void updateRst(ListBrlyQFlt1NConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFlt1NConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFlt1NConnection& rst);
};

/**
  * PgBrlyQFlt1NConnection: C++ wrapper for table TblBrlyQFlt1NConnection (PgSQL database)
  */
class PgTblBrlyQFlt1NConnection : public TblBrlyQFlt1NConnection, public PgTable {

public:
	PgTblBrlyQFlt1NConnection();
	~PgTblBrlyQFlt1NConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFlt1NConnection** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQFlt1NConnection& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFlt1NConnection** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFlt1NConnection& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFlt1NConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFlt1NConnection& rst);

	void insertRec(BrlyQFlt1NConnection* rec);
	void insertRst(ListBrlyQFlt1NConnection& rst);
	void updateRec(BrlyQFlt1NConnection* rec);
	void updateRst(ListBrlyQFlt1NConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFlt1NConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFlt1NConnection& rst);
};

#endif

