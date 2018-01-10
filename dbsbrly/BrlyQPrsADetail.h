/**
  * \file BrlyQPrsADetail.h
  * Dbs and XML wrapper for table TblBrlyQPrsADetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQPRSADETAIL_H
#define BRLYQPRSADETAIL_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQPrsADetail: record of TblBrlyQPrsADetail
  */
class BrlyQPrsADetail {

public:
	BrlyQPrsADetail(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string x1SrefKType;
	string titX1SrefKType;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQPrsADetail: recordset of TblBrlyQPrsADetail
  */
class ListBrlyQPrsADetail {

public:
	ListBrlyQPrsADetail();
	ListBrlyQPrsADetail(const ListBrlyQPrsADetail& src);
	~ListBrlyQPrsADetail();

	void clear();
	unsigned int size() const;
	void append(BrlyQPrsADetail* rec);

	ListBrlyQPrsADetail& operator=(const ListBrlyQPrsADetail& src);

public:
	vector<BrlyQPrsADetail*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQPrsADetail: C++ wrapper for table TblBrlyQPrsADetail
  */
class TblBrlyQPrsADetail {

public:
	TblBrlyQPrsADetail();
	virtual ~TblBrlyQPrsADetail();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQPrsADetail** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPrsADetail& rst);

	virtual void insertRec(BrlyQPrsADetail* rec);
	ubigint insertNewRec(BrlyQPrsADetail** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");
	ubigint appendNewRecToRst(ListBrlyQPrsADetail& rst, BrlyQPrsADetail** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");
	virtual void insertRst(ListBrlyQPrsADetail& rst);
	virtual void updateRec(BrlyQPrsADetail* rec);
	virtual void updateRst(ListBrlyQPrsADetail& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQPrsADetail** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPrsADetail& rst);
};

/**
  * MyBrlyQPrsADetail: C++ wrapper for table TblBrlyQPrsADetail (MySQL database)
  */
class MyTblBrlyQPrsADetail : public TblBrlyQPrsADetail, public MyTable {

public:
	MyTblBrlyQPrsADetail();
	~MyTblBrlyQPrsADetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQPrsADetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPrsADetail& rst);

	void insertRec(BrlyQPrsADetail* rec);
	void insertRst(ListBrlyQPrsADetail& rst);
	void updateRec(BrlyQPrsADetail* rec);
	void updateRst(ListBrlyQPrsADetail& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQPrsADetail** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPrsADetail& rst);
};

/**
  * PgBrlyQPrsADetail: C++ wrapper for table TblBrlyQPrsADetail (PgSQL database)
  */
class PgTblBrlyQPrsADetail : public TblBrlyQPrsADetail, public PgTable {

public:
	PgTblBrlyQPrsADetail();
	~PgTblBrlyQPrsADetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQPrsADetail** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQPrsADetail& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQPrsADetail** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQPrsADetail& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQPrsADetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPrsADetail& rst);

	void insertRec(BrlyQPrsADetail* rec);
	void insertRst(ListBrlyQPrsADetail& rst);
	void updateRec(BrlyQPrsADetail* rec);
	void updateRst(ListBrlyQPrsADetail& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQPrsADetail** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPrsADetail& rst);
};

#endif

