/**
  * \file BrlyQLocBgn1NLeg.h
  * Dbs and XML wrapper for table TblBrlyQLocBgn1NLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCBGN1NLEG_H
#define BRLYQLOCBGN1NLEG_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocBgn1NLeg: record of TblBrlyQLocBgn1NLeg
  */
class BrlyQLocBgn1NLeg {

public:
	BrlyQLocBgn1NLeg(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQLocBgn1NLeg: recordset of TblBrlyQLocBgn1NLeg
  */
class ListBrlyQLocBgn1NLeg {

public:
	ListBrlyQLocBgn1NLeg();
	ListBrlyQLocBgn1NLeg(const ListBrlyQLocBgn1NLeg& src);
	~ListBrlyQLocBgn1NLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocBgn1NLeg* rec);

	ListBrlyQLocBgn1NLeg& operator=(const ListBrlyQLocBgn1NLeg& src);

public:
	vector<BrlyQLocBgn1NLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocBgn1NLeg: C++ wrapper for table TblBrlyQLocBgn1NLeg
  */
class TblBrlyQLocBgn1NLeg {

public:
	TblBrlyQLocBgn1NLeg();
	virtual ~TblBrlyQLocBgn1NLeg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocBgn1NLeg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocBgn1NLeg& rst);

	virtual void insertRec(BrlyQLocBgn1NLeg* rec);
	ubigint insertNewRec(BrlyQLocBgn1NLeg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQLocBgn1NLeg& rst, BrlyQLocBgn1NLeg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQLocBgn1NLeg& rst);
	virtual void updateRec(BrlyQLocBgn1NLeg* rec);
	virtual void updateRst(ListBrlyQLocBgn1NLeg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocBgn1NLeg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocBgn1NLeg& rst);
};

/**
  * MyBrlyQLocBgn1NLeg: C++ wrapper for table TblBrlyQLocBgn1NLeg (MySQL database)
  */
class MyTblBrlyQLocBgn1NLeg : public TblBrlyQLocBgn1NLeg, public MyTable {

public:
	MyTblBrlyQLocBgn1NLeg();
	~MyTblBrlyQLocBgn1NLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocBgn1NLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocBgn1NLeg& rst);

	void insertRec(BrlyQLocBgn1NLeg* rec);
	void insertRst(ListBrlyQLocBgn1NLeg& rst);
	void updateRec(BrlyQLocBgn1NLeg* rec);
	void updateRst(ListBrlyQLocBgn1NLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocBgn1NLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocBgn1NLeg& rst);
};

/**
  * PgBrlyQLocBgn1NLeg: C++ wrapper for table TblBrlyQLocBgn1NLeg (PgSQL database)
  */
class PgTblBrlyQLocBgn1NLeg : public TblBrlyQLocBgn1NLeg, public PgTable {

public:
	PgTblBrlyQLocBgn1NLeg();
	~PgTblBrlyQLocBgn1NLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocBgn1NLeg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocBgn1NLeg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocBgn1NLeg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocBgn1NLeg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocBgn1NLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocBgn1NLeg& rst);

	void insertRec(BrlyQLocBgn1NLeg* rec);
	void insertRst(ListBrlyQLocBgn1NLeg& rst);
	void updateRec(BrlyQLocBgn1NLeg* rec);
	void updateRst(ListBrlyQLocBgn1NLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocBgn1NLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocBgn1NLeg& rst);
};

#endif

