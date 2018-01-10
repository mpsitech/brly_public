/**
  * \file BrlyQLocEqpMNConnection.h
  * Dbs and XML wrapper for table TblBrlyQLocEqpMNConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCEQPMNCONNECTION_H
#define BRLYQLOCEQPMNCONNECTION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocEqpMNConnection: record of TblBrlyQLocEqpMNConnection
  */
class BrlyQLocEqpMNConnection {

public:
	BrlyQLocEqpMNConnection(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint conIxBrlyVLat = 0, const string srefConIxBrlyVLat = "");

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
  * ListBrlyQLocEqpMNConnection: recordset of TblBrlyQLocEqpMNConnection
  */
class ListBrlyQLocEqpMNConnection {

public:
	ListBrlyQLocEqpMNConnection();
	ListBrlyQLocEqpMNConnection(const ListBrlyQLocEqpMNConnection& src);
	~ListBrlyQLocEqpMNConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocEqpMNConnection* rec);

	ListBrlyQLocEqpMNConnection& operator=(const ListBrlyQLocEqpMNConnection& src);

public:
	vector<BrlyQLocEqpMNConnection*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocEqpMNConnection: C++ wrapper for table TblBrlyQLocEqpMNConnection
  */
class TblBrlyQLocEqpMNConnection {

public:
	TblBrlyQLocEqpMNConnection();
	virtual ~TblBrlyQLocEqpMNConnection();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocEqpMNConnection** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocEqpMNConnection& rst);

	virtual void insertRec(BrlyQLocEqpMNConnection* rec);
	ubigint insertNewRec(BrlyQLocEqpMNConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint conIxBrlyVLat = 0, const string srefConIxBrlyVLat = "");
	ubigint appendNewRecToRst(ListBrlyQLocEqpMNConnection& rst, BrlyQLocEqpMNConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint conIxBrlyVLat = 0, const string srefConIxBrlyVLat = "");
	virtual void insertRst(ListBrlyQLocEqpMNConnection& rst);
	virtual void updateRec(BrlyQLocEqpMNConnection* rec);
	virtual void updateRst(ListBrlyQLocEqpMNConnection& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocEqpMNConnection** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocEqpMNConnection& rst);
};

/**
  * MyBrlyQLocEqpMNConnection: C++ wrapper for table TblBrlyQLocEqpMNConnection (MySQL database)
  */
class MyTblBrlyQLocEqpMNConnection : public TblBrlyQLocEqpMNConnection, public MyTable {

public:
	MyTblBrlyQLocEqpMNConnection();
	~MyTblBrlyQLocEqpMNConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocEqpMNConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocEqpMNConnection& rst);

	void insertRec(BrlyQLocEqpMNConnection* rec);
	void insertRst(ListBrlyQLocEqpMNConnection& rst);
	void updateRec(BrlyQLocEqpMNConnection* rec);
	void updateRst(ListBrlyQLocEqpMNConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocEqpMNConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocEqpMNConnection& rst);
};

/**
  * PgBrlyQLocEqpMNConnection: C++ wrapper for table TblBrlyQLocEqpMNConnection (PgSQL database)
  */
class PgTblBrlyQLocEqpMNConnection : public TblBrlyQLocEqpMNConnection, public PgTable {

public:
	PgTblBrlyQLocEqpMNConnection();
	~PgTblBrlyQLocEqpMNConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocEqpMNConnection** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocEqpMNConnection& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocEqpMNConnection** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocEqpMNConnection& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocEqpMNConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocEqpMNConnection& rst);

	void insertRec(BrlyQLocEqpMNConnection* rec);
	void insertRst(ListBrlyQLocEqpMNConnection& rst);
	void updateRec(BrlyQLocEqpMNConnection* rec);
	void updateRst(ListBrlyQLocEqpMNConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocEqpMNConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocEqpMNConnection& rst);
};

#endif

