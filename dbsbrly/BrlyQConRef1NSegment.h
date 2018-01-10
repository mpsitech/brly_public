/**
  * \file BrlyQConRef1NSegment.h
  * Dbs and XML wrapper for table TblBrlyQConRef1NSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONREF1NSEGMENT_H
#define BRLYQCONREF1NSEGMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConRef1NSegment: record of TblBrlyQConRef1NSegment
  */
class BrlyQConRef1NSegment {

public:
	BrlyQConRef1NSegment(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint refNum = 0);

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
  * ListBrlyQConRef1NSegment: recordset of TblBrlyQConRef1NSegment
  */
class ListBrlyQConRef1NSegment {

public:
	ListBrlyQConRef1NSegment();
	ListBrlyQConRef1NSegment(const ListBrlyQConRef1NSegment& src);
	~ListBrlyQConRef1NSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyQConRef1NSegment* rec);

	ListBrlyQConRef1NSegment& operator=(const ListBrlyQConRef1NSegment& src);

public:
	vector<BrlyQConRef1NSegment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQConRef1NSegment: C++ wrapper for table TblBrlyQConRef1NSegment
  */
class TblBrlyQConRef1NSegment {

public:
	TblBrlyQConRef1NSegment();
	virtual ~TblBrlyQConRef1NSegment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQConRef1NSegment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConRef1NSegment& rst);

	virtual void insertRec(BrlyQConRef1NSegment* rec);
	ubigint insertNewRec(BrlyQConRef1NSegment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint refNum = 0);
	ubigint appendNewRecToRst(ListBrlyQConRef1NSegment& rst, BrlyQConRef1NSegment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint refNum = 0);
	virtual void insertRst(ListBrlyQConRef1NSegment& rst);
	virtual void updateRec(BrlyQConRef1NSegment* rec);
	virtual void updateRst(ListBrlyQConRef1NSegment& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQConRef1NSegment** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConRef1NSegment& rst);
};

/**
  * MyBrlyQConRef1NSegment: C++ wrapper for table TblBrlyQConRef1NSegment (MySQL database)
  */
class MyTblBrlyQConRef1NSegment : public TblBrlyQConRef1NSegment, public MyTable {

public:
	MyTblBrlyQConRef1NSegment();
	~MyTblBrlyQConRef1NSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConRef1NSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConRef1NSegment& rst);

	void insertRec(BrlyQConRef1NSegment* rec);
	void insertRst(ListBrlyQConRef1NSegment& rst);
	void updateRec(BrlyQConRef1NSegment* rec);
	void updateRst(ListBrlyQConRef1NSegment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConRef1NSegment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConRef1NSegment& rst);
};

/**
  * PgBrlyQConRef1NSegment: C++ wrapper for table TblBrlyQConRef1NSegment (PgSQL database)
  */
class PgTblBrlyQConRef1NSegment : public TblBrlyQConRef1NSegment, public PgTable {

public:
	PgTblBrlyQConRef1NSegment();
	~PgTblBrlyQConRef1NSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConRef1NSegment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQConRef1NSegment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConRef1NSegment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConRef1NSegment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConRef1NSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConRef1NSegment& rst);

	void insertRec(BrlyQConRef1NSegment* rec);
	void insertRst(ListBrlyQConRef1NSegment& rst);
	void updateRec(BrlyQConRef1NSegment* rec);
	void updateRst(ListBrlyQConRef1NSegment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConRef1NSegment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConRef1NSegment& rst);
};

#endif

