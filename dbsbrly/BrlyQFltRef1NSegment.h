/**
  * \file BrlyQFltRef1NSegment.h
  * Dbs and XML wrapper for table TblBrlyQFltRef1NSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTREF1NSEGMENT_H
#define BRLYQFLTREF1NSEGMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltRef1NSegment: record of TblBrlyQFltRef1NSegment
  */
class BrlyQFltRef1NSegment {

public:
	BrlyQFltRef1NSegment(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint refNum = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	uint refNum;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQFltRef1NSegment: recordset of TblBrlyQFltRef1NSegment
  */
class ListBrlyQFltRef1NSegment {

public:
	ListBrlyQFltRef1NSegment();
	ListBrlyQFltRef1NSegment(const ListBrlyQFltRef1NSegment& src);
	~ListBrlyQFltRef1NSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltRef1NSegment* rec);

	ListBrlyQFltRef1NSegment& operator=(const ListBrlyQFltRef1NSegment& src);

public:
	vector<BrlyQFltRef1NSegment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQFltRef1NSegment: C++ wrapper for table TblBrlyQFltRef1NSegment
  */
class TblBrlyQFltRef1NSegment {

public:
	TblBrlyQFltRef1NSegment();
	virtual ~TblBrlyQFltRef1NSegment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQFltRef1NSegment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltRef1NSegment& rst);

	virtual void insertRec(BrlyQFltRef1NSegment* rec);
	ubigint insertNewRec(BrlyQFltRef1NSegment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint refNum = 0);
	ubigint appendNewRecToRst(ListBrlyQFltRef1NSegment& rst, BrlyQFltRef1NSegment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint refNum = 0);
	virtual void insertRst(ListBrlyQFltRef1NSegment& rst);
	virtual void updateRec(BrlyQFltRef1NSegment* rec);
	virtual void updateRst(ListBrlyQFltRef1NSegment& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQFltRef1NSegment** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltRef1NSegment& rst);
};

/**
  * MyBrlyQFltRef1NSegment: C++ wrapper for table TblBrlyQFltRef1NSegment (MySQL database)
  */
class MyTblBrlyQFltRef1NSegment : public TblBrlyQFltRef1NSegment, public MyTable {

public:
	MyTblBrlyQFltRef1NSegment();
	~MyTblBrlyQFltRef1NSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltRef1NSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltRef1NSegment& rst);

	void insertRec(BrlyQFltRef1NSegment* rec);
	void insertRst(ListBrlyQFltRef1NSegment& rst);
	void updateRec(BrlyQFltRef1NSegment* rec);
	void updateRst(ListBrlyQFltRef1NSegment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltRef1NSegment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltRef1NSegment& rst);
};

/**
  * PgBrlyQFltRef1NSegment: C++ wrapper for table TblBrlyQFltRef1NSegment (PgSQL database)
  */
class PgTblBrlyQFltRef1NSegment : public TblBrlyQFltRef1NSegment, public PgTable {

public:
	PgTblBrlyQFltRef1NSegment();
	~PgTblBrlyQFltRef1NSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltRef1NSegment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltRef1NSegment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltRef1NSegment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltRef1NSegment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltRef1NSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltRef1NSegment& rst);

	void insertRec(BrlyQFltRef1NSegment* rec);
	void insertRst(ListBrlyQFltRef1NSegment& rst);
	void updateRec(BrlyQFltRef1NSegment* rec);
	void updateRst(ListBrlyQFltRef1NSegment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltRef1NSegment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltRef1NSegment& rst);
};

#endif

