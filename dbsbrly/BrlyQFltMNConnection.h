/**
  * \file BrlyQFltMNConnection.h
  * Dbs and XML wrapper for table TblBrlyQFltMNConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTMNCONNECTION_H
#define BRLYQFLTMNCONNECTION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltMNConnection: record of TblBrlyQFltMNConnection
  */
class BrlyQFltMNConnection {

public:
	BrlyQFltMNConnection(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

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
  * ListBrlyQFltMNConnection: recordset of TblBrlyQFltMNConnection
  */
class ListBrlyQFltMNConnection {

public:
	ListBrlyQFltMNConnection();
	ListBrlyQFltMNConnection(const ListBrlyQFltMNConnection& src);
	~ListBrlyQFltMNConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltMNConnection* rec);

	ListBrlyQFltMNConnection& operator=(const ListBrlyQFltMNConnection& src);

public:
	vector<BrlyQFltMNConnection*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQFltMNConnection: C++ wrapper for table TblBrlyQFltMNConnection
  */
class TblBrlyQFltMNConnection {

public:
	TblBrlyQFltMNConnection();
	virtual ~TblBrlyQFltMNConnection();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQFltMNConnection** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltMNConnection& rst);

	virtual void insertRec(BrlyQFltMNConnection* rec);
	ubigint insertNewRec(BrlyQFltMNConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQFltMNConnection& rst, BrlyQFltMNConnection** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	virtual void insertRst(ListBrlyQFltMNConnection& rst);
	virtual void updateRec(BrlyQFltMNConnection* rec);
	virtual void updateRst(ListBrlyQFltMNConnection& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQFltMNConnection** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltMNConnection& rst);
};

/**
  * MyBrlyQFltMNConnection: C++ wrapper for table TblBrlyQFltMNConnection (MySQL database)
  */
class MyTblBrlyQFltMNConnection : public TblBrlyQFltMNConnection, public MyTable {

public:
	MyTblBrlyQFltMNConnection();
	~MyTblBrlyQFltMNConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltMNConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltMNConnection& rst);

	void insertRec(BrlyQFltMNConnection* rec);
	void insertRst(ListBrlyQFltMNConnection& rst);
	void updateRec(BrlyQFltMNConnection* rec);
	void updateRst(ListBrlyQFltMNConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltMNConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltMNConnection& rst);
};

/**
  * PgBrlyQFltMNConnection: C++ wrapper for table TblBrlyQFltMNConnection (PgSQL database)
  */
class PgTblBrlyQFltMNConnection : public TblBrlyQFltMNConnection, public PgTable {

public:
	PgTblBrlyQFltMNConnection();
	~PgTblBrlyQFltMNConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltMNConnection** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltMNConnection& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltMNConnection** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltMNConnection& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltMNConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltMNConnection& rst);

	void insertRec(BrlyQFltMNConnection* rec);
	void insertRst(ListBrlyQFltMNConnection& rst);
	void updateRec(BrlyQFltMNConnection* rec);
	void updateRst(ListBrlyQFltMNConnection& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltMNConnection** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltMNConnection& rst);
};

#endif

