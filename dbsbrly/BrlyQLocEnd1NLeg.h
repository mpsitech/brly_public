/**
  * \file BrlyQLocEnd1NLeg.h
  * Dbs and XML wrapper for table TblBrlyQLocEnd1NLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCEND1NLEG_H
#define BRLYQLOCEND1NLEG_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocEnd1NLeg: record of TblBrlyQLocEnd1NLeg
  */
class BrlyQLocEnd1NLeg {

public:
	BrlyQLocEnd1NLeg(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQLocEnd1NLeg: recordset of TblBrlyQLocEnd1NLeg
  */
class ListBrlyQLocEnd1NLeg {

public:
	ListBrlyQLocEnd1NLeg();
	ListBrlyQLocEnd1NLeg(const ListBrlyQLocEnd1NLeg& src);
	~ListBrlyQLocEnd1NLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocEnd1NLeg* rec);

	ListBrlyQLocEnd1NLeg& operator=(const ListBrlyQLocEnd1NLeg& src);

public:
	vector<BrlyQLocEnd1NLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocEnd1NLeg: C++ wrapper for table TblBrlyQLocEnd1NLeg
  */
class TblBrlyQLocEnd1NLeg {

public:
	TblBrlyQLocEnd1NLeg();
	virtual ~TblBrlyQLocEnd1NLeg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocEnd1NLeg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocEnd1NLeg& rst);

	virtual void insertRec(BrlyQLocEnd1NLeg* rec);
	ubigint insertNewRec(BrlyQLocEnd1NLeg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQLocEnd1NLeg& rst, BrlyQLocEnd1NLeg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQLocEnd1NLeg& rst);
	virtual void updateRec(BrlyQLocEnd1NLeg* rec);
	virtual void updateRst(ListBrlyQLocEnd1NLeg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocEnd1NLeg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocEnd1NLeg& rst);
};

/**
  * MyBrlyQLocEnd1NLeg: C++ wrapper for table TblBrlyQLocEnd1NLeg (MySQL database)
  */
class MyTblBrlyQLocEnd1NLeg : public TblBrlyQLocEnd1NLeg, public MyTable {

public:
	MyTblBrlyQLocEnd1NLeg();
	~MyTblBrlyQLocEnd1NLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocEnd1NLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocEnd1NLeg& rst);

	void insertRec(BrlyQLocEnd1NLeg* rec);
	void insertRst(ListBrlyQLocEnd1NLeg& rst);
	void updateRec(BrlyQLocEnd1NLeg* rec);
	void updateRst(ListBrlyQLocEnd1NLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocEnd1NLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocEnd1NLeg& rst);
};

/**
  * PgBrlyQLocEnd1NLeg: C++ wrapper for table TblBrlyQLocEnd1NLeg (PgSQL database)
  */
class PgTblBrlyQLocEnd1NLeg : public TblBrlyQLocEnd1NLeg, public PgTable {

public:
	PgTblBrlyQLocEnd1NLeg();
	~PgTblBrlyQLocEnd1NLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocEnd1NLeg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocEnd1NLeg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocEnd1NLeg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocEnd1NLeg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocEnd1NLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocEnd1NLeg& rst);

	void insertRec(BrlyQLocEnd1NLeg* rec);
	void insertRst(ListBrlyQLocEnd1NLeg& rst);
	void updateRec(BrlyQLocEnd1NLeg* rec);
	void updateRst(ListBrlyQLocEnd1NLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocEnd1NLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocEnd1NLeg& rst);
};

#endif

