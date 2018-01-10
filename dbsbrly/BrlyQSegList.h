/**
  * \file BrlyQSegList.h
  * Dbs and XML wrapper for table TblBrlyQSegList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQSEGLIST_H
#define BRLYQSEGLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQSegList: record of TblBrlyQSegList
  */
class BrlyQSegList {

public:
	BrlyQSegList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint refIxVTbl;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	ubigint refUref;
	string stubRefUref;
	double alt0;
	double alt1;
	double theta0;
	double theta1;
	double phi0;
	double phi1;
	uint start;
	string ftmStart;
	uint stop;
	string ftmStop;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQSegList: recordset of TblBrlyQSegList
  */
class ListBrlyQSegList {

public:
	ListBrlyQSegList();
	ListBrlyQSegList(const ListBrlyQSegList& src);
	~ListBrlyQSegList();

	void clear();
	unsigned int size() const;
	void append(BrlyQSegList* rec);

	ListBrlyQSegList& operator=(const ListBrlyQSegList& src);

public:
	vector<BrlyQSegList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQSegList: C++ wrapper for table TblBrlyQSegList
  */
class TblBrlyQSegList {

public:
	TblBrlyQSegList();
	virtual ~TblBrlyQSegList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQSegList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegList& rst);

	virtual void insertRec(BrlyQSegList* rec);
	ubigint insertNewRec(BrlyQSegList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");
	ubigint appendNewRecToRst(ListBrlyQSegList& rst, BrlyQSegList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");
	virtual void insertRst(ListBrlyQSegList& rst);
	virtual void updateRec(BrlyQSegList* rec);
	virtual void updateRst(ListBrlyQSegList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQSegList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegList& rst);
};

/**
  * MyBrlyQSegList: C++ wrapper for table TblBrlyQSegList (MySQL database)
  */
class MyTblBrlyQSegList : public TblBrlyQSegList, public MyTable {

public:
	MyTblBrlyQSegList();
	~MyTblBrlyQSegList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQSegList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegList& rst);

	void insertRec(BrlyQSegList* rec);
	void insertRst(ListBrlyQSegList& rst);
	void updateRec(BrlyQSegList* rec);
	void updateRst(ListBrlyQSegList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQSegList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegList& rst);
};

/**
  * PgBrlyQSegList: C++ wrapper for table TblBrlyQSegList (PgSQL database)
  */
class PgTblBrlyQSegList : public TblBrlyQSegList, public PgTable {

public:
	PgTblBrlyQSegList();
	~PgTblBrlyQSegList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQSegList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQSegList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQSegList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQSegList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQSegList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegList& rst);

	void insertRec(BrlyQSegList* rec);
	void insertRst(ListBrlyQSegList& rst);
	void updateRec(BrlyQSegList* rec);
	void updateRst(ListBrlyQSegList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQSegList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegList& rst);
};

#endif

