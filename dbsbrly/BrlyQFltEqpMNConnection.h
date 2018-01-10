/**
  * \file BrlyQFltEqpMNConnection.h
  * Dbs and XML wrapper for table TblBrlyQFltEqpMNConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTEQPMNCONNECTION_H
#define BRLYQFLTEQPMNCONNECTION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltEqpMNConnection: record of TblBrlyQFltEqpMNConnection
  */
class BrlyQFltEqpMNConnection {

public:
	BrlyQFltEqpMNConnection(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint conIxBrlyVLat = 0, const string srefConIxBrlyVLat = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint conIxBrlyVLat;
	string srefConIxBrlyVLat;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQFltEqpMNConnection: recordset of TblBrlyQFltEqpMNConnection
  */
class ListBrlyQFltEqpMNConnection {

public:
	ListBrlyQFltEqpMNConnection();
	ListBrlyQFltEqpMNConnection(const ListBrlyQFltEqpMNConnection& src);
	~ListBrlyQFltEqpMNConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltEqpMNConnection* rec);

	ListBrlyQFltEqpMNConnection& operator=(const ListBrlyQFltEqpMNConnection& src);

public:
	vector<BrlyQFltEqpMNConnection*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQFltEqpMNConnection: C++ wrapper for table TblBrlyQFltEqpMNConnection
  */
class TblBrlyQFltEqpMNConnection {

public:
	TblBrlyQFltEqpMNConnection();
	virtual ~TblBrlyQFltEqpMNConnection();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQFltEqpMNConnection** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltEqpMNConnection& rst);

	virtual void insertRec(BrlyQFltEqpMNConnection* rec);
	ubigint insertNewRec(BrlyQFltEqpMNConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint conIxBrlyVLat = 0, const string srefConIxBrlyVLat = "");
	ubigint appendNewRecToRst(ListBrlyQFltEqpMNConnection& rst, BrlyQFltEqpMNConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint conIxBrlyVLat = 0, const string srefConIxBrlyVLat = "");
	virtual void insertRst(ListBrlyQFltEqpMNConnection& rst);
	virtual void updateRec(BrlyQFltEqpMNConnection* rec);
	virtual void updateRst(ListBrlyQFltEqpMNConnection& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQFltEqpMNConnection** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltEqpMNConnection& rst);
};

/**
  * MyBrlyQFltEqpMNConnection: C++ wrapper for table TblBrlyQFltEqpMNConnection (MySQL database)
  */
class MyTblBrlyQFltEqpMNConnection : public TblBrlyQFltEqpMNConnection, public MyTable {

public:
	MyTblBrlyQFltEqpMNConnection();
	~MyTblBrlyQFltEqpMNConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltEqpMNConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltEqpMNConnection& rst);

	void insertRec(BrlyQFltEqpMNConnection* rec);
	void insertRst(ListBrlyQFltEqpMNConnection& rst);
	void updateRec(BrlyQFltEqpMNConnection* rec);
	void updateRst(ListBrlyQFltEqpMNConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltEqpMNConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltEqpMNConnection& rst);
};

/**
  * PgBrlyQFltEqpMNConnection: C++ wrapper for table TblBrlyQFltEqpMNConnection (PgSQL database)
  */
class PgTblBrlyQFltEqpMNConnection : public TblBrlyQFltEqpMNConnection, public PgTable {

public:
	PgTblBrlyQFltEqpMNConnection();
	~PgTblBrlyQFltEqpMNConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltEqpMNConnection** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltEqpMNConnection& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltEqpMNConnection** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltEqpMNConnection& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltEqpMNConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltEqpMNConnection& rst);

	void insertRec(BrlyQFltEqpMNConnection* rec);
	void insertRst(ListBrlyQFltEqpMNConnection& rst);
	void updateRec(BrlyQFltEqpMNConnection* rec);
	void updateRst(ListBrlyQFltEqpMNConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltEqpMNConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltEqpMNConnection& rst);
};

#endif

