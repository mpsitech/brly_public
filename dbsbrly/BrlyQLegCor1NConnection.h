/**
  * \file BrlyQLegCor1NConnection.h
  * Dbs and XML wrapper for table TblBrlyQLegCor1NConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGCOR1NCONNECTION_H
#define BRLYQLEGCOR1NCONNECTION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegCor1NConnection: record of TblBrlyQLegCor1NConnection
  */
class BrlyQLegCor1NConnection {

public:
	BrlyQLegCor1NConnection(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQLegCor1NConnection: recordset of TblBrlyQLegCor1NConnection
  */
class ListBrlyQLegCor1NConnection {

public:
	ListBrlyQLegCor1NConnection();
	ListBrlyQLegCor1NConnection(const ListBrlyQLegCor1NConnection& src);
	~ListBrlyQLegCor1NConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegCor1NConnection* rec);

	ListBrlyQLegCor1NConnection& operator=(const ListBrlyQLegCor1NConnection& src);

public:
	vector<BrlyQLegCor1NConnection*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLegCor1NConnection: C++ wrapper for table TblBrlyQLegCor1NConnection
  */
class TblBrlyQLegCor1NConnection {

public:
	TblBrlyQLegCor1NConnection();
	virtual ~TblBrlyQLegCor1NConnection();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLegCor1NConnection** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegCor1NConnection& rst);

	virtual void insertRec(BrlyQLegCor1NConnection* rec);
	ubigint insertNewRec(BrlyQLegCor1NConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQLegCor1NConnection& rst, BrlyQLegCor1NConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQLegCor1NConnection& rst);
	virtual void updateRec(BrlyQLegCor1NConnection* rec);
	virtual void updateRst(ListBrlyQLegCor1NConnection& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLegCor1NConnection** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegCor1NConnection& rst);
};

/**
  * MyBrlyQLegCor1NConnection: C++ wrapper for table TblBrlyQLegCor1NConnection (MySQL database)
  */
class MyTblBrlyQLegCor1NConnection : public TblBrlyQLegCor1NConnection, public MyTable {

public:
	MyTblBrlyQLegCor1NConnection();
	~MyTblBrlyQLegCor1NConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegCor1NConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegCor1NConnection& rst);

	void insertRec(BrlyQLegCor1NConnection* rec);
	void insertRst(ListBrlyQLegCor1NConnection& rst);
	void updateRec(BrlyQLegCor1NConnection* rec);
	void updateRst(ListBrlyQLegCor1NConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegCor1NConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegCor1NConnection& rst);
};

/**
  * PgBrlyQLegCor1NConnection: C++ wrapper for table TblBrlyQLegCor1NConnection (PgSQL database)
  */
class PgTblBrlyQLegCor1NConnection : public TblBrlyQLegCor1NConnection, public PgTable {

public:
	PgTblBrlyQLegCor1NConnection();
	~PgTblBrlyQLegCor1NConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegCor1NConnection** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegCor1NConnection& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegCor1NConnection** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegCor1NConnection& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegCor1NConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegCor1NConnection& rst);

	void insertRec(BrlyQLegCor1NConnection* rec);
	void insertRst(ListBrlyQLegCor1NConnection& rst);
	void updateRec(BrlyQLegCor1NConnection* rec);
	void updateRst(ListBrlyQLegCor1NConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegCor1NConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegCor1NConnection& rst);
};

#endif

