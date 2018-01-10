/**
  * \file BrlyQSegMNConnection.h
  * Dbs and XML wrapper for table TblBrlyQSegMNConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQSEGMNCONNECTION_H
#define BRLYQSEGMNCONNECTION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQSegMNConnection: record of TblBrlyQSegMNConnection
  */
class BrlyQSegMNConnection {

public:
	BrlyQSegMNConnection(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint x1Start;
	string ftmX1Start;
	uint x1Stop;
	string ftmX1Stop;
	double x2Legphi0;
	double x2Legphi1;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQSegMNConnection: recordset of TblBrlyQSegMNConnection
  */
class ListBrlyQSegMNConnection {

public:
	ListBrlyQSegMNConnection();
	ListBrlyQSegMNConnection(const ListBrlyQSegMNConnection& src);
	~ListBrlyQSegMNConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQSegMNConnection* rec);

	ListBrlyQSegMNConnection& operator=(const ListBrlyQSegMNConnection& src);

public:
	vector<BrlyQSegMNConnection*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQSegMNConnection: C++ wrapper for table TblBrlyQSegMNConnection
  */
class TblBrlyQSegMNConnection {

public:
	TblBrlyQSegMNConnection();
	virtual ~TblBrlyQSegMNConnection();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQSegMNConnection** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegMNConnection& rst);

	virtual void insertRec(BrlyQSegMNConnection* rec);
	ubigint insertNewRec(BrlyQSegMNConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQSegMNConnection& rst, BrlyQSegMNConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	virtual void insertRst(ListBrlyQSegMNConnection& rst);
	virtual void updateRec(BrlyQSegMNConnection* rec);
	virtual void updateRst(ListBrlyQSegMNConnection& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQSegMNConnection** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegMNConnection& rst);
};

/**
  * MyBrlyQSegMNConnection: C++ wrapper for table TblBrlyQSegMNConnection (MySQL database)
  */
class MyTblBrlyQSegMNConnection : public TblBrlyQSegMNConnection, public MyTable {

public:
	MyTblBrlyQSegMNConnection();
	~MyTblBrlyQSegMNConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQSegMNConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegMNConnection& rst);

	void insertRec(BrlyQSegMNConnection* rec);
	void insertRst(ListBrlyQSegMNConnection& rst);
	void updateRec(BrlyQSegMNConnection* rec);
	void updateRst(ListBrlyQSegMNConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQSegMNConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegMNConnection& rst);
};

/**
  * PgBrlyQSegMNConnection: C++ wrapper for table TblBrlyQSegMNConnection (PgSQL database)
  */
class PgTblBrlyQSegMNConnection : public TblBrlyQSegMNConnection, public PgTable {

public:
	PgTblBrlyQSegMNConnection();
	~PgTblBrlyQSegMNConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQSegMNConnection** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQSegMNConnection& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQSegMNConnection** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQSegMNConnection& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQSegMNConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegMNConnection& rst);

	void insertRec(BrlyQSegMNConnection* rec);
	void insertRst(ListBrlyQSegMNConnection& rst);
	void updateRec(BrlyQSegMNConnection* rec);
	void updateRst(ListBrlyQSegMNConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQSegMNConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegMNConnection& rst);
};

#endif

